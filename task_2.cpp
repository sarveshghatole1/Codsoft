#include<iostream>
using namespace std;
int main()
{
    cout<<"calculator\n";

    int op1 , op2;
    cout<<"Enter operand 1 : "; cin>>op1;
    cout<<"Enter operand 2 : "; cin>>op2;


    cout<<"Choose an operation : \n";
    cout<<"1. Addition\n";
    cout<<"2. Subtraction\n";
    cout<<"3. Multiplication\n";
    cout<<"4. Division\n";
    
    int choice;
    cout<<"Enter choice : ";
    cout<<"Result : ";
    cin>>choice;
    switch(choice)
    {
        case 1 :
        {
            cout<<op1 + op2;
            break;
        }
        case 2 :
        {
            cout<<op1 - op2;
            break;
        }
        case 3 :
        {
            cout<<op1 * op2;
            break;
        }
        case 4 :
        {
            cout<<op1 / op2;
            break;
        }
    }
    return 0;
}