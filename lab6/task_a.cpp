#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n; cin>>n;
    vector<char>arr(n);
    vector<char>vowel;
    vector<char>consonant;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        if(arr[i]=='a'||arr[i]=='e'||arr[i]=='i'||arr[i]=='o'||arr[i]=='u'){
            vowel.push_back(arr[i]);
        }
        else{
            consonant.push_back(arr[i]);
        }
    }
    sort(vowel.begin(), vowel.end());
    sort(consonant.begin(), consonant.end());

    for(char p:vowel){
        cout<<p;
    }
    for(char c:consonant){
        cout<<c;
    }

    return 0;
}