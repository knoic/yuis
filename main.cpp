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
cout<<longBytes;
	return 0;
}       //��ȡְ���������ݺ���,������ִ��ʱҪ���úͱ�����õĵ�һ������
void write();        //����ְ���������ݺ���
void find();		 //��ѯְ���������ݺ���
void list();			//���ְ���������ݺ���
void modify();			//�޸�ְ���������ݺ���
void del();				//ɾ��ְ���������ݺ���



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