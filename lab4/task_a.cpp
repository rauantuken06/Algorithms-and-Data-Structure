#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* right;
    Node* left;
    Node(int x):data(x), right(nullptr), left(nullptr) {}
};

void bt_insert(Node* &root, int val){
    if(root==nullptr){
        root=new Node(val);
        return;
    }
    else{
        if(val<root->data){
            bt_insert(root->left, val);
        }
        else{
            bt_insert(root->right, val);
        }
    }
}

bool check(string s, Node* node){
    Node* cur=node;
    for(int i=0; i<s.size(); i++){
        if(cur==nullptr) return false;
        else if(s[i]=='L'){
            cur=cur->left;
        }
        else{
            cur=cur->right;
        }
    }
    if(cur!=nullptr) return true;
    else return false;
}

int main(){
    int n, m, x;
    string s;
    Node* root=nullptr;

    cin>>n>>m;

    for(int i=0; i<n; i++){
        cin>>x;
        bt_insert(root, x);
    }

    for(int i=0; i<m; i++){
        cin>>s;
        if(check(s, root)){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
}