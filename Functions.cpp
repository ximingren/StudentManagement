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
            //�����Ǽ���Ƿ����ظ���ѧ������
            if(clas[i].getClassId()!=0)
            {
                Student* students=clas[i].getStudents();
                //���length��������
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

    cout<<"��������"<<endl;
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
    cout<<"��������Ҫ��ѯ��ѧ����ѧ�ţ�"<<endl;
    do
    {
        cin>>in_number;
        if(in_number<1)
            cout<<"��������������������"<<endl;
    }while(in_number<1);
    Student stu=findStudent(in_number);
    if(stu.getId()==0)
        cout<<"�Ҳ�����ѧ������Ϣ"<<endl;
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
    cout<<"��������Ҫ��ѯ�İ༶�İ�ţ�"<<endl;
    do
    {
        cin>>in_number;
        if(in_number<1)
            cout<<"��������������������"<<endl;
    }while(in_number<1);
    for(int i=0;i<length(clas);i++)
    {
        if(clas[i].getClassId()==in_number)
        {
               students=clas[i].getStudents();
               break;
        }
    }
    //TODO ���30
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
    cout<<"������Ҫɾ����ѧ����ѧ��"<<endl;
    cin>>in_number;
    Student stu=findStudent(in_number);
    if(stu.getId()==0)
        cout<<"�Ҳ�����ѧ������Ϣ"<<endl;
    else
    {
          stu.setId(0);
          cout<<"ɾ���ɹ�"<<endl;
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
    cout<<"�������ݳɹ�"<<endl;
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
            cout<<name<<"��"<<score<<endl;
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
        cout<<"������ѧ����ѧ��"<<endl;
        flag=0;
        cin>>in_number;
        Student stu=findStudent(in_number);
        if(stu.getId()!=0)
        {
              cout<<"�Ѿ�����ͬ��ѧ�ţ�����������"<<endl;
              flag=1;
        }
        if(in_number<1)
            cout<<"���������������������������"<<endl;
    }while(in_number<1||flag==1);
    stu_id=in_number;
    cout << "������\t����\t�Ա�\t����\t��ѧ\tӢ��"<<endl;
    cin>>name>>gender>>score[0]>>score[1]>>score[2];
}

void Student::displayInfo(int flag)
{
    string prom;
    if(flag==0)
    {
        cout<<"\tѧ��\t����\t�Ա�\t����\t��ѧ\tӢ��\tƽ����\t�ܷ�"<<endl;
        cout<<"\t"<<stu_id<<"\t"<<name<<"\t"<<gender<<"\t"<<score[0]<<"\t"<<score[1]<<"\t"<<score[2]<<"\t"<<getAverage()<<"\t"<<getTotal_score()<<endl;
    }
    else if(flag==1)
    {
        prom="\tѧ��\t����\t�Ա�";
        if(score[0]<60)
            prom=prom+"\t����";
        if(score[1]<60)
             prom=prom+"\t��ѧ";
        if(score[2]<60)
             prom=prom+"\tӢ��";
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

