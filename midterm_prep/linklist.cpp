#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int value):data(value), next(nullptr) {}
};

struct LinkedList{
    int size;
    Node* head;
    Node* tail;
    LinkedList():size(0), head(nullptr), tail(nullptr) {}

    void push_back(int val){
        Node* node=new Node(val);
        if(!tail){
            head=node;
            tail=node;
        }
        else{
            tail->next=node;
            tail=node;
        }
        size++;
    }

    void push_front(int val){
        Node* node=new Node(val);
        if(!head){
            head=node;
            tail=node;
        }
        else{
            node->next=head;
            head=node;
        }
        size++;
    }

    void print(){
        Node* curr=head;
        while(curr){
            cout<<curr->data<<" ";
            curr=curr->next;
        }
    }
};

int main(){
    int n, m;
    cin>>n>>m;

    LinkedList* LiLi=new LinkedList();
    LinkedList* Lol_Lol=new LinkedList();

    for(int i=0; i<n; i++){
        int val; cin>>val;
        Lol_Lol->push_back(val);
    }

    for(int i=0; i<m; i++){
        int val; cin>>val;
        LiLi->push_front(val);
    }

    Lol_Lol->print();
    cout<<"\n";
    LiLi->print();

    return 0;

}