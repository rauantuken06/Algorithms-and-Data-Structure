#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<string>students;
    string prev="";
    for(int i=0; i<n; i++){
        string name;
        cin>>name;
        if(name!=prev){
            students.push_back(name);
        }
        prev=name;
    }
    cout<<"All in all: "<<students.size()<<"\n";
    cout<<"Students:"<<"\n";
    for(int i=students.size()-1; i>=0; i--){
        cout<<students[i]<<"\n";
    }

    return 0;
}