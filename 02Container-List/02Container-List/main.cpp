#include <iostream>
#include <list>

using namespace std;

//����ڵ�
template<typename T>
struct MyList_node
{
	MyList_node<T> *prev;
	MyList_node<T> *next;
	T data;
};

//ͬʱ��������ͱ�͵�����������һ��
template<typename T>
struct MyList_iterator
{
	typedef MyList_iterator<T> iterator;
	typedef MyList_node<T>* link_type;

	//�ڵ�ָ��
	link_type node;
	//���캯��
	MyList_iterator(link_type x) : node(x){

	}
	MyList_iterator() :node(NULL){

	}
	//����++
	iterator& operator ++(){
		node = node->next;
		//���ر�����ͬʱָ����һ��
		return *this;
	}
	iterator& operator++(int){
		//������������ǰ��ָ��ֵ
		iterator temp = *this;
		++*this;
		//����δ����ǰ�Ķ���
		return temp;
	}
	//����--
	iterator& operator --(){
		node = node->prev;
		//���ر�����ͬʱָ����һ��
		return *this;
	}
	iterator& operator--(int){
		//������������ǰ��ָ��ֵ
		iterator temp = *this;
		--*this;
		//����δ����ǰ�Ķ���
		return temp;
	}
	iterator& operator=(iterator x){
		node = x.node;
		return *this;

	}
	bool operator ==(const iterator& x){
		return node == x.node;
	}

	bool operator !=(const iterator& x){
		return node != x.node;
	}
	T& operator*()const{
		//���ؽڵ������
		return node->data;
	}
};

template<typename T>
class MyList{
public:
	//�������ͱ�
	//�� MyList<T> ����Ϊ�ڲ����� iterator
	typedef MyList_iterator<T> iterator;
public:
	//����
	MyList() :length(0){
		node = new MyList_node<T>;
		node->next = node;
		node->prev = node;
	}
	~MyList(){
		//delete node;
	}
	//���������ͷ����
	iterator begin(){
		return node->next;
	}
	iterator end(){
		return node;
	}

	//push_front, push_back
	//�������ͷ����������
	void push_front(const T& x){
		insert(begin(), x);
	}

	//������β����������
	void push_back(const T& x){
		insert(end(), x);
	}

	void pop_front(){
		erase(begin());
	}
	void pop_back(){
		erase(--end());
	}
	iterator insert(const iterator& position, const T& x){
		MyList_node<T>* temp = new MyList_node<T>;
		temp->data = x;
		temp->prev = position.node->prev;
		temp->next = position.node;
		position.node->prev->next = temp;
		position.node->prev = temp;
		++length;
		return temp;
	}
	void erase(const iterator& position){
		position.node->prev->next = position.node->next;
		position.node->next->prev = position.node->prev;
		--length;
	}
protected:
	MyList_node<T> * node;
	size_t length;
};


//ͨ�ò��Һ���
template<typename _InputIter,typename _Tp>
_InputIter MyFind(_InputIter _first, _InputIter _last, const _Tp& _val){
	while (_first != _last && !(*_first == _val)){
		++_first;
		return _first;
	}
}
int main(void)
{
	//list<int> my1;
	MyList<int> mylist1;
	mylist1.push_front(10);
	mylist1.push_front(20);
	mylist1.push_front(30);
	MyList<int>::iterator iter;
	iter = mylist1.begin();
	cout << *++iter << endl;

	cout << *MyFind(mylist1.begin(), mylist1.end(), 20) << endl;
	system("pause");
	return 0;
}