#include "bits/stdc++.h"
#include "testlib.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1001;
int startsquare[MN][MN];
int givensquare[MN][MN];
int n;
bool used[MN];
void readAns(InStream& stream){
    for(int i=1;i<=n;i++) {
        for (int j = 1; j <= n; j++) {
            givensquare[i][j] = stream.readInt(1, n);
            if (givensquare[i][j] != startsquare[i][j] && startsquare[i][j] != 0) {//checks that all values are identical except when input is 0
                stream.quitf(_wa, "latin square does not match input latin square");
            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)used[j]=false;
        for(int j=1;j<=n;j++){
            if(used[givensquare[i][j]]){// checks that given row is a valid permutation
                stream.quitf(_wa,"output is not a valid latin square");
            }
            used[givensquare[i][j]]=true;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)used[j]=false;
        for(int j=1;j<=n;j++){
            if(used[givensquare[j][i]]){// checks that given column is a valid permutation
                stream.quitf(_wa,"output is not a valid latin square");
            }
            used[givensquare[j][i]]=true;
        }
    }
}
int main(int argc, char *argv[]) {
    setName("checker for problem d");
    registerTestlibCmd(argc, argv);

    n=inf.readInt();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            startsquare[i][j]=inf.readInt(0,n);
        }
    }

    readAns(ans);
    readAns(ouf);
    quit(_ok, "participant's solution is correct");

    return 0;
}

