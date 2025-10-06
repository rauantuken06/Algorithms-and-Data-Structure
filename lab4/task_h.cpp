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
    if(x<root->data) insertBST(root->left, x);
    else insertBST(root->right, x);
}

void toGreaterSum(Node* root, int &acc){
    if(!root) return;
    toGreaterSum(root->right, acc);
    acc+=root->data;
    root->data=acc;
    toGreaterSum(root->left, acc);
}

void printInorder(Node* root){
    if(!root) return;
    printInorder(root->right);
    cout<<root->data<<" ";
    printInorder(root->left);
}

int main(){
    int n;
    cin>>n;

    Node* root=nullptr;

    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        insertBST(root, x);
    }

    int sum=0;
    toGreaterSum(root, sum);
    printInorder(root);

    return 0;
}