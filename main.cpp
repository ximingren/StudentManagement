#include "ClassHead.h"
#include <iostream>
#include<fstream>
#include <vector>

int main()
{
    char in_choose;
    char second_choose;
    string file_name="data.dat";
    fstream file(file_name,ios_base::in|ios_base::out|ios_base::binary);
    do
    {
        cout<<"\t\ta.学生成绩插入"<<endl;
        cout<<"\t\tb.学生成绩查询"<<endl;
        cout<<"\t\tc.班级学生成绩查询"<<endl;
        cout<<"\t\td.学生成绩删除"<<endl;
        cout<<"\t\te.载入数据"<<endl;
        cout<<"\t\tg.退出系统"<<endl;

        cin>>in_choose;
        switch(in_choose)
        {
        case 'a':
            InsertStudent();
            save();
            break;
        case 'b':
             cout<<"\t\ta.查询学生的所有科目成绩"<<endl;
              cout<<"\t\tb.查询学生的不及格科目成绩"<<endl;
              cin>>second_choose;
            switch(second_choose)
            {
               case'a':
                searchByStuId(0);
                break;
               case'b':
                searchByStuId(1);//查询该生不及格的科目成绩
                break;
            }
             break;
        case 'c':
            cout<<"\t\ta.查询班级所有的学生成绩"<<endl;
            cout<<"\t\tb.列出成绩不及格的学生名单"<<endl;
            cin>>second_choose;
            switch(second_choose)
            {
            case 'a':
                searchByClass(0);
                break;
            case'b':
                searchByClass(1);//查询该班所有不及格的学生的成绩
                break;
            }
             break;
        case 'd':
             deleteByStuId();
             break;
        case 'e':
            for(int i=0;i<1;i++)
                file.read(reinterpret_cast<char*>(&clas[i]),sizeof(clas[i]));
            cout<<"载入数据成功"<<endl;
            break;
         default:
            cout<<"选择错误，请重新选择"<<endl;
        }
    }while(in_choose!='g');
}
