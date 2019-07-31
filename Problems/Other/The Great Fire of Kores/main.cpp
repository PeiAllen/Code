#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
struct tri{
	lli x,y,ind;
	bool comm;
	tri(lli a=0, lli b=0, bool c=false,lli d=0):x(a),y(b),comm(c),ind(d){}
};
struct bunker{
	lli x,y;
	bunker(lli a=0, lli b=0):x(a),y(b){}
};
struct sortc{
	bool operator()(const tri &lhs, const tri &rhs){
		if(lhs.x==rhs.x){
			if(lhs.comm&&!rhs.comm) return 0;
			else if(rhs.comm&&!lhs.comm)return 1;
			else return lhs.y>rhs.y;
		}
		return lhs.x<rhs.x;
	}
};
struct sortc2{
	bool operator()(const tri &lhs, const tri &rhs){
		if(lhs.x==rhs.x){
			if(lhs.comm&&!rhs.comm) return 0;
			else if(rhs.comm&&!lhs.comm)return 1;
			else return lhs.y>rhs.y;
		}
		return lhs.x>rhs.x;
	}
};
struct bestupcomp{
	bool operator()(const bunker &lhs, const bunker &rhs){
		return lhs.y<rhs.y;
	}
};
struct bestdowncomp{
	bool operator()(const bunker &lhs, const bunker &rhs){
		return lhs.y>rhs.y;
	}
};
inline lli dist(lli x1,lli y1, lli x2, lli y2){
	return abs(x1-x2)+abs(y1-y2);
}
lli besttr[100001];
set<bunker,bestupcomp> bestup;
set<bunker,bestdowncomp> bestdown;
inline lli which(lli x,lli y){
	auto up=bestup.lower_bound(bunker(0,y));
	auto down=bestdown.lower_bound(bunker(0,y));
	if(up==bestup.end()){
		return dist(x,y,down->x,down->y);
	}
	if(down==bestdown.end()){
		return dist(x,y,up->x,up->y);
	}
	return min(dist(x,y,up->x,up->y),dist(x,y,down->x,down->y));
}
void insertup(tri bunk){
	bool stop=false;
	if(bestup.empty()){
		bestup.insert(bunker(bunk.x,bunk.y));
		return;
	}
	auto og=bestup.lower_bound(bunker(0,bunk.y));
	auto it=og;
	if(og!=bestup.begin()){
		it--;
	}
	else{
		stop=true;
	}
	if(og!=bestup.end()&&og->y==bunk.y)bestup.erase(og);
	bestup.insert(bunker(bunk.x,bunk.y));
	while(!stop){
		if(dist(bunk.x,it->y,bunk.x,bunk.y)<=dist(bunk.x,it->y,it->x,it->y)){
			auto te=it;
			if(it!=bestup.begin())it--;
			else stop=true;
			bestup.erase(te);
		}
		else{
			break;
		}
	}
}
void insertdown(tri bunk){
	bool stop=false;
	if(bestdown.empty()){
		bestdown.insert(bunker(bunk.x,bunk.y));
		return;
	}
	auto og=bestdown.lower_bound(bunker(0,bunk.y));
	auto it=og;
	if(og!=bestdown.begin()){
		it--;
	}
	else{
		stop=true;
	}
	if(og!=bestdown.end()&&og->y==bunk.y)bestdown.erase(og);
	bestdown.insert(bunker(bunk.x,bunk.y));
	while(!stop){
		if(dist(bunk.x,it->y,bunk.x,bunk.y)<=dist(bunk.x,it->y,it->x,it->y)){
			auto te=it;
			if(it!=bestdown.begin())it--;
			else stop=true;
			bestdown.erase(te);
		}
		else{
			break;
		}
	}
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	lli n,m;
	cin>>n;
	vector<tri> linesweep;
	lli x,y;
	for(lli i=0;i<n;i++){
		cin>>x>>y;
		linesweep.push_back(tri(x,y,true,i));
		besttr[i]=LLONG_MAX;
	}
	cin>>m;
	for(lli i=0;i<m;i++){
		cin>>x>>y;
		linesweep.push_back(tri(x,y,false));
	}
	sort(linesweep.begin(),linesweep.end(),sortc());
	for(tri cur:linesweep){
		if(cur.comm){
			if(bestup.size()){
				besttr[cur.ind]=min(besttr[cur.ind],which(cur.x,cur.y));
			}
		}
		else{
			insertup(cur);
			insertdown(cur);
		}
	}
	bestup.clear();
	bestdown.clear();
	sort(linesweep.begin(),linesweep.end(),sortc2());
	for(tri cur:linesweep){
		if(cur.comm){
			if(bestup.size()){
				besttr[cur.ind]=min(besttr[cur.ind],which(cur.x,cur.y));
			}
		}
		else{
			insertup(cur);
			insertdown(cur);
		}
	}
	lli ans=0;
	for(lli i=0;i<n;i++){
		ans+=besttr[i];
	}
	printf("%lli\n",ans);
	return 0;
}