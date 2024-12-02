// main.cpp
#include <iostream>
#include "Sistema.h"

using namespace std;

void mostrarMenu(int minutos)
{
	int horas = minutos / 60 % 24;
	int min = minutos % 60;
	/* * " << (horas >= 10 ? "" : "0") << horas << ":" << (min >= 10 ? "" : "0") << min << " *  */

	cout << R"(
+............................................................................................................................................+	
|                                        ____  _             _  __ _               _                                                         |
|                                       |  _ \| | __ _ _ __ (_)/ _(_) ___ __ _  __| | ___  _ __                                              |
|                                       | |_) | |/ _` | '_ \| | |_| |/ __/ _` |/ _` |/ _ \| '__|                                             |
|                                       |  __/| | (_| | | | | |  _| | (_| (_| | (_| | (_) | |                                                |
|                                       |_|   |_|\__,_|_| |_|_|_| |_|\___\__,_|\__,_|\___/|_|                                                |
+............................................................................................................................................+
.                                                                                                                                            .
.                                 88888888888888                                                                                             .
.                                d88888888888888p                                 +----------------------------------------------------+     .
.                             qpp8888888888888888p                                |                   System Menu                      |     .
.                         ppp8888888888888888888888ppppppp....ppp                 +----------------------------------------------------+     .
.                      qp8888888888888888888888888888888888888888888qq            | 1.  Crear la pila de procesos                      |     .
.                     p8888'   q88888b   88888pp888888p   ''888pp     ''b··       | 2.  Mostrar procesos en la pila                    |     .
.                   q888b     q88888p      '8888p 88888p       '88p               | 3.  Borrar pila de procesos                        |     .
.                  p888       88888'8p       8888p '8888p         88qp            | 4.  Simular el paso de N minutos                   |     .
.               pp888b       q8888   8p       8888p  8888pp           ''8b        | 5.  Mostrar datos lista nucelos                    |     .
.          pppp88888       pp8888p   8p      q88888p   8888pp                     | 6.  Consultar nucleos con mas y menos procesos     |     .
.   pdd8888''   p88      p8888888p    8      888888p     888888pppp               | 7.  Consultar numero de nucleos operativos         |     .
. '           p8       q8888  888p    8     q88b 88b       88888888888ppp         | 8.  Annadir un proceso al arbol de busqueda        |     .
.           p'        q888    d888p        q88b  88b        88p        '888q      | 9.  Mostrar datos del arbol (por prioridad)        |     .
.          d         q88b      d88p       q888p  88         888p            8q    | 10. Mostrar procesos con la prioridad dada         |     .
.                    88b        d88p     p8' 8b  88         8p'88p            '   | 11. Mostrar ordenes de prioridad que               |     .
.                   p8b        p8888p   d8   8   88         dp   8bp              |     han tenido un proceso ejecutado                |     .
.                 qp8        q88' 88p  db   q8   88          8p   '8p             | 12. Nivel de prioridad con mayor y menor numero    |     .
.               pd8'        q8     88  8   q8    88           8     b             |     de procesos                                    |     .
.            pd8'          q8      88p     8      8p          d     8             | 13. Tiempo promedio de procesos con una prioridad  |     .
.          '               8b      d8p     b      88          d     d             | 14. Tiempo promedio de cada nivel en preorden      |     .
.                          8       888bp           8p                             | 15. Ejecutar todos los procesos                    |     .
.                         qb       8b  8            8p                            | 0.  Salir                                          |     .
.                         '       db   8             '8                           +----------------------------------------------------+     .
.                                qb    8               'q                                                                                    .
.                               qb     dp                '.                                                                                  .
.                               '       '                                                           ...........                              . )"
		 << endl;
	cout << ".                                                                                                   |  " << (horas >= 10 ? "" : "0") << horas << ":" << (min >= 10 ? "" : "0") << min << "  |                              ." << endl;
	cout << ".                                                                                                   ...........                              . " << endl;
	cout << "+............................................................................................................................................+" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
}

int main()
{
	Sistema sistema;
	int opcion;

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
			sistema.minMaxPrioridad();
			break;
		case 13:
			cout << "Introduce la prioridad: ";
			cin >> prioridad;
			sistema.mediaPrioridad(prioridad);
			break;
		case 14:
			sistema.mostrarMediaPreorden();
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

/*
								88888888888888
								88888888888888
							   d88888888888888p
							qpp8888888888888888p
						ppp8888888888888888888888ppppppp....ppp
					 qp8888888888888888888888888888888888888888888qq
					p8888'   q88888b   88888pp888888p   ''888pp     ''b··
				  q888b     q88888p      '8888p 88888p       '88p
				 p888       88888'8p       8888p '8888p         88qp
			  pp888b       q8888   8p       8888p  8888pp           ''8b
		 pppp88888       pp8888p   8p      q88888p   8888pp
  pdd8888''   p88      p8888888p    8      888888p     888888pppp
'           p8       q8888  888p    8     q88b 88b       88888888888ppp
		  p'        q888    d888p        q88b  88b        88p        '888q
		 d         q88b      d88p       q888p  88         888p            8q
				   88b        d88p     p8' 8b  88         8p'88p            '
				  p8b        p8888p   d8   8   88         dp   8bp
				qp8        q88' 88p  db   q8   88          8p   '8p
			  pd8'        q8     88  8   q8    88           8     b
		   pd8'          q8      88p     8      8p          d     8
		 '               8b      d8p     b      88          d     d
						 8       888bp           8p
						qb       8b  8            8p
						'       db   8             '8
							   qb    8               'q
							  qb     dp                '.
							  '       '
								 q@@@@@@@@@@@@@
								 q@@@@@@@@@@@@@
								 Q@@@@@@@@@@@@@
								 j@@@@@@@@@@@@@
								 @@@@@@@@@@@@@@
								 @@@@@@@@@@@@@@
								g@@@@@@@@@@@@@@@
							__g@@@@@@@@@@@@@@@@@g_
						_gg@@@@@@@@@@@@@@@@@@@@@@@gggggg__________
					  _g@@@@@MMQ@@@@@@M@@@@@@M@@@@@@@@@@@@@@@@MMMMMwg_
					_g@@@M"   g@@@@@F   M@@@@@_7@@@@@g   ""MM@@g_    "7*~~
				   j@@@F     q@@@@@@      "&@@@g_M@@@@g       "%@g_
				 _g@@M       @@@@@"@@       %@@@@_"%@@@g_        7MWg_
			  _gg@@@`       g@@@@  "@@       @@@@@  J@@@@g           ""*rr
		__ggg@@MM@@`     _g@@@@@@   4@      q@@@@@p   %@@@@g_
  _,wmMMM"""` _g@F     _g@@@M@@@@    @      g@@M@@@     "@@@@@ggg__
r"          _gM`      _@@@M` @@@@    &     g@@h @@@       %@@*MMM&&@@ggg_
		   yC        q@@M    "@@@p    `   g@@D  @@h        @@g        "7MNg_
		  7         _@@P      "@@@       g@M@p  @@         @&@g_           *q_
				   _@@h        Q@@@     g@` @D  @@         @p"%@g_           "
				  _g@`       _g@@@@p   gM   @   @@         J@  "M@_
				 _@M`       g@M` &@@  jP   j@   @@          &p   "@p
			  _g@M`        g@`    @@  F   _@    4@_          %    "@
		   _wM*`          q@      j@H     @      @@          d     ]
		  `               @h      j@g_    P      3@          d     d
						  @       @@M&_   U       &g
						 QU      _@U "@            Mg
						 /       gP   @             "N_
								jP    &               "w_
							   qP     "p                "v
							   ]       '
a
a


	   ======
	 ==========
  ++++===========
 ++===========+===+
 ++==++=====+++==++
 +++===++++++++++++
  ++++***+#*++++++
	++++******+
		****#
		****
		****

                                                                    
                           **+*++****                               
                        ***+++++*++***+**       *+                  
              +  **** *##*++**++++++++*** =+=+++++=+                
            **++*+++*+*####*++++****+***##*+*+++==**++   +          
            *******+***##%%##*##*###**%%##*+++++=++*** +=++=+       
         ** **#######%%#%%%%%#%%%%#%%#%%###+**+++*+***+++++*=       
         ****+++=++++++*#%%%%%#****###%#%####*+*****+####**+        
        ###****++++++****%#%#****==++++++#%%#%##*##%%##+++          
        **#*#**++++*+**###%###*#*++++***+*###%%%#%%##**+++*+++      
         ###*##########*****#%#%#*#**##***#%%@%%#%%#**++++*+***+    
    *****++*+++++++*+*###*+#%%%%%%%%%%%%#%%%%%%%%%%##++++*++*#*#**  
    *##+++*++++++**+*#*##%%%%###**++*++++*++***#%#%#%#**######%%##  
  ***+*******=++**####%%%%%%##+=+++++++*=+++=**#*#%######%##%##%**  
  *###*%****#**####%#%%%%%#%***#***#+*++****+++**+#####@@%%%%#      
  #*#%#####**##*#%%%%#**#%###+**++*###%*#*#**+##**#%#%@%%%##*+***   
 **%%%%%%%%%%%%%%%%%##**++*#%####*#%%%%%##*###%####%%%%####****#*** 
   **#%#%%%%%%%%**++#%#%##%%%%%*#*%@%%%%%#%##%%%#%%%@%%%%###%%##*   
        ######**++###%%%%%%%#%@%%%%%@%%%%%%%%%#%%#%%%%%%%%%####     
          *  *##**#%##%##%#%%%%%%@%%%@%%%%%%%#*##%%#### ####        
                     %##**++**%%%@@%%%@%%% *#  ***####              
                               %%%%%%%%%%                           
                               #%%%%%%%                             
                               #%%#####                             
                               #%%#####                             
                              #%%%#####                             
                             ##%%%#######                           
                         ##%#%%%@%#%%%%##%%%%%                      
                                 @%%%     %                         

*/