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


void grsds(int i)           //˰����
{
    printf("˰���㣺");
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
    fp=fopen("gz.dat","a+");// localfile�ļ���
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
    cout<<n<<endl;                          //����������ͳ��
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
		printf("���ţ�");
		printf("%s",zggz[i].num);
	    printf("\n���֣�");
		printf("%s",zggz[i].name);
		printf("\n��λ���ʣ�");
		printf("%g",zggz[i].pay_gw);
		printf("\nн�����ʣ�");
		printf("%g",zggz[i].pay_xinji);
		printf("\nְ�������");
		printf("%g",zggz[i].pay_zw);
		printf("\n��Ч���ʣ�");
		printf("%g",zggz[i].pay_xiaoji);
		printf("\nӦ�����ʣ�");
		printf("%g",zggz[i].pay_yf);
		printf("\n��������˰��");
		printf("%g",zggz[i].duty);
		printf("\nʵ�����ʣ�");
		printf("%g",zggz[i].pay_sf);
		/*cout<<"���ţ�"<<zggz[i].num<<endl;
		cout<<"���֣�"<<zggz[i].name<<endl;
		cout<<"��λ���ʣ�"<<zggz[i].pay_gw<<endl;
		cout<<"н�����ʣ�"<<zggz[i].pay_xinji<<endl;
		cout<<"ְ�������"<<zggz[i].pay_zw<<endl;
		cout<<"��Ч���ʣ�"<<zggz[i].pay_xiaoji<<endl;
		cout<<"Ӧ�����ʣ�"<<zggz[i].pay_yf<<endl;
		cout<<"��������˰��"<<zggz[i].duty<<endl;
		cout<<"ʵ�����ʣ�"<<zggz[i].pay_sf<<endl;*/
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
			printf("\n��ʼ�޸�\n");
		    printf("\n����������\n");
			scanf("%s", zggz[i].name);
			printf("\n��λ���ʣ�\n");
			scanf("%f", &zggz[i].pay_gw);
			printf("\nн�����ʣ�\n");
			scanf("%f", &zggz[i].pay_xinji);
			printf("\nְ�������\n");
			scanf("%f", &zggz[i].pay_zw);
			printf("\n��Ч���ʣ�\n");
			scanf("%f", &zggz[i].pay_xiaoji);
			zggz[i].pay_yf=zggz[i].pay_gw+zggz[i].pay_xiaoji+zggz[i].pay_xinji+zggz[i].pay_zw;
		    grsds(i);
		    zggz[i].pay_sf=zggz[i].pay_yf-zggz[i].duty;
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
	printf("������������ְ��������\n");
	scanf("%d", &add_num);
	for(int i=n;i<n+add_num;++i)
	{
		printf("\n�����빤��\n");
		scanf("%s", zggz[i].num);
		printf("\n����������\n");
		scanf("%s", zggz[i].name);
		printf("\n��λ���ʣ�\n");
		scanf("%f", &zggz[i].pay_gw);
		printf("\nн�����ʣ�\n");
		scanf("%f", &zggz[i].pay_xinji);
		printf("\nְ�������\n");
		scanf("%f", &zggz[i].pay_zw);
		printf("\n��Ч���ʣ�\n");
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
		printf("\n��ӭʹ��ְ������ϵͳ");
		printf("\n��ѡ����Ҫʹ�õĹ��ܣ������������֣��س�ȷ�ϣ�");
		printf("\n1.��ѯ\n2.�޸�\n3.���\n4.ɾ��\n5.���\n6.����\n7.�˳�\n");
		scanf("%d", &choose_num);
		if(choose_num<8&&choose_num>0)
		{
			switch(choose_num)
			{
			    case 1:
					{
						printf("\n�ѽ����ѯģ��");
						find();
			            break;
					}
				case 2:
					{
						printf("\n�ѽ����޸�ģ��");
			            modify();
			            break;
					}
				case 3: 
					{
			            printf("\n�ѽ������ģ��");
			            add();
			            break;
					}
		        case 4:
					{
			            printf("\n�ѽ���ɾ��ģ��");
			            del();
			            break;
					}
				case 5:
					{
			            printf("\n�ѽ������ģ��");
			            list();
			            break;
					}
				case 6:
					{
			            printf("\n�ѱ���");
			            write();
			            break;
					}
				case 7:
					{
						printf("\nϵͳ�˳�����ӭ�ٴ�ʹ�ã�");
		                for_main=2;break;
					}
			}
	}
		else
		{
			printf("\n������ѡ����");
		}
	}

   	
	system("pause");
	return 0;
}