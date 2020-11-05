// N가지 종류의 두더지 M마리가 원형으로 나열되어 있다.
// 첫 두더지를 망치로 잡은 후, 그 두더지에 쓰여진 숫자만큼 건너 뛴 위치에 있는 두더지를 잡는다.
// 이를 계속 반복하여 두더지 게임을 진행할 때, 가장 먼저 사라지는 두더지의 종류는?
// (0 < length < 2000000)

#define _CRT_SECURE_NO_WARNIGS
#include <stdio.h>
#include <stdlib.h>

int first_eliminated_mole(int* m, int m_num) {
	int count = 0;
	int i = 0;
	int j = 0;

	int tmp = m[0];
	m[0] = 0;

	while (find_erased_num(m, tmp, m_num) != 0) {
		while (count != tmp + 1) {
			if (m[i % m_num] != 0) {
				count++;
			}
			i++;
		}
		count = 0;
		j = (i - 1) % m_num;
		tmp = m[j];
		m[j] = 0;
	}
	return tmp;
}

find_erased_num(int* m, int k, int m_num) {
	int ans = 0;
	for (int s = 0; s < m_num; s++) {
		if (m[s] & k == 0) {
			s = m_num;
			ans = 1;
		}
	}
	return ans;
}

int main() {
	int* m;
	int m_num = 0;

	scanf("%d", &m_num);
	m = (int*)malloc(sizeof(int)*m_num);

	for (int i = 0; i < m_num; i++) {
		scanf("%d", &m[i]);
	}
	printf("%d\n", first_eliminated_mole(m, m_num));
	free(m);

	return 0;
}