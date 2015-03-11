

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

template<typename Item> class storage_template
{
public:
	//  �������� ���������
	storage_template(void)
	{
		_items = 0;;
		_size=0;
	};

	~storage_template(void)
	{
		if (_items)delete[] _items;
	}

	//  ���������� �������� (�����)
	void Store(Item);

	//  �������� �������
	Item Get(unsigned num);
	//  �������� �������
	void Set(unsigned num, Item P);
	Item *Value(unsigned num);
	//  ������� �������
	void Drop(unsigned num);
	//we can work with storage as an array
	Item& operator[] (unsigned num);


	//  
	unsigned Size()const
	{
		return _size;
	};

private:
	Item *_items;
	unsigned _size;
};