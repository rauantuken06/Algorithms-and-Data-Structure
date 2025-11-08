#include <iostream>
#include <string>
using namespace std;

const int product = 2;
const long long quotient = 1000000007;
const long long max_n = 1000005;
unsigned long long product_powers[max_n];

void compute_powers(int n){
    product_powers[0] = 1;
    for(int i = 1; i < n; i++){
        product_powers[i] = (product_powers[i - 1] * product) % quotient;
    }
}

string restore_string(unsigned long long arr[], int n){
    string word = "";
    word+=char('a' + arr[0]);
    for(int i = 1; i < n; i++){
        int diff = arr[i] - arr[i - 1];
        int value = diff / product_powers[i];
        word += ('a' + value);
    }
    return word;
}

int main(){
    int n;
    cin>>n;
    unsigned long long arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    compute_powers(n);
    cout<<restore_string(arr, n);

    return 0;
}