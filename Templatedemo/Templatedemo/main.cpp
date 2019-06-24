#include <iostream>
#include <string>
#include "MyArr.hpp"

using namespace std;

int main(void)
{
	Array<int, 5> myIntArr;

	for (int i = 0; i < myIntArr.size(); i++)
	{
		myIntArr.set(i * 10, i);
		cout << myIntArr[i] << endl;
	}
	system("pause");

	return 0;

}