#undef  CLASSNAME
#define CLASSNAME priority_queue

#if !defined(TYPENAME) || !defined(TYPEID)
    // #define TYPENAME const huffman_node_t *
    // #define TYPEID const_huffman_node_t_p
    #error "You must define a TYPENAME es. const int* and a TYPEID int_ptr"
#endif

#include "../generics/gbinary_heap/gbinary_heap.h"
#include "../generics/gbinary_heap/gbinary_heap.c"


#undef TYPENAME
#undef TYPEID
