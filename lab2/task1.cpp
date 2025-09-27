#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n;
    cin>>n;
    long long* arr=new long long [n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    long long k;
    cin>>k;
    long long BestDistance=llabs(arr[0]-k);
    long long answer=0;
    for(int i=0; i<n; i++){
        long long NowDist=llabs(arr[i]-k);
        if(NowDist<BestDistance){
            BestDistance=NowDist;
            answer=i;
        }
    }
    cout<<answer<<"\n";
    return 0;
}