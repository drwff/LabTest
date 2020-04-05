#pragma once
#include"Windows.h"
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace std;
class Pr
{
protected:
	int x;
	int y;
	int a;
	int b;
public:
	Pr(int _x=0, int _y=0, int _a=0, int _b=0)
	{
		x = _x;
		y = _y;
		a = _a;
		b = _b;
	}
	~Pr() {};
	virtual void show(Graphics ^g) = 0;
	virtual void move(int dx) = 0;
};

