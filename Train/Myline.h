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
class Myline
{
protected:
	int xl, yl, xr, yr;
public:
	Myline(int _xl=0, int _yl=0, int _xr=0, int _yr=0)
	{
		xl = _xl;
		yl = _yl;
		xr = _xr;
		yr = _yr;
	}
	~Myline() {};
	void show(Graphics ^g)
	{
		Pen^pen = gcnew Pen(Color::Black, 5);
		SolidBrush^brush = gcnew SolidBrush(Color::Black);
		g->DrawLine(pen, xl, yl, xr, yr);
	}
	void move(int dx)
	{
		xl += dx;
		xr += dx;
	}
};

