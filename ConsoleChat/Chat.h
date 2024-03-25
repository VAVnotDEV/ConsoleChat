#pragma once
#include "Message.cpp"

class Chat
{
public:
	Chat() = default;
	~Chat();

	bool AddUser(const User& user);
	bool LoginUser(string& login, string& password);
	void listUsers(const string& name);
	void sendMessage();
	


private:
	vector<User>_user;
	vector<Message<string>>textMessages;

};