#include<stdio.h>
#include<string.h>
void str_reverse(char s[],int h,int t)
{
    char temp;

    /*
    **当h比t小的时候就将s[h]和s[t]中的字符交换，完成反转
    */
    while(h < t)
    {
        temp = s[h];
        s[h] = s[t];
        s[t] = temp;
        h++;
        t--;
    }
}
int main()
{
    char str[128];
    int i = 0;
    char ch;
    
    printf("请输入一个字符串:\n");

    while((ch = getchar()) != '\n')
    {
        str[i] = ch;
        i++;
    }
    str[i] = '\0';

    int length = strlen(str);//记录句子的长度
    int head = 0;//用来标记单词的开头
    int tail = 0;//用来标记单词的结尾

    str_reverse(str,0,length-1);//先将整个句子反转

    /*
    **通过空格和字符结束标志找到每一个单词，将单词反转过来
    */
    while(tail <= length)
    {
        if(str[tail] == ' '||str[tail] == '\0')
        {
            str_reverse(str,head,tail-1);
            head = tail + 1;
        }
        tail++;
    }

    printf("%s",str);
    printf("\n");
    
    return 0;
}
