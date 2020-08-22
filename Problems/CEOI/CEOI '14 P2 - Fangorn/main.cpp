#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
pair<double,double> camps[(int)1e4+1];
pair<double,double> trees[(int)2e3+1];
bool work[(int)1e4+1];
const double pi=acos(-1);
vector<double> angles;
int rightindex(double angle){
    int te=(upper_bound(angles.begin(),angles.end(),angle)-angles.begin());
    return (te==sz(angles)?0:te);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int w,h;
    cin>>w>>h;
    pair<double,double> st;
    cin>>st.first>>st.second;
    int c;
    cin>>c;
    for(int i=0;i<c;i++)cin>>camps[i].first>>camps[i].second,work[i]=true;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>trees[i].first>>trees[i].second;
    for(int i=0;i<n;i++){
        angles=vector<double>();
        for(int j=0;j<n;j++){
            if(i!=j){
                double te=atan2(trees[j].second-trees[i].second,trees[j].first-trees[i].first)-pi;
                if(te<=-pi)te=pi-(-pi-te);
                angles.push_back(te);
            }
        }
        sort(angles.begin(),angles.end());
        int curregion=rightindex(atan2(st.second-trees[i].second,st.first-trees[i].first));
        double le=angles[(curregion?curregion-1:sz(angles)-1)],ri=angles[curregion];
        bool baf=le>ri;
        for(int j=0;j<c;j++){
            double te=atan2(camps[j].second-trees[i].second,camps[j].first-trees[i].first);
            if(baf){
                if(te>ri&&te<le)work[j]=false;
            }
            else{
                if(te<le||te>ri)work[j]=false;
            }
        }
    }
    vector<int> workingcamps;
    for(int i=0;i<c;i++)if(work[i])workingcamps.push_back(i+1);
    printf("%d\n",sz(workingcamps));
    for(auto x:workingcamps)printf("%d ",x);
    return 0;
}