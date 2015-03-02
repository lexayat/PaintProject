#include <math.h>

struct Point
{
	double X;
	double Y;
};
struct Sect
{
	Point A;
	Point B;
};

class DynArrayPoint
{
public:
	//  �������� ���������
	DynArrayPoint(void);

	//  ���������� �������� (�����)
	void Store(Point);

	//  �������� �������
	Point Get(unsigned num);
	//  �������� �������
	void Set(unsigned num, Point P);
	Point *Value(unsigned num);
	//  ������� �������
	void Drop(unsigned num);
	//we can work with storage as an array
	Point& operator[] (unsigned num);


	//  
	unsigned Size()const
	{
		return _Size;
	};

private:
	Point *_Points;
	unsigned _Size;
};

class DynArraySect
{
public:
	//Create dyn array
	DynArraySect(void);
	//Add section
	void Store(Sect S);
	//get section
	Sect Get(unsigned num);
	//Set el.
	void Set(unsigned num, Sect S);
	//get adres
	Sect *Value(unsigned num);
	//delete
	void Drop(unsigned num);
	//Ortogonal
	Sect ort(unsigned num);
	//get length of sector
	double len(unsigned num);

	Sect& operator[] (unsigned num);
	//������ ���-�� ��������� �������
	unsigned Size(){
		return _Size;
	}


private:
	Sect *_Sections;
	unsigned _Size;
};

