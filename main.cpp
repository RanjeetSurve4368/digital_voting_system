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
      // loginCheck();
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
  
      // Convert string to appropriate types
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
    void CountVotes(){
      cout<<"Please Enter id of Candidate you want to count votes of"<<endl;
      int idToCount;
      cin>>idToCount;
      cout<<"Please Enter name of Candidate you want to count votes of"<<endl;
      string nameToCount;
      cin>>nameToCount;
      vector <cDetails> candidates;
      ifstream infile("candidates.txt");
      
  
      if (!infile) {
          cout << "Error opening file!" << endl;
          return;
      }
      string line;
      bool found=false;
      while(getline(infile,line)){
        stringstream ss(line);
        string idStr,nameStr,voteCountStr;
        getline(ss,idStr,',');
        getline(ss,nameStr,',');
        getline(ss,voteCountStr,',');

        int id=stoi(idStr);
        int voteCount=stoi(voteCountStr);
        if (id == idToCount && nameStr == nameToCount) {
          cout << "Candidate '" << nameStr << "' with ID " << id << " has " << voteCount << " votes." << endl;
          found = true;
          break;
      }
    }
    infile.close();

    if (!found) {
        cout << "Candidate not found with provided details." << endl;
    }

    getoptions();
  }

};

class Voter{
  public:
  int Vid,Vpassword;
  string Vname;
  void login(){
    cout<<"Please Enter your voter id: "<<endl;
    // int Vid;
    cin>>Vid;
    cout<<"Please enter voter name: "<<endl;
    // string Vname;
    cin>>Vname;
    cout<<"Please enter your password"<<endl;
    // int Vpassword;
    cin>>Vpassword;
    loginCheck(Vid,Vname,Vpassword);
    
  }
  void loginCheck(int Vid,string Vname, int Vpassword){
    vector <vDetails> voters;
      ifstream infile("voters.txt");
      
  
      if (!infile) {
          cout << "Error opening file!" << endl;
          return;
      }
      string line;
    bool checked = false;

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
  
      if (v.id == Vid && v.password == Vpassword && v.name == Vname) {
          checked = true; 
          getoption();
          break;
      } 

      
  }
  }
  void getoption(){
    cout<<"Welcome for voting please click 1 to vote "<<endl;
    int Voption;
    cin>>Voption;
    if(Voption==1){
      getVote();
    }
  }

  void getVote(){
    vector <vDetails> voters;
      ifstream infile("voters.txt");
      
  
      if (!infile) {
          cout << "Error opening file!" << endl;
          return;
      }
      string line;
    bool voted = false;

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
  
      if (v.id==Vid && v.name==Vname && v.password==Vpassword) {
          if(v.status==true){
            cout<<"You already voted";
          }
          else{
            // cout<<"Helo world";
            candidateList();
          }
          
      } 

      
  }
  }
  void candidateList(){
    cout<<"Following are names of candidates"<<endl;
    vector <cDetails> candidates;
      ifstream infile("candidates.txt");  
      if (!infile) {
          cout << "Error opening file!" << endl;
          return;
      }
      string line;
      while(getline(infile,line)){
        stringstream ss(line);
        string idStr,nameStr,voteCountStr;
        getline(ss,idStr,',');
        getline(ss,nameStr,',');
        getline(ss,voteCountStr,',');
       
        cout<<"id: "<<idStr<<" Name: "<<nameStr<<endl;
    }
    infile.close();
    voteForCandidate();
    
  }
  void voteForCandidate(){
    int chosenId;
    cout << "Enter the ID of the candidate you want to vote for: ";
    cin >> chosenId;

    // Step 1: Update vote count in candidates.txt
    vector<cDetails> candidates;
    ifstream infile("candidates.txt");
    string line;

    if (!infile) {
        cout << "Error opening candidates file!" << endl;
        return;
    }

    while (getline(infile, line)) {
        stringstream ss(line);
        string idStr, nameStr, voteCountStr;
        getline(ss, idStr, ',');
        getline(ss, nameStr, ',');
        getline(ss, voteCountStr, ',');

        cDetails c;
        c.id = stoi(idStr);
        c.name = nameStr;
        c.voteCount = stoi(voteCountStr);

        if (c.id == chosenId) {
            c.voteCount += 1;
        }

        candidates.push_back(c);
    }
    infile.close();

    ofstream outfile("candidates.txt");
    for (auto& c : candidates) {
        outfile << c.id << "," << c.name << "," << c.voteCount << "\n";
    }
    outfile.close();

    // Step 2: Update voter's status in voters.txt
    vector<vDetails> voters;
    ifstream vinfile("voters.txt");

    if (!vinfile) {
        cout << "Error opening voters file!" << endl;
        return;
    }

    while (getline(vinfile, line)) {
        stringstream ss(line);
        string idStr, nameStr, passwordStr, statusStr;
        vDetails v;

        getline(ss, idStr, ',');
        getline(ss, nameStr, ',');
        getline(ss, passwordStr, ',');
        getline(ss, statusStr, ',');

        v.id = stoi(idStr);
        v.name = nameStr;
        v.password = stoi(passwordStr);
        v.status = (statusStr == "1" || statusStr == "true");

        if (v.id == Vid && v.name == Vname && v.password == Vpassword) {
            v.status = true;
        }

        voters.push_back(v);
    }
    vinfile.close();

    ofstream voutfile("voters.txt");
    for (auto& v : voters) {
        voutfile << v.id << "," << v.name << "," << v.password << "," << v.status << "\n";
    }
    voutfile.close();

    cout << "Vote cast successfully!" << endl;
}
};

void login(){
  int login1;
  cout<<"If you want to login as voter please enter 1 and if you want to login as admin please enter 0"<<endl;
  cin>>login1;
  if(login1==1) {
    Voter a;
    a.login();
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
