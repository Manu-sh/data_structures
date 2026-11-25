/* GFIFO.C */
#include "../ccommon.c"

#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>

typedef struct _(node) {
	struct _(node) *next;
	TYPENAME data;
} _(Node);

struct STRUCT {
	_(Node) *head;
	_(Node) *tail; /* point to a preallocated block without data */
	_(Node) *back; /* point to a valid block which may contain the last inserted value if !empty  */
	size_t length; /* for obvious reasons the tail isn't count as part of length */
};

/* in the worst case back point to head and that coincide with tail
(the pre-allocated block) (ls->back == ls->head == ls->tail)
so a->back it's a valid blk */

FORCED(inline) size_t    _(max_size)()                 { return SIZE_MAX; }
FORCED(inline) TYPENAME  _(back)(const STRUCT *ls)     { return ls->back->data;  }
FORCED(inline) size_t    _(length)(const STRUCT *ls)   { return ls->length;      }
FORCED(inline) bool      _(is_empty)(const STRUCT *ls) { return !ls->head->next; }
FORCED(inline) TYPENAME  _(top)(const STRUCT *ls)      { return ls->head->data;  } /* there is always at least 1 blk */

FORCED(inline) STRUCT * _(new)() {

    STRUCT *ls;
    if (UNLIKELY(!(ls = (STRUCT *)calloc(1, sizeof(STRUCT)))))
        return NULL;

    /* pre-allocation */
    if (UNLIKELY(!(ls->head = (_(Node) *)calloc(1, sizeof(_(Node)))))) {
        free(ls);
        return NULL;
    }

    ls->tail = ls->head;
    ls->back = ls->head;

    return ls;
}

FORCED(inline) void _(free)(STRUCT *ls) {

    _(Node) *next;

    if (!ls) return;

	while ((next = ls->head->next)) {
        free(ls->head);
        ls->head = next;
	}

	free(ls->head), free(ls);
}

FORCED(inline) bool _(push)(STRUCT *ls, const TYPENAME e) {

    _(Node) *next;

    /* pre-allocation */
    if (UNLIKELY(!(next = (_(Node) *)calloc(1, sizeof(_(Node))))))
        return false;

    /* save into a previous preallocated block */
    ls->tail->data = CAST_PTR(TYPENAME, e);
    ls->tail->next = next; /* NODE_PUSH_BACK() */

    /* tail must point to a preallocated block without data */
    ls->back = ls->tail;
    ls->tail = next;

    ++ls->length;
    return true;
}


FORCED(inline) TYPENAME  _(pop)(STRUCT *ls) {

	/* there is always at least one block */
    TYPENAME ret = ls->head->data;
    _(Node) *tofree = ls->head;

    if (!ls->head->next) { /* don't free nothing if is the last blk */
        /* ls->head->data = NULL; */
        ls->back       = ls->head;
        return ret;
    }

    ls->head = ls->head->next;
    free(tofree);

    --ls->length;
    return ret;

}



/* merge b to a, in case of success b pointer is set to NULL and
it return the result of merge (that is a) otherwise return NULL,
you can pass null safely to this function */

FORCED(inline) STRUCT * _(merge)(STRUCT *a, STRUCT **b) {

    if (!a || !b || !*b) return NULL;

    /* remove tail (the preallocated block without data) */
	if (a->length) free(a->tail);

	/* in the worst case back point to head and that coincide with tail
	(the pre-allocated block that doesn't contain data)
	(ls->back == ls->head == ls->tail) so a->back it's a valid blk */

	/* merge */
	a->back->next = (*b)->head;
	a->tail       = (*b)->tail;
	a->back       = (*b)->back;

    /* remember the tail isn't count as part of length */
    a->length += (*b)->length;

    /* free the container structure Fifo (not the nodes) */
    free(*b); *b = NULL;
    return a;
}
