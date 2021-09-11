#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}

int main(){
    double papaJacksonSalary, mamaJacksonSalary, juniorJacksonSalary, mamaJacksonHouse, mamaJacksonCar,
            juniorJacksonHour, juniorJacksonRate, juniorJacksonWeeks;

    cout << "--------------Income--------------" << endl;

    cout << endl;

    cout << "Papa Jackson's yearly salary: ";
    cin >> papaJacksonSalary;
    cout << "Amount of car insurance sold my Mama Jackson: ";
    cin >> mamaJacksonCar;
    cout << "Amount of house insurance sold my Mama Jackson: ";
    cin >> mamaJacksonHouse;
    cout << "Junior Jackson's hourly rate: ";
    cin >> juniorJacksonRate;
    cout << "Number of hours Junior Jackson works per week: ";
    cin >> juniorJacksonHour;
    cout << "Number of weeks Junior Jackson works per year: ";
    cin >> juniorJacksonWeeks;
    return 0;
}