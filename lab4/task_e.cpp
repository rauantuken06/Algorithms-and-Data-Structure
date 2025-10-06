#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x, y, z;
    vector<int> tree[1010];
    int lvl[1010], mx=INT_MIN;

    cin>>n;

    for(int i=0; i<n-1; i++){
        cin>>x>>y>>z;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }

    memset(lvl, -1, sizeof(lvl));
    lvl[1]=0;
    queue<int> qoo;
    map<int, int> loool;
    qoo.push(1);

    while(!qoo.empty()){
        int c=qoo.front();
        qoo.pop();
        for(auto lol:tree[c]){
            if(lvl[lol]==-1){
                qoo.push(lol);
                lvl[lol]=lvl[c]+1;
            }
        }
    }

    for(int i=0; i<n; i++){
        loool[lvl[i]]++;
        mx=max(mx, loool[lvl[i]]);
    }

    cout<<mx;
}