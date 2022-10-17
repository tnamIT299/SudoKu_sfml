#pragma once
#include"XacThuc.h"
class UserInfo {
private:
	static XacThuc* xacThuc;

public:
	static XacThuc* getXacThuc();
};