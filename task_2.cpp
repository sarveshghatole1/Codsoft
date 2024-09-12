#include <iostream>
using namespace std;

int main()
{
    int choice;
    do
    {
        cout << "Calculator\n";

        int op1, op2;
        cout << "Enter operand 1: "; 
        cin >> op1;
        cout << "Enter operand 2: "; 
        cin >> op2;

        cout << "Choose an operation:\n";
        cout << "1. Addition\n";
        cout << "2. Subtraction\n";
        cout << "3. Multiplication\n";
        cout << "4. Division\n";
        cout << "5. Exit\n"; 

        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 5) 
        {
            cout << "Exiting the calculator.\n";
            break; 
        }

        cout << "Result: ";

        switch (choice)
        {
            case 1:
                cout << op1 + op2;
                break;
            case 2:
                cout << op1 - op2;
                break;
            case 3:
                cout << op1 * op2;
                break;
            case 4:
                if (op2 != 0)
                    cout << op1 / op2;
                else
                    cout << "Error: Division by zero";
                break;
            
        }
      cout <<endl;   
    }
     
    while (true); 
    return 0;
}