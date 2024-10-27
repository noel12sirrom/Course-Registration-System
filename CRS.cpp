# include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
using namespace std;

int main(){
    LinkedList ll;
    ll.initializeDefaultLists();
    string name;
    int id;

    /*
    ll.printCourselist(1);
    cout<< endl;
    ll.printStudentlist();
    
    cout<<"enter id"<<endl;
    cin>> id;*/
    ll.addStudent(1234,"ken");
    ll.printStudentlist();
    ll.addCourseToStudent(1234);
    ll.removeCourseFromStudent(1234);
    
}