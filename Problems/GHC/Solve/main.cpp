#include <bits/extc++.h>
#define all(x) (x).begin(), (x).end()

// #define ONLINE_JUDGE

// #ifndef ONLINE_JUDGE
// template<typename T>
// void pr(T a){std::cerr<<a<<std::endl;}
// template<typename T,typename... Args>
// void pr(T a, Args... args) {std::cerr<<a<<' ',pr(args...);}
// #define watch(x) cerr << #x << ": " << x << endl
// #else
// template<typename... Args>
// #define watch(x) ;
// void pr(Args... args){}
// #endif

using namespace std;
constexpr int MAXSTREET = 1e5+5, MAXINTER = 1e5+5, MAXCAR = 1005;

template<typename T>
int size(const T &a){return int(a.size());}

mt19937_64 g(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 g((uint64_t) new char);
// mt19937_64 g(0);
int randint(int l, int r){return uniform_int_distribution<int>(l, r)(g);}
long long randl(long long l, long long r){return uniform_int_distribution<long long>(l, r)(g);}
double randf(double l, double r){return uniform_real_distribution<double>(l, r)(g);}

struct answer{
    int score = 0;
    vector<pair<int, int>> lights[MAXINTER];
    // {time i, which street gets green}
};

answer run(const int duration, const int numinter, const int numstreet, const int numcar, const int bonus,
           const int length[MAXSTREET], const int destinter[MAXSTREET], const int pathlen[MAXCAR], const vector<int> &carpriority, const vector<int> (&carpath)[MAXCAR]){

    answer ret;
    array<int, 2> carat[numcar+1]; //intersection, how long until arrives at it
    map<int, queue<int>> waiting[numstreet+1];
    set<int> taken[numinter+1];
    vector<bool> done(numcar+1);

    vector<int> inorder = carpriority;
    sort(all(inorder));

    //add cars in order of input
    //(actualy time may be longer because you need to clear intersections of dummies)
    for(int car=0;car<numcar;car++){
        carat[car] = {0, -1};
        int street = carpath[car][carat[car][0]];
        int inter = destinter[street];
        waiting[inter][street].emplace(car);
    }

    for(int curtime = 0; curtime < duration; curtime++){
        // watch(curtime);
        vector<pair<int,int>> topop;
        vector<pair<pair<int,int>,int>> topush;
        for(int car: carpriority){
            if(done[car]) continue;
            // pr(car, carat[car][0], carat[car][1]);
            int street = carpath[car][carat[car][0]];
            int inter = destinter[street];
            if(carat[car][1] > 0){
                //keep on moving
                carat[car][1]--;
            }
            else{
                //move this car if possible
                //check if this light is free
                if(!size(ret.lights[inter]) or ret.lights[inter].back().first < curtime){
                    //check if this car is first in line
                    // assert(waiting[inter].count(street) and size(waiting[inter][street]));
                    if(waiting[inter][street].front() == car){

                        // make sure it's continuous interval of time
                        if((size(ret.lights[inter]) and ret.lights[inter].back().second == street) or !taken[inter].count(street)){
                            //now I can take
                            taken[inter].insert(street);
                            ret.lights[inter].emplace_back(curtime, street);

//                            topop.push_back({inter,street});
                            waiting[inter][street].pop();

                            carat[car][0]++;
                            street = carpath[car][carat[car][0]];
                            inter = destinter[street];
                            carat[car][1] = length[street]-1;
                        }
                    }
                }
            }

            if(!carat[car][1]){
                carat[car][1] = -1;
                //arives at a light
                if(carat[car][0] == pathlen[car]-1){
                    done[car] = 1;
                    ret.score += bonus + duration-curtime-1;
                    // pr("arrive", car, curtime+1);
                }
                else{
                    topush.push_back({{inter,street},car});
                }
            }
        }
//        for(auto x:topop){
//            waiting[x.first][x.second].pop();
//        }
        for(auto x:topush){
            waiting[x.first.first][x.first.second].push(x.second);
        }
    }

    return ret;
}

__gnu_pbds::gp_hash_table<string, int> mp;
string streetnames[MAXSTREET];
int laststreetid;

int duration, numinter, numstreet, numcar, bonus;
int length[MAXSTREET];
int destinter[MAXSTREET];
int pathlen[MAXCAR];
vector<int> carpath[MAXCAR];

int getid(const string &s){
    if(mp.find(s) != mp.end()) return mp[s];
    streetnames[laststreetid] = s;
    return mp[s] = laststreetid++;
}

const string& getname(int id){
    return streetnames[id];
}

int main(int argc, char* args[]){
    int runtimes = 20;
    if(argc > 1){
        runtimes = atoi(args[1]);
        // cerr<<"runtimes "<<runtimes<<'\n';
    }

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> duration >> numinter >> numstreet >> numcar >> bonus;
    for(int i = 0; i < numstreet; i++){
        int frominter, tointer; string streetname;
        cin >> frominter >> tointer >> streetname;
        int street = getid(streetname);
        cin >> length[street];
        destinter[street] = tointer;
    }
    for(int i = 0; i < numcar; i++){
        cin >> pathlen[i];
        carpath[i].resize(pathlen[i]);
        for(int j = 0; j < pathlen[i]; j++){
            string s;
            cin>>s;
            int id = getid(s);
            carpath[i][j] = id;
        }
    }
    // input done
    vector<int> carpriority(numcar);
    iota(all(carpriority), 0);
    shuffle(all(carpriority), g);

    // carpriority.resize(numcar*0.75);

    auto ret = run(duration, numinter, numstreet, numcar, bonus, length, destinter, pathlen, carpriority, carpath);
    while(runtimes--){
        shuffle(all(carpriority), g);
        auto r2 = run(duration, numinter, numstreet, numcar, bonus, length, destinter, pathlen, carpriority, carpath);
        if(r2.score > ret.score)ret=r2;
    }

    cerr<<"ans "<<ret.score<<'\n';
    ofstream myfile;
    myfile.open("ans.txt");
    myfile<<ret.score<<"\n";
    myfile.close();


    int A = 0;
    for(int inter = 0; inter < numinter; inter++){
        if(size(ret.lights[inter])){
            A++;
        }
    }
    cout<<A<<'\n';
    for(int inter = 0; inter < numinter; inter++){
        if(size(ret.lights[inter])){
            vector<pair<int, int>> out;
            int laststreet = -1, lasttime = 0;
            for(auto x: ret.lights[inter]){
                auto t=x.first,street=x.second;
                // for(auto p: ret.lights[inter]){
                // auto t = p.first, street = p.second;

                if(street != laststreet){
                    if(laststreet!=-1) {
                        out.emplace_back(laststreet, t - lasttime);
                        laststreet = street;
                        lasttime = t;
                    }
                    else{
                        laststreet = street;
                        lasttime = 0;
                    }
                }
            }
            out.emplace_back(laststreet, duration-lasttime);

            cout<<inter<<'\n';
            cout<<size(out)<<'\n';
            for(auto x: out)
                cout<<getname(x.first)<<' '<<x.second<<'\n';
        }
    }
}