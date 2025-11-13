#include <iostream>
#include <vector>
using namespace std;

void compute_LPS(const string& pattern, int m, vector<int> LPS){
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

vector<int> compute_KMP(const string& text, const string& pattern){
    int n = text.size();
    int m = pattern.size();

    vector<int> answers;
    vector<int> LPS(m);
    compute_LPS(pattern, m, LPS);

    int i = 0;
    int j = 0;

    while(i < n){
        if(text[i] == pattern[j]){
            i++;
            j++;
        }
        if(j == m){
            answers.push_back(i - j);
            j = LPS[j - 1];
        }
        else if(i < n && text[i] != pattern[j]){
            if(j != 0){
                j = LPS[j - 1];
            }
            else{
                i++;
            }
        }
    }
    return answers;
}

int main(){
    string text1, text2;
    cin >> text1 >> text2;

    string double_text2 = text2 + text2;
    vector<int> indexes = compute_KMP(double_text2, text1);

    if(indexes.empty()){
        cout << -1 << "\n";
    }
    else{
        for(int i = 0; i < indexes.size(); i++){
            cout << indexes[i] << " ";
        }
    }
    
    return 0;
}