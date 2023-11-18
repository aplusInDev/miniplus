#include "main.h"

void menu(Meteo *meteo)
{
    int choice;

    // system("cls");
    // system("clear");
    dashe(50);
    cout << "1: condition actuelle" << endl;
    cout << "2: prevision" << endl;
    cout << "3: statistique" << endl;
    cout << "0: exit" << endl;
    cout << "enter your choice : ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        showCond(meteo);
        break;
    case 2:
        showPrevision(meteo);
        break;
    case 3:
        showStatistics(meteo);
        break;
    }
}

char sub_menu()
{
    char choice;

    cout << "press 1 : return" << endl;
    cout << "any number : update" << endl;
    cout << "enter your choice : ";
    cin >> choice;
    return (choice);
}
