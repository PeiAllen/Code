#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
int arr[2];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int type;
    char x;
    char y;
    int n;
    while(1){
        cin>>type;
        if(type==1){
            cin>>x>>n;
            arr[x-'A']=n;
        }
        else if(type==2){
            cin>>x;
            printf("%d\n",arr[x-'A']);
        }
        else if(type==3){
            cin>>x>>y;
            arr[x-'A']+=arr[y-'A'];
        }
        else if(type==4){
            cin>>x>>y;
            arr[x-'A']*=arr[y-'A'];
        }
        else if(type==5){
            cin>>x>>y;
            arr[x-'A']-=arr[y-'A'];
        }
        else if(type==6){
            cin>>x>>y;
            arr[x-'A']=abs(arr[x-'A'])/abs(arr[y-'A'])*(((arr[x-'A']<0)+(arr[y-'A']<0))%2?-1:1);
        }
        else break;
    }
    return 0;
}