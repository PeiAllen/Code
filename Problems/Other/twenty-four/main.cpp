#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
random_device rd;
set<string> ans;
vector<int> arr;
int ma=0;
void findsol(vector<int> left,int cur,string k, int bracket, int look, int end, int start,int wh){
	if(!left.size()){
		if(cur==look){
			while(bracket--)k="("+k;
			while(end--)k+=')';
			ans.insert(k);
		}
		int fin=0;
		if(wh==1){
			fin=24-look+cur;
		}
		else if(wh==2){
			fin=24+look-cur;
		}
		else if(wh==3){
			fin = (24 / look) * cur;
		}
		else{
			if(cur!=0&&(24*look)%cur==0) {
				fin = (24 * look) / cur;
			}
		}
		if(fin<=24)ma=max(ma,fin);
		return;
	}
	for(int i=0;i<left.size();i++){
		vector<int> te=left;
		swap(te[i],te[te.size()-1]);
		te.pop_back();
		findsol(te,cur*left[i],k+"*"+to_string(left[i]),bracket,look,end,start,wh);
		findsol(te,cur+left[i],k+"+"+to_string(left[i])+")",bracket+1,look,end,start,wh);
		findsol(te,cur-left[i],k+"-"+to_string(left[i])+")",bracket+1,look,end,start,wh);
		string te2=k;
		for(int i=0;i<bracket;i++){
			te2='('+te2;
			if(start!=0) {
				start += 1;
			}
		}
		findsol(te,left[i]-cur,te2.substr(0,start)+"("+to_string(left[i])+"-"+te2.substr(start,te2.size()-start)+")",0,look,end,start,wh);
		if(cur%left[i]==0) {
			findsol(te,cur/left[i],k+"/"+to_string(left[i]),bracket,look,end,start,wh);
		}
		if(cur!=0&&left[i]%cur==0){
			findsol(te,left[i]/cur,to_string(left[i])+"/"+te2,0,look,end,start,wh);
		}
		if(cur!=0&&look%cur==0&&te.size()==1){
			findsol(te, left[i],te2 + "*("+to_string(left[i]), 0, look / cur, end + 1,te2.size()+2,3);
		}
		if(look!=0&&cur%look==0&&te.size()==1&&cur/look!=0){
			findsol(te,left[i],te2+"/("+to_string(left[i]),0,cur/look,end+1,te2.size()+2,4);
		}
		if(te.size()==1){
			findsol(te, left[i],te2 + "+"+to_string(left[i]), 0, look-cur, end,te2.size()+1,1);
		}
		if(te.size()==1){
			findsol(te,left[i],te2+"-("+to_string(left[i]),0,cur-look,end+1,te2.size()+2,2);
		}
	}
}

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	arr.resize(4);
	for(;n>0;n--){
		ma=0;
		ans.clear();
		cin>>arr[0]>>arr[1]>>arr[2]>>arr[3];
		for (int i = 0; i < 4; i++) {
			vector<int> te = arr;
			swap(te[i], te[te.size() - 1]);
			te.pop_back();
			findsol(te, arr[i], to_string(arr[i]), 0,24,0,0,1);
		}
		printf("%d\n",ma);
		for(string x:ans){
			cout<<x<<"\n";
		}
	}
	return 0;
}