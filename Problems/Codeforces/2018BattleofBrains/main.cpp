#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
//using namespace __gnu_pbds;
//
//typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define complete_unique(a) a.erase(unique(a.begin(),a.end()),a.end())
#define all(a) a.begin(),a.end()
#define println printf("\n");
#define readln(x) getline(cin,x);
#define pb push_back
//#define endl "\n"
#define INT_INF 0x3f3f3f3f
#define LL_INF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9
#define MOD 1000000007
#define MOD2 1494318097
#define SEED 131
#define mp make_pair
#define fastio cin.tie(0); cin.sync_with_stdio(0);

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<ll,ll> pll;
typedef pair<int,pii> triple;
typedef int8_t byte;

const ld PI = (ld)4*atanl(1);

mt19937 g1(chrono::steady_clock::now().time_since_epoch().count());

int randint(int a, int b){return uniform_int_distribution<int>(a, b)(g1);}
ll randlong(ll a,ll b){return uniform_int_distribution<long long>(a, b)(g1);}

ll gcd(ll a, ll b){return b == 0 ? a : gcd(b, a % b);}
ll lcm(ll a, ll b){return a*b/gcd(a,b);}
ll fpow(ll  b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
ll divmod(ll i, ll j, ll mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}

struct player{
    string name;
    int att,def;
    int titles_won,matches_won,matches_lost;
    ll score;
};
int cur_rand = 0, multiplier = 1000075057, adder = 1000099999, modder = 1088888881;
inline void gen_next_rand(){cur_rand=((ll)cur_rand*multiplier+adder)%modder;}
inline bool point_simulator(player p1, player p2){
    gen_next_rand();
    int p = 50+p1.att-p2.def;
    int r = cur_rand%100;
    return r<p;
}

struct cmp{
    bool operator()(const player &a, const player&b) const {
        if(a.score == b.score) return a.name<b.name;
        return a.score>b.score;
    }
};
set<player,cmp> players,retired;
map<string,player> conv;
map<string,map<string,int>> tourneys,matches;
int Q;

inline int find_rank(player t, bool ret){
    int cnt = 0;
    set<player,cmp> &s = (ret?retired:players);
    for(player check:s){
        if(check.name == t.name) return cnt+1;
        cnt++;
    }
    assert(false);
}

inline vector<string> get_players(int amount, int rnk){
    int cnt = 0;
    vector<string> ret;
    for(player check:players){
        if(++cnt == rnk+1){
            auto it = players.lower_bound(check);
            for(int k=1; k<=amount; k++){
                ret.pb((*it).name);
                ++it;
            }
            break;
        }
    }
    assert(ret.size()==amount);
    return ret;
}

inline void invalidate_old(string name){
    for(auto &check:tourneys[name]){
        player t = conv[check.first];
        players.erase(t);
        t.score-=1<<check.second;
        conv[check.first] = t;
        players.insert(t);
    }
}

inline vector<int> get_permutation(int k){
    if(k == 1) return {1,2};
    vector<int> te = get_permutation(k-1);
    vector<int> ans(1<<k);
    for(int i=0; i<(1<<k); i++){
        if(i%2) ans[i] = (1<<k)+1-ans[i-1];
        else ans[i] = te[i/2];
    }
    return ans;
}

inline string simulate_game(string &a, string &b){
    int a_points = 0, b_points = 0;
    player a_p = conv[a], b_p = conv[b];
    while(a_points != 75 && b_points != 75){
        if(point_simulator(a_p,b_p)){
            if(a_points == 60&&b_points!=60) a_points = 75;
            else{
                if(b_points == 60 && a_points == 60) b_points = 45,a_points=45;
                else a_points+=15;
            }
        }else{
            if(b_points == 60&&a_points!=60) b_points = 75;
            else{
                if(a_points == 60 && b_points == 60) b_points = 45,a_points=45;
                else b_points+=15;
            }
        }
    }
    if(a_points == 75) return a;
    return b;
}

inline string simulate_set(string a, string b, int &cnt){
    int a_wins = 0, b_wins = 0;
    while(!((a_wins >= 6 && a_wins-2 >= b_wins) || (b_wins >= 6 && b_wins-2 >= a_wins))){
        string winner;
        if(cnt%2 == 0) winner = simulate_game(a,b);
        else winner = simulate_game(b,a);
        cnt++;
        if(winner == a) a_wins++;
        else b_wins++;
    }
    if(b_wins >= 6 && b_wins-2 >= a_wins) return b;
    return a;
}

inline string get_winner(string a, string b, int set_count){
    int a_wins = 0, b_wins = 0, req = (set_count+1)/2, cnt = 0;
    while(a_wins < req && b_wins < req){
        string winner = simulate_set(a,b,cnt);
        if(winner == a) a_wins++;
        else b_wins++;
    }
    if(b_wins == req) swap(a,b);
    player t = conv[a];
    players.erase(t);
    t.matches_won++;
    players.insert(t);
    conv[a] = t;

    t = conv[b];
    players.erase(t);
    t.matches_lost++;
    players.insert(t);
    conv[b] = t;
    return a;
}

inline void play_tournament(string name, int num_rounds, int set_count, vector<string> &v){
    map<string,int> number_wins;
    for(string check:v)
        number_wins[check] = 0;

    assert(v.size()==(1<<num_rounds));
    vector<int> permut = get_permutation(num_rounds);
    assert(permut.size()==v.size());
    vector<string> real_v;
    for(int check:permut)
        real_v.pb(v[check-1]);
  //  reverse(real_v.begin(),real_v.end());
    for(int i=1; i<=num_rounds; i++){
        vector<string> next_v;
        for(int k=0; k<real_v.size(); k+=2){
            string first = real_v[k], second = real_v[k+1];
            string winner = get_winner(first,second,set_count);
            next_v.pb(winner);
            number_wins[winner]++;
        }
        real_v = next_v;
    }
    assert(real_v.size()==1);
    string winner = real_v[0];
    player t = conv[winner];
    players.erase(t);
    t.titles_won++;
    players.insert(t);
    conv[winner] = t;
    tourneys[name] = number_wins;
    for(pair<string,int> check:number_wins){
        t = conv[check.first];
        players.erase(t);
        t.score+=1<<check.second;
        players.insert(t);
        conv[check.first] = t;
    }
}

int main(){
    fastio; cin >> Q;
    while(Q--){
        string op; cin >> op;
        if(op == "add"){
            player t;
            cin >> t.name >> t.att >> t.def;
            t.score = t.titles_won = t.matches_lost = t.matches_won = 0;
            players.insert(t);
            conv[t.name] = t;
            cout << "added " << t.name << endl;
        }else if(op == "retire"){
            string s; cin >> s;
            player t = conv[s];
            players.erase(t);
            retired.insert(t);
            cout << "retired " << s << endl;
        }else if(op == "play"){
            string name; int k,set_count,rnk;
            cin >> name >> k >> set_count >> rnk;

            vector<string> v = get_players(1<<k,rnk);
            invalidate_old(name);
            play_tournament(name,k,set_count,v);

            cout << "played " << name << endl;
        }else if(op == "standings"){
            int cnt = 0;
            for(player check:players)
                cout << (++cnt) << ". " << check.name << " " << check.score << endl;
        }else if(op == "profile"){
            string s; cin >> s;
            player t = conv[s];
            bool ret = !players.count(t);
            cout<<ret<<endl;
            cout << t.name << endl;
            cout << "att: " << t.att << endl;
            cout << "def: " << t.def << endl;
            cout << "retired: " << (ret?"yes":"no") << endl;
            cout << "rank: " << (ret?'-':find_rank(t,ret)) << endl;
            cout << "score: " << (ret?'-':t.score) << endl;
            cout << "title: " << t.titles_won << endl;
            cout << "win-loss: " << t.matches_won << "-" << t.matches_lost << endl;
        }else{
            assert(op=="h2h");
            string f,s; cin >> f >> s;
            cout << f << " " << matches[f][s] << " : " << matches[s][f] << " " << s << endl;
        }
        cout << "******************************" << endl;
    }
}