#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
typedef pair <lli, lli> pll;
int N, K;
long long arr[20005];
bool dp[1<<11][20005];
long long val[12];
int ptr[12];
int main(int argc, char* argv[]) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	registerGen(argc, argv, 1);
	rnd.setSeed(time(0));
	for(int cases=0;cases<20;cases++) {//adjust number of cases here and caseid
		memset(arr,0,sizeof(arr));
		memset(dp,0,sizeof(dp));
		memset(val,0,sizeof(val));
		memset(ptr,0,sizeof(ptr));
		ofstream o("subtask1case" + to_string(cases) + ".in");//adjust name of file here(would recommend just doing subtask1,subtask2 etc.) also need to adjust name below in the out file
		N=rnd.next(1,20000),K=rnd.next(1,min(N,11));//adjust n,k constraints here, or set them
	//	N=20000,K=11;//adjust n,k constraints here, or set them
		o<<N<<" "<<K<<"\n";
		for(int i = 1; i<N; i++){
			arr[i]=rnd.next((long long)1,(long long)1e9);//adjust ai constraints here
			o<<arr[i]<<" ";
			arr[i] += arr[i-1];
		}
		arr[N]=rnd.next((long long)1,(long long)1e9);//adjust ai constraints here
		o<<arr[N]<<"\n";
		arr[N] += arr[N-1];
		for(int k = 0; k<K-1; k++){
			val[k]=rnd.next((long long)1,(long long)1e14);//adjust ki constraints here
			o<<val[k]<<" ";
		}
		val[K-1]=rnd.next((long long)1,(long long)1e14);//adjust ki constraints here
		o<<val[K-1]<<"\n";
		o.close();
		dp[0][0] = 1;
		for(int i = 1; i<=N; i++){
			for(int k = 0; k<K; k++){
				while(ptr[k] < i && arr[i] - arr[ptr[k]+1] >= val[k]){
					ptr[k]++;
				}
			}
			for(int m = 0; m<1<<K; m++){
				if(dp[m][i-1]){
					dp[m][i] = 1;
				}
				else{
					for(int k = 0; k<K; k++){
						if(((1<<k)&m) && ptr[k] != i && arr[i]-arr[ptr[k]] >= val[k]){
							dp[m][i] |= dp[m^(1<<k)][ptr[k]];
						}
					}
				}
			}
		}
		ofstream o2("subtask1case" + to_string(cases) + ".out");//adjust name of file here(would recommend just doing subtask1,subtask2 etc.) also need to adjust name below
		if(dp[(1<<K)-1][N]){
			o2 << "YES\n";
		}
		else{
			o2 << "NO\n";
		}
	}
	return 0;
}