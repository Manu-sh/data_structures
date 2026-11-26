#define GCOMMON_H

/* the following define is used only by gcommon.c */

/* CLASSNAME & TYPENAME MUST BE DEFINED BEFORE INCLUDING THIS HDR
   	example:
  		#define CLASSNAME vector
  		#define TYPEID char_ptr
  		#define TYPENAME char *
*/

/* #pragma once */
#include <stdbool.h>
#include <stddef.h>

#if !defined(CLASSNAME) || !defined(TYPENAME) || !defined(TYPEID)
/* #if !defined(CLASSNAME) || !defined(TYPENAME) || !defined(TYPEID) || !defined(SIZETYPE) */
   	#error "you must define CLASSNAME & TYPENAME & TYPEID"
#endif

#define EMPTY
#define UNDERSCORE _
#define TOKENPASTE(_A_, _B_, _C_) _A_ ## _B_ ## _C_
#define TKPASTE(_A_, _B_, _C_) TOKENPASTE(_A_, _B_, _C_)

#define _(_NAME_) TKPASTE(CLASSNAME, TKPASTE(UNDERSCORE, TYPEID, UNDERSCORE), _NAME_) /* _(popBack) -> vector_char_popBack */
#define STRUCT    TKPASTE(CLASSNAME, UNDERSCORE, TYPEID) /* example: vector_char */
/*
#define SIZE_TYPE TKPASTE(CLASSNAME, TKPASTE(UNDERSCORE, TYPEID, UNDERSCORE), SIZETYPE) // example: vector_char_size_t
*/
typedef struct STRUCT STRUCT;
/*
typedef SIZETYPE SIZE_TYPE;
*/

#ifndef LIKELY
    #define LIKELY(_EXP_)       __builtin_expect((_EXP_), 1)
#endif

#ifndef UNLIKELY
    #define UNLIKELY(_EXP_)     __builtin_expect((_EXP_), 0)
#endif
