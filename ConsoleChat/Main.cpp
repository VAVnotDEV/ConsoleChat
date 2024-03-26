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
		cout << "\n\t****���������� ���****\n" << REGISTER << ".�����������\n" << LOGIN << ".����\n"  << EXIT << ".�����\n" << "������� ������� : ";

		cin >> choise;
		cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


			switch (choise)
			{
				//�����������
			case REGISTER:
			{
				cout << "\t/ * * ����������� ������ ������������ * */ \n" << "���������� �����: "; cin >> login;
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
				cout << "������� ������: "; cin >> password;

				//������ ������������
				if (chat.loginUser(login, password))
				{
					while (choise != LOGOUT)
					{
						string text, reciever;
						system("cls");
						cout << "\n������������, " << login << "!\n" << "�������� �������� ��� ��������\n";

						chat.listUsers(login);

						cout << SEND_ALL << ".��������� ����\n" << LOGOUT << ".�����\n" << "\n�������� �������: ";  cin >> choise;
						cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

						if (choise == SEND_ALL)		//��������
						{
							while (text != "exit")
							{
								cin.ignore();
								cout << "��������� (��� ������ ������� exit): "; cin >> text;
								chat.sendAllMessage(login, text);
								cout << login << " :" << text << endl;
							}
						}
						else if (choise == LOGOUT)	//����� ������������
						{
							break;
						}
						else						//�������� ��������� ������������
						{
							try {
								reciever = chat.getContact(choise);
								chat.displayAllMessages(login, reciever);
								while (text != "exit")
								{
									cin.ignore();
									cout << "��������� (��� ������ ������� exit): "; cin >> text;
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
			case EXIT:		//���������� ������ ���������
				break;
			default:
				cout << "������� ������� �������" << endl;
				break;
			}
	}

	return 0;
}