#pragma once
#include "Message.h"

class Chat
{
public:
	Chat() = default;
	~Chat();
	
	void RegistrationUser(string& login, string& password);
	bool LoginUser(string& login, string& password);
	void listUsers();

private:
	vector<User>_user;
	vector<Message<string>>textMessages;
	
};