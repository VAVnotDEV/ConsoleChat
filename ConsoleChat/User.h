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
	//Конструткоры, деструкторы
	User() = default;
	User(const string& name, const string& password);
	User(const string& name);

	User(const User& other);
	User(User&& other) noexcept;
	virtual ~User();

	//Гетеры
	string getName() const;
	string getPassword() const;

	//Сетеры
	void setName(string name);
	void setPassword(string password);
	
	//Операторы
	User& operator=(User& other);
	User& operator=(User&& other) noexcept;

};