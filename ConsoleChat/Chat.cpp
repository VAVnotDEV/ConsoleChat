#include "Chat.h"

Chat::~Chat() {};


bool Chat::AddUser(const User& user)
{
		for (int i = 0; i < _user.size(); ++i)
		{
			if (user.getName() == _user[i].getName())
			{
				cout << "��� ������, ���������" << endl;
				return false;
			
			}
		}
		cout << "������������ ������� ��������" << endl;
		_user.push_back(user);
		return true;
}

bool Chat::LoginUser(string& name, string& password) //����
{
	for (int i = 0; i < _user.size(); ++i)
	{
		if (_user[i].getName() == name && _user[i].getPassword() == password)
		{
			return true;
		}
	}
	return false;
}

void Chat::listUsers() // ������ ���������
{
	cout << "\n������ ���������" << endl;

	for (int i = 0; i < _user.size(); i++)
	{
		cout << i << " - " << _user[i].getName() << endl;
	}
}