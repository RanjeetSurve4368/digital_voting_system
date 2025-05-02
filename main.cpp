#include <iostream>
#include <string>
#include <vector>
#include <fstream>
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
    int Eid,Epassword;
    string Ename;

    // void Admin(int i,int pass,string n){ 
    //  id=i;
    //  password=pass;
    //  name=n;

    void getinput(){
      cout<<"Enter your name: "<<endl;
      cin>>Ename;
      cout<<"Enter your id: "<<endl;
      cin>>Eid;
      cout<<"Enter your password: "<<endl;
      cin>>Epassword;
      loginCheck(Eid,Epassword,Ename);
    }
    bool loginCheck(int id, int password, string name){
     for(auto& admin: Admins){
      if(admin.id==Eid && admin.password==Epassword && admin.name==Ename){
      cout<<"Welcome "<<name<<" to make changes"<<endl;
      cout<<"Please Choose options below "<<endl;
      cout<<"1.Add Voter"<<endl;
      cout<<"2.Delete Voter"<<endl;
      cout<<"3.Add Candidate"<<endl;
      cout<<"4.Delete Candidate"<<endl;
      cout<<"5.Count Votes"<<endl;
      getoptions();
     }
     else{
      cout<<"Please Check your info and try again";
      getinput();
     }
    }
    }
    void getoptions(){
     int option;
     cin>>option;
     if(option==1){
      AddVoter();
     }
     else if(option ==2){
      DeleteVoter();
     }
     else if(option == 3){
      AddCandidate();
     }
     else if(option == 4){
      DeleteCandidate();
     }
     else if(option == 5){
      CountVotes();
     }
     else{
      cout<<"Please choose valid option";
      loginCheck();
     }
    }
    void AddVoter(){
     vDetails newVoter;
     cout<<"Enter name of new voter";
     cin>>newVoter.name;
     cout<<"Enter id of new voter";
     cin>>newVoter.id;
     cout<<"Enter password of new voter";
     cin>>newVoter.password;
     newVoter.status= false;

     ofstream outfile("voters.txt",ios::app);
      if(!outfile){
      cout<<"Error openeing file"<<endl;
      return;
     }
     outfile << newVoter.id << "," << newVoter.name << "," << newVoter.password << "," << newVoter.status << "\n";
     outfile.close();

     cout << "Voter added successfully!" << endl;

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
    Admin a;
    a.getinput();
    
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

};
