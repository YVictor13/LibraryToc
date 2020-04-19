#include<iostream>
#include<windows.h>
#include<stdlib.h>
using namespace std;

extern void bookAdd();			//图书增加 
extern void bookModify();		//图书修改 
extern void bookFind();			//图书查询 
extern void bookDel();			//图书删除 
extern void bookShow();			//图书信息显示 
extern void borrowerAdd();		//借书人注册 
extern void borrowerModify();	//借书人信息修改 
extern void borrowerFind();		//借书人信息查询 
extern void borrowerDel();		//借书人删除 
extern void borrowerShow();		//借书人信息显示 
extern void borrowerAdmin();	//借书手续 
extern void returnAdmin();		//还书手续 
extern void print_main_menu();	//打印主菜单 
extern void borrowAndReturnShow();//借还信息显示 
extern void print_bookAdmin_menu();//打印图书管理菜单 
extern void bookAdmin_process();//图书管理流程 
extern void print_userAdmin_menu();//打印借书人管理菜单 
extern void borrowerAdmin_process();//借书人管理流程 
extern void print_borrowAndReturn_menu();//打印借还管理菜单 
extern void borrowAndReturnAdmin_process();//借还管理流程 

void bookAdmin_process(){
	char n;
	cin>>n;
	system("cls");
	switch(n){
		case '1':
			bookAdd();
			break;
		case '2':
			bookModify();
			break;
		case '3':
			bookFind();
			break;
		case '4':
			bookDel();
			break;
		case '5':
			bookShow();
			break;
		case 'q':
			return;
		default:cout<<"提示：无效的输入！\n请输入相应的序号并按回车，输入q返回"<<endl;
	}
}
void borrowerAdmin_process(){
	char n;
	cin>>n;
	system("cls");
	switch(n){
		case '1':
			borrowerAdd();
			break;
		case '2':
			borrowerModify();
			break;
		case '3':
			borrowerFind();
			break;
		case '4':
			borrowerDel();
			break;
		case '5':
			borrowerShow();
			break;
		case 'q':
			return;
		default:cout<<"提示：无效的输入！\n请输入相应的序号并按回车，输入q返回"<<endl;
	}
}
void borrowAndReturnAdmin_process(){
	char n;
	cin>>n;
	system("cls");
	switch(n){
		case '1':
			borrowerAdmin();
			break;
		case '2':
			returnAdmin();
			break;
		case '3':
			borrowAndReturnShow();
			break; 
		case 'q':
			return;
		default:cout<<"提示：无效的输入！\n请输入相应的序号并按回车，输入q返回"<<endl;
	}
}
void mainProcess(){	//程序流程控制 
	//打印菜单 
	print_main_menu(); 
	char n;
	cin>>n;
	Sleep(500);
	system("cls");
	switch(n){
		case '1':
			print_bookAdmin_menu();
			bookAdmin_process();
			break;
		case '2':
			print_userAdmin_menu();
			borrowerAdmin_process();
			break;
		case '3':
			print_borrowAndReturn_menu();
			borrowAndReturnAdmin_process(); 
			break;
		case 'q':
			return;
		default:cout<<"提示：无效的输入！\n请输入相应的序号并按回车，输入q退出程序"<<endl;
	}
	mainProcess();	
} 
int main(int argc, char** argv) {
	mainProcess();
	return 0;
}

