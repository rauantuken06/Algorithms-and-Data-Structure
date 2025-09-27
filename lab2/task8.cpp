#include <iostream>
#include <string>
using namespace std;

struct Node{
    string value;
    Node* prev;
    Node* next;
    Node(const string& v):value(v), prev(nullptr), next(nullptr){}
};

struct Deque{
    Node* head=nullptr;
    Node* tail=nullptr;

    void add_front(const string& s){
        Node* node=new Node(s);
        node->next=head;
        if(head) head->prev=node;
        head=node;
        if(!tail) tail=node;
    }

    void add_back(const string& s){
        Node* node=new Node(s);
        node->prev=tail;
        if(tail) tail->next=node;
        tail=node;
        if(!head) head=node;
    }

    bool erase_front(string& out){
        if(!head) return false;
        Node* node=head;
        out=node->value;
        head=head->next;
        if(head) head->prev=nullptr;
        else tail=nullptr;
        delete node;
        return true;
    }

    bool erase_back(string& out){
        if(!tail) return false;
        Node* node=tail;
        out=node->value;
        tail=tail->prev;
        if(tail) tail->next=nullptr;
        else head=nullptr;
        delete node;
        return true;
    }

    bool front(string& out) const{
        if(!head) return false;
        out=head->value;
        return true;
    }

    bool back(string& out) const{
        if(!tail) return false;
        out=tail->value;
        return true;
    }

    void clear(){
        Node* curr=head;
        while(curr){
            Node* nxt=curr->next;
            delete curr;
            curr=nxt;
        }
        head=tail=nullptr;
    }
};

int main(){
    Deque dq;
    string cmd;

    while(cin>>cmd){
        if(cmd=="add_front"){
            string name;
            cin>>name;
            dq.add_front(name);
            cout<<"ok\n";
        }
        else if(cmd=="add_back"){
            string name;
            cin>>name;
            dq.add_back(name);
            cout<<"ok\n";
        }
        else if(cmd=="erase_front"){
            string out;
            if(dq.erase_front(out)){
                cout<<out<<"\n";
            }
            else{
                cout<<"error\n";
            }
        }
        else if(cmd=="erase_back"){
            string out;
            if(dq.erase_back(out)){
                cout<<out<<"\n";
            }
            else{
                cout<<"error\n";
            }
        }
        else if(cmd=="front"){
            string out;
            if(dq.front(out)){
                cout<<out<<"\n";
            }
            else{
                cout<<"error\n";
            }
        }
        else if(cmd=="back"){
            string out;
            if(dq.back(out)){
                cout<<out<<"\n";
            }
            else{
                cout<<"error\n";
            }
        }
        else if(cmd=="clear"){
            dq.clear();
            cout<<"ok\n";
        }
        else if(cmd=="exit"){
            cout<<"goodbye\n";
            break;
        }
    }
    
    return 0;
}