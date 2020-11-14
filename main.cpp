//
//  main.cpp
//  Stack_ADT_LL
//
//  Created by Ch Muhammad Wahab on 6/11/2020.
//  Copyright © 2020 Ch Muhammad Wahab. All rights reserved.
//

#include<iostream>
#include<fstream>
using namespace std;

template<class t>
struct Node
{
    t data;
    struct Node<t>* next;
};
template<class t>
class stack{
struct Node<t>* topptr;

public:
    stack(){
        topptr=NULL;
    }
void push(const t &data)
{
    struct Node<t>* temp;
    temp = new Node<t>;
    if (!temp)
    {
        cout << "\nHeap Overflow";
        exit(1);
    }
    temp->data = data;
    temp->next = topptr;
    topptr = temp;
}

bool empty() const
{
    return topptr == NULL;
}
int top() const
{
        return topptr->data;
}
void pop()
{
    struct Node<t>* temp;
    if (topptr == NULL)
    {
        cout << "\nStack Underflow" << endl;
        exit(1);
    }
    else
    {
        temp = topptr;
        topptr = topptr->next;
        delete temp;
    }
    
}
    void stack_status(){
        cout<<"Current Status of Stack\n";
        struct Node<t> *temp;
        temp=topptr;
        if(temp==NULL){
            cout<<"Stack Underflow!\n";
        }
        while(temp!=NULL){
            cout<<temp->data<<endl;
            temp=temp->next;
        }
    }
    ~stack(){
        while (!empty()) {
            pop();
        }
    }
};



int main(int argc,char** argv)
{
    stack<int> s;
    for (int i=0; i<10; i++) {
        s.push(i+1);
    }
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    
}
