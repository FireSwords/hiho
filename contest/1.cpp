#include <cstdio>

int a[3][3];

int count_row(int row) {
	return (a[row][0]!=0)+(a[row][1]!=0)+(a[row][2]!=0);
}

int count_col(int col) {
	return (a[0][col]!=0)+(a[1][col]!=0)+(a[2][col]!=0);
}

int count_cross1() {
	return (a[0][0]!=0)+(a[1][1]!=0)+(a[2][2]!=0);
}

int count_cross2() {
	return (a[0][2]!=0)+(a[1][1]!=0)+(a[2][0]!=0);
}

int main(void) {
	int zerocnt = 0;
	int i,j;
	for (i=0; i<3; ++i)
		for (j=0; j<3; ++j) {
			scanf("%d", &a[i][j]);
			if (a[i][j]==0) zerocnt++;
		}
	if (a[1][1]==0) {
	    a[1][1] = 5;
	    zerocnt--;
	}
	
	int flag = 1;
	while (flag) {
		int num;
		
		int flag1 = 0;
		for (i=0; i<3; ++i) {
			if (count_row(i)==2) {
				num = 15-a[i][0]-a[i][1]-a[i][2];
				if (a[i][0]==0) a[i][0]=num;
				if (a[i][1]==0) a[i][1]=num;
				if (a[i][2]==0) a[i][2]=num;
				zerocnt--;
				flag1 = 1;
			}
		}	
		
		int flag2 = 0;
		for (j=0; j<3; ++j) {
			if (count_col(j)==2) {
				num = 15-a[0][j]-a[1][j]-a[2][j];
				if (a[0][j]==0) a[0][j]=num;
				if (a[1][j]==0) a[1][j]=num;
				if (a[2][j]==0) a[2][j]=num;
				zerocnt--;
				flag2 = 1;
			}
		}
		
		int flag3 = 0;
		if (count_cross1()==2) {
			num = 15-a[0][0]-a[1][1]-a[2][2];
			if (a[0][0]==0) a[0][0]=num;
			if (a[1][1]==0) a[1][1]=num;
			if (a[2][2]==0) a[2][2]=num;
			zerocnt--;
			flag3 = 1;
		}
		
		int flag4 = 0;
		if (count_cross2()==2) {
			num = 15-a[0][2]-a[1][1]-a[2][0];
			if (a[0][2]==0) a[0][2]=num;
			if (a[1][1]==0) a[1][1]=num;
			if (a[2][0]==0) a[2][0]=num;
			zerocnt--;
			flag4 = 1;
		}

		flag = flag1 + flag2 + flag3 + flag4;
	}
	
	if (zerocnt==0)
		for (i=0; i<3; ++i) {
			printf("%d %d %d\n", a[i][0], a[i][1], a[i][2]);
		}
	else
		printf("Too Many\n");	
	return 0;
}
