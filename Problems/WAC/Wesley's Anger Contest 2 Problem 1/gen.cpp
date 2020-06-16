#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
string day[7]={"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
int main(int argc, char* argv[]){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    srand(atoi(argv[1]));
    cout<<day[rand()%7]<<"\n";
    return 0;
}