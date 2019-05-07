#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX 30

int pow(int base, int exp);
//char * mystrtok(char * str, const char * delim);
int Convertion(char *hex);

int main()
{
	char hex[MAX];
	const char *limits = " ,.;()-";
	char *pw;
	gets(hex);
	pw = strtok(hex, limits);
	while (pw != NULL)
	{
	
		printf("%s = %d \n", pw, Convertion(pw));
		pw = strtok(NULL, limits);
	}
	
	system("pause");
	return 0;
}


int Convertion(char *hex)
{
	long long decimal, place;
	int i = 0, val, len;
	decimal = 0;
	place = 1;
	len = mystrlen(hex);
	len--;
	for (i = 0; hex[i] != '\0'; i++)
	{
		if (hex[i] >= '0' && hex[i] <= '9')
		{
			val = hex[i] - 48;
		}
		else if (hex[i] >= 'a' && hex[i] <= 'f')
		{
			val = hex[i] - 97 + 10;
		}
		else if (hex[i] >= 'A' && hex[i] <= 'F')
		{
			val = hex[i] - 65 + 10;
		}
		else
		{
			return -1;
		}
		decimal += val * pow(16, len);
		len--;
	}
	return decimal;
}

int pow(int base, int exp)
{
	if (exp < 0)
		return -1;
	int result = 1;
	while (exp)
	{
		if (exp & 1)
			result *= base;
		exp >>= 1;
		base *= base;
	}
	return result;
}

int mystrlen(char *str)
{
	int len = 0;
	int i;

	for (i = 0; str[i] != 0; i++)
	{
		len++;
	}
	return(len);
}

//char * mystrtok(char * str, const char * delim)
//{
//	static char * last = 0;
//	if (str) last = str;
//	if ((last == 0) || (*last == 0)) return 0;
//	char * c = last;
//	while (strchr(delim, *c)) ++c;
//	if (*c == 0) return 0;
//	char * start = c;
//	while (*c && (strchr(delim, *c) == 0)) ++c;
//	if (*c == 0)
//	{
//		last = c;
//		return start;
//	}
//	*c = 0;
//	last = c + 1;
//	return start;
//}