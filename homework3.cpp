#include <iostream>  
#include <string>  
using namespace std;  
 
 struct Word  
 {
     string Str;  
     int Count;   
 };  
 
 void CalcCount(Word *words,string &newWord,int size)  //ͳ�ƴ�Ƶ
 {  
     int i=0;  
     for(;i<size;i++)  
     {  
        if(words[i].Str==newWord)  
         {  
             words[i].Count++;  
             return;  
         }  
         else if(words[i].Str=="")  
             break;  
     }  
    words[i].Str=newWord;  
    words[i].Count =1;  
 }  

 int main()  
 {
     Word *words;  
     string content;  
     cout<<"����һ��Ӣ��:";  
     getline(cin, content);    //������������ָ���ַ���
   
     int wCount = 1;  
     for(unsigned int i=0; i<content.length();i++)    //���㵥������  
     {  
         if(content[i]==' ')  
             wCount++;  
     }  

     words=new Word[wCount];  
   
     string::size_type offset=content.find(' ');//���ʶ����Կո����  
     while(offset!=string::npos)  
     {  
         string wStr=content.substr(0,offset);   //string.substr()��0��ʼ���س���Ϊoffset���ַ���
	    if (wStr.length()<4)                //��ȥ����С��4�ĵ���
        {
            wCount--;
            content.erase(0,offset+1);
            offset=content.find(' ');
            continue;
        }
	 
         content.erase(0,offset+1);             //string.erase()ɾ����0��ʼ�ĳ���Ϊoffset+1���ַ���
         CalcCount(words,wStr,wCount);  
         offset=content.find(' ');   
	 }
	
    if (content.length()>= 4)
    {
        CalcCount(words, content, wCount);                           //�������һ������ 
    }
    else wCount--;

    for (int j=0; j<wCount; j++)
    {
        if (words[j].Str=="")
        {
            wCount--;
        }
    }
   

     for(i=0;i<wCount-1;i++)  
     {  
         cout << words[i].Str << "Ƶ��:" << words[i].Count << "��" << endl;  
     }  
    
	 delete [] words;  
     return 0;  
 }  