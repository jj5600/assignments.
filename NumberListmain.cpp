/******************************************************************************
 * Joseph Marquez- Linked Lists - Chapter 18

*******************************************************************************/
#include <iostream>
#include"NumberList.h"
#include<algorithm>
#include <string.h>
#include<stdlib.h>
#include<iomanip>
using namespace std;
//function prototypes
string stringmatch(string);
void showmenu();
void append();



int main()
{   
    int menuNumber; //Number chosen by user
    string x; // random testing variables
    int t,test;
    string s1;
    const int APPEND=1, //values for menu choice
              INSERT=2,
              DELETE=3,
              PRINT=4,
              REVERSE=5,
              SEARCH=6,
              EXIT=7;
        NumberList list;  //object
  do{ 
      showmenu();
      cin>>menuNumber;
      while(menuNumber< APPEND || menuNumber >EXIT) // corrects user if they make an improper choice
        {
            cout<<"Please Pick a valid choice";
        }
      if(menuNumber!= EXIT) // proceeds to where user desires
      {
          switch(menuNumber)
          {
              case APPEND:
                cout<<"Please enter a color\n";
                cin>>s1; // accepting a string from a user
                x=stringmatch(s1); // high level validation point to make sure user is typing in valid color
                list.appendNode(x); // the returned value is then passed to the mutator
                 break;
              case INSERT:
                cout<<"Insert a string: ";
                cin>>s1;
                cout<<"please enter a position: ";
                cin>>t;
                x=stringmatch(s1); // high level string validation
                test=list.insertNode(x,t); // Hl validation put into mutator
                if(test==-1) // if mutator returns -1 then...
                    { cout<<"Im sorry there is no position "<<t<<" in the linked list";
                    }
                break;
              case DELETE:
                cout<<"Insert a position to delete: ";
                cin>>t;
                test=list.deleteNode(t); //only low level validation here as specified by prompt
                break;
              case PRINT:
                list.displayList(); // basic function to display list
                break;
              case REVERSE:
                list.reverseList(); // reverse list
                cout<<"Done......\n";
                break;
              case SEARCH:
                cout<<"Please enter a string: ";
                cin>>s1; // string validation again (high level) then fed to mutator
                x=stringmatch(s1);
                list.searchList(x);
                break;
          }
          
      }
        
        }while(menuNumber != EXIT); // if user chooses exit then exit
            cout<<"Goodbye........";
            return 0;
}
// ********************************************************
// name:      showmenu
// called by: main
// passed:    nothing
// returns:   nothing
// calls:     nothing
// displays the menu with all the options for the user *  
// ********************************************************
  
void showmenu()
{
    cout<<"\nMenu\n"
        << "1. Append\n"
        << "2. Insert\n"
        << "3. Delete\n"
        << "4. Print\n"
        << "5. Reverse\n"
        << "6. Search\n"
        << "7. Exit\n"
        <<"Please choose a menu option:";
}
// ********************************************************
// name:      stringmatch
// called by: main
// passed:    string s1
// returns:   s1
// calls:     nothing
// this function takes user input converts it to lower case 
//the compares it to the three acceptable colors and returns it *  
// ********************************************************
string stringmatch(string s1) 
{ 
    const string s2="blue";
    const string s3="red";
    const string s4="yellow";
   transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
  
   while(s1.compare(s2) != 0 && s1.compare(s3) != 0 && s1.compare(s4) !=0)
   {    cout<<"**You did not input a valid color \n";
        cout<<"Please input a valid color :";
        cin>>s1;
       transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
   }
    
    
    return s1; 
 
}
