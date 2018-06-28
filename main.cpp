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


void grsds(int i)           //税计算
{
    printf("税计算：");
	if(zggz[i].pay_yf<=500)
    {
        zggz[i].duty=zggz[i].pay_yf*0.05;
    }
    else if(zggz[i].pay_yf<=2000 && zggz[i].pay_yf>500)
    {
        zggz[i].duty=(zggz[i].pay_yf-500)*0.1+500*0.05;
    }
    else if(zggz[i].pay_yf<=5000 && zggz[i].pay_yf>2000)
    {
         zggz[i].duty=(zggz[i].pay_yf-2000)*0.15+1500*0.1+500*0.05;
    }
    else if(zggz[i].pay_yf<=20000 && zggz[i].pay_yf>5000)
    {
        zggz[i].duty=(zggz[i].pay_yf-5000)*0.20+3000*0.15+1500*0.1+500*0.05;
    }
    else if(zggz[i].pay_yf<=40000 && zggz[i].pay_yf>20000)
    {
        zggz[i].duty=(zggz[i].pay_yf-20000)*0.25+15000*0.2+3000*0.15+1500*0.1+500*0.05;
    }
	else if(zggz[i].pay_yf<=40000 && zggz[i].pay_yf>20000)
    {
        zggz[i].duty=(zggz[i].pay_yf-20000)*0.25+15000*0.2+3000*0.15+1500*0.1+500*0.05;
    }
	else if(zggz[i].pay_yf<=60000 && zggz[i].pay_yf>40000)
    {
        zggz[i].duty=(zggz[i].pay_yf-40000)*0.3+20000*0.25+15000*0.2+3000*0.15+1500*0.1+500*0.05;
    }
	else if(zggz[i].pay_yf<=80000 && zggz[i].pay_yf>60000)
    {
        zggz[i].duty=(zggz[i].pay_yf-60000)*0.35+20000*0.3+20000*0.25+15000*0.2+3000*0.15+1500*0.1+500*0.05;
    }
	else if(zggz[i].pay_yf<=100000 && zggz[i].pay_yf>80000)
    {
        zggz[i].duty=(zggz[i].pay_yf-80000)*0.4+20000*0.35+20000*0.3+20000*0.25+15000*0.2+3000*0.15+1500*0.1+500*0.05;
    }
	else if(zggz[i].pay_yf>100000)
    {
        zggz[i].duty=(zggz[i].pay_yf-100000)*0.45+20000*0.4+20000*0.35+20000*0.3+20000*0.25+15000*0.2+3000*0.15+1500*0.1+500*0.05;
    }
}
int read()
{
	FILE*fp;
    fp=fopen("gz.dat","a+");// localfile文件名
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
    cout<<n<<endl;                          //测试用人数统计
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
	char gonghao[10];
	printf("请输入查询工号：\n");
	scanf("%s", gonghao);
	for(int i=0;i<n;i++)
	{
		if(!strcmp(gonghao,zggz[i].num))
		{
			printf("工号：");
			printf("%s",zggz[i].num);
			printf("\n名字：");
			printf("%s",zggz[i].name);
			printf("\n岗位工资：");
			printf("%f",zggz[i].pay_gw);
			printf("\n薪级工资：");
			printf("%f",zggz[i].pay_xinji);
			printf("\n职务津贴：");
			printf("%f",zggz[i].pay_zw);
			printf("\n绩效工资：");
			printf("%f",zggz[i].pay_xiaoji);
			printf("\n应发工资：");
			printf("%f",zggz[i].pay_yf);
			printf("\n个人所得税：");
			printf("%f",zggz[i].duty);
			printf("\n实发工资：");
			printf("%f",zggz[i].pay_sf);
            
			/*cout<<"工号："<<zggz[i].num<<endl;
		    cout<<"名字："<<zggz[i].name<<endl;
		    cout<<"岗位工资："<<zggz[i].pay_gw<<endl;
		    cout<<"薪级工资："<<zggz[i].pay_xinji<<endl;
		    cout<<"职务津贴："<<zggz[i].pay_zw<<endl;
		    cout<<"绩效工资："<<zggz[i].pay_xiaoji<<endl;
		    cout<<"应发工资："<<zggz[i].pay_yf<<endl;
		    cout<<"个人所得税："<<zggz[i].duty<<endl;
		    cout<<"实发工资："<<zggz[i].pay_sf<<endl;
			*/
			break;
		}
	
	}
	if(i==n)
	{
		printf("查无此人\n");
	}
	return 0;
	
};		 //查询职工工资数据函数

void list()
{
	for(int i=0;i<n;i++)
	{
		printf("工号：");
		printf("%s",zggz[i].num);
	    printf("\n名字：");
		printf("%s",zggz[i].name);
		printf("\n岗位工资：");
		printf("%g",zggz[i].pay_gw);
		printf("\n薪级工资：");
		printf("%g",zggz[i].pay_xinji);
		printf("\n职务津贴：");
		printf("%g",zggz[i].pay_zw);
		printf("\n绩效工资：");
		printf("%g",zggz[i].pay_xiaoji);
		printf("\n应发工资：");
		printf("%g",zggz[i].pay_yf);
		printf("\n个人所得税：");
		printf("%g",zggz[i].duty);
		printf("\n实发工资：");
		printf("%g",zggz[i].pay_sf);
		/*cout<<"工号："<<zggz[i].num<<endl;
		cout<<"名字："<<zggz[i].name<<endl;
		cout<<"岗位工资："<<zggz[i].pay_gw<<endl;
		cout<<"薪级工资："<<zggz[i].pay_xinji<<endl;
		cout<<"职务津贴："<<zggz[i].pay_zw<<endl;
		cout<<"绩效工资："<<zggz[i].pay_xiaoji<<endl;
		cout<<"应发工资："<<zggz[i].pay_yf<<endl;
		cout<<"个人所得税："<<zggz[i].duty<<endl;
		cout<<"实发工资："<<zggz[i].pay_sf<<endl;*/
	}
}			//浏览职工工资数据函数
void modify()
{
	char gonghao[10];
	cout<<"请输入查询工号："<<endl;
	cin>>gonghao;
	for(int i=0;i<n;i++)
	{
		if(!strcmp(gonghao,zggz[i].num))
		{
			printf("\n开始修改\n");
		    printf("\n请输入姓名\n");
			scanf("%s", zggz[i].name);
			printf("\n岗位工资：\n");
			scanf("%f", &zggz[i].pay_gw);
			printf("\n薪级工资：\n");
			scanf("%f", &zggz[i].pay_xinji);
			printf("\n职务津贴：\n");
			scanf("%f", &zggz[i].pay_zw);
			printf("\n绩效工资：\n");
			scanf("%f", &zggz[i].pay_xiaoji);
			zggz[i].pay_yf=zggz[i].pay_gw+zggz[i].pay_xiaoji+zggz[i].pay_xinji+zggz[i].pay_zw;
		    grsds(i);
		    zggz[i].pay_sf=zggz[i].pay_yf-zggz[i].duty;
		}
	
	}
	if(i==n)
	{
		printf("查无此人\n");
	}

};			//修改职工工资数据函数
void del()
{
	char gonghao[10],choose[1];
	printf("请输入需要修改的职工工号\n");
	scanf("%s", gonghao);
	for(int i=0;i<n;i++)
	{
		if(!strcmp(gonghao,zggz[i].num))
		{
			printf("是否确认删除该记录?（请输入y/n）\n");
			scanf("%s", choose);
			if(!strcmp(choose,"y"))
			{
				printf("开始删除\n");
				for(int j=i;j<n-1;j++)
				{
					strcpy(zggz[j].num,zggz[j+1].num);
					strcpy(zggz[j].name,zggz[j+1].name);
					zggz[j].pay_gw=zggz[j+1].pay_gw;
					zggz[j].pay_sf=zggz[j+1].pay_sf;
					zggz[j].pay_xiaoji=zggz[j+1].pay_xiaoji;
					zggz[j].pay_xinji=zggz[j+1].pay_xinji;
					zggz[j].pay_yf=zggz[j+1].pay_yf;
					zggz[j].pay_zw=zggz[j+1].pay_zw;
				}
				n=n-1;
				printf("删除完成，请及时保存\n");

			}
			else
			{
				printf("放弃删除\n");
			}


			
		}
	
	}
	if(i==n)
	{
		printf("查无此人\n");
	}

};				//删除职工工资数据函数
void add()
{
	int add_num;
	printf("请输入需存入的职工人数：\n");
	scanf("%d", &add_num);
	for(int i=n;i<n+add_num;++i)
	{
		printf("\n请输入工号\n");
		scanf("%s", zggz[i].num);
		printf("\n请输入姓名\n");
		scanf("%s", zggz[i].name);
		printf("\n岗位工资：\n");
		scanf("%f", &zggz[i].pay_gw);
		printf("\n薪级工资：\n");
		scanf("%f", &zggz[i].pay_xinji);
		printf("\n职务津贴：\n");
		scanf("%f", &zggz[i].pay_zw);
		printf("\n绩效工资：\n");
		scanf("%f", &zggz[i].pay_xiaoji);
		zggz[i].pay_yf=zggz[i].pay_gw+zggz[i].pay_xiaoji+zggz[i].pay_xinji+zggz[i].pay_zw;
		grsds(i);
		zggz[i].pay_sf=zggz[i].pay_yf-zggz[i].duty;

		/*cin>>zggz[i].num>>zggz[i].name>>zggz[i].pay_gw>>zggz[i].pay_xinji>>zggz[i].pay_zw>>zggz[i].pay_xiaoji;
		zggz[i].pay_yf=zggz[i].pay_gw+zggz[i].pay_xiaoji+zggz[i].pay_xinji+zggz[i].pay_zw;*/
	}
		n=n+add_num;

};


int main()
{
	read();
    for(int for_main=0;for_main<=1;)
	{
		int choose_num;
		printf("\n欢迎使用职工管理系统");
		printf("\n请选择你要使用的功能（键盘输入数字，回车确认）");
		printf("\n1.查询\n2.修改\n3.添加\n4.删除\n5.浏览\n6.保存\n7.退出\n");
		scanf("%d", &choose_num);
		if(choose_num<8&&choose_num>0)
		{
			switch(choose_num)
			{
			    case 1:
					{
						printf("\n已进入查询模块");
						find();
			            break;
					}
				case 2:
					{
						printf("\n已进入修改模块");
			            modify();
			            break;
					}
				case 3: 
					{
			            printf("\n已进入添加模块");
			            add();
			            break;
					}
		        case 4:
					{
			            printf("\n已进入删除模块");
			            del();
			            break;
					}
				case 5:
					{
			            printf("\n已进入浏览模块");
			            list();
			            break;
					}
				case 6:
					{
			            printf("\n已保存");
			            write();
			            break;
					}
				case 7:
					{
						printf("\n系统退出，欢迎再次使用！");
		                for_main=2;break;
					}
			}
	}
		else
		{
			printf("\n请重新选择功能");
		}
	}

   	
	system("pause");
	return 0;
}