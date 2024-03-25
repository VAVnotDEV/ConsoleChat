#include "Chat.h"


//ConsoleChat
//1.Пользователь отправляет сообщение адресату или группе.
//1.Регистрация
//2.Авторизация
//3.Выбор адресата
//4.Отправка сообщения или Рассылка
//5.Сохранение сообщений на время работы программы.
//6.Выход пользователя
//7.Выход из программы

auto main() -> int
{
	setlocale(LC_ALL, "");

	Chat chat;
	enum command { REGISTER = 1, LOGIN, SEND, SEND_ALL, MAIN_MENU, EXIT, LOGOUT };
	string login, password;
	int choise = 0;

	User u1{ "a", "a" };
	User u2{ "b", "b" };
	User u3{ "c", "c" };
	User u4{ "q", "q" };
	chat.addUser(u1);
	chat.addUser(u2);
	chat.addUser(u3);
	chat.addUser(u4);

	while (choise != EXIT)
	{
		cout << "\n\t****Консольный чат****\n" << "1.Регистрация \n2.Вход\n3.Выход\n" << "Введите команду: ";
		cin >> choise;

		switch (choise)
		{
			//Регистрация
		case REGISTER:
		{
			cout << "\t/ * * Регистрация нового пользователя * */ \n"
				<< "Придумайте логин: "; cin >> login;
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
			cin.ignore();
			cout << "Введите пароль: "; cin >> password;

			if (chat.loginUser(login, password))
			{
				while (choise != LOGOUT)
				{
					string text, reciever;
					cout << "\nВыберите действие\n 3.Отправить личное сообщение\n 4.Рассылка\n 7.Выход\n"; cin >> choise;

					switch (choise)
					{
					case SEND:
					{
						chat.listUsers(login);
						cout << "Выберите адресата" << endl; cin >> reciever;
						cin.ignore();
						cout << "Введите сообщение: "; getline(cin, text);
						chat.sendMessage(login, reciever, text);
						chat.displayMessages(login, reciever);
					}
					break;

					case SEND_ALL:
						cout << "Отправить всем\n";
						cin >> text;
						chat.sendAllMessage(login, text);
						break;
					case LOGOUT:
						break;
					default:
						cout << "Команда не выбрана\n";
						break;
					}
				}
			}
				break;

		case EXIT:			//Выход
			continue;
			break;
		default:
			cout << "Команда не выбрана" << endl;
			break;
			}
		}

		return 0;
	}