#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct DSU{
    vector<int> parent;
    vector<int> rank;
    DSU(int n){
        parent.resize(n);
        rank.resize(n);
        for(int i = 0; i < n; i++){
            parent[i] = i;
            rank[i] = 1;
        }
    }

    int find(int v){
        if(parent[v] == v){
            return v;
        }
        return parent[v] = find(parent[v]);
    }

    void unite(int x, int y){
        int s1 = find(x);
        int s2 = find(y);
        if(s1 == s2){
            return;
        }

        if(rank[s1] < rank[s2]){
            parent[s1] = s2;
        }
        else if(rank[s1] > rank[s2]){
            parent[s2] = s1;
        }
        else{
            parent[s2] = s1;
            rank[s1]++;
        }
    }
};

bool comparator(vector<int>& a, vector<int>& b){
    return a[2] < b[2];
}

int kruskal(int V, vector<vector<int>>& edges, vector<vector<int>>& mst_edges){
    sort(edges.begin(), edges.end(), comparator);

    DSU dsu(V);
    int cost = 0;
    int counter = 0;
    for(auto &e : edges){
        int x = e[0], y = e[1], w = e[2];
        if(dsu.find(x) != dsu.find(y)){
            dsu.unite(x, y);
            mst_edges.push_back(e);
            cost += w;
            if(++counter == V - 1){
                break;
            }
        }
    }
    return cost;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges;

    for(int i = 0; i < m; i++){
        int x, y, w;
        cin >> x >> y >> w;
        x--;
        y--;

        edges.push_back({x, y, w});
    }

    vector<vector<int>> edges_of_mst;
    int mst_cost = kruskal(n, edges, edges_of_mst);
    
    cout << "MST cost: " << mst_cost << "\nEdges:\n";
    for(auto &e : edges_of_mst){
        cout << e[0] + 1 << " - " << e[1] + 1 << " == " << e[2] << "\n";
    }

    return 0;
}