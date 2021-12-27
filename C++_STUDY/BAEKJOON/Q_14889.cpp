#include <iostream>
#include <cmath>
#include <memory.h>
using namespace std;

int N;
int table[20][20];
int* start_team;
int* link_team;

int find_teamPower(int* team) {
	int pw = 0;
	
	for (int i = 0; i < N / 2; i++) {
		int row = team[i];
		for (int j = 0; j < N / 2; j++) {
			int col = team[j];
			pw += table[row][col];
		}
	}

	return pw;
}

void make_link_team() {
	int* link = new int[N];
	memset(link, 0, N * sizeof(int));

	for (int i = 0; i < N / 2; i++) {
		int indx = start_team[i];
		link[indx] = 1;
	}

	int indx = 0;
	for (int i = 0; i < N; i++) {
		if (link[i] == 0) {
			link_team[indx] = i;
			indx++;
		}
	}

	delete[] link;
}

int main() {
	int temp, min = 10000;
	int pw_start, pw_link;
	
	cin >> N;
	start_team = new int[N / 2];
	link_team = new int[N / 2];
	memset(start_team, 0, (N / 2) * sizeof(int));
	memset(link_team, 0, (N / 2) * sizeof(int));
	for (int i = 0; i < N / 2; i++)
		start_team[i] = i;

	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) {
			cin >> temp;
			table[row][col] = temp;
		}
	}

	int sp = N / 2 - 1;
	
	while (true) {
		make_link_team();
		pw_start = find_teamPower(start_team);
		pw_link = find_teamPower(link_team);
		int sub = abs(pw_start - pw_link);
		min = min > sub ? sub : min;


		if (start_team[0] == N - (N / 2))
			break;

		start_team[sp]++;
		while (sp >= 0 &&start_team[sp] == sp + N / 2 + 1 ) {
			/*cout << "Not Printed : ";
			for (int i = 0; i < N / 2; i++)
				cout << start_team[i] << " ";
			cout << endl;*/

			sp--;
			//cout << "sp = " << sp << ". sp+N/2+1 = " << sp + N / 2+1 << "\n";
			start_team[sp]++;
			for (int j = sp + 1; j < N/2; j++)
				start_team[j] = start_team[j - 1] + 1;
		}
		sp = N / 2 - 1;		
	}
	cout << min;

	delete[] start_team;
	delete[] link_team;

	return 0;
}