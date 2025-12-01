#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;

int main(){
    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }

    vector<int> dist(n, INF);
    vector<bool> visited(n, false);

    dist[0] = 0;
    long long total = 0;

    for(int it = 0; it < n; it++){
        int v = -1;
        for(int i = 0; i < n; i++){
            if(!visited[i] && (v == -1 || dist[i] < dist[v])){
                v = i;
            }
        }

        visited[v] = true;
        total += dist[v];

        for(int u = 0; u < n; u++){
            if(!visited[u] && arr[v][u] < dist[u]){
                dist[u] = arr[v][u];
            }
        }
    }

    cout << total << "\n";

    return 0;
}