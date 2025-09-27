#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int value):data(value), next(nullptr){}
};

pair<int, Node*> getLenTail(Node* head){
    if (!head) return {0, nullptr};
    int n = 1;
    Node* curr = head;
    while (curr->next){
        curr = curr->next;
        ++n;
    }
    return {n, curr};
}

Node* go(Node* head, int k){
    Node* curr = head;
    while (k-- > 0 && curr) curr = curr->next;
    return curr;
}

Node* inserts(Node* head, int x, int p){
    Node* node=new Node(x);
    if(p == 0){
        node->next=head;
        return node;
    }
    Node* prev=go(head, p-1);
    node->next=prev->next;
    prev->next=node;
    return head;
}

Node* removeAt(Node* head, int p){
    if(!head) return head;
    if(p==0){
        Node* tmp=head;
        head=head->next;
        delete tmp;
        return head;
    }
    Node* prev=go(head, p-1);
    Node* del=prev->next;
    prev->next=del->next;
    delete del;
    return head;
}

void printList(Node* head){
    if(!head){
        cout <<-1<<"\n";
        return;
    }
    for(Node* curr=head; curr; curr = curr->next){
        cout<<curr->data<< " ";
    }
    cout << "\n";
}

Node* replaceNode(Node* head, int p1, int p2){
    if(!head || p1==p2) return head;

    Node* move = nullptr;
    if(p1 == 0){
        move=head;
        head=head->next;
    } else {
        Node* prev1=go(head, p1-1);
        move=prev1->next;
        prev1->next=move->next;
    }

    if(p2 == 0){
        move->next=head;
        head=move;
    } else {
        Node* prev2=go(head, p2-1);
        move->next=prev2->next;
        prev2->next=move;
    }
    return head;
}

Node* reverseList(Node* head){
    Node* prev=nullptr;
    Node* curr=head;
    while(curr){
        Node* nxt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nxt;
    }
    return prev;
}

Node* cyclic_left(Node* head, int x){
    if (!head || !head->next || x == 0) return head;

    pair<int, Node*> pr = getLenTail(head);
    int n = pr.first;
    Node* tail = pr.second;

    x %= n;
    if (x == 0) return head;

    Node* cutPrev = go(head, x - 1);
    Node* newHead = cutPrev->next;

    tail->next = head;
    cutPrev->next = nullptr;

    return newHead;
}

Node* cyclic_right(Node* head, int x){
    if (!head || !head->next || x == 0) return head;

    pair<int, Node*> pr = getLenTail(head);
    int n = pr.first;
    Node* tail = pr.second;

    x %= n;
    if (x == 0) return head;

    int left = n - x;                    // вправо x = влево (n - x)
    Node* cutPrev = go(head, left - 1);
    Node* newHead = cutPrev->next;

    tail->next = head;       // замкнули
    cutPrev->next = nullptr; // разомкнули

    return newHead;
}

int main(){
    Node* head=nullptr;
    int cmd;
    while (cin>>cmd){
        if (cmd==0){
            return 0;
        }
        else if (cmd==1){
            int x, p; 
            cin>>x>>p;
            head=inserts(head, x, p);
        }
        else if (cmd==2){
            int p;
            cin>>p;
            head=removeAt(head, p);
        }
        else if (cmd==3){
            printList(head);
        }
        else if (cmd == 4){
            int p1, p2;
            cin>>p1>>p2;
            head=replaceNode(head, p1, p2);
        }
        else if (cmd==5){
            head=reverseList(head);
        }
        else if (cmd == 6){
            int x;
            cin>>x;
            head=cyclic_left(head, x);
        }
        else if (cmd==7){
            int x;
            cin>>x;
            head=cyclic_right(head, x);
        }
    }
    return 0;
}