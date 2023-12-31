﻿#include<iostream>
#include<iomanip>
#include<fstream>
#include<windows.h>
using namespace std;

void menu();

class ManageMenu
{
protected:
	string userName;
public:
	ManageMenu() {
		system("color 0A");
		cout << "\n\n\n Enter Your Name to continue as an Admin" << endl ;
		cin >> userName;
		system("CLS");
		menu();
	}
	~ManageMenu() {

	};
};

class Customers {
public:
	std::string name, gender, address;
	int age, mobileNo; 
	static int customerID;
	char all[999];

	void getDetails() {
		ofstream out("old-customers.txt", ios::app);
		{
			std::cout << "Enter Customer ID :" << std::endl;
			std::cin >> customerID;
			std::cout << "Enter Name :" << std::endl;
			std::cin >> name;
			std::cout << "Enter Age :" << std::endl;
			std::cin >> age;
			std::cout << "Enter Mobile Number :" << std::endl;
			std::cin >> mobileNo;
			std::cout << "Enter Address :" << std::endl;  
			std::cin >> address;
			std::cout << "Enter your gender :" << std::endl;
			std::cin >> gender;
		}
		out << "\n Cutomer ID:" << customerID << "\n Name:" << name << "\n Age:" << age << "\n Mobile Number:" << mobileNo << "\n Gender:" << gender<< "\n Address:"<<address;
		out.close();
		cout << "\n SAVED \n NOTE: We save your details record for future purposes \n" << endl;

	}

	void showDetails()
	{
		ifstream in("old-customers.txt");
		{
			if (!in)
			{
				cout << "File Error!" << endl;

			}
			while (!(in.eof())) {
				in.getline(all,999);
				cout << all;
			}
			in.close();
		}
	}

};

int Customers::customerID;

class Cabs {
public:
	int cabChoice;
	int kilometers;
	float cabCost;
	static float lastcabCost;

	void cabDetails()
	{
		cout << "We collaborate with fastest,safest and smartest cab service around the counrty" << endl<<endl;
		cout << "-----------------STARTREK TRAVEL-------------------" << endl<<endl;
		cout << "1. Rent a Standard Cab - Rs.15 for 1Km" << endl;
		cout << "2. Rent a Luxury Cab - Rs.25 for 1Km" << endl;
		cout << "\n To calculate the cost for your journey:" << endl;
		cout << "Enter which kind of cab you need : \t";
		cin >> cabChoice;
		cout << "Enter kilometers you have to travel : \t";
		cin >> kilometers;
		int hireCab;
		if (cabChoice == 1) {
			cabCost = kilometers * 15;
			cout << "\n Your tour cost " << cabCost << " rupees for a Standard Cab" << endl;
			cout << "Press 1 to hire this cab OR \t";
			cout << "Press 2 to select another cab"<<endl;
			cin >> hireCab;
			system("CLS");
			if (hireCab == 1)
			{
				lastcabCost = cabCost;
				cout << "\n You have successfully hired a Standard cab" << endl;
				cout << "Goto Menu and take the bill " << endl;
			}
			else if (hireCab == 2)
			{
				cabDetails();
			}
			else {
				cout << "Invalid Input! Redirecting .... \n Please Wait" << endl;
				Sleep(600);
				system("CLS");
				cabDetails();
			}
		}
		else if (cabChoice == 2) {
			cabCost = kilometers * 25;
			cout << "\n Your tour cost " << cabCost << " rupees for a Luxury Cab" << endl;
			cout << "Press 1 to hire this cab: or";
			cout << "Press 2 to select another cab:";
			cin >> hireCab;
			system("CLS");
			if (hireCab == 1)
			{
				lastcabCost = cabCost;
				cout << "\n You have successfully hired a Luxury cab" << endl;
				cout << "\n Goto Menu and take the bill " << endl;
			}
			else if (hireCab == 2)
			{
				cabDetails();
			}
			else {
				cout << "Invalid Input! Redirecting .... \n Please Wait" << endl;
				Sleep(600);
				system("CLS");
				cabDetails();
			}
		}
		else {
			cout << "Invalid Input! Redirecting to the main menu .... \n Please Wait" << endl;
			Sleep(600);
			system("CLS");
			menu();
				
		}
		cout << "\n Press 1 to Redirect Main Menu";
		cin >> hireCab;
		system("CLS");
		if (hireCab == 1)
		{
			menu();
		}
		else {
			menu();
		}

	}
	
	};

float Cabs::lastcabCost;

	class Bookings {
	public:
		int choiceHotel;
		int packChoice;
		 static float hotelCost;

		void Hotels()
		{
			string hotelNo[] = { "Hilton" , "Raddison" , "Mariott", "Merdian" };
			for (int i = 0; i < 4; i++)
			{
				cout << (i + 1) << ". Hotel"<<" "<<" "<< hotelNo[i] << endl;
			}
			cout << "\n Currently we collaborated with above hotels" << endl;
			cout << "Press any key to back or \n Enter number of the hotel you want to book:";
				cin >>choiceHotel ;
				system("CLS");
				if (choiceHotel == 1) {
					cout << "------ WELCOME TO THE HOTEL HILTON ------" << endl;
					cout << "The Garden , food and beverage . Enjoy all you can drink , Stay cool and enjoy" << endl;
					cout << "Packages offered by HILTON : \n" << endl;
					cout << "1: Standard Pack :";
					cout << "\t All basic facilities you need just for: Rs 10,000 " << endl;
					cout << "2: Premium Pack" << endl;
					cout << "\t Enjoy the premium experience at : Rs 25,000 " << endl;
					cout << "3: Luxury Pack" << endl;
					cout << "\t Experience Luxury at : Rs 50,000" << endl;
					cout << "\n Press another key to back or \n Enter package number you want to book :";
					cin >> packChoice;
					if (packChoice == 1) {
						hotelCost = 10000.00;
						cout << "\n You have successfully booked Standard Pack at Hilton" << endl;
						cout << "\n Goto Menu and take the receipt" << endl;
					}
					else if (packChoice == 2)
					{
						hotelCost = 25000.00;
						cout << "\n You have successfully booked Premium Pack at Hilton" << endl;
						cout << "\n Goto Menu and take the receipt" << endl;

					}
					else if (packChoice == 3)
					{
						hotelCost = 50000.00;
						cout << "\n You have successfully booked Luxury Pack at Hilton" << endl;
						cout << "\n Goto Menu and take the receipt" << endl;

					}
					else
					{
						cout << "Invalid choice ! Redirecting .... \n Please Wait !" << endl;
						Sleep(600);
						system("CLS");
						Hotels();
					}
					int gotoMenu;
					cout << "\n Press 1 to redirect to Main menu : \t" << endl;
					cin >> gotoMenu;
					if (gotoMenu == 1) {
						menu();
					}
					else {
						menu();
					}

				}
				else if (choiceHotel == 2) {
					cout << "------ WELCOME TO THE HOTEL RADDISON ------" << endl;
					cout << "The Garden , food and beverage . Enjoy all you can drink , Stay cool and enjoy" << endl;
					cout << "Packages offered by RADDISON : \n" << endl;
					cout << "1: Standard Pack :";
					cout << "\t All basic facilities you need just for: Rs 5,000 " << endl;
					cout << "2: Premium Pack" << endl;
					cout << "\t Enjoy the premium experience at : Rs 15,000 " << endl;
					cout << "3: Luxury Pack" << endl;
					cout << "\t Experience Luxury at : Rs 30,000" << endl;
					cout << "\n Press another key to back or \n Enter package number you want to book :";
					cin >> packChoice;
					if (packChoice == 1) {
						hotelCost = 5000.00;
						cout << "\n You have successfully booked Standard Pack at Raddison" << endl;
						cout << "\n Goto Menu and take the receipt" << endl;
					}
					else if (packChoice == 2)
					{
						hotelCost = 15000.00;
						cout << "\n You have successfully booked Premium Pack at Raddison" << endl;
						cout << "\n Goto Menu and take the receipt" << endl;

					}
					else if (packChoice == 3)
					{
						hotelCost = 30000.00;
						cout << "\n You have successfully booked Luxury Pack at Raddison" << endl;
						cout << "\n Goto Menu and take the receipt" << endl;

					}
					else
					{
						cout << "Invalid choice ! Redirecting .... \n Please Wait !" << endl;
						Sleep(600);
						system("CLS");
						Hotels();
					}


				}
				else  if (choiceHotel == 3) {
					cout << "------ WELCOME TO THE HOTEL MARIOTT ------" << endl;
					cout << "The Garden , food and beverage . Enjoy all you can drink , Stay cool and enjoy" << endl;
					cout << "Packages offered by Mariott : \n" << endl;
					cout << "1: Standard Pack :";
					cout << "\t All basic facilities you need just for: Rs 20,000 " << endl;
					cout << "2: Premium Pack" << endl;
					cout << "\t Enjoy the premium experience at : Rs 45,000 " << endl;
					cout << "3: Luxury Pack" << endl;
					cout << "\t Experience Luxury at : Rs 70,000" << endl;
					cout << "\n Press another key to back or \n Enter package number you want to book :";
					cin >> packChoice;
					if (packChoice == 1) {
						hotelCost = 20000.00;
						cout << "\n You have successfully booked Standard Pack at Mariott" << endl;
						cout << "\n Goto Menu and take the receipt" << endl;
					}
					else if (packChoice == 2)
					{
						hotelCost = 45000.00;
						cout << "\n You have successfully booked Premium Pack at Mariott" << endl;
						cout << "\n Goto Menu and take the receipt" << endl;

					}
					else if (packChoice == 3)
					{
						hotelCost = 70000.00;
						cout << "\n You have successfully booked Luxury Pack at Mariott" << endl;
						cout << "\n Goto Menu and take the receipt" << endl;

					}
					else
					{
						cout << "Invalid choice ! Redirecting .... \n Please Wait !" << endl;
						Sleep(600);
						system("CLS");
						Hotels();
					}


				}
				else if (choiceHotel == 4) {
					cout << "------ WELCOME TO THE HOTEL MERIDIAN ------" << endl;
					cout << "The Garden , food and beverage . Enjoy all you can drink , Stay cool and enjoy" << endl;
					cout << "Packages offered by Meridian : \n" << endl;
					cout << "1: Standard Pack :";
					cout << "\t All basic facilities you need just for: Rs 10,000 " << endl;
					cout << "2: Premium Pack" << endl;
					cout << "\t Enjoy the premium experience at : Rs 25,000 " << endl;
					cout << "3: Luxury Pack" << endl;
					cout << "\t Experience Luxury at : Rs 50,000" << endl;
					cout << "\n Press another key to back or \n Enter package number you want to book :";
					cin >> packChoice;
					if (packChoice == 1) {
						hotelCost = 10000.00;
						cout << "\n You have successfully booked Standard Pack at Meridian" << endl;
						cout << "\n Goto Menu and take the receipt" << endl;
					}
					else if (packChoice == 2)
					{
						hotelCost = 25000.00;
						cout << "\n You have successfully booked Premium Pack at Meridian" << endl;
						cout << "\n Goto Menu and take the receipt" << endl;

					}
					else if (packChoice == 3)
					{
						hotelCost = 50000.00;
						cout << "\n You have successfully booked Luxury Pack at Meridian" << endl;
						cout << "\n Goto Menu and take the receipt" << endl;

					}
					else
					{
						cout << "Invalid choice ! Redirecting .... \n Please Wait !" << endl;
						Sleep(600);
						system("CLS");
						Hotels();
					}


				}
				else
				{
					cout << "Invalid choice ! Redirecting .... \n Please Wait !" << endl;
					Sleep(600);
					system("CLS");
					menu();
					}

		}

	};

	float Bookings::hotelCost;

	class Charges : public Bookings,Cabs,Customers {

	public:
		void printBill()
		{
			ofstream outf("receipt.txt");
			{
				outf << "------  STARTREK TRAVEL AGENCY ------" << endl;
				outf << "------------ RECEIPT ------------" << endl;
				outf << "_________________________________" << endl;
				outf << "Customer ID:" << Customers::customerID << endl << endl;
				outf << "Description \t \t Total" << endl;
				outf << "Hotel cost: \t \t" << fixed << setprecision(2) << Bookings::hotelCost << endl;
				outf << "Travel (cab) cost :\t" << fixed << setprecision(2) << Cabs::lastcabCost << endl;
				outf << "_________________________________" << endl;
				outf << "Total Charge: \t\t" << fixed << setprecision(2) << Bookings::hotelCost + Cabs::lastcabCost << endl;
				outf << "_________________________________" << endl;
				outf << "____________ THANK YOU __________" << endl;


			}

			outf.close();
		}
		void showBill() {
			ifstream inf("receipt.txt");
			{
				if (!inf)
				{
					cout << "File opening error !" << endl;
				}
				while (!(inf.eof())) {
					inf.getline(all, 999);
					cout << all << endl;
				}
			}
			inf.close();
		}
	};

	void menu()
	{
		int mainChoice;
		int inChoice;
		int gotoMenu;


		cout << "\t\t\t   * STARTREK TRAVEL * \n" << endl;
		cout << "\t----------------------- MAIN MENU ----------------------" << endl;
		cout << "\t________________________________________________________\n" << endl;
		//cout << "\t|\t|\t|\t|\t|"<<endl
		cout << "\t|\t\tCustomer Management -> 1\t\t|" << endl;
		cout << "\t|\t\tCabs Management     -> 2\t\t|" << endl;
		cout << "\t|\t\tBookings Management -> 3\t\t|" << endl;
		cout << "\t|\t\tCharges and Bills   -> 4\t\t|" << endl;
		cout << "\t|\t\tExit                -> 5\t\t|" << endl;
		/*cout << "\t|\t|\t|\t|\t|" << endl;*/ 
		cout << "\t________________________________________________________\n" << endl;
		cout << "\n Enter Your Choice :";
		cin >> mainChoice;
		system("CLS");
		Customers a2;
		Cabs a3;
		Bookings a4;
		Charges a5;
		if (mainChoice == 1)
		{
			cout << endl<<endl;
			cout << "\t----- Customers -----" << endl;
			cout << endl;

			cout << "\t1: Enter new customers" << endl;
			cout << "\t2: See old customers" << endl;
			cout << "\t\n Enter Choice :" << endl;
			cin >> inChoice;
			system("CLS");
			if (inChoice == 1)
			{
				a2.getDetails();

			}
			else if (inChoice == 2)
			{
				a2.showDetails();
			}
			else
			{
				cout << "Invalid Input ! Redirecting to Previous Menu \n Please Wait !" << endl;
				Sleep(600);
				system("CLS");
				menu();
			}
			cout << "\n Press 1 to redirect to Main menu : \t" << endl;

			cin >> gotoMenu;
			system("CLS");
			if (gotoMenu == 1) {
				menu();
			}
			else {
				menu();
			}
		}
		else if (mainChoice == 2)
		{
			a3.cabDetails();
		}
		else if (mainChoice == 3)
		{
			cout << "--> Book a luxury Hotel using the system <--"<<endl;
			a4.Hotels();
		}
		else if (mainChoice == 4)
		{
			cout << "--> Get your receipt <--" << endl;
			a5.printBill();
			cout << "Your receipt is generated you can get it from file path"<<endl;
			cout << "To display the receipt in the screen , Enter 1: or Enter another key to back main menu:";
			cin >> gotoMenu;
			if (gotoMenu == 1) {
				system("CLS");
				a5.showBill();
				cout << "\n Press 1 to redirect main menu :";
				cin >> gotoMenu;
				system("CLS");
				if (gotoMenu == 1)
				{
					menu();
				}
				else {
					menu();
				}

			}
			else {
				system("CLS");
				menu();
			}
		}
		else if (mainChoice == 5) {
			cout << "---THANKS FOR VISITING ---";
			Sleep(600);
			system("CLS");
			menu();

		}
		else
		{
			cout << "Invalid choice ! Redirecting .... \n Please Wait !" << endl;
			Sleep(600);
			system("CLS");
			menu();
		}
	}

	int main()
	{
		ManageMenu startObject;
		
		return 0;
	}

