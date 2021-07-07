// class의 정의를 담음.
#include <iostream>
#include <cstring>
#include "Car.h"

using namespace std;

void Car::InitMembers(const char* ID, int fuel)
{
    strcpy_s(gamerID, ID);  // strcpy는 안전하지 않은 함수이므로 strcpy_s 사용
    fuelGauge = fuel;
    curSpeed = 0;
}

void Car::ShowCarState()
{
    cout << "소유자 ID: " << gamerID << endl;
    cout << "연료량: " << fuelGauge << "%" << endl;
    cout << "현재 속도: " << curSpeed << "km/h" << endl << endl;
}

void Car::Accel()
{
    if (fuelGauge <= 0)
        return;
    else
        fuelGauge -= FUEL_STEP;

    if (curSpeed + ACC_STEP >= MAX_SPD)
    {
        curSpeed = MAX_SPD;
        return;
    }
    curSpeed += ACC_STEP;
}

void Car::Break()
{
    if (curSpeed < BRK_STEP)
    {
        curSpeed = 0;
        return;
    }
    curSpeed -= BRK_STEP;
}