#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define A first
#define B second
template<typename T> int SZ(const T &a){return int(a.size());}
const int MN=501;
pii arr[MN];
int dist(pii a, pii b){
    return abs(a.A-b.A)+abs(a.B-b.B);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i].A>>arr[i].B;
    }
    int best=INT_MAX;
    for(int i=0;i<n;i++){
        vector<pii> bus(arr,arr+n);
        sort(bus.begin(),bus.end(),[&](const auto &lhs, const auto &rhs){
            return dist(arr[i],lhs)<dist(arr[i],rhs);
        });
        best=min(best,dist(arr[i],bus.back())+dist(arr[i],bus[SZ(bus)-2]));
        bus.erase(find(bus.begin(),bus.end(),arr[i]));
        for(int j=0;j<n;j++)if(j!=i){
                vector<pii> finbus(bus.begin(),bus.end());
                finbus.erase(find(finbus.begin(),finbus.end(),arr[j]));
                int am=0;
                pii worst=arr[j];
                pii worst2=arr[j];
                pii worst3=arr[j];
                pii bestrest={10000,10000};
                if(j>i) {
                    for (int k = SZ(bus); k >= 0; k--) {
                        int longest = (k == SZ(bus) - 1 ? (SZ(bus) == 1 ? 0 : dist(bus[SZ(bus) - 2], arr[i])) : dist(bus.back(), arr[i]));
                        int secondlongest = (SZ(bus) <= 2 ? 0 : dist(arr[i], (k >= SZ(bus) - 2 ? bus[SZ(bus) - 3] : bus[SZ(bus) - 2])));
                        best = min(best, max(longest + secondlongest, longest + dist(arr[i], arr[j]) + dist(arr[j], bus[k])));
                        if (am >= 3) {
                            best = min(best, max({dist(worst, arr[j]) + dist(arr[i], arr[j]) + dist(arr[i], bestrest), dist(arr[j], worst) + dist(arr[j], worst2), dist(arr[i], bestrest) + dist(arr[i], bus[k])}));
                            best = min(best, max({dist(worst, arr[j]) + dist(arr[i], arr[j]) + dist(arr[i], worst2), dist(arr[j], worst) + dist(arr[j], worst3), dist(arr[i], worst2) + dist(arr[i], bus[k])}));
                            best = min(best, max({dist(worst2, arr[j]) + dist(arr[i], arr[j]) + dist(arr[i], worst), dist(arr[j], worst3) + dist(arr[j], worst2), dist(arr[i], worst) + dist(arr[i], bus[k])}));
                        }
                        if (dist(bus[k], arr[j]) > dist(worst, arr[j])) {
                            worst3 = worst2;
                            if (worst2 != arr[j] && dist(arr[i], bestrest) > dist(arr[i], worst2))bestrest = worst2;
                            worst2 = worst;
                            worst = bus[k];
                        } else if (dist(bus[k], arr[j]) > dist(worst2, arr[j])) {
                            worst3 = worst2;
                            if (worst2 != arr[j] && dist(arr[i], bestrest) > dist(arr[i], worst2))bestrest = worst2;
                            worst2 = bus[k];
                        } else {
                            bestrest = bus[k];
                            if (dist(bus[k], arr[j]) > dist(worst3, arr[j]))worst3 = bus[k];
                        }
                        am++;
                    }
                }
                else{
                    for (int k = SZ(bus); k >= 0; k--) {
                        int longest = (k == SZ(bus) - 1 ? (SZ(bus) == 1 ? 0 : dist(bus[SZ(bus) - 2], arr[i])) : dist(bus.back(), arr[i]));
                        int secondlongest = (SZ(bus) <= 2 ? 0 : dist(arr[i], (k >= SZ(bus) - 2 ? bus[SZ(bus) - 3] : bus[SZ(bus) - 2])));
                        best = min(best, max(longest + secondlongest, longest + dist(arr[i], arr[j]) + dist(arr[j], bus[k])));
                    }
                }
            }
    }
    printf("%d\n",best);
    return 0;
}