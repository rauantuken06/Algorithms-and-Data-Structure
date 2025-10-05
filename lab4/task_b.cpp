#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* right;
    Node* left;
    Node(int x):data(x), right(nullptr), left(nullptr) {}
};

void btree_insert(Node* &root, int val){
    if(root==nullptr){
        root=new Node(val);
        return;
    }
    else{
        if(val<root->data){
            btree_insert(root->left, val);
        }
        else{
            btree_insert(root->right, val);
        }
    }
}

int sum=0;

int count(Node* cur){
    if(cur==nullptr) return 0;
    return 1+count(cur->right)+count(cur->left);
}

int search_subtree(Node* cur, int val){
    if(cur==nullptr) return 0;
    else if(cur->data==val) return count(cur);
    else if(val<cur->data) return search_subtree(cur->left, val);
    else return search_subtree(cur->right, val);
}

int main(){
    int n, x;
    Node* root=NULL;

    cin>>n;
    
    for(int i=0; i<n; i++){
        cin>>x;
        btree_insert(root, x);
    }

    cin>>x;
    Node* cur=root;
    cout<<search_subtree(cur, x);

    return 0;
}