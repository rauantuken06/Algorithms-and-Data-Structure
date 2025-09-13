#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    string line1, line2;
    cin>>line1>>line2;
    stack<char>st_line1, st_line2;
    for(char c : line1){
        if(!st_line1.empty() && c=='#'){
            st_line1.pop();
        }
        else{
            st_line1.push(c);
        }
    }
    for(char c : line2){
        if(!st_line2.empty() && c=='#'){
            st_line2.pop();
        }
        else{
            st_line2.push(c);
        }
    }
    if(st_line1==st_line2){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }

    return 0;
}