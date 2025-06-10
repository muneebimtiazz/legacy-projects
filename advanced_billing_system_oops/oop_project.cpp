#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>
#include"Customer.h";
#include"Billing.h";
using namespace std;
class LESCO :public Customer
{
public:
	char** username;
	int NumofUsers;
	int size;
	LESCO()
	{
		username = nullptr;
		NumofUsers = 0;
		size = 0;
	}
	~LESCO()
	{
		delete[]username;
	}
	void SearchEmploye(string name)
	{
		char buffer[50];
		int count = 0;
		fstream myfile;
		myfile.open("EmployeesData.txt", ios::in);
		while (!myfile.eof())
		{
			myfile.getline(buffer, 50, ',');
			if (buffer == name)
			{
				cout << "Employe Data found -->";
				cout << buffer;
				count++;
			}
			myfile.getline(buffer, 50);
			//cout << buffer;
		}
		myfile.close();
		if (count == 0)
		{
			cout << "No employee Found -->";
		}
	}
	void updatepassword(string newpass, string name)
	{
		bool flag = false;
		char buffer[50];
		fstream firstfile{ "EmployeesData.txt", ios::in };
		fstream secondfile{ "new.txt", ios::out | ios::app };
		while (!firstfile.eof())
		{
			firstfile.getline(buffer, 50, ',');
			if (buffer == name)
			{
				secondfile << buffer << "," << newpass << endl;
				firstfile.getline(buffer, 50);
			}
			else
			{
				secondfile << buffer << ",";
				firstfile.getline(buffer, 50);
				secondfile << buffer << endl;
			}
		}
		firstfile.close();
		secondfile.close();
		remove("EmployeesData.txt");
		rename("new.txt", "EmployeesData.txt");
		//return true;
	}
	int Changepassword(string name)
	{
		char buffer[50];
		fstream myfile;
		myfile.open("EmployeesData.txt", ios::in);
		while (!myfile.eof())
		{
			myfile.getline(buffer, 50, ',');
			if (buffer == name)
			{
				myfile.getline(buffer, 50);
				cout << "Employe Name found -->Changing Password :\n";
				cout << "Enter Previous Password :";
				string pass;
				cin >> pass;
				if (pass == buffer)
				{
					cout << "Correct --> Enter New Password ";
					string newpass;
					cin >> newpass;
					myfile.close();
					updatepassword(newpass, name);
					return 0;
				}
				else
				{
					cout << "Password Doesn't Match ";
				}
				//cout << buffer;
			}
			myfile.getline(buffer, 50);
		}
		myfile.close();
	}
	bool Emp_Login()
	{

		char buffer[50];
		string name;
		cout << "Enter UserName :";
		cin >> name;
		fstream myfile;
		myfile.open("EmployeesData.txt", ios::in);
		while (!myfile.eof())
		{
			myfile.getline(buffer, 50, ',');
			if (buffer == name)
			{
				myfile.getline(buffer, 50);
				cout << "Employe Name found: \n";
				cout << "Enter Password :";
				string pass;
				cin >> pass;
				if (pass == buffer)
				{
					cout << "Successfully Login ";
					return true;
				}
				else
				{
					//cout << "Wrong Password :----> ";
					return false;
				}
			}
			myfile.getline(buffer, 50);
		}
		myfile.close();
		return false;
	}
	void Display_menu()
	{
		cout << "\t\tWelcome To Employee Interface\t\t" << endl << endl;
		//cout << "----------------------------------------------------" << endl << endl;
		cout << "Press 1: To Add Employees" << endl;
		cout << "Press 2: To update Password." << endl;
		cout << "Press 3: Search the Employe" << endl;
		cout << "Press 4: To Add Customer/Meter" << endl;
		cout << "Press 5: To See Detail Report of Customers" << endl;
		cout << "Press 6: To Add Bills of Customers" << endl;
		cout << "Press 7: To Main Page" << endl;
		//cout << "----------------------------------------------------" << endl << endl;
		cout << "Enter your Choice: ";
	}
	void Front_menu()
	{
		cout << "\t\tWelcome To Bijli System \t\t " << endl << endl;
		cout << "----------------------------------------------------" << endl << endl;
		cout << "Press 1: Employee" << endl;
		cout << "Press 2: Customer" << endl;
		cout << "Press 3: Exit" << endl;
		cout << "----------------------------------------------------" << endl << endl;
		cout << "Enter your Choice: ";
	}
	friend istream& operator>>(istream& in, LESCO& l);
	friend ostream& operator<<(ostream& out, LESCO& l);
};
istream& operator>>(istream& in, LESCO& l)
{
	cout << "Enter Number of Employees : ";
	in >> l.NumofUsers;
	cout << "Enter Length of username and password : ";
	in >> l.size;
	l.username = new char* [l.NumofUsers];
	for (int i = 0; i < l.NumofUsers; i++)
	{
		l.username[i] = new char[l.size];
	}
	cout << "Enter Name and then Password Followed by a Comma in the format username, password : " << endl;
	for (int i = 0; i < l.NumofUsers; i++)
	{
		in >> l.username[i];
	}
	return in;
}
ostream& operator<<(ostream& out, LESCO& l)
{
	for (int i = 0; i < l.NumofUsers; i++)
	{
		for (int j = 0; j < l.size; j++)
		{
			out << l.username[i][j];
		}
	}

	return out;
}
int main()
{
	string pass = "LESCO";
	string check;
	bool flag = true;
	bool login = false;
	int	a, x;
	LESCO l1;
	Customer C;
m: l1.Front_menu();
	cin >> x;
	system("cls");
	if (x == 1)
	{
		cout << "Enter Company Password : ";
		cin >> check;
		if (check == pass)
		{
		l: login = l1.Emp_Login();
			if (login)
			{
				system("cls");
				cout << "Successfully Login\n\nPress any key";
				int a = _getch();
			}
			else
			{
				cout << "User Name Or Password Not Found \nWant to try Again ?";
				cout << "\n" << "If you want to try again enter y " << endl;
				cout << "If you want to Exit press any key else y" << endl;
				char b = ' ';
				cin >> b;
				if (b == 'y')
				{
					system("cls");
					goto l;
				}
				else
				{
					flag = false;
					system("cls");
					cout << "System Exited ";
					return 0;
				}
			}
			system("cls");
			while (login && flag)
			{
				l1.Display_menu();
				cin >> a;
				if (a == 1)
				{
					system("cls");
					cin >> l1;
					ofstream out("EmployeesData.txt", ios::app);
					out << endl;
					for (int i = 0; i < l1.NumofUsers; i++)
					{
						//out << endl;
						out << l1.username[i];
						if (i < l1.NumofUsers - 1)
						{
							out << endl;
						}
					}
					//out << endl;
					out.close();
				}
				else if (a == 2)
				{
					system("cls");
					cout << "Enter Name To Search and update password ";
					string name;
					cin >> name;
					l1.Changepassword(name);
				}
				else if (a == 3)
				{
					system("cls");
					cout << "Enter Name To Search in data ";
					string name;
					cin >> name;
					l1.SearchEmploye(name);
				}
				else if (a == 4)
				{
					system("cls");
					cout << "Add customer";
					cout << endl;
					l1.addmeter();
				}
				else if (a == 5)
				{
					system("cls");
					int total = C.Count_line() + 1;
					cout << "Total Customer : " << total << "\n\n";
					l1.CustomerDetailReport();
				}
				else if (a == 6)
				{
					system("cls");
					l1.Add_Bill();
				}
				else if (a == 7)
				{
					system("cls");
					goto m;
				}
				else
				{
					system("cls");
					cout << "Invalid Choice :hehe " << endl;
					return 0;
				}
				cout << "\n" << "If you want to choose again enter y " << endl;
				cout << "If you want to Exit press any key else y" << endl;
				char b = ' ';
				cin >> b;
				if (b == 'y')
				{
					flag = true;
					system("cls");
				}
				else
				{
					flag = false;
					system("cls");
					cout << "System Exited ";
					return 0;
				}
			}
		}
		else
		{
			cout << "Have A Nice Day --> Wrong Password Entered ";
		}
	}
	else if (x == 2)
	{
		cout << "\t\tWelcome To Customer Login\t\t" << endl << endl;
	c: login = C.Customer_Login();
		if (login)
		{
			system("cls");
			cout << "Successfully Login\n\nPress any key";
			int a = _getch();
		}
		else
		{
			cout << "User Name Or Password Not Found \nWant to try Again ?";
			cout << "\n" << "If you want to try again enter y " << endl;
			cout << "If you want to Exit press any key else y" << endl;
			char b = ' ';
			cin >> b;
			if (b == 'y')
			{
				system("cls");
				goto c;
			}
			else
			{
				flag = false;
				system("cls");
				cout << "System Exited ";
				return 0;
			}
		}
		system("cls");
		while (login && flag)
		{
			C.Display_menu();
			cin >> a;
			if (a == 1)
			{
				system("cls");
				C.SeeProfile();
			}
			else if (a == 2)
			{
				system("cls");
				C.Paidbills();
			}
			else if (a == 3)
			{
				int count = 0;
				system("cls");
				cout << "\t\t\t| UnPaid Bills |\t\t\t\n";
				C.UnPaidbills(count);
				if (count == 0)
				{
					cout << "<--- No UNPAID BiLLS --->";
					C.updateStatus();
				}
			}
			else if (a == 4)
			{
				int c = 0;
				system("cls");
				string i;
				cout << "\t\t\t| Pending Bills |\t\t\t\n";
				i = C.UnPaidbills(c);
				if (c == 0)
				{
					cout << "No Pending Bills ";
					C.updateStatus();
				}
				else
				{
					C.paybill(i);
				}
			}
			else if (a == 5)
			{
				system("cls");
				goto m;
			}
			else
			{
				system("cls");
				cout << "Invalid Choice :hehe " << endl;
				return 0;
			}
			cout << "\n" << "If you want to choose again enter y " << endl;
			cout << "If you want to Exit press any key else y" << endl;
			char b = ' ';
			cin >> b;
			if (b == 'y')
			{
				flag = true;
				system("cls");
			}
			else
			{
				flag = false;
				system("cls");
				cout << "System Exited ";
				return 0;
			}
		}
	}
	else
	{
		cout << "System Exited :->>> GOOD Bye ";
		return 0;
	}
}