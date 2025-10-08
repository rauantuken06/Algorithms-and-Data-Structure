#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* right;
    Node* left;
    Node(int val):data(val), right(nullptr), left(nullptr) {}
};

void insertBST(Node* &root, int x){
    if(!root){
        root=new Node(x);
        return;
    }
    else{
        if(x<root->data) insertBST(root->left, x);
        else insertBST(root->right, x);
    }
}

int cnt=0;
void search(Node* &root){
    if(root==nullptr) return;
    else{
        if(root->left!=nullptr && root->right!=nullptr) cnt++;
        search(root->left);
        search(root->right);
    }
}

int main(){
    int n, x;
    cin>>n;

    Node* root=nullptr;
    for(int i=0; i<n; i++){
        cin>>x;
        insertBST(root, x);
    }

    search(root);
    cout<<cnt<<"\n";
}