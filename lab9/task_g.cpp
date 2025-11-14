#include <iostream>
#include <vector>
using namespace std;

void compute_LPS(const string& pattern, int m, vector<int>& LPS){
    int length = 0;
    LPS[0] = 0;
    int i = 1;

    while(i < m){
        if(pattern[i] == pattern[length]){
            length++;
            LPS[i] = length;
            i++;
        }
        else{
            if(length != 0){
                length = LPS[length - 1];
            }
            else{
                LPS[i] = 0;
                i++;
            }
        }
    }
}

int main(){
    string sub_s;
    cin >> sub_s;
    int m = sub_s.size();

    vector<int> LPS(m);
    compute_LPS(sub_s, m, LPS);

    int period = m - LPS[m - 1];

    cout << period << "\n";

    return 0;
}