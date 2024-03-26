#include "Chat.h"


auto main() -> int
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