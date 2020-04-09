#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
using namespace std;
int custcounter = 1, medcounter = 1, supcounter = 1;
char character, character2;
struct idcust {
	char U = 'U';
	int no = 0;
};

struct idmed {
	char U = 'M';
	int no = 0;
};

struct idsup {
	char U = 'S';
	int no = 0;
};

struct Date {
	int Day;
	int Month;
	int Year;
};

struct Customer {
	idcust IDcust;
	char Name[50] = "";
	int Phone = 0;
	char purchasedProducts[100] = "";
	Date dateOfLastBill;
	int its_value = 0;
	int totalPriceOfBoughtProductsPerWeek = 0;
};

Customer new_customer[100];

struct Supplier {
	idsup IDsup;
	char Name[50] = "";
	int Phone = 0;
	char suppliedMedicalProduct[50] = "";
};

Supplier new_supplier[100];

struct MedicalSupply {
    idmed IDmed;
    char Name[50] = "";
    Date expiryDate;
    char SupplierName[50] = "";
    int Stock = 0;
    int Price = 0;
};

MedicalSupply new_medicalsupply[100];

void mainmenu() {
    cout << "\t\t\t\t\tWelcome\n\n";
    cout << "\t\t\t\t  Bio*17 pharma store\n";

    cout << "\t\t\t*********************************************\n";

    cout << "\n\tFor customers menu press C ";
    cout << "\tFor products menu press P";
    cout << "\tFor suppliers menu press S\n\n";

    cout << "\tENTER YOUR CHOICE: ";
    cin.get(character);
    cin.ignore();
    if (character == 'c' || character == 'C') {
        cout << "\n Customer menu:-\n";
        cout << "\tFor new customer press N \n";
        cout << "\tFor current customer press U\n\n";
        cout << "\tENTER YOUR CHOICE: ";
        cin.get(character2);
        cin.ignore();
        if (character2 == 'n' || character2 == 'N') {
            cout << "\tadded\n";
        }
        else if (character2 == 'U' || character2 == 'u') {
            cout << "\tupdated\n";
        }
    }


    else if (character == 'M' || character == 'm') {
        cout << "\n Medical supply menu:-\n";
        cout << "\tFor new product press W\n";
        cout << "\tFor current product press E\n";
        cout << "\tENTER YOUR CHOICE: ";
        cin.get(character2);
        cin.ignore();
        if (character2 == 'w' || character2 == 'W') {
            cout << "\tadded\n";
        }
        else if (character2 == 'e' || character2 == 'E') {
            cout << "\tupdated\n";
        }
    }

    else if (character == 's' || character == 'S') {
        cout << "\n Supplier menu:-\n";
        cout << "\tFor new supplier press R\n";
        cout << "\tFor current supplier press T\n";
        cout << "\tENTER YOUR CHOICE: ";
        cin.get(character2);
        cin.ignore();
        if (character2 == 'r' || character2 == 'R') {
            cout << "\tadded\n";
        }
        else if (character2 == 'T' || character2 == 't') {
            cout << "\tupdated\n";
        }
    }


    else {
        cout << "INVALIDE CHOICE,PLEASE TRY AGAIN\n";
    }
}

Customer add_customer() {
	
	new_customer[custcounter - 1].IDcust.no = custcounter;
	cout << new_customer[custcounter - 1].IDcust.U << new_customer[custcounter - 1].IDcust.no << endl;
	cout << "Enter customer name : ";
	gets_s(new_customer[custcounter - 1].Name, 50);
	cout << "Enter phone number : ";
	cin >> new_customer[custcounter - 1].Phone;
	cin.ignore();
	cout << "Enter purchase products : ";
	gets_s(new_customer[custcounter - 1].purchasedProducts, 100);
	cout << "Enter date of last bill : ";
	cin >> new_customer[custcounter - 1].dateOfLastBill.Day >> new_customer[custcounter - 1].dateOfLastBill.Month >> new_customer[custcounter - 1].dateOfLastBill.Year;
	cout << "Enter its value : ";
	cin >> new_customer[custcounter - 1].its_value;
	cout << "Enter total price of bought products/week : ";
	cin >> new_customer[custcounter - 1].totalPriceOfBoughtProductsPerWeek;
    cout << endl;
	custcounter++;
	return new_customer[custcounter - 1];
}

Supplier add_supplier() {
    new_supplier[supcounter - 1].IDsup.no = supcounter;
    cout << new_supplier[supcounter - 1].IDsup.U << new_supplier[supcounter - 1].IDsup.no << endl;
    cin.ignore();
    cout << "Enter supplier name : ";
    gets_s(new_supplier[supcounter - 1].Name, 50);
    cout << "Enter phone number : ";
    cin >> new_supplier[supcounter - 1].Phone;
    cin.ignore();
    cout << "Enter supplied products : ";
    gets_s(new_supplier[supcounter - 1].suppliedMedicalProduct);
    cout << endl;
    supcounter++;
    return new_supplier[supcounter - 1];
}

MedicalSupply add_medicalsupply() {
    new_medicalsupply[medcounter - 1].IDmed.no = medcounter;
    cout << new_medicalsupply[medcounter - 1].IDmed.U << new_medicalsupply[medcounter - 1].IDmed.no << endl;
    cout << "Enter medical supply name : ";
    gets_s(new_medicalsupply[medcounter - 1].Name, 50);
    cout << "Enter date of expiry : ";
    cin >> new_medicalsupply[medcounter - 1].expiryDate.Day >> new_medicalsupply[medcounter - 1].expiryDate.Month >> new_medicalsupply[medcounter - 1].expiryDate.Year;
    cin.ignore();
    cout << "Enter name of supplier: ";
    gets_s(new_medicalsupply[medcounter - 1].SupplierName, 50);
    cout << "Enter Stock number: ";
    cin >> new_medicalsupply[medcounter].Stock;
    cout << "Enter price: ";
    cin >> new_medicalsupply[medcounter].Price;
    cout << endl;
    medcounter++;
    return new_medicalsupply[medcounter - 1];
}

void main() {
    mainmenu();
	add_customer();
    add_supplier();
    add_medicalsupply();
}



 
