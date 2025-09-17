#include <iostream>
using namespace std;
int main()
{
    int x = 10;
    int y = 20; //variable declaration and initialization
    int sum = x + y; //sum of two var
    cout << sum; //output of the sum

    //double (number including decimal points)
    double price = 5.50;
    double gpa = 4.0;
    cout << price;

    //char (single characters)
    char grade = 'A';
    char initial = 'B';
    char symbol = '!';
    cout<< grade; // can only store single characters

    //boolean (only two states which are true and false)
    bool power = true;
    bool student = false;
    bool answer = false;

    //string (represents a sequence of characters or text)
    string name = "john";
    string fullname = "john alibaba";
    string address = "111 chinatown";
    cout<< "hello  " << name << endl;
    cout<< "your gpa is  " << gpa << endl;
 

    return 0;
}