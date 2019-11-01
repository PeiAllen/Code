#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
typedef pair<long double, long double> pld;
void sc(){}
template<typename T,typename... Args>
void sc(T& a, Args&... args) {cin>>a,sc(args...);}
template<typename T>
void pr(T a){cout<<a;}
template<typename T,typename... Args>
void pr(T a, Args... args) {cout<<a<<" ",pr(args...);}
template<typename T>
void prl(T a){cout<<a<<"\n";}
template<typename T,typename... Args>
void prl(T a, Args... args) {cout<<a<<" ",prl(args...);}
template<typename T>
int sz(const T &a){return (int)a.size();}
template<typename T>
constexpr const T& _max(const T & a,const T & b){return max(a,b);}
template<typename T,typename... Args>
constexpr const T& _max(const T & a, Args... args){return max(a,_max(args...));}
#define max(...) _max(__VA_ARGS__)
template<typename T>
constexpr const T& _min(const T &a,const T &b){return min(a,b);}
template<typename T,typename... Args>
constexpr const T& _min(const T &a, Args... args){return min(a,_min(args...));}
#define min(...) _min(__VA_ARGS__)
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
long double prec=1e-13;
long double arr[2][3];
long double area[2];
long double totalarea=0;
pld LI(const pld &p1, const pld &q1, const pld &p2, const pld &q2) {
	long double A1 = q1.second - p1.second, B1 = p1.first - q1.first, C1 = A1 * p1.first + B1 * p1.second;
	long double A2 = q2.second - p2.second, B2 = p2.first - q2.first, C2 = A2 * p2.first + B2 * p2.second, det = A1 * B2 - A2 * B1;
	if (abs(det) <= prec) return {numeric_limits<long double>::infinity(),-1};
	return {(B2 * (C1 / det) - B1 * (C2 / det)), (A1 * (C2 / det) - A2 * (C1 / det))};
}
int ccw(const pld &a, const pld &b, const pld &c) { // -1 if clockwise, 0 if collinear, +1 if counterclockwise
	long double area2 = (b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first);
	if (area2 < -prec) return -1;
	else if (area2 > prec) return +1;
	else return 0;
}
long double distanceTo(const pld &cur,const pld &that)  { long double dx = cur.first - that.first, dy = cur.second - that.second; return sqrt(dx * dx + dy * dy); }
bool onSegment(const pld &cur,const pld &p, const pld &q)  {
	return abs(distanceTo(cur,p) + distanceTo(cur,q) - distanceTo(p,q)) <= prec;
}
bool LSI(const pld &p1, const pld &q1, const pld &p2, const pld &q2) {
	int o1 = ccw(p1, q1, p2), o2 = ccw(p1, q1, q2), o3 = ccw(p2, q2, p1), o4 = ccw(p2, q2, q1);
	if (o1 != o2 && o3 != o4) return true;
	if (o1 == 0 && onSegment(p2,p1, q1)) return true;
	if (o2 == 0 && onSegment(q2,p1, q1)) return true;
	if (o3 == 0 && onSegment(p1,p2, q2)) return true;
	if (o4 == 0 && onSegment(q1,p2, q2)) return true;
	return false;
}
bool lessthan(long double a, long double b){
	return a+prec<b;
}
bool equal(long double a, long double b){
	return abs(a-b)<=prec;
}
long double check(long double overlap){
	long double locs[2][3]={{-1,overlap,overlap+arr[0][0]},{-1,arr[0][0],arr[0][0]+arr[1][0]}};
	pld tip[2];
	rep(i,0,2){
		long double height=2*(area[i]/arr[i][0]);
		long double oth=sqrt(arr[i][2]*arr[i][2]-height*height);
		long double xcord=locs[i][1]+((!lessthan(oth,arr[i][0])&&!equal(oth,arr[i][0]))?-1:1)*sqrt(arr[i][1]*arr[i][1]-height*height);
		tip[i]={xcord,height};
	}
	pair<long double,int> left=max(make_pair(arr[0][0],1),make_pair(overlap,0));
	if(equal(arr[0][0],overlap)){
		long double top[2]={tip[0].second,tip[1].second},bot[2]={tip[0].first-overlap,tip[1].first-arr[0][0]};
		bool neg[2]={bot[0]<0,bot[1]<0};
		if(neg[0]&&!neg[1]){
			left={arr[0][0],1};
		}
		else if(neg[1]&&!neg[0]){
			left={overlap,0};
		}
		else{
			bot[0]=bot[0];
			bot[1]=bot[1];
			if(top[0]/bot[0]<top[1]/bot[1])left={overlap,0};
			else left={arr[0][0],1};
		}
	}
	long double right=min(overlap+arr[0][0],arr[1][0]+arr[0][0]);
	set<pii> lines;
	vector<pld> points;
	points.push_back({left.first,0});
	pld cur{left.first,0};
	pii cure={left.second,1};
	rep(i,0,2){
		rep(j,1,3){
			if(j==1&&i==left.second)continue;
			lines.insert({i,j});
		}
	}
	int wh=0;//1 means to the right, 2 means to the left
	while(1){
		pld next={numeric_limits<long double>::infinity(),-1};
		pld nexte={-1,-1};
		long double dist=numeric_limits<long double>::infinity();
		for(pii x:lines){
			pld te=LI({locs[x.first][x.second],0},tip[x.first],{locs[cure.first][cure.second],0},tip[cure.first]);
			if(te.first==numeric_limits<long double>::infinity())continue;
			if(equal(te.first,cur.first)&&equal(te.second,cur.second))continue;
			if(wh){
				if(wh==1){
					if(lessthan(te.first,cur.first))continue;
				}
				else{
					if(!lessthan(te.first,cur.first)&&!equal(te.first,cur.first))continue;
				}
			}
			long double tedi=sqrt((te.first-cur.first)*(te.first-cur.first)+(te.second-cur.second)*(te.second-cur.second));
			if((dist==numeric_limits<long double>::infinity()||lessthan(tedi,dist))){
				if(LSI({locs[x.first][x.second],0},tip[x.first],{locs[cure.first][cure.second],0},tip[cure.first])){
					next = {te.first, te.second};
					nexte = x;
					dist=tedi;
				}
			}
		}
		if(next.first==numeric_limits<long double>::infinity()){
			break;
		}
		wh=cure.first;
		lines.erase(nexte);
		points.push_back(next);
		cur=next;
		cure=nexte;
	}
	points.push_back({right,0});
	long double dbcnt=0;
	rep(i,0,sz(points)){
		dbcnt+=points[i].first*(i+1==sz(points)?points[0].second:points[i+1].second)/2;
	}
	rep(i,0,sz(points)){
		dbcnt-=points[i].second*(i+1==sz(points)?points[0].first:points[i+1].first)/2;
	}
	dbcnt=abs(dbcnt);
	return totalarea-dbcnt;
}
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	long double ans=numeric_limits<long double>::infinity();
	rep(i,0,2)rep(j,0,3)sc(arr[i][j]);
	long double arrte[2][3];
	rep(i,0,2)rep(j,0,3)arrte[i][j]=arr[i][j];
	int shuf[2][3]={{0,1,2},{0,1,2}};
	rep(i,0,2){
		long double perim=0;
		rep(j,0,3)perim+=arr[i][j];
		area[i]=sqrt(perim*(perim-2*arr[i][0]))*sqrt((perim-2*arr[i][1])*(perim-2*arr[i][2]))/4;
		totalarea+=area[i];
	}
	do{
		rep(j,0,3)arr[0][shuf[0][j]]=arrte[0][j];
		do{
			rep(j,0,3)arr[1][shuf[1][j]]=arrte[1][j];
			long double lo=0,hi=arr[0][0]+arr[1][0];
			while((hi-lo)/lo>=prec){
				long double m1=lo+(hi-lo)/3,m2=hi-(hi-lo)/3;
				long double a=check(m1);
				long double b=check(m2);
				if(a<b)hi=m2;
				else if(a>b)lo=m1;
				else lo=m1,hi=m2;
			}
			ans=min(ans,check(lo),check(hi));
		}while(next_permutation(shuf[1],shuf[1]+3));
	} while(next_permutation(shuf[0],shuf[0]+3));
	cout<<fixed<<setprecision(10)<<ans<<"\n";
	return 0;
}