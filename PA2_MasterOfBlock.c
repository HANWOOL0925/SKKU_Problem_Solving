// 위쪽 단면에 문자열(M)이 새겨진 레고 블록으로 성벽을 쌓았을 때 성벽의 문자열(N)이 생긴다.
// (0 < M (블록 문자열의 길이) < 36), (M <= N (성벽의 문자열의 길이) < 1000)일 때,
// 성벽을 쌓기 위한 레고의 최소 개수와 성벽이 가질 수 있는 최소 높이를 구하라.
// 블록의 문자열들은 모두 같으며 순서를 바꿀 수 없다. 문자열 안에는 중복되는 문자가 존재하지 않으며 반드시 겹치는 부분이 존재한다.


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int block_length = 0;
int wall_length = 0;

char* block;
char* wall;

int answer_num = 0;
int answer_height = 0;

int index(char c) {
	int a = 0;
	for (a = 0; a < block_length; a++) {
		if (block[a] == c)
			return a;
	}
}

void calculator() {
	int* complete = 0;
	int* height = 0;
	int count = 0;
	int i = 0;
	int j = 0;
	int k = 0;
	int bount = 0;
	int comp = 0;

	complete = malloc(sizeof(int) * (wall_length / block_length + 1));
	height = malloc(sizeof(int) * (wall_length / block_length) * 2);

	for (i = 0; i < (wall_length / block_length) * 2; i++) {
		height[i] = 0;
	}

	for (i = 0; i <= wall_length - block_length; i++) {
		for (j = 0; j < block_length; j++) {
			if (wall[i + j] == block[j])
				bount++;
		}
		if (bount == block_length) {
			comp++;
			complete[k] = i;
			k++;
		}
		bount = 0;
	}
	complete[k] = wall_length;

	for (i = 0; i < complete[0]; i++) {
		if (wall[i] == block[0])
			height[0]++;
	}
	height[0]++;


	int a = 1;

	for (i = 0; i < 2 * comp - 1; i++) {
		height[i + 1] = height[i];
		for (k = complete[i / 2]; k < complete[i / 2 + 1]; k++) {
			if (i % 2 == 0) {
				if (wall[k] == block[block_length - 1]) {
					height[i + 1]--;
				}
				for (j = a; j < block_length; j++) {
					if (k == complete[i / 2] && wall[k - j] == block[0] && (j - index(wall[complete[i / 2] + block_length]) < 0)) {
						height[i + 1]--;
						if (j == block_length - 1)
							a = block_length;
					}
				}
			}
			if (i % 2 == 1) {
				if (wall[k] == block[0])
					height[i + 1]++;
			}
		}
	}

	height[2 * comp - 1]++;

	int min = 1;
	int max = 0;
	for (i = 0; i < 2 * comp; i++) {
		if (height[i] > max)
			max = height[i];
		if (height[i] < min)
			min = height[i];
	}
	if (min > 0)
		answer_height = max;
	else
		answer_height = max + abs(min) + 1;

	for (i = 0; i < wall_length; i++) {
		if (wall[i] == block[0] || wall[i] == block[block_length - 1])
			count++;
	}
	answer_num = count - 1;
}

int main()
{
	scanf("%d", &block_length);
	scanf("%d", &wall_length);

	block = malloc(sizeof(char) * (block_length + 1));
	wall = malloc(sizeof(char) * (wall_length + 1));
	scanf("%s", block);
	scanf("%s", wall);

	calculator();

	printf("%d\n", answer_num);
	printf("%d\n", answer_height);

	return 0;
}

/* BAD BBBADADABBAD 7 3
QWERT QWERQWEQWERTRQWERTWQWEQWERTWQWERTWERT 11 4

(1)
4 10
ASDF ASASASDFDF
4 3

(2)
4 10
ASDF ASDASASDFF
4 3

(3)
4 7
ASDF AAASDFF
4 4

(4)
4 11
ASDF ASDFDFDASDF
4 3

(5)
4 11
ASDF ASDFDASASDF
4 3

(6)
4 10
ASDF ASDFDASDFF
4 2

(7)
5 26
QWERT QQWERQWQWQWERTRQQQWEQWERTT
11 7
*/
