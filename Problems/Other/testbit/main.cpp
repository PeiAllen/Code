#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int bit[100];
int query(int loc){
	int sum=0;
	for(;loc>0;loc-=loc&-loc){
		sum+=bit[loc];
	}return sum;
}
void update(int loc, int val){
	for(;loc<100;loc+=loc&-loc){
		bit[loc]+=val;
	}
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    update(2,3);
    update(5,-3);
    printf("%d %d\n",query(4),query(4)-query(3));
    return 0;
}