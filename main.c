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
#include <getopt.h>
#include "State.h"

char **names;
int final_state  = 0;
int auto_loaded  = 0;
int input_string = 0;

void usage(){
	die("usage: [-fs by final state] [-s read string]")
}

int main ( int argc, char *argv[] ){
	for( int i=0; i<argc; i++ )
		// Options that take no arguments
		if(!strcmp( argv[i], "-h"))
			usage();
		else if(!strcmp( argv[i], "-fs" )) // Automata by final state
			final_state = 1;
		else if(!strcmp( argv[i], "-s"  )) // Read string insted of file
			input_string = 1;
		else if(!strcmp( argv[i], "-f"  )){ // Load the automata from file
			if( !auto_loaded ){
				auto_loaded = 1;
				loadAuto(argv[++i]);
			}

		} else {
			if(input_string)
				evalAuto(argv[++i]);
			else{
				
			}
		}		
	return 0;
}
