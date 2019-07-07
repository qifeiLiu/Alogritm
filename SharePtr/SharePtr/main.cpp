#include <iostream>
using namespace std;
/*多个指针指同一个资源，此时，资源的释放不能取决于一个对象的生命周期*/
/*只要还有指针在持有资源，那就一定不能释放，引用计数的由来*/
/*只要*/
/*shareptr*/
template<typename T> class SharePtr;
//定义计数模板
template<typename T>
class Res_Ptr{
private:
	T* res_p;//用以指向资源的裸指针
	int use_num;//
	Res_Ptr(T *p) : res_p(p), use_num(1)
	{
		cout << "构造函数" << endl;
    }
	~Res_Ptr()
	{
		delete res_p;
		cout << "Res_Ptr析构函数" << endl;
	}
	friend class SharePtr<T>;
};

//shareptr
template<typename T>
class SharePtr{
public:
	SharePtr(T *p, T i) :ptr(new Res_Ptr<T>(p)), val(1){
		cout << "SharedPtr的构造函数" << "use num "<<ptr->use_num<<endl;
	}
	SharePtr(const SharePtr& orig) :ptr(orig.ptr), val(orig.val){
		++ptr->use_num;
		cout << "SharePtr的拷贝构造函数: " << "use_num:" << ptr->use_num << endl;
	}
	~SharePtr(){
		cout << "SharePtr 的析构函数: " << "use_num:" << ptr->use_num << endl;
		if (--ptr->use_num == 0){
			delete ptr;
		}
	}
private:
	Res_Ptr<T>* ptr;//指向计数类 Res_ptr;
	T val;
};
//template <class T>
//class Myptr
//{
//private:
//	T* _ptr;
//public:
//	Myptr(T* p):_ptr(p){
//		cout << "构造时分配" << endl;
//	}
//	~Myptr()
//	{
//		cout << "析构时分配" << endl;
//		delete _ptr;
//	}
//
//	T& operator *()
//	{
//		return *_ptr;
//	}
//	T* operator ->()
//	{
//		return _ptr;
//	}
//};

int main(void)
{
	int a = 10;//局部变量-> 函数栈帧
	// local heap => new delete
	//跨 local heap / heap => 构造
	{
		SharePtr<int> p = SharePtr<int>(new int(24), 100);
	}
	


	system("pause");
}