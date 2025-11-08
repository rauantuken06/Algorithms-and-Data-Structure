#include <iostream>
using namespace std;

const long long MAX_N = 1000005;
const long long quotient = 1000000007;
const int product = 11;
unsigned long long prefix[MAX_N];
unsigned long long product_powers[MAX_N];
unsigned long long covered[MAX_N] = {0};

void compute_powers(int n){
    product_powers[0] = 1;
    for(int i = 1; i <= n; i++){
        product_powers[i] = (product_powers[i - 1] * product) % quotient;
    }
}

void compute_prefix(const string& s){
    prefix[0] = (s[0] - 'a' + 1);
    for(int i = 1; i <= s.size(); i++){
        prefix[i] = (prefix[i - 1] + (s[i] - 'a' + 1) * product_powers[i]) % quotient;
    }
}

unsigned long long get_substring_hash(int l, int r){
    long long hash = prefix[r];
    if(l > 0){
        hash = (hash + quotient - prefix[l - 1]) % quotient; 
    }
    return hash;
}

unsigned long long get_hash(const string& s){
    long long hash = 0;
    for(int i = 0; i < s.size(); i++){
        hash = (hash + (s[i] - 'a' + 1) * product_powers[i]) % quotient;
    }
    return hash;
}

int main(){
    string word;
    cin>>word;

    int n;
    cin>>n;

    compute_powers(word.size());
    compute_prefix(word);

    while(n--){
        string sub_string;
        cin>>sub_string;
        int m = sub_string.size();

        unsigned long long hash_sub = get_hash(sub_string);
        for(int i = 0; i + m <= word.size(); i++){
            unsigned long long current_hash = get_substring_hash(i, i + m - 1);
            if(current_hash == (hash_sub * product_powers[i]) % quotient){
                for(int j = i; j < i + m; j++){
                    covered[j] = 1;
                }
            }
        }
    }

    for(int i = 0; i < word.size(); i++){
        if(covered[i] == 0){
            cout<<"NO"<<"\n";
            return 0;
        }
    }
    cout<<"YES"<<"\n";

    return 0;
}