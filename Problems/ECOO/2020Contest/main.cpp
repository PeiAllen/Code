#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
string arr[500];
int ans[11];
vector<int> ret;
int h,w;
void disjoint(int col){
    char last='-';
    ret.clear();
    if(col<0)return;
    for(int i=0;i<h;i++){
        if(arr[i][col]=='*'&&last=='-')ret.push_back(i);
        last=arr[i][col];
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int cs=-1;
        while(n--){
            cs++;
            cin>>h>>w;
            vector<int> filled;
            for(int i=0;i<h;i++){
                cin>>arr[i];
            }
            bool done=false;
            for(int i=w-1;i>=0&&!done;i--){
                disjoint(i);
                if(sz(ret)){
                    if(sz(ret)==1){
                        int loc=ret[0];
                        disjoint(i-1);
                        if(loc<ret[1]){
                            ans[cs]=2;
                            done=true;
                        }
                        else{
                            for(int j=i-2;j>=0&&!done;j--){
                                disjoint(j);
                                if(sz(ret)==2){
                                    ans[cs]=6;
                                    done=true;
                                }
                            }
                            if(!done){
                                ans[cs]=5;
                                done=true;
                            }
                        }
                    }
                    else{
                        vector<int> te;
                        for(int x:ret)te.push_back(x);
                        disjoint(i-1);
                        if(sz(ret)==0){
                            ans[cs]=1;
                            done=true;
                        }
                        else if(sz(ret)==2){
                            ans[cs]=0;
                            done=true;
                        }
                        else if(sz(ret)==1){
                            if(ret[0]<te[0]){
                                ans[cs]=7;
                                done=true;
                            }
                            else{
                                ans[cs]=4;
                                done=true;
                            }
                        }
                        else{
                            for(int j=i-2;j>=0&&!done;j--){
                                disjoint(j);
                                if(sz(ret)==1){
                                    ans[cs]=9;
                                    done=true;
                                }
                                else if(sz(ret)==2){
                                    ans[cs]=8;
                                    done=true;
                                }
                            }
                            if(!done){
                                ans[cs]=3;
                                done=true;
                            }
                        }
                    }
                }
            }
        }
        for(int i=0;i<=cs;i++){
            printf("%d",ans[i]);
        }
        printf("\n");
    }
    return 0;
}