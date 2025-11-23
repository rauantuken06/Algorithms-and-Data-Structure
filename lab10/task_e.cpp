#include <iostream>
using namespace std;

int main(){
    int n, queries;
    cin >> n >> queries;

    int matrix[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> matrix[i][j];
        }
    }

    while(queries--){
        int vertex1, vertex2, vertex3;
        cin >> vertex1 >> vertex2 >> vertex3;
        vertex1--;
        vertex2--;
        vertex3--;
        
        if(matrix[vertex1][vertex2] == 1 && matrix[vertex1][vertex3] == 1 && matrix[vertex2][vertex3] == 1){
            cout << "YES" << "\n";
        }
        else{
            cout << "NO" << "\n";
        }
    }

    return 0;
}