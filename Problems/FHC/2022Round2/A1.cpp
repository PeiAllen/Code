#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e6+1;
int arr[MN];
int psum[26][MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    for(int cs=1;cs<=t;cs++){
        string s;
        cin>>s;
        int n=sz(s);
        for(int i=1;i<=n;i++){
            arr[i]=s[i-1]-'a';
        }
        for(int i=0;i<26;i++){
            for(int j=1;j<=n;j++){
                psum[i][j]=psum[i][j-1]+(arr[j]==i);
            }
        }
        int q;
        cin>>q;
        int l,r;
        int ans=0;
        while(q--){
            cin>>l>>r;
            if((r-l+1)%2==1){
                int mid=(r+l)/2;
                int off=0;
                for(int i=0;i<26;i++){
                    if(psum[i][mid]-psum[i][l-1]!=psum[i][r]-psum[i][mid]){
                        if(psum[i][mid]-psum[i][l-1]-1==psum[i][r]-psum[i][mid]){
                            off++;
                        }
                        else{
                            off+=2;
                        }
                    }
                }
                if(off==1){
                    ans++;
                }
                else{
                    off=0;
                    mid--;
                    for(int i=0;i<26;i++){
                        if(psum[i][mid]-psum[i][l-1]!=psum[i][r]-psum[i][mid]){
                            if(psum[i][mid]-psum[i][l-1]+1==psum[i][r]-psum[i][mid]){
                                off++;
                            }
                            else{
                                off+=2;
                            }
                        }
                    }
                    if(off==1){
                        ans++;
                    }
                }
            }
        }
        printf("Case #%d: %d\n",cs,ans);
    }
    return 0;
}


/*
so realy jsut check even.
determine if the set of characters in the start is the same as the set of characters in the end. 
    26*1e6??
    or 
odd case:
    if delete in front, or delete in back
        so either the middle is included in left or giht
            and then check if you can delete a character to make it match.
            solves 26*q

check if the count for two subarrays is the same??
oh give each number a hash lmfao im stupid and xor.
uhh to check which one to delete..
if xor result is a number.

mmo?
line sweep.
*/