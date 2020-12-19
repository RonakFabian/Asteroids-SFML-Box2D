#pragma once

#include <list>
#include <iostream>

template<class T>
class ObjectPool
{
public:
	
	static ObjectPool* GetInstance();


	ObjectPool();
	~ObjectPool();
	T* GetResource();

	std::list<T*> resources;
	static void ReturnResource(T* obj);
	static ObjectPool* Instance;
	
private:
	
};

template <class T>
ObjectPool<T>* ObjectPool<T>::GetInstance()
{
	if(Instance==nullptr)
	{
		Instance = new ObjectPool;
	}
	return Instance;
}

template <class T>
ObjectPool<T>::ObjectPool()
{
	Instance = new ObjectPool;
}

template <class T>
ObjectPool<T>::~ObjectPool()
{
	
}

template <class T>
T* ObjectPool<T>::GetResource()
{
	if (resources.empty())
	{
		std::cout << "Creating new." << std::endl;
		return new T;
	}
	else
	{
		std::cout << "Reusing existing." << std::endl;
		T* resource = resources.front();
		resources.pop_front();
		return resource;
	}
}

template <class T>
void ObjectPool<T>::ReturnResource(T* obj)
{
	//Reset T-  Object
	resources.push_back(obj);
}



