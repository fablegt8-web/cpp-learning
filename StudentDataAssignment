#include <stdio.h>
#include <iostream>
#include <vector>
#include <iterator>


struct subsruct {
    std::string subjname;
    int mark;
};

struct Student_info {
    std::string id;
    std::string name;
    std::vector<subsruct> subjects; // An additional Array used to store Student score for several subjects dynamically
};

bool check(std::string studentId, std::vector<Student_info> Database){
    for(int i=0; i<Database.size(); i++){
        if(studentId == Database[i].id) return true;
    }
    
    return false;   
}

void display(std::string studentId, std::vector<Student_info> Database){
    bool userfound = false;
    for(int i=0; i<Database.size(); i++){
        if(Database[i].id == studentId){
            userfound = true;
            std::cout << "Id: \t" << Database[i].id << std::endl;
            std::cout << "Name: \t" << Database[i].name << std::endl;
            
            std::cout << "======Subjects======" << std::endl;
            if(Database[i].subjects.size() == 0){
                std::cout << "please enter 'update' during the prompt to add a subject" << std::endl;
                break;
            }
            for(int j=0; j<Database[i].subjects.size(); j++){
                std::cout << "Subject Name: \t\t" << Database[i].subjects[i].subjname << std::endl;
                std::cout << "Mark: \t\t\t" << Database[i].subjects[i].mark << std::endl;
            }
            break;
        }
    }
    if(!userfound){
        std::cout << "user not found, enter the 'input' command within the prompt to add new user." << "\n";
    }
}

void update(std::string studentId, std::vector<Student_info> &Database){
    for(int i=0; i<Database.size(); i++){
        if(Database[i].id == studentId){
            std::string uinput;
            do {
                std::string subjname;
                bool subjfound = false;
                std::cout << "enter a subject name: ";
                std::cin >> subjname;
                std::cout << std::endl;
                
                for(int j=0; j<Database[i].subjects.size(); j++){
                    if(Database[i].subjects[j].subjname == subjname){
                        subjfound = true;
                        int markinp;
                        
                        std::cout << "the subject " << subjname << " has been found " << std::endl << "please enter the mark: ";;
                        std::cin >> markinp;
                        
                        Database[i].subjects[j].mark = markinp;
                        
                        std::cout << "the subject has been updated!" << std::endl;
                        return;
                    }
                }
                if(!subjfound){
                    std::string addsubj;
                    std::cout << "subject not found would you like to insert a new subject?\n(y/n): ";
                    std::cin >> addsubj;
                    std::cout << std::endl;
                    
                    if(addsubj=="y"){
                        int subjmarkinp;
                        std::cout << "input the subject's mark: ";
                        std::cin >> subjmarkinp;
                        std::cout << "subject has been added!" << std::endl;
                        Database[i].subjects.push_back({subjname, subjmarkinp});
                        
                        
                        std::cout << "would you like to continue?" << std::endl << "(y/n): ";
                        std::cin >> uinput;
                        std::cout << std::endl;
                        
                        if(uinput == "y"){
                            continue;
                        } else if (uinput == "n"){
                            std::cout << "operation has been aborted" << std::endl;
                            break;
                        } else {
                            std::cout << "unknown input entered, operation has been aborted" << std::endl;
                            break;
                        }
                    } else if(addsubj=="n"){
                        std::cout << "operation aborted..." << std::endl;
                        break;
                    } else {
                        std::cout << "unkown input enter, operation aborted.." << std::endl;
                        break;
                    }
                }
            } while(true);
        }
    }
}

void findbest(std::string subjectName, std::vector<Student_info> &Database){
    struct student_a {
        std::string name;
        std::string id;
        int mark;
    };
    
    std::vector<student_a> student_array;
    
    // inserting every valid entries for the subject
    for(int i=0; i<Database.size(); i++){
        for(int j=0; j<Database[i].subjects.size(); j++){
            if(Database[i].subjects[j].subjname == subjectName){
                student_array.push_back({Database[i].name, Database[i].id, Database[i].subjects[j].mark});
                // std::cout << "======Best mark for " << subjectName << " subject======\n";
                // std::cout << "name\t\t" << "id\t\t" << "mark\n";
                // std::cout << Database[i].name << "\t\t" << Database[i].id << "\t\t" << Database[i].subjects[j].mark << "\n";
            }
        }
    }
    
    // sorting the entries
    for(int i=0; i<student_array.size(); i++){
        for(int j=i; j<student_array.size(); j++){
            // if array[j].mark > student_array[i].mark
            if(student_array[j].mark > student_array[i].mark){
                student_a temp = student_array[j]; //creates a copy of the intended destination
                student_array[j] = student_array[i]; //array[i] changes position with array[j]
                student_array[i] = temp; //copy is inserted into array[i] position
            } else if(student_array[j].mark < student_array[i].mark){
                continue;
            } else {
                continue;
            }
        }
    }
    std::cout << "======Best mark for " << subjectName << " subject======\n";
    for(int i=0; i<student_array.size(); i++){
        std::cout << "name\t\t" << "id\t\t" << "mark\n";
        std::cout << student_array[i].name << "\t\t" << student_array[i].id << "\t\t" << student_array[i].mark << "\n";
    }
}

void input(std::vector<Student_info> &Database) {
    Student_info newStudent;
    
    std::cout << "please enter a student id: ";
    std::cin >> newStudent.id;
    std::cout << std::endl;
    
    bool res = check(newStudent.id, Database);
    if(res) {
        std::cout << "user already exist";
        return;
    }
    
    std::cout << "please enter a student name: ";
    std::cin >> newStudent.name;
    std::cout << std::endl;
    
    char answer;
    std::cout << "are you sure the following is true?" << std::endl 
              << "Student id: " << newStudent.id << std::endl 
              << "Student name: " << newStudent.name << std::endl 
              << "(y/n): ";
    std::cin >> answer;
    
    switch(answer){
        case 'y': 
            std::cout << "new user (" << newStudent.id << ") has been created and saved in the Database!";
            Database.push_back(newStudent);
            break;
        case 'n':
            std::cout << "the operation has been cancelled..";
            break;
        default:
            std::cout << "the operation has been cancelled due to an unknown prompt";
            break;
    }
    
    std::cout << std::endl;
}

void help(){
    std::cout << "here's a list of available prompt, there's no need to enter an argument\n";
    std::cout << "input\t\t\t" << "add a new student to the database\n";
    std::cout << "display\t\t\t" << "display student's info\n";
    std::cout << "update\t\t\t" << "update a student's subject\n";
    std::cout << "help\t\t\t" << "output this text\n";
    std::cout << "findbest\t\t" << "find the student with best grade in a specific subject\n";
}


int main(){
    std::vector<std::string> Students_names; // A one-dimensional Array used to store Student names dynamically
    std::vector<Student_info> Database; // Database used to store student datas dynamically
    
    
    do {
        std::cout << "prompt your input: ";
        std::string function_type;
        std::cin >> function_type;
        
        std::cout << std::endl;
        // user can input student's id if 'input' is entered in the prompt
        if(function_type == "input"){
           input(Database);
        } else if (function_type == "display"){
           std::string studentId;
           std::cout << "enter student Id: ";
           std::cin >> studentId;
           std::cout << std::endl;
           display(studentId, Database);
        } else if (function_type == "update"){
           std::string studentId;
           std::cout << "enter student Id: ";
           std::cin >> studentId;
           std::cout << std::endl;
           
           update(studentId, Database);
        } else if (function_type == "help"){
            help();
        } else if (function_type == "findbest"){
            std::string subjectName;
            std::cout << "enter a subject name: ";
            std::cin >> subjectName;
            std::cout << std::endl;
            findbest(subjectName, Database);
        } else {
            std::cout << "unknown prompt, try 'help'" << std::endl;
        }
        
    } while (true);

}
