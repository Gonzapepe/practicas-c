// array

GArray* garray_new(int capacity) {
	// Allocate size power of 2

	GArray* arr = malloc(sizeof(GArray));
	arr->size = 0;
	arr->capacity = capacity;
	arr->data = (int*)malloc(sizeof(int) * capacity);

	return arr;
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

void run_all_tests() {
	test_size_init();
	test_append();
	test_append_past_capacity();
	test_empty();
}

void test_append_past_capacity() {
	GArray* arrptr = garray_new(2);
	garray_append(arrptr, 100);
	garray_append(arrptr, 2);
	garray_append(arrptr, 10);
	int new_size = garray_size(arrptr);
	assert(new_size == 2);
	garray_destroy(arrptr);
}

void test_append() {
	GArray* arrptr = garray_new(2);
	garray_append(arrptr, 2);
	garray_append(arrptr, 5);
	int new_size = garray_size(arrptr);
	assert(new_size == 2);
	garray_destroy(arrptr);
}

void test_capacity() {
	GArray* arrptr = garray_new(3);
	garray_append(arrptr, 5);
	int capacity = garray_capacity(arrptr);
	assert(capacity == 3);
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