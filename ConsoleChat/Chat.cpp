#include "Chat.h"



void Chat::RegistrationUser(string& name, string& password)
{

	while(true)
	{
		cout << "Enter name: " << endl;
		getline(cin, name);
		for (int i = 0; i < _user.size(); ++i)
		{
			if (_user[i].getName() == name)
			{
				cout << "Имя занято" << endl;
			}
		}
		break;
	}
	cout << "Введите пароль: " << endl;
	getline(cin, name);
	_user.emplace_back(name, password);
}

bool Chat::LoginUser(string& name, string& password)
{
	for (int i = 0; i < _user.size(); ++i)
	{
		if (_user[i].getName() == name && _user[i].getPassword() == password)
		{
			return true;
		}
		return false;
	}
	

}

void Chat::listUsers()
{
	for (int i = 0; i < _user.size(); i++)
	{
		cout << i << " - " << _user[i].getName() << endl;
	}
}