#include <iostream>
using namespace std;

void merge(string arr[], int left, int mid, int right){
    int i=left;
    int j=mid+1;
    string temp[1000];
    int k=0;

    while(i<=mid && j<=right){
        if(arr[i].size()<=arr[j].size()){
            temp[k]=arr[i];
            i++;
            k++;
        }
        else{
            temp[k]=arr[j];
            j++;
            k++;
        }
    }

    while(i<=mid){
        temp[k]=arr[i];
        i++;
        k++;
    }

    while(j<=right){
        temp[k]=arr[j];
        j++;
        k++;
    }

    for(int p=0; p<k; p++){
        arr[left+p]=temp[p];
    }
}

void mergeSort(string arr[], int left, int right){
    if(left>=right){
        return;
    }

    int mid=(left+right)/2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid+1, right);

    merge(arr, left, mid, right);

}

int main(){
    int k;
    cin>>k;
    cin.ignore();

    while(k--){
        string lol;
        getline(cin, lol);

        string words[1000];
        string word="";
        int counter=0;

        for(int i=0; i<lol.size(); i++){
            if(lol[i]==' '){
                words[counter]=word;
                word="";
                counter++;
            }
            else{
                word+=lol[i];
            }
        }
        if(word!=""){
            words[counter]=word;
            counter++;
        }

        mergeSort(words, 0, counter-1);
        for(int i=0; i<counter; i++){
           cout<<words[i]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}