#include <iostream>
#include "StudentNode.h"
#include "CourseNode.h"
using namespace std;
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class LinkedList{
    private:
        CourseNode defaultCourses[4] = {
            CourseNode{"Introduction to Math", "0001", 3, 50, NULL},
            CourseNode{"Discrete Math", "0002", 4, 50, 0001},
            CourseNode{"Critical Thinking", "0003", 2, 60, NULL},
            CourseNode{"Academic Writing", "0004", 3, 80, 0003}
        };

        StudentNode defaultStudent[1] ={
            StudentNode{2111686, "Leon",}
        };
        
    public:
        StudentNode * studentNodeHead=nullptr;
        CourseNode * courseNodeHead=nullptr;

        CourseNode* studentCourseNodeHead = nullptr;

        LinkedList(){
            studentNodeHead = nullptr;
            courseNodeHead = nullptr;
        }

        //initializes the course linked list with 4 courses already in place (default courses)
        void initializeDefaultLists(){
            for(int i = 0; i< 4; i++){
                addCourse(defaultCourses[i].title, defaultCourses[i].courseCode, defaultCourses[i].credits, defaultCourses[i].maxCapacity, defaultCourses[i].prerequisite);
            }
            for(int i = 0; i< 1; i++){
                addStudent(defaultStudent[i].id, defaultStudent[i].name);
            }
        }
        StudentNode* studentSearch(int id){
            StudentNode* current = studentNodeHead;
            while(current != nullptr){
                
                if(current->id == id){
                    cout<<"found person"<<endl;
                    return current;
                }
                current = current->next;
            }
            cout<<"Could not find entry"<<endl;
            return nullptr;
        }
        CourseNode* courseSearch(string courseCode){
            CourseNode* current = courseNodeHead;
            while(current != nullptr){
                if(current->courseCode == courseCode){
                    cout<<"found"<<endl;
                    return current;
                }
                current = current->next;
            }
            cout<<"Could not find entry"<<endl;
            return nullptr;
        }

        void addStudent(int id, string name) {
            StudentNode* newStudent = new StudentNode(id, name);
            newStudent->next = studentNodeHead;
            studentNodeHead = newStudent;
            //newStudent->display(); cout<<endl;
        }
        void removeStudent(int id){
            StudentNode* currentNode = studentNodeHead;
            StudentNode* previousNode = nullptr;

            while(currentNode != nullptr){

                if(currentNode->id == id){
                    if(previousNode == nullptr){
                        studentNodeHead = currentNode->next;
                    }else{
                        previousNode->next = currentNode->next;
                    }
                   delete currentNode;
                   cout<<"Course succesfully removed."<<endl;
                   return;
                }else{
                    previousNode = currentNode;
                    currentNode = currentNode->next;
                }  
            }  
        }
        
         //need to check if course already exists
        void addCourse(string title, string CourseCode, int credits, int maxCapacity, int prerequisite){
            CourseNode* newCourse = new CourseNode(title, CourseCode, credits, maxCapacity, prerequisite);
            newCourse->next = courseNodeHead;
            courseNodeHead = newCourse;
        }


        void removeCourse(string courseCode){
            CourseNode* current = courseNodeHead;
            CourseNode* previousNode = nullptr;

            while(current != nullptr){

                if(current->courseCode == courseCode){
                    if(previousNode == nullptr){
                        courseNodeHead = current->next;
                    }else{
                        previousNode->next = current->next;
                    }
                   delete current;
                   return;
                }else{
                    previousNode = current;
                    current = current->next;
                }    
            }
        }

        //if added, minus from capacity (so if there were 50 , 49 left) (1)
        void addCourseToStudent(int studentId){
            CourseNode*  current = courseNodeHead;
            StudentNode* Student = studentSearch(studentId);
            string inpCourseCode;
            studentCourseNodeHead = Student->Courses;

            printCourselist(courseNodeHead);
          
            cout << "Enter the course code of the course you want to add: ";
            cin >> inpCourseCode;
            cout<<endl;
            
            //(1) check comment above this comment for number
            while(current!= nullptr){
                //if inputed course code is found in list of courses it adds it to the students course.
                if(inpCourseCode == current->courseCode){
                    CourseNode* newCourseNode = current;

                    newCourseNode->next = studentCourseNodeHead;
                    studentCourseNodeHead = newCourseNode;   

                    cout <<"Added =>"<<endl;
                    printCourselist(studentCourseNodeHead);
                    return;
                }
                
                current = current->next;
                if(current== nullptr){
                    cout << "Course not found."<<endl;
                }
            }
        }

        void removeCourseFromStudent(int studentId){
            StudentNode* Student = studentSearch(studentId); // need to add validation that if stuydent doesnt exist then dont continue this 
            CourseNode*  current = studentCourseNodeHead;
            CourseNode* previousNode = nullptr;
            string inpCourseCode;
            
            studentCourseNodeHead = Student->Courses;

            printCourselist(studentCourseNodeHead);
          
            cout << "Enter the course code of the course you want to remove: ";
            cin >> inpCourseCode;
            cout<<endl;
            
            //(1) check comment above this comment for number
            while(current!= nullptr){
                //if inputed course code is found in list of courses it adds it to the students course.
                if(inpCourseCode == current->courseCode){
                     if(previousNode == nullptr){
                        studentCourseNodeHead = current->next;
                    }else{
                        previousNode->next = current->next;
                    }
                    delete current;
                    cout << "Course succesfully removed."<<endl;

                    //printCourselist(studentCourseNodeHead);
                   return;
                }else{
                    previousNode = current;
                    current = current->next;
                    
                    if(current == nullptr){
                        cout << "Course not found."<<endl;
                    }
                    return;
                }      
            }     
        }


        //prints linkedlist for students
        void printStudentlist(){
            StudentNode* current = studentNodeHead;
            while (current!= nullptr){
                current->display();
                cout<<endl;
                current = current->next;
            }
        }

        //this can print the list of courses available as well as courses that a student enrolled in by taking the node head as th start of the list
        void printCourselist(CourseNode* current){
            while (current!= nullptr){
                current->display();
                cout<<endl;
                current = current->next;
            }
        }
};
#endif