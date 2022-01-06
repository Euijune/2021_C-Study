#include <iostream>
#include <vector>
using namespace std;

vector<int> RGB, _RGB;

int main() {
	// For Fast I/O
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	RGB = { 0,0,0 };

	int N, temp, pre_min, ans = 1000*1000;
	cin >> N;

	for (int i = 0; i < N; i++) {
		_RGB = { 0,0,0 };
		for (int j = 0; j < 3; j++) {
			cin >> temp;
			switch (j) {
			case 0:
				pre_min = min(RGB[1], RGB[2]);
				break;
			case 1:
				pre_min = min(RGB[0], RGB[2]);
				break;
			case 2:
				pre_min = min(RGB[0], RGB[1]);
				break;
			}
			//cout << "RGB[" << j << "] = " << temp << " + " << pre_min << endl;
			_RGB[j] = temp + pre_min;
		}
		copy(_RGB.begin(), _RGB.end(), RGB.begin());
		/*for (int k = 0; k < 3; k++)
			cout << RGB[k] << " ";
		cout << endl;*/
	}

	for (int elem : RGB)
		ans = min(ans, elem);
	cout << ans;

	return 0;
}