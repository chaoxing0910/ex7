#include <stdio.h>
#define m 5   //Ͷ�ʵ�Ǯ(��)
#define n 4   //Ͷ�ʵ���Ŀ��
using namespace std;
int main() {
	int	f[100][100],max[100][100] = { 0 },p[100][100];//Ͷ�ʺ����棬������棬���� 
	for (int i = 0; i <= m; i++){ 
		for (int j = 1; j <= n; j++){
			scanf("%d", &f[j][i]);
		}
	}
	//0 0 0 0
	//11 0 2 20
	//12 5 10 21
	//13 10 30 22
	//14 15 32 23
	//15 20 40 24
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++){
			for (int k = 0; k <= j; k++){
				if (max[i][j] <= max[i - 1][j - k] + f[i][k]) {
					max[i][j] = max[i - 1][j - k] + f[i][k];
					p[i][j] = k;
				}
			}
		}
	}		
	printf("������棺%d\n���䷽�����£�\n",max[n][m]);
	int t = m;
	for (int i = n; i >= 1;i--) {
		printf("�������%d����Ŀ%d��\n",i,p[i][t]);
		t -= p[i][t];
	}
}
