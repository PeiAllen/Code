#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=51;
int arr[MAXN][MAXN];
vector<int> nums;
int low;
void solve(int offset, int stam, int enam){
    int sm=min(stam,enam);
    int mid=stam+enam-2*sm;
    if(mid>=sm) {
        int othst = sm+mid;
        for (int i = 0; i < sm; i++) {
            arr[i+offset][i+offset] = low;
            arr[i + othst+offset][i + othst+offset] = low + 1;
            arr[((i + 1) % sm)+offset][i+offset] = low + 1;
            arr[othst +offset+ ((i + 1) % sm)][othst +offset+ i] = low;
        }
        for (int i = 1; i < sm - 1; i++) {
            arr[0+offset][i+offset] = nums[i - 1];
            arr[0 +offset+ othst][i +offset+ othst] = nums[i - 1];
        }
        int am = sm - 2;
        if(am>0)for (int i = 1; i < sm; i++) {
            int cur = (1 - i + am) % am;
            for (int j = 0; j < sm; j++) {
                if (arr[i+offset][j+offset] == 0) {
                    arr[i+offset][j+offset] = nums[cur];
                    arr[i +offset+ othst][j +offset+ othst] = nums[cur];
                    cur = (cur + 1) % am;
                }
            }
        }
        int f = low, s = low + 1;
        if (stam == sm) {
            swap(f, s);
        }
        for (int i = 0; i < mid; i++) {
            arr[i + offset + sm][i + offset + sm] = f;
            arr[((i + 1) % mid) + sm + offset][i + sm + offset] = low + 1;
        }
        for (int i = 1; i < mid - 1; i++) {
            arr[0 + sm + offset][i + sm + offset] = nums[i - 1];
        }
        am = mid - 2;
        if(am>0)for (int i = 1; i < mid; i++) {
            int cur = (1 - i + am) % am;
            for (int j = 0; j < mid; j++) {
                if (arr[i + sm + offset][j + sm + offset] == 0) {
                    arr[i + sm + offset][j + sm + offset] = nums[cur];
                    cur = (cur + 1) % am;
                }
            }
        }
        int teof=am;
        am=stam+enam-(am+2);
        for(int i=0;i<mid;i++){
            int cur=(-i+am)%am;
            for(int j=0;j<sm;j++){
                arr[i + sm + offset][j+offset]=nums[cur+teof];
                cur = (cur + 1) % am;
            }
            for(int j=0;j<sm;j++){
                arr[i + sm + offset][j+offset+sm+mid]=nums[cur+teof];
                cur = (cur + 1) % am;
            }
        }
        for(int i=0;i<mid;i++){
            int cur=(-i+am)%am;
            for(int j=sm-1;j>=0;j--){
                arr[j+offset+sm+mid][i + sm + offset]=nums[cur+teof];
                cur = (cur + 1) % am;
            }
            for(int j=sm-1;j>=0;j--){
                arr[j+offset][i + sm + offset]=nums[cur+teof];
                cur = (cur + 1) % am;
            }

        }
    }
    else{
        solve(offset+mid,stam-mid,enam-mid);
        sm=mid;

    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    int cs=1;
    while(t--){
        int n,k;
        cin>>n>>k;
        if((k%n==1&&k/n==1)||(k%n==n-1&&k/n+1==n)){
            printf("Case #%d: IMPOSSIBLE\n",cs);
        }
        else{
            for(int i=0;i<n;i++)for(int j=0;j<n;j++)arr[i][j]=0;
            nums.clear();
            low=k/n;
            for(int i=1;i<=n;i++)if(i!=low&&i!=low+1)nums.push_back(i);
            solve(0,n-(k%n),k%n);
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    printf("%d ",arr[i][j]);
                }
                printf("\n");
            }
        }
        cs++;
    }
    return 0;
}