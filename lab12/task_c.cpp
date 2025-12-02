#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<bool>> air(n + 1, vector<bool>(n + 1, false));

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        air[u][v] = air[v][u] = true;
    }

    auto bfs_air = [&](int start) {
        vector<int> dist(n + 1, -1);
        queue<int> q;
        dist[start] = 0;
        q.push(start);

        while (!q.empty()) {
            int v = q.front();
            q.pop();

            for (int to = 1; to <= n; ++to) {
                if (to == v) continue;
                if (air[v][to] && dist[to] == -1) {
                    dist[to] = dist[v] + 1;
                    q.push(to);
                }
            }
        }
        return dist;
    };

    auto bfs_road = [&](int start) {
        vector<int> dist(n + 1, -1);
        queue<int> q;
        dist[start] = 0;
        q.push(start);

        while (!q.empty()) {
            int v = q.front();
            q.pop();

            for (int to = 1; to <= n; ++to) {
                if (to == v) continue;
                if (!air[v][to] && dist[to] == -1) {
                    dist[to] = dist[v] + 1;
                    q.push(to);
                }
            }
        }
        return dist;
    };

    auto distAir = bfs_air(1);
    auto distRoad = bfs_road(1);

    int dAir = distAir[n];
    int dRoad = distRoad[n];

    if (dAir == -1 || dRoad == -1) {
        cout << -1 << "\n";
    } else {
        cout << max(dAir, dRoad) << "\n";
    }

    return 0;
}