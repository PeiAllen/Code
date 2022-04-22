#include <bits/stdc++.h>

using namespace std;

string s;
string t;
int freqs [18];
int freqt [18];
bool works [18][18];
int q;
string output;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> s;
    cin >> t;
    for (char i: s) {
        freqs[i-'a'] ++;
    }
    for (char i: t) {
        freqt[i-'a'] ++;
    }
    for (char i = 'a'; i <= 'r'; i++) {
        for (char j = 'a'; j <= 'r'; j++) {
            string tempa;
            string tempb;
            for (char k: s) {
                if (k == i || k == j) {
                    tempa += k;
                }
            }
            for (char k: s) {
                if (k == i || k == j) {
                    tempb += k;
                }
            }
            if (tempa == tempb) {
                works[i-'a'][j-'a'] = true;
            }
            else {
                works[i-'a'][j-'a'] = false;
            }
        }
    }
    cin >> q;
    for (int i = 1; i <= q; i++) {
        bool subset = true;;
        string temp;
        cin >> temp;
        int sums;
        int sumt;
        for (char j: temp) {
            sums += freqs[j-'a'];
            sumt += freqt[j-'a'];
        }
        if (sums == sumt) {
            for (int j = 0; j < temp.size(); j++) {
                for (int k = j+1; k < temp.size(); k++) {
                    if (!works[temp[j]-'a'][temp[k]-'a']) {
                        subset = false;
                    }
                }
            }
        }
        else {
            subset = false;
        }
        if (subset) output += 'Y';
        else output += 'N';
    }
    cout << output << "\n";
    return 0;
}
