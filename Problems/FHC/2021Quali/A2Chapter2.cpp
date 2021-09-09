#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int SZ(const T &a){return int(a.size());}
int dist[27][27];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("consistency_chapter_2_input.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    cin>>t;
    for(int cs=1;cs<=t;cs++){
        string s;
        int k;
        cin>>s>>k;
        char a,b;
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++)dist[i][j]=INT_MAX;
            dist[i][i]=0;
        }
        for(int i=0;i<k;i++){
            cin>>a>>b;
            dist[a-'A'][b-'A']=1;
        }
        for(int mid=0;mid<26;mid++){
            for(int st=0;st<26;st++){
                if(dist[st][mid]!=INT_MAX)for(int en=0;en<26;en++){
                    if(dist[mid][en]!=INT_MAX){
                        dist[st][en]=min(dist[st][en],dist[st][mid]+dist[mid][en]);
                    }
                }
            }
        }
        int best=INT_MAX;
        for(char i='A';i<='Z';i++){
            int am=0;
            for(auto x:s){
                if(dist[x-'A'][i-'A']==INT_MAX){
                    am=INT_MAX;
                    break;
                }
                am+=dist[x-'A'][i-'A'];
            }
            best=min(best,am);
        }
        if(best==INT_MAX)best=-1;
        printf("Case #%d: %d\n",cs,best);
    }
    return 0;
}