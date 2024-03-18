#pragma once
#include "User.h"


template <class T>
class Message
{
private:	
	string _to;
	string _form;
	T _message;

public:
	Message() = default;
	Message(string to, string form, T message);
	Message(const Message& other);
	Message(const Message&& other) noexcept;
	~Message();

	string getTo() const;
	string getForm() const;
	T getMessage() const;

	void setTo(string value);
	void setForm(string value);
	void setMessage(T value);

	Message& operator=(const Message& other);
	Message& operator=(const Message&& other) noexcept;
};