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
}