///////////////////////////////////////////////////////
//                  memcount.hpp                     //
// Por Ginés G.M., basado en el código de la función //
// SafeExec, por Jose Paulo Leal.        25/1/2008   //
//---------------------------------------------------//
// Esta librería contiene dos funciones para obtener //
// la memoria total usada en un programa, haciendo   //
// uso de la información ofrecida por el sistema ope-//
// rativo (por ello, es incompatible con Windows).   //
///////////////////////////////////////////////////////


#ifndef _MEMORY_COUNT
#define _MEMORY_COUNT

int mem_total (void);
// Devuelve la cantidad total de memoria usada por el programa
// en el instante en el que se realiza la llamada.
// El valor viene dado en Kbytes (1024 bytes).

int mem_total (int &data, int &stack);
// Igual que la función anterior. Y además almacena en la
// variable data la memoria de datos (memoria estática más
// dinámica), y en stack la memoria de pila, ambas en Kbytes.

#endif
