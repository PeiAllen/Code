#include <bits/extc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
constexpr int MAXSTREET = 1e5+5, MAXINTER = 1e5+5, MAXCAR = 1005;

template<typename T>
int size(const T &a){return int(a.size());}

struct answer{
    int score = 0;
    vector<pair<int, int>> lights[MAXINTER];
    // {time i, which street gets green}
};

answer run(const int duration, const int numinter, const int numstreet, const int numcar, const int bonus,
           const int length[MAXSTREET], const int destinter[MAXSTREET], const int pathlen[MAXCAR], const vector<int> &carpriority, const vector<int> (&carpath)[MAXCAR]){

    answer ret;
    array<int, 2> carat[numcar]; //intersection, how long until arrives at it
    map<int, queue<int>> waiting[numinter];
    set<int> taken[numinter];
    vector<bool> done(numcar);
    //in order of input
    for(int car = 0; car < numcar; car++){
        carat[car] = {0, 0};
    }

    for(int curtime = 0; curtime < duration; curtime++){
        for(int car: carpriority){
            int street = carpath[car][carat[car][0]];
            int inter = destinter[street];
            if(carat[car][1]){
                //keep on moving

                if(!--carat[car][1]){
                    //arives at a light
                    if(carat[car][0] == pathlen[car]-1){
                        done[car] = 1;
                        ret.score += bonus + duration-curtime-1;
                    }
                    waiting[inter][street].emplace(car);
                }
            }
            else{
                assert(!carat[car][1]);
                //move this car if possible
                //check if this light is free
                if(!size(ret.lights[inter]) or ret.lights[inter].back().first < curtime){
                    //check if this car is first in line
                    if(waiting[inter][street].front() == car){
                        // make sure it's continuous interval of time
                        if((ret.lights[inter].back().second == street) or !taken[inter].count(street)){
                            //now I can take
                            taken[inter].insert(street);
                            ret.lights[inter].emplace_back(curtime, street);

                            waiting[inter][street].pop();

                            carat[car][0]++;
                            street = carpath[car][carat[car][0]];
                            inter = destinter[street];
                            carat[car][1] = length[street];
                        }
                    }
                }
            }
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

int main(){
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
    auto ret = run(duration, numinter, numstreet, numcar, bonus, length, destinter, pathlen, carpriority, carpath);
    cout<<ret.score<<endl;
}