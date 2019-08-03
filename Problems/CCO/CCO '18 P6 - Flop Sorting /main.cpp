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
bool issorted(int l, int r){
	for(int i=l;i<r;i++)if(arr[i]>arr[i+1])return false;
	return true;
}
int findmid(int l, int r){
	vector<int> te;
	te.insert(te.begin(),arr+l,arr+r+1);
	sort(te.begin(),te.end());
	return te[(r-l)/2];
}
void mergesort(int l, int r){
	int mid=(l+r)/2;
	if(r-l+1<=3){
		if(l==r)return;
		if(r-l+1==2) {
			if (arr[l] > arr[r]) {
				moves.push_back({l, r});
				swap(arr[l], arr[r]);
			}
			return;
		}
		if(arr[l]>arr[l+1]){
			moves.push_back({l, l+1});
			swap(arr[l], arr[l+1]);
		}
		if(arr[l+1]>arr[r]){
			moves.push_back({l+1, r});
			swap(arr[l+1], arr[r]);
		}
		if(arr[l]>arr[l+1]){
			moves.push_back({l, l+1});
			swap(arr[l], arr[l+1]);
		}
		return;
	}
	mergesort(l, mid);
	mergesort(mid + 1, r);
	int midval=findmid(l,r);
	int le=l;
	while(le<=mid&&arr[le]<=midval){
		le++;
	}
	int ri=r;
	while(ri>mid&&arr[ri]>midval){
		ri--;
	}
	reverarray(le,mid);
	reverarray(mid+1,ri);
	int temid=((ri-le+1)%2?mid-1:mid);
	for(int i=0;i<(ri-mid);i++){
		swap(arr[temid-i],arr[mid+i+1]);
		moves.push_back({temid-i,mid+i+1});
	}
	if(!issorted(l,mid))mergesort(l,mid);
	if(!issorted(mid+1,r))mergesort(mid+1,r);
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