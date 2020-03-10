#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
int arr[503];
vector<vector<int>> st;
int deq[503];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    arr[0]=1001;
    arr[n+1]=1001;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    st.push_back({});
    int ans=0;
    for(int i=1;i<=n;i++){
        if(arr[i-1]<=arr[i]||arr[i+1]<=arr[i])st.back().push_back(arr[i]);
        else st.push_back({}),ans++;
    }
    for(auto x:st){
        int l=0,r=-1;
        set<int> nums;
        for(int y:x){
            nums.insert(y);
            deq[++r]=y;
        }
        while(r-l+1>1){
            int aml=0;
            while(l<=r&&deq[l]==*nums.begin()){
                aml++;
                l++;
            }
            int amr=0;
            while(l<=r&&deq[r]==*nums.begin()){
                amr++;
                r--;
            }
            if(aml%2)ans++;
            if(amr%2)ans++;
            for(int i=0;i<aml/2;i++)deq[--l]=*nums.begin()+1;
            for(int i=0;i<amr/2;i++)deq[++r]=*nums.begin()+1;
            nums.insert(*nums.begin()+1);
            nums.erase(nums.begin());
        }
        ans+=(r-l+1);
    }
    printf("%d\n",ans);
    return 0;
}