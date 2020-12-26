#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "State.h"
#include "util.h"

State* initState( ){
	State *s = ecalloc( sizeof( State  ), 1 );
	s->end   = ecalloc( sizeof( State* ), 1 );
	s->read  = initSentence();
	s->pop   = initSentence();
	s->push  = initSentence();
	s->name  = NULL;
	return s;
}

State* destroyState( State *s ){
	destroySentence( s->read );
	destroySentence( s->pop  );
	destroySentence( s->push );
	free( s->end );
	free( s );
	return NULL;
}

void addTrans( State *start, char *read, char *pop, char *push, State *end){
	start->trans++;

	start->end = erealloc( start->end, start->trans * sizeof(State));
	start->end[start->trans-1] = end;

	addWord( read, start->read );
	addWord( pop,  start->pop  );
	addWord( push, start->push );
}

State* evalState( State *s, char *read, char *stack ){
	int index = findWord( read, s->read );
	if(index == -1)
		die("Rejected: State \"%s\" didn't find the read \"%s\" transition", s->name,read);
	char *pop = getPop( index, s );
	if( !strcmp( stack + strlen(stack) - strlen(pop), pop ) ) {
		strcrop( stack, 0, strlen(pop) );
		strcat( stack, getPush( index, s ) );
		return s->end[index];
	}
	die("Rejected: Stack don't have on top \"%s\", Stack=%s", pop, stack );
	return NULL;
}

char* getRead( int i, State *s ){
	return nWord(i, s->read );
}
char* getPop( int i, State *s){
	return nWord(i, s->pop );
}
char* getPush( int i, State *s){
	return nWord(i, s->push );
}

State* getNextState( int i, State *s){
	if( i >= s->trans )
		die("Rejected: Overflow");
	return s->end[i];
}
