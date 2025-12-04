#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 100;
vector<int> adjacency_list[MAX_N];
bool visited[MAX_N];

void DFS(int v){
    // Mark current vertex as visited.
    visited[v] = true;
    cout << v << " ";

    // Visit all neighbors
    for(int i = 0; i < adjacency_list[v].size(); i++){
        int u = adjacency_list[v][i];
        if(!visited[u]){
            DFS(u);
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        visited[i] = false;
    }

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;

        adjacency_list[u].push_back(v);
        adjacency_list[v].push_back(u);
    }

    cout << "DFS traversal: ";
    DFS(0);
    cout << "\n";

    return 0;
}