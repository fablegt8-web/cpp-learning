#include <iostream>
using namespace std;

// Function prototypes
void dollarline();
void starline();
void hashline();
void message();

int main()
{
    cout << "This is dollar line" << endl;
    dollarline(); // call function

    cout << "This is star line" << endl;
    starline(); // call function

    cout << "This is hash line" << endl;
    hashline(); // call function

    message(); // call function

    return 0;
}

// Function definitions
void dollarline()
{
    cout << "$$$$$$$$$$$$$$$$$$$" << endl;
}

void starline()
{
    cout << "*******************" << endl;
}

void hashline()
{
    cout << "###################" << endl;
}

void message()
{
    cout << "This is a user-defined function example!" << endl;
}
