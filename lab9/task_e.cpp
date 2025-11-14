#include <iostream>
#include <vector>
using namespace std;

void compute_lps(const string& pattern, int m, vector<int>& LPS){
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
    int num;
    cin >> num;

    vector<int> result;
    for(int i = 0; i < num; i++){
        string word;
        cin >> word;
        int n;
        cin >> n;
        int m = word.size();
        vector<int> indexes(m);
        compute_lps(word, m, indexes);

        int overlap = indexes[indexes.size() - 1];
        int answer = (m + (n - 1) * (m - overlap));
        result.push_back(answer);
    }

    for(int i = 0; i < result.size(); i++){
        cout << result[i] << "\n";
    }

    return 0;
}