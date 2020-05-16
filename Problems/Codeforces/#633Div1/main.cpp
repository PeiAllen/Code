#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}

int main(){
//    cin.tie(NULL);
//    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        lli n;
        cin>>n;
        set<lli> nums;
        for(int i=1;i<=1e6;i++)nums.insert(i);
        for(int i=1;i<=n;i++){
            //  printf("%d\n",*nums.begin());
            lli cur=*nums.begin();
            nums.erase(cur);
            auto te=nums.begin();
            while(!nums.count(*te^cur)){
                te++;
            }
            printf("%lli\n",(*te)^cur);
            cout<<bitset<8>(cur).to_string()<<"\n";
            // printf("%d\n",*te^cur);
            lli val=*te;
            nums.erase(val);
            nums.erase(val^cur);
        }
    }
    return 0;
}