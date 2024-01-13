#include "Sale.h"
using namespace std;
using namespace sql;

Sale::Sale(ResultSet* data) {

	value = data->getDouble("value");
	date = data->getString("date");
	package_name = data->getString("packagename");

	
}

vector<Sale> Sale::salesReport(string start, string end, vector <int> packageID, bool sortByDate, bool ascending) {


	string package_nameString = "";
	if (packageID.size() > 0) {
		package_nameString = " AND pc.package_name IN (";
		for (int i = 0; i < packageID.size(); i++) {
			package_nameString += "?,";
		}

		package_nameString.erase(package_nameString.size() - 1);
		package_nameString += ") ";

	}


	string sql = " SELECT p.dateTime as date, pc.package_name as packagename, SUM(p.Total_Payment) as value "
		" FROM payment p "
		" JOIN package pc ON p.packageID = pc.packageID "
		+ package_nameString;


	sql += " WHERE p.dateTime >= ? AND p.dateTime <= ? ";

	sql += "GROUP BY ";
		if (!packageID.empty()) {

			sql += "pc.package_name, ";
		}

	sql += " CAST(MONTH(p.dateTime) AS VARCHAR(2)) + '-' + CAST(YEAR(p.dateTime) AS VARCHAR(4)) ";

	sql += " ORDER BY ";
	if (sortByDate) {

		sql += " p.dateTime";
	}
	else {

		sql += " value ";
	}
	

	if (ascending) {
		sql += " ASC ";
	}
	else {
		sql += " DESC ";
	}

	vector <Sale> salesReport;

	DBConnection db;

	db.prepareStatement(sql);

	int index = 1;

	while (index <= packageID.size()) {

		db.stmt->setInt(index, packageID[index - 1]);
		index++;

	}

	db.stmt->setString(index, start);
	index++;
	db.stmt->setString(index, end);
	db.QueryResult();

	if (db.res->rowsCount() > 0) {

		while (db.res->next()) {
			Sale tmpSale(db.res);
			salesReport.push_back(tmpSale);
		}
	}

	db.~DBConnection();
	return salesReport;



}