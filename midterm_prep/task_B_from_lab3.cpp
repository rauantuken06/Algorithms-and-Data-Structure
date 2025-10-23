#include <iostream>
using namespace std;

int main(){
    long long n, m;
    cin>>n>>m;
    long long arr[n];

    for(long long i=0; i<n; i++){
        cin>>arr[i];
    }

    long long left=0, right=1e18;
    while(left<=right){
        long long mid=left+(right-left)/2;
        long long counter_blocks=1;
        long long sum=0;

        for(int i=0; i<n; i++){
            if(mid<sum+arr[i]){
                counter_blocks++;
                sum=0;
            }
            if(mid<arr[i]){
                counter_blocks=m+1;
            }

            sum+=arr[i];
        }

        if(m<counter_blocks){
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }

    cout<<left;
    return 0;
}