#include <iostream>
#include "main.h"

int main(void)
{
	// used for uncoding char
	setlocale(LC_ALL, "");
	
    Meteo *meteo = new Meteo(generate_temp(), generate_hyg(), generate_press());

    menu(meteo);
    delete meteo;

    return (0);
}
