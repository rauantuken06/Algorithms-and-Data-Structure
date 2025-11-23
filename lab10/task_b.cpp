#include <iostream>
using namespace std;

const int MAX_N = 105;
int matrix[MAX_N][MAX_N];
bool visited[MAX_N];

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

int minimal_distance(int from, int to, int n){
    for(int i = 0; i < MAX_N; i++){
        visited[i] = false;
    }

    Queue ochered;
    ochered.push(from, 0);
    visited[from] = true;

    while(!ochered.isEmpty()){
        pair<int, int> current = ochered.front();
        ochered.pop();
        int node = current.first;
        int total_distance = current.second;

        if(node == to){
            return total_distance;
        }

        for(int i = 0; i < n; i++){
            if(matrix[node][i] == 1 && visited[i] == false){
                visited[i] = true;
                ochered.push(i, total_distance + 1);
            }
        }
    }
    return -1;
}

int main(){
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> matrix[i][j];
        }
    }

    int from, to;
    cin  >> from >> to;
    from--;
    to--;

    cout << minimal_distance(from, to, n) << "\n";

    return 0;
}