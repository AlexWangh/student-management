#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class student{
    int user_id;
    string name;
    string password;
    string title;
    int request_id;
    bool isActive;

    vector<string> information;
    vector<string> subjects;
    

    void login();
    void logout();
    void initPassword();
    void showsubs();
    void requestjoin();
    void drop();
    void student_interface();

    ~student(){
        //先找student id；

        ifstream myFile;
        myFile.open("students.csv");


        while (myFile.good()){
            string line;
            getline (myFile,line,',');    
            information.push_back(line);       
        }

        user_id=stoi(information[0],nullptr,10);
        name=information[1];
        password=information[2];
        title=information[3];

        for (int k=4;k<information.size();k++) {
            subjects.push_back(information[k]);
        }
    }

    void create_account(string no){
        cout<<no;
        int id;
        string pass3;
        cout<<"Please write down your user id: ";
        cin>>id;
        if (/*id找得到*/){
            cout<<"Please set your password:";
            cin>>pass3;
            student_interface();
        }
        else{
            string no;
            no="Cannot find your id";
            create_account(no);
        }
    }


    void login(string wrong_or_true){
        int id;
        string pass;

        cout<<wrong_or_true;

        cout<<"Enter your user_id: ";
        cin>>id;

        cout<<"Enter your password: ";
        cin>>pass;
        
        if (pass==password && id==user_id){
            student_interface();
        }
        else {        
            string wrong;
            wrong="Your user id or password is incorrect";            
            login(wrong);
        }
    }

    void student_interface(){
        int num;
        cout<<"1. show subjects"<<endl;
        cout<<"2. Request to join course"<<endl;
        cout<<"3. Drop course"<<endl;
        cout<<"4. Initial your password"<<endl;
        cout<<"5. Log out"<<endl;
        cout<<endl;
        cout<<"Enter your choice";
        cin>>num;

        if (num==1){
            showsubs();
        }
        else if (num==2){
            requestjoin();
        }
        else if (num==3){
            drop();
        }
        else if (num==4){
            initPassword();
        }
        else if (num==5){
            logout();
        }
        else {
            student_interface();
        }
    }
    
    void initPassword(){
        string new_pass;
        int num;
        cout<<"Enter your new password: ";
        cin>>new_pass;

        password=new_pass;
        cout<<"1. exit";
        if(num==1){
            student_interface();
        }
    };

    void showsubs(){
        for (string&i : subjects) {
            cout << i << endl;
        }
    }

    void requestjoin(){
        string courseid;

        cout<<"Please select the course you want to join: ";
        cin>>courseid;

        //1.怎么让tutor同意
        //2.怎么加在course的最后面？
        //当老师下次打开时会自动收到申请
        subjects.push_back(courseid);
    }

    void drop(){
        string drop_course;
        int num=0;
        bool find=0;

        cout<<"Please select the course you want to drop: ";
        cin>>drop_course;
        for (string& i : subjects) {
            if (i==drop_course){
                subjects.erase(subjects.begin()+num);
                find=true;
                break;
            }
            num++;
        }
        if (find=true){
            int choose;
            cout<<"Do you want to drop another course?"<<endl;
            cout<<"1.Yes"<<endl;
            cout<<"2.No"<<endl;
            cin>>choose;
            if (choose==1){
                drop();
            }
            else{
                student_interface();
            }
        }
        else{
            drop();
        }

        //找他的这门课
        //找到之后，把这门课去掉
    }
    
    void logout(){
        //把信息记下来
        ofstream myFile;
        myFile.open("student.csv");
        myFile<<user_id<<","
            <<name<<","
            <<password<<","
            <<title<<",";
        
        for (int i=0;i<subjects.size();i++){
            myFile<<subjects[i]<<",";
            //重新写myfile会不会新起一行？
        }
        <<"\n";
    }
    //退到主页面

};