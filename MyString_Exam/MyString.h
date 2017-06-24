#ifndef MYSTRING_H
#define MYSTRING_H

#include<iostream>
using namespace std;

class MyString{
  friend ostream& operator<<(ostream&, MyString&);
  friend istream& operator>>(istream&, MyString&);
 public:
  MyString(const char* str = NULL);
  MyString(const MyString &other);
  MyString& operator=(const MyString& other);
  bool operator==(const MyString&);
  char& operator[](unsigned int);
  size_t size();
  ~MyString();
 private:
  char* m_data;
};


#endif
