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

bool compute_kmp(const string& text, const string& pattern){
    int n = text.size();
    int m = pattern.size();

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
            return true;
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
    return false;
}

int main(){
    string text1, text2;
    cin >> text1 >> text2;

    string current = text1;
    int k = current.size();
    int n = text1.size();
    int m = text2.size();
    int cnt = 1;

    while(k < m){
        current += text1;
        cnt++;
        k += n;
    }

    if(compute_kmp(current, text2)){
        cout << cnt << "\n";
    }
    else{
        current += text1;
        cnt++;
        if(compute_kmp(current, text2)){
            cout << cnt << "\n";
        }
        else{
            cout << -1 << "\n";
        }
    }

    return 0;
}