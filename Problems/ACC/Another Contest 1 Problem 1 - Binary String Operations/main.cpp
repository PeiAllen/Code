#include <bits/stdc++.h>
#pragma GCC optimize "Ofast"
using namespace std;
typedef long long int lli;
struct block{
	vector<bool> arr;
	bool rever;
	int ans,prefix;
	int ends[2]={};
	block(){
		rever=false;
		ans=0;
		prefix=0;
	}
	inline void swape(block &x){
		swap(prefix,x.prefix);
		swap(ans,x.ans);
		swap(ends,x.ends);
		swap(rever,x.rever);
		arr.swap(x.arr);
	}
};
struct comparator{
	inline bool operator()(const int& lhs, const block& rhs)const{
		return lhs<rhs.prefix;
	}
};
vector<block> arr;
int maxblocksize;
int killblocksize;
inline void resolvere(int ind){
	if(arr[ind].rever){
		reverse(arr[ind].arr.begin(),arr[ind].arr.end());
		swap(arr[ind].ends[0],arr[ind].ends[1]);
		arr[ind].rever=false;
	}
}
inline void calc(int ind){
	resolvere(ind);
	arr[ind].ends[0]=0;
	while(arr[ind].ends[0]<arr[ind].arr.size()&&arr[ind].arr[arr[ind].ends[0]]){
		arr[ind].ends[0]+=1;
	}
	int am=0;
	arr[ind].ans=0;
	for(bool i:arr[ind].arr){
		if(i)am+=1;
		else am=0;
		arr[ind].ans=max(arr[ind].ans,am);
	}
	arr[ind].ends[1]=am;
}
inline void rever(int a, int b){
	int a1=(upper_bound(arr.begin(),arr.end(),a,comparator())-arr.begin())-1;
	int b1=(upper_bound(arr.begin(),arr.end(),b,comparator())-arr.begin())-1;
	pair<int,int> left={a1,a-arr[a1].prefix};
	pair<int,int> right={b1,b-arr[b1].prefix};
	if(left.first==right.first){
		resolvere(left.first);
		reverse(arr[left.first].arr.begin()+left.second,arr[left.first].arr.begin()+right.second+1);
		calc(left.first);
		return;
	}
	for(int i=0;i<(right.first-left.first-1)/2;i++)arr[left.first+i+1].swape(arr[right.first-i-1]);
	for(int i=left.first+1;i<right.first;i++){
		arr[i].rever=!arr[i].rever;
	}
	resolvere(left.first);
	resolvere(right.first);
	int te=min((int)arr[left.first].arr.size()-left.second,right.second+1);
	for(int i=0;i<te;i++){
		swap(arr[left.first].arr[i+left.second],arr[right.first].arr[right.second-i]);
	}
	if(te<(int)arr[left.first].arr.size()-left.second){
		reverse(arr[left.first].arr.begin()+left.second+te,arr[left.first].arr.end());
		arr[right.first].arr.insert(arr[right.first].arr.begin(),arr[left.first].arr.begin()+left.second+te,arr[left.first].arr.end());
		arr[left.first].arr.resize(left.second+te);
	}
	else if(te<right.second+1){
		reverse(arr[right.first].arr.begin(),arr[right.first].arr.begin()+right.second-te+1);
		arr[left.first].arr.insert(arr[left.first].arr.end(),arr[right.first].arr.begin(),arr[right.first].arr.begin()+right.second-te+1);
		arr[right.first].arr.erase(arr[right.first].arr.begin(),arr[right.first].arr.begin()+right.second-te+1);
	}
	int offset=0;
	while(arr[left.first+offset].arr.size()>killblocksize){
		arr.insert(arr.begin()+left.first+offset+1,block());
		arr[left.first+offset+1].arr.insert(arr[left.first+offset+1].arr.begin(),arr[left.first+offset].arr.begin()+maxblocksize,arr[left.first+offset].arr.end());
		arr[left.first+offset].arr.resize(maxblocksize);
		calc(left.first+offset);
		offset+=1;
	}
	calc(left.first+offset);
	while(arr[right.first+offset].arr.size()>killblocksize){
		arr.insert(arr.begin()+right.first+offset+1,block());
		arr[right.first+offset+1].arr.insert(arr[right.first+offset+1].arr.begin(),arr[right.first+offset].arr.begin()+maxblocksize,arr[right.first+offset].arr.end());
		arr[right.first+offset].arr.resize(maxblocksize);
		calc(right.first+offset);
		offset+=1;
	}
	calc(right.first+offset);
	for(left.first+=1;left.first<arr.size();left.first++){
		arr[left.first].prefix=arr[left.first-1].prefix+arr[left.first-1].arr.size();
	}
}
inline int query(int a, int b){
	int a1=(upper_bound(arr.begin(),arr.end(),a,comparator())-arr.begin())-1;
	int b1=(upper_bound(arr.begin(),arr.end(),b,comparator())-arr.begin())-1;
	pair<int,int> left={a1,a-arr[a1].prefix};
	pair<int,int> right={b1,b-arr[b1].prefix};
	resolvere(left.first);
	resolvere(right.first);
	if(left.first==right.first){
		int am=0;
		int ans=0;
		for(int i=left.second;i<=right.second;i++){
			if(arr[left.first].arr[i])am+=1;
			else am=0;
			ans=max(ans,am);
		}
		return ans;
	}
	int ans=0;
	int am=0;
	for(int i=left.second;i<arr[left.first].arr.size();i++){
		if(arr[left.first].arr[i])am+=1;
		else am=0;
		ans=max(ans,am);
	}
	for(int i=left.first+1;i<right.first;i++){
		ans=max(ans,arr[i].ans);
		ans=max(ans,arr[i].ends[arr[i].rever?1:0]+am);
		if(arr[i].ends[arr[i].rever?0:1]==arr[i].arr.size()){
			am+=arr[i].ends[arr[i].rever?0:1];
		}
		else{
			am=arr[i].ends[arr[i].rever?0:1];
		}
		ans=max(ans,am);
	}
	for(int i=0;i<=right.second;i++){
		if(arr[right.first].arr[i])am+=1;
		else am=0;
		ans=max(ans,am);
	}
	return ans;
}
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	int n,q;
	cin>>n>>q;
	maxblocksize=1.4*(double)sqrt(n);
	killblocksize=3*maxblocksize;
	int othblock=1.7*(double)killblocksize;
	string in;
	cin>>in;
	int ind=0;
	arr.push_back(block());
	for(int i=0;i<in.size();i++){
		if(arr[ind].arr.size()==maxblocksize){
			arr.push_back(block());
			ind+=1;
		}
		arr[ind].arr.push_back((in[i]=='1'?1:0));
	}
	for(int i=0;i<=ind;i++)calc(i);
	for(int i=1;i<arr.size();i++){
		arr[i].prefix=arr[i-1].prefix+arr[i-1].arr.size();
	}
	int a,b,c;
	for(int i=0;i<q;i++){
		cin>>a>>b>>c;
		if(a==1){
			rever(b,b+c-1);
		}
		else{
			printf("%d\n",query(b,b+c-1));
		}
		if(arr.size()>othblock){
			vector<block> te;
			int ind=0;
			te.push_back(block());
			for(int j=0;j<arr.size();j++){
				resolvere(j);
				for(int x:arr[j].arr){
					if(te[ind].arr.size()==maxblocksize){
						te.push_back(block());
						ind+=1;
					}
					te[ind].arr.push_back(x);
				}
			}
			arr=te;
			for(int j=0;j<=ind;j++)calc(j);
			for(int j=1;j<arr.size();j++){
				arr[j].prefix=arr[j-1].prefix+arr[j-1].arr.size();
			}
		}
	}
	return 0;
}