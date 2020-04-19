#include<iostream>
#include<windows.h>
#include<stdlib.h>
using namespace std;

extern void bookAdd();			//ͼ������ 
extern void bookModify();		//ͼ���޸� 
extern void bookFind();			//ͼ���ѯ 
extern void bookDel();			//ͼ��ɾ�� 
extern void bookShow();			//ͼ����Ϣ��ʾ 
extern void borrowerAdd();		//������ע�� 
extern void borrowerModify();	//��������Ϣ�޸� 
extern void borrowerFind();		//��������Ϣ��ѯ 
extern void borrowerDel();		//������ɾ�� 
extern void borrowerShow();		//��������Ϣ��ʾ 
extern void borrowerAdmin();	//�������� 
extern void returnAdmin();		//�������� 
extern void print_main_menu();	//��ӡ���˵� 
extern void borrowAndReturnShow();//�軹��Ϣ��ʾ 
extern void print_bookAdmin_menu();//��ӡͼ�����˵� 
extern void bookAdmin_process();//ͼ��������� 
extern void print_userAdmin_menu();//��ӡ�����˹���˵� 
extern void borrowerAdmin_process();//�����˹������� 
extern void print_borrowAndReturn_menu();//��ӡ�軹����˵� 
extern void borrowAndReturnAdmin_process();//�軹�������� 

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
		default:cout<<"��ʾ����Ч�����룡\n��������Ӧ����Ų����س�������q����"<<endl;
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
		default:cout<<"��ʾ����Ч�����룡\n��������Ӧ����Ų����س�������q����"<<endl;
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
		default:cout<<"��ʾ����Ч�����룡\n��������Ӧ����Ų����س�������q����"<<endl;
	}
}
void mainProcess(){	//�������̿��� 
	//��ӡ�˵� 
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
		default:cout<<"��ʾ����Ч�����룡\n��������Ӧ����Ų����س�������q�˳�����"<<endl;
	}
	mainProcess();	
} 
int main(int argc, char** argv) {
	mainProcess();
	return 0;
}

