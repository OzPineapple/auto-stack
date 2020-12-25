#ifndef STATE_H
#define STATE_H

typedef struct State_def {
	int trans;
	char *read;
	char *pop;
	char *push;
	struct State_def **end;
} State;

State* initState ( );
State* destroyState( State *s );
void appendTrans( State *start, char read, char pop, char push, State *end);
char getRead( int i, State *s);
char getPop( int i, State *s);
char getPush( int i, State *s);
State getNext( int i, State *s);

#endif
