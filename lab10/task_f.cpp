#include <iostream>
using namespace std;

const int MAX = 100005;
const int MAX_EDGES = 200005;
int head[MAX];
int to[MAX_EDGES];
int next_edge[MAX_EDGES];
int edge_count = 0;

bool visited[MAX];

struct Queue {
    int q[MAX];
    int ql, qr;

    Queue() {
        ql = 0;
        qr = 0;
    }

    void push(int x) {
        q[qr++] = x;
    }

    int front() {
        return q[ql];
    }

    void pop() {
        ql++;
    }

    bool isEmpty() {
        return ql == qr;
    }
};

void addEdge(int u, int v) {
    to[edge_count] = v;
    next_edge[edge_count] = head[u];
    head[u] = edge_count;
    edge_count++;
}

bool bfs(int s, int f, int n) {
    for (int i = 1; i <= n; i++)
        visited[i] = false;

    Queue q;
    q.push(s);
    visited[s] = true;

    while (!q.isEmpty()) {
        int v = q.front();
        q.pop();

        if (v == f)
            return true;

        int e = head[v];
        while (e != -1) {
            int u = to[e];
            if (!visited[u]) {
                visited[u] = true;
                q.push(u);
            }
            e = next_edge[e];
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        head[i] = -1;

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        addEdge(x, y);
        addEdge(y, x);
    }

    int s, f;
    cin >> s >> f;

    if (bfs(s, f, n))
        cout << "YES" << "\n";
    else
        cout << "NO" << "\n";

    return 0;
}