#include "stdio.h"
#include "stdlib.h"
#include "./sala.h"
#define CAPACIDAD_MAXIMA 2147483647

int capacity_sala = -1;
int* sala;
int ocupados = 0;

int crea_sala(int capacidad) {
    if(capacity_sala != -1 || CAPACIDAD_MAXIMA < capacidad) return -1;
    if(capacidad < 1) return -1;

    sala = (int*) calloc(capacidad, sizeof(int));
    if(sala == NULL) return -1;

    capacity_sala = capacidad;

    return capacity_sala;
}

int asientos_ocupados() {
    if(capacity_sala == -1) return -1;
    return ocupados;
}

int capacidad_sala () {
    if(capacity_sala == -1) return -1;
    return capacity_sala;
}

int asientos_libres() {
    if(capacity_sala == -1) return -1;
    return (capacity_sala - ocupados);
}

int estado_asiento(int id_asiento) {
    if(capacity_sala == -1) return -1;
    if(id_asiento < 1 || id_asiento > capacity_sala) return -1;
    id_asiento--;
    return sala[id_asiento];
}

int libera_asiento(int id_asiento) {
    if(capacity_sala == -1 || ocupados == 0) return -1;
    if(id_asiento < 1 || id_asiento > capacity_sala) return -1;
    id_asiento--;
    int status = sala[id_asiento];
    if(status == 0) return -1;
    sala[id_asiento] = 0;
    ocupados--;
    return status;
}

int reserva_asiento(int id_persona) {
    if(capacity_sala == -1) return -1;
    if(id_persona < 1) return -1;
    if(ocupados == capacity_sala) return -1;
    for(int i = 0; i < capacity_sala; i++) {
        if(sala[i] == 0) {
            sala[i] = id_persona;
            ocupados++;
            return (i+1);
        }
    }

    return -1;
}

int elimina_sala() {
    if(capacity_sala == -1) return -1;

    capacity_sala = -1;
    ocupados = 0;
    free(sala);
    return 0;
}