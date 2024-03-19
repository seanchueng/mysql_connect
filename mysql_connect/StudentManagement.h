#pragma once
#include <mysql.h>
#include<iostream>
#include <string>
#include <vector>
using namespace std;

struct student_info {
	int student_id;
	string student_name;
	string class_id;
};


class StudentManagement
{	
	//一些Mysql连接参数
	const char* host = "127.0.0.1";
	const char* user = "root";
	const char* password = "6300";
	const char* database_name = "student_management";
	const int port = 3306;

	MYSQL* connector;


public:

	StudentManagement();
	~StudentManagement();

	bool insert(student_info& person);
	bool update(student_info& person);
	bool drop(int student_id);
	vector<student_info> get(student_info& person,string condition ="");


public:
	static StudentManagement* GetInstance(); //单例模式
};

