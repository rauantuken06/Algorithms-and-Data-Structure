#include <iostream>
using namespace std;

#define ull unsigned long long

const ull quotient1 = 1e9 + 7;
const ull quotient2 = 1e9 + 9;
const int product = 11;
const int MAX_N = 2005;

struct Hash{
    ull hash1;
    ull hash2;
};

string words[10];
ull product_powers1[MAX_N];
ull product_powers2[MAX_N];
Hash prefix[10][MAX_N];

void compute_powers(){
    product_powers1[0] = 1;
    product_powers2[0] = 1;
    for(int i = 1; i < MAX_N; i++){
        product_powers1[i] = (product_powers1[i - 1] * product) % quotient1;
        product_powers2[i] = (product_powers2[i - 1] * product) % quotient2;
    }
}

void compute_prefix(int index){
    string target = words[index];
    int size = target.size();
    for(int i = 0; i < size; i++){
        ull current = (target[i] - 'a' + 1);
        if(i == 0){
            prefix[index][i].hash1 = current;
            prefix[index][i].hash2 = current;
        }
        else{
            prefix[index][i].hash1 = (prefix[index][i - 1].hash1 * product + current) % quotient1;
            prefix[index][i].hash2 = (prefix[index][i - 1].hash2 * product + current) % quotient2;
        }
    }
}

Hash get_hash(int index, int l, int r){
    Hash res;
    if(l == 0){
        res = prefix[index][r];
    }
    else{
        res.hash1 = (prefix[index][r].hash1 + quotient1 - (prefix[index][l - 1].hash1 * product_powers1[r - l + 1]) % quotient1) % quotient1;
        res.hash2 = (prefix[index][r].hash2 + quotient2 - (prefix[index][l - 1].hash2 * product_powers2[r - l + 1]) % quotient2) % quotient2;
    }

    return res;
}

bool equal_hash(Hash a, Hash b){
    return (a.hash1 == b.hash1 && a.hash2 == b.hash2);
}

int main(){
    int k;
    cin>>k;
    for(int i = 0; i < k; i++){
        cin>>words[i];
    }

    compute_powers();
    for(int i = 0; i < k; i++){
        compute_prefix(i);
    }
    
    string ans = "";
    int n = words[0].size();
    for(int len = n; len >= 1; len--){
        for(int i = 0; i + len <= n; i++){
            Hash base = get_hash(0, i, i + len - 1);
            bool ok = true;
            for(int j = 1; j < k; j++){
                bool found = false;
                for(int t = 0; t + len <= words[j].size(); t++){
                    Hash h = get_hash(j, t, t + len - 1);
                    if(equal_hash(h, base)){
                        found = true;
                        break;
                    }
                }
                if(!found){
                    ok = false;
                    break;
                }
            }
            if(ok){
                ans = words[0].substr(i, len);
                cout<<ans;
                return 0;
            }
        }
    }

    return 0;
}