#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right){
    int i = left;
    int j = mid+1;
    int temp[1000];
    int index=0;

    while(i <= mid && j <= right){
        if(arr[i] <= arr[j]){
            temp[index] = arr[i];
            i++;
            index++;
        }
        else{
            temp[index] = arr[j];
            j++;
            index++;
        }
    }

    while(i <= mid){
        temp[index] = arr[i];
        i++;
        index++;
    }
    
    while(j<=right){
        temp[index] = arr[j];
        j++;
        index++;
    }

    for(int p = 0; p < index; p++){
        arr[left + p] = temp[p];
    }
}

void mergeSort(int arr[], int left, int right){
    if(left >= right){
        return;
    }

    int mid = (left + right) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid+1, right);

    merge(arr, left, mid, right);
}

int main(){
    int n, m;
    cin>>n>>m;

    int arr1[n], arr2[m];

    for(int i = 0; i < n; i++){
        cin>>arr1[i];
    }

    for(int i = 0; i < m; i++){
        cin>>arr2[i];
    }

    mergeSort(arr1, 0, n-1);
    mergeSort(arr2, 0, m-1);

    int i = 0;
    int j = 0;
    while(i < n && j < m){
        if(arr1[i] == arr2[j]){
            cout<<arr1[i]<<" ";
            i++;
            j++;
        }
        else if(arr1[i] < arr2[j]){
            i++;
        }
        else{
            j++;
        }
    }

    return 0;
}