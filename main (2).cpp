/**********************************************************************************************************
 * Chatper 9 Review Assignment-Pointers : June 24 2020  - Menu Driven program with pointers
**************************************************************************************************************//
#include <iostream>
#include <iomanip>
using namespace std;
// global constatns and fucntion prototypes
const int ELEMENTS=25; 
void showmenu(); 
void swapcol(char*); 
void showarray(char *); 
void showvowel(char *); 
void showchar(char *); 


int main()
{
    int menuNumber; // Number chosen by user
    const int INTERCHANGE =1,// constants for menu choices
              DISPLAYVOWEL=2,
              DISPLAYARRAY=3,
              SEARCHFORCHAR=4,
              THEEXITCHOICE=5;
    char words[ELEMENTS]={  's','w','e','e','t', // declaration of 25 element array with requested words
                            'h','e','a','r','t',  
                            'e','g','r','i','t',
                            'c','l','o','n','e',
                            'o','d','o','r','s'};
    char * point; //pointer declaration
    point = words; // pointer assignment
   
    
    
    do{
        showmenu(); 
        cin>>menuNumber;
        
        while(menuNumber< INTERCHANGE || menuNumber >THEEXITCHOICE) // corrects the user if they make an invalid choice
        { cout<<"Pleases pick a valid choice: ";
             cin >> menuNumber;
        }
        
        if(menuNumber != THEEXITCHOICE) // choice 1-4 options
        { 
            switch(menuNumber)
            {
                case INTERCHANGE: // choice 1 interchanging
                    swapcol(point);
                    break;
                case DISPLAYVOWEL:// choice 2 displaying the vowel
                    showvowel(point);
                    break;
                case DISPLAYARRAY: // choice 3 showing the array
                    showarray(point);
                    break;
                case SEARCHFORCHAR: // this choice searches for a given character in the given array
                    showchar(point);
                    break;
                
            }
        }
        
        } while(menuNumber != THEEXITCHOICE);
            cout<<"Goodbye........";
            return 0;
}
// ********************************************************
// name:      showmenu
// called by: main
// passed:    none
// returns:   nothing
// calls:     nothing
// The showmenu displays the menu options for the user    *
// ********************************************************

void showmenu()
{
    cout<<"\nMenu\n"
        << "1. Interchange column 1 with column 4\n"
        << "2. Display the total number of vowels\n"
        << "3. Display the array in a matrix (rows and columns)\n"
        << "4. Search for and display the number of instances of any given character\n"
        << "5. Exit\n"
        << "Enter your choice: ";
}
// ********************************************************
// name:      showarray
// called by: main
// passed:    char * point
// returns:   nothing
// calls:     nothing
// The showarray function prints out the array for the user*
// ********************************************************

void showarray(char * point)
{   
   
    for ( int i = 0; i < ELEMENTS; i++ )
      {

        cout <<setw(4)<< *(point + i) << " "; 
        if(i==4||i==9||i==14||i==19||i==24)
        {
            cout<<"\n";
        }
        else continue;
      }
    
    
}
// ********************************************************
// name:      showvowel
// called by: main
// passed:    char * point
// returns:   nothing
// calls:     nothing
// The showvowel function iterates through the  array and  *
// counts the number of vowels that are present          *
// ********************************************************
void showvowel(char * point) // this counts the vowels in the passed array
{   int count=0;
  
        for(int y=0;y< ELEMENTS; y++)
        { char t;
            t= *(point + y); 
            if(t=='a'||t=='e'||t=='i'||t=='o'||t=='u') // adds to count if any of these requirements are met
            {
            count=count+1;
            
            }
            else
            continue;
        }
    
    cout<<"The number of vowels are: "<<count<<endl; // printing out the total number of vowels
}
// ********************************************************
// name:      showchar
// called by: main
// passed:    char * point
// returns:   nothing
// calls:     none
// The showchar function iterates through the    *
//  array and finds the specific char the user desires *
// ********************************************************
void showchar(char*point)
{   char temp;
    int count=0;
    cout<<"Please type the char you'd like to search for: ";
    cin >> temp; // prompting the user to type in the character they want to search for
    int y=0;
    
        for(int y=0;y< ELEMENTS; y++)
        { char t =*(point + y);
            if(t== temp) // comparing the current element to the char they want to search for
            {
            count=count+1;
            //cout<< "current count is "<< count<< endl;
            }
            else
            continue;
        }
    
    cout<<" "<<temp<<" occurs: "<< count<<" time(s)";
}
// ********************************************************
// name:      swapcol
// called by: main
// passed:    char * point
// returns:   nothing
// calls:     nothing
// The swapcol fucntion swaps what APPEARS To be the "first and 4th columns"  *  
// ********************************************************
void swapcol(char * point)
{
    int y=0;
    int z=3;
    char temp;
    for(int x=0;x<5;x++) // iterates through the rows
    {   
        temp= *(point + y);  //  swaps the 1st and 4th elements respective to the current row
        *(point + y)=*(point + z);
        *(point + z)= temp;
        y+=5;
        z+=5;
        
    }
    cout<<"Done swapping columns-----"; // letting the user know that the swapping process is done
    
}




