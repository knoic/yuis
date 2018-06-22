#include<iostream>
#include<stdio.h>
#include<string>
#include<fstream>
using namespace std;
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
};


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
cout<<longBytes;
	return 0;
}       //读取职工工资数据函数,主函数执行时要调用和必须调用的第一个函数
void write();        //保存职工工资数据函数
void find();		 //查询职工工资数据函数
void list();			//浏览职工工资数据函数
void modify();			//修改职工工资数据函数
void del();				//删除职工工资数据函数



int main()
{
read();

	for(int for_main=0;for_main<=1;)
	{
		int choose_num;
	    struct zggz zg_read[100];
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
				FILE *fp ;
				fp=fopen("gz.dat" , "rb" );
                if ( fp == NULL )
                {return -1 ;
				}
                fread( (char*)zg_read , sizeof(struct zggz), 1 , fp ); //从文件中读n个结构体的数据
				fclose(fp);
				break;
			}
	    case 2:cout<<"已进入修改模块";
			
	    case 3: 
			{
			cout<<"已进入添加模块";
			int n;
			cout<<"请输入需存入的职工人数："<<endl;
			cin>>n;
		
			struct zggz zg[100];
			for(int i=0;i<n;++i)
			{
				
				cin>>zg[i].num>>zg[i].name>>zg[i].pay_gw>>zg[i].pay_xinji>>zg[i].pay_zw>>zg[i].pay_xiaoji;
			}
			
		
			cout<<zg[0].pay_gw;
			FILE *fp ;
            fp=fopen("gz.dat" , "a+" );
            if ( fp == NULL )
            return -1 ;
            fwrite( (char*)zg , sizeof(struct zggz), n , fp ); //将数组写入文件
		

        
            fclose(fp);
            fp=fopen("gz.dat" , "rb" );
            if ( fp == NULL )
            return -1 ;
            fread( (char*)zg_read , sizeof(struct zggz), 1 , fp ); //从文件中读三个结构体的数据，也可以一个一个的读
            fclose(fp);
            cout<<zg_read[0].name<<zg_read[0].num<<zg_read[0].pay_gw;
		    return 0;
		    break;
		}
		









	case 4:cout<<"已进入删除模块";break;
	case 5:cout<<"已进入浏览模块";break;
	case 6:cout<<"已保存";break;
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