#pragma once
#include"Windows.h"
#include"Pr.h"
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace std;
class Mytruba:public Pr
{
public:
	Mytruba(int _x=0, int _y=0, int _h=1) :Pr(_x, _y, 2 * _h, 4 * _h) {};
	void show(Graphics ^g)
	{
		Pen^pen = gcnew Pen(Color::Black, 5);
		SolidBrush^brush = gcnew SolidBrush(Color::Black);
		g->DrawRectangle(pen, x, y, a, b);
		g->FillRectangle(brush, x, y, a, b);
	}
	void move(int dx)
	{
		x += dx;
	}
};

