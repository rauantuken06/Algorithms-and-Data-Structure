#include <iostream>
#include <string>
using namespace std;

const int SIZE = 50021;
const long long quotient = 1000000007;
const int product = 11;
unsigned long long Product_powers[1000005];
unsigned long long prefix1[1000005];
unsigned long long prefix2[1000005];

struct Node{
    string key;
    Node* next;

    Node(string s){
        key = s;
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

    unsigned long long get_Hash(const string& s){
        long long hash = 0;
        long long product_power = 1;
        for(char c : s){
            hash = (hash + (unsigned long long)(c) * product_power) % quotient;
            product_power = (product_power * product) % quotient;
        }
        return hash;
    }

    int get_index(const string& s){
        return (int)(get_Hash(s)) % SIZE;
    }

    bool isExist(const string& s){
        int hash_index = get_index(s);
        Node* current = table[hash_index];
        while(current){
            if(current->key == s){
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void insert(const string& s){
        int hash_index = get_index(s);
        if(!isExist(s)){
            Node* node = new Node(s);
            node->next = table[hash_index];
            table[hash_index] = node;
        }
    }
};

int main(){
    string s1, s2, target;
    cin>>s1>>s2>>target;

    int n1 = s1.size(), n2 = s2.size(), m = target.size();

    HashTable hashtable;
    unsigned long long target_hash = hashtable.get_Hash(target);

    Product_powers[0] = 1;
    for(int i = 1; i <= max(n1, n2); i++){
        Product_powers[i] = (Product_powers[i - 1] * product) % quotient;
    }

    prefix1[0] = (unsigned long long)(s1[0]);
    for(int i = 1; i < n1; i++){
        prefix1[i] = (prefix1[i - 1] + (unsigned long long)(s1[i]) * Product_powers[i]) % quotient;
    }

    for(int i = 0; i + m <= n1; i++){
        long long hash = prefix1[i + m - 1];
        if(i > 0){
            hash = (hash + quotient - prefix1[i - 1]) % quotient;
        }
        if(hash == (target_hash * Product_powers[i]) % quotient){
            hashtable.insert(to_string(i));
        }
    }

    int counter = 0;
    prefix2[0] = (unsigned long long)(s2[0]);
    for(int i = 1; i < n2; i++){
        prefix2[i] = (prefix2[i - 1] + (unsigned long long)(s2[i])* Product_powers[i]) % quotient;
    }

    for(int i = 0; i + m <= n2; i++){
        long long hash = prefix2[i + m - 1];
        if(i > 0){
            hash = (hash + quotient - prefix2[i - 1]) % quotient;
        }
        if(hash == (target_hash * Product_powers[i]) % quotient && hashtable.isExist(to_string(i))){
            counter++;
        }
    }

    cout<<counter<<"\n";

    return 0;
}