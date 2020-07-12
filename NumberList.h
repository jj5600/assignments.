#ifndef NUMBERLIST_H
#define NUMBERLIST_H
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<iomanip>
using namespace std;
// ********************************************************
// name:      NumberList
// called by: main
// 
// 
// 
// this is the basis for the linked list  *  
// ********************************************************
class NumberList 
{ private:
    struct ListNode
        {
            string value; // all doubles replaced with string
            struct ListNode * next;
        };
        ListNode *head;
  public:
    NumberList()
        {
            head=nullptr;
        }
    ~NumberList(); // there is an issue there
    void appendNode(string);
    void reverseList();
    int insertNode(string,int);
    int deleteNode(int);
    int searchList(string);
    void displayList() const;
};
#endif