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
		step���� 
		����abc aΪ��0�� bΪ��1�� cΪ��2��
		aabbcc aaΪ��0�� bbΪ��1�� ccΪ��2��
	*/
	unsigned int step;
	
	/* 
		steplen ÿ������ 
		����abc ������Ϊ1
		aabbcc ������Ϊ2
	*/
	unsigned int steplen[3];
	
	/*
		�㷨����:
		���������������Ӵ�������Ҫ3��������ֻ��������3���������
		Ҳ����Ҫ�ڸ����ַ����в�������abc aabbcc aaabbbccc���Ӵ���
		ÿ������Ĭ��Ϊ1��������ظ��ַ�����ǰ������1��
		�ַ�����ʱ��鵱ǰ��������������Ӧ����
		
		�Ӹ����ַ�������ʼλ��Ҳ���ǵ�0���ַ���ʼ����Ϊ���ܵ��Ӵ�ƥ��Ŀ��������
		���������������ӵ�1���ַ���ʼ���ٴ�ƥ�䡣�Դ����ƣ�ֱ������
	*/
	
	
	unsigned int subStrStart;
	unsigned int subStrStartMax=len-3;

	if(len<3)
	{
		printf("N0 ");
		return STR_NO;
	}

	//��ѯ���п��ܵ��Ӵ�
	for(subStrStart=0; subStrStart<=subStrStartMax; subStrStart++)
	{
		//������������ʼ��
		steplen[0]=1;
		steplen[1]=1;
		steplen[2]=1;
		step=0;
		
		//��⵱ǰ�Ӵ�
		for(i=subStrStart+1; i<len; i++)
		{
			//�ַ�����
			if((str[i]-str[i-1])==1)
			{
				//��0������������
				if(step==0)
				{
					step=1;
				}
				//��1��
				else if(step==1)
				{
					//��0���������ڵ��ڵ�1��������������Ƿ����������Ӵ�
					//��������
					if(steplen[0]>=steplen[1])
					{
						step=2;
					}
					//��0������С�ڵ�1��������ֱ��������һ�Ӵ��ļ�⡣
					//����aabbbcccdd,��c��ʱ���⵽a�ĳ���С��b�ĳ��ȣ�
					//��ֱ�Ӽ����bΪ�����Ӵ����Ҵ�c��ʼ���
					else
					{
						printf("N1 %d %d ", subStrStart, i);
						subStrStart+=steplen[0];
						steplen[0]=steplen[1];
						steplen[1]=1;
					}
				}
				//��2��
				else
				{
					//��2���������ڵ��ڵ�1���������Ӵ���������
					if(steplen[2]>=steplen[1])
					{
						printf("Y0 %d %d ", subStrStart, i);
						return STR_YES;
					}
					//��2������С�ڵ�1��������ֱ��������һ�Ӵ��ļ�⡣
					//����aaabbbccdd,��d��ʱ���⵽c�ĳ���С��b�ĳ��ȣ�
					//��ֱ�Ӽ����bΪ�����Ӵ����Ҵ�d��ʼ���
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
			//�ظ��ַ� ��������
			else if(str[i]==str[i-1])
			{
				steplen[step]++;
			}
			//�ַ��ǵ���������ظ�������
			else
			{
				break;
			}
		}
		
		//�Ѿ�����2�����ҵ�2���������ڵ��ڵ�1���������Ӵ���������
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
