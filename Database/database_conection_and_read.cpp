#include <iostream>
#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

#define SERVER "localhost"
#define USER "pi"
#define PASSWORD "123456"
#define DATABASE "HelloWorld"

int main() {
	MYSQL *connect;
	connect=mysql_init(NULL);

	if (!connect)
	{
		cout<<"MySQL Initialization failed";
		return 1;
	}

	if (mysql_real_connect(connect, SERVER, USER, PASSWORD,
	DATABASE,0,NULL,0) == NULL )
	{
		cout<<"connection failed\n";
	}
	else
	{
		cout<<"connection Succeeded\n";
	}

	MYSQL_RES *res_set;
	MYSQL_ROW row;
	mysql_query (connect,"SELECT * from User;");
	unsigned int i =0;
	res_set = mysql_store_result(connect);
	unsigned int numrows = mysql_num_rows(res_set);

	while (((row= mysql_fetch_row(res_set)) !=NULL ))
	{ //cout<<" %s\n",row[i] !=NULL?row[i] : "NULL";

		cout <<"\t | \t" << row[i] << "\t | \t";
		cout <<  row[i+1] <<  "\t |"<< endl;
	}

mysql_close (connect);
return 0;
}
