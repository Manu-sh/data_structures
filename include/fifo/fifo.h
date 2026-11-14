#if !defined(TYPENAME) || !defined(TYPEID)
    #error "You must define a TYPENAME es. const int* and a TYPEID int_ptr"
#endif

#include "../generics/gslinked_list/gfifo.h"
#include "../generics/gslinked_list/gfifo.c"


#undef TYPENAME
#undef TYPEID
