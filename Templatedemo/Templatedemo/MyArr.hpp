#pragma once

template <typename T, int n>
class Array{
public:
	Array();
	Array(int length);
	~Array();
	int size();

	T get(int num);
	T& operator[](int num);
	void set(T data, int num);
public:
	T *pt;
};

template <typename T, int n>
Array<T, n>::Array(){
	this->pt = new T[n];
}

template <typename T, int n>
Array<T, n>::Array(int length){
	this->pt = new T[length];
}

template <typename T, int n>
Array<T, n>::~Array(){
	delete this->pt;
}

template <typename T, int n>
int Array<T, n>::size(){
	return n;
}

template <typename T, int n>
T Array<T, n>::get(int num){
	if (num >= n || num < 0)
	{
		//
	}
	else{
		return *(this->pt + num);
	}
}

template <typename T, int n>
void Array<T, n>::set(T data, int num){
	if (num >= n || num < 0)
	{
		//
	}
	else{
		 *(pt + num) = data;
	}
}

template <typename T, int n>
T& Array<T, n>::operator[](int num){
	if (num < 0 || num >= n)
	{
		//
	}
	else{
		return *(pt + num);
	}
}