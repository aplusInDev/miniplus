#include "main.h"

void dashe(int x)
{
    cout << endl
         << setfill('-') << setw(x) << "-" << endl;
}
void dash(int x)
{
    cout << endl
         << setfill('-') << setw(x) << "-";
}
void space(int x)
{
    cout << setw(x) << setfill(' ');
}