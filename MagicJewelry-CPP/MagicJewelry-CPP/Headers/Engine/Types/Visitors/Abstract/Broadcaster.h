#pragma once

#include <list>
#include <algorithm>

using namespace std;

template<class T>
class Broadcaster
{
public:
	virtual void Subscribe(T object) 
	{
		if ((find(broadcastList.begin(), broadcastList.end(), object) == broadcastList.end()))
			broadcastList.insert(broadcastList.end(), object);
	}
	virtual void Unsubscribe(T object)
	{
		if ((find(broadcastList.begin(), broadcastList.end(), object) != broadcastList.end()))
			broadcastList.remove(object);
	}
	virtual void Broadcast() = 0;
protected:
	Broadcaster() 
	{
	}
	list<T> broadcastList;
};

