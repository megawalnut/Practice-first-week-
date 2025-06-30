#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

class WorkWithfile {
	private:
		std::string m_fileName;
		std::fstream m_file;
	public:
		//конструктор
		WorkWithfile(const std::string& name);
		//деструктор
		~WorkWithfile();
		//запись
		void in(const std::string& str);
		//чтение
		std::vector<std::string> out(); 
};