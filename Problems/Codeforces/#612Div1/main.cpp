#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
void sc(){}
template<typename T,typename... Args>
void sc(T& a, Args&... args) {cin>>a,sc(args...);}
template<typename T>
void pr(T a){cout<<a;}
template<typename T,typename... Args>
void pr(T a, Args... args) {cout<<a<<" ",pr(args...);}
template<typename T>
void prl(T a){cout<<a<<"\n";}
template<typename T,typename... Args>
void prl(T a, Args... args) {cout<<a<<" ",prl(args...);}
template<typename T>
int sz(const T &a){return (int)a.size();}
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
vector<string> arr[101];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    sc(n);
    cout<<"? 1 "<<n<<endl;
    string a;
    for(int i=0;i<(n*(n+1)/2);i++){
        sc(a);
        if(a=="-"){
            exit(0);
            return 0;
        }
        arr[sz(a)].push_back(a);
    }
    if(n==1){
        cout<<"! "<<arr[1][0]<<endl;
        exit(0);
        return 0;
    }
    char st;
    cout<<"? 1 1"<<endl;
    sc(st);
    if(st=='-'){
        exit(0);
        return 0;
    }
    char en;
    cout<<"? "<<n<<" "<<n<<endl;
    sc(en);
    if(en=='-'){
        exit(0);
        return 0;
    }
    queue<>
    return 0;
}