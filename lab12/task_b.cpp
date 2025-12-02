#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = (ll)4e18;

int n, m;
vector<vector<pair<int, int>>> g;

vector<ll> dijkstra(int start) {
    vector<ll> dist(n + 1, INF);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [d, v] = pq.top();
        pq.pop();
        if (d != dist[v]) continue;

        for (auto [to, w] : g[v]) {
            if (dist[to] > dist[v] + w) {
                dist[to] = dist[v] + w;
                pq.push({dist[to], to});
            }
        }
    }
    return dist;
}

int main() {
    cin >> n >> m;
    g.assign(n + 1, {});

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    int s, merch, pharm, grand;
    cin >> s >> merch >> pharm >> grand;

    auto distS = dijkstra(s);
    auto distM = dijkstra(merch);
    auto distP = dijkstra(pharm);

    ll ans = INF;

    if (distS[merch] < INF && distM[pharm] < INF && distP[grand] < INF) {
        ans = min(ans, distS[merch] + distM[pharm] + distP[grand]);
    }

    if (distS[pharm] < INF && distP[merch] < INF && distM[grand] < INF) {
        ans = min(ans, distS[pharm] + distP[merch] + distM[grand]);
    }

    if (ans >= INF) {
        cout << -1 << "\n";
    } else {
        cout << ans << "\n";
    }

    return 0;
}