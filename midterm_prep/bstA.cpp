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

Node* addElemnts(Node* &root, int x){
    Node* node=new Node(x);
    if(!root){
        root=node;
        return root;
    }

    Node* current=root;
    Node* prev=nullptr;

    while(current){
        prev=current;
        if(x<current->data){
            current=current->left;
        }
        else{
            current=current->right;
        }
    }
    if(x<prev->data){
        prev->left=node;
    }
    else{
        prev->right=node;
    }
    return root;
}

void check(Node* root, string word){
    Node* curr=root;

    for(char c:word){
        if(curr==nullptr) break;
        if(c=='L'){
            curr=curr->left;
        }
        else{
            curr=curr->right;
        }
    }

    if(curr!=nullptr){
        cout<<"YES"<<"\n";
    }
    else{
        cout<<"NO"<<"\n";
    }
}

int main(){
    int n, m;
    cin>>n>>m;
    int arr[n];
    Node* root=nullptr;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        root=addElemnts(root, arr[i]);
    }

    for(int i=0; i<m; i++){
        string path;
        cin>>path;
        check(root, path);
    }

    return 0;
}