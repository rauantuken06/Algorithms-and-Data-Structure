#include <iostream>
#include <vector>
using namespace std;

int main(){
    int num1, num2;
    cin >> num1 >> num2;

    vector<int> arr;
    int i = 0;
    while(num1 != num2){
        if(num1 < num2){
            num1 = num1 * 2;
            arr.push_back(num1);
            i++;
        }
        else{
            num1 = num1 - 1;
            arr.push_back(num1);
            i++;
        }
    }

    cout << i << "\n";
    for(int p = 0; p < arr.size(); p++){
        cout << arr[p] << " ";
    }

    return 0;
}