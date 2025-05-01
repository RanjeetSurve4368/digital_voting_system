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
vector<aDetails> Admins={
{1,"Ranjeet",1111},
{2,"God",2222} }

void adminlogin(){
  int Enterid, Enterpassword;
  string Entername;
  cout<<"Enter your name: "<<endl;
  cin>>Entername;

  cout<<"Enter your id: "<<endl;
  cin>>Enterid;

  cout<<"Enter your password: "<<endl;
  cin>>Enterpassword;

  for(auto& admin: admins){
    if(admin.id==Enterid && admin.name==Entername && admin.password==Enterpassword){
      cout<<"Welcome "<<Entername<< endl;
      cout<<"Please choose what you want to do from below options";
}
void login(){
  int login1;
  cout<<"If you want to login as voter please enter 1 and if you want to login as admin please enter 0";
  cin<<login1;
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
