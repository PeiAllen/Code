#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    mt19937_64 gen(stoi(argv[1]));
    int n=20;
    uniform_int_distribution<int> edges(n-1,10*n);
    int m=edges(gen);
    printf("5\n1\n%d %d\n",n,m);
    set<pair<int,int>> ree;
    for(int i=0;i<n-1;i++){
        uniform_int_distribution<int> te(1,i+1);
        int v=te(gen);
        ree.insert({v,i+2});
        printf("%d %d\n",i+2,v);
    }
    for(int i=n-1;i<m;i++){
        int u,v;
        while(1) {
            uniform_int_distribution<int> te(1, n - 1);
            u = te(gen);
            uniform_int_distribution<int> te2(u + 1, n);
            v=te2(gen);
            if(!ree.count({u,v})){
                ree.insert({u,v});
                break;
            }
        }
        printf("%d %d\n",u,v);
    }
    return 0;
}