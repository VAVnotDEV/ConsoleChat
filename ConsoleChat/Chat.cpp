#include "Chat.h"

Chat::~Chat() {};


bool Chat::addUser(const User& user)
{
		for (int i = 0; i < _user.size(); ++i)
		{
			if (user.getName() == _user[i].getName())
			{
				cout << "Имя занято, повторите" << endl;
				return false;
			}
		}
		cout << "Пользователь успешно добавлен" << endl;

		_user.push_back(user);

		return true;
}

bool Chat::loginUser(string& name, string& password) //Вход
{
	for (int i = 0; i < _user.size(); ++i)
	{
		if (_user[i].getName() == name && _user[i].getPassword() == password)
		{
			cout << "Здравствуйте, " << _user[i].getName() << endl;
			return true;
		}
	}
	cout << "Ошибка авторизации (неверный логин или  пароль)\n";
	return false;
}

void Chat::listUsers(const string &name) // Список контактов
{
	cout << "\nСписок контактов: " << endl;

	for (int i = 0; i < _user.size(); i++)
	{
		if (_user[i].getName() == name)
		{
			continue;
		}
		cout << i << " - " << _user[i].getName() << endl;
	}
	cout << endl;
}

bool Chat::sendMessage(const string& from, const string& to, const string& text)
{
	for (int i = 0; i < _user.size(); ++i)
	{
		if (_user[i].getName() == to)
		{
			_textMessages.push_back(Message<string>(from, to, text));
			return true;
		}
	}

	cout << "Сообщение не отправлено, адресат не найден" << endl;

	return false;
}

void Chat::sendAllMessage(const string& from, const string& text)
{
	for (int i = 0; i < _user.size(); ++i)
	{
		if (_user[i].getName() == from)
		{
			continue;
		}
		_textMessages.push_back(Message<string>(from, _user[i].getName(), text));
	}
}

void Chat::displayMessages(const string& from, const string& to)
{
	for (int i = 0; i < _textMessages.size(); ++i)
	{
		if (_textMessages[i].getFrom() == from && _textMessages[i].getTo() == to)
		{
			cout << "От " << _textMessages[i].getFrom() << " Сообщение: " << _textMessages[i].getMessage() << " К " << _textMessages[i].getTo() << endl;
		}
	}
}