#include<iostream>
#include<vector>
#include<iomanip>
#include<fstream>
#define bookData "bookData.txt"
using namespace std;
//分割字符串
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
//新增 
void bookAdd(){
	//图书名称、图书编号、价格、作者、存在状态
	string bookName,bookNo,bookPrice,bookAuthor,bookState;

	cout<<"请输入图书名称：";
	cin>>bookName;
	cout<<"请输入图书编号：";
	cin>>bookNo;
	cout<<"请输入单价：";
	//价格不能小于等于0 
	cin>>bookPrice;
	if(bookPrice[0]=='0'||bookPrice[0]=='-'){
		cout<<"价格不能小于等于0"<<endl;
		return;
	} 
	bookPrice+="元";
	cout<<"请输入作者：";
	cin>>bookAuthor;
	
	bookState="存在";
	//判断编号是否已存在
	string temp;
	ifstream infile;
	infile.open(bookData);
	while(getline(infile,temp))
    {
    	vector<string> v;
    	SplitString(temp, v,",");
    	if(v[1]==bookNo){
    		cout<<"提示：添加失败，图书编号已存在！"<<endl;;
    		return;
		}
    }
	
	fstream file1;
	file1.open(bookData,ios::app|ios::out);
	string data=bookName+","+bookNo+","+bookPrice+","+bookAuthor+","+bookState; 
	file1<<data<<endl;
	file1.close();
	cout<<"新增数据成功"<<endl; 
}
//修改 
void bookModify(){
	string temp;
	vector<string> dataTxt;
	string bookNo;
	cout<<"请输入图书编号:"; 
	cin>>bookNo;
	
	ifstream infile;
	infile.open(bookData);
	while(getline(infile,temp))
    {
    	string tempBookName,tempBookPrice,tempBookAuthor,tempBookState;
    	vector<string> v;
		 
    	SplitString(temp, v,","); 
    	if(v[1]==bookNo){
    		cout<<"当前图书名称："<<v[0]<<endl;
    		cout<<"新的图书名称:";
    		cin>>tempBookName;
    		
    		cout<<"当前图书价格："<<v[2]<<endl;
    		cout<<"新的图书价格:";
    		cin>>tempBookPrice;
    		tempBookPrice+="元";
    		
    		cout<<"当前图书作者："<<v[3]<<endl;
    		cout<<"新的图书作者:";
    		cin>>tempBookAuthor;
    		
    		cout<<"当前图书状态："<<v[4]<<endl;
    		cout<<"新的图书状态（存在/已借出/丢失）:";
    		cin>>tempBookState;
    		//状态不合法则修改失败 
    		if(!(tempBookState=="存在"||tempBookState=="已借出"||tempBookState=="丢失")){
				cout<<"图书状态不合法！"<<endl;
				return; 
			} 
    		
			temp=tempBookName+","+bookNo+","+tempBookPrice+","+tempBookAuthor+","+tempBookState;
			cout<<"修改后的信息为："<<temp<<endl;
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
//查询
void bookFind(){
	cout<<"请输入图书编号或图书名称进行查询（支持图书名称模糊查询）："; 
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
    		cout<<"图书名称："<<v[0]<<endl;
    		cout<<"图书编号："<<v[1]<<endl;
    		cout<<"图书价格："<<v[2]<<endl;
    		cout<<"图书作者："<<v[3]<<endl;
    		cout<<"存在状态："<<v[4]<<endl;
    		cout<<"---------------------------------------"<<endl; 
    		findFlag=false;
		}
    }
    if(findFlag){
    	cout<<"抱歉，没有找到相关图书信息！"<<endl;
	}
	infile.close();
} 
//删除
void bookDel(){
	string temp;
	vector<string> dataTxt;
	string delStr;
	cout<<"请输入图书编号或名称:"; 
	cin>>delStr;
	
	ifstream infile;
	infile.open(bookData);
	while(getline(infile,temp))
    {
    	vector<string> v;
		 
    	SplitString(temp, v,","); 
    	if(v[1]==delStr||v[0]==delStr){
    		cout<<"图书编号："<<v[1]<<"\t"<<"图书名称："<<v[0]<<endl;
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
	cout<<"已成功删除以上图书"<<endl;
} 
//显示
void bookShow(){
	cout<<setw(20)<<"图书编号"<<setw(20)<<"图书名称"<<setw(10)<<"图书价格"<<setw(20)<<"图书作者"<<setw(10)<<"存在状态"<<endl;
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

