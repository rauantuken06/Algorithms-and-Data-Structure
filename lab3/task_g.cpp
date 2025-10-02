#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long k;
    cin >> n >> k;

    vector<long long> a(n);
    long long mx = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    auto ok = [&](long long C) -> bool {
        long long flights = 0;
        for (long long x : a) {
            flights += (x + C - 1) / C;
            if (flights > k) return false;
        }
        return flights <= k;
    };

    long long left = 1, right = mx, ans = mx;
    while (left <= right) {
        long long mid = (left + right) / 2;
        if (ok(mid)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << ans << "\n";
    return 0;
}