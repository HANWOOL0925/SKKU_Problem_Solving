// N개의 Gas Station이 직선 도로 위에 있다.
// 각 Gas Station에서 이동에 사용되는 가스를 충전할 수 있으며, 충전한 가스로 이동할 수 있는 최대 거리가 길이 N의 배열로 주어진다.
// 가스는 한 번 사용하면 남은 양과 상관없이 모두 연소될 때 주어진 배열로부터 0번 째 Station에 위치한 차량이 N-1번 째 Station으로 갈 수 있는지 출력하라.
// (0 < N (Gas Station의 수 < 2500)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define true 1
#define false 0

int isReachable(int *gasStation, int N) {
	int i = 0;
	int j = 0;
	int Max = 1;
	int k = 0;
	int result = 2;

	for (i = 0; Max != 0 && result == 2;) {
		Max = gasStation[i + 1];
		for (j = 1; j <= gasStation[i] && i + j < N; j++) {
			if (gasStation[i + j] >= Max) {
				Max = gasStation[i + j];
				k = i + j;
			}
		}
		if (Max == 0)
			result = 0;
		i = k;
		if (i == N - 1)
			result = 1;
	}

	return result;
}

int main()
{
	char *input = NULL;
	int in_tmp, N = 0;
	size_t size;
	char *ptr;
	int gasStation[2500];
	int result = true;

	getline(&input, &size, stdin);

	ptr = strtok(input, " ");
	while (ptr != NULL)
	{
		in_tmp = atoi(ptr);
		gasStation[N++] = in_tmp;

		ptr = strtok(NULL, " ");
	}
	result = isReachable(gasStation, N);
	printf("%s\n", (result ? "true" : "false"));

	return 0;
}