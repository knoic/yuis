#include<iostream>
#include<stdio.h>
#include<string>
#include<fstream>
using namespace std;
long n;
struct zggz
{
    char name[20];
	char num[10];
	float pay_gw;           //岗位工资
	float pay_xinji;       //薪级工资
	float pay_zw;        //职务津贴
	float pay_xiaoji;      //绩效工资
	float pay_yf;          //应发工资
	float pay_sf;         //实发工资
	float duty;             //个人所得税
}zggz[100];


void cal_duty()           //税计算
{



};
int read()
{
	FILE*fp;
    fp=fopen("gz.dat","rb");// localfile文件名
    fseek(fp,0,SEEK_SET);
    fseek(fp,0,SEEK_END);
    long longBytes=ftell(fp)/sizeof(struct zggz);// 统计人数
    n=longBytes;
    fseek(fp,0,SEEK_SET);
    if ( fp == NULL )
	{
		return -1 ;
	}
    fread( (char*)zggz , sizeof(struct zggz), n , fp ); //从文件中读n个结构体的数据
	fclose(fp);
    cout<<n<<endl;
    cout<<zggz[2].name;
	return 0;
}       //读取职工工资数据函数,主函数执行时要调用和必须调用的第一个函数
int write()
{
	FILE *fp ;
    fp=fopen("gz.dat" , "wb" );
    if ( fp == NULL )
    {
		return -1 ;
	}
    fwrite( (char*)zggz , sizeof(struct zggz), n , fp ); //将数组写入文件
	fclose(fp);
};        //保存职工工资数据函数
int find()
{
	char name_find[10];
	cout<<"请输入查询工号："<<endl;
	cin>>name_find;
	for(int i=0;i<n;i++)
	{
		strcmp(name_find,zggz[i].num);
		cout<<strcmp(name_find,zggz[i].num);
	if(!strcmp(name_find,zggz[i].num))
		{
			cout<<"工号："<<zggz[i].num<<endl;
		    cout<<"名字："<<zggz[i].name<<endl;
		    cout<<"岗位工资："<<zggz[i].pay_gw<<endl;
		    cout<<"薪级工资："<<zggz[i].pay_xinji<<endl;
		    cout<<"职务津贴："<<zggz[i].pay_zw<<endl;
		    cout<<"绩效工资："<<zggz[i].pay_xiaoji<<endl;
		    cout<<"应发工资："<<zggz[i].pay_yf<<endl;
		    cout<<"个人所得税："<<zggz[i].duty<<endl;
		    cout<<"实发工资："<<zggz[i].pay_sf<<endl;
		}
		else
		{
			cout<<"查无此人"<<endl;
		}
	}
	return 0;
	
};		 //查询职工工资数据函数
void list()
{
	for(int i=0;i<n;i++)
	{
		cout<<"工号："<<zggz[i].num<<endl;
		cout<<"名字："<<zggz[i].name<<endl;
		cout<<"岗位工资："<<zggz[i].pay_gw<<endl;
		cout<<"薪级工资："<<zggz[i].pay_xinji<<endl;
		cout<<"职务津贴："<<zggz[i].pay_zw<<endl;
		cout<<"绩效工资："<<zggz[i].pay_xiaoji<<endl;
		cout<<"应发工资："<<zggz[i].pay_yf<<endl;
		cout<<"个人所得税："<<zggz[i].duty<<endl;
		cout<<"实发工资："<<zggz[i].pay_sf<<endl;
	}
}			//浏览职工工资数据函数
void modify();			//修改职工工资数据函数
void del();				//删除职工工资数据函数
void add()
{
	int add_num;
	cout<<"请输入需存入的职工人数："<<endl;
	cin>>add_num;
	for(int i=n;i<n+add_num;++i)
	{
		cin>>zggz[i].num>>zggz[i].name>>zggz[i].pay_gw>>zggz[i].pay_xinji>>zggz[i].pay_zw>>zggz[i].pay_xiaoji;
		zggz[i].pay_yf=zggz[i].pay_gw+zggz[i].pay_xiaoji+zggz[i].pay_xinji+zggz[i].pay_zw;
	}
		n=n+add_num;

};


int main()
{
read();

	for(int for_main=0;for_main<=1;)
	{
		int choose_num;
	   
	cout<<"欢迎使用职工管理系统"<<endl;
	cout<<"请选择你要使用的功能（键盘输入数字，回车确认）"<<endl;
	cout<<"1.查询"<<"\n"<<"2.修改"<<"\n"<<"3.添加"<<"\n"<<"4.删除"<<"\n"<<"5.浏览"<<"\n"<<"6.保存"<<"\n"<<"7.退出"<<endl;
	cin>>choose_num;
	if(choose_num<8&&choose_num>0)
	{
	switch(choose_num)
	{
	    case 1:cout<<"已进入查询模块";
			{
				find();
			    break;
			}
	    case 2:cout<<"已进入修改模块";
			
	    case 3: 
			{
			cout<<"已进入添加模块";
			add();
			
			
		
		break;
		}
		









	case 4:cout<<"已进入删除模块";break;
	case 5:
		{
			cout<<"已进入浏览模块";
			list();
			break;
		}
	case 6:
		{
			cout<<"已保存";
			write();
			break;
		}
	case 7:
		{cout<<"系统退出，欢迎再次使用！";
		   for_main=2;break;
		}
	}
	}
	else{
		cout<<"请重新选择功能"<<endl;
	}
	}

   	
	system("pause");
	return 0;
}