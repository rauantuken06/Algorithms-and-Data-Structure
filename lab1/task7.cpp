#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main(){
    int n;
    cin>>n;
    string votes;
    cin>>votes;
    queue<int>saka, katsu;

    for(int i=0; i<n; i++){
        if(votes[i]=='S'){
            saka.push(i);
        }
        if(votes[i]=='K'){
            katsu.push(i);
        }
    }

    while(!saka.empty() && !katsu.empty()){
        int i=saka.front(); saka.pop();
        int j=katsu.front(); katsu.pop();
        if(i<j){
            saka.push(i+n);
        }
        else{
            katsu.push(j+n);
        }
    }
    
    if(katsu.empty()){
        cout<<"SAKAYANAGI";
    }
    else{
        cout<<"KATSURAGI";
    }

    return 0;
}