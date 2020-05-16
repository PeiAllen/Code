#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
typedef __float128 ld;
ld w,h,l,u,r,d;
ld get(ld a, ld b){
    ld calc=1;
    if (b-1 > 0) {
        lli am = (lli) (a - 1 + b - 1) / (lli) (b - 1);
        lli oth = (lli) (a - 1 + b - 1) % (lli) (b - 1);
        ld pre = 1;
        for (lli i = 1; i <= am; i++)pre *= 2;
        for (ld i = a; i <= (a - 1 + b-1); i++) {
            calc *= i /pre/ (i - (a - 1));
            if(i-a+1<=oth)calc/=2;
        }
    } else {
        for (int i = 0; i < a - 1 + b-1; i++)calc /= 2;
    }
    return calc;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    int cs=1;
    while(t--){
        long double w1,h1,l1,u1,r1,d1;
        cin>>w1>>h1>>l1>>u1>>r1>>d1;
        w=w1,h=h1,l=l1,u=u1,r=r1,d=d1;
        ld ans=1;
        //(l-1+u-2)*...(l)/(1)...(u-2)/2^(l-1+u-2)
        if(u-1>0) {
            if(u<=r) {
                ld calc = get(l, u - 1);
                for (ld i = l; i <= r; i++) {
                    if (i == w) {
                        calc = get(1, r);
                        if (r - 1 >= 1) {
                            if(r<=u-1) {
                                ld calc2 = get(2, r - 1);
                                for (ld j = 2; j <= u - 1; j++) {
                                    calc += calc2 / 2;
                                    calc2 /= (2 * j / (j + r - 2));
                                }
                            }
                            else{
                                ld calc2 = get(u-1, r - 1);
                                for (ld j = u-1; j >=2; j--) {
                                    calc += calc2 / 2;
                                    calc2 *= (2 * (j-1) / ((j-1) + r - 2));
                                }
                            }
                        }
                        ans -= calc;
                    } else {
                        ans -= calc / 2;
                        calc /= (2 * i / (i + u - 2));
                    }
                }
            }
            else{
                if(r==w){
                    ld calc = get(1, r);
                    if (r - 1 >= 1) {
                        if(r<=u-1) {
                            ld calc2 = get(2, r - 1);
                            for (ld j = 2; j <= u - 1; j++) {
                                calc += calc2 / 2;
                                calc2 /= (2 * j / (j + r - 2));
                            }
                        }
                        else{
                            ld calc2 = get(u-1, r - 1);
                            for (ld j = u-1; j >=2; j--) {
                                calc += calc2 / 2;
                                calc2 *= (2 * (j-1) / ((j-1) + r - 2));
                            }
                        }
                    }
                    ans -= calc;
                }
                else {
                    ld calc = get(r, u - 1);
                    ans-=calc/2;
                }
                if(r-1>=1) {
                    ld calc = get(r-1, u - 1);
                    for (ld i = r-1; i >=l; i--) {
                            ans -= calc / 2;
                            calc *= (2 * (i-1) / ((i-1) + u - 2));
                    }
                }
            }
        }
        if(l-1>0) {
            if(l<=d) {
                ld calc = get(u, l - 1);
                for (ld i = u; i <= d; i++) {
                    if (i == h) {
                        calc = get(1, d);
                        if (d - 1 >= 1) {
                            if(d<=l-1){
                                ld calc2 = get(2, d - 1);
                                for (ld j = 2; j <= l - 1; j++) {
                                    calc += calc2 / 2;
                                    calc2 /= (2 * j / (j + d - 2));
                                }
                            }
                            else{
                                ld calc2 = get(l-1, d - 1);
                                for (ld j = l-1; j >=2; j--) {
                                    calc += calc2 / 2;
                                    calc2 *= (2 * (j-1) / ((j-1) + d - 2));
                                }
                            }
                        }
                        ans -= calc;
                    } else {
                        ans -= calc / 2;
                        calc /= (2 * i / (i + l - 2));
                    }
                }
            }
            else{
                if(d==h){
                    ld calc = get(1, d);
                    if (d - 1 >= 1) {
                        if(d<=l-1) {
                            ld calc2 = get(2, d - 1);
                            for (ld j = 2; j <= l - 1; j++) {
                                calc += calc2 / 2;
                                calc2 /= (2 * j / (j + d - 2));
                            }
                        }
                        else{
                            ld calc2 = get(l-1, d - 1);
                            for (ld j = l-1; j >=2; j--) {
                                calc += calc2 / 2;
                                calc2 *= (2 * (j-1) / ((j-1) + d - 2));
                            }
                        }
                    }
                    ans -= calc;
                }
                else{
                    ld calc = get(d , l - 1);
                    ans -= calc / 2;
                }
                if(d-1>=1) {
                    ld calc = get(d - 1, l - 1);
                    for (ld i = d-1; i >=u; i--) {
                        ans -= calc / 2;
                        calc *= (2 * (i-1) / ((i-1) + l - 2));
                    }
                }
            }
        }
        printf("Case #%d: %.18f\n",cs,(double)ans);
        cs++;
    }
    return 0;
}