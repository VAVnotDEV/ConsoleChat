#include "Chat.h"


//ConsoleChat
//1.Пользователь отправляет сообщение адресату и группе.
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
	enum command {REGISTER = 1, LOGIN, SEND, MAIN_MENU,};

	string name;
	string password;
	User u1(name, password);
	chat.AddUser(u1);
		while (!chat.AddUser(u1))
		{
			string name;
			string password;
			cin >> name >> password;


			cin >> name >> password;
		}


		

	//while (true)
	//{
	//	int choise = 0;
	//	cout << "Введите команду: ";
	//	cin >> choise;

	//	switch (choise)
	//	{
	//	case REGISTER:
	//	{
	//	}

	//	break;
	//	case LOGIN:
	//		break;
	//	case SEND:
	//		break;
	//	default:
	//		continue;
	//		break;
	//	}
	//}



	return 0;
}