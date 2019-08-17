#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
int arr[4097];
vector<pii> moves;
void reverarray(int l, int r){
	while(l<r){
		moves.push_back({l,r});
		swap(arr[l++],arr[r--]);
	}
}
int findmid(int l, int mid,int r){
	vector<int> te;
	te.insert(te.begin(),arr+l,arr+r+1);
	sort(te.begin(),te.end());
	return te[mid-l];
}
void merge(int l, int mid, int r){//mid inclusive, not nessccarily half half
	if(mid<l||mid>=r||r<l)return;
	if(arr[mid]<=arr[mid+1])return;
	int temid=findmid(l,mid,r);
	int lestart=(upper_bound(arr+l,arr+mid+1,temid)-(arr+l))+l;
	int riend=mid+1+(mid-lestart);//inclusive
	reverarray(lestart,mid);
	reverarray(mid+1,riend);
	reverarray(lestart,riend);
	merge(l,lestart-1,mid);
	merge(mid+1,riend,r);
}
void mergesort(int l, int r){
	if(l==r)return;
	int mid=(l+r)/2;
	mergesort(l,mid);
	mergesort(mid+1,r);
	merge(l,mid,r);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	mergesort(1,n);
	vector<pii> ans;
	ans.insert(ans.end(),moves.begin(),moves.end());
	moves.clear();
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	mergesort(1,n);
	reverse(moves.begin(),moves.end());
	printf("%d\n",ans.size()+moves.size());
	for(pii x:ans)printf("%d %d\n",x.first,x.second);
	for(pii x:moves)printf("%d %d\n",x.first,x.second);
    return 0;
}