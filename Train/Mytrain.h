#pragma once
#include"Windows.h"
#include"Myengine.h"
#include"Mytruba.h"
#include"Vagon.h"
#include"Myline.h"
#include"Paravoz.h"
#include"Myscep.h"
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace std;
class Mytrain
{
private:
	Paravoz p;
	Vagon *vag;
	Myscep *s;
	int n;
public:
	Mytrain(int _x, int _y, int _h , int _n)
	{
		n = _n;
		p = Paravoz(_x - 14 * _h, _y - 10 * _h, _h);
		vag = new Vagon[n];
		s = new Myscep[n];
		for (int i = 0; i < n; i++)
		{
			s[i] = Myscep(_x - (16 * _h*(i+1)), _y, _h);
			vag[i] = Vagon(_x - (14 * _h + 16 * _h*(i + 1)), _y - 10 * _h, _h);
		}
	}
	Mytrain(const Mytrain &tmp)
	{
		p = tmp.p;
		n = tmp.n;
		vag = new Vagon[n];
		s = new Myscep[n];
		for (int i = 0; i < n; i++)
		{
			s[i] = tmp.s[i];
			vag[i] = tmp.vag[i];
		}
	}
	~Mytrain()
	{
		delete[]s;
		delete[]vag;
	}
	Mytrain &operator=(Mytrain tmp)
	{
		if (n != tmp.n)
		{
			if (n != 0)
			{
				delete[]s;
				delete[]vag;
			}
			n = tmp.n;
			vag = new Vagon[n];
			s = new Myscep[n];
		}
		n = tmp.n;
		p= tmp.p;
		for (int i = 0; i < n; i++)
		{
			s[i] = tmp.s[i];
			vag[i] = tmp.vag[i];
		}
		return *this;
	}
	void show(Graphics ^g)
	{
		p.show(g);
		for (int i = 0; i < n; i++)
		{
			s[i].show(g);
			vag[i].show(g);
		}
	}
	void move(int dx)
	{
		p.move(dx);
		for (int i = 0; i < n; i++)
		{
			s[i].move(dx);
			vag[i].move(dx);
		}
	}

};

