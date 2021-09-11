#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1001;
int arr[MN][MN];
int leftmost[MN],rightmost[MN],topmost[MN],bottommost[MN];
bool off[MN];
vector<int> turnoff[MN];
vector<pair<int,pii>> toinsert[MN];
vector<int> ls[MN],rs[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int h,w,s;
    cin>>h>>w>>s;
    for(int i=1;i<=256;i++)leftmost[i]=INT_MAX,topmost[i]=INT_MAX;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>arr[i][j];
            leftmost[arr[i][j]]=min(leftmost[arr[i][j]],j);
            rightmost[arr[i][j]]=max(rightmost[arr[i][j]],j);
            topmost[arr[i][j]]=min(topmost[arr[i][j]],i);
            bottommost[arr[i][j]]=max(bottommost[arr[i][j]],i);
        }
    }
    int colcnt=0;
    vector<int> xs,ys;
    for(int i=1;i<=256;i++){
        if(leftmost[i]<=rightmost[i]){
            colcnt++;
            xs.push_back(topmost[i]);
            xs.push_back(bottommost[i]);
            ys.push_back(leftmost[i]);
            ys.push_back(rightmost[i]);
        }
    }
    sort(xs.begin(),xs.end()),xs.erase(unique(xs.begin(),xs.end()),xs.end());
    sort(ys.begin(),ys.end()),ys.erase(unique(ys.begin(),ys.end()),ys.end());
    for(int i=1;i<=256;i++){
        if(leftmost[i]<=rightmost[i]){
            turnoff[lower_bound(xs.begin(),xs.end(),topmost[i])-xs.begin()+1].push_back(i);
            toinsert[lower_bound(xs.begin(),xs.end(),bottommost[i])-xs.begin()].push_back({i,{lower_bound(ys.begin(),ys.end(),leftmost[i])-ys.begin(),lower_bound(ys.begin(),ys.end(),rightmost[i])-ys.begin()}});
        }
    }
    int best=0;
    for(int i=0;i<sz(xs);i++){
        for(auto x:turnoff[i])off[x]=true;
        for(int j=0;j<sz(ys);j++)ls[j]=vector<int>(),rs[j]=vector<int>();
        for(int j=i;j<sz(xs);j++){
            for(auto x:toinsert[j]){
                if(!off[x.first]){
                    ls[x.second.second].push_back(x.second.first);
                    rs[x.second.first].push_back(x.second.second);
                }
            }
            int height=xs[j]-xs[i]+1;
            int maxwidth=s/height;
            if(maxwidth) {
                int othptr = -1;
                int cnt=0;
                for (int k = 0; k < sz(ys); k++) {
                    while (othptr + 1 < sz(ys) && ys[othptr + 1] <=ys[k]+maxwidth-1){
                        othptr++;
                        for(auto x:ls[othptr]){
                            if(x>=k)cnt++;
                        }
                    }
                    best=max(best,cnt);
                    for(auto x:rs[k]){
                        if(x<=othptr)cnt--;
                    }
                }
            }
        }
    }
    printf("%d\n",colcnt-best);
    return 0;
}