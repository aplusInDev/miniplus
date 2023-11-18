#ifndef __MAIN_H__
#define __MAIN_H__

#include <iostream>
#include <list>
#include <iomanip>
#include <time.h>
#include <array>
#include <vector>
#include <bits/stdc++.h>
#include <fstream>

using namespace std;

// =========================
// ------ generator --------
// =========================
vector<int> generate_temp();
vector<int> generate_hyg();
vector<int> generate_press();
// =========================

/**
 * Observer - abstract class used to perform
 * the observer pattern concept
 */
class Observer
{
public:
    virtual void update(vector<int> temp, vector<int> hyg, vector<int> press) = 0;
    virtual ~Observer(){}; // virtual destructor
};

/**
 * Meteo - class inherits from Observer
 * and has update method to update the
 * weather information
 * @temp: temperature value
 * @hyg: himmidity value
 * @press: presure value
 *
 */
class Meteo : public Observer
{
private:
    vector<int> temp, hyg, press;

public:
    ~Meteo()
    {
        cout << "day destructor" << endl;
    }
    Meteo()
    {
        this->temp = {0, 0, 0};
        this->hyg = {0, 0, 0};
        this->press = {0, 0, 0};
    }
    Meteo(vector<int> t, vector<int> h, vector<int> p)
    {
        this->temp = t;
        this->hyg = h;
        this->press = p;
    }
    void set_temp(vector<int> t)
    {
        this->temp = t;
    }
    vector<int> get_temp()
    {
        return this->temp;
    }
    void set_hyg(vector<int> h)
    {
        this->hyg = h;
    }
    vector<int> get_hyg()
    {
        return this->hyg;
    }
    void set_press(vector<int> p)
    {
        this->press = p;
    }
    vector<int> get_press()
    {
        return this->press;
    }
    void update(vector<int> temp, vector<int> hyg, vector<int> press)
    {
        set_temp(temp);
        set_hyg(hyg);
        set_press(press);
    }
};

/**
 * MeteoObserver - This class has attach, detach,
 * notify methods to perform the observer pattern concept
 * @temp: temperature value
 * @hyg: himmidity value
 * @press: presure value
 *
 */
class MeteoObserver
{
private:
    vector<int> temp, hyg, press;

public:
    ~MeteoObserver()
    {
        cout << "Meteo destructor" << endl;
        // remove all observer
        for (auto observer : observerList)
        {
            delete observer;
        }
        observerList.clear();
    }
    MeteoObserver()
    {
        this->temp = {0, 0, 0};
        this->press = {0, 0, 0};
        this->hyg = {0, 0, 0};
    }
    list<Observer *> observerList;
    void attach(Observer *observer)
    {
        observerList.push_back(observer);
    }
    void detach(Observer *observer)
    {
        observerList.remove(observer);
    }
    void notify()
    {
        for (auto observer : observerList)
        {
            observer->update(this->temp, this->hyg, this->press);
        }
    }
    void set_temp(vector<int> t)
    {
        this->temp = t;
    }
    vector<int> get_temp()
    {
        return this->temp;
    }
    void set_hyg(vector<int> h)
    {
        this->hyg = h;
    }
    vector<int> get_hyg()
    {
        return this->hyg;
    }
    void set_press(vector<int> p)
    {
        this->press = p;
    }
    vector<int> get_press()
    {
        return this->press;
    }
    void getMeteo()
    {
        this->temp = generate_temp();
        this->press = generate_press();
        this->hyg = generate_hyg();
        notify();
    }
};

// =========================
// ------ tools ------------
// =========================
void showCond(Meteo *meteo);
void showPrevision(Meteo *meteo);
void showStatistics(Meteo *meteo);
void menu(Meteo *meteo);
char sub_menu();
// =========================
// ------ quick addition ---
// =========================
void dash(int x);
void dashe(int x);
void space(int x);
// =========================

#endif /*__MAIN_H__ */