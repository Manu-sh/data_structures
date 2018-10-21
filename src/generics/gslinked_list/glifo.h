#undef CLASSNAME
#define CLASSNAME lifo
#include "../hcommon.h"

STRUCT * _(new)();
void     _(free)(STRUCT *ls);
TYPENAME _(top)(STRUCT *ls);
TYPENAME _(back)(STRUCT *ls);
int      _(length)(STRUCT *ls);
bool     _(isEmpty)(STRUCT *ls);
int      _(maxSize)();

bool     _(push)(STRUCT *ls, const TYPENAME e);

// TODO test it
TYPENAME _(pop)(STRUCT *ls);

/* merge b to a, in case of success b pointer is set to NULL and
it return the result of merge (that is a) otherwise return NULL,
you can pass null safely to this function */
STRUCT * _(merge)(STRUCT *a, STRUCT **b);