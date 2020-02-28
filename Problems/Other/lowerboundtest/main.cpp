#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
template <class T> struct RIT :iterator<random_access_iterator_tag, T,lli,const T*,T>{
    T elt,skip;
    RIT(T t, T jump) : elt(t), skip(jump) {}
    bool operator == (const RIT &other) const { return elt == other.elt; }
    bool operator != (const RIT &other) const { return elt != other.elt; }
    T &operator * ()  { return elt; }
    RIT &operator ++ () { elt += skip; return *this; }
    RIT &operator += (lli am) { elt += am*skip; return *this; }
    RIT operator + (lli am) const { auto ret = RIT(elt + am * skip,skip); return ret; }
    lli operator - (const RIT& other) const{return (elt-other.elt)/skip;}
};
bool func(double a){
    return a<7.1;
}
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    printf("%f\n",*lower_bound(RIT<double>(1,0.1), RIT<double>(1000,0.1), func, [](auto & lhs, auto f){
        return f(lhs);
    }));
    return 0;
}