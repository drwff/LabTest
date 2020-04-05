#pragma once
#include"Windows.h"
#include"Myline.h"
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace std;
class Myscep:public Myline
{
public:
	Myscep(int _x=0,int _y=0,int _h=1) :Myline(_x, _y, _x + 2 * _h, _y) {};
	~Myscep() {};
	void show(Graphics ^g)
	{
		Pen^pen = gcnew Pen(Color::Black, 5);
		SolidBrush^brush = gcnew SolidBrush(Color::Black);
		g->DrawLine(pen, xl, yl, xr, yr);
	}
};

