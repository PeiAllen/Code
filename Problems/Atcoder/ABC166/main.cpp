#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
vector<char> ans;
string ins[(int)1e5+1];
vector<int> used[3];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    lli a,b,c;
    cin>>n>>a>>b>>c;
    string in;
    bool work=true;
    for(int i=0;i<n;i++) {
        cin >> ins[i];
        used[ins[i][0]-'A'].push_back(i);
        used[ins[i][1]-'A'].push_back(i);
    }
    used[0].push_back(n+1);
    used[1].push_back(n+1);
    used[2].push_back(n+1);
    for(int i=0;i<n;i++){
        in =ins[i];
        if(in=="AB"){
            if(b==a){
                if(used[0][lower_bound(used[0].begin(),used[0].end(),i+1)-used[0].begin()]<used[1][lower_bound(used[1].begin(),used[1].end(),i+1)-used[1].begin()]){
                    a+=1;
                    b-=1;
                    ans.push_back('A');
                }
                else{
                    b+=1;
                    a-=1;
                    ans.push_back('B');
                }
            }
            else if(b<a){
                b+=1;
                a-=1;
                ans.push_back('B');
            }
            else{
                a+=1;
                b-=1;
                ans.push_back('A');
            }
        }
        else if(in=="AC"){
            if(c==a){
                if(used[0][lower_bound(used[0].begin(),used[0].end(),i+1)-used[0].begin()]<used[2][lower_bound(used[2].begin(),used[2].end(),i+1)-used[2].begin()]){
                    a+=1;
                    c-=1;
                    ans.push_back('A');
                }
                else{
                    c+=1;
                    a-=1;
                    ans.push_back('C');
                }
            }
            else if(c<a){
                c+=1;
                a-=1;
                ans.push_back('C');
            }
            else{
                a+=1;
                c-=1;
                ans.push_back('A');
            }
        }
        else{
            if(b==c){
                if(used[2][lower_bound(used[2].begin(),used[2].end(),i+1)-used[2].begin()]<used[1][lower_bound(used[1].begin(),used[1].end(),i+1)-used[1].begin()]){
                    c+=1;
                    b-=1;
                    ans.push_back('C');
                }
                else{
                    b+=1;
                    c-=1;
                    ans.push_back('B');
                }
            }
            else if(b<c){
                b+=1;
                c-=1;
                ans.push_back('B');
            }
            else{
                c+=1;
                b-=1;
                ans.push_back('C');
            }
        }
        if(a<0||b<0||c<0){
            work=false;
        }
    }
    if(work){
        printf("Yes\n");
        for(char x:ans)printf("%c\n",x);
    }
    else printf("No\n");
    return 0;
}