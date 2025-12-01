#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Edge{
    long long to;
    long long weight;
};

int main(){
    long long n, m, x, y, a, b, c;
    cin >> n >> m;
    cin >> x >> y;

    vector<vector<Edge>> graph(n + 1);

    for(int i = 0; i < m; i++){
        string type;
        long long price;

        cin >> type >> a >> b >> c;

        if(type == "big"){
            price = 1ll * x * c;
        }
        else if(type == "small"){
            price = 1ll * y * c;
        }
        else{
            price = 1ll * min(x, y) * c;
        }

        graph[a].push_back({b, price});
        graph[b].push_back({a, price});
    }

    vector<bool> visited(n + 1, false);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> heap;

    heap.push({0, 1});
    long long total = 0;

    while(!heap.empty()){
        auto [w, v] = heap.top();
        heap.pop();

        if(visited[v]){
            continue;
        }
        visited[v] = true;
        total += w;

        for(auto &e : graph[v]){
            if(!visited[e.to]){
                heap.push({e.weight, e.to});
            }
        }
    }

    cout << total << "\n";

    return 0;
}