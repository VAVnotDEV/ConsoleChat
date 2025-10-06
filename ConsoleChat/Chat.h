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
	bool loginUser(const string& login, const string& password);
	//Список пользователей
	void listUsers(const string& name);
	//Отправка сообщения
	bool sendMessage(const string& from, const string& to, const string& text);
	//Отправка сообщения всем
	void sendAllMessage(const string& from, const string& text);
	//Вывод сообшений
	void displayAllMessages(const string& from, const string& to) const;
	//Выбор адресата
	string getContact(const int index) const;
	
private:
	vector<User>_user;
	vector<Message<string>>_textMessages;

};

//Выход за границы массива
class Bad_Range : public exception
{
public:
	virtual const char* what() const noexcept override
	{
		return "ERROR: index out of range";
	}
};