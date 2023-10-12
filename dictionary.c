/********************************Dictionary****************************************/
/*Headerfile inclusion*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/************************Declaration of structure dictionary***********************/
struct Dictionary
{
	char word[20];
	char meaning[20];
}D;
/****************************Declaration of function********************************/
void AddNewWord();
void ShowDictionary();
void SearchWord();
void UpdateWord();
void DeleteWord();
/**************************Definition of main function******************************/
main()
{
	int ich;
	while(1)//for repetation
	{
		system("cls");
		printf("\n1.you are user");
		printf("\n2.you are Admin");
		printf("\n3.For Exit");
		printf("\nEnter your choice:");
		scanf("%d",&ich);
		system("cls");
		switch(ich)//to select
		{
			case 1://when you are user
			      SearchWord();
			break;
			case 2://when you are Admin
			{
				char pass[20],ch;
				int len=0;
				printf("Enter password:");
				while((ch=getch())!=13&&len<20)
				{
					pass[len++]=ch;
					printf("%c",1);
				}
				pass[len]='\0';
				system("cls");
				if(!strcmp(pass,"nikita2806"))//to compare
				{
					printf("Wellcome Admin\n");
					{
						while(1)//for repeatation
						{
							system("pause");
							system("cls");
							printf("\n1.Add New Word");
							printf("\n2.Show Dictionary");
							printf("\n3.Search Word");
							printf("\n4.Update Word");
							printf("\n5.Delete word");
							printf("\n6.Exit");
							printf("\nEnter your choice:");
							scanf("%d",&ich);
							system("cls");
							switch(ich)//to select
							{
								case 1:
									   AddNewWord();
								break;
								case 2:
									   ShowDictionary();
								break;
								case 3:
									   SearchWord();
								break;
					            case 4:
					            	   UpdateWord();
					            break;
					            case 5:
					            	   DeleteWord();
								break;
								case 6:
								break;
								default:
								        printf("Wrong Choice"); 
							}//switch close
						}//while close
					}
				}//if close
				else
				{
				    printf("Wrong password");
				}
			}//case2 close
			break;
			case 3:
				   exit(0);
			default:
					printf("Wrong Choice");
		}//switch close
	}//while close
}//main close
/**************************Definition of AddNewWord function()**********************/
void AddNewWord()
{
   FILE *fptr;
   fptr=fopen("project.com","ab");
   printf("Add word in dictionary:\n");
   printf("Enter word=");
   fflush(stdin);
   gets(D.word); 
   printf("Enter meaning=");
   fflush(stdin);
   gets(D.meaning); 
   fwrite((char*)&D,1,sizeof(D),fptr);
   fclose(fptr);
}
/*************************Definition of ShowDictionary function()*******************/
void ShowDictionary()
{
  	FILE *fptr;
  	fptr=fopen("project.com","rb");
  	printf("word => meaning\n");
  	while(fread((char*)&D,1,sizeof(D),fptr))
  	{
	   printf("%s => %s\n",D.word,D.meaning);
    }
	fclose(fptr);
}
/*************************Definition of SearchWord function()*******************/
void SearchWord()
{
	FILE *fptr;
	char sword[20];
	while(1)
	{
	int f=0;
	fptr=fopen("project.com","rb");
	printf("Enter word for search:");
	fflush(stdin);
	gets(sword);
	while(fread((char*)&D,1,sizeof(D),fptr))
	{
		if(!strcmp(D.word,sword))
	    {
	    	printf("%s => %s\n",D.word,D.meaning);
	    	f=1;
	    	break;
		}
	}
	if(f==0)
		printf("word is not in Dictionary\n");
	
	fclose(fptr);
	printf("Do you want to continue press 1:");
	scanf("%d",&f);
	if(f!=1)
	break;
	system("cls");
   }
}
/*************************Definition of UpdateWord function()**********************/
void UpdateWord()
{
	FILE *fptr1,*fptr2;
	char sword[20];
	int f=0;
	fptr1=fopen("project.com","rb");
	fptr2=fopen("dictionary.txt","w");
	printf("Enter word for update:");
	fflush(stdin);
	gets(sword);
	while(fread((char*)&D,1,sizeof(D),fptr1))
	{
		if(!strcmp(D.word,sword))
		{
			printf("\nold word is:");
			printf("\nword=%s=>",D.word);
	        printf("meaning=%s",D.meaning);
			
			printf("\nEnter new word:\n");
			printf("Enter word:");
			fflush(stdin);
			gets(D.word);
			printf("Enter meaning:");
			fflush(stdin);
			gets(D.meaning);
			fwrite((char*)&D,1,sizeof(D),fptr2);
			f=1;
		}
		else
		{
		    fwrite((char*)&D,1,sizeof(D),fptr2);
		}
		
    }
	if(f==0)
		printf("word is not in dictionary\n");
	fclose(fptr1);
	fclose(fptr2);
	remove("project.com");
	rename("dictionary.txt","project.com");
}
/**************************Definition of DeleteWord function()**********************/
void DeleteWord()
{
	FILE *fptr1,*fptr2;
	char sword[20];
	int f=0;
	fptr1=fopen("project.com","rb");
	fptr2=fopen("dictionary.txt","w");
	printf("Enter word for delete:");
	fflush(stdin);
	gets(sword);
	while(fread((char*)&D,1,sizeof(D),fptr1))
	{
		if(!strcmp(D.word,sword))
		{
			printf("\n word is:");
			printf("\nword=%s=>",D.word);
	        printf("meaning=%s",D.meaning);
			printf("\nword is deleted\n");
			f=1;
		}
		else
		{
			fwrite((char*)&D,1,sizeof(D),fptr2);
		}
    }
	if(f==0)
		printf("word is not in dictionary\n");
	fclose(fptr1);
	fclose(fptr2);
	remove("project.com");
	rename("dictionary.txt","project.com");
}

