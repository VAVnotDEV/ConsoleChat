#pragma once
#include <iostream>
#include "User.h"

using namespace std;

template <class T>
class Message
{
private:	
	User _messageTo;
	User _messageForm;
	T _message;

public:
	Message(User messageTo, User MessageForm, T message);
	
	~Message();


};