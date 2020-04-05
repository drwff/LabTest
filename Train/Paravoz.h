#pragma once
#include"Windows.h"
#include"Myengine.h"
#include"Mytruba.h"
#include"Vagon.h"
#include"Myline.h"
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace std;
class Paravoz
{
private:
	Vagon v;
	Myengine engine;
	Mytruba truba;
public:
	Paravoz(int _x=0, int _y=0, int _h=1) :v(_x, _y, _h) {
		engine = Myengine(_x+_h,_y+10*_h,_h);
		truba = Mytruba(_x + 10 * _h, _y - 4 * _h, _h);
	}
	~Paravoz() {};
	Paravoz &operator=(Paravoz tmp)
	{
		v = tmp.v;
		engine = tmp.engine;
		truba = tmp.truba;
		return *this;
	}
	Paravoz(const Paravoz &tmp)
	{
		v = tmp.v;
		engine = tmp.engine;
		truba = tmp.truba;
	}
	void show(Graphics ^g)
	{
		v.show(g);
		engine.show(g);
		truba.show(g);
	}
	void move(int dx)
	{
		v.move(dx);
		engine.move(dx);
		truba.move(dx);
	}
};

