//pythonでいうところの print("yes"*(n ==0) or "no")
// [condition] ?"yes" :"no"
#include <iostream>
using namespace std;
int main(){
    int n = 1;
    cout << (n ==0 ?"yes" :"no") <<endl;
    n = 0;
    cout << (n ==0 ?"yes" :"no") <<endl;
}
