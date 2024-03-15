#include <iostream>
#include "Message.h"
#include "User.h"


using namespace std;


auto main() -> int
{
	string x;
	string y;
	cin >> x >> y;
	User u(x, y);
	

	cout << u.getName() << " " << u.getPassword() << endl;


	return 0;
}