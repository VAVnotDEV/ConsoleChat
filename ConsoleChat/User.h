#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <exception>

using std::cout;
using std::cin;
using std::exception;
using std::string;
using std::endl;
using std::vector;

class User
{
private:
	string _name;
	string _password;

public:
	//������������, �����������
	User() = default;
	User(string name, string password);
	User(string name);

	User(const User& other);
	User(const User&& other) noexcept;
	virtual ~User();

	//������
	string getName() const;
	string getPassword() const;

	//������
	void setName( string name);
	void setPassword( string password);
	
	//���������
	User& operator=(User& other);
	User& operator=(User&& other) noexcept;

};