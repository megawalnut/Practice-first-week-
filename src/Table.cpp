#include "Table.h"
#include "Car.h"
#include "Boat.h"
#include "Helicopter.h"
#include "Spaceship.h"

#include <map>
#include <functional>
#include <stdlib.h>

//конструктор
Table::Table(std::unique_ptr<Strategy>&& otherStrategy) : m_context{std::move(otherStrategy)}
{
    createMap = 
    {
        {"Car", [](){ return std::make_unique<CreateCar>();} },
        {"Boat", [](){ return std::make_unique<CreateBoat>();} },
        {"Helicopter", [](){ return std::make_unique<CreateHelicopter>();} },
        {"Spaceship", [](){ return std::make_unique<CreateSpaceship>();} },
    };
    m_mapForStrategy = 
    {
        { 1, []() { return std::make_unique<StrategyId>(); } },
        { 2, []() { return std::make_unique<StrategyType>(); } },
        { 3, []() { return std::make_unique<StrategyModel>(); } },
        { 4, []() { return std::make_unique<StrategyBrand>(); } },
        { 5, []() { return std::make_unique<StrategyYear>(); } },
        { 6, []() { return std::make_unique<StrategyWeight>(); } },
        { 7, []() { return std::make_unique<StrategyOwners>(); } },
        { 8, []() { return std::make_unique<StrategyMileage>(); } },
        { 9, []() { return std::make_unique<StrategyLengthBoat>(); } },
        { 10, []() { return std::make_unique<StrategyWidthBoat>(); } },
        { 11, []() { return std::make_unique<StrategyCapacity>(); } },
        { 12, []() { return std::make_unique<StrategyEnginePower>(); } },
        { 13, []() { return std::make_unique<StrategyMaxSpeed>(); } },
        { 14, []() { return std::make_unique<StrategyHyperjumpRange>(); } },
    };
}


//методы
//для отрисовки
void Table::forPrintTable(const std::vector<std::unique_ptr<Transport>>& vehicles,
    int label_width,
    int data_width,
    const std::string& label, 
    std::function<std::string(Transport*)> get_value) const 
{
    //вывод заголовка
    std::cout << "| " << std::setw(label_width) << std::left << label << " |";
    
    //вывод данных для каждого транспорта
    for (const auto& v : vehicles) {
        std::cout << std::setw(data_width) << std::left << get_value(v.get()) << " |";
    }
    
    //перенос строки после завершения строки таблицы
    std::cout << "\n";
}
//отрисовка
void Table::printTable() const
{
    try
    {
        const int label_width = 20;  //ширина для полей
        const int data_width = 15;   //Ширина для данных


        std::cout << std::string(label_width + 3 + (data_width + 3) * m_vehicles.size() + 1, '-') << '\n';

        //ID
        forPrintTable(m_vehicles, label_width, data_width, "ID", [](Transport* v) 
        { 
            return std::to_string(v->get_id()); 
        });
        //отрисовка границы
        std::cout << std::string(label_width + 3 + (data_width + 3) * m_vehicles.size() + 1, '-') << '\n';

        //type
        forPrintTable(m_vehicles, label_width + 3, data_width, "Тип", [](Transport* v) 
        { 
            return v->get_type(); 
        });
        //отрисовка границы
        std::cout << std::string(label_width + 3 + (data_width + 3) * m_vehicles.size() + 1, '-') << '\n';

        //brand
        forPrintTable(m_vehicles, label_width + 5, data_width, "Марка", [](Transport* v) 
        { 
            return v->get_brand(); 
        });
        //отрисовка границы
        std::cout << std::string(label_width + 3 + (data_width + 3) * m_vehicles.size() + 1, '-') << '\n';

        //model
        forPrintTable(m_vehicles, label_width + 6, data_width, "Модель", [](Transport* v) 
        { 
            return v->get_model(); 
        });
        //отрисовка границы
        std::cout << std::string(label_width + 3 + (data_width + 3) * m_vehicles.size() + 1, '-') << '\n';

        //year
        forPrintTable(m_vehicles, label_width + 3, data_width, "Год", [](Transport* v) 
        { 
            return std::to_string(v->get_year()); 
        });
        //отрисовка границы
        std::cout << std::string(label_width + 3 + (data_width + 3) * m_vehicles.size() + 1, '-') << '\n';

        //weight
        forPrintTable(m_vehicles, label_width + 5, data_width, "Вес(кг)", [](Transport* v)
        { 
            std::ostringstream out;
            //форматируем сторку
            out << std::fixed << std::setprecision(2) << v->get_weight();
            return out.str(); 
        });
        //отрисовка границы
        std::cout << std::string(label_width + 3 + (data_width + 3) * m_vehicles.size() + 1, '-') << '\n';

        //car->owners
        forPrintTable(m_vehicles, label_width + 9, data_width, "Car->Владельцы",  [](Transport* v) 
        {
            if (auto car = dynamic_cast<Car*>(v)) 
                return std::to_string(car->get_owners());
            return std::string("X");
        });
        //отрисовка границы
        std::cout << std::string(label_width + 3 + (data_width + 3) * m_vehicles.size() + 1, '-') << '\n';
        
        //car->milaege
        forPrintTable(m_vehicles, label_width + 8, data_width, "Car->Пробег (км)", [](Transport* v) 
        {
            if (auto car = dynamic_cast<Car*>(v)) 
            {
                std::ostringstream out;
                //форматируем сторку
                out << std::fixed << std::setprecision(2) << car->get_mileage();
                return out.str();
            }
            return std::string("X");
        });
        //отрисовка границы
        std::cout << std::string(label_width + 3 + (data_width + 3) * m_vehicles.size() + 1, '-') << '\n';

        //boat->length
        forPrintTable(m_vehicles, label_width + 6, data_width, "Boa->Длина (м)", [](Transport* v) 
        {
            if (auto boat = dynamic_cast<Boat*>(v)) 
            {
                std::ostringstream out;
                //форматируем сторку
                out << std::fixed << std::setprecision(2) << boat->get_lengthBoat();
                return out.str();
            }
            return std::string("X");
        });
        //отрисовка границы
        std::cout << std::string(label_width + 3 + (data_width + 3) * m_vehicles.size() + 1, '-') << '\n';

        //boat->width
        forPrintTable(m_vehicles, label_width + 7, data_width, "Boa->Ширина (м)", [](Transport* v) 
        {
            if (auto boat = dynamic_cast<Boat*>(v)) 
            {
                std::ostringstream out;
                //форматируем сторку
                out << std::fixed << std::setprecision(2) << boat->get_widthBoat();
                return out.str();
            }
            return std::string("X");
        });
        //отрисовка границы
        std::cout << std::string(label_width + 3 + (data_width + 3) * m_vehicles.size() + 1, '-') << '\n';

        //helicopter->capacity
        forPrintTable(m_vehicles, label_width + 9, data_width, "Hel->Грузопод.(т)", [](Transport* v) 
        {
            if (auto hel = dynamic_cast<Helicopter*>(v)) 
            {
                std::ostringstream out;
                //форматируем сторку
                out << std::fixed << std::setprecision(2) << hel->get_capacity();
                return out.str();
            }
            return std::string("X");
        });
        //отрисовка границы
        std::cout << std::string(label_width + 3 + (data_width + 3) * m_vehicles.size() + 1, '-') << '\n';

        //hecilopter->enginePower
        forPrintTable(m_vehicles, label_width + 10, data_width, "Hel->Мощность(лс)", [](Transport* v) 
        {
            if (auto heli = dynamic_cast<Helicopter*>(v)) 
                return std::to_string(heli->get_enginePower());
            return std::string("X");
        });
        //отрисовка границы
        std::cout << std::string(label_width + 3 + (data_width + 3) * m_vehicles.size() + 1, '-') << '\n';

        //spaceship->maxSpeed
        forPrintTable(m_vehicles, label_width + 8, data_width, "Spa->Max скорость", [](Transport* v) 
        {
            if (auto spa = dynamic_cast<Spaceship*>(v)) 
            {
                std::ostringstream out;
                //форматируем сторку
                out << std::fixed << std::setprecision(2) << spa->get_maxSpeed();
                return out.str();
            }
            return std::string("X");
        });
        //отрисовка границы
        std::cout << std::string(label_width + 3 + (data_width + 3) * m_vehicles.size() + 1, '-') << '\n';

        //spaceship->hyperjumpRange
        forPrintTable(m_vehicles, label_width + 11, data_width, "Spa->Дальность (ае)", [](Transport* v) 
        {
            if (auto spa = dynamic_cast<Spaceship*>(v)) 
            {
                std::ostringstream out;
                //форматируем сторку
                out << std::fixed << std::setprecision(2) << spa->get_hyperjumpRange();
                return out.str();
            }
            return std::string("X");
        });
        //отрисовка границы
        std::cout << std::string(label_width + 3 + (data_width + 3) * m_vehicles.size() + 1, '-') << '\n';

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

// создание
Transport*  Table::create_tr(
    const std::string &typeTrans,
    const std::string &brandTrans,
    const std::string &modelTrans,
    int yearTrans,
    double weightTrans)
{
    try
    {
        auto creator = createMap[typeTrans]();

        if (creator)
        {
            std::unique_ptr<Transport> res = creator->create(
                brandTrans, 
                modelTrans, 
                yearTrans, 
                weightTrans);

            Transport* ptr = res.get(); 
            m_vehicles.push_back(std::move(res));
            return ptr;
        }
        return nullptr;
    }
    catch (...)
    {
        std::cerr << "Неизвестная ошибка" << std::endl;
        return nullptr;
    }
}

//создание с доп. полями
void Table::create_addit_field_tr(const std::string& typeTrans, 
    const std::string& brandTrans, 
    const std::string& modelTrans, 
    int yearTrans, 
    double weightTrans)
{

    auto it = create_tr(typeTrans, brandTrans, modelTrans, yearTrans, weightTrans);

    if(it)
    {
        std::cout << "Хотите заполнить дополнительные поля?\n";
        std::cout << "1: Да\n0: Нет" << std::endl;
        int answer = -1;
        while (answer != 0 && answer != 1)
            std::cin >> answer;
                
        if (answer)
            it->edit();
    }
}

// удаление
void Table::delete_tr(int id)
{
    try
    {
        if (m_vehicles.empty())
            throw std::logic_error("Список пуст");

        bool flag = false;

        for (auto it = m_vehicles.begin(); it != m_vehicles.end(); ++it)
        {
            if ((*it)->get_id() == id)
            {
                m_vehicles.erase(it);
                flag = 1; // указываем, что нашли элемент
                std::cout << "Элемент удален" << std::endl;
                break;
            }
        }

        if (!flag)
            throw std::logic_error("Элемент не найден");
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

// редактирование
void Table::edit_tr(int id, int for_edit)
{
    try
    {

        if (m_vehicles.empty())
            throw std::logic_error("Список пуст");

        bool flag = false;

        for (auto it = m_vehicles.begin(); it != m_vehicles.end(); ++it)
        {
            if ((*it)->get_id() == id)
            {
                if (for_edit == 5) 
                {
                   (*it)->edit();
                }

                if (for_edit != 0 && for_edit != 5)
                {
                    std::cout << "Введите изменение: " << std::endl;
                    std::string editClassField;
                    std::cin >> editClassField;

                    if (for_edit == 1 || for_edit == 2)
                        editClassField[0] = std::toupper(editClassField[0]);

                    //устанавливаем стратегию для редактирования поля
                    m_context.setStrategy(m_mapForStrategy[for_edit]());

                    //вызываем редактирование
                    m_context.callEditStrategy(editClassField, *it);

                }

                flag = true; // указываем, что нашли элемент
                break;
            }
        }
        if (!flag)
            throw std::logic_error("Элемент не найден");
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

// сортировка
void Table::sort_tr(int for_sort)
{
    try
    {
        auto it_strategy = m_mapForStrategy.find(for_sort);
        //проверка на наличие стратегии
        if (it_strategy == m_mapForStrategy.end())
            throw std::logic_error("нет такой стратегии!");

        //задаем стратегию для сортировки
        m_context.setStrategy(it_strategy->second());

        //вызываем сортировку по полю
        m_context.callSortStrategy(m_vehicles);

        //отрисовываем
        printTable();

        //ззадаем стратегию для сортировки по ID(возвращаем в исходное положение)
        m_context.setStrategy(m_mapForStrategy[1]());
        //вызываем сортировку по ID
        m_context.callSortStrategy(m_vehicles);

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

// поиск
void Table::find_tr(const std::string& edit, int for_find)
{
    try
    {
        if (m_vehicles.empty())
            throw std::logic_error("Список пуст");

        auto it_strategy = m_mapForStrategy.find(for_find);
        //проверка на наличие стратегии
        if (it_strategy == m_mapForStrategy.end())
            throw std::logic_error("нет такой стратегии!");

        //устанавливаем стратегию
        m_context.setStrategy(it_strategy->second());

        //вызываем поиск по полю
        std::vector<Transport*> vec = m_context.callFindStrategy(edit, m_vehicles);
        
        if(vec.empty())
        {
            std::cerr << "Элемент не найдет!" << std::endl;
            return;
        }
        for (const auto& it : vec)
        {
            it->info();
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

// сохранить в файл
void Table::writingFile(const std::string &name)
{
    try
    {
        WorkWithFile w(name);
        std::string result;

        for (auto& it : m_vehicles)
        {
            result = it->get_type();
            result += " ";
            result += it->get_brand();
            result += " ";
            result += it->get_model();
            result += " ";
            result += std::to_string(it->get_year());
            result += " ";
            result += std::to_string(it->get_weight());
            result += " ";
            result += it->load_to_file();
            w.inputToFile(result);
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

// загрузить из файла
void Table::readingFile(const std::string &name)
{
    try
    {
        std::string typeTrans, brandTrans, modelTrans;
        int yearTrans;
        double weightTrans;
        WorkWithFile w(name);
        std::vector<std::string> v;     //вектор строк из файла(1 строка - 1 объект)
        v = w.outFromFile();        //получили вектор объектов-строк

        if (v.empty())
            throw std::runtime_error("Файл пустой");

        for (const std::string &line : v)
        {
            std::istringstream in(line);
            in >> typeTrans >> brandTrans >> modelTrans >> yearTrans >> weightTrans;
            auto it = create_tr(typeTrans, brandTrans, modelTrans, yearTrans, weightTrans);
            
            if (it)
                it->read_from_file(in);
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