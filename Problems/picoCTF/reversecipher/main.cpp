#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
void sc(){}
template<typename T,typename... Args>
void sc(T& a, Args&... args) {cin>>a,sc(args...);}
template<typename T>
void pr(T a){cout<<a;}
template<typename T,typename... Args>
void pr(T a, Args... args) {cout<<a<<" ",pr(args...);}
template<typename T>
void prl(T a){cout<<a<<"\n";}
template<typename T,typename... Args>
void prl(T a, Args... args) {cout<<a<<" ",prl(args...);}
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

int main(void)

{
	size_t sVar1;
	char local_58 [23];
	char local_41;
	int local_2c;
	FILE *local_28;
	FILE *local_20;
	unsigned int local_14;
	int local_10;
	char local_9;

	local_20 = fopen("flag.txt","r");
	local_28 = fopen("rev_this","a");
	if (local_20 == (FILE *)0x0) {
		puts("No flag found, please make sure this is run on the server");
	}
	if (local_28 == (FILE *)0x0) {
		puts("please run this on the server");
	}
	sVar1 = fread(local_58,24,1,local_20);//reads first 23 bytes to local_58
	local_2c = (int)sVar1;
	if ((int)sVar1 < 1) {
		/* WARNING: Subroutine does not return */
		exit(0);
	}
	local_10 = 0;
	while (local_10 < 8) {
		local_9 = local_58[local_10];
		fputc((int)local_9,local_28);
		local_10 = local_10 + 1;
	}
	local_14 = 8;
	while ((int)local_14 < 0x17) {
		if ((local_14 & 1) == 0) {
			local_9 = local_58[(int)local_14] + '\x05';
		}
		else {
			local_9 = local_58[(int)local_14] + -2;
		}
		fputc((int)local_9,local_28);
		local_14 = local_14 + 1;
	}
	local_9 = local_41;
	fputc((int)local_41,local_28);
	fclose(local_28);
	fclose(local_20);
	return 0;
}
