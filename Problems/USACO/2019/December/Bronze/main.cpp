#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
string arr[8]={"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("lineup.in","r",stdin);
    freopen("lineup.out","w",stdout);
    int n;
    cin>>n;
    sort(arr,arr+8);
    pair<string,string> rules[n];
    string gt;
    for(int i=0;i<n;i++){
        cin>>rules[i].first>>gt>>gt>>gt>>gt>>rules[i].second;
    }
    do {
        bool work=true;
        for(int i=0;i<n;i++){
            for(int j=0;j<8;j++){
                if(arr[j]==rules[i].first){
                    if(j==0||arr[j-1]!=rules[i].second){
                        if(j==7||arr[j+1]!=rules[i].second){
                            work=false;
                        }
                    }
                }
            }
        }
        if(work){
            for(int i=0;i<8;i++){
                cout<<arr[i]<<"\n";
            }
            return 0;
        }
    } while ( next_permutation(arr,arr+8) );
}