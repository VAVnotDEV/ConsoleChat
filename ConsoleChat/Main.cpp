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
	string name, password;
	int choise = 0;

	while (choise != 6)
	{
		cout << "\t****Консольный чат****\n" << "1.Регистрация \n2.Вход\n3.Выход\n" << "Введите команду: ";
		cin >> choise;

		switch (choise)
		{
		case REGISTER: //Регистрация
		{
			cout << "\t/ * * Регистрация нового пользователя * */ \n"
				<< "Придумайте логин: "; cin >> name;
			cin.ignore();
			cout << "Придумайте пароль: "; getline(cin, password);
			User newUser(name, password);
			chat.AddUser(newUser);
			system("pause");
			system("cls");
		}
		break;

		case LOGIN: //Вход
			cout << "\t/ * * Авторизация * */ \n"
				<< "Введите логин: "; cin >> name;
			cin.ignore();
			cout << "Введите пароль" << endl;
			getline(cin, password);
			cout << name << endl;

			while (choise != LOGOUT) //вход
			{
				cout << "Выберите действие\n 3.Отправить сообщение\n 4.Рассылка\n 7.Выход\n";
				cin >> choise;

				switch (choise)
				{
				case SEND:
					chat.listUsers(name);
					break;
				case SEND_ALL:

					break;
				case LOGOUT:
					break;
				default:
					cout << "Команда не выбрана\n";
					break;
				}
			}
			break;

		case EXIT:
			continue;
			break;
		default:
			cout << "Команда не выбрана" << endl;
			break;
		}
	}

	return 0;
}