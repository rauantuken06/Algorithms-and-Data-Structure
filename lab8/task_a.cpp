#include <iostream>
#include <string>
using namespace std;

const int SIZE = 50021;
const long long quotient = 1000000007;
const int product = 11;

void copyString(char* a, const char* b){
    int i = 0;
    while(b[i] != '\0'){
        a[i] = b[i];
        i++;
    }
    a[i] = '\0';
}

bool isEqualStr(const char* a, const char* b){
    int i = 0;
    while(a[i] != '\0' && b[i] != '\0'){
        if(a[i] != b[i]){
            return false;
        }
        i++;
    }
    return a[i] == b[i];
}

struct Node{
    char key[105];
    Node* next;

    Node(const char* c){
        copyString(key, c);
        next = nullptr;
    }
};

struct HashTable{
    Node* table[SIZE];

    HashTable(){
        for(int i = 0; i < SIZE; i++){
            table[i] = nullptr;
        }
    }

    int get_index(const char s[]){
        long long hash = 0;
        long long power_prod = 1;
        for(int i = 0; s[i]; i++){
            long long current = (s[i] - 47) * power_prod % quotient;
            hash = (hash + current) % quotient;
            power_prod = (power_prod * product) % quotient;
        }
        return (int)(hash % SIZE);
    }

    bool isExist(const char s[]){
        int hash_index = get_index(s);
        Node* current = table[hash_index];
        while(current){
            if(isEqualStr(current->key, s)){
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void insert(const char s[]){
        int hash_index = get_index(s);
        if(!isExist(s)){
            Node* node = new Node(s);
            node->next = table[hash_index];
            table[hash_index] = node;
        }
    }
};

int main(){
    int n;
    cin>>n;
    int total = 2 * n;
    static char strings[20050][105];
    HashTable hashtable;

    for(int i = 0; i < total; i++){
        cin>>strings[i];
        hashtable.insert(strings[i]);
    }

    int counter = 0;
    for(int i = 0; i < total; i++){
        if(counter == n){
            break;
        }

        long long hash = 0;
        long long power_prod = 1;
        for(int j = 0; strings[i][j]; j++){
            long long current = (strings[i][j] - 47) * power_prod % quotient;
            hash = (hash + current) % quotient;
            power_prod = (power_prod * product) % quotient;
        }

        string hashtoStr(to_string(hash));
        if(hashtable.isExist(hashtoStr.c_str())){
            cout<<"Hash of string \""<<strings[i]<<"\" is "<<hashtoStr<<"\n";
            counter++;
        }
    }

    return 0;
}