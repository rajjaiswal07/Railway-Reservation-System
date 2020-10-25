#include <iostream>
#include<stdio.h>
#define clrscr() system("cls");
#include<conio.h>
#include <windows.h>
#include <mysql.h>
#include<string>
#include <iomanip>
#include <locale>
#include <sstream>

using namespace std;

//---------------------------------------user define function start----------------------------------
void viewinfo();
void cancelticket();
void bookticket();
void intro();
void admin();
void adminDashboard();
void addTrain();
void deleteTrain();
//---------------------------------------main function start------------------------------------------
int main()
{
	intro();
	string num;
	system("COLOR 0f");
	int ch;
	time_t currentTime;
	time(&currentTime);
	cout<<"\n\t\t\t     %s\n",ctime(&currentTime);

	cout<<"\n\t\t\t*********************************\n";
	cout<<"\t\t\t*******RAILWAY RESERVATION SYSTEM*******\n";
	cout<<"\t\t\t*********************************\n";
	cout<<"\n\t\t\t<<<<<<<<<<WELCOME USERS>>>>>>>>>>\n";
	cout<<"\n\n\t\t\t\t      MENU\n";
	cout<<"\t\t\t             ******";
	cout<<"\n\t\t\t[1] VIEW INFORMATION\n";
	cout<<"\n\t\t\t[2] BOOK TICKET\n";
	cout<<"\n\t\t\t[3] CANCEL TICKET\n";
	cout<<"\n\t\t\t[4] ADMIN";
	cout<<"\n\n\t\t\t[5] EXIT\n";
	cout<<"\n\t\t\t********************************";
	cout<<"\n\t\t\t********************************";
	cout<<"\n\t\t\tENTER YOUR CHOICE: ";

	cin>>ch;
	switch(ch)
	{
		case 1:
			viewinfo();
			break;
			case 2:
				bookticket();
				break;
				case 3:
					cancelticket();
					break;
					case 4:
						admin();
						break;
						case 5:
						    main();
							break;
							default:
								system("cls");
								cout<<"\n\t\t\t==============================================\n";
								cout<<"\t\t\t   *******RAILWAY RESERVATION SYSTEM*******\n";
								cout<<"\t\t\t   ==============================================\n";
								cout<<"\n\n\t\t\t<<<<<<<<YOU ENTERED WRONG CHOICE>>>>>>>>\n";
								cout<<"\t\t\t<<<<<<<<PLEASE ENTER RIGHT THING>>>>>>>>\n";
								getch();
								system("cls");
								main();
	}
	return 0;
}

//-----------------------------------view information function--------------------------------------
void viewinfo()
{
    clrscr();
	int ch;
	//system("cls");
	cout<<"\n\t\t     **********************************************************"<<endl;
	cout<<"\n\t\t     ********************RAILWAY RESERVATION SYSTEM********************"<<endl;
	cout<<"\n\t\t     **********************************************************"<<endl;
	cout<<"train number"<<"   "<<"train name"<<"   "<<"start place"<<"   "<<"destination place"<<"   "<<"price"<<"   "<<"seat"<<"   "<<"time"<<endl;
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES *res;
    int qstate;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn,"localhost","root","","railwaysystem",0,NULL,0);
    string query="select * from traindetails";
    const char* q = query.c_str();
    qstate = mysql_query(conn,q);
    if(!qstate)
        {
            res = mysql_store_result(conn);
            while(row=mysql_fetch_row(res))
            {
		cout<<"    "<<row[1]<<"    "<<row[2]<<"    "<<row[3]<<"    "<<row[4]<<"    "<<row[5]<<"    "<<row[6]<<"    "<<row[7]<<endl;
	            }
        }
        mysql_close(conn);

	cout<<"    ***********************************************************************************************\n";
	cout<<"\n\t\t\tpress '1' for main menu & press any key for exit:  ";
	cin>>ch;
	switch(ch)
	{
		case 1:
			system("cls");
			main();
			break;
				default:
					exit(0);
	}
}

void intro()
{

	cout<<"\n\t\t\t*********************************************************************************";
cout<<"\n\t\t           * VES Institute Of Technology *";
cout<<"\n\t\t\t*************************************************************************************";
cout<<"\n\n\n\n\t\tMade By: \tRaj Jaiswal - 27 ";
cout<<"\t";
	cout<<"\n\n\n";
	cout<<"\n\n\n\t VESIT C++ Mini-PROJECT";
	cout<<"\n\n\n\t TOPIC: Railway Reservation System";
	cout<<"\n\n\n\n\n\n\t\t\t\tPress any key to continue.........";
	getch();
}

//---------------------------------------book ticket function-----------------------------------------------
void bookticket()
{
    //char train_number[20];
	string name;
	string phone;
	string date;
	string source;
	string destination;
	string seat;
	int n,i;
	string trainNumber;
	system ("cls");
	cout<<"\n\n\t\t\t============================================"<<endl;
	cout<<"\n\t\t\t**********RAILWAY RESERVATION SYSTEM**********\n"<<endl;
	cout<<"\t\t\t=================================================="<<endl;
	cout<<"\n\n\t\t\t Enter the Train Number You want to buy Tickets "<<endl;
    cin>>trainNumber;
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES *res;
    int qstate;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn,"localhost","root","","railwaysystem",0,NULL,0);
    string query="select * from traindetails where train_number='"+trainNumber+"'";
    const char* q = query.c_str();
    qstate = mysql_query(conn,q);
    if(!qstate){
            int noOfTickets;
            cout<<"\n\n\t\t\t Enter number of Tickets to buy :"<<endl;
            cin>>noOfTickets;
            for(i=1;i<1+noOfTickets;i++){
                cout<<"\n Enter the Name :";
                cin>>name;
                cout<<"\n Enter the Phone Number :";
                cin>>phone;
                cout<<"\n Enter the Source :";
                cin>>source;
                cout<<"\n Enter the Destination :";
                cin>>destination;
                cout<<"\n Enter the Date :";
                cin>>date;
                cout<<"\n Enter the Seat Number :";
                cin>>seat;
                MYSQL* conn;
                MYSQL_ROW row;
                MYSQL_RES *res;
                //record rec;
                conn = mysql_init(0);
                conn = mysql_real_connect(conn,"localhost","root","","railwaysystem",0,NULL,0);
                //rec.create_record();
                if(conn)
                {
                    string query="INSERT INTO bookedticket(name,phone,source,destination,date,seat) values ('"+name+"','"+phone+"','"+source+"','"+destination+"','"+date+"','"+seat+"')";
                    const char* q = query.c_str();
                    //cout<<"query is: "<<q<<endl;
                    int qstate = mysql_query(conn,q);
                }
                    mysql_close(conn);
            }
        } else {
            cout<<"train not fopund";
                mysql_close(conn);
        }
}

void cancelticket()
{
    string num;
    cout<<"Enter the Mobile Number to cancel Ticket";
    cin>>num;
    MYSQL* conn;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn,"localhost","root","","railwaysystem",0,NULL,0);
	if(conn)
    {
        string query="DELETE FROM bookedticket WHERE phone='"+num+"'";
        const char* q = query.c_str();
        //cout<<"query is: "<<q<<endl;
        int qstate = mysql_query(conn,q);
          if(!qstate)
            cout<<"\n\nRecord Deleted Successfully"<<endl;
        else
            cout<<"query problem: "<<mysql_error(conn)<<endl;
    }
    mysql_close(conn);
}

void admin()
{
    int pass;
    int passcode = 1234567;
    cout<<"*******ADMIN LOGIN**********"<<endl;
    cout<<"Enter the password"<<endl;
    cin>>pass;
    if(pass == passcode) {
        adminDashboard();
    } else {
    cout<<"You Password is Wrong. Please try Again";
    }
}

void adminDashboard()
{
    system("COLOR 0f");
	int ch;
	time_t currentTime;
	time(&currentTime);
	cout<<"\n\t\t\t     %s\n",ctime(&currentTime);

	cout<<"\n\t\t\t*********************************\n";
	cout<<"\t\t\t*******RAILWAY RESERVATION SYSTEM*******\n";
	cout<<"\t\t\t*********************************\n";
	cout<<"\n\t\t\t<<<<<<<<<< WELCOME TO ADMIN PANEL >>>>>>>>>>\n";
	cout<<"\n\n\t\t\t\t      MENU\n";
	cout<<"\t\t\t             ******";
	cout<<"\n\t\t\t[1] ADD TRAIN\n";
	cout<<"\n\t\t\t[2] DELETE TRAIN\n";
	cout<<"\n\t\t\t[3] VIEW PASSENGERS\n";
	cout<<"\n\n\t\t[4] EXIT\n";
	cout<<"\n\t\t\t********************************";
	cout<<"\n\t\t\t********************************";
	cout<<"\n\t\t\tENTER YOUR CHOICE: ";

	cin>>ch;
	switch(ch)
	{
		case 1:
			addTrain();
			break;
			case 2:
				deleteTrain();
				break;
				case 3:
					cancelticket();
					break;
						case 4:
						    main();
							break;
							default:
								system("cls");
								cout<<"\n\t\t\t==============================================\n";
								cout<<"\t\t\t   *******RAILWAY RESERVATION SYSTEM*******\n";
								cout<<"\t\t\t   ==============================================\n";
								cout<<"\n\n\t\t\t<<<<<<<<YOU ENTERED WRONG CHOICE>>>>>>>>\n";
								cout<<"\t\t\t<<<<<<<<PLEASE ENTER RIGHT THING>>>>>>>>\n";
								getch();
								system("cls");
								main();
	}
}

void addTrain()
{
    string trainNumber;
	string trainName;
	string source;
	string destination;
	string price;
	string totalSeats;
	string trainTime;
	system ("cls");
	cout<<"\n\n\t\t\t============================================"<<endl;
	cout<<"\n\t\t\t**********RAILWAY RESERVATION SYSTEM**********\n"<<endl;
	cout<<"\t\t\t=================================================="<<endl;
                cout<<"\n Enter the Train Number :";
                cin>>trainNumber;
                cout<<"\n Enter the Train Name :";
                cin>>trainName;
                cout<<"\n Enter the Source :";
                cin>>source;
                cout<<"\n Enter the Destination :";
                cin>>destination;
                cout<<"\n Enter the Number of Seats :";
                cin>>totalSeats;
                cout<<"\n Enter the Timing of Train :";
                cin>>trainTime;
                 cout<<"\n Enter the Price :";
                cin>>price;
                MYSQL* conn;
                MYSQL_ROW row;
                MYSQL_RES *res;
                //record rec;
                conn = mysql_init(0);
                conn = mysql_real_connect(conn,"localhost","root","","railwaysystem",0,NULL,0);
                //rec.create_record();
                if(conn)
                {
                    string query="INSERT INTO traindetails (train_number,train_name,start_place,destination_place,price,seat,time) values ('"+trainNumber+"','"+trainName+"','"+source+"','"+destination+"','"+price+"','"+totalSeats+"','"+trainTime+"')";

                    const char* q = query.c_str();
                    //cout<<"query is: "<<q<<endl;
                    int qstate = mysql_query(conn,q);
                    cout<<"Train Details Added"<<endl;
                    adminDashboard();
                } else {
                    cout<<"Trains Details Not Added";
                    mysql_close(conn);
                }
}

void deleteTrain()
{
    string trainNumber;
    cout<<"Enter Train Number to delete :"<<endl;
    cin>>trainNumber;
    MYSQL* conn;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn,"localhost","root","","railwaysystem",0,NULL,0);
	if(conn)
    {
        string query="DELETE FROM traindetails WHERE train_number='"+trainNumber+"'";
        const char* q = query.c_str();
        //cout<<"query is: "<<q<<endl;
        int qstate = mysql_query(conn,q);
          if(!qstate){
            cout<<"\n\nTrain Details Deleted Successfully"<<endl;
            adminDashboard();
          } else {
            cout<<"query problem: "<<mysql_error(conn)<<endl;
          }
    }
    mysql_close(conn);
}
