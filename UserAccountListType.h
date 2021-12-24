#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <list>
#include <iomanip>
#include "UserAccountType.h"

using namespace std ; 
// BIG (O) == O(1)

class UserAccountNode{
        public :
        UserAccountType user_account ;
        UserAccountNode *link ;  
};
class UserAccountListType{
        private:
        UserAccountNode *first ; 
        UserAccountNode *last ; 
        int conter ; 
        public:
        UserAccountListType () ; 
        ~UserAccountListType () ; 
        void destroyList() ; 
        void print() const ; 
        bool IsUserIdExist(string ud); 
        void insertUserAccount(const UserAccountType newItem);
        void deleteUserAccount(string ud);
        void printInfo_of_UserId(string user_id);


};
// BIG (O) == O(1)

UserAccountListType::UserAccountListType () {
        conter = 0 ; 
        first = last = NULL  ; 

}
// BIG (O) == O(n)

UserAccountListType::~UserAccountListType () {
        destroyList() ; //if the list has any nodes, delete them
         


}
// BIG (O) == O(n)

void UserAccountListType::destroyList() {
        UserAccountNode *p ; 
while (first != NULL){
      p = first;
     first = first->link;
      delete p;
}
   last = NULL;
    conter = 0;
}
// BIG (O) == O(n)

 void UserAccountListType:: print() const {
                 UserAccountNode *p = first ; 
                 while(p!=NULL){
                         p->user_account.printUserInfo();
                         p=p->link; 

                 }
                 cout << endl ; 


 }
 // BIG (O) == O(n)

bool UserAccountListType:: IsUserIdExist(string ud){
        UserAccountNode *p = first ; 
        while (p!=NULL){
                if (p->user_account.getUserId()==ud)
                return true ; 
                p = p->link;
        }
        return false ; 

  
}
// BIG (O) == O(n)

 void UserAccountListType::insertUserAccount(const UserAccountType newItem){
          
               UserAccountNode *p = new UserAccountNode ; 
               p->user_account=newItem ; 

               if (p->user_account.isCompleteUserAccount()) {
                      if (!IsUserIdExist(p->user_account.getUserId())) {
                        if (first == NULL){ //if list is empty, newNode is the only node
                              first = p;
                             last = p;
                             conter++;
                }

                       last->link=p ; 
                       last = p ; 
                       p->link = NULL ; 
                       conter++ ; 
                       }
                       else 
                       cout << "this user_id is found here before .  try another one " << endl  ; 
               }
               else 
               cout << "this user account is incomplete and cannot be inserted in the list" << endl ; 
               
 }
 // BIG (O) == O(n)

void UserAccountListType:: deleteUserAccount(string ud){
        bool found = false  ; 
        UserAccountNode *p = first ;
        UserAccountNode *q = first->link ; 
        if (first == NULL)
          cout << "Cannot delete from an empty list." << endl; 

                 else {
                 if (first->user_account.getUserId()==ud) { // the id first node 
                         p = first ; 
                         first = first->link ; 
                         conter-- ; 
                         if (first == NULL) //the list has only one node
                         last = NULL;
                        delete p;

                 }

              else {
        while (q != NULL && !found){
                if(q->user_account.getUserId()!=ud){
                p = q ; 
                q=q->link ; 
                }
                else 
                found = true ; 
              }//end while 
              if (found){
                p->link = q->link ; 
                conter-- ; 
                if (last==q) // the id last node 
                last = p ; 
                delete q ; 
                
              }
              else 
              cout << "The item to be deleted is not in "
              << "the list." << endl;
              

        }
                 }

        


}
// BIG (O) == O(n)

void UserAccountListType:: printInfo_of_UserId(string user_id){
        UserAccountNode *p = first ;
        bool found = false  ; 

        while (p!=NULL&& !found){
                if (p->user_account.getUserId()==user_id)
                found = true ; 
                else 
                p = p->link ; 
        }
        if(found)
        p->user_account.printUserInfo() ; 
        else 
        cout << "the id not found " << endl; 

} 