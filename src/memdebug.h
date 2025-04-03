#ifndef MEMDEBUG_H
#define MEMDEBUG_H

#include <unistd.h>
#include <ios>
#include <iostream>
#include <fstream>
#include <string>

#include <logging.h>

void process_mem_usage(double& vm_usage, double& resident_set); 
void print_usage(char* id);

#endif // MEMDEBUG_H
