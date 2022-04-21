#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define A first
#define B second
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=5e5+1;

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
// Indices are 0-indexed and ranges are inclusive
// Template Arguments:
//   T: the type of the element of the array
//   Cmp: the comparator to compare two elements
//     Required Functions:
//       operator (a, b): returns true if and only if a compares less than b
// Constructor Arguments:
//   A: a vector of type T of the values in the array
//   cmp: an instance of the Cmp struct
// Functions:
//   rank(l, r, k): returns the number of elements less than k (using the
//     comparator) in the range [l, r]
//   count(l, r, lo, hi) returns the number of elements not less than lo and
//     not greater than hi (using the comparator) in the range [l, r]
//   select(l, r, k): returns the kth element (0-indexed) sorted by the
//     comparator if the range [l, r] was sorted
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
#define clt [&] (const T &a, const T &b) { return cmp(a, b); }
#define cle [&] (const T &a, const T &b) { return !cmp(b, a); }
    int N, H; Cmp cmp; vector<int> mid; vector<BitPrefixSumArray> B; vector<T> S;
    WaveletMatrix(vector<T> A, Cmp cmp = Cmp())
            : N(A.size()), H(N == 0 ? 0 : __lg(N) + 1), cmp(cmp), mid(H),
              B(H, BitPrefixSumArray(N)), S(move(A)) {
        vector<T> temp = S; sort(S.begin(), S.end(), cmp); vector<int> C(N);
        for (int i = 0; i < N; i++)
            C[i] = lower_bound(S.begin(), S.end(), temp[i], cmp) - S.begin();
        for (int h = H - 1; h >= 0; h--) {
            int ph = 1 << h; for (int i = 0; i < N; i++) B[h].set(i, C[i] <= ph - 1);
            mid[h] = stable_partition(C.begin(), C.end(), [&] (int v) {
                return v <= ph - 1;
            }) - C.begin();
            B[h].build(); for (int i = mid[h]; i < N; i++) C[i] -= ph;
        }
    }
    template <class F> int cnt(int l, int r, const T &v, F f) {
        int ret = 0; for (int cur = 0, h = H - 1; h >= 0; h--) {
            int ph = 1 << h, ql = B[h].query(l - 1), qr = B[h].query(r);
            if (cur + ph - 1 >= N || f(v, S[cur + ph - 1])) { l = ql; r = qr - 1; }
            else { cur += ph; ret += qr - ql; l += mid[h] - ql; r += mid[h] - qr; }
        }
        return ret;
    }
    int rank(int l, int r, const T &v) { return cnt(l, r, v, cle); }
    int count(int l, int r, const T &lo, const T &hi) {
        return cnt(l, r, hi, clt) - cnt(l, r, lo, cle);
    }
    T select(int l, int r, int k) {
        int cur = 0; for (int h = H - 1; h >= 0; h--) {
            int ql = B[h].query(l - 1), qr = B[h].query(r);
            if (k < qr - ql) { l = ql; r = qr - 1; }
            else { cur += 1 << h; k -= qr - ql; l += mid[h] - ql; r += mid[h] - qr; }
        }
        return S[cur];
    }
#undef clt
#undef cle
};

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m,a,b,c,d;
    cin>>n>>m;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    WaveletMatrix<int> tree(arr);
    for(int i=0;i<m;i++){
        cin>>a>>b>>c>>d;
        c--,d--;
        int val=0;
        for(int j=__lg(int(2e5));j>=0;j--){
            int want=(1<<j)^(a&(1<<j));
            if(tree.count(c,d,val+want-b,val+want+(1<<j)-1-b)){
                val+=want;
            }
            else val+=want^(1<<j);
        }
        printf("%d\n",val^a);
    }
    return 0;
}