#include<iostream>
#include<vector>
#include<iomanip>
#include<fstream>
#define bookData "bookData.txt"
using namespace std;
//�ָ��ַ���
void SplitString(const string& s, vector<string>& v, const string& c)
{
    string::size_type pos1, pos2;
    pos2 = s.find(c);
    pos1 = 0;
    while(string::npos != pos2)
    {
        v.push_back(s.substr(pos1, pos2-pos1));
         
        pos1 = pos2 + c.size();
        pos2 = s.find(c, pos1);
    }
    if(pos1 != s.length())
        v.push_back(s.substr(pos1));
}
//���� 
void bookAdd(){
	//ͼ�����ơ�ͼ���š��۸����ߡ�����״̬
	string bookName,bookNo,bookPrice,bookAuthor,bookState;

	cout<<"������ͼ�����ƣ�";
	cin>>bookName;
	cout<<"������ͼ���ţ�";
	cin>>bookNo;
	cout<<"�����뵥�ۣ�";
	//�۸���С�ڵ���0 
	cin>>bookPrice;
	if(bookPrice[0]=='0'||bookPrice[0]=='-'){
		cout<<"�۸���С�ڵ���0"<<endl;
		return;
	} 
	bookPrice+="Ԫ";
	cout<<"���������ߣ�";
	cin>>bookAuthor;
	
	bookState="����";
	//�жϱ���Ƿ��Ѵ���
	string temp;
	ifstream infile;
	infile.open(bookData);
	while(getline(infile,temp))
    {
    	vector<string> v;
    	SplitString(temp, v,",");
    	if(v[1]==bookNo){
    		cout<<"��ʾ�����ʧ�ܣ�ͼ�����Ѵ��ڣ�"<<endl;;
    		return;
		}
    }
	
	fstream file1;
	file1.open(bookData,ios::app|ios::out);
	string data=bookName+","+bookNo+","+bookPrice+","+bookAuthor+","+bookState; 
	file1<<data<<endl;
	file1.close();
	cout<<"�������ݳɹ�"<<endl; 
}
//�޸� 
void bookModify(){
	string temp;
	vector<string> dataTxt;
	string bookNo;
	cout<<"������ͼ����:"; 
	cin>>bookNo;
	
	ifstream infile;
	infile.open(bookData);
	while(getline(infile,temp))
    {
    	string tempBookName,tempBookPrice,tempBookAuthor,tempBookState;
    	vector<string> v;
		 
    	SplitString(temp, v,","); 
    	if(v[1]==bookNo){
    		cout<<"��ǰͼ�����ƣ�"<<v[0]<<endl;
    		cout<<"�µ�ͼ������:";
    		cin>>tempBookName;
    		
    		cout<<"��ǰͼ��۸�"<<v[2]<<endl;
    		cout<<"�µ�ͼ��۸�:";
    		cin>>tempBookPrice;
    		tempBookPrice+="Ԫ";
    		
    		cout<<"��ǰͼ�����ߣ�"<<v[3]<<endl;
    		cout<<"�µ�ͼ������:";
    		cin>>tempBookAuthor;
    		
    		cout<<"��ǰͼ��״̬��"<<v[4]<<endl;
    		cout<<"�µ�ͼ��״̬������/�ѽ��/��ʧ��:";
    		cin>>tempBookState;
    		//״̬���Ϸ����޸�ʧ�� 
    		if(!(tempBookState=="����"||tempBookState=="�ѽ��"||tempBookState=="��ʧ")){
				cout<<"ͼ��״̬���Ϸ���"<<endl;
				return; 
			} 
    		
			temp=tempBookName+","+bookNo+","+tempBookPrice+","+tempBookAuthor+","+tempBookState;
			cout<<"�޸ĺ����ϢΪ��"<<temp<<endl;
		}
		dataTxt.push_back(temp); 
    }
	infile.close();
	fstream file1;
	file1.open(bookData,fstream::out | ios_base::trunc); 
	for(int i=0;i<dataTxt.size();i++){
			file1<<dataTxt[i]<<endl;
	}
	file1.close();
}
//��ѯ
void bookFind(){
	cout<<"������ͼ���Ż�ͼ�����ƽ��в�ѯ��֧��ͼ������ģ����ѯ����"; 
	string findStr,temp;
	cin>>findStr;
	bool findFlag=true;
	ifstream infile;
	infile.open(bookData);
	while(getline(infile,temp))
    {
    	vector<string> v; 
    	SplitString(temp, v,","); 
    	if(v[1]==findStr||v[0]==findStr||v[0].find(findStr)!=v[0].npos){
    		cout<<"ͼ�����ƣ�"<<v[0]<<endl;
    		cout<<"ͼ���ţ�"<<v[1]<<endl;
    		cout<<"ͼ��۸�"<<v[2]<<endl;
    		cout<<"ͼ�����ߣ�"<<v[3]<<endl;
    		cout<<"����״̬��"<<v[4]<<endl;
    		cout<<"---------------------------------------"<<endl; 
    		findFlag=false;
		}
    }
    if(findFlag){
    	cout<<"��Ǹ��û���ҵ����ͼ����Ϣ��"<<endl;
	}
	infile.close();
} 
//ɾ��
void bookDel(){
	string temp;
	vector<string> dataTxt;
	string delStr;
	cout<<"������ͼ���Ż�����:"; 
	cin>>delStr;
	
	ifstream infile;
	infile.open(bookData);
	while(getline(infile,temp))
    {
    	vector<string> v;
		 
    	SplitString(temp, v,","); 
    	if(v[1]==delStr||v[0]==delStr){
    		cout<<"ͼ���ţ�"<<v[1]<<"\t"<<"ͼ�����ƣ�"<<v[0]<<endl;
			continue;
		}
		dataTxt.push_back(temp); 
    }
	infile.close();
	fstream file1;
	file1.open(bookData,fstream::out | ios_base::trunc); 
	for(int i=0;i<dataTxt.size();i++){
			file1<<dataTxt[i]<<endl;
	}
	file1.close();
	cout<<"�ѳɹ�ɾ������ͼ��"<<endl;
} 
//��ʾ
void bookShow(){
	cout<<setw(20)<<"ͼ����"<<setw(20)<<"ͼ������"<<setw(10)<<"ͼ��۸�"<<setw(20)<<"ͼ������"<<setw(10)<<"����״̬"<<endl;
	string temp;
	ifstream infile;
	infile.open(bookData);
	while(getline(infile,temp))
    {
    	vector<string> v;
    	SplitString(temp, v,","); 
    	cout<<setw(20)<<v[1]<<setw(20)<<v[0]<<setw(10)<<v[2]<<setw(20)<<v[3]<<setw(10)<<v[4]<<endl;
    }
	infile.close();
} 

