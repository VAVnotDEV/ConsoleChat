#pragma once
#include "User.h"


template <class T>
class Message
{
private:	
	string _from;
	string _to;
	T _message;

public:
	Message() = default;
	Message(string from, string to, T message);
	Message(const Message& other);
	Message(const Message&& other) noexcept;
	~Message();

	string getTo() const;
	string getFrom() const;
	T getMessage() const;

	void setTo(string value);
	void setFrom(string value);
	void setMessage(T value);

	Message& operator=(const Message& other);
	Message& operator=(const Message&& other) noexcept;
};