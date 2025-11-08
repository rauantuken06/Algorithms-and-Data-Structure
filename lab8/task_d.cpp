#include <iostream>
using namespace std;

const long long MAX_N = 1000005;
const int product = 11;
const long long quotient = 1000000007;
unsigned long long product_powers[MAX_N];
unsigned long long prefix[MAX_N];

struct Pattern{
    string sub;
    int count;
};

void compute_powers(int n){
    product_powers[0] = 1;
    for(int i = 1; i < n; i++){
        product_powers[i] = (product_powers[i - 1] * product) % quotient;
    }
}

void compute_prefixes(const string& s){
    prefix[0] = (s[0] - 'a' + 1);
    for(int i = 1; i <= s.size(); i++){
        prefix[i] = (prefix[i - 1] + (s[i] - 'a' + 1) * product_powers[i]) % quotient;
    }
}

unsigned long long get_hash(const string& s){
    long long hash = 0;
    for(int i = 0; i < s.size(); i++){
        hash = (hash + (s[i] - 'a' + 1) * product_powers[i]) % quotient;
    }
    return hash;
}

unsigned long long get_substring_hash(int l, int r){
    long long hash = prefix[r];
    if(l > 0){
        hash = (hash + quotient - prefix[l - 1]) % quotient;
    }
    return hash;
}

int count_occurences(const string& text, const string& sub){
    int n = text.size();
    int m = sub.size();
    unsigned long long sub_hash = get_hash(sub);
    int counter = 0;
    for(int i = 0; i + m <= n; i++){
        long long current_hash = get_substring_hash(i, i + m - 1);
        if(current_hash == (sub_hash * product_powers[i]) % quotient){
            counter++;
        }
    }
    return counter;
}

int main(){
    compute_powers(MAX_N - 1);

    while (true){
        int n;
        cin>>n;
        if(n == 0){
            break;
        }

        Pattern paterns[151];
        for(int i = 0; i < n; i++){
            cin>>paterns[i].sub;
            paterns[i].count = 0;
        }

        string text;
        cin>>text;
        compute_prefixes(text);
        int max_count = 0;
        for(int i = 0; i < n; i++){
            paterns[i].count = count_occurences(text, paterns[i].sub);
            if(paterns[i].count > max_count){
                max_count = paterns[i].count;
            }
        }

        cout<<max_count<<"\n";
        for(int i = 0; i < n; i++){
            if(paterns[i].count == max_count){
                cout<<paterns[i].sub<<"\n";
            }
        }
    }

    return 0;
}