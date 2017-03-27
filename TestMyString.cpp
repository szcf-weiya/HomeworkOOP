# include "MyString.h"
# include <iostream>
# include <fstream>
# include <string>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# define MAX_WORD_LENGTH 30
using namespace std;

bool ispunctuation(char ch)// judge punctuation
{
  if(((ch>=97)&&(ch<=122))||((ch>=65)&&(ch<=90))||((ch>=48)&&(ch<=57)))
    return 0;
  else if ((ch==',')||(ch=='.')||(ch=='?')||(ch=='!')||(ch==':')||(ch=='(')||(ch==')')||(ch=='\"')||(ch=='|')||(ch==';')||(ch=='-'))
    return 1;
  else 
    return 0;
}


int main()
{  
  FILE *fp;
  //  FILE *fwp;
  char ch;
  MyString str1("es");
  MyString str2("wh");
  MyString str3("con");
  MyString str4("the");
  MyString str5("fore");
  MyString str6("tell");
  MyString str7("shed");
  MyString str8("nag");

  MyString* strArray = new MyString[400];
  
  int num_es = 0;
  int num_wh = 0;
  int num_con = 0;
  int num_the = 0;
  int num_fore = 0;
  int num_tell = 0;
  int num_shed = 0;
  int num_nag = 0;
  int i = 0, j = 0;
  char * term;
  int space_num = 0;
  MyString longest_word;
  fp = fopen("data.txt", "r");
  //  fwp = fopen("MyStringResult.txt", "w+");
  ofstream fout("MyStringResult.txt");
  while((ch = fgetc(fp)) != EOF){
    term = (char*)malloc(sizeof(char)*MAX_WORD_LENGTH);
    while ((ch==' ')||(ispunctuation(ch))||(ch=='\n')||(ch=='\t'))
      {
	if (ch == ' ')
	  {
	    if (space_num == 0)
	      fout << ' ';
	    space_num ++;
	  }
	if (ispunctuation(ch))
	  fout << ' '; 
	ch = fgetc(fp);
      }
    space_num = 0; // the space num, only remain one space

    if (ch==EOF) // finish reading
      break;
    i = 0;
    while ((ch!=' ')&&(!ispunctuation(ch))&&(ch!='\n') && (ch!='\t')){
      //      str.append(ch);
      term[i] = ch;
      i++;
      ch = fgetc(fp);
    }
    term[i] = '\0';
    fout << term;
    //    fwrite(term, 1, strlen(term), fwp);

    if (ispunctuation(ch))
      fout << ch;
    else if(ch == ' ')
      {
        fout << ' ';
	space_num++;
      }
    
    MyString tmp(term);
    if (tmp.length() > longest_word.length())
      longest_word = tmp; //record the longest word
    bool isSub = false;
    if (tmp.find("es") != -1){
      num_es++;
      isSub = true;
    }
    if (tmp.find("wh") != -1){
      num_wh++;
      isSub = true;
    }
    if (tmp.find("con") != -1){
      num_con++;
      isSub = true;
    }
    if (tmp.find("the") != -1){
      num_the++;
      isSub = true;
    }
    if (tmp.find("fore") != -1){
      num_fore++;
      isSub = true;
    }
    if (tmp.find("tell") != -1){
      num_tell++;
      isSub = true;
    }
    if (tmp.find("shed") != -1){
      num_shed++;
      isSub = true;
    }
    if (tmp.find("nag") != -1){ 
      num_nag++;
      isSub = true;
    }
    
    if (isSub){
      strArray[j] = tmp; // store the words contains these substring
      j++;
    }
      
     
  }

  // bubble sort
  for (int k1 = 0; k1 < j - 1; k1++)
    {
      bool isSorted = true;
      for (int k2 = 0; k2 < j - 1 - k1; k2++)
	{
	  if (strArray[k2] > strArray[k2+1])
	    {
	      isSorted = false;
	      MyString tmp = strArray[k2];
	      strArray[k2] = strArray[k2+1];
	      strArray[k2+1] = tmp;
	    }
	}
      if (isSorted) break;
    }
  fout << "\n--------------------------" <<endl;
  fout << "Number of each substring:" <<endl;
  fout << "num_es: " << num_es << "\n"
       << "num_wh: " << num_wh << "\n"
       << "num_con: " << num_con << "\n"
       << "num_the: " << num_the << "\n"
       << "num_fore: " << num_fore << "\n"
       << "num_tell: " << num_tell << "\n"
       << "num_shed: " << num_shed << "\n"
       << "num_nag: " << num_nag << endl;
  fout << "----------------------------" << endl;
  fout << "Output in dictionary order: " << endl; 
  MyString tmp = strArray[0];
  fout << strArray[0] << endl;
  for (int k = 1; k < j; k++)
    {
      tmp = strArray[k-1];// avoid print the same word
      if (strArray[k] == tmp)
	continue;
      fout << strArray[k] << endl;
    }
    
  fout << "----------------------------" << endl;
  fout << "Longest word: "
       << longest_word << endl;
  fclose(fp);
  fout.close();
  return 0;
}
