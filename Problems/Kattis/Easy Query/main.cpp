#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}

// Prefix Sum Array supporting range sum queries where all values are 0 or 1,
//   and all values are set before all queries
// Indices are 0-indexed and ranges are inclusive
// Constructor Arguments:
//   N: the size of the array
// Functions:
//   set(i, v): sets the index i with the boolean value v
//   get(i): gets the value of index i
//   build(): builds the prefix sum array, must be called before query can
//     be called after a set operation
//   query(r): queries the sum of the range [0, r]
//   query(l, r): queries the sum of the range [l, r]
// In practice, has a moderate constant, performs faster than a regular prefix
//   sum array and uses less memory
// Time Complexity:
//   constructor, set, get, query: O(1)
//   build: O(N / 64)
// Memory Complexity: O(N / 64)
// Tested:
//   Fuzz and Stress Tested
struct BitPrefixSumArray {
    int M; vector<uint64_t> mask; vector<int> pre;
    BitPrefixSumArray(int N) : M((N >> 6) + 1), mask(M, 0), pre(M + 1, 0) {}
    void set(int i, bool v) {
        int j = i >> 6, k = i & 63;
        mask[j] = (mask[j] & ~(uint64_t(1) << k)) | (uint64_t(v) << k);
    }
    bool get(int i) { return (mask[i >> 6] >> (i & 63)) & 1; }
    void build() {
        for (int j = 0; j < M; j++)
            pre[j + 1] = pre[j] + __builtin_popcountll(mask[j]);
    }
    int query(int r) {
        r++; int j = r >> 6, k = r & 63;
        return pre[j] + __builtin_popcountll(mask[j] & ((uint64_t(1) << k) - 1));
    }
    int query(int l, int r) { return query(r) - query(l - 1); }
};

// Wavelet Matrix supporting rank and select operations for a subarray
// Indices are 0-indexed and ranges are inclusive with the exception of
//   functions that accept two iterators as a parameter, such as
//   the constructor, which are exclusive
// Template Arguments:
//   T: the type of the element of the array
//   Cmp: the comparator to compare two elements
//     Required Functions:
//       operator (a, b): returns true if and only if a compares less than b
// Constructor Arguments:
//   N: the size of the array
//   f: a generating function that returns the ith element on the ith call
//   st: an iterator pointing to the first element in the array
//   en: an iterator pointing to after the last element in the array
// Functions:
//   rank(l, r, k): returns the number of elements less than k (using the
//     comparator) in the range [l, r]
//   count(l, r, lo, hi) returns the number of elements not less than lo and
//     not greater than hi (using the comparator) in the range [l, r]
//   select(l, r, k): returns the kth element sorted by the comparator if the
//     range [l, r] was sorted
// In practice, has a moderate constant
// Time Complexity:
//   constructor: O(N log N)
//   rank, count, select: O(log N)
// Memory Complexity: O(N + (N log N) / 64)
// Tested:
//   https://www.spoj.com/problems/KQUERY/ (rank/count)
//   https://www.spoj.com/problems/KQUERYO/ (rank/count)
//   https://codeforces.com/contest/1284/problem/D (rank/count)
//   https://www.spoj.com/problems/MKTHNUM/ (select)
//   https://judge.yosupo.jp/problem/range_kth_smallest (select)
template <class T, class Cmp = less<T>> struct WaveletMatrix {
    int N, H; vector<int> mid; vector<BitPrefixSumArray> B; vector<T> S;
    template <class F> WaveletMatrix(int N, F f)
            : N(N), H(N == 0 ? 0 : __lg(N) + 1), mid(H), B(H, BitPrefixSumArray(N)) {
        S.reserve(N); for (int i = 0; i < N; i++) S.push_back(f());
        vector<T> temp = S; sort(S.begin(), S.end(), Cmp()); vector<int> C(N);
        for (int i = 0; i < N; i++)
            C[i] = lower_bound(S.begin(), S.end(), temp[i], Cmp()) - S.begin();
        for (int h = H - 1; h >= 0; h--) {
            int ph = 1 << h; for (int i = 0; i < N; i++) B[h].set(i, C[i] <= ph - 1);
            mid[h] = stable_partition(C.begin(), C.end(), [&] (int v) {
                return v <= ph - 1;
            }) - C.begin();
            B[h].build(); for (int i = mid[h]; i < N; i++) C[i] -= ph;
        }
    }
    template <class It> WaveletMatrix(It st, It en)
            : WaveletMatrix(en - st, [&] { return *st++; }) {}
    template <class F> int cnt(int l, int r, const T &v, F f) {
        int ret = 0, cur = 0; for (int h = H - 1; h >= 0; h--) {
            int ph = 1 << h, ql = B[h].query(l - 1), qr = B[h].query(r);
            if (cur + ph - 1 >= N || f(v, S[cur + ph - 1])) { l = ql; r = qr - 1; }
            else { cur += ph; ret += qr - ql; l += mid[h] - ql; r += mid[h] - qr; }
        }
        return ret;
    }
    int rank(int l, int r, const T &v) {
        return cnt(l, r, v, [&] (const T &a, const T &b) { return !Cmp()(b, a); });
    }
    int count(int l, int r, const T &lo, const T &hi) {
        return cnt(l, r, hi, [&] (const T &a, const T &b) { return Cmp()(a, b); })
               - cnt(l, r, lo, [&] (const T &a, const T &b) { return !Cmp()(b, a); });
    }
    T select(int l, int r, int k) {
        int cur = 0; for (int h = H - 1; h >= 0; h--) {
            int ql = B[h].query(l - 1), qr = B[h].query(r);
            if (k < qr - ql) { l = ql; r = qr - 1; }
            else { cur += 1 << h; k -= qr - ql; l += mid[h] - ql; r += mid[h] - qr; }
        }
        return S[cur];
    }
};

// Bottom up segment tree supporting point updates and range queries
// Indices are 0-indexed and ranges are inclusive with the exception of
//   functions that accept two iterators as a parameter, such as
//   the constructor, which are exclusive
// Template Arguments:
//   C: struct to combine data and lazy values
//     Required Fields:
//       Data: the data type
//       Lazy: the lazy type
//     Required Functions:
//       static qdef(): returns the query default value of type Data
//       static merge(l, r): returns the values l of type Data merged with
//         r of type Data, must be associative
//       static applyLazy(l, r): returns the value r of type Lazy applied to
//         l of type Data, must be associative
//     Sample Struct: supporting point increments and range max queries
//       struct C {
//         using Data = int;
//         using Lazy = int;
//         static Data qdef() { return numeric_limits<int>::min(); }
//         static Data merge(const Data &l, const Data &r) {
//           return max(l, r);
//         }
//         static Data applyLazy(const Data &l, const Lazy &r) {
//           return l + r;
//         }
//       };
// Constructor Arguments:
//   N: the size of the array
//   f: a generating function that returns the ith element on the ith call
//   st: an iterator pointing to the first element in the array
//   en: an iterator pointing to after the last element in the array
//   vdef: the default value to fill the array with
// Functions:
//   update(i, v): updates the index i with the lazy value v
//   query(l, r): queries the range [l, r] and returns the aggregate value
// In practice, has a small constant, not quite as fast as fenwick trees,
//   but faster than top down segment trees
// Time Complexity:
//   constructor: O(N)
//   update, query: O(log N)
// Memory Complexity: O(N)
// Tested:
//   https://dmoj.ca/problem/ds3
//   https://dmoj.ca/problem/dmpg17g2
//   https://dmoj.ca/problem/coci17c1p5
//   https://judge.yosupo.jp/problem/point_set_range_composite
struct C {
    using Data = int;
    using Lazy = int;
    static Data qdef() { return 0; }
    static Data merge(const Data &l, const Data &r) {
        return l|r;
    }
    static Data applyLazy(const Data &l, const Lazy &r) {
        return l|r;
    }
};
template <class C> struct SegmentTreeBottomUp {
    using Data = typename C::Data; using Lazy = typename C::Lazy;
    int N; vector<Data> TR;
    template <class F> SegmentTreeBottomUp(int N, F f)
            : N(N), TR(N * 2, C::qdef()) {
        generate(TR.begin() + N, TR.end(), f);
        for (int i = N - 1; i > 0; i--) TR[i] = C::merge(TR[i * 2], TR[i * 2 + 1]);
    }
    template <class It> SegmentTreeBottomUp(It st, It en)
            : SegmentTreeBottomUp(en - st, [&] { return *st++; }) {}
    SegmentTreeBottomUp(int N, const Data &vdef)
            : SegmentTreeBottomUp(N, [&] { return vdef; }) {}
    void update(int i, const Lazy &v) {
        for (i += N, TR[i] = C::applyLazy(TR[i], v); i /= 2;)
            TR[i] = C::merge(TR[i * 2], TR[i * 2 + 1]);
    }
    Data query(int l, int r) {
        Data ql = C::qdef(), qr = C::qdef();
        for (l += N, r += N; l <= r; l /= 2, r /= 2) {
            if (l % 2) ql = C::merge(ql, TR[l++]);
            if (!(r % 2)) qr = C::merge(TR[r--], qr);
        }
        return C::merge(ql, qr);
    }
};



const int MN=2e5+1;
vector<int> appear[MN];
int arr[MN];
struct bit{
    int N;
    struct node{
        vector<int> vals;
        vector<SegmentTreeBottomUp<C>> data;
        node(){
            vals={};
            data=vector<SegmentTreeBottomUp<C>>();
        }
    }t[MN];
    void mt(){
        for(int i=1;i<=N;i++)t[i].vals={arr[i-1]};
        for(int i=1;i<=N;i++) {
            t[i].vals.erase(unique(t[i].vals.begin(),t[i].vals.end()),t[i].vals.end());
            t[i].data.resize(3,SegmentTreeBottomUp<C>(1,0));
            for(int j=0;j<3;j++)t[i].data[j]=SegmentTreeBottomUp<C>(sz(t[i].vals),0);
            if(i + (i & -i) <= N) {
                vector<int> te(sz(t[i + (i & -i)].vals)+sz(t[i].vals));
                merge(t[i + (i & -i)].vals.begin(),t[i + (i & -i)].vals.end(),t[i].vals.begin(),t[i].vals.end(),te.begin());
                t[i + (i & -i)].vals=te;
            }
        } 
    }
    void update(int i, int val, int ver) {
        for(i++;i<=N;i+=i&-i)t[i].data[ver].update(lower_bound(t[i].vals.begin(),t[i].vals.end(),val)-t[i].vals.begin(),val);
    }
    array<int,3> query(int i, int mival, int maval) {
        if(mival>maval)return {0,0,0};
        array<int,3> ret={0,0,0};
        for(i++;i>0;i-=i&-i){
            int lp=lower_bound(t[i].vals.begin(),t[i].vals.end(),mival)-t[i].vals.begin(),rp=upper_bound(t[i].vals.begin(),t[i].vals.end(),maval)-t[i].vals.begin()-1;
            if(lp<=rp)for(int j=0;j<3;j++)ret[j]|=t[i].data[j].query(lp,rp);
        }
        return ret;
    }
}tree;
vector<pair<pair<int,pair<pii,int>>,pii>> queries[MN];
ll ans[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n,q,a,b,c,d;
        cin>>n>>q;
        vector<int> vals;
        for(int i=0;i<n;i++)cin>>arr[i],vals.push_back(arr[i]),appear[i]=vector<int>(),queries[i]=vector<pair<pair<int,pair<pii,int>>,pii>>();
        WaveletMatrix<int> kth(arr,arr+n);
        for(int i=0;i<q;i++){
            cin>>a>>b>>c>>d,a--,b--;
            queries[a].push_back({{b,{{c,d},i}},{kth.select(a,b,c-1),kth.select(a,b,d-1)}});
        }
        sort(vals.begin(),vals.end()),vals.erase(unique(vals.begin(),vals.end()),vals.end());
        tree.N=n;
        tree.mt();
        for(int i=0;i<n;i++)appear[lower_bound(vals.begin(),vals.end(),arr[i])-vals.begin()].push_back(i);
        for(int i=n-1;i>=0;i--){
            int ind=lower_bound(vals.begin(),vals.end(),arr[i])-vals.begin();
            int loc=lower_bound(appear[ind].begin(),appear[ind].end(),i)-appear[ind].begin();
            tree.update(i,arr[i],0);
            if(sz(appear[ind])-loc>=2)tree.update(appear[ind][loc+1],arr[i],1);
            if(sz(appear[ind])-loc>=3)tree.update(appear[ind][loc+2],arr[i],2);
            for(auto x:queries[i]){
                if(x.second.first==x.second.second){
                    int appearcnt=x.first.second.first.second-x.first.second.first.first+1;
                    ans[x.first.second.second]=min(appearcnt,3)*ll(x.second.first);
                    continue;
                }
                array<int,3> res=tree.query(x.first.first,x.second.first+1,x.second.second-1);
                int smallind=lower_bound(vals.begin(),vals.end(),x.second.first)-vals.begin();
                int appearsmall=upper_bound(appear[smallind].begin(),appear[smallind].end(),x.first.first)-lower_bound(appear[smallind].begin(),appear[smallind].end(),i)-(x.first.second.first.first-1-kth.rank(i,x.first.first,x.second.first));
                int appearlarge=x.first.second.first.second-kth.rank(i,x.first.first,x.second.second);
                for(int j=0;j<3;j++){
                    if(appearsmall>j)res[j]|=x.second.first;
                    if(appearlarge>j)res[j]|=x.second.second;
                }
                ans[x.first.second.second]=accumulate(res.begin(),res.end(),ll(0));
            }
        }
        for(int i=0;i<q;i++)printf("%lli\n",ans[i]);
    }
    return 0;
}