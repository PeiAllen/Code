#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int r,c;
map<string,double> dp[2];
char player[2]={'J','D'};
int error[2];
double go(string board, int turn){
	if(dp[turn].count(board))return dp[turn][board];
	vector<double> moves;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(board[i*c+j]==player[turn]){
				if(i>0&&board[(i-1)*c+j]!='_'){
					string te=board;
					te[i*c+j]='_';
					te[(i-1)*c+j]=player[turn];
					moves.push_back(1-go(te,(turn+1)%2));
				}
				if(i<r-1&&board[(i+1)*c+j]!='_'){
					string te=board;
					te[i*c+j]='_';
					te[(i+1)*c+j]=player[turn];
					moves.push_back(1-go(te,(turn+1)%2));
				}
				if(j>0&&board[i*c+j-1]!='_'){
					string te=board;
					te[i*c+j]='_';
					te[i*c+j-1]=player[turn];
					moves.push_back(1-go(te,(turn+1)%2));
				}
				if(j<c-1&&board[i*c+j+1]!='_'){
					string te=board;
					te[i*c+j]='_';
					te[i*c+j+1]=player[turn];
					moves.push_back(1-go(te,(turn+1)%2));
				}
			}
		}
	}
	if(!moves.size())return dp[turn][board]=0;
	sort(moves.begin(),moves.end());
	double ans=0;
	for(int i=max(0,(int)moves.size()-error[turn]);i<moves.size();i++){
		ans+=moves[i];
	}
	ans/=(double)min(error[turn],(int)moves.size());
	return dp[turn][board]=ans;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>r>>c;
    string in="";
    string te;
    for(int i=0;i<r;i++){
		cin>>te;
		in+=te;
    }
    cin>>error[0]>>error[1];
    printf("%.3f\n",go(in,0));
    return 0;
}