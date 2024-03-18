#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class User
{
private:
	string _name;
	string _password;

public:
	//Конструткоры, деструкторы
	User() = default;
	User(string name);
	User(string name, string password);
	User(const User& other);
	User(const User&& other) noexcept;
	~User();

	//Гетеры
	string getName() const;
	string getPassword() const;

	//Сетеры
	void setName( string name);
	void setPassword( string password);
	
	//Операторы
	User& operator=(User& other);
	User& operator=(User&& other) noexcept;
};