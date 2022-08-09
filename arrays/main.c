#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "array.h"
#include "array.c"

void run_example();

int main(int argc, char* argv[]) {
	run_all_tests();
	//run_example();
	
	return 0;
}

void run_example() {
	int capacity;

	printf("Enter how many numbers would you like to store: ");
	scanf_s("%d", &capacity);

	printf("You'll be storing %d numbers.\n", capacity);

	GArray* arrptr = garray_new(capacity);

	int append_success = 0;

	for (int d = 1; d <= capacity; d++) {
		append_success = garray_append(arrptr, d);
		if (!append_success) {
			printf("No more room.\n");
		}
	}

	garray_print(arrptr);

	garray_destroy(arrptr);
}