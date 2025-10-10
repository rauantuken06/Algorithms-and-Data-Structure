#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, m; cin>>n>>m;
    priority_queue<long long> arr;
    for(int i=0; i<n; i++){
        long long num;
        cin>>num;
        arr.push(num);
    }

    long long lol=0;
    long long pribyl_ot_biletov=0;
    while(lol!=m){
        long long L=arr.top(); arr.pop();
        pribyl_ot_biletov+=L;
        long long fixed=L-1;
        arr.push(fixed);
        lol++;
    }

    cout<<pribyl_ot_biletov<<"\n";

    return 0;
}