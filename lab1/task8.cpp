#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main(){
    deque<long long>deq;
    deque<string>for_res;
    char str;
    while(cin>>str){
        if(str=='!'){
            break;
        }
        if(str=='+' || str=='-'){
            long long num;
            cin>>num;
            if(str=='+'){
                deq.push_front(num);
            }
            else{
                deq.push_back(num);
            }
        }
        else if(str=='*'){
            if(deq.empty()){
                for_res.push_back("error");
            }
            else if(deq.size()==1){
                long long a = deq.front();
                for_res.push_back(to_string(a+a));
                deq.pop_front();
            }
            else{
                long long a = deq.front();
                long long b =deq.back();
                for_res.push_back(to_string(a+b));
                deq.pop_front();
                deq.pop_back();
            }
        }
    }
    
    while(!for_res.empty()){
        cout<<for_res.front()<<endl;
        for_res.pop_front();
    }
    return 0;
}