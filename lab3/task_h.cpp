#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<long long>blocks(n);
    for (int i=0; i<n; i++) {
        cin>>blocks[i];
    }

    vector<long long>prefix(n);
    prefix[0] = blocks[0];
    for (int i=1; i<n; i++) {
        prefix[i] = prefix[i-1] + blocks[i];
    }

    while (m--) {
        long long line;
        cin >> line;

        int block=lower_bound(prefix.begin(), prefix.end(), line) - prefix.begin();
        cout<<block + 1<< "\n";
    }

    return 0;
}