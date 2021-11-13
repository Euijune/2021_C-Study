#include <iostream>

using namespace std;
typedef pair<int, int> pii;

int N;
pii arr[100001], * arr2;

void merge(int left, int right);
void partition(int left, int right);

int main() {
	// For fast I/O
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);

	cin >> N;
	arr2 = new pii[N];	// Cartesian Coordinate System 직교좌표계

	for (int i = 0; i < N; i++) {
		pii temp;
		cin >> temp.first >> temp.second;
		arr[i] = temp;
	}

	// merge sort
	partition(0, N - 1);

	for (int i = 0; i < N; i++)
		cout << arr[i].first << " " << arr[i].second << endl;

	delete arr2;
	
	return 0;
}

void merge(int left, int right) {
	int mid = (left + right) / 2;
	
	int i = left;
	int j = mid + 1;
	int k = left;
	while (i <= mid && j <= right) {
		if (arr[i].second < arr[j].second)	arr2[k++] = arr[i++];
		else if (arr[i].second == arr[j].second) {

			if (arr[i].first <= arr[j].first)
				arr2[k++] = arr[i++];
			else
				arr2[k++] = arr[j++];
		}
		else arr2[k++] = arr[j++];
			
	}

	int tmp = i > mid ? j : i;	// 분할된 어느 한 쪽이 배열범위를 넘어가면 멈추고, 남은원소(이미 정렬되어있음)를 뒤에 집어넣는다 

	while (k <= right)
		arr2[k++] = arr[tmp++];

	for (int i = left; i <= right; i++)
		arr[i] = arr2[i];
}

void partition(int left, int right) {
	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		partition(left, mid);
		partition(mid+1, right);
		merge(left, right);
	}
}