#pragma once
#include "Message.cpp"


class Chat
{
public:
	Chat() = default;
	~Chat();

	//�������� ������������
	bool addUser(const User& user); 
	//����������� ������������
	bool loginUser(string& login, string& password);
	//������ �������������
	void listUsers(const string& name);
	//�������� ���������
	bool sendMessage(const string& from, const string& to, const string& text);
	//�������� ��������� ����
	void sendAllMessage(const string& from, const string& text);
	//����� ���������
	void displayAllMessages(const string& from, const string& to) const;
	//����� ��������
	string getContact(const int index) const;
	
private:
	vector<User>_user;
	vector<Message<string>>_textMessages;

};

//����� �� ������� �������
class Bad_Range : public exception
{
public:
	virtual const char* what() const noexcept override
	{
		return "ERROR: index out of range";
	}
};