#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}

int main(int argc, char* argv[]){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    srand(atoi(argv[1]));
    int n=5;
    int c=(rand()%((n*(n-1))/2))+1;
    printf("%d %d %d\n",n,2,c);
    for(int i=0;i<n;i++){
        printf("%d %d\n",rand()%11,rand()%11);
    }
    return 0;
}