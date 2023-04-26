#ifndef _SHELL_H_
#define _SHELL_H_
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

/* initializeShell */

void exiti_shelli(char **command);
int main(int ac, char **av, char **env);
void i_iEOFi(char *buffer);
void handle(int signals);
void iprompti(void);

/* childCreator */

void child_creator(char **command, char *name, char **env, int cicles);
int changer_direc(const char *path);

/* executioner */

void errormsag(char *name, int cicles, char **command);
void envi_printi(char **env);
void executeer(char **command, char *name, char **env, int cicles);
char **pathgeti(char **env);


/* tokenner */

char **tokeninng(char *buffer, const char *s);


/* memoryFree */

void freelyExit(char **command);
void freelyDp(char **command);


/* auxilliaryFunct */

unsigned int strlengi(char *s);
char *strcpyi(char *dest, char *src);
char *strcati(char *dest, char *src);
int strcmpi(char *s1, char *s2);
int iatoii(char *s);

/* This is the end of the header file */
/* Stop */
/* END */

#endif
