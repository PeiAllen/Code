#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
int len;
vector<int> pos;
vector<int> stage;
int bs=100;
struct SQRT{
    struct node{
        vector<int> inds;
        vector<pii> use;
        node(){
            inds={};
            use={};
        }
        void calc(){
            use.resize(sz(inds));
            for(int i=sz(inds)-1;i>=0;i--){
                int r=upper_bound(inds.begin(),inds.end(),inds[i]+len)-inds.begin();
                if(r==sz(inds))use[i]={1,inds[i]+len};
                else use[i]={use[r].first+1,use[r].second};
            }
        }
    };
    struct comp{
        bool operator()(const int &val, const node &it) {
            return val < it.inds[0];
        }
    };
    vector<node> arr;
    SQRT(){arr={};}
    int getans(){
        int am=0;
        int loc=-1;
        for(int i=0;i<sz(arr);i++){
            int ind=upper_bound(arr[i].inds.begin(),arr[i].inds.end(),loc)-arr[i].inds.begin();
            if(ind!=sz(arr[i].inds)){
                am+=arr[i].use[ind].first;
                loc=arr[i].use[ind].second;
            }
        }
        return am;
    }
    void build(){
        arr.resize((sz(stage)-1)/bs+1);
        for(int i=0;i<sz(arr);i++){
            arr[i].inds.resize(i==sz(arr)-1?((sz(stage)-1)%bs)+1:bs);
        }
        for(int i=0;i<sz(stage);i++)arr[i/bs].inds[i%bs]=stage[i];
        for(int i=0;i<sz(arr);i++)arr[i].calc();
    }
    void insert(int loc){
        int ind=(upper_bound(arr.begin(),arr.end(),loc,comp())-arr.begin())-1;
        if(ind==-1)ind=0;
        arr[ind].inds.insert(upper_bound(arr[ind].inds.begin(),arr[ind].inds.end(),loc),loc);
        if(sz(arr[ind].inds)>2*bs){
            arr.insert(arr.begin()+ind+1,node());
            arr[ind+1].inds.resize(sz(arr[ind].inds)-bs);
            for(int i=bs;i<sz(arr[ind].inds);i++)arr[ind+1].inds[i-bs]=arr[ind].inds[i];
            arr[ind].inds.resize(bs);
            arr[ind+1].calc();
        }
        arr[ind].calc();
    }
    void erase(int loc){
        int ind=(upper_bound(arr.begin(),arr.end(),loc,comp())-arr.begin())-1;
        arr[ind].inds.erase(upper_bound(arr[ind].inds.begin(),arr[ind].inds.end(),loc)-1);
        if(!sz(arr[ind].inds))arr.erase(arr.begin()+ind);
        else arr[ind].calc();
    }
}solver;
void init(int N, int L, int* X){
    pos.resize(N);
    stage.resize(N);
    for(int i=0;i<N;i++)pos[i]=X[i],stage[i]=X[i];
    len=L;
    solver.build();
}
int update(int i, int y){
    solver.erase(pos[i]);
    pos[i]=y;
    solver.insert(pos[i]);
    return solver.getans();
}
//int main(){
//    cin.tie(NULL);
//    ios_base::sync_with_stdio(false);
//    int te[4]={10,15,17,20};
//    init(4,10,te);
//    printf("%d\n",update(2,16));
//    printf("%d\n",update(1,25));
//    printf("%d\n",update(3,35));
//    printf("%d\n",update(0,38));
//    printf("%d\n",update(2,0));
//    return 0;
//}