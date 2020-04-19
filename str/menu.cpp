#include<iostream>
using namespace std;
void print_main_menu(){	//菜单 
	cout<<"=====图书管理系统====="<<endl; 
	cout<<"1、图书信息管理"<<endl;
	cout<<"2、借书人管理"<<endl;
	cout<<"3、图书借还管理"<<endl;
	cout<<"提示：请输入相应的序号并按回车，输入q返回"<<endl;
}
void print_bookAdmin_menu(){
	cout<<"1、图书基本信息的录入"<<endl;
	cout<<"2、图书基本信息的修改"<<endl;
	cout<<"3、图书基本信息的查询"<<endl; 
	cout<<"4、图书信息的删除"<<endl;
	cout<<"5、显示图书基本信息"<<endl;
	cout<<"提示：请输入相应的序号并按回车，输入q返回"<<endl;
}
void print_userAdmin_menu(){
	cout<<"1、注册借书人"<<endl;
	cout<<"2、修改借书人信息"<<endl;
	cout<<"3、查询借书人信息"<<endl; 
	cout<<"4、删除借书人"<<endl;
	cout<<"5、显示借书人信息"<<endl; 
	cout<<"提示：请输入相应的序号并按回车，输入q返回"<<endl;
} 
void print_borrowAndReturn_menu(){
	cout<<"1、办理借书手续"<<endl;
	cout<<"2、办理还书手续"<<endl;
	cout<<"3、显示借还信息"<<endl; 
	cout<<"提示：请输入相应的序号并按回车，输入q返回"<<endl;
} 

