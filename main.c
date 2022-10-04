/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssar <ssar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:08:40 by ssar              #+#    #+#             */
/*   Updated: 2021/04/16 10:45:19 by ssar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>

int _FT_STRLEN(char *s);
char *_FT_STRCPY(char *dest, char *src);
int _FT_STRCMP(char *s1, char *s2);
int _FT_WRITE(int fd, const void *buf, size_t count);
int _FT_READ(int fd, void *buf, size_t count);
char *_FT_STRDUP(const char *s);

void test_strlen(void)
{
	int a;
	unsigned long b;

	a = _FT_STRLEN("libasm cd ..");
	b = strlen("libasm cd ..");
	printf("\n\n--------test ft_strlen--------\n");
	printf("mine : %d\n", a);
	printf("them : %lu\n\n", b);
/*	if (a != (int)b)
*	{
*		printf("\033[31m" );
		printf("--> KO\n\n");
*	}
*	else
*	{
*		printf("\033[32m" );
*		printf("--> OK\n\n");
*	}
*/	printf("\033[00m" );
	a = _FT_STRLEN("");
	b = strlen("");
	printf("mine : %d\n", a);
	printf("them : %lu\n\n", b);
/*	if (a != (int)b)
*	{
*		printf("\033[31m" );
*		printf("--> KO\n\n");
*	}
*	else
*	{
*		printf("\033[32m" );
*		printf("--> OK\n\n");
*	}
*/	printf("\033[00m" );
}

void test_strcpy(void)
{
	printf("\n\n--------test ft_strcpy--------\n");
		char copy[12];
	char copy2[12];
	char copy3[1];
	char copy4[1];
	_FT_STRCPY(copy, "coucou heko");
	strcpy(copy2, "coucou heko");
	_FT_STRCPY(copy3, "");
	strcpy(copy4, "");
	printf("1 mine : %s\n", copy);
	printf("1 them : %s\n\n", copy2);
	printf("2 mine : %s\n", copy3);
	printf("2 them : %s\n\n", copy4);
}
void test_strcmp(void)
{
	printf("\n\n--------test ft_strcmp--------\n");




	char *coucou1 = "coucou";
	char *coucou2 = "coucou";
	char *coucou3 = "coucoua";
	char *coucou4 = "coucoup";
	char *coucou5 = "";
	char *coucou6 = "coucou";
	char *coucou7 = "coucou";
	char *coucou8 = "";
	int a;
	int b;
	int c;
	int d;
	int e;
	int f;
	int g;
	int h;
	int i; 
	int j;
	a = _FT_STRCMP(coucou1, coucou2);
	b = _FT_STRCMP(coucou3, coucou4);
	c = _FT_STRCMP(coucou5, coucou6);
	g = _FT_STRCMP(coucou7, coucou8);
	i = _FT_STRCMP(coucou4, coucou3);
	j = strcmp(coucou4, coucou3);
	d = strcmp(coucou5, coucou6);
	e = strcmp(coucou1, coucou2);
	f = strcmp(coucou3, coucou4);
	h = strcmp(coucou7, coucou8);
	printf("mine : %d\n", a);
	printf("them : %d\n\n", e);
	printf("mine : %d\n", b);
	printf("them : %d\n\n", f);
	printf("mine : %d\n", i);
	printf("them : %d\n\n", j);
	printf("mine : %d\n", c);
	printf("them : %d\n\n", d);
	printf("mine : %d\n", g);
	printf("them : %d\n\n", h);
}

void test_write(void)
{
	printf("\n\n--------test ft_write--------\n\n");
	_FT_WRITE(1, "mine  : coucou\n", 15);
	write(1, "them  : coucou\n", 15);
}

void test_read(void)
{
	printf("\n\n--------test ft_read--------\n");
	int c;
	int d;
	char BUF1[189];
	char BUF2[189];
	BUF1[188] = '\0';
	BUF2[188] = '\0';
	int fd;
	fd = open("MON_EXEMPLE.txt", O_CREAT | O_RDWR, 00777);
	write(fd,"ceci est un exemple pour read, les 187 premiers caracteres seront dans le buffer de ma fonction, les 187 suivants dans le buffer recuperant les donnees de la fonction d'origin, la valeur de retour est egale au nombre de bytes recuperer dans le buffer, au bien 0 en fin de fichier, ou -1 en cas d'erreur. en cas d'erreur, errno est egalement recuperable dans les deux fonctions\n", 374);
	close(fd);
	fd = open("MON_EXEMPLE.txt", O_RDONLY);
	c = _FT_READ(fd, BUF1, 187);
	d = read(fd, BUF2, 187);
	close(fd);
	printf("my fcnt : %s\n", BUF1);
	printf("retour de ma fonction : %d\n", c);	
	printf("errno : %d\n\n", errno);	
	printf("fct ori : %s\n", BUF2);
	printf("retour de la fonction d'origin: %d\n", d);	
	printf("errno : %d\n\n", errno);	
}
void test_strdup(void)
{
	printf("\n\n--------test ft_strdup--------\n");
	char *str = "voici la string a dupliquer";
	char *dest_of_my_fcnt;
	char *dest_fcnt_origin;
	dest_of_my_fcnt = _FT_STRDUP(str);
	dest_fcnt_origin = strdup(str);
	printf("mine : %s\n", dest_of_my_fcnt);
	printf("orig : %s\n", dest_fcnt_origin);
	char *str2 = "";
	char *dest_of_my_fcnt2;
	char *dest_fcnt_origin2;
	dest_of_my_fcnt2 = _FT_STRDUP(str2);
	dest_fcnt_origin2 = strdup(str2);
	printf("mine : %s\n", dest_of_my_fcnt2);
	printf("orig : %s\n", dest_fcnt_origin2);
}

int main()
{	
	test_strlen();
	test_strcpy();
	test_strcmp();
	test_write();
	test_read();
	test_strdup();

	printf("\033[31m");
	printf("\n\n\n\n************* tests rapides a modifier **************\n");
	printf("\033[00m");

printf("\033[33m" );printf("\n--> ft_strlen :\n");printf("\033[00m" );
	printf("\n");
	printf("TEST AU CHOIX MY FCNT: %d\n", _FT_STRLEN("entrez une phrase"));   // modifier
	printf("TEST AU CHOIX  ORIGIN: %lu\n\n\n", strlen("entrez une phrase"));  //modifier

printf("\033[33m" );printf("\n--> ft_strcpy : \n");	printf("\033[00m" );
	printf("\n");
	char TEST_AU_CHOIX[20];
	char TEST_AU_CHOIX2[20];
	_FT_STRCPY(TEST_AU_CHOIX, "entrez une phrase");                          // a modifier
	strcpy(TEST_AU_CHOIX2, "entrez une phrase");                             // a modifier
	printf("TEST AU CHOIX MY FCNT : %s\n", TEST_AU_CHOIX);
	printf("TEST AU CHOIX  ORIGIN : %s\n\n\n", TEST_AU_CHOIX2);

printf("\033[33m" );printf("\n--> ft_strcmp : \n");	printf("\033[00m" );
	printf("\n");
	char *TEST_AU_CHOIX3 = "entrez une phrase";                               // a modifier
	char *TEST_AU_CHOIX4 = "entrez une phrase a comparer";                    // a modifier
	int RES;
	int RES2;
	RES = _FT_STRCMP(TEST_AU_CHOIX3, TEST_AU_CHOIX4);
	RES2 = strcmp(TEST_AU_CHOIX3, TEST_AU_CHOIX4);
	printf("TEST AU CHOIX MY FCNT : %d\n", RES);
	printf("TEST AU CHOIX  ORIGIN : %d\n\n\n", RES2);

printf("\033[33m" );printf("\n--> ft_write : \n");printf("\033[00m" );
	int a;
	int b;
	printf("\n");
	a = _FT_WRITE(1, "MY FCNT : TEST AU CHOIX", 24);                          // a modifier
	printf("\nretour de ma fonction : %d\n", a);	
	printf("errno : %d\n", errno);	
	b = write(1, "ORIGIN  : TEST_AU_CHOIX", 24);                              // a modifier
	printf("\nretour de la fonction d'origin: %d\n", b);	
	printf("errno : %d\n\n", errno);	

printf("\033[33m" );printf("\n--> ft_read : \n");printf("\033[00m" );
	printf("\n");
	int c;
	int d;
	char BUF1[33];
	char BUF2[33];
	BUF1[32] = '\0';
	BUF2[32] = '\0';
	int fd;
	fd = open("FILE.txt", O_CREAT | O_RDWR, 00777);
	write(fd, "je tape 32 caracteres exactement\n", 32);
	write(fd, "je tape 32 caracteres exactement\n", 32);
	close(fd);
	fd = open("FILE.txt", O_RDONLY);
	c = _FT_READ(fd, BUF1, 32);                                               //a modifier
	d = read(fd, BUF2, 32);                                                   //a modifier
	close(fd);
	printf("my fcnt : %s\n", BUF1);
	printf("retour de ma fonction : %d\n", c);	
	printf("errno : %d\n", errno);	
	printf("fct ori : %s\n", BUF2);
	printf("retour de la fonction d'origin: %d\n", d);	
	printf("errno : %d\n\n", errno);	

printf("\033[33m" );printf("\n--> ft_strdup : \n\n");printf("\033[00m" );
	char *str = "entrez une phrase";                                          //a modifier
	char *dest_of_my_fcnt;
	char *dest_fcnt_origin;
	dest_of_my_fcnt = _FT_STRDUP(str);
	dest_fcnt_origin = strdup(str);
	printf("mine : %s\n", dest_of_my_fcnt);
	printf("orig : %s\n", dest_fcnt_origin);

	return (0);
}
