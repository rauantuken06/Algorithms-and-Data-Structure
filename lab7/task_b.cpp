#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin>>n;

    vector<int> array1(n);
    for(int i=0; i<n; i++){
        cin>>array1[i];
    }
    
    cin>>m;
    vector<int> array2(m);
    for(int i=0; i<m; i++){
        cin>>array2[i];
    }

    vector<int> result(n+m);

    sort(array1.begin(), array1.end());
    sort(array2.begin(), array2.end());

    merge(array1.begin(), array1.end(), array2.begin(), array2.end(), result.begin());

    for(int val:result){
        cout<<val<<" ";
    }

    return 0;
}