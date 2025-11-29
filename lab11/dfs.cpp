#include <iostream>
#include <vector>
using namespace std;

void dfsRec(vector<vector<int>> &adj, vector<bool> &visited, int s, vector<int> &res){
    visited[s] = true;

    res.push_back(s);

    //Recursively visit all adjacent vertices that are not visited yet

    for(int i : adj[s]){
        if(visited[i] == false){
            dfsRec(adj, visited, i, res);
        }
    }
}

vector<int> DFS(vector<vector<int>> &adj){
    vector<bool> visited(adj.size(), false);
    vector<int> res;
    dfsRec(adj, visited, 0, res);
    return res;
}