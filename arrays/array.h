#ifndef PROJECT_ARRAY_H
#define PROJECT_ARRAY_H

typedef int bool;
const int MinCapacity = 16;

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
int garray_determine_up_capacity(int capacity);
int garray_at(GArray* arrptr, int index);
void garray_resize(GArray* arrptr);
void garray_push(GArray* arrptr, int item);

void run_all_tests();

void test_append();
void test_size_init();
void test_empty();
void test_resize();

#endif