#include <iostream>
#include <string>
using namespace std;

const long long MAX_N = 1000005;
const int product = 2;
unsigned long long product_powers[MAX_N];
const long long quotient = 1e18;

void compute_powers(int size){
    product_powers[0] = 1;
    for(int i = 1; i <= size; i++){
        product_powers[i] = (product_powers[i - 1] * product);
    }
}

string restore_the_string(unsigned long long arr[], int size){
    string word = "";
    word += char('a' + arr[0]);
    for(int i = 1; i < size; i++){
        unsigned long long difference = arr[i] - arr[i - 1];
        unsigned long long value = difference / product_powers[i];
        word += char('a' + value);
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
    cout<<restore_the_string(arr, n);

    return 0;
}