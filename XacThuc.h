#pragma once

#include <stdlib.h>
#include <iostream>
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include<cppconn/prepared_statement.h>
#include<sstream>
#include<algorithm>
#include<string>
#include <cstring>
#include <string>
#include <conio.h>
using namespace std;
using namespace sql;
class XacThuc {
private: string taikhoan, matkhau, matkhau2;
public: int DangNhap();
	  int DangKy();
	  void getTaiKhoan();
	  void getMatKhau();
	  void gettimer(int);
	  string hashFuction(string input);
};
