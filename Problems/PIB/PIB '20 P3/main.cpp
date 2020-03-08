#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=1e5+1;
vector<int> length;
pii arr[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int q;
    cin>>q;
    int a,b;
    int last=-1;
    int i=1;
    while(q--){
        cin>>a;
        if(a==1){
            last++;
            length.push_back(1);
            arr[i]={last,1};
            i++;
        }
        else if(a==2){
            length[last]++;
            arr[i]={last,length[last]};
            i++;
        }
        else{
            cin>>b;
            printf("%d\n",arr[b].second%2==length[arr[b].first]%2);
        }
    }
    return 0;
}