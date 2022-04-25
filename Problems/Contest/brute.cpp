#include<bits/stdc++.h>
using namespace std;
#define fp(i,l,r) for(register int (i)=(l);(i)<=(r);++(i))
#define fd(i,l,r) for(register int (i)=(l);(i)>=(r);--(i))
#define fe(i,u) for(register int (i)=front[(u)];(i);(i)=e[(i)].next)
#define mem(a) memset((a),0,sizeof (a))
#define O(x) cerr<<#x<<':'<<x<<endl
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
    while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
    return x*f;
}
void wr(int x){
    if(x<0)putchar('-'),x=-x;
    if(x>=10)wr(x/10);
    putchar(x%10+'0');
}
const int MAXN=5e5+10,MAXM=5e4+10,inf=2e8;
struct qry{
    int op,x,y,w;
}a[500];
int m,T,lim[MAXM],L[MAXM],R[MAXM],w[MAXN],c[MAXN],pp,bel[MAXN],buc[13],cnt,top;
bool vis[MAXN],used[MAXN];
struct solver{
    int a1[MAXN],a3[MAXN],b1[MAXN],b2[MAXN],la1,la3,lb1,lb2;
    inline void init(){la1=la3=lb1=lb2=0;}
    inline void ins(int w,int c){
        if(w==1)a1[++la1]=c;else if(w==2)b1[++lb1]=c;else a3[++la3]=c;
    }
    inline void work(){
        lb2=lb1;fp(i,1,lb2)b2[i]=b1[i];
        sort(a1+1,a1+1+la1);sort(a3+1,a3+1+la3);
        for(int i=1;i<la1;i+=2)b1[++lb1]=a1[i]+a1[i+1];sort(b1+1,b1+1+lb1);
        for(int i=2;i<la1;i+=2)b2[++lb2]=a1[i]+a1[i+1];sort(b2+1,b2+1+lb2);
        fp(i,1,lb1)b1[i]+=b1[i-1];
        b2[0]=la1?a1[1]:inf;fp(i,1,lb2)b2[i]+=b2[i-1];
    }
    inline int gb1(int x){return x>lb1?inf:b1[x];}
    inline int gb2(int x){return x>lb2?inf:b2[x];}
    inline int ask1(int x){
        if(x<=0)return 0;
        return (x&1)?min(gb2(x/2),gb1((x+1)/2)):gb1(x/2);
    }
    inline int ask(int x){
        if(x<=0)return 0;
        int t=0,res=ask1(x);
        fp(i,1,la3)t+=a3[i],x-=3,res=min(res,t+ask1(x));
        return res;
    }
}S;
int ans=inf,dp[300],g[20][300],tmp2[300],len[MAXM],b[20],tot,b1[20],tot1,id[MAXM],tmp[300],dp2[300];
inline void merge(int a[],int b[]){
    fp(i,0,T)tmp2[i]=inf;
    fp(i,0,T)fp(j,0,T-i)tmp2[i+j]=min(tmp2[i+j],a[i]+b[j]);
    fp(i,0,T)a[i]=tmp2[i];
}
inline void solve(){
    fp(i,1,pp)if(a[i].op==3){
            if(used[a[i].x]&&used[a[i].y])return;
        }
    fp(i,0,T)dp2[i]=dp[i];
    fp(i,1,tot1){
        int x=b1[i],s=0,s2=0;
        fp(j,1,cnt)if(bel[buc[j]]==x){
                s+=w[buc[j]];s2+=c[buc[j]];
            }
        fp(j,-s,T-s)tmp[j+s]=g[i][j+len[x]]+s2;
        merge(dp2,tmp);
    }
    int res=dp2[T];
    fp(i,1,pp){
        if(a[i].op==1){
            if(used[a[i].x]&&used[a[i].y])res-=a[i].w;
        }
        else if(a[i].op==2){
            if(used[a[i].x]&&used[a[i].y])res+=a[i].w;
        }
    }
    ans=min(ans,res);
}
void dfs(int d){
    if(d==tot+1){solve();return;}
    dfs(d+1);
    buc[++cnt]=b[d];used[b[d]]=1;dfs(d+1);
    used[b[d]]=0;--cnt;
}
main(){
    m=read();T=read();
    fp(i,1,m){
        int num=read();lim[i]=read();T-=lim[i];
        L[i]=R[i-1]+1;R[i]=L[i]+num-1;
        fp(j,L[i],R[i])w[j]=read(),c[j]=read(),bel[j]=i;
    }
    T=max(T,0);
    pp=read();
    fp(i,1,pp){
        a[i].op=read();
        int x1=read(),y1=read(),x2=read(),y2=read();
        a[i].x=L[x1]+y1-1,a[i].y=L[x2]+y2-1;
        if(!vis[a[i].x])b[++tot]=a[i].x;vis[a[i].x]=1;
        if(!vis[a[i].y])b[++tot]=a[i].y;vis[a[i].y]=1;
        if(a[i].op!=3)a[i].w=read();
    }
    fp(i,1,T)dp[i]=inf;
    fp(i,1,m){
        S.init();
        fp(j,L[i],R[i]){
            if(!vis[j])S.ins(w[j],c[j]);
            else len[i]+=w[j];
        }
        S.work();
        if(len[i])b1[++tot1]=i,id[i]=tot1;
        if(len[i]){
            fp(j,-len[i],T)g[tot1][j+len[i]]=S.ask(lim[i]+j);
        }
        else{
            fp(j,0,T)tmp[j]=S.ask(lim[i]+j);
            merge(dp,tmp);
        }
    }
    dfs(1);
    printf("%d\n",ans>=110000000?-1:ans);
    return 0;
}