#include "WorkWithFile.h"

// конструктор
WorkWithFile::WorkWithFile(const std::string &name) : m_fileName{name}
{
    try
    {
        //октрываем файл
        m_file.open(m_fileName, std::ios_base::in | std::ios_base::out | std::ios_base::app);

        //если не открыли
        if (!m_file.is_open())
        {
            throw std::runtime_error("Не удалось открыть файл");
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }
    catch (...)
    {
        std::cerr << "Неизвестная ошибка" << std::endl;
    }
}

// деструктор
WorkWithFile::~WorkWithFile()
{
    //если файл открыт
    if (m_file.is_open())
        //закрываем файл
        m_file.close();
}

// запись
void WorkWithFile::inputToFile(const std::string &str)
{
    //если файл открыт
    if (m_file.is_open())
        //записываем строку
        m_file << str << std::endl;
}

// чтение
std::vector<std::string> WorkWithFile::outFromFile()
{

    std::vector<std::string> v;
    std::string line;

    //если файл открыт
    if (m_file.is_open())
    {
        while (getline(m_file, line))
        {
            //считываем каждую строку
            v.push_back(line);
        }
    }
    return v;
}
