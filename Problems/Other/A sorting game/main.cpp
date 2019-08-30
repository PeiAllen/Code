#include <bits/stdc++.h>
using namespace std;
#define pb push_back;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
const int MAXN=3e5+1;
int bit[MAXN];

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	int arr[n];
	priority_queue<pii,vector<pii>,greater<pii>> q;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		q.push({i,-arr[i]});
	}
	int ma=0;
	while(q.size()){

	}
    return 0;
}