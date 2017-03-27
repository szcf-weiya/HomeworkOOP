#include "MyString.h"
#include <string.h>

// no-args constructor
MyString::MyString()
{
  str = new char[1];
  str[0] = '\0';
}

// c-string constructor

MyString::MyString(const char *input)
{
  if (input == NULL)
    {
      str = new char[1];
      str = '\0';
    }
  else
    {
      int len = strlen(input) + 1;
      str = new char[len];
      strcpy(str, input);
    }
}

// copy constructor

MyString::MyString(const MyString &s)
{
  int len = strlen(s.str) + 1;
  str = new char[len];
  strcpy(str, s.str);
}

// destructor
MyString::~MyString(void)
{
  delete [] str;
}

// assign

MyString& MyString::operator = (const char *s)
{
  int length = strlen(s);
  delete [] str;
  str = new char[length+1];
  str = strcpy(str, s);
  str[length] = '\0';
  return *this;
  }

MyString& MyString::operator = (const MyString& s)
{
  if (this == &s)
    return *this;
  delete[] str;
  int len = strlen(s.str);
  str = new char[len + 1];
  strcpy(str, s.str);
  return *this;
}
//MyString 

// length
int MyString::length()
{
  return strlen(str);
}

// +
MyString operator + (const MyString &s1, const MyString &s2)
{
  int length = strlen(s1.str) + strlen(s2.str) + 1;
  char *tmp = new char[length];
  for (int i = 0; i < strlen(s1.str); i++)
    tmp[i] = s1.str[i];
  int j = 0;
  for (int k = strlen(s1.str); k < (length-1); k++,j++)
    tmp[k] = s2.str[j];
  tmp[length-1] = '\0';
  MyString s3(tmp);
  delete [] tmp;
  return s3;
}

// ==
bool operator == (const MyString& s1, const MyString& s2)
{
  if (strcmp(s1.str, s2.str) == 0)
    return true;
  else
    return false;
}

// < 
bool operator < (const MyString& s1, const MyString& s2)
{
  if (strcmp(s1.str, s2.str) < 0)
    return true;
  else
    return false;
}

bool operator > (const MyString& s1, const MyString& s2)
{
  if (strcmp(s1.str, s2.str) > 0)
    return true;
  else
    return false;
}

// <<
ostream& operator << (ostream& os, const MyString & s)
{
  os << s.str;
  return os;
}

// >>
istream& operator >> (istream& is, MyString & s)
{
  char *input = new char[100];
  is.getline(input, 100);
  int len = strlen(input) + 1;
  strcpy(s.str, input);
  delete [] input;
  return is;
}

// empty
bool MyString::empty()
{
  if (strlen(str) == 0)
    return true;
  else
    return false;
}

// at
char& MyString::at(int loc)
{
  return str[loc-1];
}

// substr
MyString MyString::substr(int index, int length)
{
  int size = length + 1;
  char *tmp = new char[size];
  int j = 0;
  for (int i = index, j = 0; i < length; i++, j++)
    tmp[j] = str[i];
  if (tmp[size-1] != '\0')
    tmp[size-1] = '\0';
  MyString res;
  delete [] res.str;
  res.str = new char[size];
  for (int m = 0; m < (size - 1); m++)
    res.str[m] = tmp[m];
  if (res.str[size-1] != '\0')
    res.str[size-1] = '\0';
  delete tmp;
  return res;
}

// compare
int MyString::compare(const MyString& s)
{
  return strcmp(str, s.str);
}

/*
 MyString::append(const char ch)
{
  int size = strlen(str) + 2;
  MyString res;
  delete [] res.str;
  res.str = new char[size];
  for (int i = 0; i < strlen(str) - 1; i++)
    res.str[i] = str[i];
  res.str[strlen(str)] = ch;
  res.str[strlen(str)+1] = '\0';
  strcpy(str, res.c_str());
  delete [] res;
}
*/

char* MyString::c_str()
{
  if (str == NULL)
    return '\0';
  else
    return str;
}

int MyString::find(const char* s)
{
  char* res = strstr(str, s);
  if (res)
    return ((this->length() - strlen(s)));
  else
    return -1;
}
