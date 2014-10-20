#include <stdio.h>
#include <string.h>


/*
MicroSoft Test

We say a string is beautiful if it has the equal amount of 3 or more continuous letters (in increasing order.)

Here are some example of valid beautiful strings: "abc", "cde", "aabbcc", "aaabbbccc".

Here are some example of invalid beautiful strings: "abd", "cba", "aabbc", "zab".

Given a string of alphabets containing only lowercase alphabets (a-z), output "YES" if the string contains a beautiful sub-string, otherwise output "NO".
*/

char *STR_YES = "YES";
char *STR_NO = "NO";
char *StringIsBeautiful(const char *str, unsigned int len)
{
	unsigned int i;

	/* 
		step步数 
		例如abc a为第0步 b为第1步 c为第2步
		aabbcc aa为第0步 bb为第1步 cc为第2步
	*/
	unsigned int step;
	
	/* 
		steplen 每步步长 
		例如abc 步长都为1
		aabbcc 步长都为2
	*/
	unsigned int steplen[3];
	
	/*
		算法解析:
		由于满足条件的子串最少需要3步，所以只考虑满足3步的情况。
		也就是要在给定字符串中查找类似abc aabbcc aaabbbccc的子串。
		每步步长默认为1，如果有重复字符，则当前步长加1。
		字符递增时检查当前步数，并作出相应处理。
		
		从给定字符串的起始位置也就是第0个字符开始，作为可能的子串匹配目标条件。
		如果不符合条件则从第1个字符开始，再次匹配。以此类推，直到结束
	*/
	
	
	unsigned int subStrStart;
	unsigned int subStrStartMax=len-3;

	if(len<3)
	{
		printf("N0 ");
		return STR_NO;
	}

	//轮询所有可能的子串
	for(subStrStart=0; subStrStart<=subStrStartMax; subStrStart++)
	{
		//步长、步数初始化
		steplen[0]=1;
		steplen[1]=1;
		steplen[2]=1;
		step=0;
		
		//检测当前子串
		for(i=subStrStart+1; i<len; i++)
		{
			//字符递增
			if((str[i]-str[i-1])==1)
			{
				//第0步，步数递增
				if(step==0)
				{
					step=1;
				}
				//第1步
				else if(step==1)
				{
					//第0步步长大于等于第1步步长，则可能是符合条件的子串
					//步数递增
					if(steplen[0]>=steplen[1])
					{
						step=2;
					}
					//第0步步长小于第1步步长，直接跳到下一子串的检测。
					//例如aabbbcccdd,到c的时候检测到a的长度小于b的长度，
					//则直接检测以b为起点的子串并且从c开始检测
					else
					{
						printf("N1 %d %d ", subStrStart, i);
						subStrStart+=steplen[0];
						steplen[0]=steplen[1];
						steplen[1]=1;
					}
				}
				//第2步
				else
				{
					//第2步步长大于等于第1步步长，子串符合条件
					if(steplen[2]>=steplen[1])
					{
						printf("Y0 %d %d ", subStrStart, i);
						return STR_YES;
					}
					//第2步步长小于第1步步长，直接跳到下一子串的检测。
					//例如aaabbbccdd,到d的时候检测到c的长度小于b的长度，
					//则直接检测以b为起点的子串并且从d开始检测
					else
					{
						printf("N2 %d %d ", subStrStart, i);
						subStrStart+=steplen[0];
						steplen[0]=steplen[1];
						steplen[1]=steplen[2];
						steplen[2]=1;
					}
				}
			}
			//重复字符 步长递增
			else if(str[i]==str[i-1])
			{
				steplen[step]++;
			}
			//字符非递增，亦非重复，结束
			else
			{
				break;
			}
		}
		
		//已经到第2步，且第2步步长大于等于第1步步长，子串符合条件
		if((step==2)&&(steplen[2]>=steplen[1]))
		{
			printf("Y1 %d %d ", subStrStart, i);
			return STR_YES;
		}
		else
		{
			printf("N3 %d %d ", subStrStart, i);
			subStrStart=i-1;
		}
	}
	printf("N4 %d %d ", subStrStart, i);
	return STR_NO;
}

int main(void)
{
	char *str[]=
	{
		"aaabbbccdd",
		"aaabbbccddw",
		"acdew",
		"abbcd",
		"abbcefg",
		"aabbbccs",
		"aabbbcchij",
		"frrssttuv",
		"frrssttttuv",
		"saabbcccd",
		"aaab",
		"abccde",
		"abb",
		"abbccdddd",
		"abbbccdddd",
		"abc",
		"afc",
		"abcsdaad",
		"aabc",
		"aabbc",
		"aabcc",
		"aabcw",
		"abcddf",
		"vabcdfg",
		"hijklsd",
		"abbcddd",
		"aabbcc",
		"aabbccdd",
		"aabbccdf",
		"aabbcddf",
		"aaabbbccd",
		"aaabbbccc",
		"aaabbbcd",
		"fllmmnnns"
	};

	int i;

	for(i=0; i<(sizeof(str)/sizeof(char*)); i++)
	{
		printf("%s : %s\n", str[i], StringIsBeautiful(str[i], strlen(str[i])));
	}

	return getchar();
}
