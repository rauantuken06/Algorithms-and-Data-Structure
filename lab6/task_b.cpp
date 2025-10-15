#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, k; cin>>n>>k;
    vector<int>arr1(n);
    vector<int>arr2(k);
    vector<int>result;

    for(int i=0; i<n; i++){
        cin>>arr1[i];
    }
    for(int i=0; i<k; i++){
        cin>>arr2[i];
    }

    for(int i=0; i<arr1.size(); i++){
        for(int j=0; j<arr2.size(); j++){
            if(arr2[j]==arr1[i]){
                result.push_back(arr1[i]);
                arr1.erase(arr1.begin()+i);
                arr2.erase(arr2.begin()+j);

                i--;
                j--;
            }
        }
    }

    sort(result.begin(), result.end());

    for(int c:result){
        cout<<c<<' ';
    }

    return 0;
}