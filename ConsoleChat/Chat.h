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
	void displayMessages(const string& from, const string& to);
	
private:
	vector<User>_user;
	vector<Message<string>>_textMessages;

};