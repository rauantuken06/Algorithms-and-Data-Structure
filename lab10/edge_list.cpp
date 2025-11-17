#include <iostream>
#include <vector>
using namespace std;

struct Edge{
    int u, v;
    int weight;
};

const int MAX_N = 1000;
Edge edges[MAX_N];
int edgeCount = 0;
int n;

void addEdge(int u, int v, int weight = 1){
    edges[edgeCount].u = u;
    edges[edgeCount].v = v;
    edges[edgeCount].weight = weight;
    edgeCount++;
}

void printEdges(){
    cout << "Edge List:" << "\n";
    for(int i = 0; i < edgeCount; i++){
        cout << "(" << edges[i].u << "," << edges[i].v;
        if(edges[i].weight != 1){
            cout << ", " << edges[i].weight;
        }
        cout << ")" << "\n";
    }
}

int main(){
    n = 5;

    addEdge(0, 1);
    addEdge(0, 3);
    addEdge(2, 1);
    addEdge(4, 1);
    addEdge(2, 3);

    printEdges();

    return 0;
}