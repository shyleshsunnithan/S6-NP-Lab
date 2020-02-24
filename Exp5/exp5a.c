#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_t idAdd;

void* add(void *arg) {
	int a, b;
	printf("Enter Two Numbers : ");
	scanf("%d %d", &a, &b);
	printf("Sum = %d\n", a+b);
}

int main() {
	int i=0, err;
	err = pthread_create(&idAdd, NULL, &add, NULL);
	if (err != 0) {
		printf("Cant create thread now : [%s]\n", strerror(err));
	} else {
		printf("Thread has been created successfully\n");
	}
	err = pthread_join(idAdd, NULL);
	if (err != 0) {
		printf("Cant joining thread : [%s]\n", strerror(err));
	} else {
		printf("Thread has been finished successfully\n");
	}
	return 0;
}
