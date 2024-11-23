#include <iostream>
#include "StudentNode.h"
#include "CourseNode.h"
using namespace std;
#ifndef QUEUE_H
#define QUEUE_H

class Queue{
    private:
    CourseNode* front; 
    CourseNode* back;  

    public:
    Queue(): front(nullptr)  , back(nullptr){}

    /*
    ~Queue(){
        delete top;}
    */
   
    bool isEmpty() const {
        return front == nullptr;
    }

    void enqueue(CourseNode* node){
        if(!isEmpty()){
            back->next = node;
            back = node;  
        }else{
            front = back = node; 
        }
    }
    
    void dequeue(){
        CourseNode* temp;
        string cT;
        if(isEmpty()){
            cout << "No Courses in waitlist" << endl;
        }else{
            temp = front->next;
            cT = front->title;
            delete front;
            front = temp;
            
            cout << "dequed from "<< cT << endl;
        }
    }

    void peek(){
        if(isEmpty()){
            cout << "No Courses in waitlist" << endl;
        }else{
            front->display();
        }
    }
    
};
#endif