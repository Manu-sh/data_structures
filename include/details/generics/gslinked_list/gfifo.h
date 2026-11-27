#undef  CLASSNAME
#define CLASSNAME fifo
#include "../gcommon.h"

STRUCT * _(new)();
void     _(free)(STRUCT *ls);
TYPENAME _(back)(const STRUCT *ls);
TYPENAME _(top)(const STRUCT *ls);
size_t   _(length)(const STRUCT *ls);
bool     _(is_empty)(const STRUCT *ls);
size_t   _(max_size)(const STRUCT *ls);

bool     _(push)(STRUCT *ls, const TYPENAME e);
TYPENAME _(pop)(STRUCT *ls);

/* merge b to a, in case of success b pointer is set to NULL and
it return the result of merge (that is a) otherwise return NULL,
you can pass null safely to this function */
STRUCT * _(merge)(STRUCT *a, STRUCT **b);
