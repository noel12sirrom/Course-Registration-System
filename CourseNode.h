#include <stdio.h>
#include <iostream>
#include "StudentNode.h"
using namespace std;
#ifndef COURSENODE_H
#define COURSENODE_H



class CourseNode { 
    public:
        string title;
        string courseCode;
        int credits;
        int maxCapacity;
        int prerequisite;
        StudentNode* students;
        CourseNode* next;


        CourseNode(){
            title = "";
            courseCode ="";
            credits = 0;
            maxCapacity = 0;
            next = nullptr;
        }


        CourseNode(string title, string courseCode, int credits, int maxCapacity, int prerequisite){
            this->title = title;
            this->courseCode = courseCode;
            this->credits = credits;
            this->maxCapacity = maxCapacity;
            this->prerequisite = prerequisite;
            
        }
         void display(){
            cout<<"Title: "<<title<<"\nCourse Code: "<<courseCode<<endl;
        }

};
#endif