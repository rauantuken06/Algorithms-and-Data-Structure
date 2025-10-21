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
        size++;
    }

    int solve(int k){
        int cnt=0;
        int index=0;
        int mini=3000;

        Node* curr=head;
        while(curr){
            int diff=abs(k-curr->data);
            if(diff<mini){
                mini=diff;
                index=cnt;
            }
            cnt++;
            curr=curr->next;
        }

        return index;
    } 
};

int main(){
    int n;
    cin>>n;

    LinkedList* list=new LinkedList();

    for(int i=0; i<n; i++){
        int lol; cin>>lol;
        list->push_back(lol);
    }
    int target;
    cin>>target;

    cout<<list->solve(target);

    return 0;
}