#include "MyString.h"
#include <iostream>
using namespace std;

int main()
{
  MyString str1 = "Aha!";
  MyString str2 = "My friend";
  MyString str3;
  if (!(str1 == str2))
    cout << str1 << " " << str2 << endl;
  cout << str1.size() << " " << str2.size() << endl;
  for (int i = 0; i <= str1.size(); i++)
    cout << str1[i] << endl;
}
