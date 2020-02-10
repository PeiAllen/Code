#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    setbuf(stdout,NULL);
    int n;
    cin>>n;
    int cur=1;
    int in;
    for(int i=2;i<=n;i++){
        printf("? %d %d\n",cur,i);
        cin>>in;
        if(in)cur=i;
    }
    printf("! %d\n",cur);
    return 0;
}