#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=1e5+1;
lli arr[MAXN];
struct seg{
    struct node {
        lli data, sum[10];
        pair<vector<int>, int> inu[10];
        node() {
            data = 0;
            for (int i = 0; i < 10; i++)sum[i] = 0, inu[i] = {{}, -1};
        }
    }t[2*MAXN];
    void pushup(int ind, int le, int ri){
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        t[ind].data=t[left].data+t[right].data;
        for(int i=0;i<10;i++)t[ind].sum[i]=t[left].sum[i]+t[right].sum[i];
    }
    void mt(int ind, int le, int ri){
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        if(le!=ri){
            mt(left,le,mid),mt(right,mid+1,ri);
            pushup(ind,le,ri);
        }
        else{
            t[ind].data=arr[le];
            lli cur=1;
            while(t[ind].data){
                t[ind].sum[t[ind].data%10]+=cur;
                cur*=10;
                t[ind].data/=10;
            }
            t[ind].data=arr[le];
        }
    }
    void merge(int ind, const vector<int>& a, int b, int & cnt){
        if(t[ind].inu[b].second!=-1){
            if(t[ind].inu[b].second!=b){
                int oldb=b;
                b=t[ind].inu[b].second;
                t[ind].inu[oldb]={{},-1};
            }
        }
        for(int x:a) {
            cnt++;
            if(t[ind].inu[x].second!=-1){
                if(t[ind].inu[x].second==x){
                    for(int y:t[ind].inu[x].first){
                        t[ind].inu[y]={{},b};
                        t[ind].inu[b].second=b;
                        t[ind].inu[b].first.push_back(y);
                        cnt++;
                    }
                    t[ind].inu[x]={{},-1};
                    continue;
                }
                else{
                    continue;
                }
            }
            t[ind].inu[b].second=b;
            t[ind].inu[b].first.push_back(x);
            t[ind].inu[x]={{},b};
        }
    }
    void rl(int ind, int le, int ri){
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        int cnt=0;
        for(int i=0;i<10;i++){
            if(t[ind].inu[i].second==i) {
                for(lli x:t[ind].inu[i].first) {
                    cnt++;
                    t[ind].data += (t[ind].inu[i].second-x) * t[ind].sum[x];
                    t[ind].sum[t[ind].inu[i].second] += t[ind].sum[x];
                    t[ind].sum[x]=0;
                }
            }
        }
        if(le!=ri){
            for(int i=0;i<10;i++){
                if(t[ind].inu[i].second==i){
                    merge(left,t[ind].inu[i].first,t[ind].inu[i].second,cnt);
                    merge(right,t[ind].inu[i].first,t[ind].inu[i].second,cnt);
                }
            }
        }
        assert(cnt<=40);
        for(int i=0;i<10;i++)t[ind].inu[i]={{},-1};
    }
    void update(int ind, int le, int ri, int l, int r, int a, int b){
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        rl(ind,le,ri);
        if(r<le||l>ri)return;
        if(le>=l&&ri<=r){
            t[ind].inu[a]={{},b},t[ind].inu[b]={{a},b};
            rl(ind,le,ri);
            return;
        }
        update(left,le,mid,l,r,a,b),update(right,mid+1,ri,l,r,a,b);
        pushup(ind,le,ri);
    }
    lli query(int ind, int le, int ri, int l, int r){
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        rl(ind,le,ri);
        if(r<le||l>ri)return 0;
        if(le>=l&&ri<=r){
            return t[ind].data;
        }
        return query(left,le,mid,l,r)+query(right,mid+1,ri,l,r);
    }
}tree;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    tree.mt(1,1,n);
    int a,b,c,d,e;
    while(q--){
        cin>>a>>b>>c;
        if(a==1){
            cin>>d>>e;
            if(d==e)continue;
            tree.update(1,1,n,b,c,d,e);
        }
        else printf("%lli\n",tree.query(1,1,n,b,c));
    }
    return 0;
}