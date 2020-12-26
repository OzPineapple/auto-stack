#ifndef STATE_H
#define STATE_H

#include "Sentence.h"

typedef struct State_def {
	int trans;
	int isFinal;
	char *name;
	sentence* read;
	sentence* pop;
	sentence* push;
	struct State_def **end;
} State;

State* initState ( );
State* destroyState( State *s );
void addTrans( State *start, char *read, char *pop, char *push, State *end);
char* getRead( int i, State *s);
char* getPop( int i, State *s);
char* getPush( int i, State *s);
State* getNextState( int i, State *s);
State* evalState( State *s, char *c , char * stack);

#endif
