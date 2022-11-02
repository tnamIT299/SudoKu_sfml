#include"UserInfo.h"
XacThuc* UserInfo::xacThuc = new XacThuc;
XacThuc*  UserInfo::getXacThuc() {
	return xacThuc;
}

int UserInfo::timeComplete = -1;
string UserInfo::userTimeComplete = "";

void UserInfo::updateTimeComplete() {
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
		string sql = "SELECT * FROM timer";
		ptmt = con->prepareStatement(sql);
		res = ptmt->executeQuery();
		if (res->next()) {
			if (timeComplete == -1) {
				timeComplete = res->getInt("timecomplete");
				userTimeComplete = res->getString("name");
			}
		}
		while (res->next()) {
			if (res->getInt("timecomplete") < timeComplete) {
				timeComplete = res->getInt("timecomplete");
				userTimeComplete = res->getString("name");
			}
		}
		delete ptmt;
		delete con;

	}
	catch (SQLException& e) {
		cout << "error";
	}
}
 