#include "main.h"

array<int, 3> prev_arr(vector<int> v)
{
    auto itr = v.end();
    array<int, 3> arr = {
        *(itr - 1),
        *(itr - 2),
        *(itr - 3)};
    return (arr);
}
array<int, 3> stat_arr(vector<int> v)
{
    array<int, 3> arr = {
        *max_element(v.begin(), v.end()),
        *min_element(v.begin(), v.end()),
        static_cast<int>(static_cast<double>(accumulate(v.begin(), v.end(), 0.0)) / v.size())};
    return (arr);
}

void showCond(Meteo *meteo)
{
    MeteoObserver *today_m = new MeteoObserver();
    array<int, 3> temp, hyg, press;
    char choice;

    today_m->attach(meteo);
    temp = prev_arr(meteo->get_temp());
    hyg = prev_arr(meteo->get_hyg());
    press = prev_arr(meteo->get_press());
    // system("cls");
    // system("clear");
    dashe(50);
    space(38);
    cout << "Condition Actuelle" << endl
         << endl;
    cout << "Hemidite"
         << "\t"
         << "==" << setw(8) << hyg[2] << " %" << endl;
    cout << "Pression"
         << "\t"
         << "==" << setw(8) << press[2] << " hpa" << endl;
    wcout << "Temperature"
         << "\t"
         << "==" << setw(8) << temp[2] << L" °C";
//         << "==" << setw(8) << temp[2] << " \u00B0C";
    dashe(50);
    choice = sub_menu();
    switch (choice)
    {
    case '1':
        menu(meteo);
        break;
    default:
        today_m->getMeteo();
        showCond(meteo);
    }
    today_m->detach(meteo);
    delete today_m;
}

void showPrevision(Meteo *meteo)
{
    MeteoObserver *meteo_m = new MeteoObserver();
    array<int, 3> temp, hyg, press;
    char choice;

    meteo_m->attach(meteo);
    temp = prev_arr(meteo->get_temp());
    hyg = prev_arr(meteo->get_hyg());
    press = prev_arr(meteo->get_press());
    //
    // system("cls");
    // system("clear");
    dashe(80);
    space(40);
    cout << "Prevision" << endl
         << endl;
    dash(24);
    cout << "Today"
         << "\t\t"
         << "Tomorow"
         << "\t\t"
         << "after Tomorow" << setw(11) << "-" << endl
         << endl;
    cout << "Hemidite"
         << "\t"
         << "==";
    wcout << setw(8) << hyg[2] << " %" << setw(16) << hyg[1] << " %" << setw(16) << hyg[0] << " %" << endl;
    cout << "Pression"
         << "\t"
         << "==";
    wcout << setw(8) << press[2] << " hpa" << setw(14) << press[1] << " hpa" << setw(14) << press[0] << " hpa" << endl;
    wcout << "Temperature"
          << "\t"
          << "==";
    wcout << setw(8) << temp[2] << L" °C";
    wcout << setw(15) << temp[1] << L" °C";
    wcout << setw(15) << temp[0] << L" °C";
    dashe(80);
    //
    choice = sub_menu();
    switch (choice)
    {
    case '1':
        menu(meteo);
        break;
    default:
        meteo_m->getMeteo();
        showPrevision(meteo);
    }
    meteo_m->detach(meteo);
    delete meteo_m;
}
void showStatistics(Meteo *meteo)
{
    MeteoObserver *meteo_m = new MeteoObserver();
    array<int, 3> temp, hyg, press;
    char choice;

    meteo_m->attach(meteo);
    temp = stat_arr(meteo->get_temp());
    hyg = stat_arr(meteo->get_hyg());
    press = stat_arr(meteo->get_press());
    dash(24);
    cout << "Max"
         << "\t\t"
         << "Min"
         << "\t\t"
         << "Avg" << setw(11) << "-" << endl
         << endl;
    cout << "Hemidite"
         << "\t"
         << "==";
    wcout << setw(8) << hyg[0] << " %" << setw(16) << hyg[1] << " %" << setw(16) << hyg[2] << " %" << endl;
    cout << "Pression"
         << "\t"
         << "==";
    wcout << setw(8) << press[0] << " hpa" << setw(14) << press[1] << " hpa" << setw(14) << press[2] << " hpa" << endl;
    wcout << "Temperature"
          << "\t"
          << "==";
    wcout << setw(8) << temp[2] << L" °C";
    wcout << setw(15) << temp[1] << L" °C";
    wcout << setw(15) << temp[0] << L" °C";
    dashe(80);
    //
    choice = sub_menu();
    switch (choice)
    {
    case '1':
        menu(meteo);
        break;
    default:
        meteo_m->getMeteo();
        showStatistics(meteo);
    }
    meteo_m->detach(meteo);
    delete meteo_m;
}
