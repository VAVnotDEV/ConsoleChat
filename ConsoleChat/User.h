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
	//Конструткоры, деструкторы
	User() = default;
	User(string name);
	User(string name, string password);
	User(const User& other);
	~User();

	//Гетеры
	string getName() const;
	string getPassword() const;

	//Сетеры
	void setName( string name);
	void setPassword( string password);
	
	User& operator=(User& other);
};