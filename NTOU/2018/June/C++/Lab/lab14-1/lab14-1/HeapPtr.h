#ifndef HeapPtr_H
#define HeapPtr_H

#include<cassert>

#include"Fred.h"

template<class T>
class HeapPtr
{
public:
	HeapPtr(T *ptr = 0);
	~HeapPtr();
	void deallocate();
	HeapPtr& operator=(T *ptr);
	T* operator->();
	T& operator*();
	T* relinguishOwnership();
	HeapPtr& operator=(const HeapPtr &);
	HeapPtr(const HeapPtr &);
private:
	T* m_ptr;		
};

template<class T>
HeapPtr<T>::HeapPtr(T* ptr)
	:m_ptr(ptr)
{
}

template<class T>
HeapPtr<T>::~HeapPtr(){
	deallocate();
}

template<class T>
void HeapPtr<T>::deallocate(){
	delete m_ptr;
	m_ptr = 0;
}

template<class T>
HeapPtr<T>& HeapPtr<T>::operator=(T *ptr)
{
	deallocate();
	m_ptr = ptr;
	return *this;
}

template<class T>
T* HeapPtr<T>::operator->()
{
	assert(m_ptr != 0);
	return m_ptr;
}

template<class T>
T& HeapPtr<T>::operator*()
{
	assert(m_ptr != 0);
	return *m_ptr;
}

template<class T>
T* HeapPtr<T>::relinguishOwnership(){
	T* old = m_ptr;
	m_ptr = 0;
	return old;
}

template<class T>
HeapPtr<T>& HeapPtr<T>::operator=(const HeapPtr<T> & rhs){
	if(&rhs == this)
		return *this;
	if(rhs.m_ptr != 0)
		m_ptr = new T(*rhs.m_ptr);
	else
		m_ptr = 0;
	return *this;
}

template<class T>
HeapPtr<T>::HeapPtr(const HeapPtr &rhs){
	if(rhs.m_ptr)
		m_ptr = new T(*rhs.m_ptr);
	else
		m_ptr = 0;
}
#endif