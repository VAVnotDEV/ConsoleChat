#pragma once
#include <iostream>
#include <string>
using namespace std;

class User
{
private:
	string _name;
	string _password;

public:
	//������������, �����������
	User() = default;
	User(string name);
	User(string name, string password);
	User(const User& other);
	~User();

	//������
	string getName() const;
	string getPassword() const;

	//������
	void setName( string name);
	void setPassword( string password);
	
	User& operator=(User& other);
};