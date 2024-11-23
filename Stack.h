#include <iostream>
#include "StudentNode.h"
using namespace std;
#ifndef STACK_H
#define STACK_H
class LinkedList;
class CourseNode;

class Stack{
    private:
    CourseNode* top;

    public:
    Stack(): top(nullptr){}
    ~Stack(){delete top;}
        
    bool isEmpty(){
        return top == nullptr;
    }

    void push(CourseNode* node){
        node->next = top;
        top = node;
    }

    void pop(){
        CourseNode* temp;
        string cT;
        if(isEmpty()){
            cout << "No Courses Registered" << endl;
        }else{
            temp = top;
            cT = temp->title;
            top = top->next;
            delete temp;
            cout << "Unregistered from "<< cT << endl;
        }
    }

    void peek(){
        if(isEmpty()){
            cout << "No Courses Registered" << endl;
        }else{
            top->display();
        }
    }



};
#endif
