#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>array(n);
    map<int, int>freq;
    for(int i=0; i<n; i++){
        cin>>array[i];
    }
    for(int x:array){
        freq[x]++;
    }
    int maxFreq=0;
    for(auto &p:freq){
        maxFreq=max(maxFreq, p.second);
    }
    vector<int>modes;
    for(auto &p:freq){
        if(p.second==maxFreq){
            modes.push_back(p.first);
        }
    }

    int temp;
    for(int i=0; i<modes.size(); i++){
        for(int j=i+1; j<modes.size(); j++){
            if(modes[i]<modes[j]){
                temp=modes[i];
                modes[i]=modes[j];
                modes[j]=temp;
            }
        }
    }
    for(int i=0; i<modes.size(); i++){
        cout<<modes[i]<<" ";
    }
    
    return 0;
}