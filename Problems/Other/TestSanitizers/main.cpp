#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
int arr[3];

int main()
{
    for (int i = 0; i <= 3; i++)
    {
        arr[i] = i;
        cout << arr[i] << " ";
    }
    cout << endl;
}