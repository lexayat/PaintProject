#include "storanges.h"
#include <stdexcept>
#include <math.h>

DynArrayPoint::DynArrayPoint(void)
{
	_Points = 0;
	_Size = 0;
}

void DynArrayPoint::Store(Point P)
{
	if (_Points == 0)
	{
		_Points = new Point;
		(*_Points).X = P.X;
		(*_Points).Y = P.Y;
		_Size++;
		//  _Points ->
	}
	else
	{
		Point *NewPoints = new Point[_Size + 1];

		//  Копируем старые элементы в новый массив
		for (unsigned s = 0; s < _Size; ++s)
		{
			NewPoints[s] = _Points[s];
		}

		//  Добавляем новый
		//  NewPoints[_Size] = P; - Равносильно
		NewPoints[_Size].X = P.X;
		NewPoints[_Size].Y = P.Y;

		//  Освобождаем занимаемую старыми элементами память
		delete[] _Points;

		//  Копируем обратно
		_Points = NewPoints;
		_Size++;
	}
}

Point DynArrayPoint::Get(unsigned num)
{
	if (num >= _Size) throw std::invalid_argument("Bad array index");
	return _Points[num];
}

Point *DynArrayPoint::Value(unsigned num)
{
	if (num >= _Size) throw std::invalid_argument("Bad array index");
	return _Points + num;

}
void DynArrayPoint::Set(unsigned num, Point P)
{
	if (num >= _Size ) throw std::invalid_argument("Bad array index");
	_Points[num] = P;
}
void DynArrayPoint::Drop(unsigned num)
{
	if (num >= _Size ) throw std::invalid_argument("Bad array index");

	Point *NewPoints = new Point[_Size -1];

	//  Копируем старые элементы в новый массив
	for (unsigned s = 0; s < num; ++s)
	{
		NewPoints[s] = _Points[s];
	}
	for (unsigned s = num + 1; s < _Size; ++s)
	{
		NewPoints[s - 1] = _Points[s];
	}

	//  Освобождаем занимаемую старыми элементами память
	delete[] _Points;

	//  Копируем обратно
	_Points = NewPoints;
	--_Size;
}
Point& DynArrayPoint::operator[] (unsigned num)
{
	if (num >= _Size) throw std::invalid_argument("Bad array index");
	return _Points[num];
}


//---------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------SECTIONS------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------


DynArraySect::DynArraySect(void)
{
	_Sections = 0;
	_Size = 0;
}

void DynArraySect::Store(Sect S)
{
	if (_Sections == 0)
	{
		_Sections = new Sect;
		(*_Sections).A.X = S.A.X;
		(*_Sections).A.Y = S.A.Y;
		(*_Sections).B.X = S.B.X;
		(*_Sections).B.Y = S.B.Y;
		_Size++;
		//  _Points ->
	}
	else
	{
		Sect *NewSections = new Sect[_Size + 1];

		//  Копируем старые элементы в новый массив
		for (unsigned s = 0; s < _Size; ++s)
		{
			NewSections[s] = _Sections[s];
		}

		//  Добавляем новый
		NewSections[_Size] = S;

		//  Освобождаем занимаемую старыми элементами память
		delete[] _Sections;

		//  Копируем обратно
		_Sections = NewSections;
		_Size++;
	}
}

Sect DynArraySect::Get(unsigned num)
{
	if (num >= _Size ) throw std::invalid_argument("Bad array index");
	return _Sections[num];
}

Sect *DynArraySect::Value(unsigned num)
{
	if (num >= _Size ) throw std::invalid_argument("Bad array index");
	return _Sections + num;
}
void DynArraySect::Set(unsigned num, Sect S)
{
	if (num >= _Size) throw std::invalid_argument("Bad array index");
	_Sections[num] = S;
}
void DynArraySect::Drop(unsigned num)
{
	if (num >= _Size) throw std::invalid_argument("Bad array index");


	Sect *NewSections = new Sect[_Size -1];

	//  Копируем старые элементы в новый массив
	for (unsigned s = 0; s < num; ++s)
	{
		NewSections[s] = _Sections[s];
	}
	for (unsigned s = num + 1; s < _Size; ++s)
	{
		NewSections[s - 1] = _Sections[s];
	}
	

	//  Освобождаем занимаемую старыми элементами память
	delete[] _Sections;

	//  Копируем обратно
	_Sections = NewSections;
	--_Size;
}
Sect& DynArraySect::operator[] (unsigned num)
{
	if (num >= _Size) throw std::invalid_argument("Bad array index");
	return _Sections[num];
}
//Make ortog sector
Sect DynArraySect::ort(unsigned num)
{
	if (num >= _Size) throw std::invalid_argument("Bad array index");
	Sect A;
	A.A.X = _Sections[num].B.Y;
	A.B.X = _Sections[num].A.Y;
	A.B.Y = _Sections[num].B.X;
	A.A.Y = _Sections[num].A.X;
	return A;
}
double DynArraySect::len(unsigned num)
{
	if (num >= _Size) throw std::invalid_argument("Bad array index");
	return sqrt((_Sections[num].B.X - _Sections[num].A.X)*(_Sections[num].B.X - _Sections[num].A.X) + (_Sections[num].B.Y - _Sections[num].A.Y)*(_Sections[num].B.Y - _Sections[num].A.Y));
}