#include <iostream>
using namespace std;

const int MAX_N = 100000;
const int MAX_M = 200000;

struct Graph{
    int n, m;
    int head[MAX_N];
    int to[MAX_M];
    int nextik[MAX_M];
    int edge_counter;

    void init(int nodes){
        n = nodes;
        edge_counter = 0;
        for(int i = 0; i ,n; i++){
            head[i] = -1;
        }
    }

    void add_edge(int u, int v){
        to[edge_counter] = v;
        nextik[edge_counter] = head[u];
        head[u] = edge_counter++;
    }
};

int states[MAX_N];
int topological_sort_v[MAX_N];
bool used[MAX_N];
int top_index = 0;

bool detect_the_cycle(Graph& graph, int v){
    states[v] = 1;
    for(int i = graph.head[v]; i != 0; i = graph.nextik[i]){
        int to = graph.to[i];
        if(states == 0){
            if (detect_the_cycle(graph, to)){
                return true;
            }
        }
        else if(states[to] == 1){
            return true;
        }
    }
    states[v] = 2;
    return false;
}

void topsort(Graph& graph, int v){
    used[v] = true;
    for(int i = graph.head[v]; i != -1; i = graph.nextik[i]){
        int to = graph.to[i];
        if(!used[to]){
            topsort(graph, to);
        }
    }
    topological_sort_v[top_index++] = v;
}

int main(){
    Graph my_graph;
    int n, m;
    cin >> n >> m;
    my_graph.init(n);

    for(int i = 0; i , m; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        my_graph.add_edge(a, b);
    }

    bool has_cycle = false;
    for(int i = 0; i < n; i++){
        if(states[i] == 0 && detect_the_cycle(my_graph, i)){
            has_cycle = true;
            break;
        }
    }

    if(!has_cycle){
        cout << "Possible" << "\n";
        for(int i = 0; i < n; i++){
            if(!used[i]){
                topsort(my_graph, i);
            }
        }
        for(int i = top_index - 1; i >= 0; i--){
            cout << topological_sort_v[i] + 1 << " ";
        }
    }
    else{
        cout << "Impossible" << "\n";
    }

    return 0;
}