#include <bits/stdc++.h>
using namespace std;
#define pb push_back;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int in;
    int ahead=0;
    for(int i=0;i<n;i++){
    	cin>>in;
    	ahead=max(ahead-in,in);//either wait for him to get people or use the past best
    }
    printf("%d\n",ahead);
    return 0;
}