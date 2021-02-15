#pragma GCC optimize "Ofast"

#include <iostream>
using namespace std;

//troloololololollol

int main() {
    int N;
    scanf("%d", &N);

    for(int S = 1; ; S++) {
        int t = 0;

        for(int i = 0; i <= S; i++) {
            t += S / 2 + (1 - i % 2);
        }

        if(t >= N) {
            printf("%d", S);
            break;
        }
    }
}