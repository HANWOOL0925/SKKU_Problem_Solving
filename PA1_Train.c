// 폭주 기관차들의 위치 순서를 반영한 정수 배열(2<n<100)과 폭주기관차의 개수가 입력된다.
// 각 기관차의 절댓값은 성능을 의미하며 양수는 오른쪽, 음수는 왼쪽으로 달린다.
// 기관차가 서로 마주치면 낮은 성능의 기관차가 폭발할 때, 충분한 시간이 지난 뒤 살아남은 기관차를 위치 순서에 따라 출력하시오.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int* RunawayTrain(int n, int* trains) {
	int* result = (int*)malloc(sizeof(int)*n);
	int i, j, k;
	int count = 0;

	for (k = 0; k < n; k++) {
		for (i = 0; i < n - 1; i++) {
			if (trains[i] > 0 && trains[i + 1] < 0) {
				if (abs(trains[i]) < abs(trains[i + 1])) {
					for (j = i; j < n - 1; j++) {
						trains[j] = trains[j + 1];
					}
					trains[n - 1] = 0;
				}
				else if (abs(trains[i]) > abs(trains[i + 1])) {
					for (j = i + 1; j < n - 1; j++) {
						trains[j] = trains[j + 1];
					}
					trains[n - 1] = 0;
				}
				else {
					for (j = i; j < n - 2; j++)
						trains[j] = trains[j + 2];
					trains[n - 1] = 0;
					trains[n - 2] = 0;
				}
			}
		}
	}
	for (i = 0; i < n; i++)
		result[i] = trains[i];

	return result;
}

int main()
{
	int n;

	scanf("%d", &n);

	int *trains = malloc(sizeof(int) * (n));

	int i = 0;

	for (i = 0; i < n; i++)
		scanf("%d", &trains[i]);

	int* result = (int*)malloc(sizeof(int)*n);

	result = RunawayTrain(n, trains);

	for (i = 0; i < n; i++) {
		if (result[i] != 0)
			printf("%d\n", result[i]);
		else
			break;
	}
	free(trains);
	return 0;
}