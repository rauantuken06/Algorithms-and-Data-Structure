#include <iostream>
using namespace std;

struct DFS{
    static const int N = 101;
    char matrix[N][N];
    int n, m;

    void run(int i, int j){
        if(i < 0 || j < 0 || i >= n || j >= m){
            return;
        }
        if(matrix[i][j] == '0' || matrix[i][j] == '#'){
            return;
        }

        matrix[i][j] = '#';
        run(i + 1, j);
        run(i - 1, j);
        run(i, j + 1);
        run(i, j - 1);
    }
};

int main(){
    DFS search_tipo;

    cin >> search_tipo.n >> search_tipo.m;
    for(int i = 0; i < search_tipo.n; i++){
        for(int j = 0; j < search_tipo.m; j++){
            cin >> search_tipo.matrix[i][j];
        }
    }

    int counter = 0;
    for(int i = 0; i < search_tipo.n; i++){
        for(int j = 0; j < search_tipo.m; j++){
            if(search_tipo.matrix[i][j] == '1'){
                counter++;
                search_tipo.run(i, j);
            }
        }
    }

    cout << counter << "\n";

    return 0;
}