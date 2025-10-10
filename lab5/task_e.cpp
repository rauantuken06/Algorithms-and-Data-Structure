#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, k;
    cin>>n>>k;
    priority_queue<long long, vector<long long>, greater<long long>> arr;
    long long sum=0;

    for(long long i=0; i<n; i++){
        string action;
        cin>>action;

        if(action=="insert"){
            long long data; cin>>data;
            arr.push(data);
            sum+=data;

            if(arr.size()>k){
                sum-=arr.top();
                arr.pop();
            }
        }
        else if(action=="print"){
            cout<<sum<<"\n";
        }
    }

    return 0;
}