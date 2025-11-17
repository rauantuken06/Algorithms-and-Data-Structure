#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> createGraph(int V, vector<vector<int>> &edges){
    vector<vector<int>> matrix(V, vector<int> (V, 0));

    for(auto &it : edges){
        int u = it[0];
        int v = it[1];

        matrix[u][v] = 1;
        matrix[v][u] = 1;
    }
    return matrix;
}

int main(){
    int V;
    cin >> V;

    int E;
    cin >> E;

    vector<vector<int>> edges;
    for(int i = 0; i < E; i++){
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    vector<vector<int>> matrix = createGraph(V, edges);
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}