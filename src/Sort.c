/*
 ============================================================================
 Name        : Sort.c
 Author      : Adam
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

typedef struct
{
	int r[MAXSIZE+1];
	int length;
}SqList;


void swap(SqList *L, int i, int j)
{
	int temp = L->r[i];
	L->r[i] = L->r[j];
	L->r[j] = temp;
}

void initData(SqList *L, int *arr, int len)
{
	int i = 0;

	for(i = 0; i < len; i++) {
		L->r[i] = arr[i];
	}
	L->length = len;
}

void BubbleSort0(SqList *L)
{
	int i, j;
	for(i = 0; i < L->length; i++) {
		for(j = i+1; j < L->length; j++) {
			if(L->r[i] > L->r[j]) {
				swap(L, i, j);
			}
		}
	}
}

void BubbleSort(SqList *L)
{
	int i, j;
	for(i = 0; i < L->length; i++) {
		for(j = L->length-1; j >= i; j--) {
			if(L->r[i] > L->r[j+1]) {
				swap(L, i , j+1);
			}
		}
	}
}

void InsertSort(SqList *L)
{
	int i, j;
	for(i = 2; i <= L->length; i++) {
		if(L->r[i] < L->r[i-1]) {
			L->r[0] = L->r[i];
			for(j = i-1; L->r[j] > L->r[0]; j--) {
				L->r[j+1] = L->r[j];
			}
			L->r[j+1] = L->r[0];
		}
	}
}

int main(void)
{
	int array[6] = {0, 5, 3, 4, 6, 2};
	SqList *L = NULL;
	int i;

	L = (SqList *)malloc(sizeof(SqList));

	initData(L, array, 6);

	printf("before sort....\n");
	for(i = 0; i < L->length; i++) {
		printf("%d ", L->r[i]);
	}
	printf("\n");
	InsertSort(L);
	printf("after sort....\n");
	for(i = 0; i < L->length; i++) {
		printf("%d ", L->r[i]);
	}
	return EXIT_SUCCESS;
}
