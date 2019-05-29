#ifndef ClassHead
#define ClassHead
#include <iostream>
#include <string>

using namespace std;

class Subject
{
private:
    int score;
    string name;
public:
    void setScore();
    void setName(string name);
    void displayScore(int flag);
};


class Student
{
private:
    int score[3];//3科,语数英
    string name;//姓名
    int stu_id;//学号
    string gender;//性别
public:
    Student()
    {
        //构造函数
        stu_id=0;
    }
    void setInfo();//设置信息好成绩
    void displayInfo(int flag);//显示信息
    int getId();//返回学号
    void setId(int Id);//设置学号
    int getTotal_score();
    int getAverage();
};

class Class
{

private:
    Student students[30];
    int class_id;
public:
    Class()
    {
        class_id=0;
    }
    void setStudent();
    int getClassId();
    void setClassId(int class_id);
    Student * getStudents();
};

Student findStudent(int in_number);
void InsertStudent( );
void searchByStuId(int flag);
void searchByClass(int flag);
void deleteByStuId();
void countScoreByClass(int reverse_flag);
void save();
extern Class clas[3];
#endif
