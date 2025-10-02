#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long H;
    if (!(cin >> n >> H)) return 0;

    vector<long long>a(n);
    long long mx = 0;
    for (int i=0; i<n; ++i) {
        cin>>a[i];
        mx=max(mx, a[i]);
    }

    auto can = [&](long long k) -> bool {
        long long hours = 0;
        for (long long x : a) {
            hours+=(x+k-1)/k;
            if (hours>H) return false;
        }
        return hours<=H;
    };

    long long L = 1, R = mx, ans = mx;
    while (L <= R) {
        long long mid=(L + R) / 2;
        if (can(mid)) {
            ans=mid;
            R=mid - 1;
        } else {
            L=mid + 1;
        }
    }

    cout<<ans<<"\n";
    return 0;
}