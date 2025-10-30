#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
using namespace std;

struct Student{
    string surname;
    string name;
    double gpa;
};

double getGpa(const string &mark){
    if(mark == "A+"){
        return 4.0;
    }
    if(mark == "A"){
        return 3.75;
    }
    if(mark == "B+"){
        return 3.5;
    }
    if(mark == "B"){
        return 3.0;
    }
    if(mark == "C+"){
        return 2.5;
    }
    if(mark == "C"){
        return 2.0;
    }
    if(mark == "D+"){
        return 1.5;
    }
    if(mark == "D"){
        return 1.0;
    }
    return 0.0;
}

double check = 1e-9;
bool compare_stud(Student &a, Student &b){
    if(fabs(a.gpa - b.gpa) > check){
        return a.gpa < b.gpa;
    }
    if(a.surname != b.surname){
        return a.surname < b.surname;
    }
    return a.name < b.name;
}

void merge(Student stud[], int left, int mid, int right){
    int i = left;
    int j = mid + 1;
    Student temp[right - left + 1];
    int index = 0;

    while(i <= mid && j <= right){
        if(compare_stud(stud[i], stud[j])){
            temp[index] = stud[i];
            i++;
            index++;
        }
        else{
            temp[index] = stud[j];
            j++;
            index++;
        }
    }

    while(i <= mid){
        temp[index] = stud[i];
        i++;
        index++;
    }

    while(j <= right){
        temp[index] = stud[j];
        j++;
        index++;
    }

    for(int lol = 0; lol < index; lol++){
        stud[left + lol]=temp[lol];
    }
}

void mergeSort(Student stud[], int left, int right){
    if(left >= right){
        return;
    }

    int mid = (left + right) / 2;
    mergeSort(stud, left, mid);
    mergeSort(stud, mid + 1, right);

    merge(stud, left, mid, right);
}

int main(){
    int n;
    cin>>n;

    Student *Students = new Student[n];

    for(int i = 0; i < n; i++){
        string surname, name;
        cin>>surname>>name;
        int num_subj;
        cin>>num_subj;
        double credit_cnt = 0;
        double sum = 0;
        for(int j = 0; j < num_subj; j++){
            string mark;
            cin>>mark;
            int credit;
            cin>>credit;
            sum += getGpa(mark) * credit;
            credit_cnt += credit;
        }
        double gpa = sum / credit_cnt;
        Students[i].surname = surname;
        Students[i].name = name;
        Students[i].gpa = gpa;
    }

    mergeSort(Students, 0, n - 1);

    for(int i = 0; i < n; i++){
        cout<<fixed<<setprecision(3)<<Students[i].surname
        <<" "<<Students[i].name<<" "<<Students[i].gpa;
        cout<<"\n";
    }

    delete[] Students;

    return 0;
}