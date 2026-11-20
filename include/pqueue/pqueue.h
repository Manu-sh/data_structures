#undef  CLASSNAME
#define CLASSNAME pqueue

#if !defined(TYPENAME) || !defined(TYPEID)
    #error "You must define a TYPENAME es. const int* and a TYPEID int_ptr"
#endif

#include "../details/generics/gbinary_heap/gbinary_heap.h"
#include "../details/generics/gbinary_heap/gbinary_heap.c"

/* YOU CAN PLACE YOUR CUSTOM EXTRA FUNCTIONS HERE ex:

   TYPENAME _(function_name)(const STRUCT *self) {
        return self->some_detail;
   }
*/

#undef TYPENAME
#undef TYPEID
#undef CLASSNAME
