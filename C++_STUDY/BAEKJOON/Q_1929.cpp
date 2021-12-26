#include <iostream>
using namespace std;

int M, N;
bool is_primes[1000001];

int find_true(int& sp) {
	for (int i = sp; i <= N; i++)
		if (is_primes[i] == true) {
			sp = i + 1;
			return i;
		}

	return -1;
}

int main() {
	// For Fast I/O
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int Indx, sp = 2;
	cin >> M >> N;

	memset(is_primes, true, (N+1) * sizeof(bool));

	is_primes[0] = false;
	is_primes[1] = false;
	
	/*for (int i = M; i <= N; i++) {
		cout << is_primes[i] << " ";
	}
	cout << endl;*/
	
	Indx = find_true(sp);
	do {
		for (int i = Indx * 2; i <= N; i += Indx)
			is_primes[i] = false;

		/*for (int i = M; i <= N; i++) {
			cout << is_primes[i] << " ";
		}
		cout << endl;*/

		Indx = find_true(sp);
	} while (Indx != -1);
	
	for (int i = M; i <= N; i++) {
		if (is_primes[i] == true)
			cout << i << '\n';
	}

	return 0;
}