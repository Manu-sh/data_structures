#include "dequeue/dequeue_char.h"
#include "dequeue/dequeue_int.h"
#include <stdio.h>


int main() {

	dequeue_char *v = dequeue_char_new();

	char i;
	int ch;

	for (i = 'a'; i <= 'z'; i++) {
		dequeue_char_push_back(v, i);
		printf("%c added\n", dequeue_char_back(v));
	}

	for (ch = '9'; ch >= '0'; ch--) {
		dequeue_char_push_front(v, ch);
		printf("-> %c added\n", dequeue_char_front(v));
	}


	puts("\nextract all elements from the top:\n");

	while (!dequeue_char_is_empty(v)) {
	    printf("-> %c popFront\n", dequeue_char_pop_front(v));
	}


	dequeue_char_free(v);
	return 0;
}
