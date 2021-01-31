#include <iostream>
#include <fstream>
using namespace std;
int main(){
  ofstream write;
  ifstream read;
  string str1;
  write.open("data.csv",ios::app);
  read.open("data.csv");
  write<<"Usama"<<","<<"Is"<<","<<"Good"<<endl;
  while(!read.eof()){
  read>>str1;
  cout<<str1;
}
  read.close();
  write.close();

  // string name,roll,sec,var;
  // int marks;
  // ofstream write,write1;
  // write.open("data.csv");
  // write1.open("update.csv");
  // ifstream read;
  // //cin.ignore();
  // cout<<"Enter name "<<endl;
  // getline(cin,name);
  // cout<<"Enter roll number "<<endl;
  // getline(cin,roll);
  // cout<<"Enter section "<<endl;
  // getline(cin,sec);
  // cout<<"Enter marks "<<endl;
  // cin>>marks;
  // if(write.is_open())
  // write<<roll<<","<<name<<","<<sec<<","<<marks<<endl;
  // else
  // cout<<"File is not fount";
  // write.close();
  // read.open("data.csv");
  // getline(read,var);
  // cout<<var<<endl;
  // write1<<var;
  // write1.close();
  // rename(
}
