#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> createGraph(int V, vector<vector<int>> &edges){
    vector<vector<int>> adjacency(V);

    for(auto &it : edges){
        int u = it[0];
        int v = it[1];

        adjacency[u].push_back(v);
        adjacency[v].push_back(u);
    }
    return adjacency;
}

int main(){
    int vertexes;
    cin >> vertexes;

    int edges;
    cin >> edges;

    vector<vector<int>> edges_list;
    for(int i = 0; i < edges; i++){
        int u, v;
        cin >> u >> v;
        edges_list.push_back({u, v});
    }

    vector<vector<int>> adjacency_list = createGraph(vertexes, edges_list);
    cout << "Adjacency List: " << "\n";
    for(int i = 0; i < vertexes; i++){
        cout << i << ": ";
        for(int j : adjacency_list[i]){
            cout << j << " ";
        }
        cout << "\n";
    }

    return 0;
}