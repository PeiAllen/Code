#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define A first
#define B second
template<typename T> int sz(const T &a){return int(a.size());}
int board[5][5];
bool done[5][5];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("input.txt","r",stdin);
    string nums;
    cin>>nums;
    int last=-1;
    vector<int> vals;
    for(int i=0;i<sz(nums);i++){
        if(nums[i]==','){
            vals.push_back(stoi(nums.substr(last+1,i)));
            last=i;
        }
    }
    vals.push_back(stoi(nums.substr(last+1)));
    int a;
    int earliest=INT_MIN;
    ll best=0;
    while(cin>>a){
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                done[i][j]=false;
                if(i!=0||j!=0){
                    cin>>a;
                }
                board[i][j]=a;
            }
        }
        bool fin=false;
        int used=0;
        for(auto x:vals){
            used++;
            for(int i=0;i<5&&!fin;i++) {
                for (int j = 0; j < 5&&!fin; j++) {
                    if(board[i][j]==x){
                        done[i][j]=true;
                        bool r=true,c=true;
                        for(int k=0;k<5;k++){
                            if(!done[k][j])r=false;
                            if(!done[i][k])c=false;
                        }
                        if(r||c){
                            fin=true;
                        }
                    }
                }
            }
            if(fin)break;
        }
        if(fin&&used>earliest){
            ll sum=0;
            for(int i=0;i<5;i++) {
                for (int j = 0; j < 5; j++) {
                    if(!done[i][j])sum+=board[i][j];
                }
            }
            earliest=used;
            best=sum*vals[used-1];
        }
    }
    printf("%lli\n",best);
    return 0;
}