#include <stdio.h>
#include <iostream>
using namespace std;
#ifndef STUDENTNODE_H
#define STUDENTNODE_H

//forward dependency
class CourseNode;

class StudentNode{
    public:
        int id;
        string name;
        CourseNode* Courses;
        StudentNode* next;

        StudentNode(){
            id = 0;
            name = "";
            Courses = nullptr;
            next = nullptr;
        }

        StudentNode(int id, string name){
            this->id = id;
            this->name = name;
            this->Courses = nullptr;
            this->next = nullptr;
        }

        //incomplete
        void display(){
            cout<<"Name: "<<name<<"\nid: "<<id<<"\nCourses: "<<Courses<<endl;
        }

};
#endif
