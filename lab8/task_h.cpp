#include <iostream>
#include <string>
using namespace std;

const long long SIZE = 500301;
const long long quotient1 = 1e9 + 7;
const long long quotient2 = 1e9 + 9;
const long long product1 = 47;
const long long product2 = 53;

const long long MAX_N = 2005;
unsigned long long prefixes1[MAX_N];
unsigned long long prefixes2[MAX_N];
unsigned long long product_powers1[MAX_N];
unsigned long long product_powers2[MAX_N];

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
        prefixes1[i] = (prefixes1[i - 1] + (unsigned long long)(s[i] - 'a' + 1) * product_powers1[i]) % quotient1;
        prefixes2[i] = (prefixes2[i - 1] + (unsigned long long)(s[i] - 'a' + 1) * product_powers2[i]) % quotient2;
    }
}

unsigned long long get_hash1(const string& s){
    unsigned long long hash = 0;
    for(int i = 0; i < s.size(); i++){
        hash = (hash + (unsigned long long)(s[i] - 'a' + 1) * product_powers1[i]) % quotient1;
    }
    return hash;
}

unsigned long long get_hash2(const string& s){
    unsigned long long hash = 0;
    for(int i = 0; i < s.size(); i++){
        hash = (hash + (unsigned long long)(s[i] - 'a' + 1) * product_powers2[i]) % quotient2;
    }
    return hash;
}

unsigned long long get_substr_hash1(int l, int r){
    unsigned long long hash = prefixes1[r];
    if(l > 0){
        hash = (hash + quotient1 - prefixes1[l - 1]) % quotient1;
    }
    return hash;
}

unsigned long long get_substr_hash2(int l, int r){
    unsigned long long hash = prefixes2[r];
    if(l > 0){
        hash = (hash + quotient2 - prefixes2[l - 1]) % quotient2;
    }
    return hash;
}

int count_occurences(const string& text, const string& sub){
    int n = text.size();
    int m = sub.size();
    int counter = 0;

    unsigned long long sub_hash1 = get_hash1(sub);
    unsigned long long sub_hash2 = get_hash2(sub); 

    for(int i = 0; i + m <= n; i++){
        unsigned long long current_hash1 = get_substr_hash1(i, i + m - 1);
        unsigned long long current_hash2 = get_substr_hash2(i, i + m - 1);

        unsigned long long expected_hash1 = (sub_hash1 * product_powers1[i]) % quotient1;
        unsigned long long expected_hash2 = (sub_hash2 * product_powers2[i]) % quotient2;

        if(current_hash1 == expected_hash1 && current_hash2 == expected_hash2){
            counter++;
        }
    }
    return counter;
}

int main(){
    string word;
    cin>>word;
    int queries;
    cin>>queries;
    int n = word.size();

    compute_powers(n);
    compute_prefixes(word);
    
    int result[queries];
    for(int i = 0; i < queries; i++){
        int left, right;
        cin>>left>>right;
        left--;
        right--;

        string sub_string = word.substr(left, right - left + 1);
        result[i] = count_occurences(word, sub_string);
    }

    for(int i = 0; i < queries; i++){
        cout<<result[i]<<"\n";
    }

    return 0;
}