
#include <stdlib.h>
#include <iostream>
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include<sstream>
#include<algorithm>
#include<string>
#include <cstring>
#include <string>
#include <conio.h>
using namespace std;
using namespace sql;
class xacThuc {
private: string taikhoan, matkhau, matkhau2;
public: int DangNhap();
	  int DangKy();
	  void getTaiKhoan();
	  void getMatKhau();
	  void gettimer(int timer);
	  string hashFuction(string input);
};
void xacThuc::gettimer(int timer) {
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
		res = stmt->executeQuery("SELECT * FROM timer");
		while (res->next()) {
			const string arr = res->getString("name");
			const string arr1 = res->getString("");
			const int  id = res->getInt("id");
			const string name = this->taikhoan;
			const int  timecomplete = timer;
			stmt->execute("INSERT INTO timer(name,timer) VALUES(\'@name'\,\'timecomplete'\)");	
		}

		delete stmt;
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
	if (strcmp(s1, s2) == 0) {

	}
}
int  xacThuc::DangNhap() {
	char pass[100];
	int i=1;
	cout << "Tai Khoan: ";
	cin >> this->taikhoan;   
	cout << "Mat Khau: ";
	cin >> this->matkhau;
	xacThuc::hashFuction(this->matkhau);
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
		while (res->next()) {
		 const string arr = res->getString("name");
		 const string arr1 = res->getString("password");
		 const int  id = res->getInt("id");
		 const string name = this->taikhoan;
		 const string password = xacThuc::hashFuction(this->matkhau);
		 cout << name <<endl ;
		 cout << password << endl;
		 cout << arr << endl;
		 cout << arr1 << endl;
		 for (int i=0;i<id;i++)
		if (SoSanh(arr,name)==true) {
			if (SoSanh(arr1,password)==true) {
				cout << "DANG NHAP THANH CONG";
				return true;
			}
			else {
				cout << "MAT KHAU CUA BAN KHONG CHINH XAC";
				xacThuc::DangNhap();
			}
		}
		else {
			cout << "Tai Khoan cua ban khong chinh xac" << endl;
			xacThuc::DangNhap();
		}
		}
		
		delete stmt;
		delete con;

	}
	catch (SQLException& e) {
		cout << "error";
	}
};
string xacThuc::hashFuction(string input) {
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
int  xacThuc::DangKy() {
	cout << "Tai Khoan: ";
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
			if(SoSanh(namee,taikhoan) == true ){
				cout << "tai khoan da ton tai trong co so du lieu"<<endl;
				cout << "vui long dang ky lai" << endl;
				xacThuc::DangKy();
				
			}

		}
		delete stmt;
		delete con;

	}
	catch (SQLException& e) {
		cout << "error";
	}
	cout << "Mat Khau: ";
	cin >> this->matkhau;
	cout << "Nhap lai Mat Khau: ";
	cin >> this->matkhau2;
	if (this->matkhau == this->matkhau2) {
		cout << "Dang ky thanh cong";
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
			const string taikhoan = this->taikhoan;
			const string matkhau2 = xacThuc::hashFuction(this->matkhau);
			stmt->execute("INSERT INTO user(name,password) VALUES(\'@taikhoan'\,\'@matkhau2'\)");
			res = stmt->executeQuery("SELECT * FROM user");
			delete stmt;
			delete con;

		}
		catch (SQLException& e) {
			cout << "error";
		}
		return 1;
	}
	else {
		cout << "Mat Khau khong trung khop!" << endl;
		cout << "Vui long dang ky lai !" << endl;
		xacThuc::DangKy();
	};
};


int main()
{
	xacThuc x;
	int a;
	cout << "1. Dang nhap" << endl;
	cout << "2. Dang ky" << endl;
	cout << "Nhap lua chon cua ban: "; cin >> a;
	switch (a) {
	case 1: {
		x.DangNhap(); break; }
	case 2: {
		x.DangKy(); break; }
	}
    return 0;
}