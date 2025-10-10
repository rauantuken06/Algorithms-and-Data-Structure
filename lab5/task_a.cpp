#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    priority_queue<long long, vector<long long>, greater<long long>>arr;
    vector<long long>result;
    for(long long i=0; i<n; i++){
        long long num; cin>>num;
        arr.push(num);
    }

    long long sum_of=0;
    while(arr.size()>1){
        long long L=arr.top(); arr.pop();
        long long R=arr.top(); arr.pop();
        long long total_sum=L+R;
        arr.push(total_sum);
        result.push_back(total_sum);
    }

    long long sum_of_all=0;
    for(long long i=0; i<result.size(); i++){
        sum_of_all+=result[i];
    }

    cout<<sum_of_all<<"\n";

    return 0;
}