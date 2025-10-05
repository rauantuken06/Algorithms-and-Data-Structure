#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
    
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

int cnt[5005];

void bt_insert(Node* &root, int val){
    if(root == nullptr) {
        root = new Node(val);
        return;
    }
    else {
        if(val < root->data) bt_insert(root->left, val);
        else bt_insert(root->right, val);
    }
}
int max_lvl = 0;
void lol_lolovich(Node* root, int lvl){
    if(root == nullptr) return;
    cnt[lvl] += root->data;
    lol_lolovich(root->left, lvl+1);
    lol_lolovich(root->right, lvl+1);
    max_lvl = max(max_lvl, lvl);
}

int main() {
    
    int n, x;
    Node* root = NULL;
    
    cin >> n;
    
    for(int i = 1; i <= n; i++) cin >> x, bt_insert(root, x);
    
    lol_lolovich(root, 0);
    
    cout << max_lvl + 1 << '\n';
    
    for(int i = 0; i <= max_lvl; i++) cout << cnt[i] << ' '; 
    
    return 0;
}