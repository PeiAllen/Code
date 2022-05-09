#include <bits/stdc++.h>

using namespace std;

int n;
int arr [10001];
vector<int> out;
vector<int> newout;
vector<int> zero;
vector<int> one;
vector<int> two;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1; i <= n; i++) {
        if (arr[i]%3 == 0) zero.push_back(arr[i]);
        else if (arr[i]%3 == 1) one.push_back(arr[i]);
        else if (arr[i]%3 == 2) two.push_back(arr[i]);
    }
    if ((one.size()>0 && two.size()>0 && zero.size() == 0) || (zero.size() > one.size()+two.size()+1)) cout << "impossible\n";
    else {
        for (int i: one) {
            out.push_back(i);
            if (zero.size() > 0) {
                out.push_back(zero.back());
                zero.pop_back();
            }
        }
        for (int i: two) out.push_back(i);
        if (zero.size() > 0) {
            out.insert(out.begin(), zero.back());
            zero.pop_back();
        }
        if (zero.size() > 0) {
            out.push_back(zero.back());
            zero.pop_back();
        }
        while (out.size() > 0) {
            newout.push_back(out.back());
            out.pop_back();
            if (out.size() > 0 && zero.size() > 0 && out.back()%3 == newout.back()%3) {
                newout.push_back(zero.back());
                zero.pop_back();
            }
        }
        for (int i = 0; i < n; i++) cout << newout[i] << " \n"[i==n-1];
    }
    return 0;
}