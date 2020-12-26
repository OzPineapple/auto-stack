/*
	INSTITUTO POLITECNICO NACIONAL
	ESCUELA SUPERIOR DE COMPUTO

	Automata pila

	Materia:
	Teoría computacional

	Profesor:
	Benjamín Luna Benoso

	Alumno:
	Cortés Piña Oziel

	Grupo:
	2CM5
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "State.h"
#include "Auto.h"
#include "util.h"

Auto *aut;
int final_state  = 0;
int auto_loaded  = 0;
int input_string = 0;

void run( char *input ){
	if(!auto_loaded){
		auto_loaded = 1;
		printf( "Loading automata: %s\n", input );
		aut = initAuto( input );
	} else {
		if(input_string)
			puts( evalStr(input, aut, final_state)? "Aceptada" : "Rechazada" ) ;
		else{
			FILE *file = efopen( input, "r" );
			char *read;
			size_t size = 0;
			while( getline( &read, &size, file ) > -1 )
				puts( evalStr( strsep(&read,"\n"), aut, final_state )? "Aceptada":"Rechazada" );
		}
		puts("\n");
	}
}

void
usage ( )
{
	die("usage: [-fs by final state] [-s read string]");
}

int main ( int argc, char *argv[] ){
	if( argc == 1 ) usage();
	for( int i=1; i<argc; i++ )
		// Options that take no arguments
		if(!strcmp( argv[i], "-h"))
			usage(); 
		else if(!strcmp( argv[i], "-fs" )) // Automata by final state
			final_state = 1;
		else if(!strcmp( argv[i], "-s"  )) // Read string insted of file
			input_string = 1;
		else 
			run(argv[i]); // Feed or create the automata
	return 0;
}
