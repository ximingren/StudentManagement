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
        cout<<"\t\ta.ѧ���ɼ�����"<<endl;
        cout<<"\t\tb.ѧ���ɼ���ѯ"<<endl;
        cout<<"\t\tc.�༶ѧ���ɼ���ѯ"<<endl;
        cout<<"\t\td.ѧ���ɼ�ɾ��"<<endl;
        cout<<"\t\te.��������"<<endl;
        cout<<"\t\tg.�˳�ϵͳ"<<endl;

        cin>>in_choose;
        switch(in_choose)
        {
        case 'a':
            InsertStudent();
            save();
            break;
        case 'b':
             cout<<"\t\ta.��ѯѧ�������п�Ŀ�ɼ�"<<endl;
              cout<<"\t\tb.��ѯѧ���Ĳ������Ŀ�ɼ�"<<endl;
              cin>>second_choose;
            switch(second_choose)
            {
               case'a':
                searchByStuId(0);
                break;
               case'b':
                searchByStuId(1);//��ѯ����������Ŀ�Ŀ�ɼ�
                break;
            }
             break;
        case 'c':
            cout<<"\t\ta.��ѯ�༶���е�ѧ���ɼ�"<<endl;
            cout<<"\t\tb.�г��ɼ��������ѧ������"<<endl;
            cin>>second_choose;
            switch(second_choose)
            {
            case 'a':
                searchByClass(0);
                break;
            case'b':
                searchByClass(1);//��ѯ�ð����в������ѧ���ĳɼ�
                break;
            }
             break;
        case 'd':
             deleteByStuId();
             break;
        case 'e':
            for(int i=0;i<1;i++)
                file.read(reinterpret_cast<char*>(&clas[i]),sizeof(clas[i]));
            cout<<"�������ݳɹ�"<<endl;
            break;
         default:
            cout<<"ѡ�����������ѡ��"<<endl;
        }
    }while(in_choose!='g');
}
