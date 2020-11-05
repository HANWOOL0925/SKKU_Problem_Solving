// 일련의 숫자들이 주어질 때, 이를 알파벳으로 바꿀 수 있는 경우의 수를 출력하시오.
// ex) 12 -> AB or L이므로 2가지

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

long long num2eng(char* input) {
	long long int ans = -1;
	int i;
	int m = strlen(input);

	if (m == 1)
		ans = input[0] - '0' == 0 ? 0 : 1;
	else if (m == 2) {
		ans = (input[1] - '0' != 0 && 10 * (input[0] - '0') + (input[1] - '0') < 27) ? 2 : 1;
	}

	if (input[m - 1] - '0' == 0 && (input[m - 2] - '0' > 2 || input[m - 2] - '0' == 0) || input[0] - '0' == 0) {
		ans = 0;
	}

	if (ans < 0 && m > 2) {
		long long int* fibo = malloc(sizeof(long long int) * m);
		fibo[0] = input[m - 1] - '0' == 0 ? 0 : 1;
		if (input[m - 2] - '0' == 0)
			fibo[1] = 0;
		else if (fibo[0] == 0 || 10 * (input[m - 2] - '0') + (input[m - 1] - '0') > 26)
			fibo[1] = 1;
		else
			fibo[1] = 2;

		for (i = 3; i <= m; i++) {
			if (input[m - i + 1] - '0' == 0 && (input[m - i] - '0' > 2 || input[m - i] - '0' == 0)) {
				fibo[m - 1] = 0;
				i = m + 1;
			}
			else if (input[m - i] - '0' == 0)
				fibo[i - 1] = 0;
			else if (10 * (input[m - i] - '0') + (input[m - i + 1] - '0') > 26)
				fibo[i - 1] = fibo[i - 2];
			else
				fibo[i - 1] = fibo[i - 2] + fibo[i - 3];
		}
		ans = fibo[m - 1];
        free(fibo);
	}
	return ans;
}

int main() {
	char input[2000];
	scanf("%s", input);
	long long answer;
	//for (int i = 0; i < 300000; i++)
	answer = num2eng(input);
	printf("%lld", answer);
	return 0;
}