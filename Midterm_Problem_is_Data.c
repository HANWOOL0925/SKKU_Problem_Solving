// 배열이 쓰여진 두 텍스트 파일이 주어진다.
// 두 배열의 공통 부분의 개수를 구하여라.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define n1_max 15000000
#define n2_max 150000000

int n1[n1_max];
int n2[n2_max];

int input[3];
int n1_num;
int n2_num;

int answer = 0; //final common

// Find common part of two array and reserve at global variable 'answer' 
void find_common() {
	int i = 0;
	int j = 0;

	while (i < n1_num && j < n2_num) {
		if (n1[i] == n2[j]) {
			i++;
			j++;
			answer++;
		}
		else if (n1[i] < n2[j]) {
			i++;
		}
		else {
			j++;
		}
	}
}

int main()
{
	FILE *fp = fopen("sample1_answer.txt", "r");
	FILE *fp2 = fopen("sample1_n2.txt", "r");
	FILE *fp3 = fopen("sample1_n1.txt", "r");

	for (int i = 0; i < 3; i++) {
		fscanf(fp, "%d", &input[i]);
	}
	fclose(fp);

	n2_num = input[0];
	n1_num = input[1];
	int common = input[2]; //Correct Answer!

	for (int i = 0; i < n2_num; i++) {
		fscanf(fp2, "%d", &n2[i]);
	}

	for (int i = 0; i < n1_num; i++) {
		fscanf(fp3, "%d", &n1[i]);
	}

	fclose(fp2);
	fclose(fp3);

	find_common();

	printf("Real_Common : %d\n", common); //Real answer
	printf("Calculated_Common : %d\n", answer); //Your guess

	return 0;

}