#include <iostream>
using namespace std;
/*���ָ��ָͬһ����Դ����ʱ����Դ���ͷŲ���ȡ����һ���������������*/
/*ֻҪ����ָ���ڳ�����Դ���Ǿ�һ�������ͷţ����ü���������*/
/*ֻҪ*/
/*shareptr*/
template<typename T> class SharePtr;
//�������ģ��
template<typename T>
class Res_Ptr{
private:
	T* res_p;//����ָ����Դ����ָ��
	int use_num;//
	Res_Ptr(T *p) : res_p(p), use_num(1)
	{
		cout << "���캯��" << endl;
    }
	~Res_Ptr()
	{
		delete res_p;
		cout << "Res_Ptr��������" << endl;
	}
	friend class SharePtr<T>;
};

//shareptr
template<typename T>
class SharePtr{
public:
	SharePtr(T *p, T i) :ptr(new Res_Ptr<T>(p)), val(1){
		cout << "SharedPtr�Ĺ��캯��" << "use num "<<ptr->use_num<<endl;
	}
	SharePtr(const SharePtr& orig) :ptr(orig.ptr), val(orig.val){
		++ptr->use_num;
		cout << "SharePtr�Ŀ������캯��: " << "use_num:" << ptr->use_num << endl;
	}
	~SharePtr(){
		cout << "SharePtr ����������: " << "use_num:" << ptr->use_num << endl;
		if (--ptr->use_num == 0){
			delete ptr;
		}
	}
private:
	Res_Ptr<T>* ptr;//ָ������� Res_ptr;
	T val;
};
//template <class T>
//class Myptr
//{
//private:
//	T* _ptr;
//public:
//	Myptr(T* p):_ptr(p){
//		cout << "����ʱ����" << endl;
//	}
//	~Myptr()
//	{
//		cout << "����ʱ����" << endl;
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
	int a = 10;//�ֲ�����-> ����ջ֡
	// local heap => new delete
	//�� local heap / heap => ����
	{
		SharePtr<int> p = SharePtr<int>(new int(24), 100);
	}
	


	system("pause");
}