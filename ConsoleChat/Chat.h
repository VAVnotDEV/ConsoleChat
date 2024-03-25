#pragma once
#include "Message.cpp"

class Chat
{
public:
	Chat() = default;
	~Chat();

	//Добавить пользователя
	bool addUser(const User& user); 
	//Авторизация пользователя
	bool loginUser(string& login, string& password);
	//Список пользователей
	void listUsers(const string& name);
	//Отправка сообщения
	bool sendMessage(const string& from, const string& to, const string& text);
	//Отправка сообщения всем
	void sendAllMessage(const string& from, const string& text);
	//Вывод сообшений
	void displayMessages(const string& from, const string& to);
	
private:
	vector<User>_user;
	vector<Message<string>>_textMessages;

};