#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>
using namespace std;
class MyString
{
  
 public:
  MyString(void); //no-args constructor
  MyString(const char *input); // 
  MyString(const MyString &s);  //copy constructor
  ~MyString(void);

  int length(); //the length of string
  char& at(int location); // returns a character at specified location-1
  bool empty();
  int find (const char* s);
  char* c_str();
  MyString substr(int index, int length); //returns a substring
  //  void append(char ch);
  int compare (const MyString& s);//  Return a value greater than 0, 0, or less than 0 if this string is greater than, equal to, or less than s.  
  
  friend bool operator == (const MyString & s1, const MyString & s2);
  friend bool operator < (const MyString & s1, const MyString & s2);
  friend bool operator > (const MyString & s1, const MyString & s2);
  friend MyString operator + (const MyString &s1, const MyString &s2);
  friend ostream& operator << (ostream& os, const MyString &s);
  friend istream& operator >> (istream& is, MyString& s);

  MyString &operator = (const MyString &s);
  MyString &operator = (const char* s);

 private:
  char *str;                      //store the string
};

#endif
