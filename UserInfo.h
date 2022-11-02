#pragma once
#include"XacThuc.h"
class UserInfo {
private:
	static XacThuc* xacThuc;

public:
	static int timeComplete;
	static string userTimeComplete;
	static XacThuc* getXacThuc();
	static void updateTimeComplete();
};