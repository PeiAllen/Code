#include "stdio.h"
#include "bitset"
using namespace std;
struct deq{
    unsigned int arr[65536];
    int l=0,r=0;
    unsigned int operator[](int ind){
        if(l+ind>=65536)return arr[l+ind-65536];
        return arr[l+ind];
    }
    int size(){
        if(r-l<0)return r-l+65536;
        return r-l;
    }
    void pop_front(){
        l++;
        if(l==65536)l=0;
    }
    void push_back(unsigned short val){
        arr[r]=val;
        r++;
        if(r==65536)r=0;
    }
};
deq arr,ans;
bitset<65536> gone;
int main(){
    int a;
    int ind=0;
    int aind=-1;
    while(1){
        scanf(" %d",&a);
        if(a==0)break;
        arr.push_back(a);
        while(gone[a]){
            gone[arr[0]]=false;
            arr.pop_front();
        }
        gone[a]=true;
        if(arr.size()>ans.size()){
            for(int i=min(ans.size(),ind-arr.size()+1-(aind-ans.size()+1));i>0;i--)ans.pop_front();
            for(int i=max(0,aind-(ind-arr.size()));i<arr.size();i++)ans.push_back(arr[i]);
            aind=ind;
        }
        ind++;
    }
    for(int i=0;i<ans.size();i++)printf("%d\n",ans[i]);
    return 0;
}