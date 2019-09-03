#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string a;
    getline(cin,a);
    int sum=0;
    int last=0;
    int neg=1;
    for(int i=0;i<a.size();i++){
        if(isdigit(a[i])){
            last=last*10+(a[i]-'0');
        }
        else{
            sum+=last*neg;
            neg=1;
            last=0;
            if(a[i]=='-')neg=-1;
        }
    }
    sum+=last;
    printf("%d\n",sum);
    return 0;
}