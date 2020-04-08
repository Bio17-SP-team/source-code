#include <iostream>
#include<cstdio> 
using namespace std;
char character;
char character2;
void mainmenu();
int main()
{
    mainmenu();
    


    system("pause");

}



void mainmenu() {
    cout << "\t\t\t\t\tWelcome\n\n";
    cout << "\t\t\t\t  Bio*17 pharma store\n";

    cout << "\t\t\t*********************************************\n";





    cout << "\n\tFor customers menu press C ";
    cout << "\tFor products menu press P";
    cout << "\tFor suppliers menu press S\n\n";

    cout << "\tENTER YOUR CHOICE: ";
    character = getchar();

    switch (character) {
    case'C':
    case 'c':
        cout << "\n Customer menu:-\n";
        cout << "\tFor new customer press N \n";
        cout << "\tFor current customer press U\n\n";
       

        break;
    case'P':
    case'p':
        cout << "\n Medical supply menu:-\n";
        cout << "\tFor new product press W\n";
        cout << "\tFor current product press E\n";
        

        break;
    case'S':
    case's':
        cout << "\n Supplier menu:-\n";
        cout << "\tFor new supplier press R\n";
        cout << "\tFor current supplier press T\n";
        

        break;
    default:
        cout << "INVALIDE CHOICE,PLEASE TRY AGAIN";
        break;
    }
}
