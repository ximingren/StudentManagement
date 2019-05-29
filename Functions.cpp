#include "ClassHead.h"
#include <string>
#include <iostream>
#include<fstream>
Class clas[3]={Class()};
template<class T>
int length(T&arr)
{
    return sizeof(arr)/sizeof(arr[0]);
}

Student findStudent(int in_number)
{
     for(int i=0;i<length(clas);i++)
        {
            //这里是检测是否有重复的学生数据
            if(clas[i].getClassId()!=0)
            {
                Student* students=clas[i].getStudents();
                //这个length很有问题
                for(int j=0;j<1;j++)
                {
                    if(students[j].getId()==in_number)
                    {
                       return students[j];
                    }
                }
            }
        }
        return Student();
}
void InsertStudent( )
{

    int class_id;

    cout<<"请输入班号"<<endl;
    cin>>class_id;

    for(int i=0;i<length(clas);i++)
    {
        if(clas[i].getClassId()==class_id)
        {
             clas[i].setStudent();
             break;
        }
        else if(clas[i].getClassId()==0)
        {
            clas[i].setClassId(class_id);
             clas[i].setStudent();
             break;
        }
    }
}

void searchByStuId(int flag)
{
    int in_number;
    cout<<"请输入所要查询的学生的学号："<<endl;
    do
    {
        cin>>in_number;
        if(in_number<1)
            cout<<"请重新输入大于零的整数"<<endl;
    }while(in_number<1);
    Student stu=findStudent(in_number);
    if(stu.getId()==0)
        cout<<"找不到该学生的信息"<<endl;
    else
        stu.displayInfo(flag);
}

void searchByClass(int flag)
{
     int in_number;
     int *sort_students;
     Student* students;
//    Student sort_students[30]=students;
     Student *temp;
    cout<<"请输入所要查询的班级的班号："<<endl;
    do
    {
        cin>>in_number;
        if(in_number<1)
            cout<<"请重新输入大于零的整数"<<endl;
    }while(in_number<1);
    for(int i=0;i<length(clas);i++)
    {
        if(clas[i].getClassId()==in_number)
        {
               students=clas[i].getStudents();
               break;
        }
    }
    //TODO 这个30
    for(int i=0;i<30;i++)
    {
        if(students[i].getId()!=0)
        {

            for(int j=i+1;j<30;j++)
            {
                 if(students[j].getId()!=0)
                {
                    if(students[i].getAverage()<students[j].getAverage())
                    {
                        (students+i)->name;
                        temp=(students+i);
                        //(students+i)=(students+j);
                        //students[j].setId(0);
                        (students+j)=temp;

                    }
                }
            }
        }
    }
    for(int i=0;i<30;i++)
    {
        if(students[i].getId()!=0)
        {
          students[i].displayInfo(flag);
        }
    }
}
void deleteByStuId()
{
    int in_number;
    cout<<"请输入要删除的学生的学号"<<endl;
    cin>>in_number;
    Student stu=findStudent(in_number);
    if(stu.getId()==0)
        cout<<"找不到该学生的信息"<<endl;
    else
    {
          stu.setId(0);
          cout<<"删除成功"<<endl;
          save();
    }
}
void save()
{
    fstream file("data.dat",ios::out|ios::binary);
    if(!file)
    {
        cout<<"file coun't open."<<endl;
        abort();
    }
    for(int i=0;i<1;i++)
        file.write(reinterpret_cast<char*>(&clas[i]),sizeof(clas[i]));
    cout<<"保存数据成功"<<endl;
    file.close();
}
void Subject::setName(string nam)
{
    name=nam;
}
void Subject::setScore()
{
    cin>>score;
}

void Subject::displayScore(int flag)
{
    if(flag==0)
        cout<<name<<": "<<score<<endl;
    else if(flag==1)
    {
        if(score<60)
            cout<<name<<"："<<score<<endl;
    }

}

void Student::setId(int id)
{
    stu_id=id;
}
void Student::setInfo()
{

    int flag,in_number;
    do
    {
        cout<<"请输入学生的学号"<<endl;
        flag=0;
        cin>>in_number;
        Student stu=findStudent(in_number);
        if(stu.getId()!=0)
        {
              cout<<"已经有相同的学号，请重新输入"<<endl;
              flag=1;
        }
        if(in_number<1)
            cout<<"输入错误，请重新输入大于零的整数"<<endl;
    }while(in_number<1||flag==1);
    stu_id=in_number;
    cout << "请输入\t姓名\t性别\t语文\t数学\t英语"<<endl;
    cin>>name>>gender>>score[0]>>score[1]>>score[2];
}

void Student::displayInfo(int flag)
{
    string prom;
    if(flag==0)
    {
        cout<<"\t学号\t姓名\t性别\t语文\t数学\t英语\t平均分\t总分"<<endl;
        cout<<"\t"<<stu_id<<"\t"<<name<<"\t"<<gender<<"\t"<<score[0]<<"\t"<<score[1]<<"\t"<<score[2]<<"\t"<<getAverage()<<"\t"<<getTotal_score()<<endl;
    }
    else if(flag==1)
    {
        prom="\t学号\t姓名\t性别";
        if(score[0]<60)
            prom=prom+"\t语文";
        if(score[1]<60)
             prom=prom+"\t数学";
        if(score[2]<60)
             prom=prom+"\t英语";
        cout<<prom<<endl;
        cout<<"\t"<<stu_id<<"\t"<<name<<"\t"<<gender;
         if(score[0]<60)
           cout<<score[0]<<"\t";

        if(score[1]<60)
           cout<<score[1]<<"\t";

        if(score[2]<60)
            cout<<score[2];
        cout<<endl;
    }
}

int Student::getId()
{
    return stu_id;
}
int Student::getTotal_score()
{
    return (score[0]+score[1]+score[2]);
}
int Student::getAverage()
{
    return (score[0]+score[1]+score[2])/3.0;
}
void Class::setClassId(int id)
{
    this->class_id=id;

}

void Class::setStudent()
{

    for(int i=0;i<length(students);i++)
    {
        if(students[i].getId()==0)
        {
             students[i].setInfo();
             break;
        }
    }
}
int Class:: getClassId()
{
    return class_id;
}
Student* Class::getStudents()
{
    return students;
}

