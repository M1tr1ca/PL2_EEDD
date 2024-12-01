// main.cpp
#include <iostream>
#include "Sistema.h"

using namespace std;

void mostrarMenu(int minutos)
{
	int horas = minutos / 60 % 24;
	int min = minutos % 60;
	/* * " << (horas >= 10 ? "" : "0") << horas << ":" << (min >= 10 ? "" : "0") << min << " *  */

	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	
	cout << R"(
+............................................................................................................................................+	
|                                        ____  _             _  __ _               _                                                         |
|                                       |  _ \| | __ _ _ __ (_)/ _(_) ___ __ _  __| | ___  _ __                                              |
|                                       | |_) | |/ _` | '_ \| | |_| |/ __/ _` |/ _` |/ _ \| '__|                                             |
|                                       |  __/| | (_| | | | | |  _| | (_| (_| | (_| | (_) | |                                                |
|                                       |_|   |_|\__,_|_| |_|_|_| |_|\___\__,_|\__,_|\___/|_|                                                |
+............................................................................................................................................+
.                                                                                                                                            .
.                        ==--===+++* ++                                                                                                      .
.                  *++ +**=-----=--==+-===-                                   +----------------------------------------------------+         .
.            +=-=+==+=+#**====-=--=-==**=--------=-                           |                   System Menu                      |         .
.           *+==----==*%%#+====+**+**#*+-------===+-----                      +----------------------------------------------------+         .
.          +*****++++*#%@@@@%%@@@@%#%@@%*=+=----=++=------                    | 1.  Crear la pila de procesos                      |         .
.         *++++===+==+=*%@@@@#%%%@@@%@@%#*++=+==+==***++==                    | 2.  Mostrar procesos en la pila                    |         .
.        %%#+===------==*%@@+===-------#%%#%#*+*%@%#*-==                      | 3.  Borrar pila de procesos                        |         .
.        #**+*+=--====+*%%%*+-*+----==--*%@@@%%@@%*+=----=-=                  | 4.  Simular el paso de N minutos                   |         .
.         *##**######%%+=*++@#%%*#++##*+#%@@@@@@%*==-----++++                 | 5.  Mostrar datos lista nucelos                    |         .
.    ***+=--=----==--=#@@##%@@@@@@@@@@@@@%%@@@@@%#*=--===**##*                | 6.  Consultar nucleos con mas y menos procesos     |         .
.    ++#=---=----=--=+#%@@@@%+=--+-=---=--+==#%%%%%#**###%@@#**               | 7.  Consultar numero de nucleos operativos         |         .
.   +*%**==---====***#@@@@@@+*--==-*--+---+---++##%@@@%%@@%%                  | 8.  Anaadir un proceso al arbol de busqueda        |         .
.   =+*%+++++*##**##%@@@@#@%*=++=+***#=*+=--===++*#%@@@@%*+++**               | 9.  Mostrar datos del arbol (por prioridad)        |         .
.  +#%@@@%@@@@@@@@@@@#*+=+*%%+*++=#%@@%*+##%%%#%%@@@@%*+*+++*+*               | 10. Mostrar procesos con la prioridad dada         |         .
.   +**%@@@@%@@@%*+=*%%%%#@@@@*#*%@@@@@@@%%@@@%@@@@@@@#*#%###+                | 11. Mostrar ordenes de prioridad que               |         .
.     +%@###%##+==+*#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%%%%                  |     han tenido un proceso ejecutado                |         .
.          **#****#%%%@@%%@@@@@@@@@@@@@@@@@#*#%%%%%%#%%##%                    | 12. Nivel de prioridad con mayor y menor numero    |         .
.               *     %##*+**@@@@@@@@@@@@@#  **####                           |     de procesos                                    |         .
.                             @@@@@@@@@                                       | 13. Tiempo promedio de procesos con una prioridad  |         .
.                             @@@@@@@                                         | 14. Tiempo promedio de cada nivel en preorden      |         .
.                             @@@@@                                           | 15. Ejecutar todos los procesos                    |         .
.                            @@@@@@@@                                         | 0.  Salir                                          |         .
.                            @@@@@@@@                                         +----------------------------------------------------+         .
.                          @@@@@@@@@@@                                                                                                       .
.                      @@@@@@@@@@@@@@@@@@@                                                          ..........                               . )" << endl;
cout<< ".                                                                                                   |  " << (horas >= 10 ? "" : "0") << horas << ":" << (min >= 10 ? "" : "0") << min << " |                               ."<<endl;
cout<<"+............................................................................................................................................+"<<endl;
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
	cout << "Crear la pila de procesos annadira los mismos 10 procesos a la pila."
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
			cout << "Introduce la prioridad: ";
			cin >> prioridad;
			sistema.mediaPrioridad(prioridad);
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
