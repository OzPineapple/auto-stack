#ifndef AUTO_H
#define AUTO_H

#include "State.h"

typedef struct Auto_def {
	int size;
	struct State_def **states;
	char **names;
} Auto;

Auto* initAuto(  );
Auto* destroy( Auto *a );
Auto* addState( Auto *a, State *s, char *name );
void delState( Auto *a, int i );
Auto* getState( Auto *a, int i );
char* getName( Auto *a, int i );

#endif
