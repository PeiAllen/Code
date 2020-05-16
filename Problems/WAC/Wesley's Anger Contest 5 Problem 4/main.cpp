#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=10001;
const int MAXH=1;
lli mod=998244353;
lli fix(lli a,lli tmod){
    while(a<0)a+=tmod;
    return a%tmod;
}
lli fastpow(lli a,lli b,lli tmod){
    lli ans=1;
    for(lli i=1;i<=b;i<<=(lli)1){
        if(b&i)ans=ans*a%tmod;
        a=a*a%tmod;
    }
    return ans;
}
vector<int> same,plu;
int loc,pre;
string old="";
string s;
lli inv[MAXN][MAXH],pp[MAXN][MAXH];
lli base[MAXH]={31};
lli hmod[MAXN]={(lli)1e9+9};
int consecnine[MAXN];
struct HSH{
    lli data[MAXH];
    HSH(lli val=0,int po=0){
        for(int i=0;i<MAXH;i++)data[i]=val*pp[po][i]%hmod[i];
    }
    bool operator==(const HSH &rhs){
        for(int i=0;i<MAXH;i++)if(data[i]!=rhs.data[i])return 0;
        return 1;
    }
    HSH operator+(const HSH &rhs){
        HSH te;
        for(int i=0;i<MAXH;i++)te.data[i]=fix(data[i]+rhs.data[i],hmod[i]);
        return te;
    }
    HSH operator-(const HSH &rhs){
        HSH te;
        for(int i=0;i<MAXH;i++)te.data[i]=fix(data[i]-rhs.data[i],hmod[i]);
        return te;
    }
    HSH divide(int am){
        HSH te;
        for(int i=0;i<MAXH;i++)te.data[i]=data[i]*inv[am][i]%hmod[i];
        return te;
    }
    HSH mutiply(int am){
        HSH te;
        for(int i=0;i<MAXH;i++)te.data[i]=data[i]*pp[am][i]%hmod[i];
        return te;
    }
};
HSH hashes[MAXN],precalc[MAXN];
void calchash(){
    for(int i=0;i<MAXH;i++)pp[0][i]=1,inv[0][i]=1;
    for(int i=1;i<=sz(s);i++){
        for(int j=0;j<MAXH;j++){
            pp[i][j]=pp[i-1][j]*base[j]%hmod[j];
            inv[i][j]=fastpow(pp[i][j],hmod[j]-2,hmod[j]);
            hashes[i].data[j]=(hashes[i-1].data[j]+((s[i-1]-'0'+1)*pp[i-1][j]%hmod[j]))%hmod[j];
            precalc[i].data[j]=((precalc[i-1].data[j]+pp[i-1][j])%hmod[j])%hmod[j];
        }
    }
}
HSH gethash(int l, int r){
    l+=1,r+=1;
    if(l>r)return HSH(1);
    return (hashes[r]-hashes[l-1]).divide(l-1);
}
HSH gethshplus(int l, int r){
    l+=1,r+=1;
    if(l>r)return HSH();
    return (gethash(l-1,r-consecnine[r]-1)+HSH(1,max(0,r-consecnine[r]-1-(l-1))))+(precalc[consecnine[r]].mutiply(max(1,r-consecnine[r]-1-(l-1)+1)));
}
void inc(string& a){
    int carry=1;
    for(int i=sz(a)-1;i>=0;i--){
        if(a[i]=='9')a[i]='0';
        else{
            a[i]=a[i]+1;
            return;
        }
    }
    if(carry)a="1"+a;
}
lli getval(const string &a){
    lli val=1;
    lli ans=0;
    for(int i=sz(a)-1;i>=0;i--){
        ans=(ans+(val*(a[i]-'0')%mod))%mod;
        val=val*10%mod;
    }
    return ans;
}
lli find(string &a){
    lli ans=0;
    lli cur=10;
    lli last=1;
    for(lli i=1;i<sz(a);i++){
        ans=(ans+(i*fix(cur-last,mod)%mod))%mod;
        last=cur;
        cur=cur*10%mod;
    }
    a[0]-=1;
    return (ans+(getval(a)*sz(a)%mod))%mod;
}
string specsubstr(int l, int r){
    if(r<sz(s))return s.substr(l,r-l+1);
    int rlen=r-sz(s)+1;
    string te=s.substr(l-rlen,rlen);
    inc(te);
    if(sz(te)>rlen)te=te.substr(1);
    return s.substr(l)+te;
}
void better(int a, int b){
    if(specsubstr(pre+1,pre+1)=="0"){
        pre=a,loc=b,old="";
        return;
    }
    if(b-a>loc-pre)return;
    if(b-a<loc-pre)pre=a,loc=b,old="";
    else{
        if(old=="")old=specsubstr(pre+1,loc);
        string ne=specsubstr(a+1,b);
        if(ne<old||old[0]=='0')old=ne,pre=a,loc=b;
        else if(ne==old&&a>pre){
            pre=a,loc=b;
        }
    }
}

bool check(int a, int b){
    if(s[a+1]=='0')return false;
    HSH te=gethshplus(a+1,b);
    int loc=b;
    int len=b-a;
    if(consecnine[loc+1]>=len)len++;
    while(loc+1<sz(s)){
        if(loc+len>=sz(s)){
            HSH end=gethash(loc+1,sz(s)-1);
            te=te-(loc+len-(sz(s)-1)<=consecnine[loc+1]?precalc[loc+len-(sz(s)-1)].mutiply(sz(s)-1-(loc+1)+1):gethshplus(loc-(loc+len-(sz(s)-1))+1,loc).mutiply(sz(s)-1-(loc+1)+1));
            if(!(end==te))return 0;
            break;
        }
        else {
            if (!(gethash(loc + 1, loc + len) == te))return 0;
            te = gethshplus(loc + 1, loc + len);
            loc += len;
            if (consecnine[loc + 1] >= len)len++;
        }
    }
    better(a,b);
    return 1;
}
bool checkall(int a, bool type){
    int curpos=sz(s);
    bool sofarallnine=true;
    bool done=false;
    while(a<sz(s)){
        if(s[a]!='9')sofarallnine=false;
        if(!(curpos>=(a+1)*2))break;
        if(type==1&&!(s[a]=='9'))break;
        if((a+1==sz(s)||s[a+1]!='0')&&!(sofarallnine&&!type)){
            better(a,curpos);
            done=true;
        }
        curpos++;
        a++;
    }
    return done;
}
bool able[MAXN][2];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>s;
    for(int i=1;i<=sz(s);i++){
        if(s[i-1]=='9')consecnine[i]=consecnine[i-1]+1;
        else consecnine[i]=0;
    }
    calchash();
    bool bad=true;
    for(char x:s)if(x!='0')bad=false;
    if(bad){
        s="1"+s;
        printf("%lli\n",find(s)+2);
        return 0;
    }
    loc=sz(s)-1,pre=-1;
    old=s;
    for(int i=0;i<sz(s)-1;i++)same.push_back(i),plu.push_back(i);
    for(int i=0;i<sz(s);i++){
        if(check(-1,i)){
            while(plu.back()>i)plu.pop_back();
            while(same.back()>i)same.pop_back();
            break;
        }
    }
    for(int i=0;i<sz(s);i++){
        vector<int> tesame;
        for(int x:same){
            if(x+1<sz(s)&&s[x+1]==s[i]&&x+1>=(i+1)*2)tesame.push_back(x+1);
        }
        vector<int> teplu;
        if(s[i]=='9'){
            for (int x:plu) {
                if (x + 1 < sz(s) && s[x + 1] == '0' && x + 1 >= (i + 1) * 2)teplu.push_back(x + 1);
            }
        }
        else{
            for(int x:same){
                if(x+1<sz(s)&&s[x+1]==s[i]+1&&x+1>=(i+1)*2)teplu.push_back(x+1);
            }
        }
        plu.clear(),same.clear();
        for(int x:teplu)plu.push_back(x);
        for(int x:tesame)same.push_back(x);
        for(int x:plu){
            if(check(i,x)){
                while(plu.back()>x)plu.pop_back();
                while(same.back()>x)same.pop_back();
            }
        }
        if(sz(plu)&&plu.back()==sz(s)-1)able[i][1]=true;
        if(sz(same)&&same.back()==sz(s)-1)able[i][0]=true;
    }
    for(int i=sz(s)-1;i>=0;i--){
        bool finished=false;
        if(sz(s)-(i+1)>loc-pre)break;
        if(able[i][0])finished|=checkall(i+1,0);
        if(able[i][1])finished|=checkall(i+1,1);
        if(finished)break;
    }
    if(old=="")old=specsubstr(pre+1,loc);
    bool allnine=true;
    for(int i=0;i<sz(s)-1;i++){
        if(s[i]!='9')allnine=false;
        if(s[i+1]!='0') {
            if (allnine) {
                if (s.back() != '0') {
                    string ne;
                    ne.resize(sz(s), '0');
                    for (int j = i + 1; j < sz(s) - 1; j++) {
                        ne[j - (i + 1)] = s[j];
                    }
                    ne[(sz(s) - 1) - (i + 1)] = s.back();
                    int tepre = i;
                    if(sz(ne)<sz(old)||old[0]=='0')old = ne, pre = tepre;
                    else if(sz(ne)==sz(old)) {
                        if (ne < old)old = ne, pre = tepre;
                        else if (ne == old && tepre > pre)pre = tepre;
                    }
                }
            } else {
                string ne = s.substr(i + 1) + s.substr(0, i + 1);
                inc(ne);
                int tepre = i;
                if(sz(ne)<sz(old)||old[0]=='0')old = ne, pre = tepre;
                else if(sz(ne)==sz(old)) {
                    if (ne < old)old = ne, pre = tepre;
                    else if (ne == old && tepre > pre)pre = tepre;
                }
            }
        }
    }
    printf("%lli\n",fix(find(old)-(pre),mod));
    return 0;
}