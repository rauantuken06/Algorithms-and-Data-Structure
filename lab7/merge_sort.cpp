#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right){
    int temp[100];
    int i = left;
    int j = mid + 1;
    int index = 0;

    while(i <= mid && j <= right){
        if(arr[i] < arr[j]){
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

    while(j <= right){
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
    mergeSort(arr, mid + 1, right);

    merge(arr, left, mid, right);
}

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    mergeSort(arr, 0, n - 1);

    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}