#include <iostream>
#include <string>
using namespace std;

void constructLps(const string &s, int *lps) {
    int n = s.size();
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < n) {
        if (s[i] == s[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0)
                len = lps[len - 1];
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

string to_lower(const string &s) {
    string res = s;
    for (int i = 0; i < res.size(); i++) {
        if (res[i] >= 'A' && res[i] <= 'Z'){
            res[i] = res[i] - 'A' + 'a';
        }
    }
    return res;
}

int main() {
    string prcity; cin >> prcity;
    prcity = to_lower(prcity);

    int n; cin >> n;

    string *cities = new string[n];
    for (int i = 0; i < n; i++) 
        cin >> cities[i];

    int max_lap = 0;
    string *results = new string[n];
    int cnt = 0;

    for (int i = 0; i < n; i++){
        string lcity = to_lower(cities[i]); 
        string s = lcity + "#" + prcity; 
        int len = s.size();

        int *lps = new int[len];
        constructLps(s, lps);

        int lap = lps[len - 1];
        delete[] lps;

        if (lap > max_lap){
            max_lap = lap;
            cnt = 0;
            results[cnt++] = cities[i];
        } else if (lap == max_lap && lap > 0){
            results[cnt++] = cities[i];
        }
    }

    if (max_lap == 0){
        cout << 0 << "\n";
    } else{
        cout << cnt << "\n";
        for (int i = 0; i < cnt; i++)
            cout << results[i] << "\n";
    }

    delete[] cities;
    delete[] results;
    return 0;
}