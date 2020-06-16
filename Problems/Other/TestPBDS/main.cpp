#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}

int arr[3];

void baf(){
    for (int i = 0; i <= 3; i++)
    {
        arr[i] = i;
        cout << arr[i] << " ";
    }
}
int main()
{
    baf();
    for (int i = 0; i <= 3; i++)
    {
        arr[i] = i;
        cout << arr[i] << " ";
    }
    cout << endl;
}
