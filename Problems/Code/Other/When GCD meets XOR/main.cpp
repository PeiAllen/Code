/* 
 * File:   main.cpp
 * Author: allen
 *
 * Created on April 21, 2019, 1:02 PM
 */

#include <cstdlib>
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli gcd(lli a, lli b) {
    if (b == 0)return a;
    return gcd(b, a % b);
}

/*
 * 
 */
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    lli n;
    cin>>n;
    lli blocksize = ceil(sqrt((double)n));
    unordered_map<lli, lli> xors[(lli)ceil(n/(double)blocksize)];
    lli totgcd[(lli)ceil(n/(double)blocksize)];
    lli totxo[(lli)ceil(n/(double)blocksize)];
    lli arr[n];
    lli gc = 0;
    lli xo = 0;
    for (lli i = 0; i < n; i++) {
        cin >> arr[i];
        if (i / blocksize != (i - 1) / blocksize) {
            if (i > 0) {
                totgcd[i / blocksize - 1] = gc;
                totxo[i / blocksize - 1] = xo;
            }
            gc = 0;
            xo = 0;
        }
        xo ^= arr[i];
        gc = gcd(gc, arr[i]);
        if (!xors[i / blocksize].count(xo)) {
            xors[i / blocksize][xo] = i;
        }
    }
    totgcd[(n - 1) / blocksize] = gc;
    totxo[(n - 1) / blocksize] = xo;
    lli q;
    cin>>q;
    lli a, b, c;
    for (; q > 0; q--) {
        cin>>a;
        if (a == 1) {
            cin >> b>>c;
            arr[b] = c;
            gc = 0;
            xo = 0;
            xors[b/blocksize].clear();
            for (lli i = (b / blocksize) * blocksize; i < min(n,(b / blocksize+1) * blocksize); i++) {
                xo ^= arr[i];
                gc = gcd(gc, arr[i]);
                if (!xors[i / blocksize].count(xo)) {
                    xors[i / blocksize][xo] = i;
                }
            }
            totgcd[(b) / blocksize] = gc;
            totxo[(b) / blocksize] = xo;
        } else {
            cin>>b;
            gc = arr[0];
            xo = 0;
            bool work=false;
            for (lli i = 0; i < (lli) ceil(n / (double) blocksize); i++) {
                if (gcd(gc, totgcd[i]) != gc) {
                    for(lli j=i*blocksize;j<min(n,(i+1)*blocksize);j++){
                        gc=gcd(gc,arr[j]);
                        xo^=arr[j];
                        if(gc*xo==b){
                            printf("%lli\n",j);
                            work=true;
                            break;
                        }
                    }
                } else {
                    if (b % gc == 0 && xors[i].count((b/gc)^xo)) {
                        printf("%lli\n",xors[i][(b/gc)^xo]);
                        work=true;
                        break;
                    }
                    gc=gcd(gc, totgcd[i]);
                    xo^=totxo[i];
                }
            }
            if(!work){
            printf("-1\n");
            }
        }
    }
    return 0;
}

