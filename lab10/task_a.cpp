#include <iostream>
using namespace std;

const int MAX_N = 1005;

int matrix[MAX_N][MAX_N];
pair<int, int> marios[MAX_N * MAX_N];
int marios_Counter;

pair<int, int> tipo_queue[MAX_N * MAX_N];
int queue_left, queue_right;

int direction_x[4] = {-1, 1, 0, 0};
int direction_y[4] = {0, 0, -1, 1};

int n, m;
int mushrooms;

bool isInside(int x, int y){
    return x >= 0 && y >= 0 && x < n && y < m; 
}

void init_queue(){
    queue_left = 0;
    queue_right = 0;

    for(int i = 0; i < marios_Counter; i++){
        tipo_queue[queue_right] = marios[i];
        queue_right++;
    }
}

void crush_Layer(){
    int layer_size = queue_right - queue_left;
    for(int s = 0; s < layer_size; s++){
        pair<int, int> current = tipo_queue[queue_left];
        queue_left++;
        int x = current.first;
        int y = current.second;

        for(int d = 0; d < 4; d++){
            int new_x = x + direction_x[d];
            int new_y = y + direction_y[d];

            if(!isInside(new_x, new_y)){
                continue;
            }

            if(matrix[new_x][new_y] == 1){
                matrix[new_x][new_y] = 2;
                mushrooms--;
                tipo_queue[queue_right] = make_pair(new_x, new_y);
                queue_right++;
            }
        }
    }
}

int bfs(){
    if(mushrooms == 0){
        return 0;
    }

    int minutes = 0;
    while(queue_left < queue_right){
        if(mushrooms == 0){
            break;
        }

        crush_Layer();
        minutes++;
    }

    if(mushrooms != 0){
        return -1;
    }
    else{
        return minutes;
    }
}

int main(){
    cin >> n >> m;
    mushrooms = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> matrix[i][j];

            if(matrix[i][j] == 2){
                marios[marios_Counter] = make_pair(i, j);
                marios_Counter++;
            }
            if(matrix[i][j] == 1){
                mushrooms++;
            }
        }
    }

    init_queue();
    cout << bfs() << "\n";

    return 0;
}