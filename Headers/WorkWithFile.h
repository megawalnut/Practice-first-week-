#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

class WorkWithFile 
{
    private:
        std::string m_fileName;    //имя файла
        std::fstream m_file;    //поток для работы с файлом

    public:
        //конструктор
        WorkWithFile(const std::string& name);

        //деструктор
        ~WorkWithFile() = default;

        //запись
        void inputToFile(const std::string& str);
        
        //чтение
        std::vector<std::string> outFromFile(); 
};