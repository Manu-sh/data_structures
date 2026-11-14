#include "pqueue/pqueue_int.h"
#include "pqueue/pqueue_char.h"

/* change the < for different heap type */
/* #define MAX_HEAP */

bool lt(int a, int b)
{
	 return a < b;
}

#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

int main() {

	pqueue_int *hp;
	pqueue_char *hpc;
	int i;

	srand(time(0));
	hp = pqueue_int_new(lt);
	hpc = pqueue_char_new(NULL); /* TODO */

	assert(hp);


	for (i = 0; i < 100; i++)
		pqueue_int_add(hp, rand());

	printf("length: %d\n", pqueue_int_length(hp));

	while (!pqueue_int_isEmpty(hp))
		printf("%d\n", pqueue_int_remove(hp));

	pqueue_int_free(hp);
	pqueue_char_free(hpc); /* TODO */
	return 0;
}
