#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
#include "student.cpp"

class tutor{
    string name;
    string password;
    string title;
    int user_id;
    bool isActive;
    vector<string> new_subs;

    void login();
    void logout();
    void initPassword();
    void changePassword();
    void resetUserPassword();
    void addNewStudent();
    void modifyStudent();
    void showSubjects();
    void showStudents();
    void lockOrUnlockUser();
    void addCommentOfUserRequest(studentid);

    void login(){

    }

    void initPassword(){

    }

    void changePassword(){
        string pass;
        cout<<"Type your new password: ";
        cin>>pass;
        password=pass;
        cout<<"Your new password had been set successful;"<<endl;
    }

    void resetUserPassword(){
        string new_password;
        int id;

        cout<<"Type the user id of the student whose password you want to change: ";
        cin>>id;

        cout<<"Type the new password: ";
        cin>>new_password;

        ifstream myFile;
            myFile.open("student.csv");
            while (myFile.good()){
                string line;
                getline(myFile,line,',');
                int num_line=stoi(line,nullptr,10);
                if (id==num_line){
                    //找到这一行的password并让它等于new_password
                }
        
            }
    }
    void addNewStudent(){

        fstream fout;
        fout.open("ex1.csv", std::ios::out | std::ios::app);
        int new_userid;


        cout<<"Type the user id of the sudent that you want to add: ";
        cin>>new_userid;

        while (true){
            string course_id;
            cout<<"Type the id subjects of the sudent that you want to add (if it is done, type end to return): ";
            cin>>course_id;
            if (course_id=="end"){
                break;
            }
            new_subs.push_back(course_id);
        }

        // Insert the data to file
        fout << new_userid << ", "
            <<"!!"<<","
            <<"!!"<<","
            <<"!!"<<","
            for 

            << "\n";

    }

    void lockOrUnlockUser(){
        int id;
        int choose; 
        cout<<"Enter the user id of the student that you want to lock or unlock: ";
        cin>>id;
        cout<<endl;
        cout<<"1. Lock"<<endl;
        cout<<"2. Unlock"<<endl;
        cout<<"Choose 1 or 2: ";
        cin>>choose;

        if (choose==1){
            ifstream myFile;
            myFile.open("student.csv");
            while (myFile.good()){
                string line;
                getline(myFile,line,',');
                int num_line=stoi(line,nullptr,10);
                if (num_line==id){
                    //把他这个密码改了？
                }
                        else{
            
                }
            }




    }


    void addCommentOfUserRequest(studentid){
        ifstream myFile;
        myFile.open("students.csv");
        while (myFile.good()){
            string line;
            getline(myFile,line,',');
            int num_line2=stoi(line,nullptr,10);
            if(num_line2==studentid){

            }
            else{
                
            }
        }
    }
};