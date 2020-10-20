// Updated : 19-10-20 23:34
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<conio.h>
#include<ctype.h>
#include<fstream>
#include<string>
#include<ctype.h>
using namespace std;
// Function Prototypes
int login_screen();
int main_screen();
int choice_screen(int);
int input_fn(int);
int spacing(int); 
int ticket_booking();
int ticket_cancelation();
int enquiry();
int help();
int thankyou();
int database();
int book_ticket();
int i; //Common Loop Variable
class userDetails
{	char* username[10][20];
	char* password[10][20];
	char* given_username[1][20];
	char* given_password[1][20];
	int usernum, is_admin, is_user;
	public:
		userDetails()
		{
			usernum = 0;
			is_admin = 0;
			is_user = 0;
		}
		int userNum()
		{	
			usernum++;
		}
		int alreadyUser()
		{
			system("cls");
			spacing(1);
			spacing(2);
			printf("\t    Sign In\n");
			spacing(1);
			spacing(2);
			printf("--> Username : ");
			scanf("%s", &given_username[1][20]);
			spacing(2);
			printf("--> Password : ");
			scanf("%s", &given_password[1][20]);
			if (strcmp(given_username[1][20], "admin") == 0)
				if (strcmp(given_password[1][20], "admin") == 0)
					is_admin = 1;
			while(is_admin)
			{
				system("cls");
				database();
			}
			for(i=0;i<usernum;i++)
				if (strcmp(given_username[1][20],username[i][20])==0)
					if (strcmp(given_password[1][20],password[i][20])==0)
						{	
							is_user = 1;
							break;
						}									
			if(is_user == 1)
				{
					spacing(2);
					printf("Welcome, %s", given_username[1][20] );
					system("cls");
					main_screen();
				}
			else
				{
					spacing(2);
					printf("Bad Credentials, Either Username Or Password Incorrect\n");
					printf("Press Any Key to Try Again!");
					getch();
					alreadyUser();
				}				
		}
		int newUser()
		{	
			system("cls");
			spacing(1);
			spacing(2);
			printf("\t    Sign Up\n");
			spacing(1);
			spacing(2);
			printf("--> Username : ");
			scanf("%s", &given_username[1][20]);
			spacing(2);
			printf("--> Password : ");
			scanf("%s", &given_password[1][20]);
			spacing(2);
			strcpy(username[usernum][20], given_username[1][20]);
			strcpy(password[usernum][20], given_password[1][20]);
			userNum();	
			alreadyUser();
			return 0;		
		}
		
}dataKey ;
int main()
{ //Main Function
	login_screen();
	return 0;
}
int login_screen()
{ //Login Screen 
	fstream alreadyUser_obj, newUser_obj;
	system("cls");
	spacing(1);
	spacing(2);
	printf("\tTicket Reservation\n");
	spacing(1);
	spacing(2);
	printf("      Login to Continue");
	spacing(2);
	printf("      --> Sign In");
	spacing(2);
	printf("      --> Sign Up");
	spacing(2);
	printf("      Choose Option (1/2) : ");
	cin>>i;
	switch (i)
	{
		case 1: // Case for Already User
			input_fn(i);
			alreadyUser_obj.open("UserDetails.dat", ios::in | ios::out );
			alreadyUser_obj.read((char *)&dataKey, sizeof(dataKey));
			dataKey.alreadyUser();
			alreadyUser_obj.close();
			break;
		case 2: // Case for New User
			input_fn(i);
			newUser_obj.open("UserDetails.dat", ios::in | ios::out | ios::app  );
			newUser_obj.write((char *)&dataKey, sizeof(dataKey));
			dataKey.newUser();
			newUser_obj.close();
			break;
		default: 
			printf("\n");
			for (i = 0; i <= 5; i++)
				printf("\t   ");
			printf("------INVALID INPUT-------");
			sleep(2);
			system("cls");
			login_screen();
			break;
	}
}
int main_screen()
{ //Main Screen
	spacing(1);
	spacing(2);
	printf("\tTicket Reservation\n");
	spacing(1);
	spacing(2);
	printf("--> Book Ticket");
	spacing(2);
	printf("--> Cancel Ticket");
	spacing(2);
	printf("--> Enquiry");
	spacing(2);
	printf("--> Help");
	spacing(2);
	printf("--> Exit");
	spacing(2);
	printf("Choose Option (1/2/3/4/5) : ");
	scanf("%d", &i);
	choice_screen(i);
	return 0;
}
int choice_screen(int main_choice)
{ //Function for choice input of main screen
	switch (main_choice)
	{
	case 1:
		input_fn(main_choice);
		ticket_booking();
		break;
	case 2:
		input_fn(main_choice);
		ticket_cancelation();
		break;
	case 3:
		input_fn(main_choice);
		enquiry();
		break;
	case 4:
		input_fn(main_choice);
		help();
		break;
	case 5:
		input_fn(main_choice);
		thankyou();
		break;
	default:
		printf("\n");
		for (i = 0; i <= 5; i++)
			printf("\t   ");
		printf("------INVALID INPUT-------");
		sleep(2);
		system("cls");
		main_screen();
	}
	return 0;
}
int spacing(int spacing_value)
{ //Function for spacing
	switch (spacing_value)
	{
	case 1:
		for (i = 0; i < 3; i++) //Heading Spacing
			printf("\n");
		for (i = 0; i < 5; i++)
			printf("\t");
		for (i = 0; i <= 32; i++)
			printf("*");
	case 2:
		for (i = 0; i < 2; i++) //Paragraph Spacing
			printf("\n");
		for (i = 0; i < 5; i++)
			printf("\t");
		return 0;
	}
}
int input_fn(int input_value)
{ //Function for showing Input
	for (i = 0; i <= 5; i++)
		printf("\t    ");
	printf("Your Choice --> ");
	printf("%d", input_value);
	sleep(1.5);
	system("cls");
	for (i = 0; i < 10; i++)
		printf("\n\t\t\t\t   ");
	printf("--------------REDIRECTING---------------");
	sleep(1.5);
	system("cls");
}
int ticket_booking()
{ //Ticket Booking Screen
	spacing(1);
	spacing(2);
	printf("\t  Ticket Booking\n");
	spacing(1);
	spacing(2);
	printf("--> Book Ticket");
	spacing(2);
	printf("--> Review Ticket");
	spacing(2);
	printf("--> Ticket Chart");
	spacing(2);
	printf("--> Go Back");
	spacing(2);
	printf("--> Exit");
	spacing(2);
	printf("Choose Option (1/2/3/4/5) : ");
	scanf("%d", &i);
	switch (i)
	{
	case 1:
		input_fn(i);
		book_ticket();
		break;
	case 2:
		input_fn(i);
		break;
	case 3:
		input_fn(i);
		break;
	case 4:
		input_fn(i);
		main_screen();
		break;
	case 5:
		input_fn(i);
		thankyou();
		break;
	default:
		printf("\n");
		for (i = 0; i <= 5; i++)
			printf("\t   ");
		printf("------INVALID INPUT-------");
		sleep(2);
		system("cls");
		ticket_booking();
	}
	return 0;
}
int ticket_cancelation()
{ //Ticket Cancellation Screen
	spacing(1);
	spacing(2);
	printf("\tTicket Cancellation\n");
	spacing(1);
	spacing(2);
	printf("--> Cancel Ticket");
	spacing(2);
	printf("--> Review Ticket");
	spacing(2);
	printf("--> Ticket Chart");
	spacing(2);
	printf("--> Go Back");
	spacing(2);
	printf("--> Exit");
	spacing(2);
	printf("Choose Option (1/2/3/4/5) : ");
	scanf("%d", &i);
	switch (i)
	{
	case 1:
		input_fn(i);
		break;
	case 2:
		input_fn(i);
		break;
	case 3:
		input_fn(i);
		break;
	case 4:
		input_fn(i);
		main_screen();
		break;
	case 5:
		input_fn(i);
		thankyou();
		break;
	default:
		printf("\n");
		for (i = 0; i <= 5; i++)
			printf("\t   ");
		printf("------INVALID INPUT-------");
		sleep(2);
		system("cls");
		ticket_cancelation();
	}
	return 0;
}
int enquiry()
{ //Function for searching for train details
	spacing(1);
	spacing(2);
	printf("\tTrain Enquiry\n");
	spacing(1);
	spacing(2);
	printf("--> By Name");
	spacing(2);
	printf("--> By Number");
	spacing(2);
	printf("--> By Station");
	spacing(2);
	printf("--> Go Back");
	spacing(2);
	printf("--> Exit");
	spacing(2);
	printf("Choose Option (1/2/3/4/5) : ");
	scanf("%d", &i);
	switch (i)
	{
	case 1:
		input_fn(i);
		break;
	case 2:
		input_fn(i);
		break;
	case 3:
		input_fn(i);
		break;
	case 4:
		input_fn(i);
		main_screen();
		break;
	case 5:
		input_fn(i);
		thankyou();
		break;
	default:
		printf("\n");
		for (i = 0; i <= 5; i++)
			printf("\t   ");
		printf("------INVALID INPUT-------");
		sleep(2);
		system("cls");
		database();
	}
	return 0;
}
int help()
{ //Function for providing help
	spacing(1);
	spacing(2);
	printf("\t     Help\n");
	spacing(1);
	spacing(2);
	printf("Press Any Key to Go Back.....");
	getch();
	system("cls");
	main_screen();
}
int thankyou()
{ //Thank You Screen
	spacing(1);
	spacing(2);
	printf("\t   Thank You!");
	spacing(2);
	printf("\t   Visit Again\n");
	spacing(1);
	sleep(1.5);
	system("cls");
	exit(0);
}
int database()
{ //Function for Storing All Details
	spacing(1);
	spacing(2);
	printf("\tDatabase\n");
	spacing(1);
	spacing(2);
	printf("--> User Database");
	spacing(2);
	printf("--> Admin Databse");
	spacing(2);
	printf("--> Travel Database");
	spacing(2);
	printf("--> Go Back");
	spacing(2);
	printf("--> Exit");
	spacing(2);
	printf("Choose Option (1/2/3/4/5) : ");
	scanf("%d", &i);
	switch (i)
	{
	case 1:
		input_fn(i);
		break;
	case 2:
		input_fn(i);
		break;
	case 3:
		input_fn(i);
		break;
	case 4:
		input_fn(i);
		main_screen();
		break;
	case 5:
		input_fn(i);
		thankyou();
		break;
	default:
		printf("\n");
		for (i = 0; i <= 5; i++)
			printf("\t   ");
		printf("------INVALID INPUT-------");
		sleep(2);
		system("cls");
		database();
	}
	return 0;
}
int book_ticket()
{ //Function for booking ticket
	spacing(1);
	spacing(2);
}
