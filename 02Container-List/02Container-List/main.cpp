#include <iostream>
#include <list>

using namespace std;

//链表节点
template<typename T>
struct MyList_node
{
	MyList_node<T> *prev;
	MyList_node<T> *next;
	T data;
};

//同时将设计类型表和迭代器整合在一起
template<typename T>
struct MyList_iterator
{
	typedef MyList_iterator<T> iterator;
	typedef MyList_node<T>* link_type;

	//节点指针
	link_type node;
	//构造函数
	MyList_iterator(link_type x) : node(x){

	}
	MyList_iterator() :node(NULL){

	}
	//重载++
	iterator& operator ++(){
		node = node->next;
		//返回本对象，同时指向下一个
		return *this;
	}
	iterator& operator++(int){
		//保存自增运算前的指针值
		iterator temp = *this;
		++*this;
		//返回未增加前的对象
		return temp;
	}
	//重载--
	iterator& operator --(){
		node = node->prev;
		//返回本对象，同时指向下一个
		return *this;
	}
	iterator& operator--(int){
		//保存自增运算前的指针值
		iterator temp = *this;
		--*this;
		//返回未增加前的对象
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
		//返回节点的数据
		return node->data;
	}
};

template<typename T>
class MyList{
public:
	//数据类型表
	//将 MyList<T> 申明为内部类型 iterator
	typedef MyList_iterator<T> iterator;
public:
	//构造
	MyList() :length(0){
		node = new MyList_node<T>;
		node->next = node;
		node->prev = node;
	}
	~MyList(){
		//delete node;
	}
	//返回链表的头函数
	iterator begin(){
		return node->next;
	}
	iterator end(){
		return node;
	}

	//push_front, push_back
	//向链表的头部加入数据
	void push_front(const T& x){
		insert(begin(), x);
	}

	//向链表尾部加入数据
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


//通用查找函数
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