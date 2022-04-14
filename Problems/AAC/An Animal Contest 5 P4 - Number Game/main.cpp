#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define A first
#define B second
template<typename T> int sz(const T &a){return int(a.size());}
int roundtoodd(int a){
    if(a%2==1)return a;
    return a+1;
}
void makemoves(int prefix, int starting, int n, int diff){
    ll sum=ll(prefix)*ll(prefix+1)/2;
    ll neededdiff=sum-diff;
    vector<int> negatives,positives;
    for(ll i=prefix;i>=1;i--){
        if(neededdiff>=2*i){
            neededdiff-=2*i;
            negatives.push_back(i);
        }
        else positives.push_back(i);
    }
    for(int i=0;i<prefix;i++){
        if(sz(negatives)&&starting-negatives.back()>=1){
            printf("%d\n",-negatives.back());
            starting-=negatives.back();
            negatives.pop_back();
        }
        else{
            printf("%d\n",positives.back());
            starting+=positives.back();
            positives.pop_back();
        }
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,x;
    cin>>n>>x;
    for(int i=1;i<=n;i++){
        int mostright=i;
        int mostleft=n-i+1;
        if(mostleft<=mostright){
            ll sum=ll(i)*ll(i-1)/2;
            if(sum%2==1){//odd
                if(x>=mostleft&&x<=mostright){
                    if(x+1>=mostleft&&x+1<=mostright){
                        printf("%d\n",i-1);
                        makemoves(i-1,x,n,1);
                        return 0;
                    }
                    if(x-1>=mostleft&&x-1<=mostright){
                        printf("%d\n",i-1);
                        makemoves(i-1,x,n,-1);
                        return 0;
                    }
                }
                else if(x<mostleft){
                    if(x+sum>=mostleft&&x+roundtoodd(mostleft-x)<=mostright){
                        printf("%d\n",i-1);
                        makemoves(i-1,x,n,roundtoodd(mostleft-x));
                        return 0;
                    }
                }
                else{
                    if(x-sum<=mostright&&x-roundtoodd(x-mostright)>=mostleft){
                        printf("%d\n",i-1);
                        makemoves(i-1,x,n,-roundtoodd(x-mostright));
                        return 0;
                    }
                }
            }
            else{//even
                if(x>=mostleft&&x<=mostright){
                    printf("%d\n",i-1);
                    makemoves(i-1,x,n,0);
                    return 0;
                }
                else if(x<mostleft){
                    if(x+sum>=mostleft&&x+(mostleft-x+1)/2*2<=mostright){
                        printf("%d\n",i-1);
                        makemoves(i-1,x,n,(mostleft-x+1)/2*2);
                        return 0;
                    }
                }
                else{
                    if(x-sum<=mostright&&x-(x-mostright+1)/2*2>=mostleft){
                        printf("%d\n",i-1);
                        makemoves(i-1,x,n,-(x-mostright+1)/2*2);
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}