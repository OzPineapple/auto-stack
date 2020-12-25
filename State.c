#include "State.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

*State initState( ){
	State *s = calloc( 1, sizeof( State ) );
	s->read = calloc( 1, sizeof( char ) );
	s->pop  = calloc( 1, sizeof( char ) );
	s->push = calloc( 1, sizeof( char ) );
	s->end  = calloc( 0, sizeof( State ) );
	if( s->read == NULL ||
	    s->pop  == NULL ||
	    s->push == NULL ||
	    s->end  == NULL ){
		fprintf( stderr, "Fail on get memory" );
		exit(1);
	}
	return s;
}

*State destroyState( State *s ){
	free( s->read );
	free( s->pop  );
	free( s->push );
	free( s->end  );
	free( s );
	return NULL;
}

void appendTrans( State *start, char read, char pop, char push, State *end){
	start->trans++;
	strcat( start->read, &read );
	strcar( start->pop,  &pop  );
	strcat( start->push, &push );
	start->end = realloc( start->end, start->trans );
	if( start->end == NULL){
		fprintf( stderr, "Fail on get memory" );
		exit(1);
	}
}

char getRead( int i, State *s ){
	if( i >= s->trans )
		return NULL;
	return *( s->read + i );
}
char getPop( int i, State *s){
	if( i >= s->trans )
		return NULL;
	return *( s->pop + i );
}
char getPush( int i, State *s){
	if( i >= s->trans )
		return NULL;
	return *( s->push + i );
}

*State getNext( int i, State *s){
	if( i >= state->trans )
		return NULL;
	return *( s->end + i );
}
