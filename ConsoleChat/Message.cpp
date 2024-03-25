#include "Message.h"

template <class T>
Message<T>::Message(string from, string to, T message) : _from(from), _to(to), _message(message) {};
template <class T>
Message<T>::Message(const Message& other) : _from(other._from), _to(other._to), _message(other._message){}
template <class T>
Message<T>::Message(const Message&& other) noexcept : _from(other._from), _to(other._to), _message(other._message){}
template <class T>
Message<T>::~Message() {};
//Get
template <class T>
string Message<T>::getTo() const
{
	return _to;
}
template <class T>
string Message<T>::getFrom() const
{
	return _from;
}
template <class T>
T Message<T>::getMessage() const
{
	return _message;
}
//Set
template <class T>
void Message<T>::setTo(string value)
{
	_to = value;
}
template <class T>
void Message<T>::setFrom(string value)
{
	_from = value;
}
template <class T>
void Message<T>::setMessage(T value)
{
	_message = value;
}
//Operators
template <class T>
Message<T>& Message<T>::operator=(const Message& other) 
{
	_from = other._from;
	_to = other._to;
	_message = other._message;
	
	return *this;
}

template <class T>
Message<T>& Message<T>::operator=(const Message&& other) noexcept
{
	_from = other._from;
	_to = other._to;
	_message = other._message;
	
	return *this;
}
