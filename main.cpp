#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct vDetails{
 int id;
 string name;
 int password;
 bool status;
};

struct cDetails{
 int id;
 string name;
 int voteCount;
};

struct aDetails{
 int id;
 string name;
 int password;
};
void voterlogin(){
  
}



class Admin{
vector<aDetails> Admins={
{1,"Ranjeet",1111},
{2,"God",2222} };

 public: 
    int id,password;
    string name;

    // void Admin(int i,int pass,string n){ 
    //  id=i;
    //  password=pass;
    //  name=n;

    void getinput(){
      cout<<"Enter your name: "<<endl;
      cin>>name;
      cout<<"Enter your id: "<<endl;
      cin>>id;
      cout<<"Enter your password: "<<endl;
      cin>>password;
    }
    bool loginCheck(int id, int password, string name){
     for(&auto admin: Admins){
      if(admin.id=id && admin.password=password && admin.name=name){
      cout<<"Welcome "<<name<<" to make changes";
     }
    }
      
};
void login(){
  int login1;
  cout<<"If you want to login as voter please enter 1 and if you want to login as admin please enter 0"<<endl;
  cin>>login1;
  if(login1==1) {
    voterlogin();
  }
  else if(login1==0){
    adminlogin();
  }
  else{
    cout<<"check your choice and enter again";
    login();
  }
}

int main(){
  long long id;
  cout<< "WELCOME TO DIGITAL VOTING SYSTEM "<< endl;
  login();
  
  
  return 0;
}
