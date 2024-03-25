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
			cout << "������������, " << _user[i].getName() << endl;
			return true;
		}
	}
	cout << "������ ����������� (�������� ����� ���  ������)\n";
	return false;
}

void Chat::listUsers(const string &name) // ������ ���������
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
		if (_user[i].getName() == to)
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
			cout << "�� " << _textMessages[i].getFrom() << " ���������: " << _textMessages[i].getMessage() << " � " << _textMessages[i].getTo() << endl;
		}
	}
}