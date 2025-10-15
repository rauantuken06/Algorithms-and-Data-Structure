#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int>arr(n);
    vector<int>result;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    sort(arr.begin(), arr.end());
    int minimal_dif=1000000;
    for(int i=0; i<n-1; i++){
        int min_in=abs(arr[i]-arr[i+1]);
        if(min_in<minimal_dif){
            minimal_dif=min_in;
        }
    }

    for(int i=0; i<n-1; i++){
        if(abs(arr[i]-arr[i+1])==minimal_dif){
            result.push_back(arr[i]);
            result.push_back(arr[i+1]);
        }
    }

    for(int lol:result){
        cout<<lol<<" ";
    }

    return 0;
}