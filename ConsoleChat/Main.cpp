#include "Chat.h"


//ConsoleChat
//1.������������ ���������� ��������� �������� ��� ������.
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
	enum command { REGISTER = 1, LOGIN, SEND, SEND_ALL, MAIN_MENU, EXIT, LOGOUT };
	string name, password;
	int choise = 0;

	while (choise != 6)
	{
		cout << "\t****���������� ���****\n" << "1.����������� \n2.����\n3.�����\n" << "������� �������: ";
		cin >> choise;

		switch (choise)
		{
		case REGISTER: //�����������
		{
			cout << "\t/ * * ����������� ������ ������������ * */ \n"
				<< "���������� �����: "; cin >> name;
			cin.ignore();
			cout << "���������� ������: "; getline(cin, password);
			User newUser(name, password);
			chat.AddUser(newUser);
			system("pause");
			system("cls");
		}
		break;

		case LOGIN: //����
			cout << "\t/ * * ����������� * */ \n"
				<< "������� �����: "; cin >> name;
			cin.ignore();
			cout << "������� ������" << endl;
			getline(cin, password);
			cout << name << endl;

			while (choise != LOGOUT) //����
			{
				cout << "�������� ��������\n 3.��������� ���������\n 4.��������\n 7.�����\n";
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
					cout << "������� �� �������\n";
					break;
				}
			}
			break;

		case EXIT:
			continue;
			break;
		default:
			cout << "������� �� �������" << endl;
			break;
		}
	}

	return 0;
}