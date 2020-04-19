#include<iostream>
#include<vector>
#include<iomanip>
#include<fstream>
#define borrowerData "borrowerData.txt"
using namespace std;
extern void SplitString(const string& s, vector<string>& v, const string& c); 
//注册 
void borrowerAdd(){
	//学号，姓名，性别 
	string borrowerNo,borrowerName,borrowerGender;

	cout<<"请输入学号：";
	cin>>borrowerNo;
	cout<<"请输入姓名：";
	cin>>borrowerName;
	cout<<"请输入性别：";
	cin>>borrowerGender;
	
	//判断编号是否已存在
	string temp;
	ifstream infile;
	infile.open(borrowerData);
	while(getline(infile,temp))
    {
    	vector<string> v;
    	SplitString(temp, v,",");
    	if(v[0]==borrowerNo){
    		cout<<"提示：添加失败，学号已存在！"<<endl;;
    		return;
		}
    }
	infile.close();
	//判断性别是否合法
	if(!(borrowerGender=="男"||borrowerGender=="女")){
		cout<<"提示：添加失败，性别不合法，请输入男或女！"<<endl;;
    		return;
	} 
	 
	fstream file1;
	file1.open(borrowerData,ios::app|ios::out);
	string data=borrowerNo+","+borrowerName+","+borrowerGender; 
	file1<<data<<endl;
	file1.close();
	cout<<"新增数据成功"<<endl; 
}
//修改 
void borrowerModify(){
	string temp;
	vector<string> dataTxt;
	string borrowerNo;
	cout<<"请输入学号:"; 
	cin>>borrowerNo;
	
	ifstream infile;
	infile.open(borrowerData);
	while(getline(infile,temp))
    {
    	string tempBorrowerName,tempBorrowerGender;
    	vector<string> v;
		 
    	SplitString(temp, v,","); 
    	if(v[0]==borrowerNo){
    		cout<<"当前姓名："<<v[1]<<endl;
    		cout<<"新的姓名:";
    		cin>>tempBorrowerName;
    		
    		cout<<"当前性别："<<v[2]<<endl;
    		cout<<"新的性别:";
    		cin>>tempBorrowerGender;
    		
			temp=v[0]+","+tempBorrowerName+","+tempBorrowerGender;
			cout<<"修改后的信息为："<<temp<<endl;
		}
		dataTxt.push_back(temp); 
    }
	infile.close();
	fstream file1;
	file1.open(borrowerData,fstream::out | ios_base::trunc); 
	for(int i=0;i<dataTxt.size();i++){
			file1<<dataTxt[i]<<endl;
	}
	file1.close();
}
//查询
void borrowerFind(){
	cout<<"请输入学号或姓名进行查询（姓名支持模糊查询）："; 
	string findStr,temp;
	cin>>findStr;
	bool findFlag=true;
	ifstream infile;
	infile.open(borrowerData);
	while(getline(infile,temp))
    {
    	vector<string> v; 
    	SplitString(temp, v,","); 
    	if(v[0]==findStr||v[1]==findStr||v[1].find(findStr)!=v[1].npos){
    		cout<<"学号："<<v[0]<<endl;
    		cout<<"姓名："<<v[1]<<endl;
    		cout<<"性别："<<v[2]<<endl;
    		cout<<"---------------------------------------"<<endl; 
    		findFlag=false;
		}
    }
    if(findFlag){
    	cout<<"抱歉，没有找到相关信息！"<<endl;
	}
	infile.close();
} 
//删除
void borrowerDel(){
	string temp;
	vector<string> dataTxt;
	string delStr;
	cout<<"请输入学号或姓名:"; 
	cin>>delStr;
	
	ifstream infile;
	infile.open(borrowerData);
	while(getline(infile,temp))
    {
    	vector<string> v;
		 
    	SplitString(temp, v,","); 
    	if(v[0]==delStr||v[1]==delStr){
    		cout<<"学号："<<v[0]<<"\t"<<"姓名："<<v[1]<<endl;
			continue;
		}
		dataTxt.push_back(temp); 
    }
	infile.close();
	fstream file1;
	file1.open(borrowerData,fstream::out | ios_base::trunc); 
	for(int i=0;i<dataTxt.size();i++){
			file1<<dataTxt[i]<<endl;
	}
	file1.close();
	cout<<"已成功删除以上数据"<<endl;
} 
//显示
void borrowerShow(){
	cout<<setw(10)<<"学号"<<setw(15)<<"姓名"<<setw(10)<<"性别"<<endl;
	string temp;
	ifstream infile;
	infile.open(borrowerData);
	while(getline(infile,temp))
    {
    	vector<string> v;
    	SplitString(temp, v,","); 
    	cout<<setw(10)<<v[0]<<setw(15)<<v[1]<<setw(10)<<v[2]<<endl;
    }
	infile.close();
} 

