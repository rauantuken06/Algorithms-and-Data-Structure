#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> dijkstra(vector<vector<pair<int, int>>>& adj, int source){
    int size = adj.size();
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > min_heap;

    vector<int> distance(size, INT16_MAX);
    min_heap.emplace(0, source);

    distance[source] = 0;
    while(!min_heap.empty()){
        auto top = min_heap.top();
        min_heap.pop();

        int d = top.first;
        int u = top.second;

        if(d > distance[u]){
            continue;
        }

        for(auto &e : adj[u]){
            int v = e.first;
            int w = e.second;
            if(distance[u] + w < distance[v]){
                distance[v] = distance[u] + w;
                min_heap.emplace(distance[v], v);
            }
        }
    }

    return distance;
}

int main(){
    int src = 0;
    vector<vector<pair<int, int>>> adj(4);
    adj[0] = { {1, 1}, {3, 5} };
    adj[1] = { {0, 1}, {3, 3}, {2, 9} };
    adj[2] = { {1, 9}, {3, 4} };
    adj[3] = { {0, 5}, {2, 4} , {1, 3} };

    vector<int> result = dijkstra(adj, src);

    for (int d : result) {
        cout << d << " ";
    }

    return 0;
}