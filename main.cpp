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
int find()
{
	char gonghao[10];
	printf("�������ѯ���ţ�\n");
	scanf("%s", gonghao);
	for(int i=0;i<n;i++)
	{
	
	
	if(!strcmp(gonghao,zggz[i].num))
		{
			printf("���ţ�");
			printf("%s",zggz[i].num);
			printf("\n���֣�");
			printf("%s",zggz[i].name);
			printf("\n��λ���ʣ�");
			printf("%f",zggz[i].pay_gw);
			printf("\nн�����ʣ�");
			printf("%f",zggz[i].pay_xinji);
			printf("\nְ�������");
			printf("%f",zggz[i].pay_zw);
			printf("\n��Ч���ʣ�");
			printf("%f",zggz[i].pay_xiaoji);
			printf("\nӦ�����ʣ�");
			printf("%f",zggz[i].pay_yf);
			printf("\n��������˰��");
			printf("%f",zggz[i].duty);
			printf("\nʵ�����ʣ�");
			printf("%f",zggz[i].pay_sf);
            
			/*cout<<"���ţ�"<<zggz[i].num<<endl;
		    cout<<"���֣�"<<zggz[i].name<<endl;
		    cout<<"��λ���ʣ�"<<zggz[i].pay_gw<<endl;
		    cout<<"н�����ʣ�"<<zggz[i].pay_xinji<<endl;
		    cout<<"ְ�������"<<zggz[i].pay_zw<<endl;
		    cout<<"��Ч���ʣ�"<<zggz[i].pay_xiaoji<<endl;
		    cout<<"Ӧ�����ʣ�"<<zggz[i].pay_yf<<endl;
		    cout<<"��������˰��"<<zggz[i].duty<<endl;
		    cout<<"ʵ�����ʣ�"<<zggz[i].pay_sf<<endl;
			*/
			break;
		}
	
	}
	if(i==n)
	{
		printf("���޴���\n");
	}
	return 0;
	
};		 //��ѯְ���������ݺ���

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
void modify()
{
	char gonghao[10];
	cout<<"�������ѯ���ţ�"<<endl;
	cin>>gonghao;
	for(int i=0;i<n;i++)
	{
		if(!strcmp(gonghao,zggz[i].num))
		{
			cout<<"��ʼ�޸�"<<endl;
		    cout<<"���֣�";
			cin>>zggz[i].name;
		    cout<<"��λ���ʣ�";
			cin>>zggz[i].pay_gw;
		    cout<<"н�����ʣ�";
			cin>>zggz[i].pay_xinji;
		    cout<<"ְ�������";
			cin>>zggz[i].pay_zw;
		    cout<<"��Ч���ʣ�";
			cin>>zggz[i].pay_xiaoji;
		}
	
	}
	if(i==n)
	{
		printf("���޴���\n");
	}

};			//�޸�ְ���������ݺ���
void del()
{
	char gonghao[10],choose[1];
	printf("��������Ҫ�޸ĵ�ְ������\n");
	scanf("%s", gonghao);
	for(int i=0;i<n;i++)
	{
		if(!strcmp(gonghao,zggz[i].num))
		{
			printf("�Ƿ�ȷ��ɾ���ü�¼?��������y/n��\n");
			scanf("%s", choose);
			if(!strcmp(choose,"y"))
			{
				printf("��ʼɾ��\n");
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
				printf("ɾ����ɣ��뼰ʱ����\n");

			}
			else
			{
				printf("����ɾ��\n");
			}


			
		}
	
	}
	if(i==n)
	{
		printf("���޴���\n");
	}

};				//ɾ��ְ���������ݺ���
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
	   
	cout<<"��ӭʹ��ְ������ϵͳ"<<endl;
	cout<<"��ѡ����Ҫʹ�õĹ��ܣ������������֣��س�ȷ�ϣ�"<<endl;
	cout<<"1.��ѯ"<<"\n"<<"2.�޸�"<<"\n"<<"3.���"<<"\n"<<"4.ɾ��"<<"\n"<<"5.���"<<"\n"<<"6.����"<<"\n"<<"7.�˳�"<<endl;
	cin>>choose_num;
	if(choose_num<8&&choose_num>0)
	{
	switch(choose_num)
	{
	    case 1:
			{
				cout<<"�ѽ����ѯģ��";
			    find();
			    break;
			}
		case 2:
			{
				cout<<"�ѽ����޸�ģ��";
			    modify();
			    break;
			}
			
	    case 3: 
			{
			cout<<"�ѽ������ģ��";
			add();
			break;
			}
		









	case 4:
		{
			cout<<"�ѽ���ɾ��ģ��";
			del();
			break;
		}
	case 5:
		{
			cout<<"�ѽ������ģ��";
			list();
			break;
		}
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