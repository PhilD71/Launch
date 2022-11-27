//
// Created by Phillip Dumitru on 2022-11-26.
//
#ifndef LAUNCH_LAUNCH_H
#define LAUNCH_LAUNCH_H
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/wait.h>

/**
 *
 * @param argv arguments for command to launch
 * @return the pid of launched process, or -1 if unsuccessful
 */
pid_t launch(char *argv[]);

/**
 * Prints the usage of this application
 */
void usage();

#endif
