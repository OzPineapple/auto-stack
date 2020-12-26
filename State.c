#include "State.h"
#include "util.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

State* initState( ){
	State *s = ecalloc( 1, sizeof( State ) );
	s->read  = initSentence();
	s->pop   = initSentence();
	s->push  = initSentence();
	s->end   = initSentence();
	return s;
}

State* destroyState( State *s ){
	destroySentence( s->read );
	destroySentence( s->pop  );
	destroySentence( s->push );
	destroySentence( s->end  );
	free( s );
	return NULL;
}

void addTrans( State *start, char *read, char *pop, char *push, State *end){
	int size = ++start->trans;

	addWord( read, start->read );
	addWord( pop,  start->pop  );
	addWord( push, start->push );
	addWord( end,  start->end  );
}

State* evalState( State *s, char *read ){
	
}

char* getRead( int i, State *s ){
	if( i >= s->trans )
		return NULL;
	return *( s->read + i );
}
char* getPop( int i, State *s){
	if( i >= s->trans )
		return NULL;
	return *( s->pop + i );
}
char* getPush( int i, State *s){
	if( i >= s->trans )
		return NULL;
	return *( s->push + i );
}

State* getNextState( int i, State *s){
	if( i >= s->trans )
		return NULL;
	return *( s->end + i );
}
