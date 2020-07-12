#include "NumberList.h"
#include<string.h>
#include<stdlib.h>
#include<iomanip>
// ********************************************************
// name:      appendNode .cpp
// called by: main
// passed:    string num
// returns:   -1
// calls:     nothing
// function adds a node at the end of the linked List *  
// ********************************************************
void NumberList::appendNode(string num)
{   if(num!="red"&&num!="yellow"&&num!="blue")
        { cout<<"*NOT a valid color *";
             exit (EXIT_FAILURE);
        }
    else
    {
            ListNode *newNode;
            ListNode *nodePtr;
            newNode= new ListNode;
            newNode->value=num;
            newNode->next =nullptr;
        if(!head)
        head=newNode;
       
        
        else
            {
            nodePtr=head;
            while(nodePtr->next)
            nodePtr=nodePtr->next;
            nodePtr->next=newNode;
            }
    }
}
// ********************************************************
// name:      displaylist
// called by: main
// passed:    nothing
// returns:   nothing
// calls:     nothing
// The displaylist traverses the linked list and displays the output  *  
// ********************************************************
void NumberList::displayList() const 
    {
        ListNode *nodePtr; 
        nodePtr = head;

        while (nodePtr)
        {
            cout << nodePtr->value << endl;
            nodePtr = nodePtr->next; 
    
        }
    }
    
// ********************************************************
// name:      insetnode
// called by: main
// passed:    string num, int b
// returns:   -1
// calls:     nothing
// This function inserts a node at a designated spot of the LL *  
// ********************************************************
int NumberList::insertNode(string num,int b)
{      if(num!="red"&&num!="yellow"&&num!="blue")
        { cout<<"*NOT a valid color *";
             exit (EXIT_FAILURE);
        } 
    
    int count=0;
        int smallc=0;
        int z=0;
    if (z==0)
    {   ListNode *nodePtr;
        nodePtr=head;
      while (nodePtr)
        {
        nodePtr = nodePtr->next; 
        smallc++;
        }
        
        
    }
   if(smallc-1<b)
        {return -1;
        }
   else{
        ListNode *newNode;
        ListNode *nodePtr;
        ListNode *previousNode = nullptr;
        newNode = new ListNode;
        newNode->value=num;

    if(!head)
        {
            head=newNode;
            newNode->next = nullptr;
         }
    
    else
    {  
        nodePtr = head;
        previousNode = nullptr;
        while(nodePtr != nullptr && count<b)
        {
            previousNode =nodePtr;
            nodePtr=nodePtr->next;
            count++;
        }
        
        if(previousNode == nullptr)
        {
            head =newNode;
            newNode->next = nodePtr;
    
        }
        else
        {
            previousNode->next = newNode;
            newNode->next = nodePtr;
            
        }
    }
   }
}
// ********************************************************
// name:      deleteNode
// called by: main
// passed:    int num
// returns:   -1
// calls:     nothing
// deltenode deltes a specified node in the LL  *  
// ********************************************************
int NumberList::deleteNode(int num)
{   int count=0;
    int smallc=0;
    int z=0;
    if (z==0)
        {   ListNode *nodePtr;
            nodePtr=head;
        while (nodePtr)
            {
            nodePtr = nodePtr->next; 
            smallc++;
            }
        
        }
    
    ListNode * nodePtr;
    ListNode * previousNode;
    if(!head)
       {cout<<"the linked list is empty";
      return -1;}
      
    if(num==0) 
    {
        nodePtr = head->next;
        delete head;
        head=nodePtr;
         
    }
   
    else
    {
        nodePtr=head;
        while(nodePtr!=nullptr && count!=num)
        {
            previousNode=nodePtr;
            nodePtr=nodePtr->next;
            count++;
            
        }
        if(nodePtr)
        {
            previousNode->next=nodePtr->next;
            delete nodePtr;
            
        }
    }
   
 }
 // ********************************************************
// name:     ~NumberList
// called by: main
// passed:    nothing
// returns:   nothing
// calls:     nothing
// The ~NumberList is the destructor function *  
// ********************************************************
NumberList::~NumberList()   
{
    ListNode * nodePtr;
    ListNode * nextNode;
    nodePtr=head;
    while(nodePtr != nullptr)
    {
        nextNode =nodePtr->next;
        delete nodePtr;
        nodePtr=nextNode;
        
        
    }
}
// ********************************************************
// name:      reverseList
// called by: main
// passed:    nothing
// returns:   nothing
// calls:     nothing
// reverselist reverses the linked list  *  
// ********************************************************
void NumberList::reverseList() 
{  ListNode * nodePtr=head;
    ListNode * nextNode=nullptr;
    ListNode * previousNode=nullptr;
     
  
        while (nodePtr != nullptr) 
        { 
           
            nextNode = nodePtr->next; 
            nodePtr->next = previousNode; 
            previousNode = nodePtr; 
            nodePtr = nextNode; 
        }
        head=previousNode;
        
} 
    // ********************************************************
// name:      searchlist
// called by: main
// passed:    string num
// returns:   nothing
// calls:     nothing
// this function searches for color specified by a user 
// ********************************************************
int NumberList::searchList(string num)
{   int count=0;
    int othercount=0;
    ListNode *nodePtr; 
 nodePtr = head;
cout<<"Location(s) are: ";
while (nodePtr)
{  
    if(nodePtr->value==num)
    { cout<<count<<" ";
         othercount++;
    }

    count++;
    nodePtr = nodePtr->next; 
    if(othercount==0)
    {
        cout<<"None";
    }
    
}
    
  
}  
    
    
    



