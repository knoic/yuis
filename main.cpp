#include<iostream>
#include<string>
#include<fstream>
using namespace std;
struct zggz
{
    char name[20];
	char num[10];
	float pay_gw;           //��λ����
	float pay_xinji;       //н������
	float pay_zw;        //ְ�����
	float pay_xiaoji;      //��Ч����
	float pay_yf;          //Ӧ������
	float pay_sf;         //ʵ������
	float duty;             //��������˰
};

/*******************************************************************************************************
��������
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
	float pay_gw,           //��λ����
		  pay_xinji,        //н������
		  pay_zw,           //ְ�����
		  pay_xiaoji,       //��Ч����
		  pay_yf,           //Ӧ������
		  pay_sf,           //ʵ������
		  duty;             //��������˰
	static int count;       //ͳ��ְ������

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
void cal_duty()           //˰����
{



};
void read()
{
	char name_1[20];
	cout<<"�����빤�ţ�"<<endl;
	scanf("%",name_1);
	
}       //��ȡְ���������ݺ���,������ִ��ʱҪ���úͱ�����õĵ�һ������
void write();        //����ְ���������ݺ���
void find();		 //��ѯְ���������ݺ���
void list();			//���ְ���������ݺ���
void modify();			//�޸�ְ���������ݺ���
void del();				//ɾ��ְ���������ݺ���



int main()
{
	int choose_num;
	
	 ifstream fin("gz.dat",ios::in);//��������ʽ��gz.dat
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

	cout<<"��ӭʹ��ְ������ϵͳ"<<endl;
	cout<<"��ѡ����Ҫʹ�õĹ��ܣ������������֣��س�ȷ�ϣ�"<<endl;
	cout<<"1.��ѯ"<<"\n"<<"2.�޸�"<<"\n"<<"3.���"<<"\n"<<"4.ɾ��"<<"\n"<<"5.���"<<"\n"<<"6.����"<<"\n"<<"7.�˳�"<<endl;
	cin>>choose_num;
	if(choose_num<8&&choose_num>0)
	{
	switch(choose_num)
	{
	    case 1:cout<<"�ѽ����ѯģ��";break;
	case 2:cout<<"�ѽ����޸�ģ��";break;
	case 3: 
		{
			cout<<"�ѽ������ģ��";
			char c_name[20],c_num[10];
			float c_pay_gw,c_pay_xinji,c_pay_zw,c_pay_xiaoji;
			int n;
			cout<<"������������ְ��������"<<endl;
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
			 ofstream fout("gz.dat",ios::out);//�������ʽ��gz.dat
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










	case 4:cout<<"�ѽ���ɾ��ģ��";break;
	case 5:cout<<"�ѽ������ģ��";break;
	case 6:

		cout<<"�ѱ���";break;
	case 7:cout<<"ϵͳ�˳�����ӭ�ٴ�ʹ�ã�";break;
	}
	}
	else{
		cout<<"������ѡ����"<<endl;
	return 0;}

   
	system("pause");
	return 0;
}

