#include "MyString.h"
#include <cstring>
#include <iostream>
#include <iomanip>
using namespace std;

MyString::MyString(const char* str)
{
  if(!str)
    m_data = NULL;
  else
    {
      int slen = strlen(str);
      m_data = new char[slen+1];
      //      strcpy_s(m_data, slen+1, str);
      strcpy(m_data, str);
    }
}


MyString::MyString(const MyString &other)
{
  if (!other.m_data)
    m_data = NULL;
  else
    {
      int slen = strlen(other.m_data);
      m_data = new char[slen+1];
      //      strcpy_s(m_data, slen+1, other.m_data);
      strcpy(m_data, other.m_data);
    }
}

MyString::~MyString()
{
  delete [] m_data;
}

MyString& MyString::operator=(const MyString& other)
{
  if (this != &other)
    {
      delete [] m_data;
      if(!other.m_data) m_data = 0;
      else
	{
	  int slen = strlen(other.m_data);
	  m_data = new char[slen+1];
	  //strcpy_s(m_data, slen+1, other.m_data);
	  strcpy(m_data, other.m_data);
	}
    }
  return *this;
}

bool MyString::operator==(const MyString &s)
{
  if (strlen(s.m_data) != strlen(m_data))
    return false;
  return strcmp(m_data, s.m_data) ? false : true;
}

char& MyString::operator[](unsigned int e)
{
  if (e >= 0 && e <= strlen(m_data))
    return m_data[e];
}

size_t MyString::size()
{
  return strlen(m_data);
}

ostream& operator<<(ostream& os, MyString& str)
{
  os << str.m_data;
  return os;
}

istream& operator>>(istream& is, MyString& s)
{
  char temp[255];
  is >> setw(255) >> temp;
  s = temp;
  return is;
}

