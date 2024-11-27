// main.cpp
#include <iostream>
#include "Sistema.h"

using namespace std;

void mostrarMenu(int minutos)
{
	int horas = minutos / 60 % 24;
	int min = minutos % 60;

	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << " +----------------------------------------------------------------+" << endl;
	cout << "|                    +-------------------+                       |" << endl;
	cout << "|                    |     * " << (horas >= 10 ? "" : "0") << horas << ":" << (min >= 10 ? "" : "0") << min << " *     |                       |" << endl;
	cout << "|                    +-------------------+                       |" << endl;
	cout << "|                                                                |" << endl;
	cout << "|     +----------------------------------------------------+     |" << endl;
	cout << "|     |                   SYSTEM MENU                      |     |" << endl;
	cout << "|     +----------------------------------------------------+     |" << endl;
	cout << "|     |  1.  Crear la pila de procesos                     |     |" << endl;
	cout << "|     |  2.  Mostrar procesos en la pila                   |     |" << endl;
	cout << "|     |  3.  Borrar pila de procesos                       |     |" << endl;
	cout << "|     |  4.  Simular el paso de N minutos                  |     |" << endl;
	cout << "|     |  5.  Mostrar datos lista nucleos                   |     |" << endl;
	cout << "|     |  6.  Consultar nucleos con mas y menos procesos    |     |" << endl;
	cout << "|     |  7.  Consultar numero de nucleos operativos        |     |" << endl;
	cout << "|     |  8.  Añadir un proceso al árbol de búsqueda        |     |" << endl;
	cout << "|     |  9.  Mostrar datos del árbol (por priodidad)       |     |" << endl;
	cout << "|     |  10. Mostrar procesos con la prioridad dada        |     |" << endl;
	cout << "|     |  11. Mostrar órdenes de prioridad que han tenido   |     |" << endl;
	cout << "|     |      un proceso ejecutado                          |     |" << endl;
	cout << "|     |  12. Nivel de priodidad con mayor y menor número   |     |" << endl;
	cout << "|     |      de procesos                                   |     |" << endl;
	cout << "|     |  13. Tiempo promedio de procesos con una           |     |" << endl;
	cout << "|     |      prioridad                                     |     |" << endl;
	cout << "|     |  14. Tiempo promedio de cada nivel en              |     |" << endl;
	cout << "|     |      preorden                                      |     |" << endl;
	cout << "|     |  15. Ejecutar todos los procesos                   |     |" << endl;
	cout << "|     |  0.  Salir                                         |     |" << endl;
	cout << "|     +----------------------------------------------------+     |" << endl;
	cout << "|          +------------------------------------------+          |" << endl;
	cout << "|          |  Selecciona una opcion y presiona Enter  |          |" << endl;
	cout << "|          +------------------------------------------+          |" << endl;
	cout << "+----------------------------------------------------------------+" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
}

int main()
{
	Sistema sistema;
	int opcion;

	cout << R"(
 _______  ___      _______  __    _  ___   _______  ___   _______  _______  ______   _______  _______  
|       ||   |    |   _   ||  |  | ||   | |       ||   | |   ____||   _   ||      | |       ||    _  |  
|    _  ||   |    |  |_|  ||   |_| ||   | |    ___||   | |  |     |  |_|  ||  _    ||   _   ||   | | |  
|   |_| ||   |    |       ||       ||   | |   |___ |   | |  |     |       || | |   ||  | |  ||   |_| | 
|    ___||   |___ |       ||  _    ||   | |    ___||   | |  |     |       || |_|   ||  |_|  ||    __  |
|   |    |       ||   _   || | |   ||   | |   |    |   | |  |____ |   _   ||       ||       ||   |  | |
|___|    |_______||__| |__||_|  |__||___| |___|    |___| |_______||__| |__||______| |_______||___|  |_|

    )" << endl;

	cout << "\n====================================================================" << endl;
	cout << "ADVERTENCIA: Ya se han creado 10 procesos en la pila de procesos." << endl;
	cout << "Los procesos que se crean son siempre los mismos." << endl;
	cout << "Crear la pila de procesos añadirá los mismos 10 procesos a la pila."
		 << endl;
	cout << "====================================================================\n"
		 << endl;

	do
	{
		mostrarMenu(sistema.getMinutos());
		cout << "       +------------------------------------------+          " << endl;
		cout << "                Selecciona una opcion: ";
		cin >> opcion;
		cout << "       +------------------------------------------+          " << endl;
		cout << "=================================================================================================================================\n"
			 << endl;

		int n;
		int PID, PPID, inicio, tiempoVida, prioridad, nucleo, tiempoEjecucion;

		switch (opcion)
		{
		case 1:
			sistema.crearProcesos();
			break;
		case 2:
			sistema.mostrarPila();
			break;
		case 3:
			sistema.borrarPila();
			break;
		case 4:
			cout << "Introduce N minutos: ";
			cin >> n;
			sistema.simularMinutos(n);
			break;
		case 5:
			sistema.mostrarEjecutando();
			break;
		case 6:
			sistema.mostrarMasMenos();
			break;
		case 7:
			sistema.mostrarNumNucleos();
			break;
		case 8:
			cout << "Introduce el PID: " << endl;
			cin >> PID;
			cout << "\nIntroduce el PPID: " << endl;
			cin >> PPID;
			cout << "\nIntroduce el tiempo hasta inicio: " << endl;
			cin >> inicio;
			cout << "\nIntroduce el tiempo de vida: " << endl;
			cin >> tiempoVida;
			cout << "\nIntroduce la prioridad: " << endl;
			cin >> prioridad;
			cout << "\nIntroduce el nucleo: " << endl;
			cin >> nucleo;
			cout << "\nIntroduce el tiempo de ejecucion: " << endl;
			cin >> tiempoEjecucion;

			sistema.insertarProceso(PID, PPID, inicio, tiempoVida, prioridad, nucleo, tiempoEjecucion);

			break;
		case 9:
			sistema.mostrarArbolInorden();
			break;
		case 10:
			cout << "Introduce la prioridad: ";
			cin >> prioridad;
			sistema.mostrarProcesosPrioridad(prioridad);
			break;
		case 11:
			sistema.mostrarNiveles();
			break;
		case 12:

			break;
		case 13:

			break;
		case 14:
			break;
		case 15:
			sistema.ejecutarProcesos();
			break;
		case 0:
			cout << "Saliendo del programa.\n";
			break;
		default:
			cout << "Opción no válida. Inténtalo de nuevo.\n";
		}
		cout << "\n=================================================================================================================================" << endl;
	} while (opcion != 0);

	return 0;
}
