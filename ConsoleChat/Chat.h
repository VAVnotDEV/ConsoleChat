#pragma once
#include "Message.h"

class Chat
{
public:
	Chat() = default;
	Chat(User users, Message<string>message) : _users(new User), _message(message) {};
	~Chat();
	
	void RegUser(string login, string password)
	{
		_users->setName(login);
		_users->setPassword(password);
	}

	void auth( bool suceful = false)
	{
	
	}

	void getUser()
	{
		for (int i = 0; i < sizeof(_users) / sizeof(_users[0]); ++i)
		{
			cout << _users[i].getName();
		}
	}

private:
	User* _users;
	Message<string>_message;
	
};