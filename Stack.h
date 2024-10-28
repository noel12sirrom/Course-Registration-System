#include <iostream>
#include "StudentNode.h"
#include "CourseNode.h"
using namespace std;

class Stack{
    private:
    CourseNode* top;

    public:
    Stack(): top(nullptr){}
    ~Stack(){delete top;}
    Stack(CourseNode* Top): top(Top) {}
        
    bool isEmpty() const {
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
