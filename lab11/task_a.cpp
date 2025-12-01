#include <iostream>
#include <queue>
using namespace std;

int main(){
    int n, m, l, r, c;
    long long answer = 0;

    cin >> n >> m;
    vector<pair<int, int>> st[n + 5], fn[n + 5];

    for(int i = 1; i <= m; i++){
        cin >> l >> r >> c;
        st[l].push_back({r, c});
        fn[r].push_back({l, c});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;

    for(int i = 1; i < n; i++){
        for(auto p : st[i]){
            min_heap.push({p.second, p.first});
        }
        while(!min_heap.empty() && min_heap.top().second <= i){
            min_heap.pop();
        }

        if(min_heap.empty()){
            cout << "0\n";
            return 0;
        }

        answer += min_heap.top().first;
    }
    cout << answer <<"\n";

    return 0;
}