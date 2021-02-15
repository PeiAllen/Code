#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
int offset[7];
int preval[7];
int mem[10240+1];
void bit_set(int loc){
    mem[loc]++;
}
int bit_get(int loc){
    return mem[loc];
}
void remember(int value){
    int prev=1;
    int val=0;
    for(int i=1;i<12;i+=2){
        offset[(i+1)/2]=prev;
        for(int j=i-2+1;j<=i;j++){
            if(value&(1<<(12-j-1)))val+=(1<<j);
        }
        bit_set(prev+val);
        prev=prev*4+1;
    }
}
int compare(int value){
    int l=0,r=6;
    int val=0;
    preval[0]=0;
    for(int i=1;i<12;i+=2) {
        for (int j = i - 2 + 1; j <= i; j++) {
            if (value & (1 << (12 - j - 1)))val += (1 << j);
        }
        preval[(i+1)/2]=val;
    }
    while(l!=r){
        int mid=(l+r+1)/2;
        if(bit_get(offset[mid]+preval[mid]))l=mid;
        else r=mid-1;
    }
    if(l==6)return 0;
    if((!!(value&(1<<(11-(2*l)))))+2*(!!(value&(1<<(11-(2*l+1)))))==0)return -1;
    if((!!(value&(1<<(11-(2*l)))))+2*(!!(value&(1<<(11-(2*l+1)))))==2){
        if(bit_get(offset[l+1]+preval[l]+0*(1<<(2*l))))return 1;
        return -1;
    }
    if((!!(value&(1<<(11-(2*l)))))+2*(!!(value&(1<<(11-(2*l+1)))))==1){
        if(bit_get(offset[l+1]+preval[l]+3*(1<<(2*l))))return -1;
        return 1;
    }
    return 1;
}
int getans(int a, int b){
    if(b<a)return -1;
    if(b==a)return 0;
    return 1;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    for(int i=0;i<=4095;i++){
        memset(mem,0,sizeof(mem));
        remember(i);
        for(int j=0;j<=4095;j++){
            if(compare(j)!=getans(i,j)){
                printf("i:%d j:%d igive:%d correct:%d\n",i,j,compare(j),getans(i,j));
                return 0;
            }
        }
    }
    return 0;
}