#include <iostream>
#include <vector>
using namespace std;

struct DSU{
    int n;
    vector<int> parent;
    vector<int> rnk;

    DSU(int n) : n(n), parent(n + 1), rnk(n + 1, 0){
        for(int i = 1; i <= n; i++){
            parent[i] = i;
        }
    }

    int find_set(int v){
        if(parent[v] == v){
            return v;
        }
        return parent[v] = find_set(parent[v]);
    }

    bool union_set(int a, int b){
        a = find_set(a);
        b = find_set(b);
        if(a == b){
            return false;
        }
        if(rnk[a] < rnk[b]){
            swap(a, b);
        }
        parent[b] = a;
        if(rnk[a] == rnk[b]){
            rnk[a]++;
        }
        return true;
    }
};

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    DSU dsu(n);
    vector<long long> ans(n + 2, 0);
    vector<bool> active(n + 1, false);

    long long cnt = 0;

    for(int i = n; i >= 1; i--){
        active[i] = true;
        cnt++;
        for(int v : graph[i]){
            if(active[v]){
                if(dsu.union_set(i, v)){
                    cnt--;
                }
            }
        }

        ans[i] = cnt;
    }

    for(int k = 1; k <= n; k++){
        if(k == n){
            cout << 0 << "\n";
        }
        else{
            cout << ans[k + 1] << "\n";
        }
    }

    return 0;
}