#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>



int sort_shake(int* a, int size) {
	int flag = 1;
	int left = 0;
	int right = size - 1;
	int d = 0;
	while ((left < right) && flag > 0) {
		flag = 0;
		for (int i = left; i < right; i++) {
			if (a[i] > a[i + 1]) {
				d = a[i];
				a[i] = a[i + 1];
				a[i + 1] = d;
				flag = 1;
			}
		}
		right--;
		for (int i = right; i > left; i--) {
			if (a[i] < a[i - 1]) {
				d = a[i];
				a[i] = a[i - 1];
				a[i - 1] = d;
				flag = 1;
			}
		}
		left++;
	}
}


int sort_bubble(int* a, int size) {
	int d = 0;
	int M = size;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M - 1; j++) {
			if (a[j] > a[j + 1]) {
				d = a[j];
				a[j] = a[j + 1];
				a[j + 1] = d;
			}
		}
	}
}

void printmas(int* a, int size) {
	printf("Массив >\n");
	for (int i = 0; i < size; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}
void fillmas(int* a, int size) {
	srand(time(0));
	for (int i = 0; i < size; i++) {
		a[i] = ((float)rand() / RAND_MAX) * (15 - 0);
	}
}


int sort_insert(int* a, int size) {
	int* af;
	int max = 0;
	int I = 0;
	af = malloc(size * sizeof(int));
	for (int i = 0; i < size; i++) {
		af[i] = a[i];
	}
	for (int i = size - 1; i >= 0; i--) {
		max = 0;
		for (int j = 0; j < size; j++) {
			if (af[j] >= max) {
				max = af[j];
				I = j;
			}
		}
		af[I] = 0;
		a[i] = max;
	}
}

int sort_select(int* a, int size) {
	int d = 0;
	int j = 0;
	if (a[1] < a[0]) {
		d = a[0];
		a[0] = a[1];
		a[1] = d;
	}
	printmas(a, size);
	for (int i = 2; i < size;i++) {
		if (a[i] < a[i - 1]) {
			for (j = 0; j < size; j++) {
				if (a[j] > a[i]) {
					d = a[i];
					for (int z = i; z > j; z--) {
						a[z] = a[z - 1];
					}
					a[j] = d;
					break;
				}

			}

		}


	}

}

int task1() {
	int* a;
	int size;
	float t;
	float time;
	puts("Введите размер массива");
	scanf("%d", &size);
	a = malloc(size * sizeof(int));
	fillmas(a, size);
	printmas(a, size);
	sort_shake(a, size);
	printmas(a, size);
	t = clock(sort_shake(a, size));
	time = (clock(sort_shake(a, size)) - t) * 1.;
	printf("Время >>> %.2f", time);


	/*
	* выбором от 100 > 12.00
	* выбором от 1000 > 110.00
	* выбором от 10000 > 667.00
	пузырьком от 100 > 0.00
	пузырьком от 1000 > 3.00
	пузырьком от 10000 > 255.00
	шейком от 100 >0.00
	шейком от 1000 > 0.00
	шейком от 10000 > 0.00
	вставками от 100 > 0.00
	вставками от 1000 > 6.00
	вставками от 10000 > 361
	*/
}

void main() {
	setlocale(LC_ALL, "ru_RU");
	task1();
}