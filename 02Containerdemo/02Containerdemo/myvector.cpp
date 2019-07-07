#include <iostream>

using namespace std;

template<typename Ty>
class Myvector{
public:
	typedef Ty value;
	typedef Ty* viter;
public:
	Myvector(int nLen = 0) :m_nLen(nLen), m_Data(NULL), star(NULL), finish(0){
		if (nLen > 0)
		{
			m_Data = new Ty[nLen];
			star = m_Data;
			end_of_element = nLen;
		}
	}
	~Myvector(){
		delete[]  m_Data;
	}
	void push_back(const value& data){
		if (end_of_element != finish){
			*(star + finish) = data;
			finish++;
		}
		else{
			cout << "exceed bound" << endl;
		}
	}
	inline value pop_up(){
		--finish;
		return *(star + finish);
	}
	value& operator[](int n){
		if (n == finish || n < finish){
			return *(star + n)
		}
		else{
			cout << "get error" << endl;
		}
	}
protected:
	viter m_Data;//����ͷָ��
	int m_nLen;//���鳤��
	viter star;//������ʼ��ַ
	int finish;// �������λ��־
	int end_of_element;//����ĩβ��־
};

int main()
{
	int a = 0;
	Myvector<int> test(10);
	test.push_back(100);
	test.push_back(200);
	cout << test.pop_up() << endl;
	system("pause");
	return 0;
}