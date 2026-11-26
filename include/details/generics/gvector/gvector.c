/* GVECTOR.C */

#include "../gcommon.c"

#include <assert.h>
#include <stdint.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

struct STRUCT {
	TYPENAME *v;
	USZT idx;
	USZT capacity;
};

#if 0
#define ALIGN16(_X_) (((_X_)+(16)) & ~0x0f)
#endif

FORCED(inline) TYPENAME * _(data)(const STRUCT *vct)     { return vct->v;        }
FORCED(inline) bool       _(is_empty)(const STRUCT *vct) { return vct->idx == 0; }
FORCED(inline) USZT       _(length)(const STRUCT *vct)   { return vct->idx;      }
FORCED(inline) USZT       _(max_size)()                  { return (-1);      }
FORCED(inline) void       _(clear)(STRUCT *vct)          { vct->idx = 0;         }
FORCED(inline) USZT       _(capacity)(const STRUCT *vct) { return vct->capacity; }

/* vector random access */
FORCED(inline) TYPENAME _(access)(const STRUCT *vct, USZT at) { return vct->v[at]; }
FORCED(inline) void _(assign)(STRUCT *vct, USZT at, const TYPENAME e) { vct->v[at] = CAST_PTR(TYPENAME, e); }

FORCED(inline) bool _(resize)(STRUCT *vct, USZT len) {

	TYPENAME *nv = (TYPENAME *)realloc(vct->v, len * sizeof(TYPENAME ));
	if (UNLIKELY(!nv)) return false;

	vct->v = nv;
	vct->capacity = len;
	vct->idx = vct->idx >= len ? len : vct->idx;

	return true;
}

FORCED(inline) bool _(shrink_to_fit)(STRUCT *vct) {
	TYPENAME *nv = (TYPENAME *)realloc(vct->v, (vct->idx+1) * sizeof(TYPENAME ));
	if (UNLIKELY(!nv)) return false;
    vct->v = nv;
    vct->capacity = vct->idx+1;
	return true;
}

FORCED(inline) STRUCT * _(new)() {

	STRUCT *vct;

	if (UNLIKELY(!(vct = (STRUCT *)calloc(1, sizeof(STRUCT)))))
		return NULL;

	vct->capacity  = 10;
	if (UNLIKELY(!(vct->v = (TYPENAME *)malloc(vct->capacity*sizeof(TYPENAME ))))) {
		free(vct);
		return NULL;
	}

	return vct;
}

FORCED(inline) void _(free)(STRUCT *vct) {
	if (!vct) return;
	free(vct->v);
	free(vct);
}

FORCED(inline) bool _(push_back)(STRUCT *vct, const TYPENAME e) {

	/* doubling-halving: growUp */
	if (vct->idx >= vct->capacity-1) {
		TYPENAME *nv = (TYPENAME *)realloc(vct->v, (vct->capacity*2) * sizeof(TYPENAME ));
		if (UNLIKELY(!nv)) return false;

		vct->v = nv;
		vct->capacity *= 2;
	}

	vct->v[vct->idx++] = CAST_PTR(TYPENAME, e);
	return true;
}

FORCED(inline) bool _(push_back_all)(STRUCT *vct, const TYPENAME *v, USZT len) {

	const TYPENAME *end = v+len;

	if (vct->idx+len >= vct->capacity) {

		TYPENAME *nv = (TYPENAME *)realloc(vct->v, (vct->capacity+len) * sizeof(TYPENAME ));
		if (UNLIKELY(!nv)) return false;

		vct->v = nv;
		vct->capacity += len;
	}


	for (; v != end; ++v)
		vct->v[vct->idx++] = *((TYPENAME *)v); /* necessary cast for pointers */

	return true;
}

/* it dosn't check if vector is empty so you MUST check it calling vector_isEmpty() */
FORCED(inline) TYPENAME _(pop_back)(STRUCT *vct) {

    assert(vct->idx > 0);

	TYPENAME ret = vct->v[--vct->idx];

	/* doubling-halving: growDown */
	if (vct->capacity/4 > vct->idx) {
		TYPENAME *nv = (TYPENAME *)realloc(vct->v, (vct->capacity/2) * sizeof(TYPENAME ));
		if (UNLIKELY(!nv)) return ret; /* do nothing */

		vct->v = nv;
		vct->capacity /= 2;
	}

	return ret;
}

/* get back the old element */
FORCED(inline) TYPENAME _(replace)(STRUCT *vct, USZT at, const TYPENAME e) {
	TYPENAME ret = vct->v[at];
	return (vct->v[at] = (TYPENAME)e), ret;
}
