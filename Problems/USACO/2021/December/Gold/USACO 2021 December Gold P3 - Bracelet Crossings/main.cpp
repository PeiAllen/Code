#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define A first
#define B second
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=51;
vector<int> locations[MN];
vector<int> arr[MN][MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t,n,m,a,b;
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;i++)locations[i]=vector<int>();
        for(int i=0;i<m;i++){
            cin>>a;
            for(int j=1;j<=n;j++)arr[i][j]=vector<int>();
            for(int j=0;j<a;j++){
                cin>>b;
                arr[i][b].push_back(j);
            }
            for(int j=1;j<=n;j++){
                if(sz(arr[i][j]))locations[j].push_back(i);
            }
        }
        bool work=true;
        for(int i=1;i<=n;i++){
            for(int j=1;j<sz(locations[i]);j++)if(locations[i][j]!=locations[i][j-1]+1)work=false;
            for(int j=i+1;j<=n;j++){
                set<int> type;
                for(int k=0;k<m;k++){
                    if(sz(arr[k][i])&&sz(arr[k][j])){
                        if(arr[k][i][0]<arr[k][j][0]){
                            if(arr[k][i][1]>arr[k][j][0]&&arr[k][i][1]<arr[k][j][1])work=false;
                            else if(arr[k][i][1]>arr[k][j][1])type.insert(0);
                            else type.insert(1);
                        }
                        else{
                            if(arr[k][j][1]>arr[k][i][0]&&arr[k][j][1]<arr[k][i][1])work=false;
                            else if(arr[k][j][1]>arr[k][i][1])type.insert(2);
                            else type.insert(3);
                        }
                    }
                }
                if(sz(type)>1)work=false;
                if(sz(type)==1){
                    if(*type.begin()==0){
                        if(locations[j][0]<locations[i][0]||locations[j].back()>locations[i].back())work=false;
                    }
                    else if(*type.begin()==2){
                        if(locations[j][0]>locations[i][0]||locations[j].back()<locations[i].back())work=false;
                    }
                }
            }
        }
        if(work)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}