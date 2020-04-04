#include <iostream>
#include <thread>
#include <chrono>
#include <random>
using namespace std;

int main() {
    srand (static_cast <unsigned> (time(0)));
    float progress = 0.0;
    float random = 0.05 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(1.0-0.05)));
    while (progress < 1.0) {
        int bar = 70;
        cout << "[";
        int pos = bar * progress;
        for (int i = 0; i < bar; ++i){
            if(i < pos){
                cout << "=";
            }
            else if (i == pos){
                cout << ">";
            }
            else {
                cout << " ";
            }
        }
        cout << "]" << int(progress * 100.0) << "%\r";
        cout.flush();
        progress += random;
        this_thread::sleep_for (chrono::seconds(1));
    }
    cout << "[======================================================================]100%\n";


    return 0;
}