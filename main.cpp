#include<iostream>
#include<stdio.h>
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
int read()
{
	FILE *fp ;
				fp=fopen("gz.dat" , "rb" );
                if ( fp == NULL )
                {return -1 ;
				}
                fread( (char*)zg_read , sizeof(struct zggz), 1 , fp ); //���ļ��ж�n���ṹ�������
				fclose(fp); 
	
}       //��ȡְ���������ݺ���,������ִ��ʱҪ���úͱ�����õĵ�һ������
void write();        //����ְ���������ݺ���
void find();		 //��ѯְ���������ݺ���
void list();			//���ְ���������ݺ���
void modify();			//�޸�ְ���������ݺ���
void del();				//ɾ��ְ���������ݺ���



int main()
{
	for(int for_main=0;for_main<=1;)
	{int choose_num;
	struct zggz zg_read[100];
	
	/* ifstream fin("gz.dat",ios::in);//��������ʽ��gz.dat
	if(!fin)
	{
        cout<<"Cannot open the file.\n";
    	exit(1);
	}
	 fstream fout("gz.dat", ios::out);
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
	    case 1:cout<<"�ѽ����ѯģ��";
			{
				FILE *fp ;
				fp=fopen("gz.dat" , "rb" );
                if ( fp == NULL )
                {return -1 ;
				}
                fread( (char*)zg_read , sizeof(struct zggz), 1 , fp ); //���ļ��ж�n���ṹ�������
				fclose(fp);
				break;
			}
	    case 2:cout<<"�ѽ����޸�ģ��";
			
	    case 3: 
			{
			cout<<"�ѽ������ģ��";
			int n;
			cout<<"������������ְ��������"<<endl;
			cin>>n;
		
			struct zggz zg[100];
			for(int i=0;i<n;++i)
			{
				
				cin>>zg[i].num>>zg[i].name>>zg[i].pay_gw>>zg[i].pay_xinji>>zg[i].pay_zw>>zg[i].pay_xiaoji;
			}
			
		
			cout<<zg[0].pay_gw;
			FILE *fp ;
            fp=fopen("gz.dat" , "wb" );
            if ( fp == NULL )
            return -1 ;
            fwrite( (char*)zg , sizeof(struct zggz), 1 , fp ); //������д���ļ�
            fclose(fp);
            fp=fopen("gz.dat" , "rb" );
            if ( fp == NULL )
            return -1 ;
            fread( (char*)zg_read , sizeof(struct zggz), 1 , fp ); //���ļ��ж������ṹ������ݣ�Ҳ����һ��һ���Ķ�
            fclose(fp);
            cout<<zg_read[0].name<<zg_read[0].num<<zg_read[0].pay_gw;
		    return 0;
		    break;
		}
		









	case 4:cout<<"�ѽ���ɾ��ģ��";break;
	case 5:cout<<"�ѽ������ģ��";break;
	case 6:cout<<"�ѱ���";break;
	case 7:
		{cout<<"ϵͳ�˳�����ӭ�ٴ�ʹ�ã�";
		   for_main=2;break;
		}
	}
	}
	else{
		cout<<"������ѡ����"<<endl;
	}
	}

   
	system("pause");
	return 0;
}

