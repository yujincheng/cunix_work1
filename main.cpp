#include <time.h>  
#include <stdio.h>  
#include <stdlib.h>  

int main()  
{  
    time_t ts;  
    unsigned int num = (unsigned int)time(&ts);  
    srand(num);  
    int a[12] = {-1};  
    int temp = rand() % 13;  
    int number = rand() % 3;  
    int ret = 1;  
    for (int i = 0; i < 12; i++)     //generate random number 
    {  
        a[i] = rand() % 1 + 1;  
    }  
    while (ret)                      //generate bad random number
    {  
        if (number != 1)  
        {  
            a[temp] = number;  
            ret = 0;  
        }  
        else  
        {  
            number = rand() % 3;  
        }  
    }  
    int x = 0;  
    int y = 0;  
    int z = 0;  
    for (int i = 0, j = 12 / 3, k = (12 / 3) * 2; i < 12 / 3; i++, k++, j++)    //fen zu  
    {  
        x += a[i];   // A zu
        y += a[j];   // B zu 
        z += a[k];   // C zu 
    }  
    printf("%d,%d,%d\n", x, y, z);  
    for (int i = 0; i < 12; i++)  
    {  
        printf("%d  ", a[i]);  
    }  
    printf("\n");  
      
    if (x > y)        //1 2 3 4 > 5 6 7 8    suppose A zu > B zu
    {  
        x -= (a[2] + a[3]);  
        x += a[4] + a[5] + a[6];   // X zu 1  2  5   6   7  
        y -= a[4] + a[5] + a[6];  
        y += z;                   // Y zu  8  9  10  11  12  
        if (x > y)     //fen zu hou X > Y  shuoming 1 2 is zhongqiu  or 8ºÅ is qingqiu  
        {  
            if (a[0] > a[1])  
            {  
                printf("NO.1 is the heavy ball,  with the weight %d\n", a[0]);  
            }  
            else if (a[0] < a[1])  
            {  
                printf("NO.2 is the heavy ball,  with the weight %d\n", a[1]);  
            }  
            else  
            {  
                printf("NO.8 is the light ball,  with the weight %d\n", a[7]);  
            }  
        }  
        else if (x == y)  //if equal shuoming issue chuzai 3 4 haoqiu is heavy balls  
        {  
            if (a[2] > a[3])  
            {  
                printf("NO.3 is the heavy ball,  with the weight %d\n", a[2]);  
            }  
            else  
            {  
                printf("NO.4 is the heavy ball,  with the weight :%d\n", a[3]);  
            }  
        }  
        else       //if X < Y shuoming 5 6 7 is light balls   
        {  
            if (a[4] == a[5])  
            {  
                printf("NO.7 is the heavy ball,  with the weight %d\n", a[6]);  
            }  
            else if (a[5] == a[6])  
            {  
                printf("NO.5 is the light ball,  with the weight %d\n", a[4]);  
            }  
            else  
            {  
                printf("NO.6 is the light ball,  with the weight %d\n", a[5]);  
  
            }  
        }  
    }  
    else if (x < y)                    //1 2 3 4 < 5 6 7 8     
    {  
        x -= (a[2] + a[3]);  
        x += a[4] + a[5] + a[6];   // X zu 1  2  5   6   7  
        y -= a[4] + a[5] + a[6];  
        y += z;                   // Y zu  8  9  10  11  12  
  
        if (x > y)  
        {  
            if (a[4] > a[5])  
            {  
                printf("NO.5 is the heavy ball,  with the weight %d\n", a[4]);  
            }  
            else if (a[4] < a[5])  
            {  
                printf("NO.6 is the heavy ball,  with the weight %d\n", a[5]);  
            }  
            else  
            {  
                printf("NO.7 is the heavy ball,  with the weight %d\n", a[6]);  
            }  
        }  
        else if (x < y)  
        {  
            if (a[0] > a[1])  
            {  
                printf("NO.2 is the light ball,  with the weight %d\n", a[1]);  
            }  
            else if (a[0] < a[1])  
            {  
                printf("NO.1 is the light ball,  with the weight %d\n", a[0]);  
            }  
            else  
            {  
                printf("NO.8 is the heavy ball,  with the weight %d\n", a[7]);  
            }  
        }  
        else   
        {  
            if (a[2] > a[3])  
            {  
                printf("NO.4 is the light ball,  with the weight %d\n", a[3]);  
            }  
            else  
            {  
                printf("NO.3 is the light ball,  with the weight %d\n", a[2]);  
            }  
        }  
    }  
    else  
    {  
        int text1 = 0, text2 = 0;  
        text1 = a[0] + a[1] + a[2];  
        text2 = a[8] + a[9] + a[10];  
        if (text1 > text2)  
        {  
            if (a[8] == a[9])  
            {  
                printf("NO.11 is the light ball,  with the weight %d\n", a[10]);  
            }  
            else if (a[8] == a[11])  
            {  
                printf("NO.10 is the light ball,  with the weight %d\n", a[9]);  
            }  
            else  
            {  
                printf("NO.9 is the light ball,  with the weight %d\n", a[8]);  
            }  
        }  
        else if(text1 == text2)  
        {  
            if (a[0] > a[11])  
            {  
                printf("NO.12 is the light ball,  with the weight %d\n", a[11]);  
            }  
            else  
            {  
                printf("NO.12 is the heavy ball,  with the weight %d\n", a[11]);  
            }  
        }  
        else  
        {  
            if (a[8] == a[9])  
            {  
                printf("NO.11 is the heavy ball,  with the weight %d\n", a[10]);  
            }  
            else if (a[8] == a[11])  
            {  
                printf("NO.10 is the heavy ball,  with the weight %d\n", a[9]);  
            }  
            else  
            {  
                printf("NO.9 is the heavy ball,  with the weight %d\n", a[8]);  
            }  
        }  
          
    }  
        
  
    while(1);  
  
  
    return 0;  
}  