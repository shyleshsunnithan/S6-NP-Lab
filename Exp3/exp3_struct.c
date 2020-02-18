#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

#define BUFF_SIZE 15


struct student_data {
	int rno;
	char name[BUFF_SIZE];
	char branch[BUFF_SIZE];
} s;

int trim(char buff[]) {
	buff[strcspn(buff, "\r\n")] = 0;
}

int main() {
	
	int fd, i, n, rno, found=0;
	char buff[BUFF_SIZE];
	//struct student* s = &students;

	fd = open("students.txt", O_RDWR | O_CREAT | O_TRUNC, 0755);
	printf("Enter number of students : ");
	fgets(buff, BUFF_SIZE, stdin);
	trim(buff);
	n = atoi(buff);

	for (i=0; i<n; i++) {
		printf("Student No. %d\n", i+1);

		printf("Enter Roll.no : ");
		fgets(buff, BUFF_SIZE, stdin);
		trim(buff);
		s.rno = atoi(buff);

		printf("Enter Name : ");
		fgets(s.name, BUFF_SIZE, stdin);
		trim(s.name);

		printf("Enter Branch Name: ");
		fgets(s.branch, BUFF_SIZE, stdin);
		trim(s.branch);

		write(fd, (char*)&s, sizeof(struct student_data));
		printf("\n");
		
	}

	lseek(fd, 0, SEEK_SET);
	printf("Enter Roll.no of Student to Read : ");
	fgets(buff, BUFF_SIZE, stdin);
	rno = atoi(buff);
	printf("\n");

	for(i=0; i<n; i++) {
		read(fd, (char*)&s, sizeof(struct student_data));
		if (s.rno == rno) {
			found = 1;
			printf("Student Details Found!!\n");
			printf("Name : %s\n", s.name);
			printf("Branch : %s\n", s.branch);
			break;
		}
	}
	if (!found) {
		printf("Student Details Not Found!!!\n");
	}

	close(fd);
	return 0;
	
}
