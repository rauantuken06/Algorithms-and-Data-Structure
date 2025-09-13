#include <iostream>
#include <queue>
using namespace std;

int main(){
    queue<int>boris, nurik;
    for(int i=0; i<5; i++){
        int x;
        cin>>x;
        boris.push(x);
    }
    for(int i=0; i<5; i++){
        int x;
        cin>>x;
        nurik.push(x);
    }
    int moves=0;
    const int limit=1000000;
    while(!boris.empty() && !nurik.empty() && moves<limit){
        moves++;
        int b=boris.front(); boris.pop();
        int n=nurik.front(); nurik.pop();
        bool borisWins;
        if(b==0 && n==9){
            borisWins=true;
        }
        else if(b==9 && n==0){
            borisWins=false;
        }
        else{
            borisWins=(b>n);
        }
        if(borisWins){
            boris.push(b);
            boris.push(n);
        }
        else{
            nurik.push(b);
            nurik.push(n);
        }
    }
    if(moves>=limit){
        cout<<"draw\n";
    }
    if(boris.empty()){
        cout<<"Nursik "<<moves<<"\n";
    }
    if(nurik.empty()){
        cout<<"Boris "<<moves<<"\n";
    }

}