
//阿里一面

//（1）new和malloc的区别

//（2）指针和引用

//（3）做题
//第一题：不申请额外空间，去掉字符串中单空格
#include <iostream>
 using namespace std;
 int main()
 {


     string s1="adcdef";
     string s2=s1;
     //char* p =&s1[2];
     //*p='d';
     printf("s1addr=%x\n",&s1[0]);
     printf("s2addr=%x\n",&s2[0]);

     char arr[] = "abc d efg  ";
     int i=0;
     int j = 0;
     while(arr[i])
     {
         if(arr[i]==' ')
         {
             j=j>0?j:i;
             while(arr[++j]&&arr[j]==' ');

             while(arr[j]&&arr[j]!=' ')
             {
                 arr[i++] = arr[j++];
             }

             //if(!arr[i])
             //{
                arr[i] = arr[j];
                //return 0;
             //}
         }
         else
         {
             i++;
         }
     }

     //cout<<arr<<endl;


 }

//第二题：两个类AB，B继承A，有函数虚继承，有个没虚继承，B *b=new B, A *a=(A*)b,(B*)a问了四个输出



 //第三题：手写一个String类，满足写时拷贝，实现构造析构，拷贝，移动构造，赋值=，c_str,size，empty，reserve函数
