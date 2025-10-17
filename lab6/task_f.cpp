#include <bits/stdc++.h>
using namespace std;

struct Student{
    string lastn, firstn;
    double gpa;
};

map<string, double> grades={
    {"A+", 4.00}, {"A", 3.75}, {"B+", 3.50}, {"B", 3.00},
    {"C+", 2.50}, {"C", 2.00}, {"D+", 1.50}, {"D", 1.00}, {"F", 0.00}
};

bool comp(const Student &a, const Student &b){
    if(a.gpa!=b.gpa) return a.gpa<b.gpa;
    if(a.lastn!=b.lastn) return a.lastn<b.lastn;
    return a.firstn<b.firstn;
}
int main(){
    int n; cin>>n;
    vector<Student> students;
    for(int i=0; i<n; i++){
        string lastn, firstn;
        int subj;
        cin>>lastn>>firstn>>subj;

        double total_points=0;
        double total_credits=0;

        for(int j=0; j<subj; j++){
            string mark;
            int credit;
            cin>>mark>>credit;

            total_points+=grades[mark]*credit;
            total_credits+=credit;
        }

        double gpa=total_points/total_credits;
        students.push_back({lastn, firstn, gpa});
    }

    sort(students.begin(), students.end(), comp);

    cout<<fixed<<setprecision(3);
    for(auto &s:students){
        cout<<s.lastn<<" "<<s.firstn<<" "<<s.gpa<<"\n";
    }

    return 0;
}