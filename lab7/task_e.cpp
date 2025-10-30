#include <iostream>
using namespace std;

const int max_n = 1000;
const int max_m = 1000;

int matrix[max_n][max_m + 1];
int temp_matrix[max_n][max_m + 1];

bool compare_rows(int row1[], int row2[], int m){
    if(row1[m] != row2[m]){
        return row1[m] > row2[m];
    }

    for(int i = 0; i < m; i++){
        if(row1[i] != row2[i]){
            return row1[i] < row2[i];
        }
    }

    return false;

}

void merge(int matrix[][max_m + 1], int left, int mid, int right, int n, int m){
    int i = left;
    int j = mid + 1;
    int k = 0;

    while(i <= mid && j <= right){
        if(compare_rows(matrix[i], matrix[j], m)){
            for(int col = 0; col <= m; col++){
                temp_matrix[k][col] = matrix[i][col];
            }
            i++;
            k++;
        }
        else{
            for(int col = 0; col <= m; col++){
                temp_matrix[k][col] = matrix[j][col];
            }
            j++;
            k++;
        }
    }

    while(i <= mid){
        for(int col = 0; col <= m; col++){
            temp_matrix[k][col] = matrix[i][col];
        }
        i++;
        k++;
    }

    while(j <= right){
        for(int col = 0; col <= m; col++){
            temp_matrix[k][col] = matrix[j][col];
        }
        j++;
        k++;
    }

    for(int p = 0; p < k; p++){
        for(int col = 0; col <= m; col++){
            matrix[left + p][col] = temp_matrix[p][col];
        }
    }
}

void mergeSort(int matrix[][max_m + 1], int left, int right, int n, int m){
    if(left >= right){
        return;
    }

    int mid = (right + left) / 2;
    mergeSort(matrix, left, mid, n, m);
    mergeSort(matrix, mid + 1, right, n, m);

    merge(matrix, left, mid, right, n, m);
}

int main(){
    int n, m;
    cin>>n>>m;

    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = 0; j < m; j++){
            cin>>matrix[i][j];
            sum+=matrix[i][j];
        }
        matrix[i][m] = sum;
    }

    mergeSort(matrix, 0, n - 1, n, m);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}