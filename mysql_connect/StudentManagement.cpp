#include "StudentManagement.h"
//封装还可以更完美一点，比如说错误信息可以写在日志文件里面，而不是控制台。


StudentManagement::StudentManagement() {
	connector = mysql_init(NULL);
	mysql_options(connector, MYSQL_SET_CHARSET_NAME, "GBK"); //设置字符编码，防止乱码；
	if (!mysql_real_connect(connector,host, user, password, database_name, port, NULL, 0)) {
		fprintf(stderr, "Failed to connect to the database :%s\n", mysql_error(connector));
		exit(1);
	}
}


StudentManagement::~StudentManagement() {
	mysql_close(connector);
}

bool StudentManagement::insert(student_info& person)
{
	char sql[256];
	sprintf(sql, "insert into students (student_id,student_name,class_id) values(%d,'%s','%s')",
		person.student_id, person.student_name.c_str(), person.class_id.c_str());

	if (mysql_query(connector, sql)) {
		fprintf(stderr, "Failed to insert the data :%s\n", mysql_error(connector));
		return false;
	}
	return true;
}

//update函数中还有问题，当插入一个和已有内容主键相同的值时，没有插入成功，但不会报错。
bool StudentManagement::update(student_info& person)
{
	char sql[256];
	sprintf(sql, "update students set student_name ='%s',class_id ='%s'"
		"where student_id = %d",
		person.student_name.c_str(), person.class_id.c_str(),person.class_id);

	if (mysql_query(connector, sql)) {
		fprintf(stderr, "Failed to update the data :%s\n", mysql_error(connector));
		return false;
	}
	return true;
}


// DROP函数的不足是如果删除的主键不在table里面，则不会进行删除操作，但是也不报错。
bool StudentManagement::drop(int student_id)
{	
	char sql[256];
	sprintf(sql, "delete from students where student_id = %d", student_id);

	if (mysql_query(connector, sql)) {
		fprintf(stderr, "Failed to delete the data :%s\n", mysql_error(connector));
		return false;
	}
	return true;

}

vector<student_info> StudentManagement::get(student_info& person, string condition)
{
	char sql[256];
	sprintf(sql, "select * from students %s" ,condition.c_str());

	if (mysql_query(connector, sql)) {
		fprintf(stderr, "Failed to get the data :%s\n", mysql_error(connector));
		return {};
	}

	//查询结果
	MYSQL_RES* res = mysql_store_result(connector);
	MYSQL_ROW row;
	vector<student_info> results;
	while ((row = mysql_fetch_row(res))) {
		student_info temp;
		temp.student_id = atoi(row[0]); //返回结果是一个字符串，要转换成int；
		temp.student_name = row[1];
		temp.class_id = row[2];
		results.push_back(temp);

	}
	return results;
}

StudentManagement* StudentManagement::GetInstance()
{
	static StudentManagement StudentManagement;
	return &StudentManagement;

}
