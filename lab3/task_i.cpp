#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin>>n;

    vector<int>arr(n);
    for (int i=0; i<n; i++) {
        cin>>arr[i];
    }

    int x;
    cin>>x;

    int left = 0, right = n - 1;
    bool found = false;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid]==x) {
            found = true;
            break;
        }
        else if (arr[mid]<x) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    if (found){
        cout<<"Yes\n";
    }
    else{
        cout<<"No\n";
    }
    return 0;
}