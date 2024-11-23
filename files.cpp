#include <fstream>
#include <iostream>
using namespace std;


int main(){
    string name;
    cout<< "name: ";
    cin>>name;

    ofstream file("name.txt", ios::out|ios::app);

    file<<name;
    file.close();
    
}