#include <iostream>
using namespace std;

int binarySearchIncreasing(int arr[], int left, int right, int target){
    while(left<=right){
        int mid=left+(right-left)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]>target){
            right=mid-1;
        }
        else{
            left=mid+1;
        }
    }
    return -1;
}

int binarySearchDicreasing(int arr[], int left, int right, int target){
    while(left<=right){
        int mid=left+(right-left)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]<target){
            right=mid-1;
        }
        else{
            left=mid+1;
        }
    }
    return -1;
}

int main(){
    int k;
    cin>>k;
    int queries[k];

    for(int i=0; i<k; i++){
        cin>>queries[i];
    }

    int n, m;
    cin>>n>>m;
    int arr[n][m];

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }

    for(int l=0; l<k; l++){
        int target=queries[l];
        int result;
        bool isThere=false;
        for(int i=0; i<n; i++){
            if(i%2==1){
                result=binarySearchIncreasing(arr[i], 0, m-1, target);
            }
            else{
                result=binarySearchDicreasing(arr[i], 0, m-1, target);
            }

            if(result!=-1){
                cout<<i<<" "<<result<<"\n";
                isThere=true;
            }
        }
    }

    return 0;
}