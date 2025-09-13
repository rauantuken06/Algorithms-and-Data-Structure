#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    string line;
    cin>>line;
    stack<char>st_line;

    for(char c : line){
        if(!st_line.empty() && st_line.top()==c){
            st_line.pop();
        }
        else{
            st_line.push(c);
        }
    }

    if(st_line.empty()){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    return 0;
} 