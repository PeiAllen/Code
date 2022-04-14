#include <bits/stdc++.h>

using namespace std;

string n;
int a;
string out;

string one() {
    string temp=string(n.size(),n[0]);
    if(temp>=n)return temp;
    return string(n.size(),n[0]+1);
}

string two() {
    out = "";
    if (n.size() == 1) return n;
    if (n[0] != n[1]) {
        string tempa = "";
        tempa += n[0];
        tempa += n[1];
        string tempb = "";
        tempb += n[0];
        tempb += n[1];
        for (int i = 2; i < n.size(); i++) {
            tempa += n[0];
            tempb += n[1];
        }
        long long tempc = stoll(tempa)-stoll(n);
        long long tempd = stoll(tempb)-stoll(n);
        if (tempc >= 0 && (tempc < tempd||tempd<0)) return tempa;
        else if (tempd >= 0) return tempb;
        tempa[1] ++;
        if (tempa[1] == tempa[0]) {
            tempa[2] = '0';
        }
        return tempa;
    }
    else {
        for (int i = 0; i < n.size(); i++) {
            if (n[i] == n[0]) out += n[0];
            else if (n[i] < n[0]) {
                out += n[i];
                for (int j = i+1; j < n.size(); j++) {
                    out += n[0];
                }
                if (stoll(out)-stoll(n) >= 0) return out;
                else {
                    out[i] ++;
                    if (out[i] == out[0]) out[i+1] = '0';
                }
                return out;
            }
            else if (n[i] > n[0]) {
                out += n[i];
                for (int j = i+1; j < n.size(); j++) {
                    out += out[0];
                }
                if (stoll(out)-stoll(n) >= 0) return out;
                if (n[i] == '9') {
                    out[i-1] ++;
                    out[i] = out[0];
                    return out;
                }
                else {
                    out[i]++;
                }
                return out;
            }
        }
    }
    return out;
}

int main()
{
    cin.tie(NULL);
    int r = 3434343;
    ios_base::sync_with_stdio(false);
    cin >> n;
    cin >> a;
    if (a == 0) cout << one();
    else {
        cout << two();
    }
    return 0;
}
