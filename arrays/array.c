#include <string.h>
// array

GArray* garray_new(int capacity) {
	// Allocate size power of 2

	int true_capacity = garray_determine_up_capacity(capacity);

	GArray* arr = malloc(sizeof(GArray));
	arr->size = 0;
	arr->capacity = true_capacity;
	arr->data = (int*)malloc(sizeof(int) * true_capacity);

	return arr;
}

void garray_resize_for_size(GArray* arrptr, int candidate_size) {
	if (arrptr->size < candidate_size) {
		if (arrptr->size == arrptr->capacity) {
			garray_upsize(arrptr);
		}
	}
	else if (arrptr->size > candidate_size) {
		if (arrptr->size < arrptr->capacity / 4) {
			garray_downsize(arrptr);
		}
	}
}

void garray_upsize(GArray* arrptr) {
	int old_capacity = arrptr->capacity;
	int new_capacity = garray_determine_up_capacity(old_capacity);

	printf("Resizing from %d to %d\n", old_capacity, new_capacity);

	int* new_data = (int*)malloc(sizeof(int) * new_capacity);

	for (int i = 0; i < old_capacity; i++) {
		*(new_data + i) = *(arrptr->data + i);
	}

	free(arrptr->data);

	arrptr->data = new_data;
	arrptr->capacity = new_capacity;
}

void garray_downsize(GArray* arrptr) {
	int old_capacity = arrptr->capacity;
	int new_capacity = old_capacity / 2;
	
	if (new_capacity < MinCapacity) {
		new_capacity = MinCapacity;
	}

	if (new_capacity != old_capacity) {
		printf("Resizing from %d to %d\n", old_capacity, new_capacity);
		int* new_data = (int*)malloc(sizeof(int) * new_capacity);

		for (int i = 0; i < arrptr->size; i++) {
			*(new_data + i) = *(arrptr->data + i);
		}
	}

	free(arrptr->data);

	arrptr->data = new_data;
	arrptr->capacity = new_capacity;
}

int garray_determine_up_capacity(int capacity) {
	const int MinInitialCapacity = 1
	int true_capacity = 16;

	if (capacity < MinInitialCapacity) {
		exit(EXIT_FAILURE);
	}
	int power = MinCapacity;
	while (capacity > power / 2) {
		power *= 2;
	}
	true_capacity = power;

	return true_capacity;
}

int garray_at(GArray* arrptr, int index) {
	if (index < 0 || index > arrptr->size - 1) {
		exit(EXIT_FAILURE);
	}
	return *(arrptr->data + index);
}


void garray_resize(GArray* arrptr) {
	int old_capacity = arrptr->capacity;
	int new_capacity = garray_determine_capacity(old_capacity);
	
	int* new_data = (int*)malloc(sizeof(int) * new_capacity);

	for (int i = 0; i < old_capacity; i++) {
		*(new_data + i) = *(arrptr->data + i);
	}
	
	free(arrptr->data);

	arrptr->data = new_data;
	arrptr->capacity = new_capacity;
}

int garray_size(GArray* arrptr) {
	return arrptr->size;
}

void garray_destroy(GArray* arrptr) {
	free(arrptr->data);
	free(arrptr);
}

bool garray_append(GArray* arrptr, int item) {
	int success = 0;

	if (arrptr->size == arrptr->capacity) {
		garray_resize(arrptr);
	}

	if (arrptr->size < arrptr->capacity) {
		*(arrptr->data + arrptr->size) = item;
		arrptr->size += 1;
		success = 1;
	}

	return success;
}


void garray_print(GArray* arrptr) {
	printf("Size: %d\n", arrptr->size);
	printf("Capacity: %d\n", arrptr->capacity);
	printf("Items: \n");

	for (int i = 0; i < arrptr->size; i++) {
		printf("%d: %d\n", i, *(arrptr->data + i));
	}

	printf("------------------\n");
}

int garray_capacity(GArray* arrptr) {
	return arrptr->capacity;
}

bool garray_is_empty(GArray* arrptr) {
	int is_empty = 0;

	if (arrptr->size == 0) {
		is_empty = 1;
	}

	return is_empty;
}

void garray_push(GArray* arrptr, int item) {
	garray_resize_for_size(arrptr, arrptr->size + 1);
	*(arrptr->data + arrptr->size) = item;
	++(arrptr->size);
}

void garray_insert(GArray* arrptr, int index, int value) {
	if (index < 0 || index> arrptr->size - 1) {
		exit(EXIT_FAILURE);
	}

	garray_resize_for_size(arrptr, arrptr->size + 1);

	//Mover items a la derecha

	int end_index = arrptr->size - 1;
	for (int i = end_index + 1; i > index; --i) {
		*(arrptr->data + i) = *(arrptr->data + i - 1);
	}
	//Despues de mover los items a la derecha insertar el valor
	*(arrptr->data + index) = value;

	arrptr->size += 1;
}



void run_all_tests() {
	test_size_init();
	test_append();
	test_resize();
	test_empty();
}


void test_append() {
	GArray* arrptr = garray_new(2);
	garray_append(arrptr, 2);
	garray_append(arrptr, 5);
	int new_size = garray_size(arrptr);
	assert(new_size == 2);
	garray_destroy(arrptr);
}

void test_at() {
	GArray* arrptr = garray_new(12);
	for (int i = 0; i < 12; i++) {
		garray_push(arrptr, i + 3);
	}
	assert(garray_at(arrptr, 6) == 9)
}

void test_empty() {
	GArray* arrptr = garray_new(3);
	int is_empty = garray_is_empty(arrptr);
	assert(is_empty == 1);
}

void test_size_init() {
	GArray* arrptr = garray_new(2);
	int initial_size = garray_size(arrptr);
	assert(initial_size == 0);
	garray_destroy(arrptr);
}
/*
void test_at() {
	GArray_arrptr = garray_new(3);
	int at_index = garray_at(2);
	assert(at_index == 2);
}
*/

void test_resize() {
	GArray* arrptr = garray_new(2);
	int old_capacity = garray_capacity(arrptr);
	assert(old_capacity == 16);
	for (int i = 0; i < 18; i++) {
		garray_append(arrptr, i + 1);
	}

	int new_capacity = garray_capacity(arrptr);
	assert(new_capacity == 32);
	garray_destroy(arrptr);
}
