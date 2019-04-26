#include <stdio.h>

void Replace (char s[], char viejo, char nuevo);
int StrLen (char Array[]);
int StrCmp(char Array1[], char Array2[]);
void Tolower (char oracion[]);
void arrayprint (char prin[]);
void StrCat (char Array1[], char Array2[]);
int StrStr (char str1[], char str2[]);
int EsPalindromo (char pal[]);
void dejarletras(char str[]);
void LeftTrim(char str[]);
int esletra (char c);

int main(void)
{
	char s[50] = "     A la, gorda drogala";
	arrayprint(s);
	LeftTrim(s);
	arrayprint(s);
	return 0;
}
void Replace (char s[], char viejo, char nuevo)
{
	int i = 0;
	while (s[i])
	{
		if (s[i] == viejo)
			s[i] = nuevo;
		else if (s[i] == (viejo + 'a'-'A'))
			s[i] = nuevo + 'a' - 'A';
		i++;
	}
	return ;
}

int StrLen (char Array[])
{
	int i = 0;
	while (Array[i])
		i++;
	return i;	
}

int StrCmp(char Array1[], char Array2[])
{
	Tolower (Array1);
	Tolower (Array2);
	int i = 0;
	while (Array1[i] != '\0')
	{
		if (Array1[i] == Array2[i])
			i++;
		else if (Array1[i] < Array2[i])
			return -1;
		else
			return 1;
	}
	if (Array2[i] == '\0')
		return 0;
	else
		return -1;
}

void Tolower (char oracion[])
{
	int i = 0;
	while (oracion[i] != '\0')
	{
		if (oracion[i] <= 'Z' && oracion[i] >= 'A')
			oracion[i] = oracion[i] + 'a' - 'A';
		i++;
	}
	return;
}

void StrCat (char Array1[], char Array2[])
{
	int i = 0, j = 0;	
	while (Array1[i] != '\0')
		i++;
	while (Array2[j] != '\0')
	{
		Array1[i] = Array2[j];
		i++;
		j++;
	}
		Array1[i] = '\0';
	return;
}

void arrayprint (char prin[])
{
	int i = 0;
	while (prin[i] != '\0')
	{
		printf("%c", prin[i]);
		i++;
	}
	printf("\n");
	return;
}

int StrStr (char str1[], char str2[])
{
	int i = 0;
	int j = 0;
	Tolower(str1);
	Tolower(str2);
	int longitud = StrLen(str2) - 1;
	while (str1[i] != '\0')
	{
		if (str1[i] == str2[j])
		{
			if (j == longitud)
				return (i - j);
			j++;
		}
		i++;
	}
	return -1;
}

int EsPalindromo (char pal[])
{
	dejarletras(pal);
	Tolower(pal);
	int i = 0, j = StrLen(pal)-1;
	while (pal[i] == pal[j])
	{
		if ((j-i)<=1)
			return 1;
		i++;
		j--;
	}
	return 0;
}

void dejarletras (char str[])
{
	Tolower(str);
	int k, i = 0;
	while (str[i] != '\0')
	{
		if (esletra(str[i]))
			i++;
		else
			{
				k = i;
				while (!esletra(str[k]) && str[k] != '\0')
					k++;
				str[i] = str[k];
				str[k] = ' ';
			}
	}
	i = 0;
	while (str[i] != ' ')
		i++;
	str[i] = '\0';
	return;
}

int esletra (char c)
{
	if ((c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A'))
		return 1;
	else
		return 0;
}

void LeftTrim (char str[])
{
	int k = 0, i = 0;
	while (str[i] == ' ')
		i++;
	while (str[i] != '\0')
		{
		str[k] = str[i];
		i++;
		k++;
		}
	str[k + 1] = '\0';
	return;
}
