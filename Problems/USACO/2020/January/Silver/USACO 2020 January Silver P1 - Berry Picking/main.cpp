#include <bits/stdc++.h>

using namespace std;
const int MAXN=1e3+1;
template<typename T>
int sz(T &a){return (int)a.size();}
int arr[MAXN];
int n,k;
priority_queue<int> stuff;
priority_queue<int> othstuff;
int check(int a){
    while(sz(stuff))stuff.pop();
    while(sz(othstuff))othstuff.pop();
    for(int i=n-1;i>=0;i--){
        if(arr[i]>=a)stuff.push(arr[i]);
        else othstuff.push(arr[i]);
    }
    if(sz(stuff)==0)return -1;
    while(sz(stuff)<k/2){
        int cur=stuff.top();
        stuff.pop();
        if(cur-a<a)return -1;
        stuff.push(cur-a);
        stuff.push(a);
    }
    int cnt=0;
    while(sz(stuff)){
        int cur=stuff.top();
        stuff.pop();
        if(cnt<k/2) {
            cur -= a;
            cnt++;
        }
        while(cur>a){
            othstuff.push(a);
            cur-=a;
        }
        othstuff.push(cur);
    }
    int ans=0;
    for(int i=0;i<k/2;i++)ans+=othstuff.top(),othstuff.pop();
    return ans;
}
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int ma=0;
    for(int i=1;i<=1000;i++){
        ma=max(ma,check(i));
    }
    printf("%d\n",ma);
    return 0;
}