#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin>>n>>q;
    vector<int>arr(n);
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }

    sort(arr.begin(), arr.end());

    while (q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        int cnt1 = upper_bound(arr.begin(), arr.end(), b) -
                   lower_bound(arr.begin(), arr.end(), a);

        int cnt2 = upper_bound(arr.begin(), arr.end(), d) -
                   lower_bound(arr.begin(), arr.end(), c);

        int result=cnt1 + cnt2;

        int L = max(a, c);
        int R = min(b, d);
        if (L <= R) {
            int overlap = upper_bound(arr.begin(), arr.end(), R) -
                          lower_bound(arr.begin(), arr.end(), L);
            result -= overlap;
        }

        cout<<result<<"\n";
    }
    return 0;
}