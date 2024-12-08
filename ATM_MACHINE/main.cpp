#include <iostream>
#include <cstring>
#include <string>
#include<sstream>
#include <math.h>
#include <fstream>
#include <conio.h>
#include<stdlib.h>


using namespace std;

void startmenu();
void createacc();
void loginacc();
void interface(string, string, string);

void startmenu()
{
	system("Color 8F");
	cout << "* * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
	cout << "* * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
	cout << "*                                               *" << endl;
	cout << "*         WELCOME TO GREEMINES ATM!             *" << endl;
	cout << "*                                               *" << endl;
	cout << "*   PLEASE SELECT A OPTION TO CONTINUE FURTHUR. *" << endl;
	cout << "*                                               *" << endl;
	cout << "*             1. CREATE A NEW ACCOUNT.          *" << endl;
	cout << "*             2.       LOGIN                    *" << endl;
	cout << "*                                               *" << endl;
	cout << "*                                               *" << endl;
	cout << "*                                               *" << endl;
	cout << "* * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
	cout << "* * * * * * * * * * * * * * * * * * * * * * * * *" << endl;

}
void createacc()
{
	cout << "* * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
	cout << "* * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
	cout << "*                                               *" << endl;
	cout << "*         WELCOME TO GREEMINES ATM!             *" << endl;
	cout << "*                                               *" << endl;
	cout << "*             CREATE A NEW ACCOUNT              *" << endl;
	cout << "*                                               *" << endl;
	cout << "*          PLEASE ENTER VALID DETAILS.          *" << endl;
	cout << "*                                               *" << endl;
	cout << "*  Step 1: ENTER YOUR Username:                 *" << endl;
	cout << "*  Step 2: CREATE A SECURE PIN:                 *" << endl;
	cout << "*                                               *" << endl;
	cout << "*                                               *" << endl;
	cout << "* * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
	cout << "* * * * * * * * * * * * * * * * * * * * * * * * *" << endl;

	string name;
	string ans;
	ofstream myfile;
	char pin[5];
	int i = 1;

	int y = 0;
	cout << endl;
	cout << "Username: ";
	getline(cin, name);
	getline(cin, name);
	cout << endl;
	myfile.open(name);


	cout << "Enter Unique 4-digit PIN :";
	for (int i = 0; i < 4; i++)
	{
		pin[i] = _getch();
		cout << "*";
	}



	for (int i = 0; i < 4; i++)
	{
		myfile << pin[i];
	}
	myfile << endl << "0.00" << endl;

	cout << endl;
	cout << "Your account has been created. THANK YOU";
	cout << endl;
	myfile.close();
	cout << "Would you like to proceed to login? (Y/N)";
	getline(cin, ans);
	if (ans == "Y" || ans == "y")
	{
		cout << "Proceeding to login";
		cout << endl;

		loginacc();
	}
	else
	{
		cout << "Invalid Choice!!!!";
	}

}
void loginacc()
{
	cout << "* * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
	cout << "* * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
	cout << "*                                               *" << endl;
	cout << "*         WELCOME TO GREEMINES ATM!             *" << endl;
	cout << "*                                               *" << endl;
	cout << "*                   LOGIN                       *" << endl;
	cout << "*                                               *" << endl;
	cout << "*            ENTER YOUR CREDENTIALS:            *" << endl;
	cout << "*                                               *" << endl;
	cout << "*      1. ENTER YOUR USERNAME:                  *" << endl;
	cout << "*                                               *" << endl;
	cout << "*      2. ENTER YOUR PIN:                       *" << endl;
	cout << "*                                               *" << endl;
	cout << "*                                               *" << endl;
	cout << "* * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
	cout << "* * * * * * * * * * * * * * * * * * * * * * * * *" << endl << endl;

	ifstream myfile;
	string savedpin;
	string filename;
	string balance;
	string PIN;



	cout << "ENTER YOUR USERNAME: ";
	cin >> filename;
	myfile.open(filename);
	if (myfile.is_open())
	{
		for (int i = 1; i <= 2; i++)
		{
			if (i == 1)
			{
				getline(myfile, savedpin);
			}
			if (i == 2)
			{
				getline(myfile, balance);
			}
		}
		int pincount = 3;
	repeat:
		if (pincount != 0)
		{

			cout << "ENTER PIN " << pincount << " tries left:";


			while (!(cin >> PIN)) {
				cout << "Invalid input. Please enter an integer: ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}



			if (PIN == savedpin)
			{
				interface(balance, PIN, filename);
				return;
			}
			else
			{


				cout << "you have entered wrong username or PIN.\n";

				pincount--;

				goto repeat;
			}
		}
		else
		{
			cout << "OPPS[OUT OF TRIES]";
			exit(0);
		}
	}
	else
	{
		cout << "\"YOU ARE NOT IN OUR DATABASE PLEASE REGESTER YOURSELF FIRST\"" << endl;
		createacc();
	}

}
void interface(string balance, string pin, string filename)
{
	int intbalance = 0;
	stringstream geek(balance);
	geek >> intbalance;
	while (true) {
		cout << "* * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
		cout << "* * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
		cout << "*                                               *" << endl;
		cout << "*         WELCOME TO GREEMINES ATM!             *" << endl;
		cout << "*                                               *" << endl;
		cout << "*              PLEASE ENTER OPTION              *" << endl;
		cout << "*                                               *" << endl;
		cout << "*              1. CHECK BALANCE                 *" << endl;
		cout << "*              2. WITHDRAW CASH                 *" << endl;
		cout << "*              3. DEPOSIT CASH                  *" << endl;
		cout << "*              4. CHANGE PIN                    *" << endl;
		cout << "*              5. EXIT TO MAIN MENU             *" << endl;
		cout << "*                                               *" << endl;
		cout << "*                                               *" << endl;
		cout << "* * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
		cout << "* * * * * * * * * * * * * * * * * * * * * * * * *" << endl << endl << endl;

		int x;
		do {
			cout << "Option: ";
			while (!(cin >> x)) {
				cout << "Invalid input. Please enter an integer: ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}

			switch (x)
			{
			case 1:
				cout << "Your balance is: " << intbalance << ".Rs" << endl;
				break;

			case 2:
			{
				int money;
				cout << "Your current balance is: " << intbalance << ".Rs" << endl;
				cout << "How much cash you want to withdraw: ";
			retry:
				while (!(cin >> money)) {
					cout << "Invalid input. Please enter an integer: ";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				if (money > intbalance)
				{
					cout << "You don't have that amount of money. Please re-enter amount: ";
					goto retry;
				}
				intbalance -= money;
				cout << "THANK YOU FOR WITHDRAWAL. YOUR CURRENT BALANCE IS: " << intbalance << ".Rs" << endl;
				ofstream myfile;
				myfile.open(filename);
				myfile << pin << endl;
				myfile << intbalance << ".Rs" << endl;
				break;
			}

			case 3:
			{
				int Snumber;
				int money = 0;
				cout << "Your current balance is: " << intbalance << ".Rs" << endl;
			otp:
				cout << "Enter OTP from your phone: "; // OTP has been initialized with a value since we aren't receiving an OTP
				while (!(cin >> Snumber)) {
					cout << "Invalid input. Please enter an integer: ";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				if (Snumber == 1234)
				{
					cout << "How much cash you want to deposit: ";
					while (!(cin >> money)) {
						cout << "Invalid input. Please enter an integer: ";
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}
				}
				else
				{
					cout << "Wrong OTP. Please try again.";
					goto otp;
				}
				intbalance += money;
				cout << "Thank you for depositing. Your current balance is: " << intbalance << ".Rs" << endl;
				ofstream myfile;
				myfile.open(filename);
				myfile << pin << endl;
				myfile << intbalance << ".Rs" << endl;
				break;
			}

			case 4:
			{
				string PIN;
				cout << "Enter your previous PIN code: ";
				while (!(cin >> PIN)) {
					cout << "Invalid input. Please enter an integer: ";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				if (PIN == pin)
				{
					string Pin;
				repeat:
					cout << "Enter New pin: ";
					while (!(cin >> Pin)) {
						cout << "Invalid input. Please enter an integer: ";
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}
					cout << "Confirm your pin: ";
					while (!(cin >> Pin)) {
						cout << "Invalid input. Please enter an integer: ";
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}
					if (Pin == PIN)
					{
						ofstream myfile;
						myfile.open(filename);
						myfile << Pin << endl;
						myfile << balance << endl;
						cout << "Your PIN has been successfully changed. THANK YOU.";
						myfile.close();
					}
					else
					{
						cout << "Both pins do not match." << endl;
						goto repeat;
					}
				}
				break;
			}

			case 5:
			{
				system("CLS");
				int x;
				cout << endl;
				cout << endl;
				startmenu();
				cout << endl;
				cout << "OPTION: ";
				while (!(cin >> x)) {
					cout << "Invalid input. Please enter an integer: ";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				switch (x)
				{
				case 1:
					createacc();
					break;
				case 2:
					loginacc();
					break;
				default:
					cout << "Invalid option, please try again!" << endl;
					break;
				}
				break;
			}

			default:
				cout << "Invalid choice, please try again." << endl;
				break;
			}

		} while (x < 1 || x > 5); // Repeat until a valid choice (1 to 5) is entered
	}
}

int main()
{
	int x;
	do {
		cout << endl;
		cout << endl;
		startmenu();  // Assuming this function displays the main menu
		cout << endl;
		cout << "OPTION: ";
		cin >> x;

		switch (x)
		{
		case 1:
			cout << endl;
			createacc();  // Assuming this function creates an account
			cout << endl;
			break;
		case 2:
			cout << endl;
			loginacc();  // Assuming this function logs in
			cout << endl;
			break;
		default:
			cout << "Invalid option, please try again." << endl;
			break;
		}
	} while (x != 1 && x != 2);  // Loop until a valid option (1 or 2) is selected

	(void)_getch();  // Wait for user input before exiting (optional)
	return 0;
}