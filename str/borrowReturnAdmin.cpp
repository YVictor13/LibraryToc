#include<iostream>
#include<windows.h>
#include<vector>
#include<iomanip>
#include<fstream>
#define borrowerData "borrowerData.txt"
#define bookData "bookData.txt"
#define borrowerandreturnData "borrowerandreturnData.txt"
using namespace std;
extern void SplitString(const string& s, vector<string>& v, const string& c);

//����������� 
void borrowerAdmin(){
	//ѧ�ţ�ͼ���ţ�״̬ ,����ʱ�䣬����ʱ�� 
	string userNo,bookNo,bookState,borrowerTime,returnTime="NULL";
	cout<<"�����ڰ����������"<<endl; 
	cout<<"������ѧ�ţ�";
	cin>>userNo;
	cout<<"������ͼ���ţ�";
	cin>>bookNo;
	bookState="�ѽ��";
	//��ȡʱ�� 
	SYSTEMTIME m_time;
	GetLocalTime(&m_time);
	char szDateTime[100] = {0};
	sprintf(szDateTime, "%02d-%02d-%02d %02d:%02d:%02d", m_time.wYear, m_time.wMonth,m_time.wDay, m_time.wHour, m_time.wMinute, m_time.wSecond);
	string time(szDateTime);
	borrowerTime=time;
	//ѧ���Ƿ����
	bool userFlag=false;
	string temp;
	ifstream infile;
	infile.open(borrowerData);
	while(getline(infile,temp))
    {
    	vector<string> v;
    	SplitString(temp, v,",");
    	if(v[0]==userNo){	//ѧ�Ŵ��� 
    		userFlag=true;
		}
    }
    infile.close();
    if(!userFlag){
    	cout<<"��ѧ��δע�ᣬ���ܰ������������"<<endl;
    	return;
	}
	//ͼ�������״̬Ϊ�����ڡ� 
	vector<string> dataTxt;
	string findStr=bookNo,tempBookState;
	bool findFlag=true;

	infile.open(bookData);
	while(getline(infile,temp))
    {
    	vector<string> v; 
    	SplitString(temp, v,","); 
    	if(v[1]==findStr){
    		tempBookState=v[4];
    		if(v[4]=="����"){
    			v[4]="�ѽ��";
    			findFlag=false;
    		} 
		}
		temp=v[0]+","+v[1]+","+v[2]+","+v[3]+","+v[4];
		dataTxt.push_back(temp);
    }
    if(findFlag){
    	cout<<"��Ǹ�����ܰ����������������״̬Ϊ"<<tempBookState<<endl;
    	return;
	}
	infile.close();
	//����book���� 
	fstream file1;
	file1.open(bookData,fstream::out | ios_base::trunc); 
	for(int i=0;i<dataTxt.size();i++){
			file1<<dataTxt[i]<<endl;
	}
	file1.close();
	
	//����д�� 
	fstream file2;
	file2.open(borrowerandreturnData,ios::app|ios::out);
	string data=userNo+","+bookNo+","+bookState+","+borrowerTime+","+returnTime; 
	file2<<data<<endl;
	file2.close();
	cout<<"ѧ�ţ�"<<userNo<<"���ĳɹ�"<<",ͼ���ţ�"<<bookNo<<endl; 
}
//���������� 
void returnAdmin(){
	string userNo,bookNo,bookState,returnTime;
	cout<<"�����ڰ���������"<<endl; 
	cout<<"������ѧ�ţ�";
	cin>>userNo;
	cout<<"������ͼ���ţ�";
	cin>>bookNo;
	//��ȡʱ�� 
	SYSTEMTIME m_time;
	GetLocalTime(&m_time);
	char szDateTime[100] = { 0 };
	sprintf(szDateTime, "%02d-%02d-%02d %02d:%02d:%02d", m_time.wYear, m_time.wMonth,m_time.wDay, m_time.wHour, m_time.wMinute, m_time.wSecond);
	string time(szDateTime);
	returnTime=time;
	//���ҽ軹��¼ 
	string temp; 
	bool findFlag=true;
	ifstream infile;
	infile.open(borrowerandreturnData);
	while(getline(infile,temp))
    {
    	vector<string> v; 
    	SplitString(temp, v,","); 
    	if(v[0]==userNo&&v[1]==bookNo){
    		findFlag=false;
		}
    }
    if(findFlag){
    	cout<<"��Ǹ��û���ҵ���ؽ�����Ϣ��"<<endl;
    	return; 
	}
	infile.close();
	//����״̬ 
	vector<string> dataTxt;
	infile.open(borrowerandreturnData);
	while(getline(infile,temp))
    {
    	vector<string> v; 
    	SplitString(temp, v,","); 
    	if(v[0]==userNo&&v[1]==bookNo){
    		v[2]="�ѹ黹";
    		v[4]=returnTime;
		}
		temp=v[0]+","+v[1]+","+v[2]+","+v[3]+","+v[4];
		dataTxt.push_back(temp);
    }
	infile.close();
	fstream file1;
	file1.open(borrowerandreturnData,fstream::out | ios_base::trunc); 
	for(int i=0;i<dataTxt.size();i++){
			file1<<dataTxt[i]<<endl;
	}
	file1.close();
	//����book״̬ 
	vector<string> dataTxtBook;
	infile.open(bookData);
	while(getline(infile,temp))
    {
    	vector<string> v; 
    	SplitString(temp, v,","); 
    	if(v[1]==bookNo&&v[4]=="�ѽ��"){
    		v[4]="����";
		}
		temp=v[0]+","+v[1]+","+v[2]+","+v[3]+","+v[4];
		dataTxtBook.push_back(temp);
    }
	infile.close();
	//����book���� 
	fstream file2;
	file2.open(bookData,fstream::out | ios_base::trunc); 
	for(int i=0;i<dataTxtBook.size();i++){
			file2<<dataTxtBook[i]<<endl;
	}
	file1.close();
	cout<<"�����������ɹ���"<<endl;
}
//��ʾ�軹��Ϣ
void borrowAndReturnShow(){
	cout<<setw(10)<<"ѧ��"<<setw(15)<<"ͼ����"<<setw(10)<<"״̬"<<setw(30)<<"����ʱ��"<<setw(30)<<"����ʱ��"<<endl;
	string temp;
	ifstream infile;
	infile.open(borrowerandreturnData);
	while(getline(infile,temp))
    {
    	vector<string> v;
    	SplitString(temp, v,","); 
    	cout<<setw(10)<<v[0]<<setw(15)<<v[1]<<setw(10)<<v[2]<<setw(30)<<v[3]<<setw(30)<<v[4]<<endl;
    }
	infile.close();
} 

