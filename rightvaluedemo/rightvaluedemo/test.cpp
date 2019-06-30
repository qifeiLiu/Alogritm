#include <iostream>

using namespace std;

class A{

public:
	A(int num){
		p = new int(num);
	}
	A(const A& r){
		cout << "A(A&)" << endl;
		p = new int;
		*(p) = *(r.p);

	}

	A(A&& r){
		cout << "A(A&&)" << endl;
		p = r.p;
		r.p = nullptr;


	}
	~A(){
		if (p != NULL)
		{
			delete p;
		}
	}
	void show_p(){
		cout <<p<<" "<<*p<< endl;
	}
private:
	int *p;
};

A func(){
	A a(100);
	return a;
}

int main()
{
	//int a = 1;
	//int b = 2;
	//int && c = a + b;
	//c++;
	//cout << "c=" << c << endl;
	A b(100);
	A x(b);
	b.show_p();
	x.show_p();
	A  f(func());
	f.show_p();
	system("pause");
	return 0;
}