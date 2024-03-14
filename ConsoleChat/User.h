#pragma once
#include <iostream>
using namespace std;

class User
{
private:
	string _name;
	string _password;

public:
	//������������, �����������
	User() = default;
	User(string name, string password);
	User(const User& other);
	~User();

	//������
	string getName() const;
	string getPassword() const;

	//������
	void setName( string name);
	void setPassword( string password);
};