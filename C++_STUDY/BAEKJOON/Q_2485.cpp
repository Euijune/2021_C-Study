#include <iostream>
using namespace std;

int gcd(int, int);

int main() {
	// For Fast I/O
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, MIN, MAX, currLoc, predLoc, gcf_dist, curr_dist;
	
	// Init value
	gcf_dist = -1;
	curr_dist = -1;
	predLoc = -1;
	currLoc = -1;
	MIN = 1000000000;
	MAX = 0;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> currLoc;
		MIN = min(MIN, currLoc);
		MAX = max(MAX, currLoc);
		curr_dist = predLoc == -1 ? -1 : currLoc - predLoc;

		if (gcf_dist != -1)
			gcf_dist = gcd(gcf_dist, curr_dist);
		else if (curr_dist != -1)
			gcf_dist = curr_dist;

		predLoc = currLoc;
	}
	cout << ((MAX - MIN) / gcf_dist - ((N - 2) + 1));

	return 0;
}

int gcd(int a, int b) { 
	return (a % b == 0 ? b : gcd(b, a % b)); 
}
