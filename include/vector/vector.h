#undef  CLASSNAME
#define CLASSNAME vector

#if !defined(TYPENAME) || !defined(TYPEID)
    #error "You must define a TYPENAME es. const int* and a TYPEID int_ptr"
#endif

#include "../details/generics/gvector/gvector.h"


/* YOU CAN PLACE YOUR CUSTOM EXTRA FUNCTIONS HERE ex:

   TYPENAME _(function_name)(const STRUCT *self) {
        return self->some_detail;
   }
*/

#include <assert.h>

/* define an extra method back() that should be inlined */
FORCED(inline) TYPENAME _(back)(const STRUCT *vct) {
	assert(!_(is_empty)(vct));
	return vct->v[ _(length)(vct)-1 ];
}


#undef TYPENAME
#undef TYPEID
