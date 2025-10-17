#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> matrix(n, vector<int>(m));
    vector<int>lool;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>matrix[i][j];
        }
    }

    for(int j=0; j<m; j++){
        for(int i=0; i<n; i++){
            lool.push_back(matrix[i][j]);
        }
        sort(lool.begin(), lool.end(), greater<int>());

        for(int i=0; i<n; i++){
            matrix[i][j]=lool[i];
        }
        lool.clear();
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}