/*
  Write a complete C++ program that does the following.
  (Programs that correctly carry out some of the tasks will
  receive partial credit.)
*/

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
  /* 1. It asks the user to enter a positive integer value, x. */
  int x;
  cout << "enter a positive integer value: " << endl;

  /*
    2. The program reads a value entered by the user. If the value is not positive,
    the program repeatedly makes the user type in another value
    until a positive value of x has been entered.
    (Note positive means greater than 0.)
  */
  cin >> x;
  while(x <= 0){
    cout << "The value you entered was illegal. Re-enter: " << endl;
    cin >> x;
  }

  /*
    3. The program prints an x × x square pattern of ∗ symbols
    in such a way that rows and columns are separated by
    rows and columns of − symbols.
    For example, if the user enters 3 for x the program
    should print the following pattern
    (there are 3 rows and 3 columns that contain ∗’s,
    but there are other rows and columns with only −’s).

    *-*-*
    -----
    *-*-*
    -----
    *-*-*
  */

    for(int n=0; n<x-1;n++){

      /* draw *'s here */
      for(int i=0; i<x;i++){
        if(i < (x-1))
          cout << "*-";
        else
          cout << "*";
      }
      cout << endl;

      /* draw separator here */
      for(int k=0;k<x*2-1;k++){
        cout << "-";
      }
      cout << endl;
    }

  return 0;
}
