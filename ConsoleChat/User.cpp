#include "User.h"
//Конструкторы
User::User(string name, string password) : _name(name), _password(password) {};
User::User(string name) : _name(name) {};
User::User(const User& other) : _name(other._name), _password(other._password){}
User::User(const User&& other) noexcept : _name(other._name), _password(other._password) {}
User::~User(){}

//Гетеры
string User::getName() const
{
	return _name;
}
string User::getPassword() const
{
	return _password;
}

//Сетеры
void User::setName(string name)
{
	_name = name;
}
void User::setPassword(string password)
{
	_password = password;
}

//Операторы
User& User::operator=(User& other)
{
	_name = other._name;
	_password = other._password;
	return *this;
}
User& User::operator=(User&& other) noexcept
{
	_name = other._name;
	_password = other._password;
	return *this;
}

