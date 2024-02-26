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


void ejecuta_tests ()
{
	test_ReservaBasica();
	// Añadir nuevos tests 
}

int main()
{
	puts("Iniciando tests...");
	
	ejecuta_tests();
	
	puts("Batería de test completa.");
    return 0;
}