// class 객체 생성 및 객체 활용
#include <iostream>
#include "Car.h"


int main(void)
{
    Car run99;
    run99.InitMembers("run99", 100);  // 클래스는 선언과 초기화를 분리해야 함
    run99.Accel(); // run99의 맴버 함수
    run99.Accel();
    run99.ShowCarState();
    run99.Break();
    run99.ShowCarState();

    Car sped77;
    sped77.InitMembers("sped77", 100);
    sped77.Accel();  // sped77의 맴버 함수
    sped77.Break();
    sped77.ShowCarState();

    system("pause");  // VC++ 에서만 필요

    return 0;
}