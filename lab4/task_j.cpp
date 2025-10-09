#include <bits/stdc++.h>
using namespace std;

vector<int>a;
vector<int>out;

void build(int l, int r){
    if(l>r) return;
    int mid=(l+r)/2;
    out.push_back(a[mid]);
    build(l, mid-1);
    build(mid+1, r);
}

int main(){
    int n;
    cin>>n;
    int m=(1<<n)-1;
    a.resize(m);

    for(int i=0; i<m; i++){
        cin>>a[i];
    }

    sort(a.begin(), a.end());
    build(0, m-1);

    for(int i=0; i<m; i++){
        if(i){
            cout<<' ';
        }
        cout<<out[i];
    }
    cout<<"\n";

    return 0;
}