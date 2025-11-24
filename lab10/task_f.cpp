#include <iostream>
using namespace std;

const int MAX_N = 100005;
const int MAX_M = 200005;

struct Queue{
    pair<int, int> tipo_queue[MAX_N];
    int queue_left;
    int queue_right;

    Queue(){
        queue_left = 0;
        queue_right = 0;
    }

    void push(int node, int distance){
        pair<int, int> for_put = make_pair(node, distance);
        tipo_queue[queue_right] = for_put;
        queue_right++;
    }

    pair<int, int> front(){
        return tipo_queue[queue_left];
    }

    void pop(){
        queue_left++;
    }

    bool isEmpty(){
        return queue_left == queue_right;
    }
};

struct Graph{
    int head[MAX_N];
    int to[MAX_M];
    int nextik[MAX_M];
    int edge_counter;

    bool visited[MAX_N];

    Graph(){
        edge_counter = 0;
        for(int i = 0; i < MAX_N; i++){
            visited[i] = false;
        }
    }

    void add_edges(int u, int v){
        ++edge_counter;
        to[edge_counter] = v;
        nextik[edge_counter] = head[u];
        head[u] = edge_counter;
    }

    bool bfs(int from, int to){
        Queue ochered;
        ochered.push(from, 0);
        visited[from] = true;

        while(!ochered.isEmpty()){
            pair<int, int> current = ochered.front();
            ochered.pop();
            int current_node = current.first;
            int current_distance = current.second;

            if(current_node == to){
                return true;
            }

            for(int i = head[current_node]; i != 0; i = nextik[i]){
                int u = this->to[i];
                if(visited[u] == false){
                    ochered.push(u, current_distance + 1);
                    visited[u] = true;
                }
            }
        }
        return false;
    }
};

int main(){
    int n, m;
    cin >> n >> m;

    Graph graph;
    for(int i = 0; i < m; i++){
        int vertex1, vertex2;
        cin >> vertex1 >> vertex2;
        graph.add_edges(vertex1, vertex2);
        graph.add_edges(vertex2, vertex1);
    }

    int from, to;
    cin >> from >> to;

    if(graph.bfs(from, to)){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }

    return 0;
}