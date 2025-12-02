#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> p, r;
    DSU(int n) : p(n+1), r(n+1, 0) {
        iota(p.begin(), p.end(), 0);
    }
    int find(int v) {
        if (p[v] == v) return v;
        return p[v] = find(p[v]);
    }
    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (r[a] < r[b]) swap(a, b);
        p[b] = a;
        if (r[a] == r[b]) r[a]++;
        return true;
    }
};

int main() {
    int n;
    cin >> n;

    vector<long long> x(n+1), y(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> x[i] >> y[i];
    }

    if (n == 1) {
        cout << 0 << '\n';
        return 0;
    }

    struct Edge {
        long long w;
        int a, b;
    };
    vector<Edge> edges;
    edges.reserve(1LL * n * (n - 1) / 2);

    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            long long dx = llabs(x[i] - x[j]);
            long long dy = llabs(y[i] - y[j]);
            long long w = dx + dy;
            edges.push_back({w, i, j});
        }
    }

    sort(edges.begin(), edges.end(),
         [](const Edge &e1, const Edge &e2) { return e1.w < e2.w; });

    DSU dsu(n);

    for (const auto &e : edges) {
        dsu.unite(e.a, e.b);
        if (dsu.find(1) == dsu.find(n)) {
            cout << e.w << '\n';
            return 0;
        }
    }

    return 0;
}