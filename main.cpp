#include <iostream>
#include "main.h"

int main(void)
{
    Meteo *meteo = new Meteo(generate_temp(), generate_hyg(), generate_press());

    menu(meteo);
    delete meteo;

    return (0);
}
