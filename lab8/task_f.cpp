#include <iostream>
using namespace std;

const long long product1 = 47;
const long long product2 = 53;
const unsigned long long quotient1 = 1e9 + 7; //1000000007
const unsigned long long quotient2 = 1e9 + 9; //1000000009

const long long SIZE = 500003;
const int MAX_N = 2005;

unsigned long long product_powers1[MAX_N];
unsigned long long product_powers2[MAX_N];
unsigned long long prefixes1[MAX_N];
unsigned long long prefixes2[MAX_N];

void compute_powers(int n){
    product_powers1[0] = 1;
    product_powers2[0] = 1;
    for(int i = 1; i <= n; i++){
        product_powers1[i] = (product_powers1[i - 1] * product1) % quotient1;
        product_powers2[i] = (product_powers2[i - 1] * product2) % quotient2;
    }
}

void compute_prefixes(const string& s){
    prefixes1[0] = (s[0] - 'a' + 1);
    prefixes2[0] = (s[0] - 'a' + 1);
    for(int i = 1; i < s.size(); i++){
        prefixes1[i] = (prefixes1[i - 1] + ((unsigned long long)(s[i] - 'a' + 1) * product_powers1[i])) % quotient1;
        prefixes2[i] = (prefixes2[i - 1] + ((unsigned long long)(s[i] - 'a' + 1) * product_powers2[i])) % quotient2;
    }
}

unsigned long long get_substring_hash1(int l, int r, int n){
    unsigned long long hash = prefixes1[r];
    if(l > 0){
        hash = (hash + quotient1 - prefixes1[l - 1]) % quotient1;
    }
    hash = (hash * product_powers1[n - r - 1]) % quotient1;
    return hash;
}

unsigned long long get_substring_hash2(int l, int r, int n){
    unsigned long long hash = prefixes2[r];
    if(l > 0){
        hash = (hash + quotient2 - prefixes2[l - 1]) % quotient2;
    }
    hash = (hash * product_powers2[n - r - 1]) % quotient2;
    return hash;
}

struct DoubleHash{
    unsigned long long hash1;
    unsigned long long hash2;

    DoubleHash(){
        hash1 = 0;
        hash2 = 0;
    }

    DoubleHash(unsigned long long a, unsigned long long b){
        hash1 = a;
        hash2 = b;
    }

    bool operator==(const DoubleHash& other) const{
        return hash1 == other.hash1 && hash2 == other.hash2;
    }
};

struct Node{
    DoubleHash key;
    Node* next;

    Node(){
        next = nullptr;
    }

    Node(DoubleHash k){
        key = k;
        next = nullptr;
    }
};

struct HashTable{
    Node* table[SIZE];
    int elements;

    HashTable(){
        elements = 0;
        for(int i = 0; i < SIZE; i++){
            table[i] = nullptr;
        }
    }

    unsigned long long get_index(DoubleHash& h){
        return (h.hash1 * 31 + h.hash2) % SIZE;
    }

    bool isExist(DoubleHash& h){
        int hash_index = get_index(h);
        Node* current = table[hash_index];
        while(current){
            if(current->key == h){
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void insert(DoubleHash& h){
        if(!isExist(h)){
            int hash_index = get_index(h);
            Node* node = new Node(h);
            node->next = table[hash_index];
            table[hash_index] = node;
            elements++;
        }
    }

    int get_elements(){
        return elements;
    }
};

int main(){
    string s;
    cin>>s;
    int n = s.size();
    compute_powers(n);
    compute_prefixes(s);

    HashTable hashtable;

    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            unsigned long long current_hash1 = get_substring_hash1(i, j, n);
            unsigned long long current_hash2 = get_substring_hash2(i, j, n);
            DoubleHash dh(current_hash1, current_hash2);
            hashtable.insert(dh);
        }
    }

    cout<<hashtable.get_elements()<<"\n";

    return 0;
}