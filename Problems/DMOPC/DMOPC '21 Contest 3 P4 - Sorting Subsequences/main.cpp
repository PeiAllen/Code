#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define A first
#define B second
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=5e5+1;
// With C++ 11 not having std::make_unique defined, a simple implementation
//   of make_unique is provided
// Template Arguments:
//   T: the type of the object to construct
//   ...Args: variadic arguments of the types of the arguments being passed to
//     the object being constructor
// Return Value:
//   a unique_ptr of type T
// Tested:
//   https://dmoj.ca/problem/set
template <class T, class ...Args> unique_ptr<T> _make_unique(Args &&...args) {
    return unique_ptr<T>(new T(forward<Args>(args)...));
}

#define make_unique _make_unique
// Skew Heap supporting merges
// Template Arguments:
//   T: the type of each element
//   Cmp: the comparator to compare two values of type T,
//       convention is same as std::priority_queue in STL
//     Required Functions:
//       operator (a, b): returns true if and only if a compares less than b
// Functions:
//   empty(): returns whether the heap is empty
//   size(): returns the number of elements in the heap
//   top(): returns the largest element in the heap based on the comparator
//   pop(): pops the largest element in the heap based on the comparator,
//     and returns that element
//   push(key): pushes val onto the heap
//   merge(h): merges the heap h into this heap, destroys heap h
// In practice, has a moderate constant
// Time Complexity:
//   constructor, empty, size, top: O(1)
//   pop, push: O(log N) amortized
//   merge: O(log (N + M)) amortized where M is the size of heap h
// Memory Complexity: O(N)
// Tested:
//   https://dmoj.ca/problem/apio16p2

template <class T, class Cmp = less<T>> struct SkewHeap {
    struct Node { T val; unique_ptr<Node> l, r; Node(const T &v) : val(v) {} };
    Cmp cmp; int cnt; unique_ptr<Node> root;
    unique_ptr<Node> merge(unique_ptr<Node> a, unique_ptr<Node> b) {
        if (!a || !b) return a ? move(a) : move(b);
        if (cmp(a->val, b->val)) a.swap(b);
        a->l.swap(a->r); a->r = merge(move(b), move(a->r)); return move(a);
    }
    SkewHeap() : cnt(0) {}
    bool empty() const { return !root; }
    int size() const { return cnt; }
    T top() const { return root->val; }
    T pop() {
        T ret = root->val; root = merge(move(root->l), move(root->r)); cnt--;
        return ret;
    }
    void push(const T &val) {
        root = merge(move(root), make_unique<Node>(val)); cnt++;
    }
    void merge(SkewHeap &h) {
        root = merge(move(root), move(h.root)); cnt += h.cnt;
    }
};
set<pii> keys[MN];
struct seg{
    pii t[2*MN];
    void mt(int ind, int le, int ri){
        if(le==ri){
            t[ind]=(sz(keys[le])?*keys[le].begin():pii{INT_MAX,INT_MAX});
            return;
        }
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        mt(left,le,mid),mt(right,mid+1,ri);
        t[ind]=min(t[left],t[right]);
    }
    void update(int ind, int le, int ri, int loc){
        if(loc>ri||loc<le)return;
        if(le==ri){
            t[ind]=(sz(keys[le])?*keys[le].begin():pii{INT_MAX,INT_MAX});
            return;
        }
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        update(left,le,mid,loc),update(right,mid+1,ri,loc);
        t[ind]=min(t[left],t[right]);
    }
    pii query(int ind, int le, int ri, int l, int r){
        if(l>ri||r<le||l>r)return {INT_MAX,INT_MAX};
        if(le>=l&&ri<=r)return t[ind];
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        return min(query(left,le,mid,l,r),query(right,mid+1,ri,l,r));
    }
}tree;
pii dsu[MN];
SkewHeap<int> vals[MN];
int arr[MN];
int find(int a){
    if(dsu[a].first==a)return a;
    return dsu[a].first=find(dsu[a].first);
}
bool uni(int a, int b){
    int ap=find(a),bp=find(b);
    if(ap==bp)return false;
    if(dsu[ap].second<dsu[bp].second)swap(ap,bp);
    dsu[ap].second+=dsu[bp].second;
    dsu[bp].first=ap;
    vals[ap].merge(vals[bp]);
    return true;
}
vector<int> indices[MN];
vector<int> finvals[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    tree.mt(0,1,n);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        dsu[i]={i,1};
        vals[i].push(arr[i]);
        keys[1].insert({arr[i],i});
    }
    tree.update(0,1,n,1);
    for(int i=1;i<=n;i++){
        int p=find(i);
        int best=vals[p].top();
        pii oth=tree.query(0,1,n,1,k-dsu[p].second);
        if(oth.first<best){
            keys[dsu[p].second].erase({vals[p].top(),p});
            keys[dsu[oth.second].second].erase({vals[oth.second].top(),oth.second});
            tree.update(0,1,n,dsu[p].second);
            tree.update(0,1,n,dsu[oth.second].second);
            vals[oth.second].pop();
            uni(oth.second,p);
            p=find(p);
            keys[dsu[p].second].insert({vals[p].top(),p});
            tree.update(0,1,n,dsu[p].second);
        }
        else{
            keys[dsu[p].second].erase({vals[p].top(),p});
            vals[p].pop();
            if(!vals[p].empty())keys[dsu[p].second].insert({vals[p].top(),p});
            tree.update(0,1,n,dsu[p].second);
        }
    }
    for(int i=1;i<=n;i++){
        indices[find(i)].push_back(i);
        finvals[find(i)].push_back(arr[i]);
    }
    for(int i=1;i<=n;i++){
        if(find(i)==i){
            sort(indices[i].begin(),indices[i].end());
            sort(finvals[i].begin(),finvals[i].end());
            for(int j=0;j<sz(indices[i]);j++){
                arr[indices[i][j]]=finvals[i][j];
            }
        }
    }
    for(int i=1;i<=n;i++)printf("%d%c",arr[i]," \n"[i==n]);
    return 0;
}