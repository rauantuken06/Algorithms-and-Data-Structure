#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin>>n>>k;
    vector<int>need;

    for(int i=0;i<n;i++){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        need.push_back(max(x2,y2));
    }

    sort(need.begin(), need.end());

    cout<<need[k-1]<<"\n";
    return 0;
}