/*************************************************
Copyright (C), 1988-1999, Huawei Tech. Co., Ltd.
File name: main.cpp
Author: Zhuchuankai Version: 0.1 Date: 2018-6-28// 作者、版本及完成日期
Description: // 用于详细说明此程序文件完成的主要功能，与其他模块
// 或函数的接口，输出值、取值范围、含义及参数间的控
// 制、顺序、独立或依赖等关系
Others: // 其它内容的说明
Function List: // 主要函数列表，每条记录应包括函数名及功能简要说明
1.grsds(int i)---------税计算
2.read()---------------读取职工工资数据函数,主函数执行时要调用和必须调用的第一个函数
3.write()--------------保存职工工资数据函数
4.find()---------------查询职工工资数据函数
5.list()---------------浏览职工工资数据函数
6.modify()-------------修改职工工资数据函数
7.del()----------------删除职工工资数据函数
8.add()----------------添加职工工资数据函数
History: // 修改历史记录列表，每条修改记录应包括修改日期、修改
// 者及修改内容简述
1. Date:
Author:
Modification:
2. ...
*************************************************/
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

	if(zggz[i].pay_yf <= 500)
    {
        zggz[i].duty = zggz[i].pay_yf*0.05;
    }

    else if(zggz[i].pay_yf <= 2000 && zggz[i].pay_yf > 500)
    {
        zggz[i].duty = (zggz[i].pay_yf-500) * 0.1 + 500 * 0.05;
    }

    else if(zggz[i].pay_yf <= 5000 && zggz[i].pay_yf > 2000)
    {
         zggz[i].duty = (zggz[i].pay_yf - 2000) * 0.15 + 1500 * 0.1 + 500 * 0.05;
    }

    else if(zggz[i].pay_yf <= 20000 && zggz[i].pay_yf > 5000)
    {
        zggz[i].duty = (zggz[i].pay_yf - 5000) * 0.20 + 3000 * 0.15 + 1500 * 0.1 + 500 * 0.05;
    }

    else if(zggz[i].pay_yf <= 40000 && zggz[i].pay_yf > 20000)
    {
        zggz[i].duty = (zggz[i].pay_yf - 20000) * 0.25 + 15000 * 0.2 + 3000 * 0.15 + 1500 * 0.1 + 500 * 0.05;
    }

	else if(zggz[i].pay_yf <= 40000 && zggz[i].pay_yf > 20000)
    {
        zggz[i].duty = (zggz[i].pay_yf - 20000) * 0.25 + 15000 * 0.2 + 3000 * 0.15 + 1500 * 0.1 + 500 * 0.05;
    }

	else if(zggz[i].pay_yf <= 60000 && zggz[i].pay_yf > 40000)
    {
        zggz[i].duty = (zggz[i].pay_yf - 40000) * 0.3 + 20000 * 0.25 + 15000 * 0.2 + 3000 * 0.15 + 1500 * 0.1 + 500 * 0.05;
    }

	else if(zggz[i].pay_yf <= 80000 && zggz[i].pay_yf > 60000)
    {
        zggz[i].duty = (zggz[i].pay_yf - 60000) * 0.35 + 20000 * 0.3 + 20000 * 0.25 + 15000 * 0.2 + 3000 * 0.15 + 1500 * 0.1 + 500 * 0.05;
    }

	else if(zggz[i].pay_yf <= 100000 && zggz[i].pay_yf > 80000)
    {
        zggz[i].duty = (zggz[i].pay_yf - 80000) * 0.4 + 20000 * 0.35 + 20000 * 0.3 + 20000 * 0.25 + 15000 * 0.2 + 3000 * 0.15 + 1500 * 0.1 + 500 * 0.05;
    }

	else if(zggz[i].pay_yf > 100000)
    {
        zggz[i].duty = (zggz[i].pay_yf - 100000) * 0.45 + 20000 * 0.4 + 20000 * 0.35 + 20000 * 0.3 + 20000 * 0.25 + 15000 * 0.2 + 3000 * 0.15 + 1500 * 0.1 + 500 * 0.05;
    }

}

int read()
{
	FILE*fp;
    fp=fopen("gz.dat", "a+");// localfile文件名
    fseek(fp,0,SEEK_SET);
    fseek(fp,0,SEEK_END);

    long longBytes = ftell(fp) / sizeof(struct zggz);// 统计人数
    n = longBytes;
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
    fp=fopen("gz.dat", "wb");
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
	for(int i=0; i<n; i++)
	{
		if(!strcmp(gonghao, zggz[i].num))
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
	for(int i=0; i<n; i++)
	{
		printf("\n         工号：");
		printf("%s",zggz[i].num);
	    printf("\n         名字：");
		printf("%s",zggz[i].name);
		printf("\n         岗位工资：");
		printf("%g",zggz[i].pay_gw);
		printf("\n         薪级工资：");
		printf("%g",zggz[i].pay_xinji);
		printf("\n         职务津贴：");
		printf("%g",zggz[i].pay_zw);
		printf("\n         绩效工资：");
		printf("%g",zggz[i].pay_xiaoji);
		printf("\n         应发工资：");
		printf("%g",zggz[i].pay_yf);
		printf("\n         个人所得税：");
		printf("%g",zggz[i].duty);
		printf("\n         实发工资：");
		printf("%g\n",zggz[i].pay_sf);
	}
}			//浏览职工工资数据函数

void modify()
{
	char gonghao[10];
	cout<<"请输入查询工号："<<endl;
	cin>>gonghao;
	for(int i=0; i<n; i++)
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
	for(int i=0; i<n; i++)
	{
		if(!strcmp(gonghao, zggz[i].num))
		{
			printf("是否确认删除该记录?（请输入y/n）\n");
			scanf("%s", choose);
			if(!strcmp(choose, "y"))
			{
				printf("开始删除\n");
				for(int j=i;j<n-1;j++)
				{
					strcpy(zggz[j].num, zggz[j+1].num);
					strcpy(zggz[j].name, zggz[j+1].name);
					zggz[j].pay_gw = zggz[j+1].pay_gw;
					zggz[j].pay_sf = zggz[j+1].pay_sf;
					zggz[j].pay_xiaoji = zggz[j+1].pay_xiaoji;
					zggz[j].pay_xinji = zggz[j+1].pay_xinji;
					zggz[j].pay_yf = zggz[j+1].pay_yf;
					zggz[j].pay_zw = zggz[j+1].pay_zw;
				}
				n = n-1;
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
	for(int i=n; i<n+add_num; ++i)
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
		zggz[i].pay_yf = zggz[i].pay_gw + zggz[i].pay_xiaoji + zggz[i].pay_xinji + zggz[i].pay_zw;
		grsds(i);
		zggz[i].pay_sf = zggz[i].pay_yf - zggz[i].duty;
	}
		n = n + add_num;

};

int main()
{
	read();
    for(int for_main=0; for_main<=1; )
	{
		int choose_num;
		printf("\n        ### 欢迎使用广西民族大学软件与信息安全学院职工工资管理系统 ###");
		printf("\n\n\n        请选择 <1 - 7> :");
		printf("\n        ==============================================================");
		printf("\n        |      1.查询职工工资记录                                    |");
		printf("\n        |      2.修改                                                |");
		printf("\n        |      3.添加                                                |");
		printf("\n        |      4.删除                                                |");
		printf("\n        |      5.保存数据到文件                                      |");
		printf("\n        |      6.浏览职工记录                                        |");
		printf("\n        |      7.退出系统                                            |");
		printf("\n        ==============================================================");
		printf("\n         你的选择是:");
		scanf("%d", &choose_num);
		if(choose_num<8&&choose_num>0)
		{
			switch(choose_num)
			{
			    case 1:
					{
						printf("\n已进入查询模块\n");
						find();
			            break;
					}
				case 2:
					{
						printf("\n已进入修改模块\n");
			            modify();
			            break;
					}
				case 3: 
					{
			            printf("\n已进入添加模块\n");
			            add();
			            break;
					}
		        case 4:
					{
			            printf("\n已进入删除模块\n");
			            del();
			            break;
					}
				case 5:
					{
			            printf("\n已保存\n");
			            write();
			            break;
					}
				case 6:
					{
						printf("\n已进入浏览模块\n");
			            list();
			            break;
					}
				case 7:
					{
						printf("\n系统退出，欢迎再次使用！\n");
		                for_main=2;
						break;
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