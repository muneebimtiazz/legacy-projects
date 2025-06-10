#pragma once
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
#include"Date.h"
class Billing
{
private:
	string Status = "UNPAID";
	int id;
	int Units;
	int PeakUnits;
	char BillPay;
	Date Entry;
	Date Due;
	int cost;
	int tax;
	int Total;
	const float SALESTAX = 0.16;
	const int NormalRate = 20;
	const int PeakRate = 25;
	const int FixCharge = 100;
public:
	Billing()
	{
		id = 0;
		int Units = 0;
		int PeakUnits = 0;
		cost = 0;
		tax = 0;
		Total = 0;
	}
	void Add_Bill()
	{
		int m = 0, d = 0, y = 0, a = 0;
		int normal = 0, peak = 0;
		fstream myfile;
		myfile.open("BillingInfo.txt", ios::app);
		myfile << endl;
		cout << "Enter Id ";
		cin >> id;
		Generate_ID(id);
		cout << "Enter Month :";
		cin >> a;
		SetMonth(a);
		cout << "Enter Regular Reading :";
		cin >> Units;
		myfile << Units << ",";
		cout << "Enter Peak Reading :";
		cin >> PeakUnits;
		myfile << PeakUnits << ",";
		cout << "Enter ENTRY Date :\n";
		cout << "Enter Year :";
		cin >> y;
		Entry.SetYear(y);
		myfile << Entry.GetYear() << "/";
		cout << "Enter Month :";
		cin >> m;
		Entry.SetMonth(m);
		myfile << Entry.GetMonth() << "/";
		cout << "Enter Date :";
		cin >> d;
		Entry.SetDate(d);
		myfile << Entry.GetDate() << ",";
		normal = Units * NormalRate;
		peak = PeakUnits * PeakRate;
		cost = normal + peak;
		myfile << cost << ",";
		tax = cost * SALESTAX;
		myfile << tax << ",";
		myfile << FixCharge << ",";
		Total = cost + tax + FixCharge;
		myfile << Total << ",";
		cout << "Enter DUE Date :\n";
		cout << "Enter Year :";
		cin >> y;
		Due.SetYear(y);
		myfile << Due.GetYear() << "/";
		cout << "Enter Month :";
		cin >> m;
		Due.SetMonth(m);
		myfile << Due.GetMonth() << "/";
		cout << "Enter Date :";
		cin >> d;
		Due.SetDate(d);
		myfile << Due.GetDate() << ",";
		myfile << Status << ",";
		system("cls");
		cout << "Data Added to Billing File\n";
		cout << "\nAll done ";
		myfile.close();
	}
	void SetMonth(int m)
	{
		fstream file;
		file.open("BillingInfo.txt", ios::app);
		if (m == 1)
		{
			char d[] = "Jan";
			int size = sizeof(d);
			store_in_file(d, size);
		}
		else if (m == 2)
		{
			char d[] = "Feb";
			int size = sizeof(d);
			store_in_file(d, size);
		}
		else if (m == 3)
		{
			char d[] = "March";
			int size = sizeof(d);
			store_in_file(d, size);
		}
		else if (m == 4)
		{
			char d[] = "April";
			int size = sizeof(d);
			store_in_file(d, size);
		}
		else if (m == 5)
		{
			char d[] = "May";
			int size = sizeof(d);
			store_in_file(d, size);
		}
		else if (m == 6)
		{
			char d[] = "June";
			int size = sizeof(d);
			store_in_file(d, size);
		}
		else if (m == 7)
		{
			char d[] = "July";
			int size = sizeof(d);
			store_in_file(d, size);
		}
		else if (m == 8)
		{
			char d[] = "Aug";
			int size = sizeof(d);
			store_in_file(d, size);
		}
		else if (m == 9)
		{
			char d[] = "Sep";
			int size = sizeof(d);
			store_in_file(d, size);
		}
		else if (m == 10)
		{
			char d[] = "Oct";
			int size = sizeof(d);
			store_in_file(d, size);
		}
		else if (m == 11)
		{
			char d[] = "Nov";
			int size = sizeof(d);
			store_in_file(d, size);
		}
		else if (m == 12)
		{
			char d[] = "Dec";
			int size = sizeof(d);
			store_in_file(d, size);
		}
	}
	void Generate_ID(int d)
	{
		int arr[4] = { 0 };
		int a = d;
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
		f.open("BillingInfo.txt", ios::app);
		for (int i = 0; i < 4; i++)
		{
			f << arr[i];
		}
		f << ",";
		f.close();
	}
	void store_in_file(char d[], int s)
	{
		fstream f;
		f.open("BillingInfo.txt", ios::app);
		for (int i = 0; i < s - 1; i++)
		{
			f << d[i];
		}
		f << ",";
		f.close();
	}
	void paybill(string id)
	{
		char buffer[100];
		int p = 0;
		int u = 0;
		fstream file{ "BillingInfo.txt", ios::in };
		cout << "Which Month Bill you want to pay ?\nFormat ENTER MONTH IN CAPITAL LETTERS\n";
		string m;
		cin >> m;
		string d;
		cout << "Enter Date :";
		cin >> d;
		while (!file.eof())
		{
			file.getline(buffer, 100, ',');
			if (buffer == id)
			{
				file.getline(buffer, 100, ',');
				if (buffer == m)
				{
					file.getline(buffer, 100, ',');
					u = stoi(buffer);
					cout << "Regular Reading : " << buffer << "\n";
					file.getline(buffer, 100, ',');
					p = stoi(buffer);
					cout << "Peak hour Reading : " << buffer << "\n";
					file.getline(buffer, 100, ',');
					file.getline(buffer, 100, ',');
					file.getline(buffer, 100, ',');
					file.getline(buffer, 100, ',');
					file.getline(buffer, 100, ',');
					cout << "Total Bill Including Sales Tax and FixCharges: " << buffer << endl << "\n";
					cout << "You want to Pay ?: Yes/No ";
					string ans;
					cin >> ans;
					if (ans == "yes")
					{
						system("cls");
						cout << " ---Bill paid ---Thankyou!!\n\n";
						file.close();
						updateBilling(id, m, d);
						updateCustomer(id, u, p);
					}
					else
					{
						system("cls");
						cout << "Have a good Day GentleMan\n\n";
					}
				}
			}
			file.getline(buffer, 100);
		}
	}
	void updateBilling(string id, string month, string date)
	{
		char buffer[100];
		string i, m;
		fstream file{ "BillingInfo.txt", ios::in };
		fstream newfile{ "newBilling.txt", ios::out | ios::app };
		while (!file.eof())
		{
			file.getline(buffer, 100, ',');
			newfile << buffer << ",";
			i = buffer;
			file.getline(buffer, 100, ',');
			newfile << buffer << ",";
			m = buffer;
			if (i == id && m == month)
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
				newfile << "PAID," << date;
				file.getline(buffer, 100, ',');
			}
			file.getline(buffer, 100);
			newfile << buffer << endl;
		}
		file.close();
		newfile.close();
		remove("BillingInfo.txt");
		rename("newBilling.txt", "BillingInfo.txt");
	}
	void updateCustomer(string id, int units, int peaks)
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
			if (i == id)
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
				newfile << stoi(buffer) + units << ",";
				file.getline(buffer, 100, ',');
				newfile << stoi(buffer) + peaks << ",";
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