#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n, m;
    cin>>n>>m;
    priority_queue<long long, vector<long long>, greater<long long>> arr;
    for(int i=0; i<n; i++){
        int data; cin>>data;
        arr.push(data);
    }

    long long cnt=0;
    while(arr.size()>1){
        if(arr.top()>m){
            cout<<cnt<<"\n";
            return 0;
        }
        
        int L=arr.top(); arr.pop();
        int R=arr.top(); arr.pop();
        int dentity=L+2*R;
        arr.push(dentity);
        cnt++;
    }

    cout<<-1<<"\n";
    return 0;
}