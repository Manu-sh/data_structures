#undef  CLASSNAME
#define CLASSNAME dequeue

#if !defined(TYPENAME) || !defined(TYPEID)
    #error "You must define a TYPENAME es. const int* and a TYPEID int_ptr"
#endif

#include "../details/generics/gdlinked_list/gdlinked_list.h"

/* YOU CAN PLACE YOUR CUSTOM EXTRA FUNCTIONS HERE ex:

   TYPENAME _(function_name)(const STRUCT *self) {
        return self->some_detail;
   }
*/

#undef TYPENAME
#undef TYPEID
