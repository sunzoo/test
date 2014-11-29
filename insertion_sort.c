#include <stdio.h>
#include <stddef.h>

/*
 * Assume a part of the array is sorted, 
 * Pick an element,
 * Traverse left and keep shifting elements right
 * until a position is found such that key is less than the element
 */
static void
insertion_sort (int *a, int size)
{
	int key, i, j;

	for (j = 1; j < size; j++) {
		key = a[j];
		i = j - 1;
		while (i >= 0 && a[i] > key) {
			a[i + 1] = a[i];
			i--;
		}
		a[i + 1] = key;
	}
}

int main (int argc, char **argv)
{
	int a[20], i, size;

	for (i = 0; argc > 1; argc--, i++) {
		a[i] = atoi(argv[i + 1]);
	}
	size = i;
	insertion_sort(a, size);
	for (i = 0; i < size; i++) {
		printf("%d\n", a[i]);
	}
}
