#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#define MAX_ARGS 100
#include <sys/stat.h>
size_t tokenizer(char *input, char *delim);
char **word_list(char *input, char *delim);
char **append(char **args, char *token);
void teborne(char **args);
void exiting(char **args, char *input);
void envir(char **args);
void printenv(void);
char *loc(char *path, char *args);
char *locate(char *path);
void printprompt(void);
char *readinput(void);
char **tokenize(char *input);
void executecommand(char **args, char **env);
extern char **environ;
#endif
