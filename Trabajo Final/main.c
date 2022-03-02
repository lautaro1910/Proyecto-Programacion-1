//INICIO
//LIBRERIAS
#include "Paciente.h"
#include "Lista_Paciente.h"
#include "Lista_Prioridad.h"

//PROTOTIPOS
//Lista_Paciente
void Insertar_Pac(ListaPac *,Paciente);
void Suprimir_Pac(ListaPac *);
Paciente Mostrar_Pac(ListaPac);

//Lista_Prioridad
void Insertar_Prio(ListaPrio *,Paciente );
void suprimirL_Prio(ListaPrio *);
Paciente Mostrar_Prio(ListaPrio );

//General
int cargar_nPacientes(ListaPac *lis);                                                                                 //A EN REVISION
void ImprimirPaciente(Paciente , int);                                                                               //B Y C
void Nivel_de_Urgencia(ListaPrio *,ListaPac *);                                                                     //D
void Atendido_Por_Medico (ListaPrio *);                                                                            //E
void Mod_EDad (ListaPac *,ListaPrio *);                                                                           //F EN REVISION
void No_Atendido (ListaPrio *);                                                                                  //G
void Mostrar_list_por_Nivel (ListaPrio);                                                                        //H
void Mostrar_atendidos (ListaPrio *);                                                                          //I
int Tiempo_de_Espera(Paciente );                                                                              //j
void Espero_MasTiempo(ListaPrio ,int, int ,int );                                                          //J
void Cargar_NoAtend_enArchivo (ListaPrio );                                                                 //K
int Borrar_PacientesFinalizados (ListaPrio *);                                                             //L
void Cargar_en_ListaIngreso (ListaPac *, int*);                                                           //LL
void Mostrar_CuantosHayEnEspera(ListaPrio ,ListaPac );                                                   //N
void Mostrar_CuantosHayAntes(ListaPrio ,ListaPac );                                                     //M

//PROGRAMA
int main(){
    int i,c;
    int borrados=0,YaUsado=0;
    Paciente P;
    Inicializar_Paciente(&P);
    ListaPac pacientes;
    ListaPrio prioridad;
    inicioLPac(&pacientes);
    inicioLPrio(&prioridad);
    do{
        system("cls");                     //modificado
        system("COLOR 03");
        printf("%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219);for(c=0;c<8;c++){printf("%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219);};printf("\n");
        printf("%c%c %c%c%c %c%c                                                                     %c%c%c\n",219,219,219,219,219,219,219,219,219,219);
        printf("%c%c  %c  %c%c                                                                     %c%c%c\n",219,219,219,219,219,219,219,219);
        printf("%c%c %c %c %c%c    1) Cargar una cantidad n de pacientes                            %c%c%c\n",219,219,219,219,219,219,219,219,219);
        printf("%c%c %c%c%c %c%c    2) Cargar Paciente/s en lista de espera                          %c%c%c\n",219,219,219,219,219,219,219,219,219,219);
        printf("%c%c %c%c%c %c%c    3) Cargar Pacientes no atendidos en el archivo                   %c%c%c\n",219,219,219,219,219,219,219,219,219,219);
        printf("%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219);for(c=0;c<8;c++){printf("%c%c%c%c%c%c%c%c%c",220,220,220,220,220,220,220,220,220);};printf("\n");
        printf("%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219);for(c=0;c<8;c++){printf("%c%c%c%c%c%c%c%c%c",223,223,223,223,223,223,223,223,223);};printf("\n");
        printf("%c%c     %c%c    4) Mostrar el siguiente que debe ser atendido por la enfermera   %c%c%c\n",219,219,219,219,219,219,219);
        printf("%c%c %c%c%c%c%c%c    5) Mostrar el siguiente que debe ser atendido por el medico      %c%c%c\n",219,219,219,219,219,219,219,219,219,219,219);
        printf("%c%c    %c%c%c    6) Mostrar atendidos por nivel de urgencia                       %c%c%c\n",219,219,219,219,219,219,219,219);
        printf("%c%c %c%c%c%c%c%c    7) Mostrar todos los pacientes atendidos                         %c%c%c\n",219,219,219,219,219,219,219,219,219,219,219);
        printf("%c%c     %c%c    8) Mostrar el\\los paciente\\s que espero mas tiempo               %c%c%c\n",219,219,219,219,219,219,219);
        printf("%c%c%c%c%c%c%c%c%c    9) Cuantos pacientes hay esperando ser atendidos                 %c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219);
        printf("%c%c%c%c%c%c%c%c%c    10) Cuantos pacientes hay antes que otro                         %c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219);
        printf("%c%c %c%c%c %c%c",219,219,219,219,219,219,219);for(c=0;c<8;c++){printf("%c%c%c%c%c%c%c%c%c",220,220,220,220,220,220,220,220,220);};printf("\n");
        printf("%c%c  %c%c %c%c",219,219,219,219,219,219);for(c=0;c<8;c++){printf("%c%c%c%c%c%c%c%c%c",223,223,223,223,223,223,223,223,223);};printf("\n");
        printf("%c%c %c %c %c%c    11) Asignar nivel de urgencia                                    %c%c%c\n",219,219,219,219,219,219,219,219,219);
        printf("%c%c %c%c  %c%c    12) Atendido por el medico                                       %c%c%c\n",219,219,219,219,219,219,219,219,219);
        printf("%c%c %c%c%c %c%c    13) Se retiro antes                                              %c%c%c\n",219,219,219,219,219,219,219,219,219,219);
        printf("%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219);for(c=0;c<8;c++){printf("%c%c%c%c%c%c%c%c%c",220,220,220,220,220,220,220,220,220);};printf("\n");
        printf("%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219);for(c=0;c<8;c++){printf("%c%c%c%c%c%c%c%c%c",223,223,223,223,223,223,223,223,223);};printf("\n");
        printf("%c%c %c%c%c %c%c    14) Modificar edad                                               %c%c%c\n",219,219,219,219,219,219,219,219,219,219);
        printf("%c%c %c%c%c %c%c    15) Borrar pacientes atendidos y no atendidos                    %c%c%c\n",219,219,219,219,219,219,219,219,219,219);
        printf("%c%c %c%c%c %c%c                                                     16) Salir       %c%c%c\n",219,219,219,219,219,219,219,219,219,219);
        printf("%c%c %c%c%c %c%c                                                                     %c%c%c\n",219,219,219,219,219,219,219,219,219,219);
        printf("%c%c     %c%c                                                                     %c%c%c\n",219,219,219,219,219,219,219);
        printf("%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219);for(c=0;c<8;c++){printf("%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219);};printf("\n");
        printf("%c%c%c%c%c%c%c%c%c%c %c %c %c %c %c%c%c%c %c%c %c %c %c%c %c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,220,219,220,219,220,220,219,220,220,219,220,219,223,219,219,223,219,223,223);for(c=0;c<7;c++){printf("%c%c%c%c%c%c",223,223,223,223,223,223);};printf("\n");
        printf("%c%c%c%c%c%c%c%c%c%c %c %c %c%c%c %c%c%c%c %c%c %c %c %c%c %c%c%c  ",219,219,219,219,219,219,219,219,219,219,223,219,220,220,219,223,223,219,223,223,219,223,219,219,220,219,223,219);
        fflush(stdin);
        scanf("%d",&i);
        system("cls");
        system("COLOR 07");
    switch(i){
        case 1: //punto a
                cargar_nPacientes(&pacientes);
                break;

        case 2: //13)Punto ll
                 if (!YaUsado){
                     Cargar_en_ListaIngreso (&pacientes,&YaUsado);
                     }
                     else{
                        printf("\n\n\n\n\tYa se cargo previamente...\n\n\t");
                        system("pause");
                     }
                     break;


        case 3: //11)Punto k
                 if (!emptyLPrio(prioridad)){
                    Cargar_NoAtend_enArchivo (prioridad);
                 }
                 else{
                    printf("\n\n\n\n\n\tPrimero debe ingresar un paciente que no haya sido atendido\n\n\t");
                    system("pause");
                    system("cls");
                 }
                 break;



        case 4: // 2) Punto b
                    if (!emptyLPac(pacientes)){
                        printf("\n\n\n\n");
                        ImprimirPaciente(Mostrar_Pac(pacientes),0);
                        printf("\n\n\t");
                        system("pause");
                        system("cls");
                    }
                    else{
                        printf("\n\n\n\n\n\tNo hay ningun paciente esperando\n\n\t");
                        system("pause");
                        system("cls");
                    }
                    break;


        case 5: //3)Punto c
                    if (!emptyLPrio(prioridad)){
                        P=Mostrar_Prio(prioridad);
                        if(Mostrar_Atendido(P)==-1 && Mostrar_HoradeAtencion(P)!=24){
                            printf("\n\n\n\n");
                            ImprimirPaciente(P,1);
                            printf("\n\n\t");
                            system("pause");
                        }
                        else{
                            printf("\n\n\n\n\n\tNo hay ningun paciente esperando\n\n\t");
                            system("pause");
                        }
                    }
                    else{
                        printf("\n\n\n\n\n\tPrimero debe haber algun paciente con urgencia\n\n\t");
                        system("pause");
                    }
                    break;

        case 6: //8)Punto h
                if (!emptyLPrio(prioridad)){
                    Mostrar_list_por_Nivel (prioridad);
                }
                else{
                    printf("\n\n\n\n\n\tNingun paciente ha sido atendido con ese nivel de urgencia\n\n\t");
                    system("pause");
                    system("cls");                }
                break;


        case 7: //9)Punto i
                if (!emptyLPrio(prioridad)){
                    Mostrar_atendidos(&prioridad);
                }
                else{
                    printf("\n\n\n\n\n\tNingun paciente ha sido atendido por el momento\n\n\t");
                    system("pause");
                    system("cls");
                }
                break;


        case 8: //10)Punto j
                 if (!emptyLPrio(prioridad)){
                    resetLPrio(&prioridad);
                    printf("\n\n\n\n");
                    Espero_MasTiempo(prioridad,0,-1,1);
                    printf("\n\t");
                    system("pause");
                 }
                 else{
                    printf("\n\n\n\n\n\tNo hay pacientes todavia\n\n\t");
                    system("pause");
                    system("cls");
                 }
                 break;

        case 9: //15)Punto n
                 if (!emptyLPac(pacientes)||!emptyLPrio(prioridad)){
                    resetLPac(&pacientes);
                    resetLPrio(&prioridad);
                    Mostrar_CuantosHayEnEspera(prioridad,pacientes);
                 }
                 else{
                    printf("\n\n\n\n\n\tNo hay pacientes en espera todavia\n\n\t");
                    system("pause");
                    system("cls");
                 }
                 break;


        case 10: //14)Punto m
                 if (!emptyLPac(pacientes)||!emptyLPrio(prioridad)){
                    Mostrar_CuantosHayAntes(prioridad,pacientes);
                 }
                 else{
                    printf("\n\n\n\n\n\tNo se han encontrado pacientes\n\n\t");
                    system("pause");
                    system("cls");
                 }
                 break;


        case 11: //4)Punto d
                if (!emptyLPac(pacientes)){
                    Nivel_de_Urgencia(&prioridad,&pacientes);
                }
                else{
                    printf("\n\n\n\n\n\tNo hay ningun paciente en espera\n\n\t");
                    system("pause");
                    system("cls");
                }
                break;

        case 12: //5)Punto e
                if (!emptyLPrio(prioridad)){
                    P=Mostrar_Prio(prioridad);
                        if (Mostrar_Atendido(P)==-1){
                            Atendido_Por_Medico(&prioridad);
                             printf("\n\n\n\n\tSe ha atendido al paciente correctamente\n");
                            printf("\n\n\t");
                            system("pause");
                        }
                        else{
                            printf("\n\n\n\n\n\tTodos los pacientes de urgencias han sido atendidos\n\n\t");
                            system("pause");
                        }
                    }
                else{
                    printf("\n\n\n\n\n\tPrimero debe haber algun paciente con urgencia\n\n\t");
                    system("pause");
                    system("cls");
                }
                break;

        case 13:   //7)Punto g
                if (!emptyLPrio(prioridad)){
                    No_Atendido(&prioridad);
                }
                else{
                    printf("\n\n\n\n\n\tPrimero debe ingresar un paciente con nivel de urgencia\n\n\t");
                    system("pause");
                    system("cls");
                }
                break;

        case 14: //6)Punto f
                if (!emptyLPac(pacientes)||!emptyLPrio(prioridad)){
                    Mod_EDad (&pacientes,&prioridad);
                }
                else{
                    printf("\n\n\n\n\n\tPara modificar la edad de un paciente primero debe cargarlo\n\n\t");
                    system("pause");
                    system("cls");
                }
                break;


        case 15: //12)Punto l
                 if (!emptyLPrio(prioridad)){
                    borrados=Borrar_PacientesFinalizados (&prioridad);
                    if(borrados){
                    printf("\n\n\n\n\tSe han borrado con exito %d pacientes\n\n\t",borrados);
                    system("pause");
                    }else{
                    printf("\n\n\n\n\tNo se encontraron pacientes para borrar\n\n\t");
                    system("pause");
                    }
                 }else{
                    printf("\n\n\n\n\n\tPrimero debe haber un paciente que haya sido atendido\n\n\t");
                    system("pause");
                    system("cls");
                 }
                 break;

        case 16: exit(1);
        }
    }while(i!=16);
    return 0;
}

//FUNCIONES

//LISTA PACIENTE
//Inserta por hora en lista pac
void Insertar_Pac (ListaPac *lis, Paciente P){
    Paciente Paux;
    Inicializar_Paciente(&Paux);
    int min2,min1;
    if(!fullLPac(*lis)){
    if(emptyLPac(*lis)){
        insertLPac(lis, P);
    }else{
    resetLPac(lis);
    min1=Mostrar_HoraIngreso(P)*60+Mostrar_MinIngreso(P);
    Paux=copyLPac(*lis);
    min2=Mostrar_HoraIngreso(Paux)*60+Mostrar_MinIngreso(Paux);
    while(!oosLPac(*lis)&&(min1>=min2)){
        forwardLPac(lis);
        if(!oosLPac(*lis)){
            Paux=copyLPac(*lis);
            min2=Mostrar_HoraIngreso(Paux)*60+Mostrar_MinIngreso(Paux);
        }
    }
    insertLPac(lis, P);
    }
    }else{
        printf("\n\n\n\n\tNo hay mas memoria para ingresar mas pacientes");
        system("pause");
    }
}

//Suprime como fila en lista pac;
void Suprimir_Pac (ListaPac *lis){
    resetLPac(lis);
    supresLPac(lis);
}

//Copia como fila en lista Pac
Paciente Mostrar_Pac(ListaPac lis){
    resetLPac(&lis);
    return copyLPac(lis);
}



//LISTA PRIORIDAD
//De lista_prio insertar por el nivel
void Insertar_Prio(ListaPrio *lis,Paciente p){
    Paciente Paux;
    Inicializar_Paciente(&Paux);
    if(!fullLPrio(*lis)){
    if(emptyLPrio(*lis)){
        insertLPrio(lis,p);
    }else{
    resetLPrio(lis);
    Paux = copyLPrio(*lis);
    switch(Mostrar_NiveldeUrgencia(p)){
        case 1: while(!oosLPrio(*lis) && Mostrar_NiveldeUrgencia(Paux)==1 && Mostrar_Atendido(Paux)!=1 && Mostrar_HoradeAtencion(Paux)!=24){
                    forwardLPrio(lis);
                    if(!oosLPrio(*lis)){
                        Paux = copyLPrio(*lis);
                        }
                    }
                break;
        case 2: while(!oosLPrio(*lis) && Mostrar_NiveldeUrgencia(Paux)!=3 && Mostrar_Atendido(Paux)!=1 && Mostrar_HoradeAtencion(Paux)!=24 ){
                    forwardLPrio(lis);
                    if(!oosLPrio(*lis)){
                        Paux = copyLPrio(*lis);
                        }
                    }
                break;
        case 3: while(!oosLPrio(*lis) && Mostrar_Atendido(Paux)!=1 && Mostrar_HoradeAtencion(Paux)!=24){
                    forwardLPrio(lis);
                    if(!oosLPrio(*lis)){
                        Paux = copyLPrio(*lis);
                        }
                    }
                break;
    }
    insertLPrio(lis,p);
    }
    }else{
        printf("\n\n\n\n\tNo hay mas memoria para ingresar mas pacientes");
        system("pause");
    }
}

//Suprime de lista prio
void suprimirL_Prio(ListaPrio *lis){
    resetLPrio(lis);
    supresLPrio(lis);
}

//Copia como fila en Lista Prio
Paciente Mostrar_Prio(ListaPrio lis){
    resetLPrio(&lis);
    return copyLPrio(lis);
}

//Insertar atendidos y no atendidos al final
void Insertar_AlFinalPrio(ListaPrio *lis,Paciente p){
    resetLPrio(lis);
    while(!oosLPrio(*lis)){
        forwardLPrio(lis);
    }
    insertLPrio(lis,p);
}



//TAREAS
// Punto A
int cargar_nPacientes(ListaPac *lis){
    int cant,i,modi,modi1;
    char modic[30];
    Paciente p;
    Inicializar_Paciente(&p);
        printf("\n\n\n\t%cCuantas personas desea ingresar?\n",168);
        printf("\tIngrese cantidad: ");
        fflush(stdin);
        scanf("%d",&cant);
        system("cls");
    while(cant<0){
        printf("\n\n\n\t%cCuantas personas desea ingresar?\n",168);
        printf("\t--Cantidad no valida--");
        printf("\n\tVuelva a ingresar la cantidad: ");
        fflush(stdin);
        scanf("%d",&cant);
        system("cls");
    }
    for(i=0;i<cant;i++){
        printf("\n\n\n\n\t-------Paciente Numero %d-------", i+1);
        printf("\n\t%cHora de ingreso del paciente?\n",168);
        printf("\tFORMATO 24 HS\n");
        printf("\n\tHora: ");
        fflush(stdin);
        scanf("%d",&modi);
    while(modi<0||modi>23){
        system("cls");
        printf("\n\n\n\n\t-------Paciente Numero %d-------", i+1);
        printf("\n\t%cHora de ingreso del paciente?\n",168);
        printf("\tFORMATO 24 HS\n");
        printf("\n\t--Hora no valida--\n");
        printf("\tVuelva a ingresar hora: ");
        fflush(stdin);
        scanf("%d",&modi);
    }
        printf("\tMinutos: ");
        fflush(stdin);
        scanf("%d",&modi1);
        system("cls");
    while(modi1<0||modi1>59){
        printf("\n\n\n\n\t-------Paciente Numero %d-------", i+1);
        printf("\n\t%cHora de ingreso del paciente?\n",168);
        printf("\tFORMATO 24 HS\n");
        printf("\n\tHora ingresada: %d",modi);
        printf("\n\t--Minutos no validos--");
        printf("\n\tVuelva a ingresar los minutos: ");
        fflush(stdin);
        scanf("%d",&modi1);
        system("cls");
    }
    Cargar_HoradeIngreso(&p, modi, modi1);
        printf("\n\n\n\n\t-------Paciente Numero %d-------", i+1);
        if(Mostrar_HoraIngreso(p)<10){
            if(Mostrar_MinIngreso(p)<10){
                printf("\n\tHora ingresada: 0%d:0%d\n", Mostrar_HoraIngreso(p),Mostrar_MinIngreso(p));
            }
            else{
                printf("\n\tHora ingresada: 0%d:%d\n", Mostrar_HoraIngreso(p),Mostrar_MinIngreso(p));
            }
        }else{
            if(Mostrar_MinIngreso(p)<10){
                printf("\n\tHora ingresada: %d:0%d\n", Mostrar_HoraIngreso(p),Mostrar_MinIngreso(p));
            }
            else{
                printf("\n\tHora ingresada: %d:%d\n", Mostrar_HoraIngreso(p),Mostrar_MinIngreso(p));
            }
        }
        printf("\tNombre: ");
        fflush(stdin);
        scanf("%29[^\n]s",modic);
    Cargar_Nombre(&p,modic);
        printf("\tApellido: ");
        fflush(stdin);
        scanf("%29[^\n]s",modic);
    Cargar_Apellido(&p,modic);
        printf("\tDNI: ");
        fflush(stdin);
        scanf("%d",&modi);
    while(modi<1000000||modi>90000000){
        system("cls");
        printf("\n\n\n\n\t-------Paciente Numero %d-------", i+1);
        if(Mostrar_HoraIngreso(p)<10){
            if(Mostrar_MinIngreso(p)<10){
                printf("\n\tHora ingresada: 0%d:0%d", Mostrar_HoraIngreso(p),Mostrar_MinIngreso(p));
            }
            else{
                printf("\n\tHora ingresada: 0%d:%d", Mostrar_HoraIngreso(p),Mostrar_MinIngreso(p));
            }
        }else{
            if(Mostrar_MinIngreso(p)<10){
                printf("\n\tHora ingresada: %d:0%d", Mostrar_HoraIngreso(p),Mostrar_MinIngreso(p));
            }
            else{
                printf("\n\tHora ingresada: %d:%d", Mostrar_HoraIngreso(p),Mostrar_MinIngreso(p));
            }
        }
        printf("\n\tNombre: %s",Mostrar_Nombre(&p));
        printf("\n\tApellido: %s",Mostrar_Apellido(&p));
        printf("\n\t--Numero de DNI no valido--\n");
        printf("\tVuelva a ingresar el DNI: ");
        fflush(stdin);
        scanf("%d",&modi);
    }
    Cargar_DNI(&p,modi);
        printf("\n\t%cDesea ingresar la edad?\n\tPresione: 1 = SI\n\t\t  0 = NO\n",168);
        printf("\tIngrese opcion: ");
        fflush(stdin);
        scanf("%d",&modi);
        system("cls");
    while(modi<0||modi>1){
        printf("\n\n\n\n\t--------Paciente Nro %d--------",i+1);
        printf("\n\tNombre: %s",Mostrar_Nombre(&p));
        printf("\n\tApellido: %s",Mostrar_Apellido(&p));
        if(Mostrar_HoraIngreso(p)<10){
            if(Mostrar_MinIngreso(p)<10){
                printf("\n\tHora ingresada: 0%d:0%d\n", Mostrar_HoraIngreso(p),Mostrar_MinIngreso(p));
            }
            else{
                printf("\n\tHora ingresada: 0%d:%d\n", Mostrar_HoraIngreso(p),Mostrar_MinIngreso(p));
            }
        }else{
            if(Mostrar_MinIngreso(p)<10){
                printf("\n\tHora ingresada: %d:0%d\n", Mostrar_HoraIngreso(p),Mostrar_MinIngreso(p));
            }
            else{
                printf("\n\tHora ingresada: %d:%d\n", Mostrar_HoraIngreso(p),Mostrar_MinIngreso(p));
            }
        }
        printf("\tDNI: %d", Mostrar_DNI(p));
        printf("\n\t%cDesea ingresar la edad?\n\tPresione: 1 = SI\n\t\t  0 = NO\n",168);
        printf("\n\t--Opcion no valida--\n");
        printf("\tIngrese opcion: ");
        fflush(stdin);
        scanf("%d",&modi);
        system("cls");
    }
    if(modi){
        printf("\n\n\n\n\t-------Paciente Numero %d-------", i+1);
        if(Mostrar_HoraIngreso(p)<10){
            if(Mostrar_MinIngreso(p)<10){
                printf("\n\tHora ingresada: 0%d:0%d\n", Mostrar_HoraIngreso(p),Mostrar_MinIngreso(p));
            }
            else{
                printf("\n\tHora ingresada: 0%d:%d\n", Mostrar_HoraIngreso(p),Mostrar_MinIngreso(p));
            }
        }else{
            if(Mostrar_MinIngreso(p)<10){
                printf("\n\tHora ingresada: %d:0%d\n", Mostrar_HoraIngreso(p),Mostrar_MinIngreso(p));
            }
            else{
                printf("\n\tHora ingresada: %d:%d\n", Mostrar_HoraIngreso(p),Mostrar_MinIngreso(p));
            }
        }
        printf("\tNombre: %s",Mostrar_Nombre(&p));
        printf("\n\tApellido: %s",Mostrar_Apellido(&p));
        printf("\n\tDNI: %d", Mostrar_DNI(p));
        printf("\n\tIngrese Edad: ");
        fflush(stdin);
        scanf("%d",&modi);
    while(modi<0||modi>99){
        printf("\n\n\n\n\t-------Paciente Numero %d-------", i+1);
        if(Mostrar_HoraIngreso(p)<10){
            if(Mostrar_MinIngreso(p)<10){
                printf("\n\tHora ingresada: 0%d:0%d\n", Mostrar_HoraIngreso(p),Mostrar_MinIngreso(p));
            }
            else{
                printf("\n\tHora ingresada: 0%d:%d\n", Mostrar_HoraIngreso(p),Mostrar_MinIngreso(p));
            }
        }else{
            if(Mostrar_MinIngreso(p)<10){
                printf("\n\tHora ingresada: %d:0%d\n", Mostrar_HoraIngreso(p),Mostrar_MinIngreso(p));
            }
            else{
                printf("\n\tHora ingresada: %d:%d\n", Mostrar_HoraIngreso(p),Mostrar_MinIngreso(p));
            }
        }
        printf("\tNombre: %s",Mostrar_Nombre(&p));
        printf("\n\tApellido: %s",Mostrar_Apellido(&p));
        printf("\n\tDNI: %d", Mostrar_DNI(p));
        printf("\n\t--Edad no valida--\n");
        printf("\tVuelva a ingresar edad: ");
        fflush(stdin);
        scanf("%d",&modi);
    }
    Cargar_Edad(&p,modi);
    system("cls");
    printf("\n\n\n\n\t-------Paciente Numero %d-------", i+1);
        if(Mostrar_HoraIngreso(p)<10){
            if(Mostrar_MinIngreso(p)<10){
                printf("\n\tHora ingresada: 0%d:0%d\n", Mostrar_HoraIngreso(p),Mostrar_MinIngreso(p));
            }
            else{
                printf("\n\tHora ingresada: 0%d:%d\n", Mostrar_HoraIngreso(p),Mostrar_MinIngreso(p));
            }
        }else{
            if(Mostrar_MinIngreso(p)<10){
                printf("\n\tHora ingresada: %d:0%d\n", Mostrar_HoraIngreso(p),Mostrar_MinIngreso(p));
            }
            else{
                printf("\n\tHora ingresada: %d:%d\n", Mostrar_HoraIngreso(p),Mostrar_MinIngreso(p));
            }
        }
        printf("\tNombre: %s",Mostrar_Nombre(&p));
        printf("\n\tApellido: %s",Mostrar_Apellido(&p));
        printf("\n\tDNI: %d", Mostrar_DNI(p));
        printf("\n\tEdad: %d",Mostrar_Edad(p));
    }
    else{
        system("cls");
    printf("\n\n\n\n\t-------Paciente Numero %d-------", i+1);
        if(Mostrar_HoraIngreso(p)<10){
            if(Mostrar_MinIngreso(p)<10){
                printf("\n\tHora ingresada: 0%d:0%d\n", Mostrar_HoraIngreso(p),Mostrar_MinIngreso(p));
            }
            else{
                printf("\n\tHora ingresada: 0%d:%d\n", Mostrar_HoraIngreso(p),Mostrar_MinIngreso(p));
            }
        }else{
            if(Mostrar_MinIngreso(p)<10){
                printf("\n\tHora ingresada: %d:0%d\n", Mostrar_HoraIngreso(p),Mostrar_MinIngreso(p));
            }
            else{
                printf("\n\tHora ingresada: %d:%d\n", Mostrar_HoraIngreso(p),Mostrar_MinIngreso(p));
            }
        }
        printf("\tNombre: %s",Mostrar_Nombre(&p));
        printf("\n\tApellido: %s",Mostrar_Apellido(&p));
        printf("\n\tDNI: %d", Mostrar_DNI(p));
    }
    Insertar_Pac(lis,p);
    printf("\n\n\n\n\t");
    printf("El paciente fue cargado exitosamente\n\n\t");
    system("pause");
    system("cls");
    }

    return cant;
}


//PUNTO B Y C
void ImprimirPaciente (Paciente P,int i ){ //medico=1, enfermera=0, punto i=2
    int min1,min2;
    printf("\t----------Datos del paciente---------- \n");
    printf("\tNombre: %s\n", Mostrar_Nombre(&P));
    printf("\tApellido: %s\n", Mostrar_Apellido(&P));
    printf("\tNumero de Documento: %d\n", Mostrar_DNI(P));
    if (i!=2){
        if(Mostrar_HoraIngreso(P)<10){
            if(Mostrar_MinIngreso(P)<10){
                printf("\tHora ingresada: 0%d:0%d\n", Mostrar_HoraIngreso(P),Mostrar_MinIngreso(P));
            }
            else{
                printf("\tHora ingresada: 0%d:%d\n", Mostrar_HoraIngreso(P),Mostrar_MinIngreso(P));
            }
        }else{
            if(Mostrar_MinIngreso(P)<10){
                printf("\tHora ingresada: %d:0%d\n", Mostrar_HoraIngreso(P),Mostrar_MinIngreso(P));
            }
            else{
                printf("\tHora ingresada: %d:%d\n", Mostrar_HoraIngreso(P),Mostrar_MinIngreso(P));
            }
        }
    }
    if (Mostrar_Edad(P)>0){
        printf("\tEdad del paciente: %d\n",Mostrar_Edad(P)); //Opcional
    }
    if(i==1||i==2){
        if (Mostrar_NiveldeUrgencia(P)==1){
            printf("\tNivel de urgencia: Urgente \n");}
            else{
                if (Mostrar_NiveldeUrgencia(P)==2){
                    printf("\tNivel de urgencia: Moderado\n");}
                else{
                    printf("\tNivel de urgencia: leve\n");
                }
            }
        if (i==1){
        if (Mostrar_Atendido(P)==1){
            printf("\tEl paciente fue atendido\n");
            if(Mostrar_HoradeAtencion(P)<10){
                if(Mostrar_MinIngreso(P)<10){
                    printf("\tHora en la que fue atendido: 0%d:0%d\n", Mostrar_HoradeAtencion(P),Mostrar_MindeAtencion(P));
                }
                else{
                    printf("\tHora en la que fue atendido: 0%d:%d\n", Mostrar_HoradeAtencion(P),Mostrar_MindeAtencion(P));
                }
            }
            else{
                if(Mostrar_MindeAtencion(P)<10){
                    printf("\tHora en la que atendido: %d:0%d\n",Mostrar_HoradeAtencion(P),Mostrar_MindeAtencion(P));
                }
                else{
                    printf("\tHora en la que atendido: %d:%d\n", Mostrar_HoradeAtencion(P),Mostrar_MindeAtencion(P));
                }
            }
        }
        else{
            if (Mostrar_Atendido(P)==-1) {
            printf("\tEl paciente esta esperando a ser atendido\n");}
            else{
            printf("\tEl paciente no fue atendido\n");
            }
        }
        }
    }
    if(i==2){
        min1 = Mostrar_HoraIngreso(P)*60 + Mostrar_MinIngreso(P);
        min2 = Mostrar_HoradeAtencion(P)*60 +Mostrar_MindeAtencion(P);
        if(min1>min2){
            if(((int)((((24*60)-min1)+min2)/60))<10){
                if(((((24*60)-min1)+min2)-((int)((((24*60)-min1)+min2)/60))*60)<10){
                    printf("\tTiempo de espera del paciente: 0%d:0%d\n",((int)(Tiempo_de_Espera(P)/60)),(((24*60)-min1)+min2)-((int)((((24*60)-min1)+min2)/60))*60);
                }
                else{
                    printf("\tTiempo de espera del paciente: 0%d:%d\n", ((int)(Tiempo_de_Espera(P)/60)),(((24*60)-min1)+min2)-((int)((((24*60)-min1)+min2)/60))*60);
                }
            }
            else{
                if(((((24*60)-min1)+min2)-((int)((((24*60)-min1)+min2)/60))*60)<10){
                    printf("\tTiempo de espera del paciente: %d:0%d\n",((int)(Tiempo_de_Espera(P)/60)),(((24*60)-min1)+min2)-((int)((((24*60)-min1)+min2)/60))*60);
                }
                else{
                    printf("\tTiempo de espera del paciente: %d:%d\n", ((int)(Tiempo_de_Espera(P)/60)),(((24*60)-min1)+min2)-((int)((((24*60)-min1)+min2)/60))*60);
                }
            }
        }else{
            if(((int)((min2-min1)/60))<10){
                if(((min2-min1)-(((int)((min2-min1)/60))*60))<10){
                    printf("\tTiempo de espera del paciente: 0%d:0%d\n", (int)((min2-min1)/60),(min2-min1)-(((int)((min2-min1)/60))*60));
                }
                else{
                    printf("\tTiempo de espera del paciente: 0%d:%d\n", (int)((min2-min1)/60),(min2-min1)-(((int)((min2-min1)/60))*60));
                }
            }
            else{
                if(((min2-min1)-(((int)((min2-min1)/60))*60))<10){
                    printf("\tTiempo de espera del paciente: %d:0%d\n",(int)((min2-min1)/60),(min2-min1)-(((int)((min2-min1)/60))*60));
                }
                else{
                    printf("\tTiempo de espera del paciente: %d:%d\n", (int)((min2-min1)/60),(min2-min1)-(((int)((min2-min1)/60))*60));
                }
            }
        }
    }
}



//PUNTO D
//¿PARA ESTE PUNTO TENGO QUE MOSTRAR AL PACIENTE?
void Nivel_de_Urgencia(ListaPrio *Prio,ListaPac *Pac){
    Paciente P;
    Inicializar_Paciente(&P);
    int modi;
    P=Mostrar_Pac(*Pac);
    printf("\n\n\n\n");
    ImprimirPaciente(P,0);
    printf("\n\tDesigne el nivel de urgencia\n\t1 = URGENTE\n\t2 = MODERADO\n\t3 = LEVE\n");
    printf("\tOpcion: ");
    fflush(stdin);
    scanf("%d",&modi);
    system("cls");
    while(modi!=1 && modi!=2 && modi!=3){
        printf("\n\n\n\n");
        ImprimirPaciente(P,0);
        printf("\n\tDesigne el nivel de urgencia\n\t1 = URGENTE\n\t2 = MODERADO\n\t3 = LEVE\n");
        printf("\t--Opcion no valida--\n");
        printf("\tOpcion: ");
        fflush(stdin);
        scanf("%d",&modi);
        system("cls");
    }
    Cargar_NiveldeUrgencia(&P,modi);
    Insertar_Prio(Prio,P);
    Suprimir_Pac(Pac);
    printf("\n\n\n\n\tSe ha cargado el nivel de urgencia exitosamente\n\n\t");
    system("pause");
}


//punto E
void Atendido_Por_Medico (ListaPrio *Prio){
    int hora, minutos;
    Paciente P;
    Inicializar_Paciente(&P);
    P=Mostrar_Prio(*Prio);
    printf("\n\n\n\n");
    ImprimirPaciente(P,0);
    switch (Mostrar_NiveldeUrgencia(P)){
                case 1: printf("\tNivel de urgencia: URGENTE\n");
                        break;
                case 2: printf("\tNivel de urgencia: MODERADO\n");
                        break;
                case 3: printf("\tNivel de urgencia: LEVE\n");
                        break;
                }
    printf("\n\tIngresar hora de atencion\n\tFORMATO 24 HS\n\t");
    printf("Hora: ");
    scanf("%d", &hora);
    system("cls");
    while (hora<0||hora>23){
        printf("\n\n\n\n");
        ImprimirPaciente(P,0);
        switch (Mostrar_NiveldeUrgencia(P)){
                case 1: printf("\tNivel de urgencia: URGENTE\n");
                        break;
                case 2: printf("\tNivel de urgencia: MODERADO\n");
                        break;
                case 3: printf("\tNivel de urgencia: LEVE\n");
                        break;
                }
        printf("\n\tIngresar hora de atencion\n\tFORMATO 24 HS\n");
        printf("\t--Hora no valida--\n");
        printf("\tHora: ");
        scanf("%d", &hora);
        system("cls");
    }
    printf("\n\n\n\n");
    ImprimirPaciente(P,0);
    switch (Mostrar_NiveldeUrgencia(P)){
                case 1: printf("\tNivel de urgencia: URGENTE\n");
                        break;
                case 2: printf("\tNivel de urgencia: MODERADO\n");
                        break;
                case 3: printf("\tNivel de urgencia: LEVE\n");
                        break;
                }
    printf("\n\tIngresar hora de atencion\n\tFORMATO 24 HS\n");
    printf("\tHora: %d\n",hora);
    printf("\tMinutos: ");
    scanf("%d", &minutos);
    system("cls");
    while (minutos<0||minutos>59){
        printf("\n\n\n\n");
        ImprimirPaciente(P,0);
        switch (Mostrar_NiveldeUrgencia(P)){
                case 1: printf("\tNivel de urgencia: URGENTE\n");
                        break;
                case 2: printf("\tNivel de urgencia: MODERADO\n");
                        break;
                case 3: printf("\tNivel de urgencia: LEVE\n");
                        break;
                }
        printf("\n\tIngresar hora de atencion\n\tFORMATO 24 HS\n");
        printf("\tHora: %d\n",hora);
        printf("\t--Minutos no validos--\n");
        printf("\tMinutos: ");
        scanf("%d", &minutos);
        system("cls");
    }
    Cargar_HoradeAtencion(&P, hora, minutos);
    Cargar_Atendido(&P, 1); //atendido
    suprimirL_Prio(Prio);
    Insertar_AlFinalPrio(Prio, P);
}


//PUNTO F
void Mod_EDad (ListaPac *LPac,ListaPrio *LPrio){
    int j,err,DNI,t=1,h=1;
    resetLPac(LPac);
    resetLPrio(LPrio);
    Paciente P;
    Inicializar_Paciente(&P);
    printf("\n\n\n\n\tPara modificar la edad de un paciente debe ingresar su DNI\n");
    printf("\tDNI: ");
    fflush(stdin);
    scanf("%d", &DNI);
    system("cls");
    while(DNI<1000000||DNI>90000000){
        printf("\n\n\n\n\tPara modificar la edad de un paciente debe ingresar su DNI\n");
        printf("\t--DNI no valido--\n");
        printf("\tDNI: ");
        fflush(stdin);
        scanf("%d", &DNI);
        system("cls");
    }
    do{
    printf("\n\n\n\n\t%c Hubo un error al ingresar el DNI ? Nro de DNI: %d \n\t1 = SI\n\t2 = NO\n\t",168,DNI);
    printf("Opcion: ");
    fflush(stdin);
    scanf("%d", &err);
    system("cls");
        while (err<1||err>2){
        printf("\n\n\n\n\t%c Hubo un error al ingresar el DNI ? Nro de DNI: %d \n\t1 = SI\n\t2 = NO\n",168,DNI);
        printf("\t--Opcion no valida\n");
        printf("\tOpcion: ");
        fflush(stdin);
        scanf("%d", &err);
        system("cls");}
    if(err==1){
        printf("\n\n\n\n\tEl DNI ingreado presenta un error, ingrese nuevamente: \n");
        printf("\tDNI: ");
        fflush(stdin);
        scanf("%d", &DNI);
        system("cls");
        while(DNI<1000000||DNI>90000000){
            printf("\n\n\n\n\tEl DNI ingreado presenta un error, ingrese nuevamente: \n");
            printf("\t--DNI no valido--\n");
            printf("\tDNI: ");
            fflush(stdin);
            scanf("%d", &DNI);
            system("cls");
        }
    }else{
        t=0;
    }
    }while(t);
    if(!emptyLPac(*LPac)){
    P=Mostrar_Pac(*LPac);
    while(Mostrar_DNI(P)!=DNI&&!oosLPac(*LPac)){
        forwardLPac(LPac);
        if(!oosLPac(*LPac)){
        P=copyLPac(*LPac);
        }
    }
    }
    if(!oosLPac(*LPac)){
        printf("\n\n\n\n\t-------Paciente encontrado--------");
        if(Mostrar_HoraIngreso(P)<10){
            if(Mostrar_MinIngreso(P)<10){
                printf("\n\tHora ingresada: 0%d:0%d", Mostrar_HoraIngreso(P),Mostrar_MinIngreso(P));
            }
            else{
                printf("\n\tHora ingresada: 0%d:%d", Mostrar_HoraIngreso(P),Mostrar_MinIngreso(P));
            }
        }else{
            if(Mostrar_MinIngreso(P)<10){
                printf("\n\tHora ingresada: %d:0%d", Mostrar_HoraIngreso(P),Mostrar_MinIngreso(P));
            }
            else{
                printf("\n\tHora ingresada: %d:%d", Mostrar_HoraIngreso(P),Mostrar_MinIngreso(P));
            }
        }
        printf("\n\tNombre: %s",Mostrar_Nombre(&P));
        printf("\n\tApellido: %s",Mostrar_Apellido(&P));
        printf("\n\tNro de DNI: %d",Mostrar_DNI(P));
        printf("\n\tIngrese edad para el paciente\n");
        printf("\tEdad: ");
        fflush(stdin);
        scanf("%d", &j);
        system("cls");
        while(j<0||j>99){
            printf("\n\n\n\n\t-------Paciente encontrado--------");
        if(Mostrar_HoraIngreso(P)<10){
            if(Mostrar_MinIngreso(P)<10){
                printf("\n\tHora ingresada: 0%d:0%d", Mostrar_HoraIngreso(P),Mostrar_MinIngreso(P));
            }
            else{
                printf("\n\tHora ingresada: 0%d:%d", Mostrar_HoraIngreso(P),Mostrar_MinIngreso(P));
            }
        }else{
            if(Mostrar_MinIngreso(P)<10){
                printf("\n\tHora ingresada: %d:0%d", Mostrar_HoraIngreso(P),Mostrar_MinIngreso(P));
            }
            else{
                printf("\n\tHora ingresada: %d:%d", Mostrar_HoraIngreso(P),Mostrar_MinIngreso(P));
            }
        }
        printf("\n\tNombre: %s",Mostrar_Nombre(&P));
        printf("\n\tApellido: %s",Mostrar_Apellido(&P));
        printf("\n\tNro de DNI: %d",Mostrar_DNI(P));
        printf("\n\tIngrese edad para el paciente\n");
            printf("\t--Edad no valida--\n");
            printf("\tEdad: ");
            fflush(stdin);
            scanf("%d", &j);
            system("pause");
        }
        Cargar_Edad(&P, j);
        supresLPac(LPac);
        Insertar_Pac(LPac, P);
        h=0;
    }else{
    if(!emptyLPrio(*LPrio)){
        P=Mostrar_Prio(*LPrio);
        while(Mostrar_DNI(P)!=DNI&&!oosLPrio(*LPrio)){
            forwardLPrio(LPrio);
            if(!oosLPrio(*LPrio)){
            P=copyLPrio(*LPrio);
            }
        }
    }
    if(oosLPrio(*LPrio)==0){
        printf("\n\n\n\n\t-------Paciente encontrado--------");
        if(Mostrar_HoraIngreso(P)<10){
            if(Mostrar_MinIngreso(P)<10){
                printf("\n\tHora ingresada: 0%d:0%d", Mostrar_HoraIngreso(P),Mostrar_MinIngreso(P));
            }
            else{
                printf("\n\tHora ingresada: 0%d:%d", Mostrar_HoraIngreso(P),Mostrar_MinIngreso(P));
            }
        }else{
            if(Mostrar_MinIngreso(P)<10){
                printf("\n\tHora ingresada: %d:0%d", Mostrar_HoraIngreso(P),Mostrar_MinIngreso(P));
            }
            else{
                printf("\n\tHora ingresada: %d:%d", Mostrar_HoraIngreso(P),Mostrar_MinIngreso(P));
            }
        }
        printf("\n\tNombre: %s",Mostrar_Nombre(&P));
        printf("\n\tApellido: %s",Mostrar_Apellido(&P));
        printf("\n\tNro de DNI: %d",Mostrar_DNI(P));
        printf("\n\tIngrese edad para el paciente\n");
        printf("\tEdad: ");
        fflush(stdin);
        scanf("%d", &j);
        system("cls");
        while(j<0||j>99){
            printf("\n\n\n\n\t-------Paciente encontrado--------");
        if(Mostrar_HoraIngreso(P)<10){
            if(Mostrar_MinIngreso(P)<10){
                printf("\n\tHora ingresada: 0%d:0%d", Mostrar_HoraIngreso(P),Mostrar_MinIngreso(P));
            }
                else{
                    printf("\n\tHora ingresada: 0%d:%d", Mostrar_HoraIngreso(P),Mostrar_MinIngreso(P));
                }
            }else{
                if(Mostrar_MinIngreso(P)<10){
                    printf("\n\tHora ingresada: %d:0%d", Mostrar_HoraIngreso(P),Mostrar_MinIngreso(P));
                }
                else{
                    printf("\n\tHora ingresada: %d:%d", Mostrar_HoraIngreso(P),Mostrar_MinIngreso(P));
                }
            }
            printf("\n\tNombre: %s",Mostrar_Nombre(&P));
            printf("\n\tApellido: %s",Mostrar_Apellido(&P));
            printf("\n\tNro de DNI: %d",Mostrar_DNI(P));
            printf("\n\tIngrese edad para el paciente\n");
            printf("\t--Edad no valida--\n");
            printf("\tEdad: ");
            fflush(stdin);
            scanf("%d", &j);
            system("cls");
        }
        Cargar_Edad(&P, j);
        supresLPrio(LPrio);
        Insertar_Prio(LPrio, P);
        h=0;
        }
    }
    if(h){
        printf("\n\n\n\n\tNo ha sido posible encontrar un paciente con el Nro de DNI: %d \n", DNI);
        printf("\n\t");
        system("pause");
    }
}

//PUNTO G
void No_Atendido (ListaPrio *Prio){
    Paciente P;
    Inicializar_Paciente(&P);
    P=Mostrar_Prio(*Prio);
    Cargar_Atendido(&P, 0); //no atendido
    Cargar_HoradeAtencion(&P, 24, 00);
    suprimirL_Prio(Prio);
    Insertar_AlFinalPrio(Prio,P);
    printf("\n\n\n\n");
    ImprimirPaciente(P,1);
    printf("\n\tNo fue atendido debido a que se retiro antes\n\n\t");
    system("pause");
}

//PUNTO H
void Mostrar_list_por_Nivel (ListaPrio LPrio){
    int u, i=1, j;
    Paciente P;
    Inicializar_Paciente(&P);
    printf("\n\n\n\n\t%c Cual es el nivel de urgencia que desea ver ?\n",168);
    printf("\tLos niveles de urgencia son:\n\t1 = URGENTE\n\t2 = MODERADO\n\t3 = LEVE\n");
    printf("\n\tIngrese nivel: ");
    scanf("%d", &u);
    system("cls");
    while (u<1||u>3){
        printf("\n\n\n\n\t%c Cual es el nivel de urgencia que desea ver ?\n",168);
        printf("\tLos niveles de urgencia son:\n\t1 = URGENTE\n\t2 = MODERADO\n\t3 = LEVE\n\n");
        printf("\t--Nivel ingresado no valido--");
        printf("\n\tIngrese nivel: ");
        scanf("%d", &u);
        system("cls");
    }
    resetLPrio(&LPrio);
    printf("\n\n\n\n"); //format
    while (!oosLPrio(LPrio)){
        P=copyLPrio(LPrio);
        if (Mostrar_NiveldeUrgencia(P)==u&&Mostrar_Atendido(P)==1){
            printf("\t----------PACIENTE NRO: %d----------\n", i++);
            ImprimirPaciente(P,1);
            printf("\n");
            j=0;
        }
        forwardLPrio(&LPrio);
    }
    if (j){
        printf("\n\n\n\n\tNadie ha sido atendido aun con el nivel de urgencia ingresado: %d\n", u);
    }
    printf("\n\t");
    system("pause");
}

//PUNTO I
void Mostrar_atendidos (ListaPrio *LPrio){
    int i=1, j;
    Paciente P;
    Inicializar_Paciente(&P);
    resetLPrio(LPrio);
    printf("\n\n\n\n");
    while (!oosLPrio(*LPrio)){
        P=copyLPrio(*LPrio);
        if (Mostrar_Atendido(P)==1){
            printf("\t--------PACIENTE NRO: %d--------\n", i++);
            ImprimirPaciente(P,2);
            printf("\n");
            j=0;
        }
        forwardLPrio(LPrio);
    }
    if (j){
        printf("\n\n\n\n\tNadie ha sido atendido\n");
    }
    printf("\n\t");
    system("pause");
}

//PUNTO J
int Tiempo_de_Espera(Paciente P){
    if((Mostrar_HoraIngreso(P)*60 + Mostrar_MinIngreso(P))>(Mostrar_HoradeAtencion(P)*60 +Mostrar_MindeAtencion(P))){
        return (int)(((24*60)-(Mostrar_HoraIngreso(P)*60+ Mostrar_MinIngreso(P)))+(Mostrar_HoradeAtencion(P)*60 +Mostrar_MindeAtencion(P)));
    }
    else{
        return (int)((Mostrar_HoradeAtencion(P)*60 +Mostrar_MindeAtencion(P))-(Mostrar_HoraIngreso(P)*60+ Mostrar_MinIngreso(P)));
    }
}

//RECURSIVA
void Espero_MasTiempo(ListaPrio LPrio,int mayor, int j,int h){
    if(!h){
        if(j==-1){
            printf("\tNo hay pacientes atendidos por el momento\n");
        }
        else{
            if(j==0){
                if(Tiempo_de_Espera(copyLPrio(LPrio))==mayor){
                    ImprimirPaciente(copyLPrio(LPrio),2);
                }else{
                    forwardLPrio(&LPrio);
                    Espero_MasTiempo(LPrio,mayor,j,h);

                }
            }else{
                if(Tiempo_de_Espera(copyLPrio(LPrio))==mayor){
                    ImprimirPaciente(copyLPrio(LPrio),2);
                    forwardLPrio(&LPrio);
                    Espero_MasTiempo(LPrio,mayor,j-1,h);
                }else{
                    forwardLPrio(&LPrio);
                    Espero_MasTiempo(LPrio,mayor,j,h);
                }
            }
        }
    }
    else{
        if(oosLPrio(LPrio)){
            h=0;
            resetLPrio(&LPrio);
            Espero_MasTiempo(LPrio,mayor,j,h);
        }
        else{
            if((Mostrar_Atendido(copyLPrio(LPrio)))==1){
                if(Tiempo_de_Espera(copyLPrio(LPrio))>=mayor){
                    if(Tiempo_de_Espera(copyLPrio(LPrio))>mayor){
                        mayor=Tiempo_de_Espera(copyLPrio(LPrio));
                        forwardLPrio(&LPrio);
                        Espero_MasTiempo(LPrio,mayor,0,h);
                    }
                    else{
                        forwardLPrio(&LPrio);
                        Espero_MasTiempo(LPrio,mayor,j+1,h);
                    }
                }
                else{
                    forwardLPrio(&LPrio);
                    Espero_MasTiempo(LPrio,mayor,j,h);
                }
            }
            else{
                forwardLPrio(&LPrio);
                Espero_MasTiempo(LPrio,mayor,j,h);
            }
        }
    }
}

//PUNTO K
void Cargar_NoAtend_enArchivo (ListaPrio LPrio){
    int j=1;
    Paciente P;
    Inicializar_Paciente(&P);
    FILE *T;
    T=fopen("noatendidos.txt", "w");
    if (T==NULL){
        printf("\n\n\n\n\tNo hay espacio suficiente...\nNo se puede realizar esta funcion.\n\n\t");
        system("pause");
    }
    else {
        while(feof(T)==0&&!oosLPrio(LPrio)){
            P=copyLPrio(LPrio);
            if (Mostrar_Atendido(P)!=1){
                if (j==1){
                    fprintf(T,"Pacientes no atendidos\n");
                    j=2;
                }
                fprintf(T,"Nombre: %s\n",Mostrar_Nombre(&P));
                fprintf(T,"Apellido: %s\n",Mostrar_Apellido(&P));
                fprintf(T,"DNI: %d",Mostrar_DNI(P));
                fprintf(T,"Hora de ingreso: %d:%d\n",Mostrar_HoraIngreso(P),Mostrar_MinIngreso(P));
                if(Mostrar_Edad(P)!=-1){
                    fprintf(T,"Edad: %d\n",Mostrar_Edad(P));
                }
                switch (Mostrar_NiveldeUrgencia(P)){
                case 1: fprintf(T,"Nivel de urgencia: URGENTE\n");
                case 2: fprintf(T,"Nivel de urgencia: MODERADO\n");
                case 3: fprintf(T,"Nivel de urgencia: LEVE\n");
                }
            }
            forwardLPrio(&LPrio);
        }
        printf("\n\n\n\n\tSe cargaron los pacientes no atendidos exitosamente\n\n\t");
        system("pause");
    }
}


//PUNTO L
int Borrar_PacientesFinalizados (ListaPrio *LPrio) {
    int i=0;
    Paciente P;
    Inicializar_Paciente(&P);
    resetLPrio(LPrio);
    while (!oosLPrio(*LPrio)) {
        P=copyLPrio(*LPrio);
        if (Mostrar_Atendido(P)==1 || Mostrar_HoradeAtencion(P)==24){
            supresLPrio(LPrio);
            i+=1;
        }else{
        if(!oosLPrio(*LPrio)){
        forwardLPrio(LPrio);
        }
        }
    }
    return i;
}

//PUNTO LL
void Cargar_en_ListaIngreso (ListaPac *LPac,int *YaUsado1) {
    int modi1,modi2;
    char modic[30];
    Paciente P;
    Inicializar_Paciente(&P);
    FILE *T;
    T=fopen("precarga.txt","r");
    if (T==NULL){
        printf("\n\n\n\n\tNo hay espacio suficiente...\n\n\t");
        system("pause");
    }
    else{
        rewind(T);
        while(feof(T)==0){
            fscanf(T,"%d",&modi1);
            if(feof(T)==0){
            fscanf(T,"%d",&modi2);
            Cargar_HoradeIngreso(&P,modi1,modi2); //hora ingre
            fscanf(T,"%s", modic);
            Cargar_Nombre(&P,modic);     //name
            fscanf(T,"%s",modic);
            Cargar_Apellido(&P,modic);  //apellido
            fscanf(T,"%d",&modi1);
            Cargar_DNI(&P,modi1);    //dni
            fscanf(T,"%d",&modi2);
            if (modi2==1) {
                fscanf(T,"%d",&modi1);
                Cargar_Edad(&P,modi1);
            }
            Insertar_Pac(LPac,P);
            }
        }
        printf("\n\n\n\n\n\tSe han cargado los pacientes del archivo precarga.txt exitosamente\n\n\t");
        system("pause");
        *YaUsado1=1;
    }
}


//PUNTO M
void Mostrar_CuantosHayAntes(ListaPrio LPrio,ListaPac LPac){
    int k=0,err,DNI,t=1;
    resetLPac(&LPac);
    resetLPrio(&LPrio);
    Paciente P;
    Inicializar_Paciente(&P);
    printf("\n\n\n\n\tPara saber cuantos hay antes ingrese DNI\n");
    printf("\tDNI: ");
    fflush(stdin);
    scanf("%d", &DNI);
    system("cls");
    while(DNI<1000000||DNI>90000000){
        printf("\n\n\n\n\tPara saber cuantos hay antes ingrese DNI\n");
        printf("\t--DNI no valido--\n");
        printf("\tDNI: ");
        fflush(stdin);
        scanf("%d", &DNI);
        system("cls");
    }
    do{
    printf("\n\n\n\n\t%c Hubo un error al ingresar el DNI ? Nro de DNI: %d \n\t1 = SI\n\t2 = NO\n\t",168,DNI);
    printf("Opcion: ");
    fflush(stdin);
    scanf("%d", &err);
    system("cls");
        while (err<1||err>2){
        printf("\n\n\n\n\t%c Hubo un error al ingresar el DNI ? Nro de DNI: %d \n\t1 = SI\n\t2 = NO\n",168,DNI);
        printf("\t--Opcion no valida\n");
        printf("\tOpcion: ");
        fflush(stdin);
        scanf("%d", &err);
        system("cls");}
    if(err==1){
        printf("\n\n\n\n\tEl DNI ingreado presenta un error, ingrese nuevamente: \n");
        printf("\tDNI: ");
        fflush(stdin);
        scanf("%d", &DNI);
        system("cls");
        while(DNI<1000000||DNI>90000000){
            printf("\n\n\n\n\tEl DNI ingreado presenta un error, ingrese nuevamente: \n");
            printf("\t--DNI no valido--\n");
            printf("\tDNI: ");
            fflush(stdin);
            scanf("%d", &DNI);
            system("cls");
        }
    }else{
        t=0;
    }
    }while(t);
    if(!oosLPrio(LPrio)){
        resetLPrio(&LPrio);
        P=copyLPrio(LPrio);
    }
    while(!oosLPrio(LPrio) && Mostrar_DNI(P)!=DNI && Mostrar_Atendido(P)==-1 && Mostrar_HoradeAtencion(P)!=24){
        k+=1;
        forwardLPrio(&LPrio);
        if(!oosLPrio(LPrio)){
            P=copyLPrio(LPrio);
        }
    }
    if(!oosLPrio(LPrio)){
        if(Mostrar_DNI(P)==DNI){
        if(Mostrar_Atendido(P)==1){
            printf("\n\n\n\n\tEl paciente con el DNI %d ya ha sido atendido\n\n\t",DNI);
        }else{
            if(Mostrar_HoradeAtencion(P)==24){
                printf("\n\n\n\n\tEl paciente con el DNI %d se ha marchado sin ser atendido\n\n\t",DNI);
            }else{
                if(k){
                    printf("\n\n\n\n\tHay %d pacientes antes que la persona con el DNI Nro: %d\n\n\t",k,DNI);
                }
                else{
                    printf("\n\n\n\n\tEl paciente con el DNI Nro: %d es el proximo que sera atendido\n\n\t",DNI);
                }
            }
            }
        }else{
        if(!oosLPac(LPac)){
            P=copyLPac(LPac);
        }
        while(!oosLPac(LPac)&& Mostrar_DNI(P)!=DNI){
            k+=1;
            forwardLPac(&LPac);
            if(!oosLPac(LPac)){
                P=copyLPac(LPac);
            }
        }
        if(Mostrar_DNI(P)==DNI){
            if(k){
                printf("\n\n\n\n\tHay %d pacientes antes que la persona con el DNI Nro: %d\n\n\t",k,DNI);
            }
            else{
                printf("\n\n\n\n\tEl paciente con el DNI Nro: %d es el proximo que sera atendido\n\n\t",DNI);
            }
        }else{
            printf("\n\n\n\n\tNo hay ningun paciente con el Nro de DNI: %d\n\n\t",DNI);
        }
    }
    }
    else{
        if(!oosLPac(LPac)){
            P=copyLPac(LPac);
        }
        while(!oosLPac(LPac)&& Mostrar_DNI(P)!=DNI){
            k=+1;
            forwardLPac(&LPac);
            if(!oosLPac(LPac)){
                P=copyLPac(LPac);
            }
        }
        if(Mostrar_DNI(P)==DNI){
            if(k){
                printf("\n\n\n\n\tHay %d pacientes antes que la persona con el DNI Nro: %d\n\n\t",k,DNI);
            }
            else{
                printf("\n\n\n\n\tEl paciente con el DNI Nro: %d es el proximo que sera atendido\n\n\t",DNI);
            }
        }else{
            printf("\n\n\n\n\tNo hay ningun paciente con el Nro de DNI: %d\n\n\t",DNI);
        }
    }
    system("pause");
}

//  IMPRIMIR CANTIDAD
// PUNTO N

void Mostrar_CuantosHayEnEspera(ListaPrio LPrio,ListaPac LPac){
    int k=0,i=0;
    Paciente P;
    Inicializar_Paciente(&P);
    while(!oosLPac(LPac)){
        i+=1;
        forwardLPac(&LPac);
    }
    printf("\n\n\n\n\t----------------ENFERMERA----------------\n");
    if(i){
        printf("\tHay %d pacientes esperando ser atendidos\n\n",i);
    }else{
        printf("\tNo hay pacientes esperando ser atendidos\n\n");
    }
    if(!oosLPrio(LPrio)){
        P=copyLPrio(LPrio);
    }
    while(!oosLPrio(LPrio) && Mostrar_Atendido(P)!=1 && Mostrar_HoradeAtencion(P)!=24){
        k+=1;
        forwardLPrio(&LPrio);
        if(!oosLPrio(LPrio)){
            P=copyLPrio(LPrio);
        }
    }
    printf("\t------------------MEDICO-----------------\n");
    if(k){
        printf("\tHay %d pacientes esperando ser atendidos\n\n\t",k);
    }else{
        printf("\tNo hay pacientes esperando ser atendidos\n\n\t");
    }
    system("pause");
}

/*
//PUNTO M
void Mostrar_CuantosHayAntes(ListaPrio LPrio,ListaPac LPac){
    int err,DNI,t=1;
    resetLPac(&LPac);
    resetLPrio(&LPrio);
    Paciente P;
    Inicializar_Paciente(&P);
    printf("Ingrese DNI de la persona: ");
    scanf("%d", &DNI);
    system("cls");
    do{
    printf("%c Hubo un error al ingresar el DNI ? Nro de DNI: %d \n1 = SI\n2 = NO\n",168,DNI);
    scanf("%d", &err);
        while (err<1||err>2){
        printf("Por favor, ingrese una opcion valida\n1 = SI\n2 = NO\n");
        scanf("%d", &err);
        system("cls");}
    if(err==1){
        printf("Vuelva a ingresar DNI: ");
        scanf("%d", &DNI);
        system("cls");
    }else{
        t=0;
    }
    }while(t);
    if(!oosLPrio(LPrio)){
        P=copyLPrio(LPrio);
    }
    while(!oosLPrio(LPrio) && Mostrar_DNI(P)!=DNI && Mostrar_Atendido(P)==0 && Mostrar_HoradeAtencion(P)!=24){
        forwardLPrio(&LPrio);
        if(!oosLPrio(LPrio)){
            P=copyLPrio(LPrio);
        }
    }
    if(!oosLPrio(LPrio)){
    if(Mostrar_DNI(P)==DNI){
        forwardLPrio(&LPrio);
        Mostrar_CuantosHayEnEspera(LPrio,LPac);
    }
    if(Mostrar_Atendido(P)==1){
        printf("El paciente con el DNI %d ya fue atendido",DNI);
    }
    if(Mostrar_HoradeAtencion(P)==24){
        printf("El paciente con el DNI %d se fue sin ser atendido",DNI);
    }
    }
    else{
        if(!oosLPac(LPac)){
            P=copyLPac(LPac);
        }
        while(!oosLPac(LPac)&& Mostrar_DNI(P)!=DNI){
            forwardLPac(&LPac);
            if(!oosLPac(LPac)){
                P=copyLPac(LPac);
            }
        }
        if(Mostrar_DNI(P)==DNI){
            forwardLPac(&LPac);
            Mostrar_CuantosHayEnEspera(LPrio,LPac);
        }else{
            printf("No hay ningun paciente con el DNI %d",DNI);
        }
    }
}

//¿SE DEBE MOSTRAR LA CANTIDAD O LOS PACIENTES?
// IMPRIMIR PACIENTE

//PUNTO N
void Mostrar_CuantosHayEnEspera(ListaPrio LPrio,ListaPac LPac){
    int k=1,i=1;
    Paciente P;
    Inicializar_Paciente(&P);
    while(!oosLPac(LPac)){
        P=copyLPac(LPac);
        if(i){
           printf("Pacientes esperando ser atendidos por la Enfermera\n");
           i=0;
        }
        ImprimirPaciente(P,0);
        forwardLPac(&LPac);
    }
    if(!oosLPrio(LPrio)){
        P=copyLPrio(LPrio);
    }
    while(!oosLPrio(LPrio) && Mostrar_Atendido(P)!=1 && Mostrar_HoradeAtencion(P)!=24){
        if(k){
           printf("Pacientes esperando ser atendidos por el Medico\n");
           k=0;
        }
        ImprimirPaciente(P,0);
        forwardLPrio(&LPrio);
        if(!oosLPrio(LPrio)){
            P=copyLPrio(LPrio);
        }
    }
    printf("\n");
    fflush(stdin);
    system("pause");
    system("cls");
}

*/
//FINAL
