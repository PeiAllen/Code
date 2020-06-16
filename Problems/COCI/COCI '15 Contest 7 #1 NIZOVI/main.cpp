#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
int sp=0;
void printspace(){
    for(int i=0;i<sp;i++)printf(" ");
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string s;
    cin>>s;
    s=s+"}";
    for(int i=0;i<sz(s)-1;i++){
        if(s[i]=='{'){
            printspace();
            printf("{\n");
            sp+=2;
        }
        else if(s[i]=='}'){
            sp-=2;
            printspace();
            printf("}");
            if(s[i+1]!=',')printf("\n");
        }
        else if(s[i]==','){
            printf(",\n");
        }
        else{
            if(s[i-1]=='{'||s[i-1]=='}'||s[i-1]==',')printspace();
            printf("%c",s[i]);
            if(s[i+1]=='}')printf("\n");
        }
    }
    return 0;
}