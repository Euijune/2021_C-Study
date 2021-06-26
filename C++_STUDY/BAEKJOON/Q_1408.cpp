#include <iostream>
#include <string>
using namespace std;

void calculTime (int time_onlysec);

int main() {
	int timeNow, timeQuestStart, ans = 0;
	int timeNow_h, timeNow_m, timeNow_s;
	int timeQuestStart_h, timeQuestStart_m, timeQuestStart_s;
	scanf_s("%d:%d:%d", &timeNow_h, &timeNow_m, &timeNow_s);
	scanf_s("%d:%d:%d", &timeQuestStart_h, &timeQuestStart_m, &timeQuestStart_s);
	
	timeNow = 3600 * timeNow_h + 60 * timeNow_m + timeNow_s;
	timeQuestStart = 3600 * timeQuestStart_h + 60 * timeQuestStart_m + timeQuestStart_s;
	
	if (timeNow < timeQuestStart) {
		ans = timeQuestStart - timeNow;
		calculTime(ans);
	}
	else if (timeNow > timeQuestStart) {
		ans = timeQuestStart + 86400 - timeNow;
		calculTime(ans);
	}

	return 0;
}

void calculTime(int time_onlysec) {
	int h, m, s;
	h = time_onlysec / 3600;
	time_onlysec -= h * 3600;
	m = time_onlysec / 60;
	time_onlysec -= m * 60;
	s = time_onlysec;

	printf("%02d:%02d:%02d", h, m, s);
}