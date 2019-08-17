#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
typedef pair <lli, lli> pll;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int x,y,h,v;
	int t;
	cin>>x>>y>>h>>v>>t;
	int time=INT_MAX;
	if(x==0&&y==0){
		if((h>=3&&v>=2)||(v>=3&&h>=2))time=1;
		else time=INT_MAX;
	}
	else{
		if(x>y){
			int st=0;
			for(;st<=((y+v)/2);st++){
				int lo=max(0,y-st*2);
				int hi=max(0,y+v-1-st*2);
				int rot=0;
				while(lo<hi){
					int mid=(lo+hi)/2;
					if(mid*2+st>=x){
						hi=mid;
						if(mid*2+st<x+h)time=min(time,mid+st);
					}
					else{
						lo=mid+1;
					}
				}
				if(lo>=0&&st*2+lo>=y&&st*2+lo<y+v) {
					if (lo * 2 + st >= x) {
						if (lo * 2 + st < x + h)time = min(time, lo + st);
					}
				}
				if(hi>=0&&st*2+hi>=y&&st*2+hi<y+v) {
					if (hi * 2 + st >= x) {
						if (hi * 2 + st < x + h)time = min(time, hi + st);
					}
				}
			}
		}
		else{
			int st=0;
			for(;st<=((x+h)/2);st++){
				int lo=max(0,x-st*2);
				int hi=max(0,x+h-1-st*2);
				int rot=0;
				while(lo<hi){
					int mid=(lo+hi)/2;
					if(mid*2+st>=y){
						hi=mid;
						if(mid*2+st<y+v)time=min(time,mid+st);
					}
					else{
						lo=mid+1;
					}
				}
				if(lo>=0&&st*2+lo>=x&&st*2+lo<x+h) {
					if (lo * 2 + st >= y) {
						if (lo * 2 + st < y + v)time = min(time, lo + st);
					}
				}
				if(hi>=0&&st*2+hi>=x&&st*2+hi<x+h) {
					if (hi * 2 + st >= y) {
						if (hi * 2 + st < y + v)time = min(time, hi + st);
					}
				}
			}
		}
	}
	if(time<t)printf("YES\n");
	else printf("NO\n");
	return 0;
}