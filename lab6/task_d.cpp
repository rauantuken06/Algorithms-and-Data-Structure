#include <bits/stdc++.h>
using namespace std;

struct Date {
    int day, month, year;
};


bool compareDates(const Date &a, const Date &b) {
    if (a.year!=b.year)  return a.year<b.year;
    if (a.month!=b.month) return a.month<b.month;
    return a.day<b.day;
}

int main() {
    int n;
    cin>>n;

    vector<Date> dates(n);
    string input;

    for (int i = 0; i < n; i++) {
        cin >> input;

        dates[i].day=(input[0] - '0') * 10 + (input[1] - '0');
        dates[i].month=(input[3] - '0') * 10 + (input[4] - '0');
        dates[i].year=(input[6] - '0') * 1000 
                    + (input[7] - '0') * 100 
                    + (input[8] - '0') * 10 
                    + (input[9] - '0');
    }

    sort(dates.begin(), dates.end(), compareDates);

    for (const auto &d : dates) {
        cout<<setw(2)<<setfill('0')<<d.day<< "-"
            <<setw(2)<<setfill('0')<<d.month<< "-"
            <<d.year<< "\n";
    }

    return 0;
}