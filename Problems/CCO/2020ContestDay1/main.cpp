#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=2e5+1;
int arr[MAXN];
int arr2[MAXN];
ll bit[MAXN];
int n;
int BS;
void update(int loc){
    for(;loc<=n;loc+=loc&-loc)bit[loc]++;
}
ll query(int loc){
    ll sum=0;
    for(;loc>0;loc-=loc&-loc)sum+=bit[loc];
    return sum;
}
struct node{
    int ma;
    vector<int> arr;
    node(){
        ma=0;
        arr={};
    }
    void recalc(){
        ma=0;
        for(int x:arr){
            ma=max(ma,x);
        }
    }
};
vector<node> block;
void gotry(int loc){
    int ind=0;
    int tominus=0;
    while(loc>=sz(block[ind].arr)){
        loc-=sz(block[ind].arr),tominus-=sz(block[ind].arr),ind++;
    }
    int r=arr[block[ind].arr[loc]]-1;
    r+=tominus;
    int val=block[ind].arr[loc];
    block[ind].arr.erase(block[ind].arr.begin()+loc);
    for(int i=loc;i<sz(block[ind].arr);i++){
        if(i==r||block[ind].arr[i]>=val){
            block[ind].arr.insert(block[ind].arr.begin()+i,val);
            return;
        }
        assert(i<r);
    }
    if(sz(block[ind].arr)==0){
        block.erase(block.begin()+ind);
        if(ind==sz(block)){
            block.push_back(node());
            block[ind].arr.push_back(val);
            block[ind].ma=val;
            block[ind].recalc();
            return;
        }
    }
    else{
        if(ind==sz(block)-1){
            block[ind].arr.push_back(val);
            block[ind].recalc();
            return;
        }
        block[ind].recalc();
        r-=sz(block[ind].arr);
        ind++;
    }
   // r--;
    while(ind<sz(block)-1&&block[ind].ma<val&&r>=sz(block[ind].arr)){
        r-=sz(block[ind].arr);
        ind++;
    }
    bool done=false;
    for(int i=0;i<sz(block[ind].arr);i++){
        if(i==r||block[ind].arr[i]>=val){
            block[ind].arr.insert(block[ind].arr.begin()+i,val);
            done=true;
            break;
        }
        assert(i<r);
    }
    if(!done)block[ind].arr.push_back(val);
    if(sz(block[ind].arr)>=2*BS){
        block.insert(block.begin() + ind + 1, node());
        block[ind+1].arr.insert(block[ind+1].arr.begin(),block[ind].arr.begin()+BS,block[ind].arr.end());
        block[ind].arr.resize(BS);block[ind + 1].recalc();
        block[ind+1].recalc();
        block[ind].recalc();
    }
    block[ind].recalc();
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n;
    priority_queue<pii> nums;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        nums.push({arr[i],i});
    }
    ll ans=0;
    for(int i=n;i>=1;i--){
        if(sz(nums)&&nums.top().first>=i){
            arr2[i]=nums.top().second;
            nums.pop();
        }
    }
    if(sz(nums)){
        printf("-\n");
        return 0;
    }
    BS=sqrt(n);
    for(int i=1;i<=n;i++){
        if(sz(block)==0||sz(block.back().arr)==BS)block.push_back(node());
        block.back().arr.push_back(arr2[i]);
    }
    for(int i=0;i<sz(block);i++)block[i].recalc();
//    for(int test=n-1;test>=1;test--) {
//        int r=arr[arr2[test]];
//        for (int i = test; i <r; i++) {
//            if (arr2[i + 1] < arr2[i]) {
//                swap(arr2[i], arr2[i + 1]);
//            }
//            else break;
//        }
//    }
    for(int test=n-1;test>=1;test--){
        gotry(test-1);
    }
    int reee=1;
    for(int i=0;i<sz(block);i++){
        for(int j:block[i].arr){
            arr2[reee]=j;
            reee++;
        }
    }
    for(int i=1;i<=n;i++){
        ans+=query(n)-query(arr2[i]);
        update(arr2[i]);
    }
    printf("%lli\n",ans);
    return 0;
}
/*
5
1 4 2 3 4
6
1 6 5 2 3 4
 */