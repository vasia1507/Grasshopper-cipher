#pragma once

#include <QFile>
#include <QTextStream>
#include <algorithm>
#include <cstdio>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <vector>

#define BLOCK_SIZE 16

void Encript_File(std::string file_name, std::string main_key);
void Decript_File(std::string file_name, std::string main_key);
int validate(std::string main_key);
