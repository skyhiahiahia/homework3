#include <iostream>  
#include <string>  
using namespace std;  
 
 struct Word  
 {
     string Str;  
     int Count;   
 };  
 
 void CalcCount(Word *words,string &newWord,int size)  //统计词频
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
     cout<<"输入一段英文:";  
     getline(cin, content);    //从输入流读入指定字符串
   
     int wCount = 1;  
     for(unsigned int i=0; i<content.length();i++)    //计算单词总数  
     {  
         if(content[i]==' ')  
             wCount++;  
     }  

     words=new Word[wCount];  
   
     string::size_type offset=content.find(' ');//单词都是以空格隔开  
     while(offset!=string::npos)  
     {  
         string wStr=content.substr(0,offset);   //string.substr()从0开始返回长度为offset的字符串
	    if (wStr.length()<4)                //除去长度小于4的单词
        {
            wCount--;
            content.erase(0,offset+1);
            offset=content.find(' ');
            continue;
        }
	 
         content.erase(0,offset+1);             //string.erase()删除从0开始的长度为offset+1的字符串
         CalcCount(words,wStr,wCount);  
         offset=content.find(' ');   
	 }
	
    if (content.length()>= 4)
    {
        CalcCount(words, content, wCount);                           //计算最后一个单词 
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
         cout << words[i].Str << "频率:" << words[i].Count << "次" << endl;  
     }  
    
	 delete [] words;  
     return 0;  
 }  