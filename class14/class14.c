#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//返回传入字符串的长度
int getStrLength(char[]);
//封装fgets，用来接收字符串的字符数组，接收的字符总数
void getString(char[], int count);
//封装fgets函数，去掉结尾的\n
//参数1：将接收到的字符串保存到传入的数组中
//参数2：最大接收的字符长度
char* myFgets(char, int);



void getString(char str[], int count)
{
	//使用fgets函数接收字符串，使用\0替换字符数组的最后一位\n
	fgets(str, count, stdin);
	//查找\n字符所在的指针
	char* find = strchr(str, '\n');
	if (find)//如果找到了
		*find = '\0';	//根据找到的指针，修改指向的元素\0
}

int getStrLength(char str[])
{
	int count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	return count;
}

char* myFgets(char* str, int maxlen)
{
	fgets(str, maxlen, stdin);
	//去掉最后一位空格
	//找到最后一位
	//初学者可能比较喜欢循环的方式
	int count = 0;
	while (str[count] != '\n')
	{
		if (str[count] == '\n')
		{
			break;
		}
		count++;
	}
}


int main()
{
	/*
	char names1[50];
	//fgets(names1, 7, stdin);
	getString(names1, 50);
	int len = getStrLength(names1);
	printf("字符串的长度为：%d\n", len);
	*/
	char word1[] = "helloworld";
	char word2[] = { 'h','e','l','l','o','w','o','r','l','d','\0' };
	
	/*
	char word3[] = "你好，世界。";
	printf("%d\n", strlen(word1));
	printf("%d\n", strlen(word2));
	printf("%d\n", strlen(word3));
	*/

	//数组的复制原理：每个元素逐个进行复制
	printf("请输入字符串：");
	myFgets(word2, 50);
	//使用内置函数，将word2的内容复制到word1数组中
	strcpy_s(word1,50, word2,50);
	printf("%s\t%s\n", word1, word2);

	return 0;
}
