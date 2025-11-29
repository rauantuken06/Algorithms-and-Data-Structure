#include <iostream>
#include <vector>
#include <limits>
#include <climits>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<long long> islands_with_ducks(n);
    long long sum_of_all = 0;
    long long mini = LLONG_MAX;
    
    for(int i = 0; i < n; i++){
        cin >> islands_with_ducks[i];
        sum_of_all += islands_with_ducks[i];
        if(islands_with_ducks[i] < mini){
            mini = islands_with_ducks[i];
        }
    }

    if(n == 1){
        cout << 0 << "\n";
        return 0;
    }

    long long answer = (n - 1) * mini + (sum_of_all - mini);
    cout << answer << "\n";

    return 0;
}