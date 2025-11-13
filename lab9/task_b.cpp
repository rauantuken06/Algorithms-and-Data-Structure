#include <iostream>
#include <vector>
using namespace std;

void compute_lps(const string& pattern, int m, vector<int> LPS){
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

vector<int> compute_kmp(const string& text, const string& pattern){
    int n = text.size();
    int m = pattern.size();

    vector<int> answers;
    vector<int> LPS(m);
    compute_lps(pattern, m, LPS);

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
    string target;
    cin >> target;
    int num;
    cin >> num;

    string text;
    cin >> text;

    vector<int> indexes = compute_kmp(text, target);

    if(indexes.size() >= num){
        cout << "YES" << "\n";
    }
    else{
        cout << "NO" << "\n";
    }

    return 0;
}