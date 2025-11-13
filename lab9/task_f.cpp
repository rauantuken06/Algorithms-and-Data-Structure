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
            answers.push_back(i - j + 1);
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
    string s1;
    cin >> s1;

    string s2;
    cin >> s2;

    vector<int> for_result = compute_KMP(s1, s2);
    
    cout << for_result.size() << "\n";
    for(int n : for_result){
        cout << n << " ";
    }

    return 0;
}