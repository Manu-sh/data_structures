#!/bin/bash

# example: ./generics-gen-fifo.sh "unsigned char *" int float

for typename in "${@}"; do
typeid=${typename// /_}
typeid=${typeid//\*/p}

cat > "fifo_${typeid}.h" << EOF
#undef TYPENAME
#undef TYPEID

#define TYPEID ${typeid}
#define TYPENAME ${typename}
#include "../../generics/gslinked_list/gfifo.h"
#include "../../generics/gslinked_list/gfifo.c"

#undef TYPENAME
#undef TYPEID
EOF
done
