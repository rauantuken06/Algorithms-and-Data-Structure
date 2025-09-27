#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL){}
};

struct LinkedList{
    Node* head;
    LinkedList() : head(NULL){}

    void push_back(int val){
        Node* newNode=new Node(val);
        if(!head){
            head=newNode;
            return;
        }
        Node* temp=head;
        while(temp->next){
            temp=temp->next;
        }
        temp->next=newNode;
    }

    void removeEverySecond(){
        if(!head) return;
        Node* curr=head;
        while(curr && curr->next){
            Node* temp=curr->next;
            curr->next=curr->next->next;
            delete temp;
            curr=curr->next;
        }
    }

    void print(){
        Node* temp=head;
        while(temp){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
};

int main(){
    int n;
    cin>>n;
    LinkedList array;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        array.push_back(x);
    }

    array.removeEverySecond();
    array.print();
    
    return 0;
}