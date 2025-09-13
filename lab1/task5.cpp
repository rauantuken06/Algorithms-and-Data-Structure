#include <iostream>
using namespace std;

bool isPrime(int x){
    if(x<2){
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
    
    long long prime[100000];
    int cnt=0;
    int num=2;
    while(cnt<100000){
        if(isPrime(num)){
            prime[cnt]=num;
            cnt++;
        }
        num++;
    }
    int superCount=0;
    for(int i=0; i<cnt; i++){
        int index=i+1;
        if(isPrime(index)){
            superCount++;
            if(superCount==n){
                cout<<prime[i]<<endl;
                return 0;
            }
        }
    }
}