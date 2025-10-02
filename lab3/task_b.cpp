#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canDivide(const vector<int>& arr, int k, long long limit) {
    long long sum=0;
    int cnt=1;

    for (int x : arr) {
        if (sum+x<=limit) {
            sum+=x;
        } else {
            cnt++;
            sum=x;
            if (cnt>k) return false;
        }
    }
    return true;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    long long maxElem = 0, sum = 0;

    for (int i = 0; i < n; i++) {
        cin>>arr[i];
        maxElem=max(maxElem, (long long)arr[i]);
        sum+=arr[i];
    }

    
    long long low=maxElem;
    long long high=sum;  

    while (low < high) {
        long long mid=(low + high)/2;
        if (canDivide(arr, k, mid)) {
            high=mid; 
        } else {
            low=mid+1;
        }
    }

    cout <<low<< endl;
    return 0;
}
