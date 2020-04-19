#include<iostream>
#include<vector>
#include<iomanip>
#include<fstream>
#define borrowerData "borrowerData.txt"
using namespace std;
extern void SplitString(const string& s, vector<string>& v, const string& c); 
//ע�� 
void borrowerAdd(){
	//ѧ�ţ��������Ա� 
	string borrowerNo,borrowerName,borrowerGender;

	cout<<"������ѧ�ţ�";
	cin>>borrowerNo;
	cout<<"������������";
	cin>>borrowerName;
	cout<<"�������Ա�";
	cin>>borrowerGender;
	
	//�жϱ���Ƿ��Ѵ���
	string temp;
	ifstream infile;
	infile.open(borrowerData);
	while(getline(infile,temp))
    {
    	vector<string> v;
    	SplitString(temp, v,",");
    	if(v[0]==borrowerNo){
    		cout<<"��ʾ�����ʧ�ܣ�ѧ���Ѵ��ڣ�"<<endl;;
    		return;
		}
    }
	infile.close();
	//�ж��Ա��Ƿ�Ϸ�
	if(!(borrowerGender=="��"||borrowerGender=="Ů")){
		cout<<"��ʾ�����ʧ�ܣ��Ա𲻺Ϸ����������л�Ů��"<<endl;;
    		return;
	} 
	 
	fstream file1;
	file1.open(borrowerData,ios::app|ios::out);
	string data=borrowerNo+","+borrowerName+","+borrowerGender; 
	file1<<data<<endl;
	file1.close();
	cout<<"�������ݳɹ�"<<endl; 
}
//�޸� 
void borrowerModify(){
	string temp;
	vector<string> dataTxt;
	string borrowerNo;
	cout<<"������ѧ��:"; 
	cin>>borrowerNo;
	
	ifstream infile;
	infile.open(borrowerData);
	while(getline(infile,temp))
    {
    	string tempBorrowerName,tempBorrowerGender;
    	vector<string> v;
		 
    	SplitString(temp, v,","); 
    	if(v[0]==borrowerNo){
    		cout<<"��ǰ������"<<v[1]<<endl;
    		cout<<"�µ�����:";
    		cin>>tempBorrowerName;
    		
    		cout<<"��ǰ�Ա�"<<v[2]<<endl;
    		cout<<"�µ��Ա�:";
    		cin>>tempBorrowerGender;
    		
			temp=v[0]+","+tempBorrowerName+","+tempBorrowerGender;
			cout<<"�޸ĺ����ϢΪ��"<<temp<<endl;
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
//��ѯ
void borrowerFind(){
	cout<<"������ѧ�Ż��������в�ѯ������֧��ģ����ѯ����"; 
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
    		cout<<"ѧ�ţ�"<<v[0]<<endl;
    		cout<<"������"<<v[1]<<endl;
    		cout<<"�Ա�"<<v[2]<<endl;
    		cout<<"---------------------------------------"<<endl; 
    		findFlag=false;
		}
    }
    if(findFlag){
    	cout<<"��Ǹ��û���ҵ������Ϣ��"<<endl;
	}
	infile.close();
} 
//ɾ��
void borrowerDel(){
	string temp;
	vector<string> dataTxt;
	string delStr;
	cout<<"������ѧ�Ż�����:"; 
	cin>>delStr;
	
	ifstream infile;
	infile.open(borrowerData);
	while(getline(infile,temp))
    {
    	vector<string> v;
		 
    	SplitString(temp, v,","); 
    	if(v[0]==delStr||v[1]==delStr){
    		cout<<"ѧ�ţ�"<<v[0]<<"\t"<<"������"<<v[1]<<endl;
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
	cout<<"�ѳɹ�ɾ����������"<<endl;
} 
//��ʾ
void borrowerShow(){
	cout<<setw(10)<<"ѧ��"<<setw(15)<<"����"<<setw(10)<<"�Ա�"<<endl;
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

