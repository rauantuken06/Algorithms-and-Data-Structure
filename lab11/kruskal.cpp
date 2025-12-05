#include <bits/stdc++.h>
using namespace std;

struct DSU{
    vector<int> parent;
    vector<int> rank;
    DSU(int n) : parent(n), rank(n, 0){
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int v){
        if(parent[v] == v){
            return v;
        }
        return parent[v] = find(parent[v]);
    }

    bool unite(int a, int b){
        a = find(a);
        b = find(b);

        if(a == b){
            return false;
        }
        if(rank[a] < rank[b]){
            swap(a, b);
        }
        parent[b] = a;
        if(rank[a] == rank[b]){
            rank[a]++;
        }
        return true;
    }
};

struct Edge{
    int u, v, w;
    bool operator<(const Edge& other) const {return w < other.w;}
};

int main(){
    int n, m;
    cin >> n >> m;
    vector<Edge> edges;
    edges.reserve(n);

    for(int i = 0; i < m; i++){
        int x, y, w;
        cin >> x >> y >> w;
        edges.push_back({x - 1, y - 1, w});
    }

    sort(edges.begin(), edges.end());
    vector<Edge> mst;
    int mst_cost = 0;
    DSU dsu(n);

    for(auto &e : edges){
        if(dsu.unite(e.u, e.v)){
            mst.push_back(e);
            mst_cost += e.w;
        }
        if((int)mst.size() == n - 1){
            break;
        }
    }

    cout << "MST cost: "<< mst_cost << "\nEdges:\n";
    for(auto e : mst){
        cout << e.u + 1 << " - " << e.v + 1 << "(" << e.w << ")\n";
    }

    return 0;
}