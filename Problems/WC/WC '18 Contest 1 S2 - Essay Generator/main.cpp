#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
vector<string> words;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int w;
    cin>>w;
    for(int i=0;i<26;i++){
        words.push_back(string(1,(char)('a'+i)));
    }
    for(int i=0;i<26;i++){
        for(int j=0;j<26;j++){
            words.push_back(string(1,(char)('a'+i))+string(1,(char)('a'+j)));
        }
    }
    for(int i=0;i<26;i++){
        for(int j=0;j<26;j++){
            for(int k=0;k<26;k++){
                words.push_back(string(1,(char)('a'+i))+string(1,(char)('a'+j))+string(1,(char)('a'+k)));
            }
        }
    }
    for(int i=0;i<w;i++)cout<<words[i]<<" \n"[i==w-1];
    return 0;
}