#include <iostream>
#include <stack>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    stack<int>lool;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    for(int i=0; i<n; i++){
        int a=arr[i];
        while(!lool.empty() && lool.top()>a){
            lool.pop();
        }
        if(lool.empty()){
            cout<<-1;
        }
        else{
            cout<<lool.top();
        }
        cout<<" ";
        lool.push(a);
    }
    return 0;
}