#include "stdafx.h"
#include "Car.h"
#include <assert.h>
#include "test.h"

void Test()
{
	CCar Car;

	//�������� ����������� ������
	  //��� ���������, ���������� �� ��������� � ��������� �����
	assert(Car.TurnOnEngine() == true);
	assert(Car.GetDirection() == Direction::STANDING_STILL);
	assert(Car.GetGear() == Gear::NEUTRAL);
	//�������� ���������� ������
	assert(Car.TurnOnEngine() == false);
	//��������� ���������� ������
	assert(Car.TurnOffEngine() == true);
	//��������� ����������� ������
	assert(Car.TurnOffEngine() == false);

	//��������� ������ ��� ������� ��������
	Car.TurnOnEngine();
	assert(Car.GetSpeed() == 0);
	assert(Car.TurnOffEngine() == true);

	//��������� ������ ��� �� ������� ��������
	Car.TurnOnEngine();
	assert(Car.SetGear(1) == true);
	assert(Car.SetSpeed(20) == true);
	assert(Car.TurnOffEngine() == false);

	CCar Car2;
	//������� ��������� ��� ����������� ���������
	assert(Car2.SetGear(0) == true);
	//������� 3-� ��� ����������� ���������
	assert(Car2.SetGear(3) == false);

	//����������� ������ �������� �� ������ ��� ������� ��������
	Car2.TurnOnEngine();
	Car2.SetGear(-1);
	assert(Car2.SetGear(1) == true);
	//����������� ������ �������� �� ������ ��� �� ������� ��������
	Car2.SetGear(-1);
	assert(Car2.SetSpeed(10) == true);
	assert(Car2.SetGear(1) == false);

	//�������������� �� ������ ���� �� ����������� �������� �� ��������� ��������, ������������� �� ������ �������� ����� ���������
	//�������������� �� ������ ���� �� ����������� �������� �� ��������� ��������, ������������� �� ������ �������� �� ���������
	CCar Car3;
	Car3.TurnOnEngine();
	Car3.SetGear(-1);
	Car3.SetSpeed(10);
	Car3.SetGear(0);
	assert(Car3.SetGear(1) == false);
	Car3.SetSpeed(0);
	assert(Car3.SetGear(1) == true);

	CCar Car4;
	//�������� �������� � �������� ��������� ��������� ��������
	Car4.TurnOnEngine();
	Car4.SetGear(1);
	assert(Car4.SetSpeed(20) == true);
	//�������� �������� ��� ������� ��������� ��������� ��������
	assert(Car4.SetSpeed(50) == false);
	//����������� �������� � ��������� ���������
	assert(Car4.SetGear(2) == true);
	//����������� �������� ��� ��������� ���������
	assert(Car4.SetGear(3) == false);
}