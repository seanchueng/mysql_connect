#include "StudentManagement.h"

int main() {
	StudentManagement* DBManager = StudentManagement::GetInstance();
	student_info a{ 9,"����","�˹�����" };
	student_info b{ 7,"����","���������" };
	student_info c{ 1,"����","���" };
	student_info d{ 1,"������","����" };
	//DBManager->insert(c);
	DBManager->insert(c);
	DBManager->drop(11);
	vector<student_info> res = DBManager->get(d);
	for (auto& i : res) {
		cout << i.student_id << "  " << i.student_name << "  " << i.class_id << endl;
	}

	return 0;
}