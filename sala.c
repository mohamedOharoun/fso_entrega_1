#include "stdio.h"
#include "stdlib.h"
#include "./sala.h"

int capacidad_maxima = -1;
int* sala;
int ocupados = 0;

int crea_sala(const int capacidad) {
    if(capacidad_maxima != -1) return -1;
    if(capacidad < 1) return -1;

    sala = (int*) calloc(capacidad, sizeof(int));
    if(sala == NULL) return -1;

    capacidad_maxima = capacidad;

    return capacidad_maxima;
}

int asientos_ocupados() {
    if(capacidad_maxima == -1) return -1;
    return ocupados;
}

int capacidad_sala () {
    if(capacidad_maxima == -1) return -1;
    return capacidad_maxima;
}

int asientos_libres() {
    if(capacidad_maxima == -1) return -1;
    return (capacidad_maxima - ocupados);
}

int estado_asiento(int id_asiento) {
    if(capacidad_maxima == -1) return -1;
    if(id_asiento < 1 || id_asiento > capacidad_maxima) return -1;
    id_asiento--;
    return sala[id_asiento];
}

int libera_asiento(int id_asiento) {
    if(capacidad_maxima == -1 || ocupados == 0) return -1;
    if(id_asiento < 1 || id_asiento > capacidad_maxima) return -1;
    id_asiento--;
    int status = sala[id_asiento];
    if(status == 0) return -1;
    sala[id_asiento] = 0;
    ocupados--;
    return status;
}

int reserva_asiento(const int id_persona) {
    if(capacidad_maxima == -1) return -1;
    if(id_persona < 1) return -1;
    if(ocupados == capacidad_maxima) return -1;
    for(int i = 0; i < capacidad_maxima; i++) {
        if(sala[i] == 0) {
            sala[i] = id_persona;
            ocupados++;
            return (i+1);
        }
    }

    return -1;
}

int elimina_sala() {
    if(capacidad_maxima == -1) return -1;

    capacidad_maxima = -1;
    ocupados = 0;
    free(sala);
    return 0;
}