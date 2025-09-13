#include <iostream>
using namespace std;
int main(){
    int num;
    cin>>num;
    bool is_Prime=true;
    if(num<2){
        is_Prime=false;
    }
    for(int i=2; i*i<=num; i++){
        if(num%i==0){
            is_Prime=false;
        }
    }
    if(is_Prime){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}