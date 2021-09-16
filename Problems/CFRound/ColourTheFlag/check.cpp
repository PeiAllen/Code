#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

std::string upper(std::string sa){
    for (size_t i = 0; i < sa.length(); i++)
        if ('a' <= sa[i] && sa[i] <= 'z')
            sa[i] = sa[i] - 'a' + 'A';
    return sa;
}

int main(int argc, char *argv[]){

    int t;
    cin>>t;
    for(int tc = 1; tc <= T; tc++){

        int n = inf.readInt();
        int m = inf.readInt();
        vector<string> in(n), s(n), t(n);
        for(int i = 0; i < n; i++)
            in[i] = inf.readWord();

        string ca = upper(ans.readWord());
        string cb = upper(ouf.readWord());

        if(ca == "NO" and cb == "YES"){
            quitf(_wa, "case %d: no valid grids exist, but contestant said YES", tc);
        }
        if(ca == "YES" and cb == "NO"){
            quitf(_wa, "case %d: valid grid exists, but contestant said NO", tc);
        }
        if(ca == "NO" and cb == "NO"){
            continue;
        }
        if(cb != "YES"){
            quitf(_wa, "case %d: contestant said neither YES nor NO", tc);
        }


        for(int i = 0; i < n; i++){
            s[i] = ans.readWord();
            t[i] = ouf.readWord();

            if (size(t[i]) != m) quitf(_wa, "case %d: contestant's grid dimensions are incorrect", tc);

            for(int j = 0; j < m; j++){
                if(t[i][j] != 'R' and t[i][j] != 'W')
                    quitf(_wa, "case %d: contestant's grid has an invalid character", tc);
                if(in[i][j] != '.' and t[i][j] != in[i][j])
                    quitf(_wa, "case %d: contestant's grid does not match input grid", tc);

                if(i and t[i][j] == t[i-1][j])
                    quitf(_wa, "case %d: contestant's grid does not satisfy property", tc);
                if(j and t[i][j] == t[i][j-1])
                    quitf(_wa, "case %d: contestant's grid does not satisfy property", tc);
            }
        }
    }

    quit(_ok, "contestant's solution is correct");
}
