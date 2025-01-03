#ifndef PROCESO_H
#define PROCESO_H
#include <iostream>

class Proceso
{
private:
    int PID;        // Identificador del proceso
    int PPID;       // Identificador del proceso padre
    int inicio;     // Inicio del proceso (en minutos desde las 00:00)
    int tiempoVida; // Tiempo de vida (en minutos)
    int prioridad;  // Prioridad del proceso (0-9)
    int nucleo;     // Núcleo asignado para la ejecución
    int tiempoEjecucion; // Tiempo que el proceso lleva en ejecución

public:
    Proceso(int pid, int ppid, int ini, int vida, int pri, int nuc);
    Proceso();
    ~Proceso();

    void mostrarInformacion();
    void reducirTiempoInicio();
    void reducirTiempoVida();
    void aumentarTiempoEjecucion();

    // Getters
    int getPID();
    int getPPID();
    int getInicio();
    int getTiempoVida();
    int getPrioridad();
    int getNucleo();
    int getTiempoEjecucion();

    // Setters
    void setPID(int PID);
    void setPPID(int PPID);
    void setInicio(int Ini);
    void setTiempoVida(int TiempoVida);
    void setPrioridad(int Prioridad);
    void setNucleo(int Nucle);
    void setTiempoEjecucion(int TiempoEjecucion);
};

#endif // PROCESO_H