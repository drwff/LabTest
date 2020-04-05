#pragma once
#include"Windows.h"
#include"Myline.h"
#include"math.h"
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace std;
class Myengine
{
private:
	Myline leftline;
	Myline midline;
	Myline rightline;
	double a;
	int r, R, xcl, ycl, ycr, xcr;
public:
	Myengine(int _x=0, int _y=0,int _h=1)
	{
		a = 1;
		r = _h;
		R = 2 * _h;
		xcl = _x + 2 * _h;
		xcr = _x + 10 * _h;
		ycl = _y + 2*_h;
		ycr = _y + 2 * _h;
		double xl = xcl + r * cos(a);
		double yl = ycl - r * sin(a);
		double xr = xcr + r * cos(a);
		double yr = ycr - r * sin(a);
		leftline = Myline(xcl, ycl, xl, yl);
		midline = Myline(xl, yl, xr, yr);
		rightline = Myline(xcr, ycr, xr, yr);
	}
	Myengine(const Myengine &tmp)
	{
		leftline = tmp.leftline;
		midline = tmp.midline;
		rightline = tmp.rightline;
		r = tmp.r;
		R = tmp.R;
		a = tmp.a;
		xcl = tmp.xcl;
		xcr = tmp.xcr;
		ycl = tmp.ycl;
		ycr = tmp.ycr;
	}
	Myengine &operator=(const Myengine tmp)
	{
		leftline = tmp.leftline;
		midline = tmp.midline;
		rightline = tmp.rightline;
		r = tmp.r;
		R = tmp.R;
		a = tmp.a;
		xcl = tmp.xcl;
		xcr = tmp.xcr;
		ycl = tmp.ycl;
		ycr = tmp.ycr;
		return *this;
	}
	void show(Graphics ^g)
	{
		leftline.show(g);
		rightline.show(g);
		midline.show(g);
	}
	void move(int dx)
	{
		a -= dx / (2 * 3.14);
		xcl += dx;
		xcr += dx;
		double xl = xcl + r * cos(a);
		double yl = ycl - r * sin(a);
		double xr = xcr + r * cos(a);
		double yr = ycr - r * sin(a);
		leftline = Myline(xcl, ycl, xl, yl);
		midline = Myline(xl, yl, xr, yr);
		rightline = Myline(xcr, ycr, xr, yr);
	}
};

