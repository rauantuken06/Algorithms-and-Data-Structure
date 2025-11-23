#include <iostream>
using namespace std;

const int MAX_N = 501;

struct Graph{
    int to[MAX_N * MAX_N];
    int next[MAX_N * MAX_N];
    int head[MAX_N];
    int edge_count;

    Graph(){
        for(int i = 0; i < MAX_N; i++){
            head[i] = -1;
        }
        edge_count = 0;
    }

    void add_edge(int u, int v){
        to[edge_count] = v;
        next[edge_count] = head[u];
        head[u] = edge_count;
        edge_count++;
    }
};

int states[MAX_N];
Graph graph;

bool detect_cycle(int v, int edge_u, int edge_v){
    states[v] = 1;

    for(int e = graph.head[v]; e != -1; e = graph.next[e]){
        int to = graph.to[e];

        if(v == edge_u && to == edge_v){
            continue;
        }

        if(states[to] == 0){
            if(detect_cycle(to, edge_u, edge_v)){
                return true;
            }
        }
        else if (states[to] == 1){
            return true;
        }
    }

    states[v] = 2;
    return false;
}

int main(){
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        graph.add_edge(u, v);
    }

    for(int u = 0; u < n; u++){
        for(int e = graph.head[u]; e != -1; e = graph.next[e]){
            int v = graph.to[e];

            for(int i = 0; i < n; i++){
                states[i] = 0;
            }

            bool has_cycle = false;

            for(int k = 0; k < n; k++){
                if(states[k] == 0){
                    if(detect_cycle(k, u, v)){
                        has_cycle = true;
                        break;
                    }
                }
            }

            if(!has_cycle){
                cout << "YES" << "\n";
                return 0;
            }
        }
    }

    cout << "NO" << "\n";
    return 0;
}