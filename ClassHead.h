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
    int score[3];//3��,����Ӣ
    string name;//����
    int stu_id;//ѧ��
    string gender;//�Ա�
public:
    Student()
    {
        //���캯��
        stu_id=0;
    }
    void setInfo();//������Ϣ�óɼ�
    void displayInfo(int flag);//��ʾ��Ϣ
    int getId();//����ѧ��
    void setId(int Id);//����ѧ��
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
