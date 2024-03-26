#include "Chat.h"

Chat::~Chat() {};


bool Chat::addUser(const User& user)
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

bool Chat::loginUser(string& name, string& password) //����
{
	for (int i = 0; i < _user.size(); ++i)
	{
		if (_user[i].getName() == name && _user[i].getPassword() == password)
		{
			return true;
		}
	}
	cout << "\n������ ����������� (�������� ����� ���  ������)\n";
	return false;
}

void Chat::listUsers(const string& name) // ������ ���������
{
	cout << "\n������ ���������: " << endl;

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
		if (text == "exit")
		{
			return false;
		}
		else if ( _user[i].getName() == to)
		{
			
			_textMessages.push_back(Message<string>(from, to, text));
			return true;
		}
	}
	cout << "��������� �� ����������, ������� �� ������" << endl;

	return false;
}

void Chat::sendAllMessage(const string& from, const string& text)
{
	for (int i = 0; i < _user.size(); ++i)
	{
		if (_user[i].getName() == from || text == "exit")
		{
			continue;
		}
		_textMessages.push_back(Message<string>(from, _user[i].getName(), text));
	}
}

void Chat::displayAllMessages(const string& from, const string& to) const
{
	for (int i = 0; i < _textMessages.size(); ++i)
	{
		if ((from == _textMessages[i].getFrom() && to == _textMessages[i].getTo()) || (from == _textMessages[i].getTo() && to == _textMessages[i].getFrom()))
		{
			cout << "��: " << _textMessages[i].getFrom() << " ���������: " << _textMessages[i].getMessage() << endl;
		}
	}
}

string Chat::getContact(const int index) const
{
	if (index < 0 || index > _user.size())
	{
		throw Bad_Range();
	}

	for (int i = 0; i < _user.size(); ++i)
	{
		return _user[index].getName();
	}

	return _user[index].getName();
}