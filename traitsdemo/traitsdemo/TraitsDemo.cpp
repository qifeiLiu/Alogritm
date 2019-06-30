#include <iostream>
using namespace std;

template <typename T>
struct map
{
	typedef T value_type;
	typedef T& reference;
	typedef T* pointer;
};


template <typename T>
class Inter_1{
public:
	typedef T value_type;
	typedef T& reference;
	typedef T* pointer;
};

template <typename T>
class Inter_2{
public:
	typedef T value_type;
	typedef T& reference;
	typedef T* pointer;
};

template <typename T>
struct Traits<T *>{
	typedef T value_type;
	typedef T& reference;
	typedef T* pointer;
};

int main(void)
{
	map<int>::value_type a = 100.9;
	cout << a << endl;
	system("pause");
	return 0;
}