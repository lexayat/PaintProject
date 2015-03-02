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
	//  Создание хранилища
	DynArrayPoint(void);

	//  Добавление элемента (точка)
	void Store(Point);

	//  Получить элемент
	Point Get(unsigned num);
	//  Изменить элемент
	void Set(unsigned num, Point P);
	Point *Value(unsigned num);
	//  Удалить элемент
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
	//узнать кол-во элементов массива
	unsigned Size(){
		return _Size;
	}


private:
	Sect *_Sections;
	unsigned _Size;
};

