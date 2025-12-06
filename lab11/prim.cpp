#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n);

    for(int i = 0; i < m; i++){
        int x, y, w;
        cin >> x >> y >> w;
        x--;
        y--;

        graph[x].push_back({y, w});
        graph[y].push_back({x, w});
    }

    const int INF = 1e9;
    vector<int> key(n, INF);
    vector<int> parent(n, -1);
    vector<int> used(n, 0);

    key[0] = 0;
    for(int i = 0;i < n; i++){
        int v = -1;
        for(int j = 0; j < n; j++){
            if(!used[j] && (v == -1 || key[j] < key[v])){
                v = j;
            }
        }
        used[v] = 1;
        for(auto &edge : graph[v]){
            int to = edge.first;
            int w = edge.second;
            if(!used[to] && w < key[to]){
                key[to] = w;
                parent[to] = v;
            }
        }
    }

    int mst_cost = 0;
    for(int w : key){
        mst_cost += w;
    }

    cout << "MST cost: " << mst_cost << "\nEdges:\n";
    for(int v = 1; v < n; v++){
        cout << parent[v] + 1 << " - " << v + 1 << "(" << key[v] << ")\n"; 
    }

    return 0;
}