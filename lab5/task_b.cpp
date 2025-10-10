#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    priority_queue<int> arr;
    for(int i=0; i<n; i++){
        int num;
        cin>>num;
        arr.push(num);
    }

    while(arr.size()>1){
        int L=arr.top();arr.pop();
        int R=arr.top();arr.pop();
        if(L!=R){
            int new_rock=L-R;
            arr.push(new_rock);
        }
    }
    
    if(!arr.empty()){
        cout<<arr.top()<<"\n";
    }
    else{
        cout<<0<<"\n";
    }

    return 0;
    
}