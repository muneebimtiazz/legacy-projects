#pragma once
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
#include"Date.h"
#include"Billing.h"
class Customer : public Billing
{
private:
	Date Date_of_Birth;
	Date Connection;
	char* Address;
	char* phone;
	char* Name;
	char Metertype;
	char Customertype;
	int ID;
	int Units;
	int PeakUnits;
	char BillPay;
	char Status = 110;
	string saveID;
	string Paid = "PAID";
	string UnPaid = "UNPAID";
public:
	Customer()
	{
		//Date_of_Birth = NULL;
		//Connection = NULL;
		Name = nullptr;
		Metertype = NULL;
		Customertype = NULL;
		ID = 0;
		Units = 0;
		BillPay = NULL;
		PeakUnits = 0;
		Address = nullptr;
		phone = 0;
		Status = NULL;
	}
	void addmeter()
	{
		int d = 0, m = 0, y = 0;
		int size = 20;
		Name = new char[size];
		Address = new char[size + 10];
		phone = new char[size - 8];
		fstream myfile;
		myfile.open("CustomerInfo.txt", ios::app);
		myfile << endl;
		Generate_ID();
		cout << "Enter Date of Birth :\n";
		cout << "Enter Year :";
		cin >> y;
		Date_of_Birth.SetYear(y);
		myfile << Date_of_Birth.GetYear() << "/";
		cout << "Enter Month :";
		cin >> m;
		Date_of_Birth.SetMonth(y);
		myfile << Date_of_Birth.GetMonth() << "/";
		cout << "Enter Date :";
		cin >> d;
		Date_of_Birth.SetDate(d);
		myfile << Date_of_Birth.GetDate() << ",";
		cin.ignore();
		cout << "Enter Name ";
		cin.getline(Name, size);
		myfile << Name << ",";
		cout << "Enter Address ";
		cin.getline(Address, (size + 10));
		myfile << Address << ",";
		cout << "Enter Phone No.";
		cin.getline(phone, (size));
		myfile << phone << ",";
		cout << "Enter Customer Type C/D : ";
		cin >> Customertype;
		myfile << Customertype << ",";
		cout << "Enter Meter Type S/T : ";
		cin >> Metertype;
		myfile << Metertype << ",";
		cout << "Enter Connection Date :\n";
		cout << "Enter Year :";
		cin >> y;
		Connection.SetYear(y);
		myfile << Connection.GetYear() << "/";
		cout << "Enter Month :";
		cin >> m;
		Connection.SetMonth(m);
		myfile << Connection.GetMonth() << "/";
		cout << "Enter Date :";
		cin >> d;
		Connection.SetDate(d);
		myfile << Connection.GetDate() << ",";
		//cout << "Enter Regular Units ";
		//cin >> Units;
		myfile << Units << ",";
		//cout << "Enter Peak Hour Units ";
		//cin >> PeakUnits;
		myfile << PeakUnits << ",";
		//cout << "BiLL Status :";
		//cin >> Status;
		myfile << Status;
		cout << "\nAll done ";
		myfile.close();
		system("cls");
		customerinfo();
	}
	void customerinfo()
	{
		int c = Count_line() + 1;
		int a[4] = { 0 };
		if (c > 9)
		{
			int rev = c % 10;
			a[3] = rev;
			c = c / 10;
			a[2] = c;
		}
		else
		{
			a[3] = c;
		}
		cout << "Your ID :";
		for (int i = 0; i < 4; i++)
		{
			cout << a[i];
		}
		cout << "\nPassword is your DOB : Thankyou\n\n";
	}
	int Count_line()
	{
		fstream file;
		file.open("CustomerInfo.txt");
		string line;
		int count = -1;
		while (!file.eof())
		{
			getline(file, line);
			count++;
		}
		//cout << "Total Customer = " << count;
		return count;
	}
	void Generate_ID()
	{
		int arr[4] = { 0 };
		int a = Count_line() + 1;
		if (a > 9)
		{
			int rev = a % 10;
			arr[3] = rev;
			a = a / 10;
			arr[2] = a;
		}
		else
		{
			arr[3] = a;
		}
		storeinfile(arr);
	}
	void storeinfile(int arr[])
	{
		fstream f;
		f.open("CustomerInfo.txt", ios::app);
		for (int i = 0; i < 4; i++)
		{
			f << arr[i];
		}
		f << ",";
		f.close();
	}
	void CustomerDetailReport()
	{
		char buffer[50];
		string id, Dob, name, address, phone, ctype, mtype, cdate, runits, punits, status;
		fstream myfile;
		myfile.open("CustomerInfo.txt", ios::in);
		while (!myfile.eof())
		{
			myfile.getline(buffer, 50, ',');
			cout << "User ID :";
			cout << buffer << endl;
			myfile.getline(buffer, 50, ',');
			cout << "DOB :";
			cout << buffer << endl;
			myfile.getline(buffer, 50, ',');
			cout << "Name :";
			cout << buffer << endl;
			myfile.getline(buffer, 50, ',');
			cout << "Address :";
			cout << buffer << endl;
			myfile.getline(buffer, 50, ',');
			cout << "Phone No :";
			cout << buffer << endl;
			myfile.getline(buffer, 50, ',');
			cout << "Customer Type :";
			cout << buffer << endl;
			myfile.getline(buffer, 50, ',');
			cout << "Meter Type :";
			cout << buffer << endl;
			myfile.getline(buffer, 50, ',');
			cout << "Connection Date :";
			cout << buffer << endl;
			myfile.getline(buffer, 50, ',');
			cout << "Regular Units :";
			cout << buffer << endl;
			myfile.getline(buffer, 50, ',');
			cout << "Peak Hour Units :";
			cout << buffer << endl;
			myfile.getline(buffer, 50);
			cout << "Paid/Unpaid Status :";
			cout << buffer << endl;
			cout << "----------------------------------------------------" << endl;
		}
		myfile.close();
	}
	bool Customer_Login()
	{

		char buffer[100];
		string id;
		cout << "Enter UserID :";
		cin >> id;
		fstream myfile;
		myfile.open("CustomerInfo.txt", ios::in);
		while (!myfile.eof())
		{
			myfile.getline(buffer, 100, ',');
			if (buffer == id)
			{
				saveID = id;
				myfile.getline(buffer, 100, ',');
				cout << "Enter Password (DOB) (Format Year/Month/Date) :";
				string pass;
				cin >> pass;
				if (pass == buffer)
				{
					cout << "Successfully Login ";
					return true;
				}
				else
				{
					cout << "Wrong Password :----> ";
					return false;
				}
			}
			myfile.getline(buffer, 100);
		}
		myfile.close();
		return false;
	}
	void Display_menu()
	{
		cout << "\t\tWelcome To Customer Interface\t\t" << endl << endl;
		//cout << "----------------------------------------------------" << endl << endl;
		cout << "Press 1: To Check Profile" << endl;
		cout << "Press 2: To Check Paid Bills" << endl;
		cout << "Press 3: To Check UnPaid Bills" << endl;
		cout << "Press 4: To Pay Bills" << endl;
		cout << "Press 5: To Main Page" << endl;
		//cout << "----------------------------------------------------" << endl << endl;
		cout << "Enter your Choice: ";
	}
	void SeeProfile()
	{
		char buffer[100];
		fstream myfile;
		myfile.open("CustomerInfo.txt", ios::in);
		while (!myfile.eof())
		{
			myfile.getline(buffer, 100, ',');
			if (buffer == saveID)
			{
				cout << "----------------------------------------------------" << endl << endl;
				cout << "User ID :";
				cout << buffer << "\n";
				myfile.getline(buffer, 100, ',');
				cout << "DOB :";
				cout << buffer << "\n";
				myfile.getline(buffer, 100, ',');
				cout << "Name :";
				cout << buffer << "\n";
				myfile.getline(buffer, 100, ',');
				cout << "Adress :";
				cout << buffer << "\n";
				myfile.getline(buffer, 100, ',');
				cout << "Phone No :";
				cout << buffer << "\n";
				myfile.getline(buffer, 100, ',');
				cout << "Customer Type :";
				cout << buffer << "\n";
				myfile.getline(buffer, 100, ',');
				cout << "Meter type :";
				cout << buffer << "\n";
				myfile.getline(buffer, 100, ',');
				cout << "Connection Date :";
				cout << buffer << "\n";
				myfile.getline(buffer, 100, ',');
				cout << "Regular Unit :";
				cout << buffer << "\n";
				myfile.getline(buffer, 100, ',');
				cout << "Peak Hour Units :";
				cout << buffer << "\n";
				myfile.getline(buffer, 100);
				cout << "Payment Status :";
				cout << buffer << "\n";
				cout << "----------------------------------------------------" << endl;
				break;
			}
			myfile.getline(buffer, 100);
		}
		myfile.close();
	}
	void Paidbills()
	{
		string code, Month, Regular, Peak, E_Date, price, SalesTaxAmount, Fixed, TotalBilling, Due_Date, Paid_Status, Bill_PaymentDate;
		char buffer[100];
		fstream myfile;
		cout << "\t\t\t| Paid Bills |\t\t\t\n";
		myfile.open("BillingInfo.txt", ios::in);
		while (!myfile.eof())
		{
			myfile.getline(buffer, 100, ',');
			if (buffer == saveID)
			{
				code = buffer;
				myfile.getline(buffer, 100, ',');
				Month = buffer;
				myfile.getline(buffer, 100, ',');
				Regular = buffer;
				myfile.getline(buffer, 100, ',');
				Peak = buffer;
				myfile.getline(buffer, 100, ',');
				E_Date = buffer;
				myfile.getline(buffer, 100, ',');
				price = buffer;
				myfile.getline(buffer, 100, ',');
				SalesTaxAmount = buffer;
				myfile.getline(buffer, 100, ',');
				Fixed = buffer;
				myfile.getline(buffer, 100, ',');
				TotalBilling = buffer;
				myfile.getline(buffer, 100, ',');
				Due_Date = buffer;
				myfile.getline(buffer, 100, ',');
				Paid_Status = buffer;
				myfile.getline(buffer, 100);
				Bill_PaymentDate = buffer;
				if (Paid_Status == Paid)
				{
					cout << "----------------------------------------------------" << endl << endl;
					cout << "User ID :";
					cout << code << "\n";
					cout << "Month :";
					cout << Month << "\n";
					cout << "Regular Reading :";
					cout << Regular << "\n";
					cout << "Peak reading :";
					cout << Peak << "\n";
					cout << "Entry Date :";
					cout << E_Date << "\n";
					cout << "Cost :";
					cout << price << "\n";
					cout << "Sales Tax Amount :";
					cout << SalesTaxAmount << "\n";
					cout << "FixedCharges :";
					cout << Fixed << "\n";
					cout << "Total billing :";
					cout << TotalBilling << "\n";
					cout << "Due Date :";
					cout << Due_Date << "\n";
					cout << "Paid Status :";
					cout << Paid_Status << "\n";
					cout << "Payment Date :";
					cout << Bill_PaymentDate << "\n";
					cout << "----------------------------------------------------" << endl;
				}
			}
			else
			{
				myfile.getline(buffer, 100);
			}
		}
		myfile.close();
	}
	string UnPaidbills(int& count)
	{
		string code, Month, Regular, Peak, E_Date, price, SalesTaxAmount, Fixed, TotalBilling, Due_Date, Paid_Status, Bill_PaymentDate;
		char buffer[100];
		fstream myfile;
		myfile.open("BillingInfo.txt", ios::in);
		while (!myfile.eof())
		{
			myfile.getline(buffer, 100, ',');
			if (buffer == saveID)
			{
				code = buffer;
				myfile.getline(buffer, 100, ',');
				Month = buffer;
				myfile.getline(buffer, 100, ',');
				Regular = buffer;
				myfile.getline(buffer, 100, ',');
				Peak = buffer;
				myfile.getline(buffer, 100, ',');
				E_Date = buffer;
				myfile.getline(buffer, 100, ',');
				price = buffer;
				myfile.getline(buffer, 100, ',');
				SalesTaxAmount = buffer;
				myfile.getline(buffer, 100, ',');
				Fixed = buffer;
				myfile.getline(buffer, 100, ',');
				TotalBilling = buffer;
				myfile.getline(buffer, 100, ',');
				Due_Date = buffer;
				myfile.getline(buffer, 100, ',');
				Paid_Status = buffer;
				myfile.getline(buffer, 100);
				Bill_PaymentDate = buffer;
				if (Paid_Status == UnPaid)
				{
					count++;
					cout << "----------------------------------------------------" << endl << endl;
					cout << "User ID :";
					cout << code << "\n";
					cout << "Month :";
					cout << Month << "\n";
					cout << "Regular Reading :";
					cout << Regular << "\n";
					cout << "Peak reading :";
					cout << Peak << "\n";
					cout << "Entry Date :";
					cout << E_Date << "\n";
					cout << "Cost :";
					cout << price << "\n";
					cout << "Sales Tax Amount :";
					cout << SalesTaxAmount << "\n";
					cout << "FixedCharges :";
					cout << Fixed << "\n";
					cout << "Total billing :";
					cout << TotalBilling << "\n";
					cout << "Due Date :";
					cout << Due_Date << "\n";
					cout << "Paid Status :";
					cout << Paid_Status << "\n";
					//cout << "Payment Date :";
					//cout << Bill_PaymentDate << "\n";
					cout << "----------------------------------------------------" << endl;
				}
			}
			else
			{
				myfile.getline(buffer, 100);
			}
		}
		myfile.close();
		return saveID;
	}
	void updateStatus()
	{
		string i;
		char buffer[100];
		fstream file{ "CustomerInfo.txt", ios::in };
		fstream newfile{ "newCustomer.txt", ios::out | ios::app };
		while (!file.eof())
		{
			file.getline(buffer, 100, ',');
			newfile << buffer << ",";
			i = buffer;
			if (i == saveID)
			{
				file.getline(buffer, 100, ',');
				newfile << buffer << ",";
				file.getline(buffer, 100, ',');
				newfile << buffer << ",";
				file.getline(buffer, 100, ',');
				newfile << buffer << ",";
				file.getline(buffer, 100, ',');
				newfile << buffer << ",";
				file.getline(buffer, 100, ',');
				newfile << buffer << ",";
				file.getline(buffer, 100, ',');
				newfile << buffer << ",";
				file.getline(buffer, 100, ',');
				newfile << buffer << ",";
				file.getline(buffer, 100, ',');
				newfile << buffer << ",";
				file.getline(buffer, 100, ',');
				newfile << buffer << ",";
				newfile << "P";
				file.getline(buffer, 100);
				newfile << endl;
			}
			file.getline(buffer, 100);
			newfile << buffer << endl;
		}
		file.close();
		newfile.close();
		remove("CustomerInfo.txt");
		rename("newCustomer.txt", "CustomerInfo.txt");
	}
};
