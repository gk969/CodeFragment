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

	unsigned int step;
	unsigned int steplen[3];

	unsigned int subStrStart;
	unsigned int subStrStartMax=len-3;

	if(len<3)
	{
		printf("N0 ");
		return STR_NO;
	}

	for(subStrStart=0; subStrStart<=subStrStartMax; subStrStart++)
	{
		steplen[0]=1;
		steplen[1]=1;
		steplen[2]=1;
		step=0;
		
		for(i=subStrStart+1; i<len; i++)
		{
			if((str[i]-str[i-1])==1)
			{
				if(step==0)
				{
					step=1;
				}
				else if(step==1)
				{
					if(steplen[0]==steplen[1])
					{
						step=2;
					}
					else
					{
						printf("N1 %d %d ", subStrStart, i);
						break;
					}
				}
				else
				{
					if(steplen[2]==steplen[1])
					{
						printf("Y0 %d ", subStrStart);
						return STR_YES;
					}
					else
					{
						printf("N2 %d %d ", subStrStart, i);
						break;
					}
				}
			}
			else if(str[i]==str[i-1])
			{
				steplen[step]++;
			}
			else
			{
				break;
			}
		}
		
		if((step==2)&&(steplen[2]>=steplen[1]))
		{
			printf("Y1 %d ", subStrStart);
			return STR_YES;
		}
	}
	printf("N4 %d %d ", subStrStart, i);
	return STR_NO;
}

int main(void)
{
	char *str[]=
	{	
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
