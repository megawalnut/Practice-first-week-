#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

class WorkWithFile {
	private:
		std::string m_fileName;
		std::fstream m_file;
	public:
		//конструктор
		WorkWithFile(const std::string& name);
		//деструктор
		~WorkWithFile();
		//запись
		void inputToFile(const std::string& str);
		//чтение
		std::vector<std::string> outFromFile(); 
};