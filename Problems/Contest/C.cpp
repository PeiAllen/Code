#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define A first
#define B second
template<typename T> int SZ(const T &a){return int(a.size());}
const int MN=1001;
pair<pll,ll> arr[MN];
ll lcm(ll a, ll b){
    ll gc=__gcd(a,b);
    return (a/gc)*b;
}
// Extended Euclidean Algorithm to compute x and y, where ax + by = gcd(a, b)
// Template Arguments:
//   T: the type of a and b
// Function Arguments:
//   a: the first value
//   b: the second value
//   x: a reference to a variable to store x
//   y: a reference to a variable to store y
// Return Value: the greatest common divisor of a and b
// In practice, has a small constant
// Time Complexity: O(log(min(a, b)))
// Memory Complexity: O(1)
// Tested:
//   https://dmoj.ca/problem/modinv
//   https://www.spoj.com/problems/CEQU/
//   https://codeforces.com/problemsets/acmsguru/problem/99999/106
template <class T> T EEA(T a, T b, T &x, T &y) {
    T xx = y = 0, yy = x = 1; while (b != 0) {
        T q = a / b; a %= b; swap(a, b);
        x -= q * xx; swap(x, xx); y -= q * yy; swap(y, yy);
    }
    if (a < 0) { a = -a; x = -x; y = -y; }
    return a;
}
// Solves the Linear Diophantine Equation ax + by = c
// All pairs of integers (s, t) where s = x.first + k * x.second
//   and t = y.first + k * y.second for all integers k are solutions
// Edge cases:
//   1. a == 0 && b == 0 is satisfied by all integer pairs (s, t) if c == 0,
//     no solutions otherwise
//   2. a == 0 is satisfied by all integer pairs (s, t) with t = c / b if c is
//     divisible by b, no solutions otherwise
//   3. b == 0 is satisfied by all integer pairs (s, t) with s = c / a if c is
//     divisible by a, no solutions otherwise
// Template Arguments:
//   T: the type of a, b, c
// Function Arguments:
//   a: the first value
//   b: the second value
//   c: the value of ax + by
//   x: a reference to a pair storing x and its mod (equal to b / gcd(a, b))
//   y: a reference to a pair storing y and its mod (equal to -a / gcd(a, b))
// Return Value: true if there is a solution, false otherwise
// In practice, has a small constant
// Time Complexity: O(log(min(a, b)))
// Memory Complexity: O(1)
// Tested:
//   https://www.spoj.com/problems/CEQU/
//   https://codeforces.com/problemsets/acmsguru/problem/99999/106
template <class T> bool LDE(T a, T b, T c, pair<T, T> &x, pair<T, T> &y) {
    assert(a != 0 && b != 0); T xg, yg, g = EEA(a, b, xg, yg);
    if (c % g != 0) return false;
    x = make_pair(xg * (c / g), b / g); y = make_pair(yg * (c / g), -a / g);
    return true;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i].A.A>>arr[i].A.B>>arr[i].B;
    }
    ll start=0,interval=1;
    for(int i=n;i>=1;i--){
        start-=arr[i].B;
        ll te=(abs(start)+interval-1)/interval;
        start+=interval*te;
        ll c=start-arr[i].A.A;
        ll a=-interval,b=arr[i].A.B;
        if(c%__gcd(a,b)==0){
            pll x,y;
            LDE(a,b,c,x,y);
            while(x.first<0){
                x.first+=x.second;
                y.first+=y.second;
            }
            while(y.first<0){
                x.first+=x.second;
                y.first+=y.second;
            }
            start=a*x.first+start;
        }
        else{
            printf("-1\n");
            return 0;
        }
        interval=lcm(interval,arr[i].A.B);
    }
    printf("%lli\n",start);
    return 0;
}