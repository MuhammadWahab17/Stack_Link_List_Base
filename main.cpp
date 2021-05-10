//
//  main.cpp
//  Stack | STL
//
//  Created by  Muhammad Wahab on 03/05/2021.
//  Copyright © 2021  Muhammad Wahab. All rights reserved.
//

#include <iostream>
using namespace std;
//LIFO //FILO
// 0 1 2 3 4 5

//push()
//top()
//pop()
//empty()
//full()
//copy constructor
//assignment operator (=)
//destructor

template<class t>
struct node{
    t data;
    node* next;
    node(){}
    node(t val, node* n=NULL){
        data = val;
        next = n;
    }
};
template<class t>
class stack{
    node<t>* head;
public:
    stack(){
        head = NULL;
    }
    stack(const stack& obj){
        head = NULL;
        operator=(obj);
    }
    void operator=(const stack& obj){
        node<t>* h = obj.head;
        stack s;
        while(h!=NULL){
            s.push(h->data);
            h=h->next;
        }
        while(!s.empty()){
            push(s.top());
            s.pop();
        }
    }
    ~stack(){
        while(!empty())
            pop();
    }
    void push(const t &val){
        if(full())
            throw "Stack Overflow";
        node<t>* temp = new node<t>(val,head);
        head = temp;
    }
    t top() const{
        return head->data;
    }
    void pop(){
        if(empty())
            throw "Stack underflow";
        node<t>* temp = head;
        head = head->next;
        delete temp;
    }
    bool full(){
        node<t>* temp = new node<t>();
        if(temp){
            return false;
        }
        else
            return true;
    }
    bool empty(){
        if(head==NULL){
            return true;
        }
        else
            return false;
    }
    
};


int main(int argc, const char * argv[]) {
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    stack<int> s2(s);
    while (!s.empty()) {
        cout<<s.top();
        s.pop();
    }
    cout<<endl;
    
    while (!s2.empty()) {
        cout<<s2.top();
        s2.pop();
    }
    
}












