#include "Message.h"

template <class T>
Message<T>::Message(string to, string form, T message) : _to(to), _form(form), _message(message) {};
template <class T>
Message<T>::Message(const Message& other) : _to(other._to), _form(other._form), _message(other._message){}
template <class T>
Message<T>::Message(const Message&& other) noexcept : _to(other._to), _form(other._form), _message(other._message){}
template <class T>
Message<T>::~Message() {};
//Get
template <class T>
string Message<T>::getTo() const
{
	return _to;
}
template <class T>
string Message<T>::getForm() const
{
	return _form;
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
void Message<T>::setForm(string value)
{
	_form = value;
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
	_to = other._to;
	_form = other._form;
	_message = other._message;
	
	return *this;
}

template <class T>
Message<T>& Message<T>::operator=(const Message&& other) noexcept
{
	_to = other._to;
	_form = other._form;
	_message = other._message;
	return *this;
}
