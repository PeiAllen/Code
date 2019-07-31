#include <bits/stdc++.h>

#define pb push_back
#define MAXN 100005

typedef long long ll;

using namespace std;

int len,cnt,vals[MAXN];
ll res;
map<ll,int> mp;
vector<int> connections[MAXN];

vector<int> split(string s){
	vector<int> v;
	string tmp = "";
	for(int i=0; i<s.size(); i++){
		if(s[i] == '.') v.pb(stoi(tmp)), tmp = "";
		else tmp.pb(s[i]);
	}
	if(tmp != "") v.pb(stoi(tmp));
	return v;
}

ll getHash(string &s){
	ll hsh = 0;
	for(int i=0; i<s.size(); i++)
		hsh = hsh*131+s[i];
	return hsh;
}

void solve(int node){
	int mx = 0;
	for(int check:connections[node]){
		mx = max(mx,vals[check]);
		solve(check);
	}
	res+=mx;
}

int main(){
	cin.tie(0); cin.sync_with_stdio(0);
	for(int qq=10; qq<=10; qq++){
		cin>>len;
		res = 1;
		for(int i=1; i<=len; i++){
			string s; cin>>s;
			vector<int> v = split(s);
			s = "";

			int prv = 0;
			for(int i=1; i<v.size(); i++){
				s+="."+to_string(v[i]);
				ll hsh = getHash(s);
				if(!mp.count(hsh))
					mp[hsh] = ++cnt;
				vals[mp[hsh]] = v[i];
				connections[prv].pb(mp[hsh]);
				prv = mp[hsh];
			}
		}
		solve(0);
		cout<<res<<endl;
		for(int i=0; i<=cnt; i++)
			connections[i].clear();
		mp.clear();
	}
}