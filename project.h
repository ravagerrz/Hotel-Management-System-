//#include <iostream>
// #include <fstream>

#ifndef __project_H_
#define __project_H_
#include<string>
using namespace std;
class project{
public:
  string id,name,empid,contact,address,password,cnic,type1;
  double average_price,sale_price,salary,total_averager_price,total_sale_price;
  int quantity;
  project();
  virtual void info();
  virtual void add_new_stock();
  virtual void update_stock(string id2);
   virtual void remove_stock(string id1);
   virtual void generate_stock_report();
  virtual void search_item(string id1);
  virtual void input();
  void input1();
  virtual void generate_sale_report();
   virtual void generate_person_wise_sale_report(string empid1);
   void add_emp();
   void update_emp_info(string id3);
   void remove_any_emp(string id4);
};
class cashier:public project{
public:
  void generate_bill();
  void update_quantity(string id6,int a);
  void input();
  void search_item(string id1);
  };
  class stock:public project{

  };
  void menu();
  void check(int &a);
#endif
