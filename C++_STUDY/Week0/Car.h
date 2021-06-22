// class의 선언을 담음.
#pragma once

#ifndef __CAR_H__ // if not define Car.h
#define __CAR_H__ // ifndef __CAR_H__ = true 라면, define Car.h
                  // 만약 이미 define되어있다면, #endif이전까지의 모든 코드 무시.

/*
헤더파일 중복포함방지로는 4,5번째 줄의 내용을 입력하거나, 2번째줄을 입력하면된다.
다만, #pragma once는 visual C++ 5.0 이상에서만 동작하기때문에 호환성측면에서는 전처리기(4,5번째)를 사용하는것이 좋다.
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
