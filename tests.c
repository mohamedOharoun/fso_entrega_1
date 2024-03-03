#include "stdio.h"
#include "sala.h"

#include <assert.h>

#define DebeSerCierto(x)	assert(x)
#define DebeSerFalso(x)		assert(!(x))

void INICIO_TEST (const char* titulo_test)
{
  printf("********** batería de pruebas para %s: ", titulo_test); 
 	// fflush fuerza que se imprima el mensaje anterior
	// sin necesidad de utilizar un salto de línea
	fflush(stdout);
}

void FIN_TEST (const char* titulo_test)
{
  printf ("********** hecho\n");
}


void test_ReservaBasica()
{
	int mi_asiento;
	#define CAPACIDAD_CUYAS 500
	#define ID_1 1500
	INICIO_TEST("Reserva básica");
    	DebeSerCierto(elimina_sala() == -1);
	crea_sala(CAPACIDAD_CUYAS);
	DebeSerCierto(capacidad_sala()==CAPACIDAD_CUYAS);
	DebeSerCierto((mi_asiento=reserva_asiento(ID_1))>=0);
	DebeSerCierto((asientos_libres()+asientos_ocupados())==CAPACIDAD_CUYAS);
	DebeSerCierto(estado_asiento(mi_asiento)>0);
	DebeSerCierto(libera_asiento(mi_asiento)==ID_1);
	DebeSerCierto((asientos_libres()+asientos_ocupados())==CAPACIDAD_CUYAS);
	elimina_sala();
	DebeSerCierto(crea_sala(2147483648) == -1);
	FIN_TEST("Reserva básica");
}

void test_extra()
{
	INICIO_TEST("Extra");
	crea_sala(CAPACIDAD_CUYAS);
	// compruebo que no se puede crear más de 1 sala
	DebeSerCierto(crea_sala(200) == -1);
	// compruebo que la capacidad es la correcta
	DebeSerCierto(capacidad_sala() == CAPACIDAD_CUYAS);
	// intento reservar todos los asientos
	for(int i = 0; i < capacidad_sala(); i++){
		reserva_asiento(i+1);
		// Se comprueba que el estado del asiento tiene la id correspondiente.
		DebeSerCierto(estado_asiento(i+1)==i+1);
	}
	// si los he reservado todos no puede quedar ninguno libre
	DebeSerCierto(asientos_libres()==0);
	// intento reservar más asientos de los que hay disponibles
	DebeSerCierto(reserva_asiento(capacidad_sala()+1) == -1);
	elimina_sala();	
	crea_sala(CAPACIDAD_CUYAS);
	// intento liberar un asiento que ya está libre
	DebeSerCierto(libera_asiento(5) == -1);
	elimina_sala();	
	// Si se intenta eliminar de nuevo una sala
	DebeSerCierto(elimina_sala() == -1);
	// Si se intenta crear una sala con una capacidad superior al límite permitido.
	DebeSerCierto(crea_sala(2147483648) == -1);

	FIN_TEST("Extra");
}

void ejecuta_tests ()
{
	test_ReservaBasica();
	// Añadir nuevos tests
	test_extra();
}

int main()
{
	puts("Iniciando tests...");
	
	ejecuta_tests();
	
	puts("Batería de test completa.");
    return 0;
}