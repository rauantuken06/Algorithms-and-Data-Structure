#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node{
    int data;
    int mode;
    Node* next;

    Node(int value):data(value), mode(1), next(nullptr) {}
};

struct LinkedList{
    int size;
    int max;
    Node* head;
    Node* tail;

    LinkedList():size(0), head(nullptr), tail(nullptr) {}

    void push_back(int value){
        if(!tail){
            Node* node=new Node(value);
            head=node;
            tail=node;
        }
        else{
            Node* curr=head;
            while(curr){
                if(value==curr->data){
                    curr->mode++;
                    break;
                }
                curr=curr->next;
            }
            Node* node=new Node(value);
            tail->next=node;
            tail=node;
        }
    }

    int getMaximum(){
        int maxii=head->mode;
        Node* curr=head;
        while(curr){
            if(curr->mode>maxii){
                maxii=curr->mode;
            }
            curr=curr->next;
        }
        return maxii;
    }

    void printList(){
        max=getMaximum();
        vector<int> result;
        Node* curr=head;
        while(curr){
            if(curr->mode==max){
                result.push_back(curr->data);
            }
            curr=curr->next;
        }

        sort(result.begin(), result.end());
        reverse(result.begin(), result.end());

        for(int val:result){
            cout<<val<<" ";
        }
    }
};

int main(){
    int n;
    cin>>n;

    LinkedList* list=new LinkedList();

    for(int i=0; i<n; i++){
        int val;
        cin>>val;
        list->push_back(val);
    }

    list->printList();

    return 0;
}