#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
  srand((unsigned int) time(NULL));
  int n = (rand() % 100) + 1; 
  int guess = 0;
  do
  {
    cout<<"Enter a num from 1 to 100 : ";
    cin>>guess;

    if (guess > n) cout<<"Guess is high"<<endl;
    else if (guess < n) cout << "Guess is low"<<endl;
    else cout<<"Guess is correct"<<endl;
  } 

  while (guess != n);
  return 0;
}