#include "Auto.h"
#include "State.h"
#include <stdio.h>
#include <stdlib.h>

Auto* initAuto(  ){
	Auto *a = calloc( 1, sizeof( Auto ) );
	a->states = calloc( 1, sizeof( **State ) );
	a->names = calloc( 1, sizeof( **char ) );
	return a;
}
Auto* destroy( Auto *a ){
	free( a->states );
	free( a->names );
	free( a );
	return NULL;
}
void* addState( Auto *a, State *s, char *n ){
	a->size++;
	a->states = realloc( sizeof( **State ), a->size );
	a->names  = realloc( sizeof( **char  ), a->size );
	if( a->states == NULL || a->names == NULL ){
		fprintf( stderr, "Couldn't get memory" );
		exit(1);
	} 
	*( a->states + a->size - 2 ) = s;
	*( a->names  + a->size - 2 ) = n;
}
void delState( Auto *a, int i ){
	
}
Auto* getState( Auto *a, int i );
char* getName( Auto *a, int i );

