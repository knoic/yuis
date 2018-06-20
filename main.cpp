#include<iostream>
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

/*******************************************************************************************************
放弃的类
class Zg{
public: 
	Zg(char *x_name,char *x_num,float x_pay_gw,float x_pay_xinji,float x_pay_zw,float x_pay_xiaoji=0);
	
	void new_writer();
	void disp()
	{
		 cout<<pay_gw<<pay_xinji<<pay_zw<<pay_xiaoji<<pay_yf<<pay_sf<<endl;     
	
	
	
	};
	void getname();
	void getnum();

private:
	char *name;
	char *num;
	float pay_gw,           //岗位工资
		  pay_xinji,        //薪级工资
		  pay_zw,           //职务津贴
		  pay_xiaoji,       //绩效工资
		  pay_yf,           //应发工资
		  pay_sf,           //实发工资
		  duty;             //个人所得税
	static int count;       //统计职工人数

};
Zg::Zg(char *x_name,char *x_num,float x_pay_gw,float x_pay_xinji,float x_pay_zw,float x_pay_xiaoji)
{
	strcpy(name,x_name);
	strcpy(num,x_num);
	pay_gw=x_pay_gw;
	pay_xinji=x_pay_xinji;
	pay_zw=x_pay_zw;
	pay_xiaoji=x_pay_xiaoji;
	pay_yf=x_pay_gw+x_pay_xinji+x_pay_zw+x_pay_xiaoji;
	
}
*******************************************************************************************************/
void cal_duty()           //税计算
{



};
void read()
{
	char name_1[20];
	cout<<"请输入工号："<<endl;
	scanf("%",name_1);
	
}       //读取职工工资数据函数,主函数执行时要调用和必须调用的第一个函数
void write();        //保存职工工资数据函数
void find();		 //查询职工工资数据函数
void list();			//浏览职工工资数据函数
void modify();			//修改职工工资数据函数
void del();				//删除职工工资数据函数



int main()
{
	int choose_num;
	
	 ifstream fin("gz.dat",ios::in);//以输入形式打开gz.dat
	if(!fin)
	{
        cout<<"Cannot open the file.\n";
    	exit(1);
	}
	/* fstream fout("gz.dat", ios::out);
   fout.write((char*)&a, sizeof(A));
    fout.close();
    fstream fin("gz.dat", ios::in);
   fin.read((char*)&b, sizeof(A));
    fin.close();*/

	cout<<"欢迎使用职工管理系统"<<endl;
	cout<<"请选择你要使用的功能（键盘输入数字，回车确认）"<<endl;
	cout<<"1.查询"<<"\n"<<"2.修改"<<"\n"<<"3.添加"<<"\n"<<"4.删除"<<"\n"<<"5.浏览"<<"\n"<<"6.保存"<<"\n"<<"7.退出"<<endl;
	cin>>choose_num;
	if(choose_num<8&&choose_num>0)
	{
	switch(choose_num)
	{
	    case 1:cout<<"已进入查询模块";break;
	case 2:cout<<"已进入修改模块";break;
	case 3: 
		{
			cout<<"已进入添加模块";
			char c_name[20],c_num[10];
			float c_pay_gw,c_pay_xinji,c_pay_zw,c_pay_xiaoji;
			int n;
			cout<<"请输入需存入的职工人数："<<endl;
			cin>>n;
		
			struct zggz zg[100];
			for(int i=0;i<n;++i)
			{
				//scanf("%s %s %f %f %f %f",zg[i].num,zg[i].name,zg[i].pay_gw,zg[i].pay_xinji,zg[i].pay_zw,zg[i].pay_xiaoji);
				cin>>zg[i].num>>zg[i].name>>zg[i].pay_gw>>zg[i].pay_xinji>>zg[i].pay_zw>>zg[i].pay_xiaoji;
			}
			
		
			cout<<zg[0].pay_gw
				;
			
	
		/*	Zg add_zg(&c_name,&c_num,c_pay_gw,c_pay_xinji,c_pay_zw,c_pay_xiaoji);
		add_zg.disp();   */
			 ofstream fout("gz.dat",ios::out);//以输出形式打开gz.dat
    if(!fout)
	    {
		    cout<<"Cannot open the file.\n";
		    exit(1);
	    }
			for(int j=0;j<n;++j)
			{
				fout<<zg[j];
                fout.close();
			}



			break;
		}










	case 4:cout<<"已进入删除模块";break;
	case 5:cout<<"已进入浏览模块";break;
	case 6:

		cout<<"已保存";break;
	case 7:cout<<"系统退出，欢迎再次使用！";break;
	}
	}
	else{
		cout<<"请重新选择功能"<<endl;
	return 0;}

   
	system("pause");
	return 0;
}

