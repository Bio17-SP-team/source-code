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
	string Name;
	int Phone = 0;
	string purchasedProducts;
	Date dateOfLastBill;
	int its_value = 0;
	int totalPriceOfBoughtProductsPerWeek = 0;
};

Customer new_customer[100];

struct Supplier {
	idsup IDsup;
	string Name;
	int Phone = 0;
	string suppliedMedicalProduct;
};

Supplier new_supplier[100];

struct MedicalSupply {
    idmed IDmed;
    string Name;
    Date expiryDate;
    string SupplierName;
    int Stock = 0;
    int Price = 0;
};

MedicalSupply new_medicalsupply[100];

void add_customer() {
    ofstream cf;
    cf.open("customer.txt", ios::app);
	new_customer[custcounter - 1].IDcust.no = custcounter;
	cout << new_customer[custcounter - 1].IDcust.U << new_customer[custcounter - 1].IDcust.no << endl;
    cf << new_customer[custcounter - 1].IDcust.U << new_customer[custcounter - 1].IDcust.no << endl;
	cout << "Enter customer name : ";
	getline (cin, new_customer[custcounter - 1].Name);
    cf << new_customer[custcounter - 1].Name << endl;
	cout << "Enter phone number : ";
	cin >> new_customer[custcounter - 1].Phone;
	cin.ignore();
    cf << new_customer[custcounter - 1].Phone << endl;
	cout << "Enter purchase products : ";
	getline (cin, new_customer[custcounter - 1].purchasedProducts);
    cf << new_customer[custcounter - 1].purchasedProducts << endl;
	cout << "Enter date of last bill : ";
	cin >> new_customer[custcounter - 1].dateOfLastBill.Day >> new_customer[custcounter - 1].dateOfLastBill.Month >> new_customer[custcounter - 1].dateOfLastBill.Year;
    cf << new_customer[custcounter - 1].dateOfLastBill.Day << " " << new_customer[custcounter - 1].dateOfLastBill.Month << " " << new_customer[custcounter - 1].dateOfLastBill.Year << endl;
	cout << "Enter its value : ";
	cin >> new_customer[custcounter - 1].its_value;
    cf << new_customer[custcounter - 1].its_value << endl;
	cout << "Enter total price of bought products/week : ";
	cin >> new_customer[custcounter - 1].totalPriceOfBoughtProductsPerWeek;
    cf << new_customer[custcounter - 1].totalPriceOfBoughtProductsPerWeek << endl;
    cf.close();
    cout << endl;
	custcounter++;
}

void add_supplier() {
    ofstream cf;
    cf.open("supplier.txt", ios::app);
    new_supplier[supcounter - 1].IDsup.no = supcounter;
    cf << new_supplier[supcounter - 1].IDsup.U << new_supplier[supcounter - 1].IDsup.no << endl;
    cout << new_supplier[supcounter - 1].IDsup.U << new_supplier[supcounter - 1].IDsup.no << endl;
    cout << "Enter supplier name : ";
    getline(cin, new_supplier[supcounter - 1].Name);
    cf << new_supplier[supcounter - 1].Name << endl;
    cout << "Enter phone number : ";
    cin >> new_supplier[supcounter - 1].Phone;
    cf << new_supplier[supcounter - 1].Phone << endl;
    cin.ignore();
    cout << "Enter supplied products : ";
    getline(cin, new_supplier[supcounter - 1].suppliedMedicalProduct);
    cf << new_supplier[supcounter - 1].suppliedMedicalProduct << endl;
    cout << endl;
    supcounter++;
}

void add_medicalsupply() {
    ofstream cf;
    cf.open("medical_supply.txt", ios::app);
    new_medicalsupply[medcounter - 1].IDmed.no = medcounter;
    cf << new_medicalsupply[medcounter - 1].IDmed.U << new_medicalsupply[medcounter - 1].IDmed.no << endl;
    cout << new_medicalsupply[medcounter - 1].IDmed.U << new_medicalsupply[medcounter - 1].IDmed.no << endl;
    cout << "Enter medical supply name : ";
    getline(cin, new_medicalsupply[medcounter - 1].Name);
    cf << new_medicalsupply[medcounter - 1].Name << endl;
    cout << "Enter date of expiry : ";
    cin >> new_medicalsupply[medcounter - 1].expiryDate.Day >> new_medicalsupply[medcounter - 1].expiryDate.Month >> new_medicalsupply[medcounter - 1].expiryDate.Year;
    cf << new_medicalsupply[medcounter - 1].expiryDate.Day << new_medicalsupply[medcounter - 1].expiryDate.Month << new_medicalsupply[medcounter - 1].expiryDate.Year << endl;
    cin.ignore();
    cout << "Enter name of supplier: ";
    getline(cin, new_medicalsupply[medcounter - 1].SupplierName);
    cf << new_medicalsupply[medcounter - 1].SupplierName << endl;
    cout << "Enter Stock number: ";
    cin >> new_medicalsupply[medcounter].Stock;
    cf << new_medicalsupply[medcounter].Stock << endl;
    cout << "Enter price: ";
    cin >> new_medicalsupply[medcounter].Price;
    cf << new_medicalsupply[medcounter].Price << endl;
    cout << endl;
    medcounter++;
}

void read_file(Customer customer[]) {
        int count = 0, array_count = 0;
        ifstream fs;
        string line;
        fs.open("customer.txt");
        while (getline(fs, line))
        {
            if (count == 0)
                customer[array_count].IDcust.no = std::stoi(line);
            else if (count == 1)
                customer[array_count].Name = line;
            else if (count == 2)
                customer[array_count].Phone = std::stoi(line);
            else if (count == 3)
                customer[array_count].purchasedProducts = line;
            else if (count == 4)
                customer[array_count].dateOfLastBill.Day = std::stoi(line);
            else if (count == 5)
                customer[array_count].its_value = std::stoi(line);
            else if (count == 6)
                customer[array_count].totalPriceOfBoughtProductsPerWeek = std::stoi(line);
            count++;
            if (count > 6)
            {
                count = 0;
                array_count++;
            }

        }
        fs.close();
    
}

void update_customer() {
    cout << "Enter phone number: ";
    int temp,temp2 = 0; bool flag = false;
    cin >> temp;
    for (int i = 0; i < 100; i++) {
        if (temp == new_customer[i].Phone) {
            flag = true;
            temp2 = i;
            break;
        }
    }
    if (flag == false) {
        cout << "This customer is not found!" << endl;
    }
    else {
        cout << new_customer[temp2].Name;
    }
}

void mainmenu() {
    cout << "\t\t\t\t\tWelcome\n\n";
    cout << "\t\t\t\t  Bio*17 pharma store\n";

    cout << "\t\t\t*********************************************\n";

    cout << "\n\tFor customers menu press C ";
    cout << "\tFor products menu press M";
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
            add_customer();
        }
        else if (character2 == 'U' || character2 == 'u') {
            update_customer();
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
            add_medicalsupply();
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
            add_supplier();
        }
        else if (character2 == 'T' || character2 == 't') {
            cout << "\tupdated\n";
        }
    }


    else {
        cout << "INVALIDE CHOICE,PLEASE TRY AGAIN\n";
    }
}

void main() {
    Customer custom[100];
    mainmenu();
	
}


