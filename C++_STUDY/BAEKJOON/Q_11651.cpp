#include <iostream>

using namespace std;
typedef pair<int, int> pii;

int main() {
	// For fast I/O
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);

	int N;
	cin >> N;
	pii* CCS = new pii[N];	// Cartesian Coordinate System 직교좌표계

	for (int i = 0; i < N; i++) {
		pii temp;
		cin >> temp.first >> temp.second;
		CCS[i] = temp;
	}

	// merge sort
	...


	for (int i = 0; i < N; i++)
		cout << CCS[i].first << " " << CCS[i].second << endl;

	delete[] CCS;
	
	return 0;
}