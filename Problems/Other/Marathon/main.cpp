#include <bits/stdc++.h>
using namespace std;

string s;
int q, psa[26][1000005];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    getline (cin, s);

    psa[s[0]+'a'][1]=1;
    for (int i=1; i<s.length(); i++){
        psa[s[i]-'a'][i+1]++;
        for (int j=1; j<=26; j++){
            psa[j][i+1]+=psa[j][i];
        }
    }
    cin >> q;
    for (int i=1; i<=q; i++){
        int x, y;
        char c;
        cin >> x >> y >> c;
        cout << psa[c-'a'][y]-psa[c-'a'][x-1] << endl;
    }
    return 0;
}