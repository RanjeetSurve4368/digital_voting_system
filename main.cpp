#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
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
     cout<<"Enter name of new voter"<<endl;
     cin>>newVoter.name;
     cout<<"Enter id of new voter"<<endl;
     cin>>newVoter.id;
     cout<<"Enter password of new voter"<<endl;
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
     getoptions();

    }
   void DeleteVoter(){
    int idToDelete;
    cout<<"Enter id of voter you want to delete"<<endl;
    cin>>idToDelete;
    int passwordToDelete;
    cout<<"Enter password of voter you want to delete"<<endl;
    cin>>passwordToDelete;
    
    vector<vDetails> voters;
    ifstream infile("voters.txt");
    ofstream tempFile("temp.txt");

    if (!infile || !tempFile) {
        cout << "Error opening file!" << endl;
        return;
    }

    string line;
    bool deleted = false;

    while (getline(infile, line)) {
      stringstream ss(line);
      string idStr, nameStr, passwordStr, statusStr;
      vDetails v;
  
      getline(ss, idStr, ',');
      getline(ss, nameStr, ',');
      getline(ss, passwordStr, ',');
      getline(ss, statusStr, ',');
  
      // Convert string to appropriate typesRanjee
      v.id = stoi(idStr);
      v.name = nameStr;
      v.password = stoi(passwordStr);
      v.status = (statusStr == "1" || statusStr == "true"); // handle true/false or 1/0
  
      if (v.id == idToDelete && v.password == passwordToDelete) {
          deleted = true; // Skip this voter
      } else {
          tempFile << v.id << "," << v.name << "," << v.password << "," << v.status << "\n";
      }
  }

    infile.close();
    tempFile.close();

    remove("voters.txt");
    rename("temp.txt", "voters.txt");

    if (deleted){
        cout << "Voter deleted successfully." << endl;
        getoptions();}
    else{
        cout << "Voter not found or credentials incorrect." << endl;
        DeleteVoter();}
   } 
   void AddCandidate(){
    cDetails newCandidate;
     cout<<"Enter name of new Candidate"<<endl;
     cin>>newCandidate.name;
     cout<<"Enter id of new Candidate"<<endl;
     cin>>newCandidate.id;
     newCandidate.voteCount=0;

     ofstream outfile("Candidates.txt",ios::app);
      if(!outfile){
      cout<<"Error openeing file"<<endl;
      return;
     }
     outfile << newCandidate.id << "," << newCandidate.name << "," << newCandidate.voteCount << "\n";
     outfile.close();

     cout << "Candidate added successfully!" << endl;
     getoptions();

    }
    void DeleteCandidate(){
     int idToDelete;
    cout<<"Enter id of Candidate you want to delete"<<endl;
    cin>>idToDelete; 
    vector<cDetails> candidates;
    ifstream infile("candidates.txt");
    ofstream tempFile("temp.txt");

    if (!infile || !tempFile) {
        cout << "Error opening file!" << endl;
        return;
    }

    string line;
    bool deleted = false;

    while (getline(infile, line)) {
      stringstream ss(line);
      string idStr, nameStr, voteCountStr;
      cDetails v;
  
      getline(ss, idStr, ',');
      getline(ss, nameStr, ',');
      getline(ss, voteCountStr, ',');
  
      // Convert string to appropriate typesRanjee
      v.id = stoi(idStr);
      v.name = nameStr;
      v.voteCount = stoi(voteCountStr); 
  
      if (v.id == idToDelete) {
          deleted = true; // Skip this voter
      } else {
          tempFile << v.id << "," << v.name << "," << v.voteCount << "\n";
      }
  }

    infile.close();
    tempFile.close();

    remove("candidates.txt");
    rename("temp.txt", "candidates.txt");

    if (deleted){
        cout << "Candidate deleted successfully." << endl;
        getoptions();}
    else{
        cout << "Candidate not found or credentials incorrect." << endl;
       DeleteCandidate();}
     
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
