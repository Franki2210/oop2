#include "stdafx.h"
#include "Car.h"
#include <assert.h>
#include "test.h"

void Test()
{
	CCar Car;

	//Включить выключенный движок
	  //При включении, автомобиль на нейтралке в состоянии покоя
	assert(Car.TurnOnEngine() == true);
	assert(Car.GetDirection() == Direction::STANDING_STILL);
	assert(Car.GetGear() == Gear::NEUTRAL);
	//Включить включенный движок
	assert(Car.TurnOnEngine() == false);
	//Выключить включенный движок
	assert(Car.TurnOffEngine() == true);
	//Выключить выключенный движок
	assert(Car.TurnOffEngine() == false);

	//Выключить движок при нулевой скорости
	Car.TurnOnEngine();
	assert(Car.GetSpeed() == 0);
	assert(Car.TurnOffEngine() == true);

	//Выключить движок при не нулевой скорости
	Car.TurnOnEngine();
	assert(Car.SetGear(1) == true);
	assert(Car.SetSpeed(20) == true);
	assert(Car.TurnOffEngine() == false);

	CCar Car2;
	//Врубить нейтралку при выключенном двигателе
	assert(Car2.SetGear(0) == true);
	//Врубить 3-ю при выключенном двигателе
	assert(Car2.SetGear(3) == false);

	//Переключить заднюю передачу на первую при нулевой скорости
	Car2.TurnOnEngine();
	Car2.SetGear(-1);
	assert(Car2.SetGear(1) == true);
	//Переключить заднюю передачу на первую при не нулевой скорости
	Car2.SetGear(-1);
	assert(Car2.SetSpeed(10) == true);
	assert(Car2.SetGear(1) == false);

	//Переключившись на заднем ходу на нейтральную передачу на ненулевой скорости, переключиться на первую передачу после остановки
	//Переключившись на заднем ходу на нейтральную передачу на ненулевой скорости, переключиться на первую передачу до остановки
	CCar Car3;
	Car3.TurnOnEngine();
	Car3.SetGear(-1);
	Car3.SetSpeed(10);
	Car3.SetGear(0);
	assert(Car3.SetGear(1) == false);
	Car3.SetSpeed(0);
	assert(Car3.SetGear(1) == true);

	CCar Car4;
	//Изменить скорость в пределах диапазона скоростей передачи
	Car4.TurnOnEngine();
	Car4.SetGear(1);
	assert(Car4.SetSpeed(20) == true);
	//Изменить скорость вне предела диапазона скоростей передачи
	assert(Car4.SetSpeed(50) == false);
	//Переключить передачу в диапазоне скоростей
	assert(Car4.SetGear(2) == true);
	//Переключить передачу вне диапазона скоростей
	assert(Car4.SetGear(3) == false);
}