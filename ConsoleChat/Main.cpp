#include "Chat.h"


//ConsoleChat
//1.������������ ���������� ��������� �������� � ������.
//1.�����������
//2.�����������
//3.����� ��������
//4.�������� ��������� ��� ��������
//5.���������� ��������� �� ����� ������ ���������.
//6.����� ������������
//7.����� �� ���������

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
	//	cout << "������� �������: ";
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