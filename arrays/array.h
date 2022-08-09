#ifndef PROJECT_ARRAY_H
#define PROJECT_ARRAY_H

typedef int bool;

typedef struct ImplementationArray {
	int size;
	int capacity;
	int* data;
} GArray;

// Array functions

GArray* garray_new(int capacity);
void garray_destroy(GArray* arrptr);

int garray_size(GArray* arrptr);
bool garray_append(GArray* arrptr, int item);
void garray_print(GArray* arrptr);
int garray_capacity(GArray* arrptr);
bool garray_is_empty(GArray* arrptr);

void run_all_tests();

void test_append();
void test_size_init();
void test_append_past_capacity();
void test_capacity();
void test_empty();
#endif