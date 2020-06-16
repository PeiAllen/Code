#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXV=1e6+1;
multiset<int> lefts[MAXV],rights[MAXV];
multiset<int> leftpoints,rightpoints;
struct seg{
    struct node{
        int maxleft,minright,ans;
        node(){
            maxleft=-1e7;//maxleft of all rights in the range
            minright=1e7;//minright of all lefts in the range.
            ans=1e7;//ans is calculed for every pair on the union of the right left and left right
        }
    }t[2*MAXV];
    void update(int ind, int le, int ri, int loc){
        if(le>loc||ri<loc)return;
        if(le==ri){
            t[ind].maxleft=(sz(lefts[loc])?*lefts[loc].rbegin():-1e7);
            t[ind].minright=(sz(rights[loc])?*rights[loc].begin():1e7);
            t[ind].ans=min((int)1e7,t[ind].minright-t[ind].maxleft);
            return;
        }
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        update(left,le,mid,loc),update(right,mid+1,ri,loc);
        t[ind].ans=min({t[left].ans,t[right].ans,t[right].minright-t[left].maxleft});
        t[ind].maxleft=max(t[left].maxleft,t[right].maxleft),t[ind].minright=min(t[left].minright,t[right].minright);
    }
}tree;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int q;
    cin>>q;
    char a;
    int l,r;
    while(q--){
        cin>>a>>l>>r;
        if(a=='A'){
            leftpoints.insert(l),rightpoints.insert(r);
            lefts[r].insert(l);
            rights[l].insert(r);
        }
        else{
            leftpoints.erase(leftpoints.find(l)),rightpoints.erase(rightpoints.find(r));
            lefts[r].erase(lefts[r].find(l));
            rights[l].erase(rights[l].find(r));
        }
        tree.update(0,1,1e6,l);
        tree.update(0,1,1e6,r);
        if(*rightpoints.begin()<=*leftpoints.rbegin())printf("%d\n",tree.t[0].ans);
        else printf("%d\n",*rights[*leftpoints.rbegin()].begin()-*lefts[*rightpoints.begin()].rbegin());
    }
    return 0;
}