#include <iostream>
using namespace std;

struct Node{
    string data;
    Node* next;

    Node(string value):data(value), next(nullptr) {}
};

struct LinkedList{
    int size;
    Node* head;
    Node* tail;

    LinkedList():size(0), head(nullptr), tail(nullptr) {}

    void push_back(string value){
        Node* node=new Node(value);
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

    void sdelat(int pos){
        tail->next=head;
        Node* temp=nullptr;
        for(int i=0; i<pos; i++){
            temp=head;
            head=head->next;
        }
        temp->next=nullptr;
        tail=temp;
    }

    void printlist(){
        Node* curr=head;
        while(curr!=nullptr){
            cout<<curr->data<<" ";
            curr=curr->next;
        }
    }
};

int main(){
    int n, k;
    cin>>n>>k;

    LinkedList* list=new LinkedList();

    for(int i=0; i<n; i++){
        string inp; cin>>inp;
        list->push_back(inp);
    }

    list->sdelat(k);
    list->printlist();

    return 0;
}