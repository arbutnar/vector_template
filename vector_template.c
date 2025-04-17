#include <stdio.h>
#include <stdlib.h>

typedef struct vector {
	int     size;
	int     capacity;
	void    **arr;
} vector;

void    add_to_vector(vector *vec, void *el) {
	if (vec->size >= vec->capacity) {
		vec->capacity *= 2;
		vec->arr = realloc(vec->arr, vec->capacity * sizeof(void *));
		if (!vec->arr)
			return ;
	}
	vec->arr[vec->size++] = el;
}

vector *new_vector(int capacity) {
	vector *vec = malloc(sizeof(vector));
	if (!vec)
		return NULL;

	vec->size = 0;
	vec->capacity = capacity;
	vec->arr = malloc(capacity * sizeof(void *));
	if (!vec->arr)
		return NULL;
	return vec;
}

void    free_vector(vector *vec) {
    if (vec->arr)
		free(vec->arr);
	if (vec)
		free(vec);
}
