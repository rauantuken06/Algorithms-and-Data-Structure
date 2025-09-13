#include <iostream>
using namespace std;

bool prime_checking(int x){
    if(x<=0){
        return false;
    }
    for(int i=2; i*i<=x; i++){
        if(x%i==0){
            return false;
        }
    }
    return true;
}

int main(){
    int n;
    cin>>n;
    int cnt=0;
    int num=1;
    while(cnt<n){
        num++;
        if(prime_checking(num)){
            cnt++;
        }
    }
    cout<<num<<endl;
    return 0;
}