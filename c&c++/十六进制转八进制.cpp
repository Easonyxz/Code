#include<stdio.h>
#include<math.h>
#include<string.h>
#include<iostream>
using namespace std;

int main()  
{  
   int n = 0, i = 0, j = 0, temp = 0, nNum = 0;  
   char ch;  
   string strHex[10];  
   string strBin[10];  
   string strOct[10];  

   cin>>n;  
   for (i = 0; i < n; ++i)  
   {  
       cin>>strHex[i];  
   }  

   //十六进制转二进制  
   for (i = 0; i < n; ++i)  
   {  
       j = 0;  
       while (strHex[i][j])  
       {  
           switch(strHex[i][j])  
           {  
           case '0': strBin[i] += "0000"; break;  
           case '1': strBin[i] += "0001"; break;  
           case '2': strBin[i] += "0010"; break;  
           case '3': strBin[i] += "0011"; break;  
           case '4': strBin[i] += "0100"; break;  
           case '5': strBin[i] += "0101"; break;  
           case '6': strBin[i] += "0110"; break;  
           case '7': strBin[i] += "0111"; break;  
           case '8': strBin[i] += "1000"; break;  
           case '9': strBin[i] += "1001"; break;  
           case 'A': strBin[i] += "1010"; break;  
           case 'B': strBin[i] += "1011"; break;  
           case 'C': strBin[i] += "1100"; break;  
           case 'D': strBin[i] += "1101"; break;  
           case 'E': strBin[i] += "1110"; break;  
           case 'F': strBin[i] += "1111"; break;  
           default:break;  
           }  
           ++j;  
       }  
   }  

   //二进制转化为八进制  
   for (i = 0; i < n; ++i)  
   {  
       j = strBin[i].size()-1;//获得长度  
       while (strBin[i][j] && j>=0)  
       {  
           temp = 3;  
           nNum = 0;  
           while (temp-- && j>=0)  
           {  
               if ('1' == strBin[i][j])  
               {  
                   switch(temp)  
                   {  
                   case 0: nNum += 4; break;  
                   case 1: nNum += 2; break;  
                   case 2: nNum += 1; break;  
                   default:break;  
                   }  
               }  
               --j;  
           }  
           strOct[i] += (nNum+'0');  
       }  
   }  

   //字符串逆序  
   for (i = 0; i < n; ++i)  
   {  
       temp = strOct[i].size()-1;  
       for (j = 0; j <= temp/2; ++j)  
       {  
           ch = strOct[i][j];  
           strOct[i][j] = strOct[i][temp-j];  
           strOct[i][temp-j] = ch;  
       }  
   }  
   //打印  
   for (i = 0; i < n; ++i)  
   {  
       j = 0;  
       while (strOct[i][j++] == '0');//跳过前面的0  

       for(--j; j < strOct[i].size(); ++j)  
       {  
           cout<<strOct[i][j]-'0';  
       }  
       /*if (i != n-1)*/  
           cout<<endl;  
   }  

   return 0;  
}  