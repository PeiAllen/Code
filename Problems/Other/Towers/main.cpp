#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int last,cur;
    int lastam=0,curam;
    cin>>last;
    int ans=0;
    for(int i=1;i<n;i++){
        cin>>cur;
        if(cur>last){
            lastam++;
            curam=1;
            if(lastam==2)ans++;
        }
        else curam=0;
        lastam=curam,last=cur;
    }
    printf("%d\n",ans);
    return 0;
}