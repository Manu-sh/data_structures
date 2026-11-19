#ifndef CLASSNAME
    #error "missing CLASSNAME macro definition"
#endif

#include "../ccommon.h"

STRUCT * _(new());
void _(free)(STRUCT *ls);

bool _(push_back)(STRUCT *ls, const TYPENAME e);
bool _(push_front)(STRUCT *ls, const TYPENAME e);

int  _(length)(const STRUCT *ls);
bool _(is_empty)(const STRUCT *ls);

TYPENAME _(front)(const STRUCT *ls);
TYPENAME _(back)(const STRUCT *ls);

TYPENAME _(pop_back)(STRUCT *ls);
TYPENAME _(pop_front)(STRUCT *ls);

/* merge b to a, in case of success b pointer is set to NULL and
it return the result of merge (that is a) otherwise return NULL,
you can pass null safely to this function */
STRUCT * _(merge)(STRUCT *a, STRUCT **b);
