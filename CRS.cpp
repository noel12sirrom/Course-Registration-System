#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Stack.h"
using namespace std;

LinkedList ll;

void initializeDefaultLists(){
    CourseNode defaultCourses[4] = {
        CourseNode{"Introduction to Math", "0001", 3, 50, NULL},
        CourseNode{"Discrete Math", "0002", 4, 50, 0001},
        CourseNode{"Critical Thinking", "0003", 2, 60, NULL},
        CourseNode{"Academic Writing", "0004", 3, 80, 0003}
    };

    StudentNode defaultStudent[1] ={
        StudentNode{2111686, "Leon"}
    };

    for(int i = 0; i< 4; i++){
        ll.addCourse(defaultCourses[i].title, defaultCourses[i].courseCode, defaultCourses[i].credits, defaultCourses[i].maxCapacity, defaultCourses[i].prerequisite);
    }
    for(int i = 0; i< 1; i++){
        ll.addStudent(defaultStudent[i].id, defaultStudent[i].name);
    }

};

/*
cout << "1. Add Student" << endl;
cout << "2. Add Course" << endl;
cout << "3. Enroll Student in Course" << endl;
cout << "4. Drop Student from Course" << endl;
cout << "5. Display Student List" << endl;
cout << "6. Display Course List" << endl;
cout << "7. Display Student's Course List" << endl;
cout << "8. Display Course's Student List" << endl;
cout << "9. Exit" << endl;
*/

int main(){
    initializeDefaultLists();
    string name;
    int id;
    int inp = 0;
    string course = "0";
    
    ll.addCourseToStudent(2111686);
    ll.addCourseToStack(2111686);


    
}