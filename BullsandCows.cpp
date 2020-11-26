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
	printf("咱们开始吧，不管你心里想了个啥数，我都先猜0123!\n");
	printf("好吧，先告诉我答案吧，几A几B？\n");
	scanf("%d%d",&a,&b);
	initdata();
	int pro=0; 
	while(a+b<8)//只有当a=4,b=4,才能退出循环，认为猜出结果，不用再猜了 
	{
		guessProcess[pro]=guessnum;
		cutdata(guessnum,a,b);
		printf("再猜一次：\n");
		guessnum = getGuess();
		guessNum(guessnum);
		scanf("%d%d",&a,&b);
		pro++;
	}
	if(a+b==8)
	{//判定猜出结果 
		guessProcess[pro]=guessnum;
		printf("就是这么牛逼！");
		saveFile();
		effecint();
	}
	else
		printf("咱这智商，也就别跟计算机玩心眼了！");
	return 0;
}
int caculateA(int source,int guess)//计算猜中几个数 ，A 
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
int caculateB(int source,int guess)//计算有几个数位置对了，B 
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
//初始化数组，0~9不同的四个数组成，共5040个数字 
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
{//将当前所猜的数，与数组中其他数做比较，所得到的AB直，与人判断的AB值不一致的，都置为0，所有一致的数，都是有可能的正确答案 
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
{//从数组中获取第一个非零值，作为可能的数，继续猜！ 
	for(int i=0;i<5040;i++)
	{
		if(data[i]!=0)
			return data[i];
	}
}
void guessNum(int guess)
{//输出所猜的数字~ 
	int a=guess/1000;
	guess%=1000;
	int b=guess/100;
	guess%=100;
	int c=guess/10;
	int d=guess%10;
	printf("%d%d%d%d\n",a,b,c,d);
	printf("几A几B？\n");
}
void saveFile()
{//将猜测的过程，保存到文件中~ 
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
	printf("累计游戏%d次，平均%f次猜出结果",line,result);
}
