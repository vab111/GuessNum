#include<stdio.h>
#include<stdlib.h>

static int data[5040];
static int guessProcess[7];
int caculateA(int,int);
int caculateB(int,int);
void initdata();
void cutdata(int,int,int);
int getGuess();
void guessNum(int);
void saveFile();
void effecint();
int main()
{
	int a=0,b=0;
	int result[7];
	int guessnum=123;
	printf("���ǿ�ʼ�ɣ��������������˸�ɶ�����Ҷ��Ȳ�0123!\n");
	printf("�ðɣ��ȸ����Ҵ𰸰ɣ���A��B��\n");
	scanf("%d%d",&a,&b);
	initdata();
	int pro=0; 
	while(a+b<8)//ֻ�е�a=4,b=4,�����˳�ѭ������Ϊ�³�����������ٲ��� 
	{
		guessProcess[pro]=guessnum;
		cutdata(guessnum,a,b);
		printf("�ٲ�һ�Σ�\n");
		guessnum = getGuess();
		guessNum(guessnum);
		scanf("%d%d",&a,&b);
		pro++;
	}
	if(a+b==8)
	{//�ж��³���� 
		guessProcess[pro]=guessnum;
		printf("������ôţ�ƣ�");
		saveFile();
		effecint();
	}
	else
		printf("�������̣�Ҳ�ͱ��������������ˣ�");
	return 0;
}
int caculateA(int source,int guess)//������м����� ��A 
{
	int a_1 = source/1000; 
	int a_2 = guess/1000;
	int b_1 = (source/100)%10;
	int b_2 = (guess/100)%10;
	int c_1 = (source/10)%10;
	int c_2 = (guess/10)%10;
	int d_1 = source%10;
	int d_2 = guess%10;
	int result = 0;
	if(a_1 == a_2 || a_1 == b_2||a_1==c_2||a_1==d_2)
		result++;
	if(b_1 == a_2 || b_1 == b_2||b_1==c_2||b_1==d_2)
		result++;
	if(c_1 == a_2 || c_1 == b_2||c_1==c_2||c_1==d_2)
		result++;
	if(d_1 == a_2 || d_1 == b_2||d_1==c_2||d_1==d_2)
		result++;
	return result;
			
}
int caculateB(int source,int guess)//�����м�����λ�ö��ˣ�B 
{
	int a_1 = source/1000; 
	int a_2 = guess/1000;
	int b_1 = (source/100)%10;
	int b_2 = (guess/100)%10;
	int c_1 = (source/10)%10;
	int c_2 = (guess/10)%10;
	int d_1 = source%10;
	int d_2 = guess%10;
	int result = 0;
	if(a_1 == a_2 )
		result++;
	if(b_1 == b_2)
		result++;
	if(c_1==c_2)
		result++;
	if(d_1==d_2)
		result++;
	return result;
			
}
void initdata()
{
//��ʼ�����飬0~9��ͬ���ĸ�����ɣ���5040������ 
	int index=0;
	for(int i=0;i<7;i++)
	{
		guessProcess[i]=0;
			
	
	}
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			if(i==j) continue;
			for(int k=0;k<10;k++)
			{
				if(k==j||k==i) continue;
				for(int l=0;l<10;l++)
				{
					if(l==k||l==j||l==i) continue;
					data[index] = i*1000+j*100+k*10+l;
					index++;
				}
				
			}
		}
	}
}
void cutdata(int target,int a,int b)
{//����ǰ���µ����������������������Ƚϣ����õ���ABֱ�������жϵ�ABֵ��һ�µģ�����Ϊ0������һ�µ����������п��ܵ���ȷ�� 
	for(int i=0;i<5040;i++)
	{
		if(data[i]==0) continue;
		if(caculateA(target,data[i])!=a)
		{
			data[i] = 0;
			continue;
		}
		else
		{
			if(caculateB(target,data[i])!=b)
			{
				data[i] = 0;
				continue;
			}
			
		}
		
	}	
}
int getGuess()
{//�������л�ȡ��һ������ֵ����Ϊ���ܵ����������£� 
	for(int i=0;i<5040;i++)
	{
		if(data[i]!=0)
			return data[i];
	}
}
void guessNum(int guess)
{//������µ�����~ 
	int a=guess/1000;
	guess%=1000;
	int b=guess/100;
	guess%=100;
	int c=guess/10;
	int d=guess%10;
	printf("%d%d%d%d\n",a,b,c,d);
	printf("��A��B��\n");
}
void saveFile()
{//���²�Ĺ��̣����浽�ļ���~ 
	FILE *file;
	file = fopen("result.txt","a");
	for(int i=0;i<7;i++)
	{
		if(guessProcess[i]!=0)
			fprintf(file,"%d\t",guessProcess[i]);
		
	
	}
	fprintf(file,"\n");
	fclose(file);
}
void effecint()
{
	int line=0,num=0;
	float result=0.0;
	FILE *file;
	file = fopen("result.txt","r");
	while(!feof(file))
  	{
    		char flag = fgetc(file);
    		if(flag == '\n')
      		line++;
  	}
 	file = fopen("result.txt","r");
	while(!feof(file))
	{
		fscanf(file,"%d",&line);
		num++;
	}
	num--;
	fclose(file);
	file = fopen("result.txt","r");
	line = 0;
	while(!feof(file))
  	{
    		char flag = fgetc(file);
    		if(flag == '\n')
      		line++;
  	}
	fclose(file);
	result = ((float)num)/((float)line);
	printf("�ۼ���Ϸ%d�Σ�ƽ��%f�β³����",line,result);
}
