#include <iostream>
#include <string>
using namespace std;

struct Node{
    string word;
    Node* next;
    Node(string w):word(w), next(nullptr){}
};

Node* shiftList(Node* head, int n, int k){
    if(!head || k%n==0){
        return head;
    }

    k=k%n;

    Node* curr=head;
    for(int i=1; i<k; i++){
        curr=curr->next;
    }

    Node* newHead=curr->next;
    curr->next=nullptr;

    Node* tail=newHead;
    while(tail->next){
        tail=tail->next;
    }

    tail->next=head;

    return newHead;
}

int main(){
    int n, k;
    cin>>n>>k;

    Node* head=nullptr;
    Node* tail=nullptr;

    for(int i=0; i<n; i++){
        string w;
        cin>>w;
        Node* node=new Node(w);
        if(!head){
            head=tail=node;
        }
        else{
            tail->next=node;
            tail=node;
        }
    }

    head=shiftList(head, n, k);

    Node* curr=head;
    while(curr){
        cout<<curr->word<<" ";
        curr=curr->next;
    }
    cout<<"\n";
}