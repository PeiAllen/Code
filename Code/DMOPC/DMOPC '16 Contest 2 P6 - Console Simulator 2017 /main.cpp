#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
vector<string> toprint;
struct node{
	string path;
	string name;
	map<string,node*> contains;
	node(string a="", string b=""):path(a),name(b){}
	void print(){
		for(auto x:contains)x.second->print();
		toprint.push_back(name);
	}
};
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	string in;
	int n;
	getline(cin,in);
	n=stoi(in);
	node* root= new node();
	root->name="~";
	root->path="~/";
	int before=-1;
	stack<node*> st;
	int a;
	string b;
	st.push(root);
	for(int i=0;i<n;i++){
		getline(cin,in);
		istringstream ss(in);
		ss>>a>>b;
		int diff=before-a+1;
		if(diff>0)while(diff--)st.pop();
		node* te= new node();
		te->name=b;
		te->path=st.top()->path+b+"/";
		st.top()->contains[b]=te;
		st.push(te);
		before=a;
	}
	getline(cin,in);
	node *cur=root;
	while(in!="exit"){
		istringstream ss(in);
		vector<string> input;
		while(ss){
			string te;
			ss>>te;
			input.push_back(te);
		}
		input.pop_back();
		if(input[0]=="ls"){
			int off=0;
			if(input.size()>1&&input[1]=="-r"){
				off+=1;
				for(auto x:cur->contains)x.second->print();
			}
			else{
				for(auto x:cur->contains)toprint.push_back(x.first);
			}
			if(input.size()>2){
				regex reg(input[3+off]);
				vector<string> temp;
				for(string x:toprint){
					if(regex_search(x,reg)){
						temp.push_back(x);
					}
				}
				toprint=temp;
			}
			sort(toprint.begin(),toprint.end());
			for(string x:toprint)cout<<x<<"\n";
			if(!toprint.size())cout<<"\n";
			cout<<"\n";
			toprint.clear();
		}
		else if(input[0]=="cd"){
			int le=0;
			int siz=1;
			if(input[1].substr(0,2)=="~/"){
				cur=root;
				le=2;
			}
			while(le<input[1].size()) {
				while (le+siz<input[1].size()&&input[1][le + siz] != '/')siz++;
				cur=cur->contains[input[1].substr(le,siz)];
				le+=(siz+1);
				siz=1;
			}
		}
		else if(input[0]=="mkdir"||input[0]=="touch"){
			node* te= new node();
			te->name=input[1];
			te->path=cur->path+input[1]+"/";
			cur->contains[input[1]]= te;
		}
		else{
			cout<<cur->path<<"\n\n";
		}
		getline(cin,in);
	}
	return 0;
}