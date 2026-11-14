#undef  CLASSNAME
#define CLASSNAME dequeue

#if !defined(TYPENAME) || !defined(TYPEID)
    // #define TYPENAME const huffman_node_t *
    // #define TYPEID const_huffman_node_t_p
    #error "You must define a TYPENAME es. const int* and a TYPEID int_ptr"
#endif

#include "../generics/gdlinked_list/gdlinked_list.h"
#include "../generics/gdlinked_list/gdlinked_list.c"


#undef TYPENAME
#undef TYPEID
