#include "XacThuc.h"
#include <stdio.h> 
#include <conio.h> 
#include<ctime> 
#include <windows.h>
#include <iostream>

//============== dịch con trỏ hiện tại đến điểm có tọa độ (x,y) ==========
void gotoXY(int x, int y) {
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x, y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}
//============= đặt màu cho chữ =========
void SetColor(WORD color) {
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
//============== làm ẩn trỏ chuột ===========
void ShowCur(bool CursorVisibility) {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}
//======= chỉnh màu =========
void textcolor(int x) {
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}
void XacThuc::gettimer(int seconds) {
	try {
		Driver* driver;
		Connection* con;
		Statement* stmt;
		PreparedStatement* ptmt;
		ResultSet* res;
		/* Create a connection */
		driver = get_driver_instance();
		con = driver->connect("tcp://127.0.0.1:3306", "root", "1234");
		/* Connect to the MySQL test database */
		con->setSchema("sodoku");
		string sql = "INSERT INTO timer(name,timecomplete) VALUES(?, ?)";
		ptmt = con->prepareStatement(sql);
		ptmt->setString(1, this->taikhoan);
		ptmt->setInt(2, seconds);
		ptmt->execute();
		delete ptmt;
		
		delete con;

	}
	catch (SQLException& e) {
		cout << "error";
	}

}

bool SoSanh(string s1, string s2)
{

	for (int i = 0; i < s1.size(); i++)
		s1[i] = toupper(s1[i]);

	for (int i = 0; i < s2.size(); i++)
		s2[i] = toupper(s2[i]);

	if (s1.compare(s2) == 0)
	{
		return true;
	}

	return false;

}
int  XacThuc::DangNhap() {
	SetColor(9); gotoXY(45, 6); printf("========= DANG NHAP =========");
	SetColor(9); gotoXY(50, 9); cout << "Tai Khoan: ";
	cin >> this->taikhoan;
	SetColor(12); gotoXY(50, 13); cout << "Mat Khau: ";
	cin >> this->matkhau;
	XacThuc::hashFuction(this->matkhau);
	try {
		Driver* driver;
		Connection* con;
		PreparedStatement* ptmt;
		
		ResultSet* res;
		/* Create a connection */
		driver = get_driver_instance();
		con = driver->connect("tcp://127.0.0.1:3306", "root", "1234");
		/* Connect to the MySQL test database */
		con->setSchema("sodoku");
		string sql = "SELECT * FROM user WHERE name = ?";
		ptmt = con->prepareStatement(sql);
		ptmt->setString(1, taikhoan);
		res = ptmt->executeQuery();
		string nameDB = "";
		string passwordDB = "";
		while (res->next()) {
			nameDB = res->getString("name");
			passwordDB = res->getString("password");
		}

		if (nameDB != "") {
			cout << "End check";
			if (passwordDB == matkhau) {
				return 1;
			}else {
				XacThuc::DangNhap();
			}
		}else { 
			return 0;
		}
		

		delete ptmt;
		delete con;

	}
	catch (SQLException& e) {
		cout << "error";
	}
	return 0;
};
string XacThuc::hashFuction(string input) {
	unsigned int  Init = 2309813;
	unsigned int  keynum = 18231311;
	unsigned int  hash;
	for (int i = 0; i < input.length(); i++) {
		hash = hash ^ input[i]; hash = hash * keynum;
	}
	string hexHash;
	stringstream hexstream;
	hexstream << hex << hash;
	hexHash = hexstream.str();
	transform(hexHash.begin(), hexHash.end(), hexHash.begin(), ::toupper);
	return hexHash;
}

int  XacThuc::DangKy() {
	system("cls");
	SetColor(9); gotoXY(45, 6); printf("========= DANG KY =========");
	SetColor(9); gotoXY(52, 9); cout << "Tai Khoan: ";
	cin >> this->taikhoan;
	try {
		Driver* driver;
		Connection* con;
		Statement* stmt;
		ResultSet* res;
		/* Create a connection */
		driver = get_driver_instance();
		con = driver->connect("tcp://127.0.0.1:3306", "root", "1234");
		/* Connect to the MySQL test database */
		con->setSchema("sodoku");
		stmt = con->createStatement();
		res = stmt->executeQuery("SELECT * FROM user");
		const string  taikhoan = this->taikhoan;
		while (res->next()) {
			const string namee = res->getString("name");
			if (SoSanh(namee, taikhoan) == true) {
				SetColor(9); gotoXY(52, 10); cout << "tai khoan da ton tai trong co so du lieu" << endl;
				SetColor(9); gotoXY(52, 11); cout << "vui long dang ky lai" << endl;
				system("pause");
				XacThuc::DangKy();

			}

		}
		delete stmt;
		delete con;

	}
	catch (SQLException& e) {
		cout << "error";
	}
	SetColor(9); gotoXY(52, 12); cout << "Mat Khau: ";
	cin >> this->matkhau;
	SetColor(9); gotoXY(52, 13); cout << "Nhap lai Mat Khau: ";
	cin >> this->matkhau2;
	if (this->matkhau == this->matkhau2) {
		try {
			Driver* driver;
			Connection* con;
			PreparedStatement* ptmt;
			ResultSet* res;
			/* Create a connection */
			driver = get_driver_instance();
			con = driver->connect("tcp://127.0.0.1:3306", "root", "1234");
			/* Connect to the MySQL test database */
			con->setSchema("sodoku");
			string sql = "INSERT INTO user(name,password) VALUES(?, ?)";
			ptmt = con->prepareStatement(sql);
			ptmt->setString(1, taikhoan);
			ptmt->setString(2, matkhau);
			ptmt->execute();
			const string taikhoan = this->taikhoan;

			const string matkhau2 = XacThuc::hashFuction(this->matkhau);
			//stmt->execute("INSERT INTO user(name,password) VALUES(\'@taikhoan'\,\'@matkhau2'\)");


			delete ptmt;
			delete con;

		}
		catch (SQLException& e) {
			SetColor(9); gotoXY(52, 14); cout << "error";
			system("pause");
		}
		return 1;
	}
	else {
		SetColor(9); gotoXY(52, 15); cout << "Mat Khau khong trung khop!" << endl;
		SetColor(9); gotoXY(52, 16); cout << "Vui long dang ky lai !" << endl;
		system("pause");
		XacThuc::DangKy();
	};
};