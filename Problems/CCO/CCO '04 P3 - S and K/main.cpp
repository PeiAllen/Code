#include <iostream>
#include <string>
#include <map>
using namespace std;

string lc(const string &s) {
    int i, p;
    for( i = 1, p = 0; p += (s[i]=='(')-(s[i]==')'); i++ );
    return s.substr( 1, i );
}

string rc(const string &s) {
    int i, p;
    for( i = s.size()-2, p = 0; p += (s[i]=='(')-(s[i]==')'); i-- );
    return s.substr( i, s.size()-1-i );
}

map<string, string> memo;
string apply(const string &s) {
    string &ret = memo[s];
    if( ret.size() ) return ret;
    if( s.size() == 1 ) return ret = s;
    if( s.substr(0, 3) == "((K" )			// rule 1
        return ret = rc(lc(s));
    if( s.substr(0, 4) == "(((S" )			// rule 2
        return ret = "(("+rc(lc(lc(s)))+rc(s)+")("+rc(lc(s))+rc(s)+"))";
    string t = apply(lc(s));				// rule 3
    if( t != lc(s) ) return ret = "("+t+rc(s)+")";
    return ret = "("+t+apply(rc(s))+")";	// rule 4
}

main() {
    freopen("sk9.in","r",stdin);
    string s;
    while( cin >> s ) {
        for(;;) {
// cout << s << '\n';
            string t = apply(s);
            if( t == s ) break;
            s = t;
        }
        cout << s << '\n';
    }
}
