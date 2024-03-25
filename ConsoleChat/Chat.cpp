#include "Chat.h"

Chat::~Chat() {};


bool Chat::AddUser(const User& user)
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

bool Chat::LoginUser(string& name, string& password) //Вход
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
	cout << "\nСписок контактов" << endl;

	for (int i = 0; i < _user.size(); i++)
	{
		if (_user[i].getName() == name)
		{
			continue;
		}
		cout << i << " - " << _user[i].getName() << endl;
	}
}

void Chat::sendMessage()
{

}
