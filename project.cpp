#include "project.h"
#include<iostream>
using namespace std;
#include <fstream>
#include <cstdlib>
#include <limits>
project::project(){
  id = "";
  name = "";
  average_price = 0;
  sale_price = 0;
  quantity = 0;
}
void project::input1(){
  string str1,str2,str3,str4,str5;
  ifstream read;
  read.open("stock.csv");
  cout<<"Enter ID except of following ID's "<<endl;
  if(read.is_open()){
    while(!read.eof()){
    getline(read,str1,',');
    getline(read,str2,',');
    getline(read,str3,',');
    getline(read,str4,',');
    getline(read,str5,'\n');
    cout<<str1<<endl;
}
  }
  else{
    cout<<"File is not found "<<endl;
  }
  read.close();
}
void project::add_new_stock(){
  ofstream write;
  ifstream read;
  string str1,str2,str3,str4,str5;
  int var = 0;
  write.open("stock.csv",ios::app);
  read.open("stock.csv");
  cout<<"press enter to continue "<<endl;
  cin.ignore();
  cout<<"Enter ID :";
    getline(cin,id);
  if(read.is_open()){
    while(!read.eof()){

          getline(read,str1,',');
          getline(read,str2,',');
          getline(read,str3,',');
          getline(read,str4,',');
          getline(read,str5,'\n');
          if(str1==id){
            cout<<"This ID already exists "<<endl;
            input1();
            cout<<"Enter ID again:";
            getline(cin,id);
          }
          else{
            continue;
          }
    }
  }
  else{
    cout<<"File is not found"<<endl;
  }
  cout<<"Enter name :";
  getline(cin,name);
  cout<<"Enter qunatity :";
  cin>>quantity;
  cout<<"Enter average price :";
  cin>>average_price;
  cout<<"Enter sale price :";
  cin>>sale_price;
  while(cin.fail()){
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(),'\n');
  cout << "Invalid Number /";
  cout<<"Enter number again"<<endl;
  cout<<"Enter qunatity :";
  cin>>quantity;
  cout<<"Enter average price :";
  cin>>average_price;
  cout<<"Enter sale price :";
  cin>>sale_price;
  }


  write<<id<<","<<name<<","<<quantity<<","<<average_price<<","<<sale_price<<endl;
  write.close();
  read.close();
}
void project::update_stock(string id2){
  string str1,str2,str3,str4;
  ofstream write;
  ifstream read;
  write.open("update.csv");
  read.open("stock.csv");

   if(read.is_open()){
    while(!read.eof()){
      getline(read,id,',');
      getline(read,str1,',');
      getline(read,str2,',');
      getline(read,str3,',');
      getline(read,str4,'\n');
      if(id == id2){

        cin.ignore();
        cout<<"Enter 1 to continue "<<endl;
        cout<<"Enter new name :";
        getline(cin,name);
        cout<<"Enter new qunatity :";
        cin>>quantity;
        cout<<"Enter new average price :";
        cin>>average_price;
        cout<<"Enter new sale price :";
        cin>>sale_price;
        while(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Invalid Number /";
        cout<<"Enter number again"<<endl;
        cout<<"Enter new qunatity :";
        cin>>quantity;
        cout<<"Enter new average price :";
        cin>>average_price;
        cout<<"Enter new sale price :";
        cin>>sale_price;

        }
        write<<id<<","<<name<<","<<quantity<<","<<average_price<<","<<sale_price<<endl;
      }
      else if(id != ""){
          write<<id<<","<<str1<<","<<str2<<","<<str3<<","<<str4<<endl;
      }

     }
}
  else
  {
    cout << "file is not open" << '\n';
  }

  read.close();
  write.close();
   rename("update.csv","stock.csv");
}
void project::remove_stock(string id1){
  ifstream read;
  ofstream write;
  int var,var1;
  string str1,str2,str3,str4;
  read.open("stock.csv");
  write.open("update.csv");

   if(read.is_open()){
    while(!read.eof()){
      getline(read,id,',');
      getline(read,str1,',');
      getline(read,str2,',');
      getline(read,str3,',');
      getline(read,str4,'\n');
      if(id==id1){

        var = stoi(str2);
        if(var>0){
          cout<<"Quantity is not less than 1 :"<<"press 1 for continue or 2 for back "<<endl;
          cin>>var1;
                if(var1 != 1){
                  write<<id<<","<<str1<<","<<str2<<","<<str3<<","<<str4<<endl;
                  }
                else{

                  continue;
                    }
                  }
        else{
          continue;
        }
      }
        else if(id != ""){
          write<<id<<","<<str1<<","<<str2<<","<<str3<<","<<str4<<endl;
        }

      }
    }

  else
  cout<<"File is not found "<<endl;
  write.close();
  read.close();
  rename("update.csv","stock.csv");
}
void project::generate_stock_report(){
  ifstream read;
  int var;
  double var1,var2;
  string str1,str2,str3,str4;
  double total_items=0.0,total_quantity=0.0,all_average_price=0.0,all_sale_price=0.0;
  read.open("stock.csv");
  if(read.is_open()){
      while(!read.eof()){
        total_averager_price = 0;
        total_sale_price = 0;
        var =0;
        var1 =0;
        var2 =0;
        getline(read,id,',');
        getline(read,str1,',');
        getline(read,str2,',');
        getline(read,str3,',');
        getline(read,str4,'\n');
        if(id!=" " ){
        var = stoi(str2);
        var1 =stoi(str3);
        var2 = stoi(str4);
        total_averager_price = var * var1;
        total_sale_price = var* var2;
        if(id!=""){
        cout<<id<<"|"<<str1<<"|"<<str2<<"|"<<str3<<"|"<<total_sale_price<<"|"<<str4<<"|"<<total_sale_price<<endl;

        all_average_price += total_averager_price;
        all_sale_price += total_sale_price;
        total_items += 1;
        total_quantity += var;
        }
      }}

  }
  else{
    cout<<"File is not found"<<endl;
  }
  cout<<"Total number of items :"<<total_items<<endl;
  cout<<"Total number of quantity :"<<total_quantity<<endl;
  cout<<"Total total_averager_price :"<<all_average_price<<endl;
  cout<<"total_sale_price :"<<all_sale_price<<endl;
read.close();
cout<<endl;
cout<<endl;
}
void project::search_item(string id1){
  ifstream read;
  read.open("stock.csv");
  int var;
  double var1,var2;
  string str1,str2,str3,str4;
  if(read.is_open()){
      while(!read.eof()){
        total_averager_price = 0;
        total_sale_price = 0;
        var =0;
        var1 =0;
        var2 =0;
        getline(read,id,',');
        getline(read,str1,',');
        getline(read,str2,',');
        getline(read,str3,',');
        getline(read,str4,'\n');
        if(id==id1){
        var = stoi(str2);
        var1 =stoi(str3);
        var2 = stoi(str4);
        total_averager_price = var * var1;
        total_sale_price = var* var2;
        if(id!=""){
        cout<<id<<"|"<<str1<<"|"<<str2<<"|"<<str3<<"|"<<total_sale_price<<"|"<<str4<<"|"<<total_sale_price<<endl;
        break;
      }
  }

  else{
    //cout<<"This item is not found "<<endl;
    continue;
  }
 }


  }
  else{
    cout<<"File is not found"<<endl;
  }
  read.close();
  cout<<endl;
  cout<<endl;
}

void project::input(){
  string str1,str2,str3,str4,str5,str6,str7,str8;
  ifstream read;
  read.open("employ.csv");
  cout<<"Enter ID except of following ID's "<<endl;
  if(read.is_open()){
    while(!read.eof()){
    getline(read,str1,',');
    getline(read,str2,',');
    getline(read,str3,',');
    getline(read,str4,',');
    getline(read,str5,',');
    getline(read,str6,',');
    getline(read,str7,',');
    getline(read,str8,'\n');
    cout<<str1<<endl;
}
  }
  else{
    cout<<"File is not found "<<endl;
  }
  read.close();
}
void project::add_emp(){
  ofstream write;
  ifstream read;
  string str1,str2,str3,str4,str5,str6,str7,str8;
  int var = 0;
  write.open("employ.csv",ios::app);
  read.open("employ.csv");
  //cout<<"Enter 1 to continue "<<endl;
  cin.ignore();
  cout<<"Enter ID :";
    getline(cin,id);
  if(read.is_open()){
    while(!read.eof()){

          getline(read,str1,',');
          getline(read,str2,',');
          getline(read,str3,',');
          getline(read,str4,',');
          getline(read,str5,',');
          getline(read,str6,',');
          getline(read,str7,',');
          getline(read,str8,'\n');
          if(str1==id){
            cout<<"This ID already exists "<<endl;
            input();
            cout<<"Enter ID again:";
            getline(cin,id);
          }
          else{
            continue;
          }
    }
  }
  else{
    cout<<"File is not found"<<endl;
  }
  cout<<"Enter password :";
  getline(cin,password);
  cout<<"Enter name :";
  getline(cin,name);
  cout<<"Enter salary :";
  cin>>salary;
  while(cin.fail()){
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(),'\n');
  cout << "Invalid Number /";
  cout<<"Enter number again"<<endl;
  cin>>salary;
  }

  cin.ignore();
  cout<<"Enter contact number :";
  getline(cin,contact);
  cout<<"Enter CNIC :";
  getline(cin,cnic);
  cout<<"Enter address :";
  getline(cin,address);

  while(var!=1 && var!=2 &&var!=3){
  cout<<"Enter type :"<<endl;
  cout<<"1: Workers"<<endl;
  cout<<"2: Stock Management"<<endl;
  cout<<"3: Cashier"<<endl;
  cin>>var;
  while(cin.fail()){
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(),'\n');
  cout << "Invalid Number /";
  cout<<"Enter number again"<<endl;
  cin>>var;
  }
  if(var==1)
  type1 = "Workers";
  else if(var==2)
  type1 = "Stock Management";
  else if(var==3)
  type1 = "Cashier";
  else
  cout<<"You enter a wrong number "<<endl;
}
  write<<id<<","<<password<<","<<name<<","<<salary<<","<<type1<<","<<contact<<","<<cnic<<","<<address<<endl;
  write.close();
  read.close();
}
void project::update_emp_info(string id3){
  string str1,str2,str3,str4,str5,str6,str7;
  ofstream write;
  ifstream read;
  write.open("update.csv");
  read.open("employ.csv");

   if(read.is_open()){
    while(!read.eof()){
      getline(read,id,',');
      getline(read,str1,',');
      getline(read,str2,',');
      getline(read,str3,',');
      getline(read,str4,',');
      getline(read,str5,',');
      getline(read,str6,',');
      getline(read,str7,'\n');
      if(id == id3){

        cin.ignore();
        //cout<<"Enter 1 to continue "<<endl;
        cout<<"Enter new name :";
        getline(cin,name);
        cout<<"Enter new contact number :";
        getline(cin,contact);
        cout<<"Enter new address :";
        getline(cin,address);
        cout<<"Enter new salary :";
        cin>>salary;
        while(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Invalid Number /";
        cout<<"Enter number again"<<endl;
        cin>>salary;
        }

        write<<id<<","<<password<<","<<name<<","<<salary<<","<<type1<<","<<contact<<","<<cnic<<","<<address<<endl;
      }
      else if(id != ""){
          write<<id<<","<<str1<<","<<str2<<","<<str3<<","<<str4<<","<<str5<<","<<str6<<","<<str7<<endl;
      }

     }
}
  else
  {
    cout << "file is not open" << '\n';
  }

  read.close();
  write.close();
   rename("update.csv","employ.csv");
}
void project::remove_any_emp(string id4){
  ifstream read;
  ofstream write;
  int var,var1;
  string str1,str2,str3,str4,str5,str6,str7;
  read.open("employ.csv");
  write.open("update.csv");

   if(read.is_open()){
    while(!read.eof()){
      getline(read,id,',');
      getline(read,str1,',');
      getline(read,str2,',');
      getline(read,str3,',');
      getline(read,str4,',');
      getline(read,str5,',');
      getline(read,str6,',');
      getline(read,str7,'\n');
      if(id==id4){
          continue;
      }
        else if(id != ""){
          write<<id<<","<<str1<<","<<str2<<","<<str3<<","<<str4<<","<<str5<<","<<str6<<","<<str7<<endl;
        }

      }
    }

  else
  cout<<"File is not found "<<endl;
  cout<<"Data remove successfully "<<endl;
  write.close();
  read.close();
  rename("update.csv","employ.csv");
}
void cashier::input(){
  string str1,str2,str3,str4,str5;
  ifstream read;
  read.open("stock.csv");
  cout<<"The following are the Id's and names of items "<<endl;
  if(read.is_open()){
    while(!read.eof()){
    getline(read,str1,',');
    getline(read,str2,',');
    getline(read,str3,',');
    getline(read,str4,',');
    getline(read,str5,'\n');
    if(str1!="")
    cout<<str1<<"|"<<str2<<endl;
}
  }
  else{
    cout<<"File is not found "<<endl;
  }
  //cin.ignore();
  read.close();
}
void cashier::update_quantity(string id6,int a){
  //std::cout << "/* message */" << '\n';
  string str1,str2,str3,str4;
  int var,var2;
  ofstream write;
  ifstream read;
  write.open("update.csv");
  read.open("stock.csv");

   if(read.is_open()){
    while(!read.eof()){
      getline(read,id,',');
      getline(read,str1,',');
      getline(read,str2,',');
      getline(read,str3,',');
      read>>str4;
      //getline(read,str4,'\n');
      //int no;
      //std::cout << "id == " << id << '\n';
      // if (id != " ") {
      //   no = stoi(id);
      // }
      // else{
      //   std::cout << "problem" << '\n';
      // }

      if(id == id6 && id!=""){
        //std::cout << "hhhhhh" << '\n';
        var = stoi(str2);
        a = var-a;

        write<<id<<","<<str1<<","<<a<<","<<str3<<","<<str4<<endl;

      }
      else if(id != ""){
          write<<id<<","<<str1<<","<<str2<<","<<str3<<","<<str4<<endl;

      }

     }
}
  else
  {
    cout << "file is not open" << '\n';
  }

  read.close();
  write.close();
   rename("update.csv","stock.csv");
}
void project::info(){
  ofstream write;
  ifstream read;
  write.open("update.csv");
  read.open("stock.csv");
  string str1,str2,str3,str4,str5;
  while(!read.eof()){
    getline(read,str1,',');
    getline(read,str2,'\n');
    // getline(read,str3,',');
    // getline(read,str4,',');
    // getline(read,str5,'\n');
    //cout<<str1<<endl;
    if(str1 == ""){
      //cout<<str1<<endl;
      //std::cout << "SSSS" << '\n';
      continue;
    }
    else
    {
      write<<str1<<","<<str2<<endl;
    }
  }
  read.close();
  write.close();
  rename("update.csv","stock.csv");
}
void cashier::generate_bill(){
ofstream write,write1;
ifstream read,read1;
string str1,str2,str3,str4,str5,str6;
int var = -1,var1,var2,var3,no;
double discount=0,total_amount=0,amount=0;

write.open("sales.csv",ios::app);
write1.open("bill.csv");
read1.open("bill.csv");
int idF;
input();
cout<<"Enter ID of purchase item :";
cin>>no;
while(cin.fail()){
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(),'\n');
cout << "Invalid Number /";
cout<<"Enter number again"<<endl;
cin>>no;
}
while(var!=0){
  read.open("stock.csv");
if(read.is_open()){
while(!read.eof()){
  getline(read,str1,',');
  getline(read,str2,',');
  getline(read,str3,',');
  getline(read,str4,',');
  getline(read,str5,'\n');
  if(str1!=" "){
   idF = stoi(str1);
}
  if(no == idF){

    var3 = stoi(str3);
    var1 = stoi(str4);
    var2 = stoi(str5);
        if(var3<1){
        cout<<"The quantity is less than 1"<<endl;
        return;
        }
        else{

        cin.ignore();
        cout<<"Enter employe ID :";
        getline(cin,empid);

        cout<<"Enter quantity :";
        cin>>quantity;
        cin.ignore();
        total_averager_price = quantity * var1;
        amount = quantity * var2;
        total_amount += amount;
        if(str1!=""){
        write1<<str1<<","<<str2<<","<<quantity<<","<<str5<<","<<amount<<endl;
        write<<str1<<","<<str2<<","<<empid<<","<<quantity<<","<<str4<<","<<total_averager_price<<","<<str5<<","<<amount<<endl;
        cout<<"Enter 0 for final bill "<<endl;
        cin>>var;
        if(var==0)
        break;
        else{
          cout<<"Enter ID of purchase item :";

          cin >> no;
        }

      }
      }

        read.close();
         break;
      }

}

}
else{
  cout<<"File is not found "<<endl;
}
}
int var5;
system("clear");
cout<<"Your Final Bill IS "<<endl;
while(!read1.eof()){
  getline(read1,str1,',');
  getline(read1,str2,',');
  getline(read1,str3,',');
  getline(read1,str4,',');
  getline(read1,str5,'\n');
  if(str1!="" && str3!=""){
    var5 = stoi(str3);
      update_quantity(str1,var);
    }
  cout<<str1<<"|"<<str2<<"|"<<str3<<"|"<<str4<<"|"<<str5<<endl;
}
if(total_amount>5000){
  cout<<"Your total amount is :"<<total_amount<<endl;
  discount = (5.0/100)*total_amount;
  cout<<"Your discount is :"<<discount<<endl;
  total_amount = total_amount - discount;
  cout<<"Your actual amount is "<<total_amount<<endl;
  }
else if(total_amount>10000){
  cout<<"Your total amount is :"<<total_amount<<endl;
  discount = (10.0/100)*total_amount;
  cout<<"Your discount is :"<<discount<<endl;
  total_amount = total_amount - discount;
  cout<<"Your actual amount is "<<total_amount<<endl;
}
else if(total_amount>20000){
  cout<<"Your total amount is :"<<total_amount<<endl;
  discount = (20.0/100)*total_amount;
  cout<<"Your discount is :"<<discount<<endl;
  total_amount = total_amount - discount;
  cout<<"Your actual amount is "<<total_amount<<endl;
}
else{
  cout<<"Your discount is :"<<discount<<endl;
  cout<<"Your total amount is :"<<total_amount<<endl;
}
read1.close();
write1.close();
write.close();
info();

}
void project::generate_sale_report(){
  ifstream read;
  int var;
  double var1,var2;
  string str1,str2,str3,str4,str5,str6,str7;
  double total_items=0.0,total_quantity=0.0,all_average_price=0.0,all_sale_price=0.0;
  read.open("sales.csv");
  if(read.is_open()){
      while(!read.eof()){
        total_averager_price = 0;
        total_sale_price = 0;
        var =0;
        var1 =0;
        var2 =0;
        getline(read,id,',');
        getline(read,str1,',');
        getline(read,str2,',');
        getline(read,str3,',');
        getline(read,str4,',');
        getline(read,str5,',');
        getline(read,str6,',');
        getline(read,str7,'\n');

        if(id!=" " ){
        var = stoi(str3);
        var1 =stoi(str5);
        var2 = stoi(str7);
        total_averager_price = var1;
        total_sale_price = var2;
        if(id!=""){
        cout<<id<<"|"<<str1<<"|"<<str2<<"|"<<str3<<"|"<<str4<<"|"<<str5<<"|"<<str6<<"|"<<str7<<endl;

        all_average_price += total_averager_price;
        all_sale_price += total_sale_price;
        total_items += 1;
        total_quantity += var;
      }}
      }

  }
  else{
    cout<<"File is not found"<<endl;
  }
  cout<<"Total number of items :"<<total_items<<endl;
  cout<<"Total number of quantity :"<<total_quantity<<endl;
  cout<<"Total total_averager_price :"<<all_average_price<<endl;
  cout<<"total_sale_price :"<<all_sale_price<<endl;
  if(all_average_price<all_sale_price)
  cout<<"The company earn the profit of :"<<all_sale_price-all_average_price<<endl;
  else
  cout<<"The company is in loss of :"<<all_average_price- all_sale_price<<endl;
read.close();
cout<<endl;
cout<<endl;
}
void project::generate_person_wise_sale_report(string empid1){
  ifstream read;
  read.open("sales.csv");
  int var;
  double var1,var2;
  string str1,str2,str3,str4,str5,str6,str7;
  double total_items=0.0,total_quantity=0.0,all_average_price=0.0,all_sale_price=0.0;
  if(read.is_open()){
      while(!read.eof()){
        total_averager_price = 0;
        total_sale_price = 0;
        var =0;
        var1 =0;
        var2 =0;
        getline(read,id,',');
        getline(read,str1,',');
        getline(read,str2,',');
        getline(read,str3,',');
        getline(read,str4,',');
        getline(read,str5,',');
        getline(read,str6,',');
        getline(read,str7,'\n');
        if(str2==empid1){
        var = stoi(str3);
        var1 =stoi(str5);
        var2 = stoi(str7);
        total_averager_price =  var1;
        total_sale_price =  var2;
        if(id!=""){
        cout<<id<<"|"<<str1<<"|"<<str3<<"|"<<str4<<"|"<<str5<<"|"<<str6<<"|"<<str7<<endl;
        all_average_price += total_averager_price;
        all_sale_price += total_sale_price;
        total_items += 1;
        total_quantity += var;
        //break;
      }
  }

  else{
    //cout<<"This item is not found "<<endl;
    continue;
  }
  }


  }
  else{
    cout<<"File is not found"<<endl;
  }
  cout<<"Total number of items :"<<total_items<<endl;
  cout<<"Total number of quantity :"<<total_quantity<<endl;
  cout<<"Total total_averager_price :"<<all_average_price<<endl;
  cout<<"total_sale_price :"<<all_sale_price<<endl;
  read.close();
  cout<<endl;
  cout<<endl;
}
void cashier::search_item(string id1){
  ifstream read;
  read.open("stock.csv");
  string str1,str2,str3,str4;
  if(read.is_open()){
      while(!read.eof()){
        getline(read,id,',');
        getline(read,str1,',');
        getline(read,str2,',');
        getline(read,str3,',');
        getline(read,str4,'\n');
        if(id==id1){
        if(id!=""){
        cout<<id<<"|"<<str1<<"|"<<str2<<"|"<<str3<<"|"<<str4<<endl;
        break;
      }
  }

  else{
    //cout<<"This item is not found "<<endl;
    continue;
  }
 }


  }
  else{
    cout<<"File is not found"<<endl;
  }
  read.close();
  cout<<endl;
  cout<<endl;
}

void check(int &a){
  ifstream read;
  string id,pass,check_id,check_pass,str8;
  a = 0;
  cout<<"Enter login id"<<endl;
  cin>>id;

  cout<<"Enter login password"<<endl;
  cin>>pass;

  read.open("employ.csv");
  if(read.is_open()){
    while(!read.eof()){
    getline(read,check_id,',');
    getline(read,check_pass,',');
    getline(read,str8,'\n');
    if(check_id==id && check_pass==pass){
      a = 1;
      cout<<"You are successfully login"<<endl;
      read.close();
      break;
    }
  }
  }
  else{
    cout<<"The file is not found"<<endl;
  }
  read.close();
}
void menu(){
  project obj;
   cashier obj1;
   //stock obj2;
   string id9;
   int str1=-1,str2=-1,str3=-1,str4=-1,str5 = -1;
   cout<<"                               "<<"|"<<" WELCOME TO MY STORE    "<<"|"<<endl;
     while(str1!=0){
     cout<<"0:exit"<<endl;
     cout<<"1:Admin "<<endl;
     cout<<"2:Stock manager"<<endl;
     cout<<"3:Cashier"<<endl;
     cin>>str1;
   while(cin.fail()){
     cin.clear();
       cin.ignore(numeric_limits<streamsize>::max(),'\n');
       cout << "Invalid Number";
       cout<<"0:exit"<<endl;
       cout<<"1:Admin "<<endl;
       cout<<"2:Stock manager"<<endl;
       cout<<"3:Cashier"<<endl;
       cin>>str1;
   }

   if(str1==1){
     check(str5);
     str2=-1;
     //cout<<str5<<endl;
     if(str5==1){

        //cout<<str5<<endl;
                   while(str2!=0){
                    cout<<"0:exit"<<endl;
                    cout<<"1:Add Stock"<<endl;
                    cout<<"2:Update stock"<<endl;
                    cout<<"3:Remove any stock"<<endl;
                    cout<<"4:Generate Stock Report"<<endl;
                    cout<<"5:Search any item"<<endl;
                    cout<<"6:Generate sale report"<<endl;
                    cout<<"7:Generate person wise sale report "<<endl;
                    cout<<"8:Add new employe"<<endl;
                    cout<<"9:Update employe info"<<endl;
                    cout<<"10:Remove any employe "<<endl;
                    cin>>str2;
                    while(cin.fail()){
                      cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        cout << "Invalid Number /";
                        cout<<"Enter number again"<<endl;
                        cin>>str2;
                    }
                    if(str2==1){
                              obj.add_new_stock();
                                }
                    else if(str2==2){
                              cout<<"Enter ID :";
                              cin>>id9;
                              while(cin.fail()){
                              cin.clear();
                              cin.ignore(numeric_limits<streamsize>::max(),'\n');
                              cout << "Invalid Number /";
                              cout<<"Enter number again"<<endl;
                              cin>>id9;
                              }
                              obj.update_stock(id9);
                            }
                    else if(str2==3){
                              cout<<"Enter ID :";
                              cin>>id9;
                              while(cin.fail()){
                              cin.clear();
                              cin.ignore(numeric_limits<streamsize>::max(),'\n');
                              cout << "Invalid Number /";
                              cout<<"Enter number again"<<endl;
                              cin>>id9;
                              }
                              obj.remove_stock(id9);
                            }

                    else if(str2==4){
                              obj.generate_stock_report();
                                    }
                    else if(str2==5){
                              cout<<"Enter ID :";
                              cin>>id9;
                              while(cin.fail()){
                              cin.clear();
                              cin.ignore(numeric_limits<streamsize>::max(),'\n');
                              cout << "Invalid Number /";
                              cout<<"Enter number again"<<endl;
                              cin>>id9;
                              }
                              obj.search_item(id9);
                            }

                      else if(str2==6){
                              obj.generate_sale_report();
                            }
                      else if(str2==7){
                              cout<<"Enter ID :";
                              cin>>id9;
                              while(cin.fail()){
                              cin.clear();
                              cin.ignore(numeric_limits<streamsize>::max(),'\n');
                              cout << "Invalid Number /";
                              cout<<"Enter number again"<<endl;
                              cin>>id9;
                              }
                              obj.generate_person_wise_sale_report(id9);
                              }
                        else if(str2==8){
                              obj.add_emp();
                              }
                        else if (str2==9){
                              cout<<"Enter ID :";
                              cin>>id9;
                              while(cin.fail()){
                              cin.clear();
                              cin.ignore(numeric_limits<streamsize>::max(),'\n');
                              cout << "Invalid Number /";
                              cout<<"Enter number again"<<endl;
                              cin>>id9;
                              }
                              obj.update_emp_info(id9);
                              }
                        else if(str2==10){
                              cout<<"Enter ID :";
                              cin>>id9;
                              while(cin.fail()){
                              cin.clear();
                              cin.ignore(numeric_limits<streamsize>::max(),'\n');
                              cout << "Invalid Number /";
                              cout<<"Enter number again"<<endl;
                              cin>>id9;
                              }
                              obj.remove_any_emp(id9);
                              }
                        else if(str2==0){
                          cout<<"You successfully logout from admin "<<endl;
                        }
                        else
                                if(str2!=0){
                                  cout<<"You enter a wrong number "<<endl;
                                }


                        }
                      }
                      else{
                        cout<<"Invalid ID Or Password"<<endl;
                      }

   }
   else if(str1==2){
     str3 = -1;
     check(str5);
                  if(str5==1){
                         while(str3!=0){
                         cout<<"0:exit"<<endl;
                         cout<<"1:Add Stock"<<endl;
                         cout<<"2:Update stock"<<endl;
                         cout<<"3:Remove any stock"<<endl;
                         cout<<"4:Generate Stock Report"<<endl;
                         cout<<"5:Search any item"<<endl;
                         cin>>str3;
                         while(cin.fail()){
                           cin.clear();
                             cin.ignore(numeric_limits<streamsize>::max(),'\n');
                             cout << "Invalid Number /";
                             cout<<"Enter number again"<<endl;
                             cin>>str3;
                         }
                                                if(str3==1){
                                                 obj.add_new_stock();
                                                   }
                                       else if(str3==2){
                                                 cout<<"Enter ID :";
                                                 cin>>id9;
                                                 while(cin.fail()){
                                                 cin.clear();
                                                 cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                                 cout << "Invalid Number /";
                                                 cout<<"Enter number again"<<endl;
                                                 cin>>id9;
                                                 }
                                                 obj.update_stock(id9);
                                               }
                                       else if(str3==3){
                                                 cout<<"Enter ID :";
                                                 cin>>id9;
                                                 while(cin.fail()){
                                                 cin.clear();
                                                 cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                                 cout << "Invalid Number /";
                                                 cout<<"Enter number again"<<endl;
                                                 cin>>id9;
                                                 }
                                                 obj.remove_stock(id9);
                                               }

                                       else if(str3==4){
                                                 obj.generate_stock_report();
                                                       }
                                       else if(str3==5){
                                                 cout<<"Enter ID :";
                                                 cin>>id9;
                                                 while(cin.fail()){
                                                 cin.clear();
                                                 cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                                 cout << "Invalid Number /";
                                                 cout<<"Enter number again"<<endl;
                                                 cin>>id9;
                                                 }
                                                 obj.search_item(id9);
                                               }
                                               else if(str3==0){
                                                 cout<<"You are successfully logout from stock manager "<<endl;
                                               }
                                               else{
                                                 if(str3!=0){
                                                   cout<<"You entered a wrong option "<<endl;
                                                 }
                                               }

                       }}
                       else{
                         cout<<"Invalid ID or Password "<<endl;
                       }
   }
   else if(str1==3){
     str4 = -1;
     check(str5);
     if(str5==1){
                                             while(str4!=0){
                                                     cout<<"0:Exit "<<endl;
                                                     cout<<"1:Generate bill"<<endl;
                                                     cout<<"2:Search Item"<<endl;
                                                     cin>>str4;
                                                     while(cin.fail()){
                                                     cin.clear();
                                                     cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                                     cout << "Invalid Number /";
                                                     cout<<"Enter number again"<<endl;
                                                     cin>>str4;
                                                     }
                                                     if(str4==1){
                                                       obj1.generate_bill();
                                                     }
                                                     else if(str4==2){
                                                       cout<<"Enter ID "<<endl;
                                                       cin>>id9;
                                                       while(cin.fail()){
                                                       cin.clear();
                                                       cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                                       cout << "Invalid Number /";
                                                       cout<<"Enter number again"<<endl;
                                                       cin>>id9;
                                                       }
                                                       obj1.search_item(id9);
                                                     }
                                                     else if(str4==0){
                                                       cout<<"You are successfully loggout from cashier "<<endl;
                                                       }
                                                      else{
                                                        if(str4!=0){
                                                          cout<<"You enter a wrong option "<<endl;
                                                        }
                                                      }
                                        }}
                                        else{
                                          cout<<"Invalid ID or Password"<<endl;
                                        }
   }
   else if(str1==0){
     cout<<"You successfully exit from program "<<endl;
   }
   else
   if(str1!=0){
     cout<<"You entered a wrong number"<<endl;
   }
}


}
