#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,t;
    cin>>t>>n;
    bool work=true;
    char a;
    for(int i=0;i<2*n+1;i++){
        for(int j=0;j<2*n+1;j++){
            cin>>a;
            if(a=='B'){
                if(abs(i-n)+abs(j-n)>t)work=false;
            }
            if(a=='W'&&i==n&&j==n&&t==0)work=false;
        }
    }
    if(work)printf("YES\n");
    else printf("NO\n");
    return 0;
}