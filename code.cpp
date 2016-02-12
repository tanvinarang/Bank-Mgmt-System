#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<Windows.h>
#include<string.h>
void admin();
void staff();
void admin_MODE(char name1[20]);
void add();
void display();
void delete_USER();
void modify_USER();
void modify_PASS();
void staff_MODE();
void create_account();
void cash_deposit();
void account_info();
void cash_withdrawl();
void exist_account();
int deposit;
int withdraw;
struct admin
{
	char name[20];
	char pass[10];
}t1;
struct staff
{
	char bankname[20];
	char branch[10];
	char acc_holder[20];
	int acc_number;
	char acc_address[20];
	int balance;
}t2,t3;
void main()
{
	int flag;
	printf("----------------------------BANK MANAGEMENT SYSTEM-----------------------------");
	int log, len, i = 0;
	printf("\nLOG IN:");
	printf("\n1:ADMIN MODE");
	printf("\n2:STAFF MODE");
	printf("\n3:EXIT");
	printf("\n");
	printf("-------------------------------------------------------------------------------\n");
	while (1)
	{
		scanf("%d", &log);
		switch (log)
		{
		case 1:
			admin();
			break;
		case 2:

			staff();
			break;
		case 3:
			exit(0);
		default:
			printf("Invalid choice\n");
			
			break;
		}
	}
	
	getch();
}
void admin()
{
	int len,len1, i = 0,j,k,l,m=0;
	char name[20];
	char pass[10];
	printf("\nEnter username:");
	scanf("%s", name);
	len1 = strlen(name);
	printf("\nEnter admin password:");
	scanf("%s", pass);
	len = strlen(pass);
	while (i<len)
	{

	printf("%c", pass[i]);
		Sleep(300);
		printf("\b \b");
		printf("*");
		i++;
	}
		
	
	if (strcmp(pass, "admin") == 0 && strcmp(name,"tanvi") == 0)
	{
		printf("\n\n                               WELCOME");
		for (l = 0; l < 2;l++)
		{
			for (k = 0; k < 4;k++)
			{
				printf(".");
				Sleep(250);
				
			}
			for (j = 4; j>0;j--)
			{
				printf("\b \b");
				
			}
			
		}

		admin_MODE(name);
	}
	
	else
	{
		printf("\n                  INCORRECT USERNAME/PASSWORD");
	}
}
void staff()
{
	int len, i,j,k;
	char name[20];
	char pass[10];
	printf("\nEnter username:");
	scanf("%s", name);
	printf("\nEnter  staff password:");
	scanf("%s", pass);
	if (strcmp("tanvi", name) == 0 && strcmp("abcd", pass) == 0)
	{
		printf("\n                      WELCOME");
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 4; j++)
			{
				printf(".");
				Sleep(250);
			}
			for (k = 4; k>0; k--)
			{
				printf("\b \b");
			}
		}
		staff_MODE(name);
	}
	else
	{
		printf("\n                  INCORRECT USERNAME/PASSWORD");
		
	}
	
}
void admin_MODE(char name1[20])
{

	Sleep(500);
	system("cls");
	printf("                                ADMIN                        USERNAME:%s          ",name1);
	printf("\n--------------------------------------------------------------------------------");
	int ch;
	printf("\n1:Add User");
	printf("\n2:Delete User");
	printf("\n3:Edit Username/Password");
	printf("\n4:Display");
	printf("\n5:Log out");
	printf("\n-------------------------------------------------------------------------------");
	while (1)
	{
		printf("\nEnter your choice:");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			add();
			break;
		case 2:
			
			delete_USER();
			break;
		case 3:

			modify_USER();
			break;
		case 4:
			display();
			break;
		case 5:
			system("cls");
			main();
			break;
		default:
			exit(0);
		}
	}
}
void staff_MODE(char name[10])
{
	Sleep(500);
	system("cls");
	printf("                                STAFF                      USERNAME:%s          ", name);
	printf("\n--------------------------------------------------------------------------------");
	int ch;
	printf("\n1:Create Account");
	printf("\n2:Cash Deposit");
	printf("\n3:Cash Withdrwal");
	printf("\n4:Account Infornamtion");
	printf("\n5:Search an existing account");
	printf("\n6:Log out");
	printf("\n-------------------------------------------------------------------------------");
	while (1)
	{
		printf("\nEnter your choice:");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			create_account();
			break;
		case 2:
			cash_deposit();
			break;
		case 3:
			cash_withdrawl(deposit);
			break;
		case 4:
			account_info(deposit,withdraw);
			
			break;
		//case 5:
			//exist_account();
			//break;
		case 6:

			system("cls");
			main();
			break;
		}
	}

}
void add()
{
	Sleep(250);
	system("cls");
	FILE*fp;
	fp = fopen("Text3.txt", "ab");
	printf("enter username:");
	char ch;
	char ch1[2];
	int len1,len,m,i=0;
	int flag=1,found=0;
	scanf("%s",t1.name);

	len1 = strlen(t1.name);
	for (m = 0; m < len1;m++)
	{
		if (t1.name[m] == ' ' || t1.name[m] == '*' || t1.name[m] == '!' || t1.name[m] == '@' || t1.name[m] == '#' || t1.name[m] == '$' || t1.name[m] == '%' || t1.name[m] == '&' || t1.name[m] == '+' || t1.name[m] == '=')
		{
			
			flag = 0;

		}
		
	}
	if (flag == 0)
	{
		printf("\n\n                      INVALID USERNAME");
		printf("\nKindly choose a username without any special characters(!,@,#,$,%,&,*)");
		Sleep(2500);
		system("cls");
		add();
	}
	printf("\nenter password");
	printf("                              (Password must be atleast 8 characters long)\n");
	printf("                               It must contain  atleast 1 lowercase character\n"),
	printf("					     1 uppercase character,\n");
	printf("					     1 special character\n");
	printf("					     and a numeral!\n");
	scanf("%s", t1.pass);
	len = strlen(t1.pass);
	if (len < 8)
	{
		printf("\npassword too short\n");
		printf("\nenter password");
		scanf("%s", t1.pass);


	}
	
	fwrite(&t1, sizeof(t1), 1, fp);
	fclose(fp);
	printf("Do you want to add another user?Y/N\n");
	while (1)
	{
		
		scanf("%c", &ch);
		switch (ch)
		{
		case 'Y':
			add();
			break;
		case 'N':
			admin_MODE("tanvi");
			break;
		}
	}
	

	

}
void display()
{
	
	char ch;
	FILE*fp;
	fp = fopen("Text3.txt", "rb");
	printf("Username\t\t\tPassword");
	while (1)
	{
		fread(&t1, sizeof(t1), 1, fp);
		if (feof(fp))
		{
			break;
		}
		else
		{
			printf("\n%s\t\t\t\t%s", t1.name, t1.pass);
		}
	}
	fclose(fp);
	
}
void delete_USER()
{
	Sleep(250);
	system("cls");
	char ch;
	FILE*fp;
	fp = fopen("Text3.txt", "rb");
	FILE*fp1;
	fp1 = fopen("Text4.txt", "wb");
	char del[10];
	printf("\nEnter Username:");
	scanf("%s", del);
	
	while (1)
	{
		fread(&t1, sizeof(t1), 1, fp);
		if (feof(fp))
		{
			break;
		}
		if (strcmp(del, t1.name) != 0)
		{
			fwrite(&t1, sizeof(t1), 1, fp1);
		}

	}
	fclose(fp);
	fclose(fp1);
	remove("Text3.txt");
	rename("Text4.txt", "Text3.txt");
	printf("Do you want to delete another user?Y/N\n");
	while (1)
	{

		scanf("%c", &ch);
		switch (ch)
		{
		case 'Y':
			delete_USER();
			break;
		case 'N':
			admin_MODE("tanvi");
			break;
		}
	}
	

}
void modify_USER()
{
	Sleep(250);
	system("cls");
	char ch;
	FILE*fp;
	fp = fopen("Text3.txt", "rb");
	FILE*fp1;
	fp1 = fopen("Text4.txt", "wb");
	char mod[10];
	printf("\nEnter Username:");
	scanf("%s", mod);

	while (1)
	{
		fread(&t1, sizeof(t1), 1, fp);
		if (feof(fp))
		{
			break;
		}
		if (strcmp(mod, t1.name) == 0)
		{
			printf("\nenter	new username:");
			scanf("%s", t1.name);
			printf("\nenter new password:");
			scanf("%s", t1.pass);
			fwrite(&t1, sizeof(t1), 1, fp1);
		}
		else
		{
			fwrite(&t1, sizeof(t1), 1, fp1);
		}
	}
	fclose(fp);
	fclose(fp1);
	remove("Text3.txt");
	rename("Text4.txt", "Text3.txt");
	printf("Do you want to modify another user?Y/N\n");
	while (1)
	{

		scanf("%c", &ch);
		switch (ch)
		{
		case 'Y':
			modify_USER();
			break;
		case 'N':
			admin_MODE("tanvi");
			break;
		}
	}


	
}
void create_account()
{
	int i, j, k;
	char ch;

	system("cls");
	printf("*************************BANK APPLICATION******************************");
	printf("\nEnter the bank name:");
	printf("\nKindly choose from the following:");
	printf("\n1:ICIC");
	printf("\n2:Axis");
	printf("\n3:Punjab");
	printf("\n4:Indian\n");
	scanf("%s", t2.bankname);
	if (strcmp(t2.bankname, "ICIC") == 0 || strcmp(t2.bankname, "Axis") == 0 || strcmp(t2.bankname, "Punjab") == 0 ||strcmp(t2.bankname, "Indian") == 0  )

	{
		printf("\nEnter the bank branch:");
		printf("\nKindly choose from the following:");
		printf("\n1:rajouri");
		printf("\n2:motinagar");
		printf("\n3:vikaspuri");
		printf("\n4:janakpuri\n");
		scanf("%s", t2.branch);
	
		if (strcmp(t2.branch, "rajouri") == 0 || strcmp(t2.branch, "motinagar") == 0 || strcmp(t2.branch, "vikaspuri") == 0 || strcmp(t2.branch, "janakpuri") == 0)
		{
			printf("\nEnter the account holder name:");
			scanf("%s", t2.acc_holder);
		}
		else
		{
			printf("Invalid bank branch");
			printf("\nKindly choose from the following:");
			printf("\n1:rajouri");
			printf("\n2:motinagar");
			printf("\n3:vikaspuri");
			printf("\n4:janakpuri\n");
			scanf("%s", t2.branch);
			//Sleep(3000);
			//create_account();
		}
	
	}


	else
	{
		printf("Invalid bank name");
		printf("\nKindly choose from the following:");
		printf("\n1:ICIC");
		printf("\n2:Axis bank");
		printf("\n3:Punjab national bank");
		printf("\n4:Indian bank");
		Sleep(3000);
		create_account();

	}
	printf("\nEnter the account holder number <1 to 10>:");
	scanf("%d", &t2.acc_number);
	if (t2.acc_number<1 || t2.acc_number>10)
	{
		printf("\nInvalid account number\n");
		printf("\nEnter the account holder number <1 to 10>:");
		scanf("%d", &t2.acc_number);
		
	}
	
		printf("\nEnter the account holder address:");
		scanf("%s", t2.acc_address);
	
	printf("*************************************THE END***********************************");
	printf("\nCreating new account");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf(".");
			Sleep(300);

		}
		for (k = 4; k>0; k--)
		{
			printf("\b \b");
		}
	}

	system("cls");
	printf("\nYour account has been created successfully");
	printf("\nBank name: %s", t2.bankname);
	printf("\nBank branch: %s", t2.branch);
	printf("\nAccount holder name: %s", t2.acc_holder);
	printf("\nAccount number: %d", t2.acc_number);
	printf("\nAccount holder address: %s", t2.acc_address);
	printf("\nAvailabl balance: 0.000000000");
	printf("\nGo back to main menue?Y/N");
	while (1)
	{
		scanf("%c", &ch);
		switch (ch)
		{
		case 'Y':
		case 'y':
			staff_MODE("tanvi");
			break;
		case 'N':
		case 'n':
			break;

		}
	}
	
	Sleep(3000);
	
}
void cash_deposit()
{

	printf("\nCurrent balance for account number %d:0.0000000", t2.acc_number);
	printf("\nEnter money you want to deposit:");
	scanf("%d", &deposit);
	printf("\nThe new balance for account number %d : %d", t2.acc_number, deposit);
	Sleep(3000);

	staff_MODE("tanvi");


}
void account_info()
{
	system("cls");
	printf("\nBank name: %s", t2.bankname);
	printf("\nBank branch: %s", t2.branch);
	printf("\nAccount holder name: %s", t2.acc_holder);
	printf("\nAccount number: %d", t2.acc_number);
	printf("\nAccount holder address: %s", t2.acc_address);
	printf("\nAvailable balance: %d",deposit-withdraw);
	
}
void cash_withdrawl()
{

	printf("\nThe current balance in your account number %d is %d", t2.acc_number, deposit);
	if (deposit == 0)
	{
		printf("\nSorry but you have insuffecient balance!");
		Sleep(2000);
	
		staff_MODE("tanvi");
	}
	
	else
	{
		printf("\nEnter the amount you wish to withdraw:");
		scanf("%d", &withdraw);
		if (withdraw > deposit)
		{
			printf("\nSorry  you have insuffecient balance!");
		}
		else
		{
			printf("\nThe current balance:%d", deposit - withdraw);
		}
		
	}

}
/*void exist_account()
{
	FILE*fp;
	fp = fopen("Text2.txt", "rb");
	fscanf(fp, "%s %s %s %d %s %d", t3.bankname, t3.branch, t3.acc_holder, &t3.acc_number, t3.acc_address, &t3.balance);
	printf("\nBank name: %s", t3.bankname);
	printf("\nBank branch: %s", t3.branch);
	printf("\nAccount holder name: %s", t3.acc_holder);
	printf("\nAccount number: %d", t3.acc_number);
	printf("\nAccount holder address: %s", t3.acc_address);
	printf("\nAvailable balance: %d", t3.balance);

}*/