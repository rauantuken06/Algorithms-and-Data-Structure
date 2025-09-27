#include <iostream>
#include <queue>
using namespace std;

int main(){
    int t;
    if(!(cin>>t)){
        return 0;
    }
    while(t--){
        int n;
        cin>>n;
        int freq[26]={0};
        queue<char>lol;
        for(int i=0; i<n; i++){
            char c;
            cin>>c;
            int indx=c-'a';

            freq[indx]++;
            lol.push(c);

            while(!lol.empty() && freq[lol.front()-'a']>1){
                lol.pop();
            }
            if(lol.empty()){
                cout<<-1<<" ";
            }
            else{
                cout<<lol.front()<<" ";
            }
        }
        cout<<"\n";
    }
    
    return 0;
}