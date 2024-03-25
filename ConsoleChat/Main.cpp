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
		cout << "\n\t****���������� ���****\n" << "1.����������� \n2.����\n3.�����\n" << "������� �������: ";
		cin >> choise;

		switch (choise)
		{
			//�����������
		case REGISTER:
		{
			cout << "\t/ * * ����������� ������ ������������ * */ \n"
				<< "���������� �����: "; cin >> login;
			cin.ignore();
			cout << "���������� ������: "; getline(cin, password);

			User newUser(login, password);
			chat.addUser(newUser);

			system("pause");
			system("cls");
		}
		break;
		//�����������
		case LOGIN:
			cout << "\n\t/ * * ����������� * */ \n" << "������� �����: "; cin >> login;
			cin.ignore();
			cout << "������� ������: "; cin >> password;

			if (chat.loginUser(login, password))
			{
				while (choise != LOGOUT)
				{
					string text, reciever;
					cout << "\n�������� ��������\n 3.��������� ������ ���������\n 4.��������\n 7.�����\n"; cin >> choise;

					switch (choise)
					{
					case SEND:
					{
						chat.listUsers(login);
						cout << "�������� ��������" << endl; cin >> reciever;
						cin.ignore();
						cout << "������� ���������: "; getline(cin, text);
						chat.sendMessage(login, reciever, text);
						chat.displayMessages(login, reciever);
					}
					break;

					case SEND_ALL:
						cout << "��������� ����\n";
						cin >> text;
						chat.sendAllMessage(login, text);
						break;
					case LOGOUT:
						break;
					default:
						cout << "������� �� �������\n";
						break;
					}
				}
			}
				break;

		case EXIT:			//�����
			continue;
			break;
		default:
			cout << "������� �� �������" << endl;
			break;
			}
		}

		return 0;
	}