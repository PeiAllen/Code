#include <bits/stdc++.h>
using namespace std;
typedef __int128 lli;
const int MAXN=1000001;
const int kek=15;
lli base=47;
lli mod=1e9+7;
lli base2=31;
lli mod2=1e9+21;
lli base3=37;
lli mod3=1e9+9;
lli base4=53;
lli mod4=2e9+11;
lli base5=89;
lli mod5=2e9+27;
lli base6=67;
lli mod6=2e9+27;
lli bases[kek]={73,79,101,103,107,937,937,997,997,1013,1013,937,937,937,73};
lli mods[kek]={(lli)1e9-11,(lli)1e9+9,(lli)2e9+11,(lli)984979187,(lli)984979187,984979187,(lli)(1e9)+7,(lli)2e9+27,(lli)1e9+9,(lli)1e9+9,984979187,(lli)1e9+9,(984979187),(lli)1e9-11,(lli)(1e9)+7};
lli fix(lli a,lli modt){
    if(a<0)a+=modt;
    return a%modt;
}
lli fastpow(lli a,lli b,lli tmod){
    lli ans=1;
    for(lli i=1;i<=b;i<<=1){
        if(b&i)ans=(ans*a)%tmod;
        a=(a*a)%tmod;
    }
    return ans;
}
set<lli> done;
set<lli> done2;
set<lli> done3;
set<lli> done4;
set<lli> done5;
set<lli> done6;
set<lli> dones[kek];
set<string> hm;
int toget[27];
int cur[MAXN+10][27];
lli hsh[MAXN+10];
lli inv[MAXN+10];
lli hsh2[MAXN+10];
lli inv2[MAXN+10];
lli hsh3[MAXN+10];
lli inv3[MAXN+10];
lli hsh4[MAXN+10];
lli inv4[MAXN+10];
lli hsh5[MAXN+10];
lli inv5[MAXN+10];
lli hsh6[MAXN+10];
lli inv6[MAXN+10];
lli hshs[kek][MAXN+10];
lli invs[kek][MAXN+10];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string n,h;
    cin>>n>>h;
    lli ns=(int)n.size();
    lli hs=(int)h.size();
    assert(ns<=MAXN&&hs<=MAXN);
    if(ns>hs){
        printf("0\n");
        return 0;
    }
    for(lli i=0;i<ns;i++){
        toget[n[i]-'a']++;
    }
    lli mut=1;
    inv[0]=1;
    lli mut2=1;
    inv2[0]=1;
    lli mut3=1;
    inv3[0]=1;
    lli mut4=1;
    inv4[0]=1;
    lli mut5=1;
    inv5[0]=1;
    lli mut6=1;
    inv6[0]=1;
    lli muts[kek];
    for(int i=0;i<kek;i++){
        muts[i]=1;
        invs[i][0]=1;
    }
    for(lli i=1;i<=hs+5;i++){
        inv[i]=fastpow(mut,mod-2,mod);
        mut=(mut*base)%mod;
        inv2[i]=fastpow(mut2,mod2-2,mod2);
        mut2=(mut2*base2)%mod2;
        inv3[i]=fastpow(mut3,mod3-2,mod3);
        mut3=(mut3*base3)%mod3;
        inv4[i]=fastpow(mut4,mod4-2,mod4);
        mut4=(mut4*base4)%mod4;
        inv5[i]=fastpow(mut5,mod5-2,mod5);
        mut5=(mut5*base5)%mod5;
        inv6[i]=fastpow(mut6,mod6-2,mod6);
        mut6=(mut6*base6)%mod6;
        for(int j=0;j<kek;j++){
            invs[j][i]=fastpow(muts[j],mods[j]-2,mods[j]);
            muts[j]=(muts[j]*bases[j])%mods[j];
        }
    }
    mut=1;
    mut2=1;
    mut3=1;
    mut4=1;
    mut5=1;
    mut6=1;
    for(int i=0;i<kek;i++)muts[i]=1;
    int am=0;
    for(lli i=0;i<hs;i++){
        hsh[i+1]=fix(hsh[i]+((mut*(lli)(h[i]-'a'+2))%mod),mod);
        hsh2[i+1]=fix(hsh2[i]+((mut2*(lli)(h[i]-'a'+2))%mod2),mod2);
        hsh3[i+1]=fix(hsh3[i]+((mut3*(lli)(h[i]-'a'+1))%mod3),mod3);
        hsh4[i+1]=fix(hsh4[i]+((mut4*(lli)(h[i]-'a'+4))%mod4),mod4);
        hsh5[i+1]=fix(hsh5[i]+((mut5*(lli)(h[i]-'a'+3))%mod5),mod5);
        hsh6[i+1]=fix(hsh6[i]+((mut6*(lli)(h[i]-'a'+1))%mod6),mod6);
        for(int j=0;j<kek;j++){
            hshs[j][i+1]=fix(hshs[j][i]+((muts[j]*(lli)(h[i]-'a'+1))%mods[j]),mods[j]);
        }
        if(i)for(int j=0;j<27;j++)cur[i][j]=cur[i-1][j];
        cur[i][h[i]-'a']++;
        bool work=true;
        if(work&&i+1-ns>=0){
            for(lli j=0;j<27;j++){
                if(cur[i][j]-cur[i-ns][j]!=toget[j])work=false;
            }
            if(work){
            assert(i+2-ns>=1&&i+2-ns<=hs+5);
            lli te=(fix(hsh[i+1]-hsh[i+1-ns],mod)*inv[i+2-ns])%mod;
            lli te2=(fix(hsh2[i+1]-hsh2[i+1-ns],mod2)*inv2[i+2-ns])%mod2;
            lli te3=(fix(hsh3[i+1]-hsh3[i+1-ns],mod3)*inv3[i+2-ns])%mod3;
            lli te4=(fix(hsh4[i+1]-hsh4[i+1-ns],mod4)*inv4[i+2-ns])%mod4;
            lli te5=(fix(hsh5[i+1]-hsh5[i+1-ns],mod5)*inv5[i+2-ns])%mod5;
            lli te6=(fix(hsh6[i+1]-hsh6[i+1-ns],mod6)*inv6[i+2-ns])%mod6;
            lli tes[kek];
            for(int j=0;j<kek;j++){
                tes[j]=(fix(hshs[j][i+1]-hshs[j][i+1-ns],mods[j])*invs[j][i+2-ns])%mods[j];
            }
            if(!done.count(te)&&!done2.count(te2)&&!done3.count(te3)&&!done4.count(te4)&&!done5.count(te5)&&!done6.count(te6)) {

                for (int j = 0; j < kek; j++) {
                    if (dones[j].count(tes[j]))work = false;
                }
                if (work) {
                 //   if(!hm.count(h.substr(i-ns+1,ns))){
                    done.insert(te);
                    done2.insert(te2);
                    done3.insert(te3);
                    done4.insert(te4);
                    done5.insert(te5);
                    done6.insert(te6);
                    for (int j = 0; j < kek; j++) {
                        dones[j].insert(tes[j]);
                    }
                    assert(i - ns + 1 + ns <= hs);
                    //  hm.insert(h.substr(i-ns+1,ns));
                    am++;
                }
            }
             //     }
            }
        }
        mut=(mut*base)%mod;
        mut2=(mut2*base2)%mod2;
        mut3=(mut3*base3)%mod3;
        mut4=(mut4*base4)%mod4;
        mut5=(mut5*base5)%mod5;
        mut6=(mut6*base6)%mod6;
        for(int j=0;j<kek;j++){
            muts[j]=(muts[j]*bases[j])%mods[j];
        }
    }
    printf("%d\n",am);
    return 0;
}