// class�� ������ ����.
#pragma once

#ifndef __CAR_H__ // if not define Car.h
#define __CAR_H__ // ifndef __CAR_H__ = true ���, define Car.h
                  // ���� �̹� define�Ǿ��ִٸ�, #endif���������� ��� �ڵ� ����.

/*
������� �ߺ����Թ����δ� 4,5��° ���� ������ �Է��ϰų�, 2��°���� �Է��ϸ�ȴ�.
�ٸ�, #pragma once�� visual C++ 5.0 �̻󿡼��� �����ϱ⶧���� ȣȯ�����鿡���� ��ó����(4,5��°)�� ����ϴ°��� ����.
*/

class Car
{

private:
    enum
    {
        ID_LEN = 20,
        MAX_SPD = 200,
        FUEL_STEP = 2,
        ACC_STEP = 10,
        BRK_STEP = 10
    };
    char gamerID[ID_LEN];
    int fuelGauge;
    int curSpeed;
public:
    void InitMembers(const char* ID, int fuel);
    void ShowCarState();
    void Accel();
    void Break();
};

#endif
