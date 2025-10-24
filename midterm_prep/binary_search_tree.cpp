#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int value){
        data=value;
        left=nullptr;
        right=nullptr;
    }
};

Node* addElements(Node* root, int x){
    Node* node=new Node(x);
    if(!root){
        root=node;
        return root;
    }
    
    if(x<root->data){
        root->left=addElements(root->left, x);
    }
    else{
        root->right=addElements(root->right, x);
    }
    return root;
}

int main(){
    int n;
    cin>>n;
    Node* root=nullptr;

    for(int i=0; i<n; i++){
        int val;
        cin>>val;
        root=addElements(root, val);
    }

    return 0;
}