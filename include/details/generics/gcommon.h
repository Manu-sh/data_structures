/*
    THIS HEADER SHOULD INCLUDED MULTIPLE TIMES, ONE FOR EACH GENERIC
 */

/* CLASSNAME & TYPENAME MUST BE DEFINED BEFORE INCLUDING THIS HDR
	example:
		#define CLASSNAME vector
		#define TYPEID char_ptr
		#define TYPENAME char *
*/

#include "common/common.h"

#define __helper static FORCED(inline)

#define SWAP(_TYPENAME_,A,B)          \
	do {                      \
		_TYPENAME_ _tmp_ = A; \
		A = B;            \
		B = _tmp_;        \
	} while(0)

/* #pragma once */
#include <stdbool.h>

#if !defined(CLASSNAME) || !defined(TYPENAME) || !defined(TYPEID)
	#error "you must define CLASSNAME & TYPENAME & TYPEID"
#endif

#define EMPTY
#define UNDERSCORE _
#define TOKENPASTE(_A_, _B_, _C_) _A_ ## _B_ ## _C_
#define TKPASTE(_A_, _B_, _C_) TOKENPASTE(_A_, _B_, _C_)

#define _(_NAME_) TKPASTE(CLASSNAME, TKPASTE(UNDERSCORE, TYPEID, UNDERSCORE), _NAME_) /* _(popBack) -> vector_char_popBack */
#define STRUCT    TKPASTE(CLASSNAME, UNDERSCORE, TYPEID) /* example: vector_char */
typedef struct STRUCT STRUCT;
