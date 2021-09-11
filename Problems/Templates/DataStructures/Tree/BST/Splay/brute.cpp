#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
struct sqrtarr {
    struct block {
        vector<int> arr;
        int pre;

        block() {
            arr = {};
            pre = 0;
        }
    };

    struct byvalue {
        bool operator()(const block &lhs, const int &val) const {
            return lhs.arr[0] < val;
        }
        bool operator()(const int &val, const block &lhs) const {
            return val < lhs.arr[0];
        }
    };

    struct byindex {
        bool operator()(const block &lhs, const int &val) const {
            return lhs.pre < val;
        }
        bool operator()(const int &val, const block &lhs) const {
            return val < lhs.pre;
        }
    };

    vector<block> arr;
    int BS, SBS;

    sqrtarr(){
        arr={};
        BS=0,SBS=0;
    }

    void calc(int loc) {
        for (; loc < sz(arr); loc++)arr[loc].pre = arr[loc - 1].pre + sz(arr[loc - 1].arr);
    }

    void insert(int val) {
        if (sz(arr) == 0) {
            arr.push_back(block());
            arr[0].arr.push_back(val);
            return;
        }
        int loc = max(0, (int) (upper_bound(arr.begin(), arr.end(), val, byvalue()) - arr.begin() - 1));
        arr[loc].arr.insert(lower_bound(arr[loc].arr.begin(), arr[loc].arr.end(), val), val);
        if (sz(arr[loc].arr) >= SBS) {
            arr.insert(arr.begin() + loc + 1, block());
            arr[loc + 1].arr.insert(arr[loc + 1].arr.begin(), arr[loc].arr.begin() + BS, arr[loc].arr.end());
            arr[loc].arr.resize(BS);
        }
        calc(loc + 1);
    }

    void remove(int val) {
        int loc = upper_bound(arr.begin(), arr.end(), val, byvalue()) - arr.begin() - 1;
        if (loc < 0)return;
        int ind = lower_bound(arr[loc].arr.begin(), arr[loc].arr.end(), val) - arr[loc].arr.begin();
        if (ind < sz(arr[loc].arr) && arr[loc].arr[ind] == val)arr[loc].arr.erase(arr[loc].arr.begin() + ind);
        if (sz(arr[loc].arr) == 0)arr.erase(arr.begin() + loc), loc--;
        calc(loc + 1);
    }

    int kth(int val) {
        val--;
        int loc = upper_bound(arr.begin(), arr.end(), val, byindex()) - arr.begin() - 1;
        return arr[loc].arr[val - arr[loc].pre];
    }

    int getind(int val) {
        int loc=lower_bound(arr.begin(),arr.end(),val,byvalue())-arr.begin()-1;
        if(loc>=0){
            int ind=lower_bound(arr[loc].arr.begin(),arr[loc].arr.end(),val)-arr[loc].arr.begin();
            if(ind<sz(arr[loc].arr)&&arr[loc].arr[ind]==val)return arr[loc].pre+ind+1;
        }
        if(loc+1<sz(arr)&&arr[loc+1].arr[0]==val)return arr[loc+1].pre+1;
        return -1;
    }

    void printarray() {
        for(auto x:arr){
            for(auto y:x.arr)printf("%d ",y);
        }
        printf("\n");
    }

    void create(const vector<int>& a){
        arr=vector<block>();
        for(int i=0;i<sz(a);i++){
            if(i%BS==0){
                arr.push_back(block());
            }
            arr.back().arr.push_back(a[i]);
        }
        calc(1);
    }
}solver;
vector<int> arr;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,q;
    cin>>n>>q;
    int lastans=0;
    int a;
    for(int i=0;i<n;i++){
        cin>>a;
        arr.push_back(a);
    }
    sort(arr.begin(),arr.end());
    solver.BS=max(1,(int)(sqrt(q)*3.8)),solver.SBS=solver.BS*2;
    solver.create(arr);
    char in;
    while(q--){
        cin>>in>>a;
        if(in=='I')solver.insert(a);
        else if(in=='R')solver.remove(a);
        else if(in=='S')printf("%d\n",lastans=solver.kth(a));
        else printf("%d\n",lastans=solver.getind(a));
    }
    solver.printarray();
    return 0;
}