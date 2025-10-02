#include <iostream>
#include <map>
using namespace std;

int main(){
    int l;
    cin>>l;
    int search_arr[l];

    int n, m;
    cin>>n>>m;
    map<int, pair<int, int>>lol;
    for(int i=0; i<l; i++){
        cin>>search_arr[i];
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int numberlol;
            cin>>numberlol;
            lol[numberlol]={i, j};
        }
    }

    for(int i=0; i<l; i++){
        if(lol.count(search_arr[i])){
            cout<<lol[search_arr[i]].first<<" "
            <<lol[search_arr[i]].second<<"\n";
        }
        else{
            cout<<-1<<"\n";
        }
    }
}