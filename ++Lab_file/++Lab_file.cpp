

#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
void problem1();
void problem2();
void problem3();

int main()
{
	//problem1();
	//problem2();
	problem3();

	return 0;
}

/*Дан текстовый файл. Необходимо создать
новый файл, в который переписать из
исходного файла все слова, состоящие не менее
чем из семи букв*/
void WriteToFile(char* path, FILE * file, char*buf) {
	if ((file = fopen(path, "w")) == NULL) {
		perror("Invalid File is not Open!");
	}
	else {
		fprintf(file, "%s", "Words: ");
		char* pch = strtok(buf, " ,.-!?:;@#%"); // во втором параметре указаны разделитель (пробел, запятая, точка, тире)
		while (pch != NULL)                         // пока есть лексемы
		{
			
			if (strlen(pch) >= 7)
			{
				fprintf(file, "%s", pch);
				fprintf(file, "%c", ' ');
			}
			pch = strtok(NULL, " ,.-!?:;@#%");
		}
		fclose(file);
	}
		
}
char* ReadFile(char* path, FILE* file) {


	char *buf= new char[1000];
	if ((file = fopen(path, "r")) == NULL) {
		perror("Invalid File is not Open!");
	}
	else {
		int counter = 0;
		while (fgets(buf, 1000, file)) {
			counter++;
		}
		cout << counter << " lines was reading!" << endl;
		fclose(file);
	}
	return buf;
}

void problem1()
{
	char inst1[] = "file1.txt";
	char inst2[] = "file2.txt";
	FILE* file = NULL;
	//char buf[1000];
	char* buf = ReadFile(inst1, file);
	WriteToFile(inst2, file, buf);

}



bool FromFileToFile() {

	FILE* file_from, * file_to;

	char buf[1000];
	char path_from[] = "file1.txt";
	char path_to[] = "file2.txt";

	if ((file_from = fopen(path_from, "r")) == NULL) {
		perror("Invalid File is not Open!");
		return false;
	}
	if ((file_to = fopen(path_to, "w")) == NULL) {
		perror("Invalid File is not Open!");
		return false;
	}
	while (fgets(buf, 1000, file_from))
	{
		fputs(buf, file_to);
	}


	fclose(file_from);
	fclose(file_to);

}

void problem2() {

	FromFileToFile();
}

bool BackFile() {
	FILE* F1, * F2;
	char ch, sl[1000], sl2[1000], c;
	if ((fopen_s(&F1, "1.txt", "r")) != 0)
	{
		printf("Invalid File is not Open!\n");
		return 0;
	}
	if ((fopen_s(&F2, "2.txt", "w+")) != 0) {
		printf("Invalid File is not Open!\n");
		return 0;
	}
	while (!feof(F1))
	{
		int N, i;
		fgets(sl, 1000, F1);
		N = strlen(sl);

		i = N;
		for (i = N - 1; i > 0; i--)
			if (sl[i] != '\n')
				fprintf(F2, "%c", sl[i]);

		fprintf(F2, "%c", sl[0]);
		fprintf(F2, "%c", '\n');
	}
	fclose(F1);
	fclose(F2);
	return 0;

}
void problem3() {
	BackFile();
}
