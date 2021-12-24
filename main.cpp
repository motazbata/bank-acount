#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <list>
#include <iomanip>
#include "UserAccountListType.h"


using namespace std ; 

 

int main() {
    int x ; 
   string fi ,us_id ; 

   UserAccountListType a  ;  
   UserAccountType  newItem  ; 

    START:
    system("clear");
    cout<< "\t\t   ===================================\n";
    cout<< "\t\t\tWELCOME TO MAJESTIC BANK\n";
    cout<< "\t\t   THIS PROGRAM TEST AS AN BANK \n";
    cout<< "\t\t   ===================================\n";
     
    cout<< "\n\nIF YOU DON'T HAVE ANY ACCOUNT YET, YOU CAN REGISTER NOW!\n\n";

    cout << "(1) - REGISTER NEW ACCOUNT \n(2) - SEARCH USER ACCOUNT\n(3) - DELETE FROM LIST\n(4) - SHOW THE LIST \n(5) - EXIT FROM PROGRAMMING\nOption: ";

    cin >> x ; 
    switch (x)
    {
    case 1:{
     system("clear");
        cout<< "--Creating a new user account and adding it to the user account list...\n";
        cout << "Please enter user's id:\n"  ; 
        cin >> fi ; 
        newItem.setUserId(fi) ; 
         cout << "Please enter user's First Name:\n"  ; 
         cin >> fi ; 
        newItem.setFirstName(fi) ;
         cout << "Please enter user's Last Name:\n"  ; 
         cin >> fi ; 
         newItem.setLastName(fi) ; 
         cout << "Please enter a password, a valid password should consist of 6-8 charachter.the password should that consists of letter one one digit and one of the symbols (*,#,$)\n"  ; 
         cin >> fi ; 
        newItem.setPassword(fi) ; 
        a.insertUserAccount(newItem) ; 
       LAPEL8:
 cout<< "YOU WANT BACK TO MENU ?\n yes or no  \n";
        cin >> us_id ; 
        if (us_id=="yes")
        goto START;
        else 
        goto LAPEL8 ;     
        break;
    }

    case 2:{
        
        cout<< "ENTER USER_ID TO FIND ACCOUNT \n";
        cin >> us_id ; 
        LAPEL:
        a.printInfo_of_UserId(us_id) ;
        cout<< "YOU WANT BACK TO MENU ?\n yes or no  \n";
        cin >> us_id ; 
        if (us_id=="yes")
        goto START;
        else 
        goto LAPEL ; 
        
 


        break;
    }
    case 3:{
       cout<< "ENTER USER_ID TO DELETE ACCOUNT \n";
       cin >>fi ; 
       a.deleteUserAccount(fi) ; 
       LAPEL1:
        cout<< "YOU WANT BACK TO MENU ?\n yes or no  \n";
        cin >> us_id ; 
        if (us_id=="yes")
        goto START;
        else 
        goto LAPEL1 ; 



            
            
    
    
        break;
    }
    case 4:{
  cout<< left<< setw(10)<< "USER"<< left<< setw(5)<<"FIRST   "<< left
       << setw(8)
        << "LAST"
        << left
        << setw(5)
        << "PASS"
        << endl << endl ;
        a.print() ; 
        LAPEL2:
        cout<< "YOU WANT BACK TO MENU ?\n yes or no  \n";
        cin >> us_id ; 
        if (us_id=="yes")
        goto START;
        else 
        goto LAPEL2 ; 

            break ; 

    }
    case 5:{
            return 0 ; 
    }

    default:
        cout<< "Sorry wrong input. Please try again.\n\n";
        goto START ; 
        break;
    }



}         

 