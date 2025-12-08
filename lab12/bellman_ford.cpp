#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> bellman_ford(int V, vector<vector<int>>& edges, int source){
    vector<int>distance(V, INT_MAX);
    distance[source] = 0;

    for(int i = 0; i < V - 1; i++){
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            if(distance[u] != INT_MAX && distance[u] + w < distance[v]){
                distance[v] = distance[u] + w;
            }
        }
    }

    for(auto &edge : edges){
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];

        if(distance[u] != INT_MAX && distance[u] + w < distance[v]){
            return {-1};
        }
    }

    return distance;
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

    int source = 0;
    
    vector<int> short_paths = bellman_ford(n, edges, source);
    for(int a : short_paths){
        cout << a << " ";
    }

    return 0;
}