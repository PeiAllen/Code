??=include <iostream>
??=include <vector>
??=include <numeric>
using namespace std;
int zero;
int add(int a, int b)??<
    vector<int> te;
    te.push_back(a);
    te.push_back(b);
    return accumulate(te.begin(),te.end(),zero);
    ??>
int main()??<
    int one=(zero==zero);
    int two=add(one,one);
    int four=add(two,two);
    int eight=add(four,four);
    int sixteen=add(eight,eight);
    int thirtytwo=add(sixteen,sixteen);
    int sixtyfour=add(thirtytwo,thirtytwo);
    cout<<(char)(add(sixtyfour,eight));
    cout<<(char)(add(sixtyfour,add(thirtytwo,add(four,one))));
    cout<<(char)(add(sixtyfour,add(thirtytwo,add(eight,four))));
    cout<<(char)(add(sixtyfour,add(thirtytwo,add(eight,four))));
    cout<<(char)(add(sixtyfour,add(thirtytwo,add(eight,add(four,add(two,one))))));
    cout<<(char)(add(thirtytwo,add(eight,four)));
    cout<<(char)(thirtytwo);
    cout<<(char)(add(sixtyfour,add(sixteen,add(four,add(two,one)))));
    cout<<(char)(add(sixtyfour,add(thirtytwo,add(eight,add(four,add(two,one))))));
    cout<<(char)(add(sixtyfour,add(thirtytwo,add(sixteen,two))));
    cout<<(char)(add(sixtyfour,add(thirtytwo,add(eight,four))));
    cout<<(char)(add(sixtyfour,add(thirtytwo,four)));
    cout<<(char)(add(thirtytwo,one));
    ??>