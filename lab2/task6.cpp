#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int value):data(value), next(nullptr){}
};

Node* insert_at_pos(Node* head, int x, int posi){
    Node* newNode=new Node(x);

    if(posi==0){
        newNode->next=head;
        return newNode;
    }

    Node* curr=head;
    for(int i=0; i<posi-1 && curr!=nullptr; i++){
        curr=curr->next;
    }

    newNode->next=(curr ? curr->next:nullptr);
    if(curr){
        curr->next=newNode;
    }
    return head;
}

int main(){
    int n;
    cin>>n;

    Node* head=nullptr;
    Node* tail=nullptr;

    for(int i=0; i<n; i++){
        int val;
        cin>>val;
        Node* node=new Node(val);
        if(!head){
            head=tail=node;
        }
        else{
            tail->next=node;
            tail=node;
        }
    }

    int x, pos;
    cin>>x>>pos;

    head=insert_at_pos(head, x, pos);

    for(Node* p=head; p!=nullptr; p=p->next){
        cout<<p->data<<" ";
    }
    cout<<"\n";
    return 0;
}