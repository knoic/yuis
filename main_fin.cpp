/*************************************************
Copyright (C), 1988-1999, Huawei Tech. Co., Ltd.
File name: main.cpp
Author: Zhuchuankai Version: 0.1 Date: 2018-6-28
Description: // 职工工资管理
Function List: // 主要函数列表，每条记录应包括函数名及功能简要说明
1.grsds(int i)---------税计算
2.read()---------------读取职工工资数据函数,主函数执行时要调用和必须调用的第一个函数
3.write()--------------保存职工工资数据函数
4.find()---------------查询职工工资数据函数
5.list()---------------浏览职工工资数据函数
6.modify()-------------修改职工工资数据函数
7.del()----------------删除职工工资数据函数
8.add()----------------添加职工工资数据函数
History: 
1. Date:  2018-6-18-----2018-6-29
Author:zhuchuankai
Modification:主体编写
2. ...
*************************************************/
#include<iostream>
#include<fstream>
#include<string.h>
#include<stdio.h>
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


/*************************************************
Function: // grsds
Description: // 个人所得税计算
Calls: // 无
Called By: // modify(), add()
Output: // 对zggz[i].duty赋值
*************************************************/
void grsds(int i)           //调用函数时，常处于for循环语句，故使用与循环变量同名的i
{
	float zggz_yns;         //应纳税所得额
	if(zggz[i].pay_yf <= 3500)
	{
		zggz[i].duty=0;
	}
	else
	{
		zggz_yns=zggz[i].pay_yf-3500;
		if(zggz_yns <= 500)
        {
            zggz[i].duty = zggz_yns*0.05;
        }
		else if(zggz_yns <= 2000 && zggz_yns > 500)
		{
            zggz[i].duty = (zggz_yns-500) * 0.1 + 500 * 0.05;
        }

        else if(zggz_yns <= 5000 && zggz_yns > 2000)
        {
            zggz[i].duty = (zggz_yns - 2000) * 0.15 + 1500 * 0.1 + 500 * 0.05;
        }

        else if(zggz_yns <= 20000 && zggz_yns > 5000)
        {
            zggz[i].duty = (zggz_yns - 5000) * 0.20 + 3000 * 0.15 + 1500 * 0.1 + 500 * 0.05;
        }

        else if(zggz_yns <= 40000 && zggz_yns > 20000)
        {
            zggz[i].duty = (zggz_yns - 20000) * 0.25 + 15000 * 0.2 + 3000 * 0.15 + 1500 * 0.1 + 500 * 0.05;
        }

	    else if(zggz_yns <= 60000 && zggz_yns > 40000)
        {
            zggz[i].duty = (zggz_yns - 40000) * 0.3 + 20000 * 0.25 + 15000 * 0.2 + 3000 * 0.15 + 1500 * 0.1 + 500 * 0.05;
        }

	    else if(zggz_yns <= 80000 && zggz_yns > 60000)
        {
            zggz[i].duty = (zggz_yns - 60000) * 0.35 + 20000 * 0.3 + 20000 * 0.25 + 15000 * 0.2 + 3000 * 0.15 + 1500 * 0.1 + 500 * 0.05;
        }

	    else if(zggz_yns <= 100000 && zggz_yns > 80000)
        {
            zggz[i].duty = (zggz_yns - 80000) * 0.4 + 20000 * 0.35 + 20000 * 0.3 + 20000 * 0.25 + 15000 * 0.2 + 3000 * 0.15 + 1500 * 0.1 + 500 * 0.05;
        }

	    else if(zggz_yns > 100000)
        {
            zggz[i].duty = (zggz_yns - 100000) * 0.45 + 20000 * 0.4 + 20000 * 0.35 + 20000 * 0.3 + 20000 * 0.25 + 15000 * 0.2 + 3000 * 0.15 + 1500 * 0.1 + 500 * 0.05;
        }
	}

}

/*************************************************
Function: // read
Description: // 读取职工工资数据函数,主函数执行时要调用和必须调用的第一个函数
Called By: // main()
Input: // 本地文件的读取
Output: // 将本地文件数据存入zggz[]
Return: // 函数返回值的说明
*************************************************/
int read()
{
	FILE*fp;
    fp=fopen("gz.dat", "a+");// localfile文件名,本地必须有此文件
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
	return 0;
}       

/*************************************************
Function: // write
Description: // 保存职工工资数据函数
Called By: // main()
Output: // 将zggz[]数据存入本地文件
*************************************************/
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
};        

/*************************************************
Function: // find
Description: // 查询职工工资数据函数
Called By: // main()
Input: // 键盘键入工号
Output: // 输出特定职工数据
*************************************************/
int find()
{
	int i,k=0;           //循环变量,判断变量
	char gonghao[10];
	printf("请输入查询工号：\n");
	scanf("%s", gonghao);
	for(i=0; i<n; i++)
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
			k=1;
            
		}
	
	}
	if(k==0)
	{
		printf("\n查无此人：");
	}
	
	return 0;
	
};		 

/*************************************************
Function: // list
Description: //浏览职工工资数据函数
Called By: // main()
Output: // 输出全部职工数据
*************************************************/
void list()
{
	for(int i=0; i<n; i++)
	{
		printf("         工号：");
		printf("%s",zggz[i].num);
	    printf("              名字：");
		printf("%s",zggz[i].name);
		printf("\n         岗位工资：");
		printf("%g",zggz[i].pay_gw);
		printf("              薪级工资：");
		printf("%g",zggz[i].pay_xinji);
		printf("\n         职务津贴：");
		printf("%g",zggz[i].pay_zw);
		printf("              绩效工资：");
		printf("%g",zggz[i].pay_xiaoji);
		printf("\n         应发工资：");
		printf("%g",zggz[i].pay_yf);
		printf("              个人所得税：");
		printf("%g",zggz[i].duty);
		printf("\n         实发工资：");
		printf("%g\n",zggz[i].pay_sf);
	}
}		

/*************************************************
Function: // read
Description: 	// 修改职工工资数据函数
Called By: // main()
Input: // 键盘键入工号
*************************************************/
void modify()
{
	int i,k=0;           //循环变量,判断变量
	char gonghao[10];
	printf("\n请输入查询工号：\n");
	scanf("%s", gonghao);
	for(i=0; i<n; i++)
	{
		if(!strcmp(gonghao,zggz[i].num))
		{
			printf("\n已查询到此人");
			printf("\n工号：");
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

			printf("\n\n开始修改\n");
		    printf("请输入姓名\n");
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
			k=1;
		}
	
	}
	if(k==0)
	{
		printf("\n查无此人：");
	}

};		

/*************************************************
Function: // del
Description: //删除职工工资数据函数
Called By: // main()
Input: // 键盘键入工号
Output: // 修改zggz[]数据
*************************************************/
void del()
{
	int i,k=0;           //循环变量,判断变量
	char gonghao[10],choose[1];
	printf("请输入需要删除的职工工号\n");
	scanf("%s", gonghao);
	for(i=0; i<n; i++)
	{
		if(!strcmp(gonghao, zggz[i].num))
		{
			k=1;
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
					zggz[j].duty = zggz[j+1].duty;
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
	if(k==0)
	{
		printf("\n查无此人：");
	}
};				

/*************************************************
Function: // add
Description: // 添加职工数据
Called By: // main()
Input: // 键盘键入职工数据
Output: // 将数据存入zggz[]
*************************************************/
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
						system("cls");
						printf("\n已进入查询模块\n");
						find();
			            break;
					}
				case 2:
					{
						system("cls");
						printf("\n已进入修改模块\n");
			            modify();
			            break;
					}
				case 3: 
					{
						system("cls");
			            printf("\n已进入添加模块\n");
			            add();
			            break;
					}
		        case 4:
					{
						system("cls");
			            printf("\n已进入删除模块\n");
			            del();
			            break;
					}
				case 5:
					{
						system("cls");
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
						system("cls");
						printf("\n系统退出，欢迎再次使用！\n");
		                for_main=2;
						break;
					}
			}
	}
		else
		{
			system("cls");
			printf("\n请重新选择功能<1 - 7>");
		}
	}
    system("pause");
	return 0;
}