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
            StudentNode{2111686, "Leon"}
        };
        
    public:
        StudentNode * studentNodeHead;
        CourseNode * courseNodeHead;

        CourseNode* studentCourseNodeHead;

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
                    cout<<"found"<<endl;
                    return current;
                }
                current = current->next;
                if (current == nullptr){
                    cout<<"Could not find entry"<<endl;
                }
            }
        }
        CourseNode* courseSearch(string courseCode){
            CourseNode* current = courseNodeHead;
            while(current != nullptr){
                if(current->courseCode == courseCode){
                    cout<<"found"<<endl;
                    return current;
                }
                current = current->next;
                if (current == nullptr){
                    cout<<"Could not find entry"<<endl;
                }
            }
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
                   cout<<"course succesfully removed"<<endl;
                   return;
                }else{
                    previousNode = currentNode;
                    currentNode = currentNode->next;
                }  
            }  
        }
        
        void addCourse(string title, string CourseCode, int credits, int maxCapacity, int prerequisite){
            CourseNode* newCourse = new CourseNode(title, CourseCode, credits, maxCapacity, prerequisite);
            newCourse->next = courseNodeHead;
            courseNodeHead = newCourse;
        }


        void removeCourse(string courseCode){
            CourseNode* currentNode = courseNodeHead;
            CourseNode* previousNode = nullptr;

            while(currentNode != nullptr){

                if(currentNode->courseCode == courseCode){
                    if(previousNode == nullptr){
                        courseNodeHead = currentNode->next;
                    }else{
                        previousNode->next = currentNode->next;
                    }
                   delete currentNode;
                   return;
                }else{
                    previousNode = currentNode;
                    currentNode = currentNode->next;
                }    
            }
        }

        //if added, minus from capacity (so if there were 50 , 49 left) (1)
        void addCourseToStudent(int studentId){
            CourseNode*  currentCourseInIteration = courseNodeHead;
            StudentNode* Student = studentSearch(studentId);
            string inpCourseCode;
            studentCourseNodeHead = Student->Courses;

            printCourselist(courseNodeHead);
          
            cout << "Enter the course code of the course you want to add: ";
            cin >> inpCourseCode;
            cout<<endl;
            
            //(1) check comment above this comment for number
            while(currentCourseInIteration!= nullptr){
                //if inputed course code is found in list of courses it adds it to the students course.
                if(inpCourseCode == currentCourseInIteration->courseCode){
                    CourseNode* newCourseNode = new CourseNode();
                    *newCourseNode = *currentCourseInIteration;

                    newCourseNode->next = studentCourseNodeHead;
                    studentCourseNodeHead = newCourseNode;
                    cout << "Added =>"<<endl;

                    printCourselist(studentCourseNodeHead);
                    return;
                }
                
                currentCourseInIteration = currentCourseInIteration->next;
                if(currentCourseInIteration == nullptr){
                    cout << "Course not found."<<endl;
                }
            }
        }

        //prints linkedlist for students
        void printStudentlist(){
            StudentNode* current = studentNodeHead;
            while (current!= nullptr){
                current->display();
                current = current->next;
            }
        }
      
        void printCourselist(CourseNode* node){
            CourseNode* current = node;
            
            while (current!= nullptr){
                current->display();
                cout<<endl;
                current = current->next;
            }
        }
};
#endif