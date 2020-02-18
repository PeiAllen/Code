#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e6+1;
int cnt[3][MAXN];
int permu[3]={0,1,2};
int cur[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string n;
    cin>>n;
    int ns=(int)n.size();
    for(int i=0;i<ns;i++){
        cur[i]=n[i]-'A';
        for(int j=0;j<3;j++)cnt[j][i+1]=cnt[j][i];
        cnt[n[i]-'A'][i+1]+=1;
    }
    int ans=(int)1e7;
    do{
        for(int test=0;test<=cnt[permu[0]][ns];test++){
            int am[3][3];
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    am[i][j]=0;
                }
            }
            for(int i=0;i<3;i++){
                am[i][permu[0]]+=cnt[i][test];
                am[i][permu[1]]+=cnt[i][test+cnt[permu[1]][ns]]-cnt[i][test];
                am[i][permu[2]]+=cnt[i][test+cnt[permu[1]][ns]+cnt[permu[2]][ns]]-cnt[i][test+cnt[permu[1]][ns]];
                am[i][permu[0]]+=cnt[i][ns]-cnt[i][test+cnt[permu[1]][ns]+cnt[permu[2]][ns]];
            }
            int cnt=0;
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    if(i!=j) {
                        int mi = min(am[i][j], am[j][i]);
                        am[i][j] -= mi;
                        am[j][i] -= mi;
                        cnt += mi;
                    }
                }
            }
            int cnt2=0;
            for(int i=0;i<3;i++) {
                for (int j = 0; j < 3; j++) {
                    if(i!=j) {
                        cnt2 += am[i][j];
                    }
                }
            }
            cnt2=cnt2*2/3;
            ans=min(ans,cnt+cnt2);
        }
    }while(next_permutation(permu,permu+3));
    printf("%d\n",ans);
    return 0;
}