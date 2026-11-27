/* GBINARY_HEAP.C */

#include "../gcommon.c"

#include <stddef.h>
#include <stdint.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

/*
	parent: j/2
	lchild: 2i
	rchild: 2i+1

	the root is v[1], v[0] is empty
*/

struct STRUCT {
	TYPENAME *v;
	bool (*lt)(TYPENAME,TYPENAME);
	size_t idx;
	size_t capacity;
};


__helper void _(fixUp)(TYPENAME *v, bool (*lt)(TYPENAME,TYPENAME), size_t k) {

	while (k > 1 && lt(v[k>>1], v[k])) {
		SWAP(TYPENAME, v[k>>1], v[k]);
		k >>= 1;
	}
}

__helper void _(fixDown)(TYPENAME *v, bool (*lt)(TYPENAME,TYPENAME), size_t p, size_t to) {

    assert(p > 0 && p < SIZE_MAX);

#if 0
	for (int j; (j = p << 1) <= to; p = j) {

		/* get max or min depending of lt() behavior */
		/* j = j < to && lt(v[j], v[j+1]) ? j+1 : j; */
		if (j < to && lt(v[j], v[j+1])) ++j;

		if (lt(v[p], v[j]))
			SWAP(TYPENAME, v[p], v[j]);
		else break;
	}
#endif

#if 1
	size_t j = to;
	while ((p << 1) < to) {

		j = lt(v[p<<1], v[(p<<1)+1]) ? (p<<1)+1 : p << 1;

		if (lt(v[p], v[j]))
			SWAP(TYPENAME, v[p], v[j]);
		else break;
		p = j;
	}

	/* TODO work well but is ugly */
	if (p <= to && p != j && lt(v[p], v[j]))
		SWAP(TYPENAME, v[p], v[j]);
#endif

}


/* SIZE_MAX-1 because heap start at 1 */
FORCED(inline)	size_t _(max_size)(const STRUCT *hp) {
    (void)hp; // shutup unused warn
	return SIZE_MAX-1;
}

/* provide a less_than() or greater_then() function
respectively if you want max_heap or min_heap */

FORCED(inline) STRUCT * _(new)(bool (*lt)(TYPENAME,TYPENAME)) {

	STRUCT *hp;

	if (UNLIKELY(!(hp = (STRUCT *)malloc(1 * sizeof(STRUCT)))))
		return NULL;

	if (UNLIKELY(!(hp->v = (TYPENAME *)malloc((hp->capacity = 10) * sizeof(TYPENAME ))))) {
		free(hp);
		return NULL;
	}

	hp->idx = 0;
	hp->lt  = lt;

	return hp;
}


FORCED(inline) void _(free)(STRUCT *hp) {
	if (!hp) return;
	free(hp->v); free(hp);
}


FORCED(inline) bool _(is_empty)(const STRUCT *hp) {
	return hp->idx == 0;
}


/* retrieve but not remove the root */
FORCED(inline) TYPENAME  _(peek)(const STRUCT *hp) {
	assert(!_(is_empty)(hp));
	return hp->v[1];
}


/* number of elements that heap contains */
FORCED(inline) size_t _(length)(const STRUCT *hp) {
	 return hp->idx;
}


FORCED(inline) bool _(add)(STRUCT *hp, const TYPENAME e) {

	/* doubling-halving: growUp */
	if (hp->idx >= hp->capacity-1) {
		TYPENAME *nv = (TYPENAME *)realloc(hp->v, (hp->capacity*2) * sizeof(TYPENAME ));
		if (UNLIKELY(!nv)) return false;

		hp->v = nv;
		hp->capacity *= 2;
	}

	hp->v[++hp->idx] = CAST_PTR(TYPENAME, e);
	_(fixUp)(hp->v, hp->lt, hp->idx);

	return true;

}

/* it dosn't check if heap is empty so you MUST check it */
FORCED(inline) TYPENAME _(remove)(STRUCT *hp) {

    assert(!_(is_empty)(hp));

	TYPENAME ret;

	SWAP(TYPENAME, hp->v[1], hp->v[hp->idx]);
	_(fixDown)(hp->v, hp->lt, 1, hp->idx-1);
	ret = hp->v[hp->idx--];

	/* doubling-halving: growDown */
	if (hp->capacity/4 > hp->idx) {
		TYPENAME *nv = (TYPENAME *)realloc(hp->v, (hp->capacity/2) * sizeof(TYPENAME ));
		if (UNLIKELY(!nv)) return ret; /* do nothing */

		hp->v = nv;
		hp->capacity /= 2;
	}

	return ret;

}


/* replace the root with another element then fix the heap if is needed
return the previous root on success, NULL if an error is occurred.
More efficient than get followed by add, since only need to balance once,
not twice, and appropriate for fixed-size heaps. */

FORCED(inline) TYPENAME _(replace)(STRUCT *hp, const TYPENAME e) {

	TYPENAME  ret = CAST_PTR(TYPENAME, e);
	assert(!_(is_empty)(hp));

	SWAP(TYPENAME, ret, hp->v[1]);
	_(fixDown)(hp->v, hp->lt, 1, hp->idx-1);
	return ret;
}
