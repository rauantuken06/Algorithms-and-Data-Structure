#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n; cin>>n;
    if(n==1){
        return 0;
    }
    vector<char> arr(n);

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    char input_char; cin>>input_char;

    for(int i=0; i<n; i++){
        if(arr[i]>input_char){
            cout<<arr[i];
            return 0;
        }
    }
    
    char for_another_case=arr[0];
    cout<<for_another_case<<"\n";
}