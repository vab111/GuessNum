#include<stdio.h>
#include<stdlib.h>
#include "conio.h"
#include<string.h> 
typedef struct media{
	char type[40];
	char actor[20];
	char press[20];
	char area[20];
	char year[20];
	char style[20];
	char code[20];
	char magnet[20];
	char volumn[20];
	char length[20];
	struct media * next;
	
}Media;
static Media *List=NULL;
void readList();
void saveList();
void showMenu();
void newNode();
void deleteNode();
void modifyNode();
void selectNode();
void caculateNode(); 
void ProcessLoop();
int PrnMainMenu();
void showList(); 
void cleanList(); 
int main()
{
	
	ProcessLoop(); 
	return 0;	
} 
void ProcessLoop()//主循环 

 {
     int iChoice;

    iChoice = PrnMainMenu();

     while (iChoice != 7)

     {
         switch(iChoice)

         {

        case 1:

            newNode();

            break;

         case 2:

            deleteNode();

            break;

        case 3:

            modifyNode();

            break;

        case 4:

            selectNode();

            break;
		case 5:
			caculateNode();
			break;
		case 6:
			showList();
			break;
        default:

            break;

        }

         iChoice = PrnMainMenu();

    }

    return;

}
int PrnMainMenu()//菜单显示 

{
     int iChoice;

    system("cls");  /*_clearscreen(0); */
	readList();
    printf("\n\t%s","多媒体信息管理");

    printf("\n\n\t                   菜单");

    printf("\n\n\n\t                   请选择:");

    printf("\n\n\t                   1、新建");

    printf("\n\n\t                   2、删除");

    printf("\n\n\t                   3、修改");

    printf("\n\n\t                   4、查找");

    printf("\n\n\t                   5、统计");
    
    printf("\n\n\t                   6、列表");

    printf("\n\n\t                   7、退出");

     printf("\n\n\n\n\n\n\t           请输入您的选择(1-7)===>");

     scanf("%d",&iChoice);     fflush(stdin);

     while (iChoice < 1 || iChoice > 7)

     {

        printf("\n您输入的序号有误，请重新输入(1-7)===>");

        scanf("%d",&iChoice);

         fflush(stdin);

     }

     return iChoice;

}
void cleanList()
{
	Media *cur;
	if(List == NULL)
	{
		
	}
	else
	{
		while(List != NULL)
		{
			cur = List;
			List = List->next;
			free(cur);
		}
	}
}
 void showList()
 {
 	char cWait;
 	int index=1;
 	Media *item = List;
 	if(item == NULL)
 	{
 		printf("当前列表为空，您可以通过新建增加数据！\n");
 		printf("\n\n\n\t      Press Enter to continue...");

     	cWait = getch();

     	return;
	}
	else
	{
		while(item != NULL)
		{
			printf("%d、\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n",index,item->type,item->actor,item->press,item->area,item->year,item->style,item->code,item->magnet,item->volumn,item->length);
			item = item->next;
			index++;
		}
		printf("\n\n\n\t      Press Enter to continue...");

     	cWait = getch();
		cleanList();
     	return;
	}
 } 
void selectNode()
{
	int index,count=0; 
	char property[40]; 
	char cWait='y';
	Media *modify,*next;
	if(modify == NULL)
	{
		printf("无数据可查询！");
		printf("\n\n\n\t      Press Enter to continue...");

     	cWait = getch();

     	return;
	}
	else
	{
		while(cWait == 'y') {
		modify = List;
		next = List;
		count=0;
		printf("请选择你需要筛选的属性项：\n");
		printf("1、媒体类型  2、作者/表演者  3、出版者  4、地区  5、年份  6、风格  7、数字化编码类型  8、介质类型  9、体积  10、时长\n");
		scanf("%d",&index);
		printf("请输入您筛选属性的参照值：\n");
		scanf("%s",property);
		switch(index)
			{
				case 1:
					while(modify!=NULL)
					{
						if(!strcmp(modify->type,property))
						{
							printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",modify->type,modify->actor,modify->press,modify->area,modify->year,modify->style,modify->code,modify->magnet,modify->volumn,modify->length);
							count++;
							next = modify;
							modify = modify->next;
						}
						else
						{
							if(modify == List)
							{
								List = modify->next;
								free(modify);
								modify = List;
								next = List;
							}
							else
							{
								next = modify->next;
								if(next == NULL)
								{
									free(modify);
									modify=NULL;
								}
								else
								{
									free(modify);
									modify = next->next;
									free(next);
								}
							}
						}
						
					}
					printf("共查询得%d条数据!\n",count);
					break;
				case 2:
					while(modify!=NULL)
					{
						if(!strcmp(modify->actor,property))
						{
							printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",modify->type,modify->actor,modify->press,modify->area,modify->year,modify->style,modify->code,modify->magnet,modify->volumn,modify->length);
							count++;
							next = modify;
							modify = modify->next;
						}
						else
						{
							if(modify == List)
							{
								List = modify->next;
								free(modify);
								modify = List;
								next = List;
							}
							else
							{
								next = modify->next;
								if(next == NULL)
								{
									free(modify);
									modify=NULL;
								}
								else
								{
									free(modify);
									modify = next->next;
									free(next);
								}
							}
						}
						
					}
					printf("共查询得%d条数据!\n",count);
					break;
				case 3:
					while(modify!=NULL)
					{
						if(!strcmp(modify->press,property))
						{
							printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",modify->type,modify->actor,modify->press,modify->area,modify->year,modify->style,modify->code,modify->magnet,modify->volumn,modify->length);
							count++;
							next = modify;
							modify = modify->next;
						}
						else
						{
							if(modify == List)
							{
								List = modify->next;
								free(modify);
								modify = List;
								next = List;
							}
							else
							{
								next = modify->next;
								if(next == NULL)
								{
									free(modify);
									modify=NULL;
								}
								else
								{
									free(modify);
									modify = next->next;
									free(next);
								}
							}
						}
						
					}
					printf("共查询得%d条数据!\n",count);
					break;
				case 4:
					while(modify!=NULL)
					{
						if(!strcmp(modify->area,property))
						{
							printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",modify->type,modify->actor,modify->press,modify->area,modify->year,modify->style,modify->code,modify->magnet,modify->volumn,modify->length);
							count++;
							next = modify;
							modify = modify->next;
						}
						else
						{
							if(modify == List)
							{
								List = modify->next;
								free(modify);
								modify = List;
								next = List;
							}
							else
							{
								next = modify->next;
								if(next == NULL)
								{
									free(modify);
									modify=NULL;
								}
								else
								{
									free(modify);
									modify = next->next;
									free(next);
								}
							}
						}
						
					}
					printf("共查询得%d条数据!\n",count);
					break;
				case 5:
					while(modify!=NULL)
					{
						if(!strcmp(modify->year,property))
						{
							printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",modify->type,modify->actor,modify->press,modify->area,modify->year,modify->style,modify->code,modify->magnet,modify->volumn,modify->length);
							count++;
							next = modify;
							modify = modify->next;
						}
						else
						{
							if(modify == List)
							{
								List = modify->next;
								free(modify);
								modify = List;
								next = List;
							}
							else
							{
								next = modify->next;
								if(next == NULL)
								{
									free(modify);
									modify=NULL;
								}
								else
								{
									free(modify);
									modify = next->next;
									free(next);
								}
							}
						}
						
					}
					printf("共查询得%d条数据!\n",count);
					break;
				case 6:
					while(modify!=NULL)
					{
						if(!strcmp(modify->style,property))
						{
							printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",modify->type,modify->actor,modify->press,modify->area,modify->year,modify->style,modify->code,modify->magnet,modify->volumn,modify->length);
							count++;
							next = modify;
							modify = modify->next;
						}
						else
						{
							if(modify == List)
							{
								List = modify->next;
								free(modify);
								modify = List;
								next = List;
							}
							else
							{
								next = modify->next;
								if(next == NULL)
								{
									free(modify);
									modify=NULL;
								}
								else
								{
									free(modify);
									modify = next->next;
									free(next);
								}
							}
						}
						
					}
					printf("共查询得%d条数据!\n",count);
					break;
				case 7:
					while(modify!=NULL)
					{
						if(!strcmp(modify->code,property))
						{
							printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",modify->type,modify->actor,modify->press,modify->area,modify->year,modify->style,modify->code,modify->magnet,modify->volumn,modify->length);
							count++;
							next = modify;
							modify = modify->next;
						}
						else
						{
							if(modify == List)
							{
								List = modify->next;
								free(modify);
								modify = List;
								next = List;
							}
							else
							{
								next = modify->next;
								if(next == NULL)
								{
									free(modify);
									modify=NULL;
								}
								else
								{
									free(modify);
									modify = next->next;
									free(next);
								}
							}
						}
						
					}
					printf("共查询得%d条数据!\n",count);
					break;
				case 8:
					while(modify!=NULL)
					{
						if(!strcmp(modify->magnet,property))
						{
							printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",modify->type,modify->actor,modify->press,modify->area,modify->year,modify->style,modify->code,modify->magnet,modify->volumn,modify->length);
							count++;
							next = modify;
							modify = modify->next;
						}
						else
						{
							if(modify == List)
							{
								List = modify->next;
								free(modify);
								modify = List;
								next = List;
							}
							else
							{
								next = modify->next;
								if(next == NULL)
								{
									free(modify);
									modify=NULL;
								}
								else
								{
									free(modify);
									modify = next->next;
									free(next);
								}
							}
						}
						
					}
					printf("共查询得%d条数据!\n",count);
					break;
				case 9:
					while(modify!=NULL)
					{
						if(!strcmp(modify->volumn,property))
						{
							printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",modify->type,modify->actor,modify->press,modify->area,modify->year,modify->style,modify->code,modify->magnet,modify->volumn,modify->length);
							count++;
							next = modify;
							modify = modify->next;
						}
						else
						{
							if(modify == List)
							{
								List = modify->next;
								free(modify);
								modify = List;
								next = List;
							}
							else
							{
								next = modify->next;
								if(next == NULL)
								{
									free(modify);
									modify=NULL;
								}
								else
								{
									free(modify);
									modify = next->next;
									free(next);
								}
							}
						}
						
					}
					printf("共查询得%d条数据!\n",count);
					break;
				case 10:
					while(modify!=NULL)
					{
						if(!strcmp(modify->length,property))
						{
							printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",modify->type,modify->actor,modify->press,modify->area,modify->year,modify->style,modify->code,modify->magnet,modify->volumn,modify->length);
							count++;
							next = modify;
							modify = modify->next;
						}
						else
						{
							if(modify == List)
							{
								List = modify->next;
								free(modify);
								modify = List;
								next = List;
							}
							else
							{
								next = modify->next;
								if(next == NULL)
								{
									free(modify);
									modify=NULL;
								}
								else
								{
									free(modify);
									modify = next->next;
									free(next);
								}
							}
						}
						
					}
					printf("共查询得%d条数据!\n",count);
					break;	
				default:
					break;
			} 
			printf("是否继续查询？y/n\n"); 
			cWait = getch();
		}
		printf("\n\n\n\t      Press Enter to continue...");

     	cWait = getch();
		cleanList();
     	return;
 	}
}
void readList()
{
	FILE *file;
	int index = 1,line=0;
	file = fopen("result.txt","r");
	if(file == NULL)
		return ;
	Media *cur;
	while(!feof(file))
  	{
    		char flag = fgetc(file);
    		if(flag == '\n')
      		line++;
  	}
  	file = fopen("result.txt","r");
	for(int i=0;i<line;i++)
  	{
    		//读取媒体数据，生成链表；
    		Media *item = (Media *)malloc(sizeof(Media));
    		item->next = NULL;
    		fscanf(file,"%s%s%s%s%s%s%s%s%s%s",item->type,item->actor,item->press,item->area,item->year,item->style,item->code,item->magnet,item->volumn,item->length);
    	//	printf("%d、\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n",index,item->type,item->actor,item->press,item->area,item->year,item->style,item->code,item->magnet,item->volumn,item->length);
    		index++;
			if(List==NULL)
			{
				List = item;
				cur = item;
			}
    		else
    		{
    			cur->next = item;
    			cur = item;
			}
			 
  	}
  	fclose(file);
}
void saveList()
{
	FILE *file;
	file = fopen("result.txt","w");
	Media *item=List;
	while(item!=NULL)
  	{
    		//保存链表到文件
    		
		fprintf(file,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n",item->type,item->actor,item->press,item->area,item->year,item->style,item->code,item->magnet,item->volumn,item->length);
		if(List == item){
			List = item;
			item = item->next;
		}
		else
		{
			free(List);
			List = item;
			item = item->next;
		}
		
			 
  	}
  	free(List);
  	List = NULL;
  	fclose(file);
} 
void showMenu()
{
	printf("请选择你的操作，直接回复序号即可！\n");
	printf("1、新建  2、删除  3、修改  4、统计  5、退出\n");
}
void newNode()
{
	int selection;
	Media *tailor = List;
	Media *item = (Media *)malloc(sizeof(Media));
	item->next = NULL;
	printf("请选择媒体类型:\n");
	printf("1、文字  2、音频  3、图像  4、视频  5、动画\n");
	scanf("%d",&selection); 
	switch(selection)
	{
		case 1:
			strcpy(item->type, "文字");
			break;
		case 2:
			strcpy(item->type, "音频");
			break;
		case 3:
			strcpy(item->type, "图像");
			break;
		case 4:
			strcpy(item->type, "视频");
			break;
		case 5:
			strcpy(item->type, "动画");
			break;
		default:
			break;
	}
	printf("请输入作者/表演者:\n");
	scanf("%s",item->actor);
	printf("请输入出版者:\n");
	scanf("%s",item->press);
	printf("请输入地区:\n");
	scanf("%s",item->area);
	printf("请输入年份:\n");
	scanf("%s",item->year);
	printf("请输入风格:\n");
	scanf("%s",item->style);
	printf("请输入数字化编码类型:\n");
	scanf("%s",item->code);
	printf("请输入介质类型:\n");
	scanf("%s",item->magnet);
	printf("请输入体积:\n");
	scanf("%s",item->volumn);
	printf("请输入时长:\n");
	scanf("%s",item->length);
	if(tailor == NULL)
		List = item;
	else{
		while(tailor->next!=NULL)
			tailor = tailor->next;
		tailor->next = item;
	} 
	
	saveList(); 
}
void deleteNode()
{
	int index;
	Media *del,*next;
	printf("请输入你需要删除条目的序号：\n");
	scanf("%d",&index);
	del = List;
	for(int i=1;i<index-1;i++){
		del = del->next;
		if(del == NULL)
		{
			printf("您输入的序号有误，请确认后重新输入！\n");
			i==index;
		}
	}
	if(del == NULL)
	{
		printf("当前无记录可删除！\n");

		
	}
	else{
		if(del==List)
		{
			if(del->next == NULL){
				free(List);
				List = NULL;
			}
			else
			{
				List= List->next;
				free(del);
			}
		}
		else{
			next = del->next;
			if(next->next == NULL)
			{
				del->next = NULL;
				free(next);
			}
			else
			{
				del->next = next->next;
				free(next);
			}
			
		}
		saveList();
	}
	
	
}
void modifyNode()
{
	int index;
	Media *modify = List;
	char command = 'y';
	printf("请输入你需要修改条目的序号：\n");
	scanf("%d",&index);
	for(int i=1;i<index;i++){
		modify = modify->next;
		if(modify == NULL)
		{
			i = index;
		}
	}
	if(modify == NULL){
		printf("您输入的序号不在当前列表中！\n");
	}
	else{
		printf("请选择你需要修改的属性项：\n");
		printf("1、媒体类型  2、作者/表演者  3、出版者  4、地区  5、年份  6、风格  7、数字化编码类型  8、介质类型  9、体积  10、时长\n");
//		while(command == 'y')
//		{
			scanf("%d",&index);
			printf("请输入新的属性值：\n");
			switch(index)
			{
				case 1:
					scanf("%s",modify->type);
					break;
				case 2:
					scanf("%s",modify->actor);
					break;
				case 3:
					scanf("%s",modify->press);
					break;
				case 4:
					scanf("%s",modify->area);
					break;
				case 5:
					scanf("%s",modify->year);
					break;
				case 6:
					scanf("%s",modify->style);
					break;
				case 7:
					scanf("%s",modify->code);
					break;
				case 8:
					scanf("%s",modify->magnet);
					break;
				case 9:
					scanf("%s",modify->volumn);
					break;
				case 10:
					scanf("%s",modify->length);
					break;	
				default:
					break;
			} 
			saveList();
//			printf("修改结果如下：\n");
//			printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",modify->type,modify->actor,modify->press,modify->area,modify->year,modify->style,modify->code,modify->magnet,modify->volumn,modify->length);
//			printf("是否继续修改本条数据？y/n\n");
//			scanf("%c",command); 
//		}
	}
}
void caculateNode()
{
	int selection;
	int i=0,count,j;
	char cWait;
	Media *cur = List,*p;
	if(cur == NULL)
	{
		printf("当前无数据可统计！");
		printf("\n\n\n\t      Press Enter to continue...");

     	cWait = getch();

     	return;
	}
	else
	{
		printf("请选择您需要统计的属性：\n");
		printf("1、作者  2、出版方  3、年份  4、风格\n");
		scanf("%d",&selection);
		switch(selection)
		{
			case 1:
				while(cur!=NULL)
				{
					p = List;
					count = 0;
					j=0;
					while(p!=NULL)
					{
						if(!strcmp(cur->actor,p->actor))
						{
							count++;
							if(j<i)
							{
								count=0;
								p=NULL;
							}
							else
							{
								p = p->next;
							}
						}
						else
						{
							p = p->next;
						}	
						
						j++;
					}
					if(count>0)
						printf("%s\t%d\n",cur->actor,count);
					i++;
					cur=cur->next;
				}
				break;
			case 2:
				while(cur!=NULL)
				{
					p = List;
					count = 0;
					j=0;
					while(p!=NULL)
					{
						if(!strcmp(cur->press,p->press))
						{
							count++;
							if(j<i)
							{
								count=0;
								p=NULL;
							}
							else
							{
								p = p->next;
							}
						}
						else
						{
							p = p->next;
						}	
						
						j++;
					}
					if(count>0)
						printf("%s\t%d\n",cur->actor,count);
					i++;
					cur=cur->next;
				}
				break;
			case 3:
				while(cur!=NULL)
				{
					p = List;
					count = 0;
					j=0;
					while(p!=NULL)
					{
						if(!strcmp(cur->year,p->year))
						{
							count++;
							if(j<i)
							{
								count=0;
								p=NULL;
							}
							else
							{
								p = p->next;
							}
						}
						else
						{
							p = p->next;
						}	
						
						j++;
					}
					if(count>0)
						printf("%s\t%d\n",cur->actor,count);
					i++;
					cur=cur->next;
				}
				break;
			case 4:
				while(cur!=NULL)
				{
					p = List;
					count = 0;
					j=0;
					while(p!=NULL)
					{
						if(!strcmp(cur->style,p->style))
						{
							count++;
							if(j<i)
							{
								count=0;
								p=NULL;
							}
							else
							{
								p = p->next;
							}
						}
						else
						{
							p = p->next;
						}	
						
						j++;
					}
					if(count>0)
						printf("%s\t%d\n",cur->actor,count);
					i++;
					cur=cur->next;
				}
				break;
			default:
				break;
		}
		printf("\n\n\n\t      Press Enter to continue...");

     	cWait = getch();
		cleanList();
     	return;
	}
}
