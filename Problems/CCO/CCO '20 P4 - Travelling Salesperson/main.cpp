#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=2e3+1;
bool matrix[MAXN][MAXN];
int arr[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    char a;
    arr[1]=n;
    for(int i=2;i<=n;i++){
        arr[i]=n-i+1;
        for(int j=1;j<i;j++){
            cin>>a;
            matrix[i][j]=a=='B';
            matrix[j][i]=a=='B';
        }
    }
    deque<int> deq;
    for(int i=1;i<=n;i++){
        deq.push_back(arr[1]);
        deq.push_back(arr[2]);
        for(int j=3;j<=n;j++){
            if(matrix[deq.front()][arr[j]]){
                deq.push_front(arr[j]);
            }
            else if(!matrix[deq.back()][arr[j]]){
                deq.push_back(arr[j]);
            }
            else if(matrix[deq.back()][deq.front()]){
                deq.push_front(deq.back());
                deq.push_front(arr[j]);
                deq.pop_back();
            }
            else{
                deq.push_back(deq.front());
                deq.push_back(arr[j]);
                deq.pop_front();
            }
        }
        if(deq.back()==i)reverse(deq.begin(),deq.end());
        printf("%d\n",n);
        for(int j=0;j<sz(deq);j++)printf("%d ",deq[j]);
        printf("\n");
        deq.clear();
        rotate(arr+1,arr+n,arr+1+n);
    }
    return 0;
}