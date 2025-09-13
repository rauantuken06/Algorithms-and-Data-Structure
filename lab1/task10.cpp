#include <iostream>
#include <deque>
using namespace std;
int main(){
    int n;
    cin>>n;
    while (n--){
        int num;
        cin>>num;
        deque<int>lol_kek;
        for(int i=num; i>=1; i--){
            lol_kek.push_front(i);
            int swap=i%lol_kek.size();
                while(swap--){
                    int backer=lol_kek.back();
                    lol_kek.pop_back();
                    lol_kek.push_front(backer);
            }
        }
        for(int i=0; i<lol_kek.size(); i++){
            cout<<lol_kek[i]<<" ";
            cout<<endl;
        }
    }
    return 0;
}