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
	float pay_gw;           //��λ����
	float pay_xinji;       //н������
	float pay_zw;        //ְ�����
	float pay_xiaoji;      //��Ч����
	float pay_yf;          //Ӧ������
	float pay_sf;         //ʵ������
	float duty;             //��������˰
}zggz[100];


void cal_duty()           //˰����
{



};
int read()
{
	FILE*fp;
    fp=fopen("gz.dat","rb");// localfile�ļ���
    fseek(fp,0,SEEK_SET);
    fseek(fp,0,SEEK_END);
    long longBytes=ftell(fp)/sizeof(struct zggz);// ͳ������
    n=longBytes;
    fseek(fp,0,SEEK_SET);
    if ( fp == NULL )
	{
		return -1 ;
	}
    fread( (char*)zggz , sizeof(struct zggz), n , fp ); //���ļ��ж�n���ṹ�������
	fclose(fp);
    cout<<n<<endl;
    cout<<zggz[2].name;
	return 0;
}       //��ȡְ���������ݺ���,������ִ��ʱҪ���úͱ�����õĵ�һ������
int write()
{
	FILE *fp ;
    fp=fopen("gz.dat" , "wb" );
    if ( fp == NULL )
    {
		return -1 ;
	}
    fwrite( (char*)zggz , sizeof(struct zggz), n , fp ); //������д���ļ�
	fclose(fp);
};        //����ְ���������ݺ���
void find();		 //��ѯְ���������ݺ���
void list()
{
	for(int i=0;i<n;i++)
	{
		cout<<"���ţ�"<<zggz[i].num<<endl;
		cout<<"���֣�"<<zggz[i].name<<endl;
		cout<<"��λ���ʣ�"<<zggz[i].pay_gw<<endl;
		cout<<"н�����ʣ�"<<zggz[i].pay_xinji<<endl;
		cout<<"ְ�������"<<zggz[i].pay_zw<<endl;
		cout<<"��Ч���ʣ�"<<zggz[i].pay_xiaoji<<endl;
		cout<<"Ӧ�����ʣ�"<<zggz[i].pay_yf<<endl;
		cout<<"��������˰��"<<zggz[i].duty<<endl;
		cout<<"ʵ�����ʣ�"<<zggz[i].pay_sf<<endl;
	}
}			//���ְ���������ݺ���
void modify();			//�޸�ְ���������ݺ���
void del();				//ɾ��ְ���������ݺ���
void add()
{
	int add_num;
	cout<<"������������ְ��������"<<endl;
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
	    struct zggz zg_read[100];
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
				list();
				break;
			}
	    case 2:cout<<"�ѽ����޸�ģ��";
			
	    case 3: 
			{
			cout<<"�ѽ������ģ��";
			add();
			
			
		
		/*	cout<<zg[0].pay_gw;
			FILE *fp ;
            fp=fopen("gz.dat" , "a+" );
            if ( fp == NULL )
            return -1 ;
            fwrite( (char*)zg , sizeof(struct zggz), n , fp ); //������д���ļ�
		

        
            fclose(fp);
            fp=fopen("gz.dat" , "rb" );
            if ( fp == NULL )
            return -1 ;
            fread( (char*)zg_read , sizeof(struct zggz), 1 , fp ); //���ļ��ж������ṹ������ݣ�Ҳ����һ��һ���Ķ�
            fclose(fp);
            cout<<zg_read[0].name<<zg_read[0].num<<zg_read[0].pay_gw;
		    return 0;
		    
			*/break;
		}
		









	case 4:cout<<"�ѽ���ɾ��ģ��";break;
	case 5:cout<<"�ѽ������ģ��";break;
	case 6:
		{
			cout<<"�ѱ���";
			write();
			break;
		}
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