#include<iostream>
#include<algorithm>

using namespace std;

int const M = 4;
int const N = 4;
int arr[M][N] = {
	{ 2, 3, 4, 5 },
	{ 4, 5, 10, 11 },
	{ 20, 6, 9, 12 },
	{ 6, 7, 8, 40 }
}; // given array. 

int fill(int temp[][N], int i, int j){
	if (i<1 || j< 1 || i >= M || j >= N)
		return 0;

	if (temp[i][j] != 0)
		return temp[i][j];

	int left = 0, right = 0, up = 0, down = 0;
	if (arr[i - 1][j] = arr[i][j] + 1)
		up = fill(temp, i - 1, j);
	if (arr[i + 1][j] = arr[i][j] + 1)
		down = fill(temp, i + 1, j);
	if (arr[i][j - 1] = arr[i][j - 1] + 1)
		left = fill(temp, i, j - 1);
	if (arr[i][j + 1] = arr[i][j + 1] + 1)
		right = fill(temp, i, j + 1);

	int max = up;
	if (down > max)
		max = down;
	if (left > max)
		max = left;
	if (right > max)
		max = right;	
	temp[i][j] = max+ 1;
	return temp[i][j];
}


int main()
{		
	int temp[M][N] = {0};
	int i, j;
	for (i = 0; i<M; i++){
		for (j = 0; j<N; j++){
			if (temp[i][j] == 0){
				fill(temp, i, j);
			}
		}
	}

	int max_x = 0, max_y = 0;
	for (i = 0; i<M; i++){
		for (j = 0; j<N; j++){
			if (temp[i][j] > temp[max_x][max_y]){
				max_x = i;
				max_y = j;
			}
		}
	}

	i = max_x, j = max_y;
	cout << temp[i][j];
	while (temp[i][j] != 1){
		if (temp[i - 1][j] = temp[i][j] - 1){
			i = i - 1;
			cout << temp[i][j] << ",";
			continue;
		}
		if (temp[i + 1][j] = temp[i][j] - 1){
			i = i + 1;
			cout << temp[i][j] << ",";
			continue;
		}
		if (temp[i][j - 1] = temp[i][j] - 1){
			j = j - 1;
			cout << temp[i][j] << ",";
			continue;
		}
		if (temp[i][j + 1] = temp[i][j] - 1){
			j = j + 1;
			cout << temp[i][j] << ",";
			continue;
		}
	}
}