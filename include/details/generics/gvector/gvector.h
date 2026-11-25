#undef  CLASSNAME
#define CLASSNAME vector

#include "../ccommon.h"

STRUCT * _(new)();
void _(free)(STRUCT *vct);

bool       _(is_empty)(const STRUCT *vct);
size_t     _(length)(const STRUCT *vct);
size_t     _(max_size)();
void       _(clear)(STRUCT *vct);
bool       _(resize)(STRUCT *vct, size_t len);
size_t     _(capacity)(const STRUCT *vct);
bool       _(shrink_to_fit)(STRUCT *vct);
TYPENAME * _(data)(const STRUCT *vct);

/* TODO ellipsi ? */
bool _(push_back_all)(STRUCT *vct, const TYPENAME *v, size_t len);
bool _(push_back)(STRUCT *vct, const TYPENAME e);

/* it dosn't check if vector is empty so you MUST check it calling vector_char_isEmpty() */
TYPENAME  _(pop_back)(STRUCT *vct);

/* vector random access */
TYPENAME  _(access)(const STRUCT *vct, size_t at);
void  _(assign)(STRUCT *vct, size_t at, const TYPENAME e);

/* get back the old element */
TYPENAME _(replace)(STRUCT *vct, size_t at, const TYPENAME e);
