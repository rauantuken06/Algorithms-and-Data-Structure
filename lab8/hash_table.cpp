#include <iostream>
#include <string>
using namespace std;

struct Node{
    string key;
    int value;
    Node* next;
};

struct HashTable{
    static const int SIZE = 10;
    Node* dataMap[SIZE];

    HashTable(){
        for(int i = 0; i < SIZE; i++){
            dataMap[i] = nullptr;
        }
    }

    ~HashTable(){
        for(int i = 0; i < SIZE; i++){
            Node* current = dataMap[i];
            while(current != nullptr){
                Node* next = current->next;
                delete current;
                current = next;
            }
        }
    }

    int hashFunc(const string &key) const{
        int hash = 0;
        for(int i = 0; i < (int)key.length(); i++){
            int ascii = (int)key[i];
            hash = (hash + ascii * 23) % SIZE;
        }
        return hash;
    }

    void insert(const string &key, int value){
        int index = hashFunc(key);
        Node* node = new Node{key, value, nullptr};

        if(dataMap[index] == nullptr){
            dataMap[index] = node;
        }
        else{
            Node* current = dataMap[index];
            while(current->next != nullptr){
                current = current->next;
            }
            current->next = node;
        }
    }

    int get_key(const string &key) const{
        int index = hashFunc(key);
        Node* current = dataMap[index];

        while(current != nullptr){
            if(current->key == key){
                return current->value;
            }
            current = current->next;
        }

        return 0;
    }

    void print(){
        for(int i = 0; i < SIZE; i++){
            cout<<"Index "<<i<<": ";
            if(dataMap[i] == nullptr){
                cout<<"Empty"<<"\n";
            }
            else{
                Node* current = dataMap[i];
                cout<<"Contains: ";
                while(current != nullptr){
                    cout<<"{"<<current->key<<", "<<current->value<<"}";
                    if(current->next){
                        cout<<", ";
                    }
                    current = current->next;
                }
                cout<<"\n";
            }
        }
    }
};

int main(){
    int n;
    cin>>n;
     
    HashTable table;
    for(int i = 0; i < n; i++){
        string key;
        cin>>key;
        int value;
        cin>>value;
        table.insert(key, value);
    }

    table.print();

    cout<<"Value of key1: "<<table.get_key("key1")<<"\n";

    return 0;
}