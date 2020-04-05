#pragma once
#include"Windows.h"
#include"Pr.h"
#include"Mybody.h"
#include"Mydoor.h"
#include"Mycircle.h"
#include"Mywindow.h"
#include"Myengine.h"
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace std;
class Vagon
{
private:
	Mybody body;
	Mydoor door;
	Mycircle lcircle, rcircle;
	Mywindow *wind;
public:
	Vagon(int _x=0, int _y=0, int _h=1)
	{
		body = Mybody(_x, _y, _h);
		door = Mydoor(_x, _y + 3 * _h, _h);
		lcircle = Mycircle(_x + _h, _y + 10 * _h, _h);
		rcircle = Mycircle(_x + 9 * _h, _y + 10 * _h, _h);
		wind = new Mywindow[3];
		for (int i = 0; i < 3; i++)
		{
			wind[i] = Mywindow(_x + 5 * _h + 3 * _h*i, _y + 3 * _h,_h);
		}
	}
	Vagon(const Vagon &tmp)
	{
		body = tmp.body;
		door = tmp.door;
		lcircle = tmp.lcircle;
		rcircle = tmp.rcircle;
		wind = new Mywindow[3];
		for (int i = 0; i < 3; i++)
		{
			wind[i] = tmp.wind[i];
		}
	}
	~Vagon()
	{
		delete[]wind;
	}
	Vagon &operator=(const Vagon tmp)
	{
		body = tmp.body;
		door = tmp.door;
		lcircle = tmp.lcircle;
		rcircle = tmp.rcircle;
		for (int i = 0; i < 3; i++)
		{
			wind[i] = tmp.wind[i];
		}
		return *this;
	}
	void show(Graphics ^g)
	{
		body.show(g);
		door.show(g);
		rcircle.show(g);
		lcircle.show(g);
		for (int i = 0; i < 3; i++)
		{
			wind[i].show(g);
		}
	}
	void move(int dx)
	{
		body.move(dx);
		door.move(dx);
		rcircle.move(dx);
		lcircle.move(dx);
		for (int i = 0; i < 3; i++)
		{
			wind[i].move(dx);
		}
	}
};

