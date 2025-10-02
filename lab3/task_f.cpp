#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> powers(n);
    for(int i=0;i<n;i++){
        cin>>powers[i];
    }

    sort(powers.begin(), powers.end());

    vector<long long> prefix(n+1, 0);
    for(int i=0;i<n;i++){
        prefix[i+1]=prefix[i] + powers[i];
    }

    int q;
    cin >> q;
    while(q--){
        int m;
        cin >> m;

        int cnt = upper_bound(powers.begin(), powers.end(), m)-powers.begin();
        long long sum=prefix[cnt];

        cout<<cnt<<" "<<sum<<"\n";
    }
    return 0;
}