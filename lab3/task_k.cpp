#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long K;
    cin >> n >> K;

    vector<long long>arr(n);
    for (int i=0; i<n; i++) {
        cin>>arr[i];
    }

    long long sum=0;
    int left=0;
    int ans=n + 1;

    for (int right = 0; right < n; right++) {
        sum += arr[right];

        while (sum >= K) {
            ans = min(ans, right - left + 1);
            sum -= arr[left];
            left++;
        }
    }

    cout<<ans<<"\n";
    return 0;
}