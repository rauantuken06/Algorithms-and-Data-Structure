#include <iostream>
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

    void push_back(int value){
        Node* node=new Node(value);
        if(!tail){
            head=node;
            tail=node;
        }
        else{
            tail->next=node;
            tail=node;
        }
    }

    void printList(){
        Node* curr=head;
        int index=0;

        while(curr){
            if(index%2==0){
                cout<<curr->data<<" ";
            }
            index++;
            curr=curr->next;
        }
    }
};

int main(){
    int n;
    cin>>n;

    LinkedList* list=new LinkedList();

    for(int i=0; i<n; i++){
        int value;
        cin>>value;
        list->push_back(value);
    }

    list->printList();

    return 0;
}