#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include<conio.h>

void adminWelcome();
void userWelcome();
void userRegister();
void welcome();
void addNewItem();
void editItem();
void deleteItem();
void printItems();
void searchItem();
void selectItems();
void billItems();

struct User 
{
	char username[50];
	char password[10];
}user;

struct Item
{
	char itemID[10];
	char itemName[10];
	char itemPrice[10];
	char colour[10];
	char itemType[10];
	char itemBrand[10];
}*item;

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main()
{
	system("cls");
	int flag = 0;
	int i;
	gotoxy(20,3);
	char *ptr = "CLOTHING MANAGEMENT SYSTEM";
	for(i=0;i<strlen(ptr);i++)
	{
		printf("%c",ptr[i]);
		usleep(10000);
	}
	printf("\n");
	ptr = "DONE BY";
	gotoxy(20,5);
	for(i=0;i<strlen(ptr);i++)
	{
		printf("%c",ptr[i]);
		usleep(10000);
	}
	printf("\n");
	ptr = "NAVANEETH KRISHNA TANGUTURI";
	gotoxy(20,7);
	for(i=0;i<strlen(ptr);i++)
	{
		printf("%c",ptr[i]);
		usleep(10000);
	}
	printf("\n");
	ptr = "SATWIK KASUKURTHI";
	gotoxy(20,9);
	for(i=0;i<strlen(ptr);i++)
	{
		printf("%c",ptr[i]);
		usleep(10000);
	}
	printf("\n");
	welcome();
	return 0;
}


void welcome()
{
	sleep(2);
	system("cls");
	gotoxy(20,3);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(20,5);
	printf("ENTER 1 FOR NEW USER");
	gotoxy(20,7);
	printf("ENTER 2 FOR REGISTERED USER ");
	gotoxy(20,9);
	printf("ENTER 3 FOR ADMIN");
	gotoxy(20,11);
	printf("ENTER 0 TO EXIT!");
	gotoxy(20,13);
	printf("NOTE: ALL THE ITEM DETAILS SUPPOSED TO BE ENTERED MUST BE IN CAPITALS!!");
	int answer;
	gotoxy(20,15);
	printf("ENTER YOUR OPTION ");
	scanf("%d",&answer);
	gotoxy(20,17);
	while(1)
	{
		switch(answer)
		{
			case 0:
				printf("EXITING!");
				exit(1);
			case 1:
				userRegister();
				break;
			case 2:
				userWelcome();
				break;
			case 3:
				adminWelcome();
				break;
			default:
				printf("ANSWER NUMBER OUT OF BOUNDS!");
		}
	}	
}

void adminWelcome()
{
	sleep(2);
	int i;
	int flag = 0;
	int choice;
	system("cls");
	gotoxy(20,3);
	printf("ADMIN");
	time_t t;
	time(&t);
	gotoxy(20,5);
	printf("TIME OF LOGGIN IN %s ",ctime(&t));
	char *admin = "admin";
	char *password = "password";
	char uname[100];
	char pass[8];
	char ch;
	gotoxy(20,7);
	printf("ENTER THE USER NAME ");
	scanf("%s",uname);
	gotoxy(20,9);
	printf("ENTER THE PASSWORD (MAX LENGTH = %d) ",strlen(password));
	i=0;
	while(i < strlen(password))
	{
		ch = getch();
		pass[i]=ch;
		printf("*");
		i++;
	}
	pass[i]='\0';
	sleep(1);
	if(!strcmp(uname,admin) && !strcmp(pass,password))
	{
		gotoxy(20,11);
		printf("LOGGED IN SUCCESSFULLY!");
		sleep(1);
		while(1)
		{
			system("cls");
			gotoxy(20,3);
			printf("ADMIN PORTAL!");
			gotoxy(20,5);
			printf("WHAT DO YOU WANT TO DO?");
			gotoxy(20,7);
			printf("ENTER 1 FOR ADDING ITEM");
			gotoxy(20,9);
			printf("ENTER 2 FOR EDITING ITEM");
			gotoxy(20,11);
			printf("ENTER 3 FOR DELETING ITEM");
			gotoxy(20,13);
			printf("ENTER 4 FOR SEARCHING ITEM");
			gotoxy(20,15);
			printf("ENTER 5 FOR PRINTING ITEMS");
			gotoxy(20,17);
			printf("ENTER 0 TO EXIT TO THE WELCOME SCREEN!");
			gotoxy(20,19);
			printf("WHATS YOUR CHOICE? ");
			scanf("%d",&choice);
			gotoxy(20,21);
			switch(choice)
			{
				case 0:
					printf("EXITING!");
					for(i = 0; i<3 ; i++)
    				{
    					sleep(1);
    					printf(".");
					}	
					sleep(1);
					welcome();
					return;
				case 1:
					addNewItem();
					break;
				case 2:
					editItem();
					break;
				case 3:
					deleteItem();
					break;
				case 4:
					searchItem();
					break;
				case 5:
					printItems();
				default:
					printf("INVALID OPTION");
			}
		}
	}
	return;
}

void userRegister()
{
	int i;
	system("cls");
	gotoxy(20,3);
	printf("WELCOME NEW USER!"); 
	gotoxy(20,5);
	printf("PLEASE ENTER YOUR DETAILS GIVEN BELOW");
	char uname[100];
	char pass[10];
	FILE *fp;
	fp=fopen("users.txt", "a+");
	gotoxy(20,7);
	printf("ENTER YOUR USERNAME ");
	scanf("%s",uname);
	gotoxy(20,9);
	while(fread (&user, sizeof(struct User), 1, fp))
	{
        if(!strcmp(user.username, uname))
		{
            printf ("USERNAME ALREADY EXISTS PLEASE TRY AGAIN");
            sleep(1);
            userRegister();
    	}
    }
    gotoxy(20,9);
	printf("ENTER YOUR PASSWORD (MAX 10 CHARACTERS) ");
	scanf("%s",pass);
	strcpy(user.username,uname);
    strcpy(user.password,pass);
    fwrite (&user, sizeof(struct User), 1, fp);
    fclose(fp);
    gotoxy(20,11);
    printf("TAKING YOU TO THE LOGIN SCREEN");
    for(i = 0; i<3 ; i++)
    {
    	sleep(1);
    	printf(".");
	}
    userWelcome();
}

void userWelcome()
{
	system("cls");
	int answer;
	int i;
	char temp[10],ch;
	char uname[100];
	char pass[10];
	int flag = 0;
	time_t t;
	time(&t);
	gotoxy(20,3);
	printf("WELCOME BACK! PLEASE ENTER THE LOGIN CREDENTIALS");
	FILE *fp;
	fp=fopen("users.txt", "r+");
	gotoxy(20,5);
	printf("ENTER USERNAME: ");
	scanf("%s",uname);
    while (fread (&user, sizeof(struct User), 1, fp)) 
	{
        if(!strcmp (user.username, uname))
        {
        	strcpy(temp,user.password);
        	gotoxy(20,7);
        	printf("ENTER PASSWORD ");
        	for(i=0;i<strlen(temp);i++)
        	{
        		ch = getch();
        		pass[i] = ch;
        		printf("*");
			}
			pass[i] = '\0';
        	if(!strcmp(pass,user.password))
        	{
        		gotoxy(20,9);
        		printf("LOGIN SUCCESSFUL!");
        		gotoxy(20,11);
				printf("TIME OF LOGGIN IN %s ",ctime(&t));
        		sleep(2);
				flag = 1;
				break;
			}
			else
			{
				gotoxy(20,9);
				printf("INVALID PASSWORD! PLEASE TRY AGAIN");
				userWelcome();
			}
		}
	}
	if(flag)
	{
		while(1)
		{
			system("cls");
			gotoxy(20,3);
			printf("WHAT DO YOU WISH TO DO?");
			gotoxy(20,5);
			printf("ENTER 1 FOR SEARCHING ITEMS");
			gotoxy(20,7);
			printf("ENTER 2 FOR VIEWING ITEMS");
			gotoxy(20,9);
			printf("ENTER 3 FOR SELECTING ITEMS");
			gotoxy(20,11);
			printf("ENTER 4 TO EXIT THE TERMINAL!");
			gotoxy(20,13);
			printf("ENTER 0 TO RETURN TO WELCOME SCREEN! ");
			scanf("%d",&answer);
			gotoxy(20,15);
			switch(answer)
			{
				case 0:
					printf("EXITING!");
					for(i = 0; i<3 ; i++)
    				{
    					sleep(1);
    					printf(".");
					}
					welcome();
					return;
				case 1:
					searchItem();
					break;
				case 2:
					printItems();
					break;
				case 3:
					selectItems();
				case 4:
					exit(1);
				default:
					printf("INVALID ENTRY!");
					break;		
			}
		}
	}
	else
	{
		gotoxy(20,17);
		printf("LOGIN FAILED, PLEASE TRY AGAIN!");
		sleep(1);
		userWelcome();
	}
	fclose(fp);
	return;
}

void addNewItem()
{
	sleep(2);
	system("cls");
	char temp[10];
	item = (struct Item*)malloc(sizeof(struct Item));
	FILE *fp;
	char itemID[10];
	char itemName[10];
	int itemPrice;
	char colour[10];
	char itemType[10];
	char itemBrand[10];
	fp=fopen("items.txt", "a+");
	gotoxy(20,3);
	printf("ENTER ITEM ID ");
	scanf("%s",temp);
	while (fread (item, sizeof(struct Item), 1, fp))
	{
		if(!strcmp(item->itemID,temp))
		{
			gotoxy(20,5);
			printf("ITEM IDs MATCH. PLEASE TRY AGAIN!");
			addNewItem();
		}
	}
	strcpy(item->itemID,temp);
	gotoxy(20,5);
	printf("ENTER ITEM NAME ");
	scanf("%s",&item->itemName);
	gotoxy(20,7);
	printf("ENTER ITEM PRICE ");
	scanf("%s",&item->itemPrice);
	gotoxy(20,9);
	printf("ENTER ITEM COLOUR ");
	scanf(" %s",&item->colour);
	gotoxy(20,11);
	printf("ENTER ITEM TYPE ");
	scanf("%s",&item->itemType);
	gotoxy(20,13);
	printf("ENTER ITEM BRAND ");
	scanf("%s",&item->itemBrand);
	fwrite (item, sizeof(struct Item), 1, fp);
	fclose(fp);
	gotoxy(20,15);
	printf("ITEM ADDED SUCCESSFULLY! PRESS ENTER TO CONTINUE");
	getch();
	free(item);
	return;
}

void editItem()
{
	sleep(2);
	int choice;
	char itemID[10];
	char answer[10];
	struct Item * ITEM;
	ITEM = (struct Item*)malloc(sizeof(struct Item));
	item = (struct Item*)malloc(sizeof(struct Item));
	int flag = 0;
	system("cls");
	gotoxy(20,3);
	printf("ENTER THE ITEM ID OF THE ITEM TO BE EDITED ");
	scanf("%s",itemID);
	FILE *fp;
	fp=fopen("items.txt","a+");
	while (fread (item, sizeof(struct Item), 1, fp))
	{
		if(!strcmp(itemID,item->itemID))
		{
			flag = 1;
			break;
		}
	}
	if(flag)
	{
		gotoxy(20,5);
		printf("ENTER 1 TO EDIT THE ITEM NAME ");
		gotoxy(20,7);
		printf("ENTER 2 TO EDIT THE ITEM PRICE ");		
		gotoxy(20,9);
		printf("ENTER 3 TO EDIT THE ITEM COLOUR");
		gotoxy(20,11);
		printf("ENTER 4 TO EDIT THE ITEM TYPE");
		gotoxy(20,13);
		printf("ENTER 5 TO EDIT ITEM BRAND");
		gotoxy(20,15);
		printf("ENTER YOUR CHOICE ");
		scanf("%d",&choice);
		gotoxy(20,17);
		switch(choice)
		{
			case 1:
				printf("ENTER THE NEW ITEM NAME ");
				scanf("%s",answer);
				strcpy(item->itemName,answer);
				break;
			case 2:
				printf("ENTER THE NEW ITEM PRICE ");
				scanf("%s",answer);
				strcpy(item->itemPrice,answer);
				break;
			case 3:
				printf("ENTER THE NEW ITEM COLOUR ");
				scanf("%s",answer);
				strcpy(item->colour,answer);
				break;
			case 4:
				printf("ENTER THE NEW ITEM TYPE ");
				scanf("%s",answer);
				strcpy(item->itemType,answer);
			case 5:
				printf("ENTER THE NEW ITEM BRAND ");
				scanf("%s",answer);
				strcpy(item->itemBrand,answer);
				break;
			default:
				printf("Invalid Entry");
				break;
		}
		fclose(fp);
		FILE *fp2;
		fp=fopen("items.txt", "a+");
		fp2=fopen("temp.txt","w");
		while(fread (ITEM, sizeof(struct Item), 1, fp))
		{
			if(strcmp(ITEM->itemID,itemID))
			{
				fwrite(ITEM, sizeof(struct Item), 1, fp2);
			}	
		}
		fclose(fp);
		fclose(fp2);
		int k = remove("items.txt");
		rename("temp.txt","items.txt");
		fp = fopen("items.txt","a+");
		fwrite (item, sizeof(struct Item), 1, fp);
		fclose(fp);
		gotoxy(20,19);
		sleep(2);
		printf("DONE!");
	}
	else
	{
		gotoxy(20,5);
		printf("ITEM NOT FOUND!");
		editItem();
	}	
}

void deleteItem()
{
	sleep(2);
	system("cls");
	FILE *fp,*fp2;
	int flag = 0;
	char answer[10];
	item = (struct Item*)malloc(sizeof(struct Item));
	fp=fopen("items.txt", "a+");
	fp2=fopen("temp.txt","w");
	gotoxy(20,3);
	printf("ENTER THE ITEM ID WHOS DETAILS ARE TO BE DELETED ");
	scanf("%s",&answer);
	while(fread (item, sizeof(struct Item), 1, fp))
	{
		if(strcmp(item->itemID,answer))
		{
			flag = 1; 
			fwrite(item, sizeof(struct Item), 1, fp2);
		}	
	}
	if(!flag)
	{
		gotoxy(20,5);
		printf("ITEM ID NOT FOUND. PLEASE TRY AGAIN!");
		deleteItem();
	}
	free(item);
	fclose(fp);
	fclose(fp2);
	int k = remove("items.txt");
	rename("temp.txt","items.txt");
	gotoxy(20,7);
	if(!k)
		printf("ITEM DELETED SUCCESSFULLY!");
	else
		printf("ERROR!");
	rename("temp.txt","items.txt");
	gotoxy(20,9);
	printf("PRESS ENTER TO CONTINUE");
	getch();
}

void printItems()
{
	sleep(2);
	int i = 7;
	system("cls");
	FILE *fp;
	item = (struct Item*)malloc(sizeof(struct Item));
	fp=fopen("items.txt", "a+");
	gotoxy(20,3);
	printf("ITEM DETAILS");
	gotoxy(20,5);
	printf("%20s%20s%20s%20s%20s%20s","ID","NAME","PRICE","COLOUR","TYPE","BRAND");
	while(fread (item, sizeof(struct Item), 1, fp))
	{
		gotoxy(20,i);
		printf("%20s",item->itemID);
		printf("%20s",item->itemName);
		printf("%20s",item->itemPrice);
		printf("%20s",item->colour);
		printf("%20s",item->itemType);
		printf("%20s",item->itemBrand);
		i+=2;
	}
	gotoxy(20,i+2);
	printf("PRESS ENTER TO CONTINUE! ");
	getch();
	free(item);
	fclose(fp);
}

void searchItem()
{
	sleep(2);
	int i = 9;
	system("cls");
	FILE *fp;
	int choice;
	int flag = 0;
	item = (struct Item*)malloc(sizeof(struct Item));
	fp=fopen("items.txt", "r+");
	char str[10];
	gotoxy(20,3);
	printf("ENTER ANYTHING YOU WANT TO SEARCH ");
	scanf("%s",str);
	do
	{
		flag = 0;
		while(fread (item, sizeof(struct Item), 1, fp))
		{
			if((!strcmp(item->colour,str) || !strcmp(item->itemBrand,str) || !strcmp(item->itemID,str) || !strcmp(item->itemName,str) || !strcmp(item->itemPrice,str) 
			|| !strcmp(item->itemType,str)))
			{
				gotoxy(20,5);
				flag = 1;	
				printf("ITEM DETAILS");
				gotoxy(20,7);
				printf("%20s%20s%20s%20s%20s%20s","ID","NAME","PRICE","COLOUR","TYPE","BRAND");
				gotoxy(20,i);
				printf("%20s",item->itemID);
				printf("%20s",item->itemName);
				printf("%20s",item->itemPrice);
				printf("%20s",item->colour);
				printf("%20s",item->itemType);
				printf("%20s",item->itemBrand);
				i+=2;
			}
		}
		rewind(fp);
		if(!flag)
		{
			gotoxy(20,i+2);
			printf("NO ITEM FOUND! PLEASE TRY AGAIN");
			gotoxy(20,i+2);
			printf("YOU WISH TO CONTINUE? ENTER 0 TO EXIT!");
			scanf("%d",&choice);
		}	
	}	
	while(choice!=0);
	gotoxy(20,i+2);
	printf("PRESS ENTER TO CONTINUE! ");
	getch();
	fclose(fp);
	free(item);
}

void selectItems()
{
	sleep(2);
	int number;
	int choice;
	int flag;
	int i;
	char answer[10];
	FILE *fp,*fp2;
	item = (struct Item*)malloc(sizeof(struct Item));
	fp=fopen("items.txt", "a+");
	fp2=fopen("selection.txt","w");
	do
	{
		system("cls");
		flag = 0;
		gotoxy(20,3);
		printf("ENTER THE ITEM ID OF THE ITEM YOU SELECTED ");
		scanf("%s",&answer);
		while(fread(item, sizeof(struct Item), 1, fp))
		{
			if(!strcmp(answer,item->itemID))
			{
				flag = 1;
				gotoxy(20,5);
				printf("ITEM SELECTED! ENTER QUANTITY OF REQUIREMENT ");
				scanf("%d",&number);
				while(number)
				{
					fwrite (item, sizeof(struct Item), 1, fp2);
					number--;
				}
			}
		}
		rewind(fp);
		if(!flag)
		{
			gotoxy(20,7);
			printf("ITEM NOT FOUND PLEASE TRY AGAIN!");
			sleep(1);
		}	
		gotoxy(20,9);
		printf("DO YOU WISH TO EXIT? ENTER 0 TO EXIT ");
		scanf("%d",&choice);
	}
	while(choice!=0);
	fclose(fp);
	fclose(fp2);
	gotoxy(20,11);
	printf("DO YOU WISH TO CONTINUE TO BILLING? ENTER 1 FOR YES 0 FOR NO ");
	scanf("%d",&choice);
	if(choice)
	{
		gotoxy(20,13);
		printf("TAKING YOU TO BILLING");
		for(i = 0; i<3 ; i++)
    	{
    		sleep(1);
    		printf(".");
		}
		sleep(1);
		billItems();
	}
	else
	{
		gotoxy(20,13);
		printf("EXITING THE PORTAL");
		for(i = 0; i<3 ; i++)
    	{
    		sleep(1);
    		printf(".");
		}
		exit(1);
	}
}
void billItems()
{
	sleep(2);
	int i;
	system("cls");
	int total = 0;
	FILE *fp;
	item = (struct Item*)malloc(sizeof(struct Item));
	fp=fopen("selection.txt","a+");
	while(fread(item, sizeof(struct Item), 1, fp))
	{
		gotoxy(20,3);
		printf("ITEM : %s",item->itemName);
		gotoxy(20,5);
		printf("ITEM PRICE: %s",item->itemPrice);
		total += atoi(item->itemPrice);
	}
	gotoxy(20,7);
	printf("TOTAL BILL IS %d",total);
	gotoxy(20,9);
	printf("THANK YOU FOR SHOPPING! PLEASE VISIT AGAIN.");
	gotoxy(20,11);
	printf("CLOSING THE PORTAL");
	for(i = 0; i<3 ; i++)
    {
    	sleep(1);
    	printf(".");
	}
	sleep(1);
	exit(1);
}
