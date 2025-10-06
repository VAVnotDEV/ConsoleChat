#include "Chat.h"
#include <limits>:

//Здравствуйте, Андрей!
//
//Отличная работа!Ниже подсвечу основные моменты.
//
//Плюсы :
//	-реализован основной функционал : регистрация и авторизация пользователей, отправка сообщений конкретному пользователю и обмен сообщениями между всеми пользователями чата одновременно;
//-код разделен на классы Chat, User, Message;
//-классы разделены на объявление и реализацию;
//-реализован шаблонный класс Message;
//-классы пользователя User и Message соответствуют "правилу пяти";
//-использованы контейнеры STL(vector);
//-есть makefile для сборки проекта;
//-есть собственное исключение Bad_Range;
//-есть README.md с описанием проекта.
//

//Что улучшить :
//-избегайте добавления на гитхаб файлов * .exe, * .sln, папки с содержимым x86/* - они будут работать только на вашем компьютере, не несут никакой ценности и при этом сильно увеличивают размер репозитория

//- старайтесь принимать аргументы по ссылке - так будет меньше копирований, и код будет эффективнее; например, вместо:
//User(string name, string password);
//сделайте:
//User(const string& name, const string& password);

//в конструкторе и операторе перемещения лучше использовать семантику перемещения; например, вместо:
//User& User::operator=(User&& other) noexcept
//{
//	_name = other._name;
//	_password = other._password;
//	return *this;
//}
//сделайте:
//User& User::operator=(User&& other) noexcept
//{
//	_name = std::move(other._name);
//	_password = std::move(other._password);
//	return *this;
//}

//- если деструктор пустой, то его тоже можно объявить через default (например, у Chat);
//- в методе Chat::getContact() не нужен цикл;
//- шаблонный класс лучше целиком определять в заголовочном файле (.hpp).
//
//Вы молодец! Есть куда расти!
//
//По любым вопросам пишите в чат в телеграме

int main()
{
	setlocale(LC_ALL, "");

	Chat chat;
	enum command { REGISTER = 1, LOGIN, SEND_ALL = 7, LOGOUT = 8, EXIT = 9 };
	auto choise = 0;
	string login, password;

	User u1{ "Ivan", "a" };
	User u2{ "Gleb", "b" };
	User u3{ "a", "a" };
	chat.addUser(u1);
	chat.addUser(u2);
	chat.addUser(u3);

	while (choise != EXIT)
	{
		cout << "\n\t****Консольный чат****\n" << REGISTER << ".Регистрация\n" << LOGIN << ".Вход\n"  << EXIT << ".Выход\n" << "Введите команду : ";

		cin >> choise;
		cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


			switch (choise)
			{
				//Регистрация
			case REGISTER:
			{
				cout << "\t/ * * Регистрация нового пользователя * */ \n" << "Придумайте логин: "; cin >> login;
				cin.ignore();
				cout << "Придумайте пароль: "; getline(cin, password);

				User newUser(login, password);
				chat.addUser(newUser);

				system("pause");
				system("cls");
			}
			break;

			//Авторизация
			case LOGIN:
				cout << "\n\t/ * * Авторизация * */ \n" << "Введите логин: "; cin >> login;
				cout << "Введите пароль: "; cin >> password;

				//Сессия пользователя
				if (chat.loginUser(login, password))
				{
					while (choise != LOGOUT)
					{
						string text, reciever;
						system("cls");
						cout << "\nЗдравствуйте, " << login << "!\n" << "Выберите адресата или действие\n";

						chat.listUsers(login);

						cout << SEND_ALL << ".Отправить всем\n" << LOGOUT << ".Выход\n" << "\nВыберите команду: ";  cin >> choise;
						cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

						if (choise == SEND_ALL)		//Рассылка
						{
							while (text != "exit")
							{
								cin.ignore();
								cout << "Сообщение (для выхода введите exit): "; cin >> text;
								chat.sendAllMessage(login, text);
								cout << login << " :" << text << endl;
							}
						}
						else if (choise == LOGOUT)	//Выход пользователя
						{
							break;
						}
						else						//Отправка сообщения пользователю
						{
							try {
								reciever = chat.getContact(choise);
								chat.displayAllMessages(login, reciever);
								while (text != "exit")
								{
									cin.ignore();
									cout << "Сообщение (для выхода введите exit): "; cin >> text;
									cout << chat.sendMessage(login, reciever, text);
									cout << login << " :" << text << endl;
								}
							}
							catch (Bad_Range& r)
							{
								cout << r.what() << endl;
								system("pause");
							}
						}
					}
				}
				break;
			case EXIT:		//Завершение работы программы
				break;
			default:
				cout << "Неверно выбрана команда" << endl;
				break;
			}
	}

	return 0;
}
