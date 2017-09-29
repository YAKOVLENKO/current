#include<iostream>
#include<vector>
#include <iomanip>
#include<string>
template <typename N>
class TVector
{
public:
	using value_type = N;
	using size_type = size_t;
	using iterator = value_type *;
	using reference = value_type&;
	using const_reference = const value_type&;
private:
	value_type * mass;
	int size = 0;
	int V = 0;
public:
	TVector()
	{
		mass = nullptr;
		size = 0;
		V = 10;
	};
	TVector(const TVector& obj)
	{
		size = obj.size;
		V = size;
		mass = new value_type[size];
		for (int i = 0; i < size; ++i)
		{
			mass[i] = obj.mass[i];
		}
	}
	TVector(const TVector&& obj)
	{
		size = obj.size;
		V = size;
		mass = obj.mass;
		
	}

	TVector& operator=(const TVector& obj)
	{
		if (this == &obj) return *this;
		size = obj.size;
		while (V < obj.size)
		{
			V *= 2;
		}
		delete[] mass;
		mass = new value_type[V];
		for (int i = 0; i < size; ++i)
			mass[i] = obj.mass[i];
		return *this
	}
	TVector&  operator=(const TVector&& obj)
	{
		if (this == &obj) return *this;
		size = obj.size;
		V = obj.V;
		mass = obj.mass;
		return *this;
	}

	~TVector()
	{
		delete[] mass;
		size = 0;
		V = 0;
	}
};

int main()
{
	system("pause");
	return 0;
}
