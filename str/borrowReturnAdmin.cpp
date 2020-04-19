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

//办理借书手续 
void borrowerAdmin(){
	//学号，图书编号，状态 ,借书时间，还书时间 
	string userNo,bookNo,bookState,borrowerTime,returnTime="NULL";
	cout<<"您正在办理借阅手续"<<endl; 
	cout<<"请输入学号：";
	cin>>userNo;
	cout<<"请输入图书编号：";
	cin>>bookNo;
	bookState="已借出";
	//获取时间 
	SYSTEMTIME m_time;
	GetLocalTime(&m_time);
	char szDateTime[100] = {0};
	sprintf(szDateTime, "%02d-%02d-%02d %02d:%02d:%02d", m_time.wYear, m_time.wMonth,m_time.wDay, m_time.wHour, m_time.wMinute, m_time.wSecond);
	string time(szDateTime);
	borrowerTime=time;
	//学号是否存在
	bool userFlag=false;
	string temp;
	ifstream infile;
	infile.open(borrowerData);
	while(getline(infile,temp))
    {
    	vector<string> v;
    	SplitString(temp, v,",");
    	if(v[0]==userNo){	//学号存在 
    		userFlag=true;
		}
    }
    infile.close();
    if(!userFlag){
    	cout<<"此学号未注册，不能办理借书手续！"<<endl;
    	return;
	}
	//图书存在且状态为“存在” 
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
    		if(v[4]=="存在"){
    			v[4]="已借出";
    			findFlag=false;
    		} 
		}
		temp=v[0]+","+v[1]+","+v[2]+","+v[3]+","+v[4];
		dataTxt.push_back(temp);
    }
    if(findFlag){
    	cout<<"抱歉，不能办理借阅手续，此书状态为"<<tempBookState<<endl;
    	return;
	}
	infile.close();
	//更新book数据 
	fstream file1;
	file1.open(bookData,fstream::out | ios_base::trunc); 
	for(int i=0;i<dataTxt.size();i++){
			file1<<dataTxt[i]<<endl;
	}
	file1.close();
	
	//数据写入 
	fstream file2;
	file2.open(borrowerandreturnData,ios::app|ios::out);
	string data=userNo+","+bookNo+","+bookState+","+borrowerTime+","+returnTime; 
	file2<<data<<endl;
	file2.close();
	cout<<"学号："<<userNo<<"借阅成功"<<",图书编号："<<bookNo<<endl; 
}
//办理还书手续 
void returnAdmin(){
	string userNo,bookNo,bookState,returnTime;
	cout<<"您正在办理还书手续"<<endl; 
	cout<<"请输入学号：";
	cin>>userNo;
	cout<<"请输入图书编号：";
	cin>>bookNo;
	//获取时间 
	SYSTEMTIME m_time;
	GetLocalTime(&m_time);
	char szDateTime[100] = { 0 };
	sprintf(szDateTime, "%02d-%02d-%02d %02d:%02d:%02d", m_time.wYear, m_time.wMonth,m_time.wDay, m_time.wHour, m_time.wMinute, m_time.wSecond);
	string time(szDateTime);
	returnTime=time;
	//查找借还记录 
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
    	cout<<"抱歉，没有找到相关借阅信息！"<<endl;
    	return; 
	}
	infile.close();
	//更新状态 
	vector<string> dataTxt;
	infile.open(borrowerandreturnData);
	while(getline(infile,temp))
    {
    	vector<string> v; 
    	SplitString(temp, v,","); 
    	if(v[0]==userNo&&v[1]==bookNo){
    		v[2]="已归还";
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
	//更新book状态 
	vector<string> dataTxtBook;
	infile.open(bookData);
	while(getline(infile,temp))
    {
    	vector<string> v; 
    	SplitString(temp, v,","); 
    	if(v[1]==bookNo&&v[4]=="已借出"){
    		v[4]="存在";
		}
		temp=v[0]+","+v[1]+","+v[2]+","+v[3]+","+v[4];
		dataTxtBook.push_back(temp);
    }
	infile.close();
	//更新book数据 
	fstream file2;
	file2.open(bookData,fstream::out | ios_base::trunc); 
	for(int i=0;i<dataTxtBook.size();i++){
			file2<<dataTxtBook[i]<<endl;
	}
	file1.close();
	cout<<"办理还书手续成功！"<<endl;
}
//显示借还信息
void borrowAndReturnShow(){
	cout<<setw(10)<<"学号"<<setw(15)<<"图书编号"<<setw(10)<<"状态"<<setw(30)<<"借书时间"<<setw(30)<<"还书时间"<<endl;
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

