#include <string.h>

typedef struct{
    int Hora;   //rango horario de 00 a 23 hs
    int Minuto;
} time;

typedef struct {
    char Nombre [30];
    char Apellido [30];
    int DNI;
    int Edad;
    time Hora_ingreso;
    time Hora_atencion; //se carga cuando el paciente es atendido por el medico
    int Nivel_urgencia; //1=Urgente(ROJO). 2=Moderado(AMARILLO). 3=Leve(VERDE)
    int Atendido; //-1=Stand by 0=Falso. 1=Verdadero
} Paciente;

void Inicializar_Paciente (Paciente* P){
    strcpy(P->Nombre,"");
    strcpy(P->Apellido,"");
    P->DNI=-1;
    P->Edad=-1;
    P->Hora_ingreso.Hora=-1;
    P->Hora_ingreso.Minuto=-1;
    P->Hora_atencion.Hora=-1;
    P->Hora_atencion.Minuto=-1;
    P->Atendido=-1;
    P->Nivel_urgencia=-1;
}

void Cargar_Nombre(Paciente *P, char Nombre_paciente[]){
    strcpy(P->Nombre, Nombre_paciente);
}

void Cargar_Apellido (Paciente *P, char Apellido_paciente []){
    strcpy(P->Apellido, Apellido_paciente);
}

void Cargar_DNI(Paciente *P, int dni){
    P->DNI=dni;
}

void Cargar_Edad (Paciente *P, int years){
    P->Edad=years;
}

void Cargar_HoradeIngreso (Paciente *P, int hora, int minuto){
    (*P).Hora_ingreso.Hora=hora;  //probar
    P->Hora_ingreso.Minuto=minuto;
}

void Cargar_HoradeAtencion (Paciente *P, int hora, int minuto){
    (*P).Hora_atencion.Hora=hora;  //probar
    P->Hora_atencion.Minuto=minuto;
}

void Cargar_NiveldeUrgencia (Paciente *P, int Urgencia){
    P->Nivel_urgencia=Urgencia; //1,2 o 3.
}

void Cargar_Atendido (Paciente *P, int aten){
    P->Atendido=aten; //1=verdadero. 0=falso
}
/*
void Modificar_Edad (Paciente *P, int years){
    P->Edad=years;
}

void Modificar_NiveldeUrgencia (Paciente *P, int Urgencia){
    P->Nivel_urgencia=Urgencia; //1,2 o 3.
}

void Modificar_HoradeAtencion (Paciente *P, int hora, int minuto){
    (*P).Hora_atencion.Hora=hora;  //probar
    P->Hora_atencion.Minuto=minuto;
}

void Modificar_Atendido (Paciente *P, int aten){
    P->Atendido=aten; //1=verdadero. 0=falso
}
*/
int Mostrar_HoraIngreso (Paciente P){
    return P.Hora_ingreso.Hora;
}

int Mostrar_MinIngreso (Paciente P){
    return P.Hora_ingreso.Minuto;
}

char* Mostrar_Nombre(Paciente *P){
    return P->Nombre;
}

char* Mostrar_Apellido (Paciente *P){
    return P->Apellido;
}

int Mostrar_DNI(Paciente P){
    return P.DNI;
}

int Mostrar_Edad (Paciente P){
    return P.Edad;
}

int Mostrar_NiveldeUrgencia (Paciente P){
    return P.Nivel_urgencia; //1,2 o 3.
}

int Mostrar_HoradeAtencion (Paciente P){
    return P.Hora_atencion.Hora;
}

int Mostrar_MindeAtencion (Paciente P){
    return P.Hora_atencion.Minuto;
}

int Mostrar_Atendido (Paciente P){
    return P.Atendido; //1=verdadero. 0=falso
}
