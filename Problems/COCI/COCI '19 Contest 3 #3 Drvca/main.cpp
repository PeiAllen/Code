#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=1e5+1;
int h[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>h[i];
    }
    sort(h,h+n);
    if(n==2){
        printf("1\n%d\n1\n%d\n",h[0],h[1]);
        return 0;
    }
    for(int i=0;i<(1<<2);i++){
        vector<int> first,second;
        first.push_back(h[0]);
        for(int j=0;j<2;j++){
            if(i&(1<<j)){
                first.push_back(h[j+1]);
            }
            else second.push_back(h[j+1]);
        }
        multiset<int> nums;
        for(int j=3;j<n;j++)nums.insert(h[j]);
        if(sz(first)==1)swap(first,second);
        int diff=first[1]-first[0];
        while(nums.count(first.back()+diff)){
            first.push_back(first.back()+diff);
            nums.erase(nums.find(first.back()));
        }
        multiset<int> diffs;
        for(auto x:second)nums.insert(x);
        second.clear();
        if(sz(nums)==0){
            nums.insert(first.back());
            first.pop_back();
        }
        if(sz(nums)==1){
            printf("%d\n",sz(first));
            for(auto x:first)printf("%d ",x);
            printf("\n");
            printf("%d\n",sz(nums));
            for(auto x:nums)printf("%d ",x);
            printf("\n");
            return 0;
        }
        int last=0;
        for(auto x:nums){
            if(last!=0)diffs.insert(x-last);
            last=x;
        }
        while(*diffs.begin()!=*diffs.rbegin()&&sz(first)>2){
            int curadd=first.back();
            first.pop_back();
            nums.insert(curadd);
            auto it=nums.lower_bound(curadd);
            if(it!=prev(nums.end(),1)&&it!=nums.begin())diffs.erase(diffs.find(*next(it,1)-*prev(it,1)));
            if(it!=prev(nums.end(),1))diffs.insert(*next(it,1)-*it);
            if(it!=nums.begin())diffs.insert(*it-*prev(it,1));
        }
        if(*diffs.begin()!=*diffs.rbegin())continue;
        printf("%d\n",sz(first));
        for(auto x:first)printf("%d ",x);
        printf("\n");
        printf("%d\n",sz(nums));
        for(auto x:nums)printf("%d ",x);
        printf("\n");
        return 0;
    }
    printf("-1\n");
    return 0;
}