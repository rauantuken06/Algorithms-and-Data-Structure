#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val):data(val), right(nullptr), left(nullptr) {}
};

Node* AddElements(Node* root, int x){
    if(!root) return new Node(x);
    if(x<root->data) root->left=AddElements(root->left, x);
    else if(x>root->data) root->right=AddElements(root->right, x);
    return root;
}

Node* getMin(Node* root){
    while(root->left!=nullptr){
        root=root->left;
    }
    return root;
}

Node* deleteNode(Node* root, int x){
    if(!root) return nullptr;
    if(x<root->data) root->left=deleteNode(root->left, x);
    else if(root->data<x) root->right=deleteNode(root->right, x);
    else{
        if(!root->left && !root->right){
            delete root;
            return nullptr;
        }
        if(!root->left){
            Node* t=root->right;
            delete root;
            return t;
        }
        if(!root->right){
            Node* t=root->left;
            delete root;
            return t;
        }
        Node* t=getMin(root->right);
        root->data=t->data;
        root->right=deleteNode(root->right, t->data);
    }
    return root;
}

int main(){
    int n;
    cin>>n;
    Node* root=nullptr;
    unordered_map<int, int> cnt;

    for(int i=0; i<n; i++){
        string s;
        int x;
        cin>>s>>x;
        if(s=="insert"){
            if(++cnt[x]==1) root=AddElements(root, x);
        }
        else if(s=="delete"){
            auto it=cnt.find(x);
            if(it!=cnt.end() && it->second>0){
                if(--it->second==0) root=deleteNode(root, x);
            }
        }
        else if(s=="cnt"){
            cout<<cnt[x]<<'\n';
        }
    }

    return 0;
}