#include <iostream>
using namespace std;

const int MAX_N = 200005;
const int MAX_M = 400005;

struct Queue{
    pair<int, int> tipo_queue[MAX_N];
    int queue_left;
    int queue_right;

    Queue(){
        queue_left = 0;
        queue_right = 0;
    }

    void push(int vertex, int distance){
        pair<int, int> for_put = make_pair(vertex, distance);
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
    bool color[MAX_N];
    int head[MAX_N];
    int to[MAX_M];
    int next_idx[MAX_M];
    int edge_counter;
    bool visited[MAX_N];

    Graph(){
        for(int i = 0; i < MAX_N; i++){
            head[i] = 0;
        }
    }

    void add_edge(int u, int v){
        to[edge_counter] = v;
        edge_counter++;
        next_idx[edge_counter] = head[u];
        head[u] = edge_counter;
    }

    void change_color_to_red(int vertex){
        color[vertex] = true;
    }

    int bfs(int start){
        for(int i = 0; i < MAX_N; i++){
            visited[i] = false;
        }

        if(color[start] == true){
            return 0;
        }

        Queue ochered;
        ochered.push(start, 0);
        visited[start] = true;

        while(!ochered.isEmpty()){
            pair<int, int> current = ochered.front();
            ochered.pop();
            int current_node = current.first;
            int current_dist = current.second;

            for(int i = head[current_node]; i != 0; i = next_idx[i]){
                int u = to[i];
                if(visited[u] == false){
                    visited[u] = true;
                    if(color[u] == true){
                        return current_dist + 1;
                    }
                    ochered.push(u, current_dist + 1);
                }
            }
        }
        return -1;
    }
};

int main(){
    int n, m, queries;
    cin >> n >> m >> queries;

    Graph graph;

    for(int i = 0; i < m ; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graph.add_edge(a, b);
    }

    while(queries--){
        int command, vertex;
        cin >> command >> vertex;
        vertex--;
        if(command == 1){
            graph.change_color_to_red(vertex);
        }
        else if(command == 2){
            cout << graph.bfs(vertex) << "\n";
        }
    }

    return 0;
}