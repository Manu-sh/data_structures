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
   	#error "you must define CLASSNAME & TYPENAME & TYPEID"
#endif

#define EMPTY
#define UNDERSCORE _
#define TOKENPASTE(_A_, _B_, _C_) _A_ ## _B_ ## _C_
#define TKPASTE(_A_, _B_, _C_) TOKENPASTE(_A_, _B_, _C_)

#define _(_NAME_) TKPASTE(CLASSNAME, TKPASTE(UNDERSCORE, TYPEID, UNDERSCORE), _NAME_) /* _(popBack) -> vector_char_popBack */
#define STRUCT    TKPASTE(CLASSNAME, UNDERSCORE, TYPEID) /* example: vector_char */
typedef struct STRUCT STRUCT;

/*
il problema qui è che le classi non contemplavano di raggiungere mai realmente la quantità massima di elementi inseribili
nemmeno sulla capacity, di conseguenza è possibile che vada in overflow usando tipi custom piccoli come uint8_t per le lunghezze

#if !defined(USIZETYPE)
    #error "you must define CLASSNAME & TYPENAME & TYPEID & USIZETYPE"
    typedef USIZETYPE _(USIZETYPE); // example: size_t -> vector_char_size_t
    #define USZT _(USIZETYPE)
#endif
*/

#ifndef LIKELY
    #define LIKELY(_EXP_)       __builtin_expect((_EXP_), 1)
#endif

#ifndef UNLIKELY
    #define UNLIKELY(_EXP_)     __builtin_expect((_EXP_), 0)
#endif
