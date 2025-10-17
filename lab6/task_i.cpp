#include <iostream>
using namespace std;

void sortStr(string &text){
    int n=text.size();
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(text[j]>text[j+1]){
                char temp=text[j];
                text[j]=text[j+1];
                text[j+1]=temp;
            }
        }
    }
}

int main(){
    string something;
    cin>>something;

    sortStr(something);
    cout<<something<<"\n";

    return 0;
}