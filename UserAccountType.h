#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <list>
#include <iomanip>

using namespace std ; 
class UserAccountType{
        protected:
        string  userId ; 
        string encrypted_password ;
        string FirtsName ; 
        string LastName ;  
        public : 
        UserAccountType() ; 
        UserAccountType (string, string, string, string) ; 
        void setUserId(string) ; 
        void setFirstName(string) ; 
        void setLastName(string); 
        void setPassword(string) ; 
        string getUserId() ; 
        bool isCompleteUserAccount() ; 
        string encryptPassword(string ) ;
        void printUserInfo() ; 
        bool isValidPassword(string pw) ;  
};
// BIG (O) == O(1)
UserAccountType::UserAccountType(){
        userId = "" ; 
        encrypted_password = "" ; 
        FirtsName = "" ; 
        LastName = "" ; 
        
}
// BIG (O) == O(1)
UserAccountType::UserAccountType (string us , string pass , string f , string l ) {
        userId = us ; 
        FirtsName = f ; 
        LastName = l ; 

        if(isValidPassword(pass)){
               encrypted_password =  encryptPassword(pass) ; 
          
        }
        else {
                cout << "!!!!!! Invalid Password !!!!!!!, Your password Will be set to null"<<endl ; 
        pass = "" ; 
        }
        // still not write is viild password  

}
// BIG (O) == O(1)
 void UserAccountType::setUserId(string us ) {
         userId = us ; 

 }
 // BIG (O) == O(1)
void UserAccountType::setFirstName(string f ) {
         FirtsName = f ; 
} 
// BIG (O) == O(1)
void UserAccountType:: setLastName(string l ){
        LastName = l ; 
} 
// BIG (O) == O(1)
void UserAccountType:: setPassword(string pass ) {
                if(isValidPassword(pass)){
               encrypted_password =  encryptPassword(pass) ; 
          
        }
        else {
                cout << "!!!!!! Invalid Password !!!!!!!, Your password Will be set to null" <<endl ;
        pass = "" ; 
        }


} 
// BIG (O) == O(1)
string UserAccountType::getUserId(){
        return userId ; 
}
// BIG (O) == O(1)
bool UserAccountType::isCompleteUserAccount(){
        if (userId==""||encrypted_password==""||FirtsName==""||LastName=="")
        return false ; 
        return true ; 
}
// BIG (O) == O(n)

string UserAccountType::encryptPassword(string x ) {
        list<char> s  ;
        list<char> st  ;
        queue<char> qu  ;
        stack <char> stac  ;
        queue<char> queu  ;



        
        for (int i = 0 ; i < x.size() ; i ++) {
                s.push_back(x[i]) ; 
        }
        char a = s.front() ; // a
        char b = s.back() ; //d 
        s.pop_back() ; 
        s.pop_front() ;
        s.push_back(a) ; 
        s.push_front(b) ; 
        for(auto it :s)
         qu.push(it) ;
          
         /*while (!qu.empty()){
                 cout << qu.front() ; 
                 qu.pop() ;
         }
         */
         
         while (!qu.empty()){
                 int a , b , c  ; 
                 a = qu.front() ;
                 qu.pop() ; 
                 b = qu.front()%10 ;
                 c = a+b ; 
                 st.push_back(c) ; 
                  
                  

         }
         
            int i = 0 ; 
         int e = st.size() ; 
         while(!st.empty()){
                 stac.push(st.front()) ;
                 if(i==e&&e%2==1)
                 break ; 
                 i+=2 ; 
                 st.pop_front() ;
                 queu.push(st.front()) ; 
                 st.pop_front(); 
                if (i == e-1)
                i++;
         }
         string us ; 
         
        while(!stac.empty()){
                 us+=stac.top() ; 
                 stac.pop() ; 
                 us+=queu.front() ; 
                 queu.pop() ; 
         }
         return us ; 
        

}
// BIG (O) == O(1)
void UserAccountType:: printUserInfo(){
            cout<< left<< setw(10)<<userId << left<< setw(5)<<FirtsName << "  "<< left
       << setw(8)
        << LastName
        << left
        << setw(5)
        << encrypted_password
        << endl;


        
        
}
// BIG (O) == O(n)

bool UserAccountType::isValidPassword(string pw) {
        bool b  = true ;
        int conterdig = 0 ;
        int contersy = 0 ;   
        int n = pw.size() ; 
        for (int i  = 0 ; i < n ; i ++ ){
                if (n<6||n>8)
                b = false ; 
                else if (isdigit(pw[i]))
                conterdig++ ; 
                else if (pw[i]=='#'||pw[i]=='*'||pw[i]=='$')
                contersy++ ; 

        }
        if (conterdig!=1||contersy!=1)
        b =  false ; 
        if (b)
        return true ; 
        return false ; 
}  