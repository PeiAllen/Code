#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=1001;
struct point{
    ll x,y;
    point(ll A, ll B){
        x=A,y=B;
    }
    point(){
        x=0,y=0;
    }
};
struct lineseg{
    point l,r;
    lineseg(point A, point B){
        l=A,r=B;
    }
};
int ccw(const point &a, const point &b, const point &c) { // -1 if clockwise, 0 if collinear, +1 if counterclockwise
    ll area2 = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    if (area2 < 0) return -1;
    else if (area2 > 0) return +1;
    else return 0;
}
bool onSegment(point p, point q, point r)
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
        return true;
    return false;
}

bool LSI(lineseg a, lineseg b) {
    point p1=a.l,q1=a.r, p2=b.l, q2=b.r;
    int o1 = ccw(p1, q1, p2), o2 = ccw(p1, q1, q2), o3 = ccw(p2, q2, p1), o4 = ccw(p2, q2, q1);
    if (o1 != o2 && o3 != o4) return true;
    if (o1 == 0 && onSegment(p2,p1, q1)) return true;
    if (o2 == 0 && onSegment(q2,p1, q1)) return true;
    if (o3 == 0 && onSegment(p1,p2, q2)) return true;
    if (o4 == 0 && onSegment(q1,p2, q2)) return true;
    return false;
}
point key[MAXN];
point triangles[MAXN][3];
bool good[MAXN];
int main(){//seems like theres a ds that allows sublinear queries to n line segments for intersection
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,t;
    cin>>n>>t;
    for(int i=0;i<n;i++){
        cin>>key[i].x>>key[i].y;
        good[i]=true;
    }
    for(int i=0;i<t;i++){
        for(int j=0;j<3;j++)cin>>triangles[i][j].x>>triangles[i][j].y;
    }
    int cnt=0;
//    for(int i=0;i<n;i++){
//        lineseg top(key[i],point(key[i].x,1e9)),bot(key[i],point(key[i].x,-1e9)),left(key[i],point(-1e9,key[i].y)),right(key[i],point(1e9,key[i].y));
//        bool curgood=true;
//        for(int j=0;j<t;j++){
//            bool topinter=false,botinter=false,leftinter=false,rightinter=false;
//            for(int k=0;k<3;k++){
//                if (LSI(top, lineseg(triangles[j][k], triangles[j][(k + 1) % 3])))topinter=true;
//                if (LSI(bot, lineseg(triangles[j][k], triangles[j][(k + 1) % 3])))botinter=true;
//                if (LSI(left, lineseg(triangles[j][k], triangles[j][(k + 1) % 3])))leftinter=true;
//                if (LSI(right, lineseg(triangles[j][k], triangles[j][(k + 1) % 3])))rightinter=true;
//            }
//            if(topinter&&botinter&&leftinter&&rightinter)curgood=false;
//        }
//        good[i]=curgood;
//    }
    for(int i=0;i<n;i++){
        if(good[i])for(int j=i+1;j<n;j++){
                if(good[j]) {
                    lineseg cur(key[i], key[j]);
                    bool work = true;
                    for (int k = 0; k < t && work; k++) {
                        for (int po = 0; po < 3 && work; po++) {
                            if (LSI(cur, lineseg(triangles[k][po], triangles[k][(po + 1) % 3])))work = false;
                        }
                    }
                    if (work)cnt++;
                }
            }
    }
    printf("%d\n",cnt);
    return 0;
}