#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int SZ(const T &a){return int(a.size());}
const ll mod=998244353;
const int BS=400;
//#define getchar() (*_pbuf ? *_pbuf++ : (_buf[fread_unlocked(_pbuf = _buf, 1, 1048576, stdin)] = 0, *_pbuf++))
//char _buf[1048577], *_pbuf = _buf;
//
//inline int readint() {
//    int c, o = 0;
//    while ((c = getchar()) < '0');
//    do {o = (o<<3)+(o<<1) + (c - '0');} while ((c = getchar()) >= '0');
//    return o;
//}
inline int readint(){
    int a;
    cin>>a;
    return a;
}
using matrix=vector<vector<ll>>;
matrix operator*(const matrix &a,const matrix &b) {
    matrix ans(SZ(a),vector<ll>(SZ(b[0])));
    for(int i=0;i<SZ(a);i++){
        for(int j=0;j<min(SZ(a[0]),SZ(b));j++){
            for(int k=0;k<SZ(b[0]);k++){
                ans[i][k]+=a[i][j]*b[j][k]%mod;
            }
        }
    }
    for(int i=0;i<SZ(ans);i++)for(int j=0;j<SZ(ans[0]);j++)ans[i][j]%=mod;
    return ans;
}
int n,m;
void solvebrute(){
    string arr;
    cin>>arr;
    string type;
    int a,b;
    auto solve=[&](){
        vector<ll> vals;
        vals.push_back(0);
        vals.push_back(1);
        for(auto x:arr){
            if(x=='W'){
                vals.back()++;
            }
            else{
                if(vals.back()==1)vals[SZ(vals)-2]++;
                else vals.back()--,vals.push_back(1),vals.push_back(1);
            }
        }
        matrix prefix(2,vector<ll>(2,0));
        prefix[0][0]=prefix[1][1]=1;
        ll last=vals.back();
        vals.pop_back();
        for(auto x:vals){
            matrix te(2,vector<ll>(2,0));
            te[0][0]=x,te[0][1]=te[1][0]=1;
            prefix=prefix*te;
        }
        matrix te(2,vector<ll>(1,0));
        te[0][0]=last,te[1][0]=1;
        prefix=prefix*te;
        printf("%lli %lli\n",prefix[0][0],prefix[1][0]);
    };
    solve();
    while(m--){
        cin>>type;
        if(type=="APPEND"){
            cin>>type;
            arr.push_back(type[0]);
        }
        else if(type=="FLIP"){
            cin>>a>>b,a-=1,b-=1;
            for(int i=a;i<=b;i++)arr[i]=(arr[i]=='E'?'W':'E');
        }
        else{
            cin>>a>>b,a-=1,b-=1;
            reverse(arr.begin()+a,arr.begin()+b+1);
        }
        solve();
    }
}
struct sqrt{
    struct block{
        bool start,reversed;//start as actual front(eg if reversed flag is true, its the back value).
        matrix poss[2][2];//from first 'E' after a 'W' to before last 'E' after a 'W'
        vector<int> values;
        int sum,psa;
        block(bool t){
            sum=0;
            start=t,reversed=0;
            values={0};
            psa=0;
        }
        void calc(){//assumes reversed is false
            for(int i=0;i<2;i++){
                for(int j=0;j<2;j++){
                    matrix prefix(2,vector<ll>(2,0));
                    prefix[0][0]=prefix[1][1]=1;
                    matrix te(2,vector<ll>(2,0));
                    te[0][1]=te[1][0]=1;
                    for(int a=j+1;a+2<SZ(values);a+=2){
                        te[0][0]=values[a];
                        prefix=prefix*te;
                        te[0][0]=values[a+1];
                        prefix=prefix*te;
                    }
                    poss[i][j]=prefix;
                }
                reverse(values.begin(),values.end());
            }
        }
        void resolve(){
            if(!reversed)return;
            reversed=false;
            reverse(values.begin(),values.end());
        }
        vector<bool> decompose(){
            resolve();
            vector<bool> full(sum);
            int ptr=0;
            bool cur=start;
            for(auto x:values){
                for(int i=0;i<x;i++)full[ptr++]=cur;
                cur^=1;
            }
            return full;
        }
        void makenode(const vector<bool> &v){
            values=vector<int>();
            values.push_back(1);
            reversed=false;
            sum=SZ(v);
            start=v[0];
            for(int i=1;i<SZ(v);i++){
                if(v[i]==v[i-1])values.back()++;
                else values.push_back(1);
            }
            calc();
        }
        void swapwith(block &a){
            swap(start,a.start);
            swap(reversed,a.reversed);
            swap(poss,a.poss);
            values.swap(a.values);
            swap(sum,a.sum);
        }

    };
    vector<block> t;
    void makepsa(int loc=1){
        for(int i=max(loc,1);i<SZ(t);i++)t[i].psa=t[i-1].psa+t[i-1].sum;
    }
    void make(const string &a){
        for(int i=0;i<SZ(a);i++){
            bool v=(a[i]=='E');
            if(i%BS==0)t.push_back(block(v));
            if((t.back().start^((SZ(t.back().values)-1)%2))==v)t.back().values.back()++;
            else t.back().values.push_back(1);
            t.back().sum++;
        }
        for(auto &x:t)x.calc();
        makepsa();
    }
    void split(int ind){
        t[ind].resolve();
        vector<bool> act=t[ind].decompose();
        t.insert(t.begin()+ind,block(0));
        vector<bool> te(act.begin()+SZ(act)/2,act.end());
        act.resize(SZ(act)/2);
        t[ind].makenode(act);
        t[ind+1].makenode(te);
        makepsa(ind);
    }
    void push_back(bool v){
        t.back().resolve();
        if((t.back().start^((SZ(t.back().values)-1)%2))==v)t.back().values.back()++;
        else t.back().values.push_back(1);
        t.back().sum++;
        if(t.back().sum>=2*BS)split(SZ(t)-1);
        else t.back().calc();
    }
    auto update(int ind, int l, int r, bool type){
        vector<bool> full=t[ind].decompose();
        if(type==0)for(int i=l;i<=r;i++)full[i]=!full[i];
        else reverse(full.begin()+l,full.begin()+r+1);
        t[ind].makenode(full);
    }
    void flip(int l, int r){
        int leftblock=upper_bound(t.begin(),t.end(),l,[&](const int &val, const block &it){
            return val<it.psa;
        })-t.begin()-1;
        int rightblock=upper_bound(t.begin(),t.end(),r,[&](const int &val, const block &it){
            return val<it.psa;
        })-t.begin()-1;
        for(int i=leftblock+1;i<rightblock;i++)t[i].start^=1;
        if(leftblock==rightblock)update(leftblock,l-t[leftblock].psa,r-t[leftblock].psa,0);
        else{
            update(leftblock,l-t[leftblock].psa,t[leftblock].sum-1,0);
            update(rightblock,0,r-t[rightblock].psa,0);
        }
    }
    void revarray(int l, int r){
        while(l<r){
            t[l].swapwith(t[r]);
            l++,r--;
        }
    }
    void rev(int l, int r){
        int leftblock=upper_bound(t.begin(),t.end(),l,[&](const int &val, const block &it){
            return val<it.psa;
        })-t.begin()-1;
        int rightblock=upper_bound(t.begin(),t.end(),r,[&](const int &val, const block &it){
            return val<it.psa;
        })-t.begin()-1;
        for(int i=leftblock+1;i<rightblock;i++)t[i].reversed^=1,t[i].start^=(SZ(t[i].values)-1)%2;
        revarray(leftblock+1,rightblock-1);
        if(leftblock==rightblock)update(leftblock,l-t[leftblock].psa,r-t[leftblock].psa,1);
        else{
            l-=t[leftblock].psa;
            r-=t[rightblock].psa;
            vector<bool> left=t[leftblock].decompose();
            vector<bool> right=t[rightblock].decompose();
            vector<bool> te(0);
            te.insert(te.end(),left.begin()+l,left.end());
            left.resize(l);
            reverse(right.begin(),right.begin()+r+1);
            left.insert(left.end(),right.begin(),right.begin()+r+1);
            right.erase(right.begin(),right.begin()+r+1);
            reverse(te.begin(),te.end());
            right.insert(right.begin(),te.begin(),te.end());
            if(SZ(right)>=2*BS){
                t.insert(t.begin()+rightblock,block(0));
                te=vector<bool>();
                te.insert(te.end(),right.begin()+SZ(right)/2,right.end());
                right.resize(SZ(right)/2);
                t[rightblock].makenode(right);
                t[rightblock+1].makenode(te);
            }
            else t[rightblock].makenode(right);
            if(SZ(left)>=2*BS){
                t.insert(t.begin()+leftblock,block(0));
                te=vector<bool>();
                te.insert(te.end(),left.begin()+SZ(left)/2,left.end());
                left.resize(SZ(left)/2);
                t[leftblock].makenode(left);
                t[leftblock+1].makenode(te);
            }
            else t[leftblock].makenode(left);
            makepsa(leftblock);
        }
    }
    pii getvalue(){
        pii prev={0,1};
        matrix prefix(2,vector<ll>(2,0));
        prefix[0][0]=prefix[1][1]=1;
        matrix te(2,vector<ll>(2,0));
        te[0][1]=te[1][0]=1;
        auto tomatrix=[&](pii v){
            te[0][0]=v.first;
            matrix toret=te;
            te[0][0]=v.second;
            return toret*te;
        };
        auto process=[&](pii cur){
            if(cur.first){
                if(prev.second==1)prev.first+=cur.second;
                else{
                    prev.second--;
                    prefix=prefix*tomatrix(prev);
                    prev={cur.second,1};
                }
            }
            else prev.second+=cur.second;
        };
        for(int i=0;i<SZ(t);i++){
            if(i==SZ(t)-1){
                vector<int> vals;
                vals.push_back(prev.first),vals.push_back(prev.second);
                bool type=t[i].start;
                if(t[i].reversed)reverse(t[i].values.begin(),t[i].values.end());
                for(auto x:t[i].values){
                    if(type){
                        if(vals.back()==1)vals[SZ(vals)-2]+=x;
                        else{
                            vals.back()-=1;
                            vals.push_back(x);
                            vals.push_back(1);
                        }
                    }
                    else vals.back()+=x;
                    type=!type;
                }
                if(t[i].reversed)reverse(t[i].values.begin(),t[i].values.end());
                matrix last(2,vector<ll>(1,0));
                last[0][0]=vals.back(),last[1][0]=1;
                vals.pop_back();
                for(auto x:vals){
                    te[0][0]=x;
                    prefix=prefix*te;
                }
                prefix=prefix*last;
            }
            else{
                if(SZ(t[i].values)<=2){
                    bool type=t[i].start;
                    if(t[i].reversed)for(auto x=t[i].values.rbegin();x!=t[i].values.rend();x++)process({type,*x}),type=!type;
                    else for(auto x:t[i].values)process({type,x}),type=!type;
                }
                else{
                    if(t[i].reversed){
                        process({t[i].start,t[i].values.back()});
                        if(t[i].start)process({0,t[i].values[SZ(t[i].values)-2]});
                        int pos=((t[i].start^((SZ(t[i].values)-1)%2))?0:1);
                        process({1,t[i].values[pos]});
                        prefix=prefix*t[i].poss[t[i].reversed][t[i].start];
                        if(pos==1)process({0,t[i].values[0]});
                    }
                    else{
                        process({t[i].start,t[i].values[0]});
                        if(t[i].start)process({0,t[i].values[1]});
                        int pos=((t[i].start^((SZ(t[i].values)-1)%2))?SZ(t[i].values)-1:SZ(t[i].values)-2);
                        process({1,t[i].values[pos]});
                        prefix=prefix*t[i].poss[t[i].reversed][t[i].start];
                        if(pos+1<SZ(t[i].values))process({0,t[i].values.back()});
                    }
                }
            }
        }
        return {prefix[0][0],prefix[1][0]};
    }
}solver;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("code4.in","r",stdin);
    freopen("out.txt","w",stdout);
    cin>>n>>m;
    string a;
    cin>>a;
    solver.make(a);
    auto te=solver.getvalue();
    printf("%d %d\n",te.first,te.second);
    int l,r;
    for(int i=0;i<m;i++){
        cin>>a;
        if(a=="APPEND"){
            cin>>a;
            solver.push_back(a[0]=='E');
        }
        else if(a=="FLIP"){
            cin>>l>>r,l-=1,r-=1;
            solver.flip(l,r);
        }
        else{
            cin>>l>>r,l-=1,r-=1;
            solver.rev(l,r);
        }
        te=solver.getvalue();
        printf("%d %d\n",te.first,te.second);
    }
    return 0;
}