#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void prim_mst(vector<vector<int>> &graph){
    int n = graph.size();
    const int INF = 1e9;

    vector<int> key(n, INF);
    vector<int> parent(n, -1);
    vector<bool> visited(n, false);
    
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > min_heap;

    key[0] = 0;
    min_heap.push({0, 0});

    while(!min_heap.empty()){
        int v = min_heap.top().second;
        min_heap.pop();
        if(visited[v]){
            continue;
        }
        visited[v] = true;

        for(int to = 0; to < n; to++){
            int w = graph[v][to];
            if(w != 0 && !visited[to] && w < key[to]){
                key[to] = w;
                parent[to] = v;
                min_heap.push({key[to], to});
            }
        }
    }

    int mst_cost = 0;
    for(int i = 1; i < n; i++){
        cout << parent[i] << " - " << i << " == " << graph[i][parent[i]] << "\n";
        mst_cost += graph[i][parent[i]];
    }
    cout << "MST cost: " << mst_cost << "\n";
}

int main(){
    vector<vector<int>> graph = {{0, 2, 0, 6, 0},
                                 {2, 0, 3, 8, 5},
                                 {0, 3, 0, 0, 7},
                                 {6, 8, 0, 0, 9},
                                 {0, 5, 7, 9, 0}};

    prim_mst(graph);

    return 0;
}