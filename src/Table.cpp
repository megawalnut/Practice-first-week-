#include "Table.h"
#include "Car.h"
#include "Boat.h"
#include "Helicopter.h"
#include "Spaceship.h"

#include <map>
#include <functional>
#include <stdlib.h>

//конструктор
Table::Table() 
{
    additMap =
    {
        {"Car", [](Transport* t)
            {
                Car* c = dynamic_cast<Car*>(t);
                std::cout << "Введите через пробел число владельцев и пробег(км):" << std::endl;
                int ownersTrans; double mileageTrans;
                std::cin >> ownersTrans >> mileageTrans;
                c->set_owners(ownersTrans);
                c->set_mileage(mileageTrans);
            }},
        {"Boat", [](Transport* t)
            {
                Boat* b = dynamic_cast<Boat*>(t);
                std::cout << "Введите через пробел длину и ширину судна(м):" << std::endl;
                double lengthBoatTrans; double widthBoatTrans;
                std::cin >> lengthBoatTrans >> widthBoatTrans;
                b->set_lengthBoat(lengthBoatTrans);
                b->set_widthBoat(widthBoatTrans);
            }},
        {"Helicopter", [](Transport* t)
            {
                Helicopter* h = dynamic_cast<Helicopter*>(t);
                std::cout << "Введите через пробел грузоподъемность(т) и мощность двигателя(л.с.):" << std::endl;
                double capacityTrans; int enginePowerTrans;
                std::cin >> capacityTrans >> enginePowerTrans;
                h->set_capacity(capacityTrans);
                h->set_enginePower(enginePowerTrans);
            }},
        {"Spaceship", [](Transport* t)
            {
                Spaceship* s = dynamic_cast<Spaceship*>(t);
                std::cout << "Введите через пробел макс. скорость(км/с) и дальность гиперпржыка(а.е.):" << std::endl;
                double maxSpeedTrans; double hyperjumpRangeTrans;
                std::cin >> maxSpeedTrans >> hyperjumpRangeTrans;
                s->set_maxSpeed(maxSpeedTrans);
                s->set_hyperjumpRange(hyperjumpRangeTrans);
            }}
    };
    createMap = 
    {
        {"Car", [](){ return std::make_unique<CreateCar>();} },
        {"Boat", [](){ return std::make_unique<CreateBoat>();} },
        {"Helicopter", [](){ return std::make_unique<CreateHelicopter>();} },
        {"Spaceship", [](){ return std::make_unique<CreateSpaceship>();} },
    };
    editMap = 
    {
        { 0, [](std::string& editClassField, std::unique_ptr<Transport>& it) { return it->set_brand(editClassField); } },
        { 1, [](std::string& editClassField, std::unique_ptr<Transport>& it) { return it->set_model(editClassField); } },
        { 2, [](std::string& editClassField, std::unique_ptr<Transport>& it) { return it->set_year(std::atoi(editClassField.c_str())); } },
        { 3, [](std::string& editClassField, std::unique_ptr<Transport>& it) { return it->set_weight(std::atof(editClassField.c_str())); } },
    };
    sortMap =
    {
        { 0, [&](){std::sort(m_vehicles.begin(), m_vehicles.end(), [](const auto &a, const auto &b) { return a->get_id()     < b->get_id();     });} },
        { 1, [&](){std::sort(m_vehicles.begin(), m_vehicles.end(), [](const auto &a, const auto &b) { return a->get_type()   < b->get_type();   });} },
        { 2, [&](){std::sort(m_vehicles.begin(), m_vehicles.end(), [](const auto &a, const auto &b) { return a->get_brand()  < b->get_brand();  });} },
        { 3, [&](){std::sort(m_vehicles.begin(), m_vehicles.end(), [](const auto &a, const auto &b) { return a->get_model()  < b->get_model();  });} },
        { 4, [&](){std::sort(m_vehicles.begin(), m_vehicles.end(), [](const auto &a, const auto &b) { return a->get_year()   < b->get_year();   });} },
        { 5, [&](){std::sort(m_vehicles.begin(), m_vehicles.end(), [](const auto &a, const auto &b) { return a->get_weight() < b->get_weight(); });} },
        { 6, [&](){std::sort(m_vehicles.begin(), m_vehicles.end(), [](const auto &a, const auto &b) { return a->get_owners() < b->get_owners(); });} },
        { 7, [&](){std::sort(m_vehicles.begin(), m_vehicles.end(), [](const auto &a, const auto &b) { return a->get_mileage() < b->get_mileage(); });} },
        { 8, [&](){std::sort(m_vehicles.begin(), m_vehicles.end(), [](const auto &a, const auto &b) { return a->get_lengthBoat() < b->get_lengthBoat(); });} },
        { 9, [&](){std::sort(m_vehicles.begin(), m_vehicles.end(), [](const auto &a, const auto &b) { return a->get_widthBoat() < b->get_widthBoat(); });} },
        { 10, [&](){std::sort(m_vehicles.begin(), m_vehicles.end(), [](const auto &a, const auto &b) { return a->get_capacity() < b->get_capacity(); });} },
        { 11, [&](){std::sort(m_vehicles.begin(), m_vehicles.end(), [](const auto &a, const auto &b) { return a->get_enginePower() < b->get_enginePower(); });} },
        { 12, [&](){std::sort(m_vehicles.begin(), m_vehicles.end(), [](const auto &a, const auto &b) { return a->get_maxSpeed() < b->get_maxSpeed(); });} },
        { 13, [&](){std::sort(m_vehicles.begin(), m_vehicles.end(), [](const auto &a, const auto &b) { return a->get_hyperjumpRange() < b->get_hyperjumpRange(); });} },
    };
    findMap =
    {
        { 0, [&](const std::string& edit)
            { return std::find_if(m_vehicles.begin(), m_vehicles.end(), [](const auto &a, std::string& edit) { return a->get_id() == atoi(edit.c_str()); }); } 
        },
        { 1, [&](const std::string& edit)
            { return std::find_if(m_vehicles.begin(), m_vehicles.end(), [](const auto &a, std::string& edit) { return a->get_type() == edit; }); } 
        },
        { 2, [&](const std::string& edit)
            { return std::find_if(m_vehicles.begin(), m_vehicles.end(), [](const auto &a, std::string& edit) { return a->get_brand() == edit; }); } 
        },
        { 3, [&](const std::string& edit)
            { return std::find_if(m_vehicles.begin(), m_vehicles.end(), [](const auto &a, std::string& edit) { return a->get_model() == edit; }); } 
        },
        { 4, [&](const std::string& edit)
            { return std::find_if(m_vehicles.begin(), m_vehicles.end(), [](const auto &a, std::string& edit) { return a->get_year() == atoi(edit.c_str()); }); } 
        },
        { 5, [&](const std::string& edit)
            { return std::find_if(m_vehicles.begin(), m_vehicles.end(), [](const auto &a, std::string& edit ){ return a->get_weight() == atof(edit.c_str()); }); } 
        },
        { 6, [&](const std::string& edit)
            { return std::find_if(m_vehicles.begin(), m_vehicles.end(), [](const auto &a, std::string& edit ) { return a->get_owners() == atoi(edit.c_str()); }); } 
        },
        { 7, [&](const std::string& edit)
            { return std::find_if(m_vehicles.begin(), m_vehicles.end(), [](const auto &a, std::string& edit ) { return a->get_mileage() == atof(edit.c_str()); }); } 
        },
        { 8, [&](const std::string& edit)
            { return std::find_if(m_vehicles.begin(), m_vehicles.end(), [](const auto &a, std::string& edit ) { return a->get_lengthBoat() == atof(edit.c_str()); }); } 
        },
        { 9, [&](const std::string& edit)
            { return std::find_if(m_vehicles.begin(), m_vehicles.end(), [](const auto &a, std::string& edit ) { return a->get_widthBoat() == atof(edit.c_str()); }); } 
        },
        { 10, [&](const std::string& edit)
            { return std::find_if(m_vehicles.begin(), m_vehicles.end(), [](const auto &a, std::string& edit ) { return a->get_capacity() == atof(edit.c_str()); }); } 
        },
        { 11, [&](const std::string& edit)
            { return std::find_if(m_vehicles.begin(), m_vehicles.end(), [](const auto &a, std::string& edit ) { return a->get_enginePower() == atoi(edit.c_str()); }); } 
        },
        { 12, [&](const std::string& edit)
            { return std::find_if(m_vehicles.begin(), m_vehicles.end(), [](const auto &a, std::string& edit ) { return a->get_maxSpeed() == atof(edit.c_str()); }); } 
        },
        { 13, [&](const std::string& edit)
            { return std::find_if(m_vehicles.begin(), m_vehicles.end(), [](const auto &a, std::string& edit ) { return a->get_hyperjumpRange() == atof(edit.c_str()); }); } 
        }
    };
    saveMap =
    {
        {"Car", [](Transport* t, std::string& result)
            { 
                Car* c = dynamic_cast<Car*>(t);
                result += c->get_owners();
                result += " ";
                result += c->get_mileage();
                return result;
            } },
        {"Boat", [](Transport* t, std::string& result)
            { 
                Boat* b = dynamic_cast<Boat*>(t);
                result += b->get_lengthBoat();
                result += " ";
                result += b->get_widthBoat();
                return result;
            } },
        {"Helicopter", [](Transport* t, std::string& result)
            { 
                Helicopter* h = dynamic_cast<Helicopter*>(t);
                result += h->get_capacity();
                result += " ";
                result += h->get_enginePower();
                return result;
            } },
        {"Spaceship", [](Transport* t, std::string& result)
            { 
                Spaceship* s = dynamic_cast<Spaceship*>(t);
                result += s->get_maxSpeed();
                result += " ";
                result += s->get_hyperjumpRange();
                return result;
            } },
    };
    loadMap =
    {
        {"Car", [](Transport* t, std::istringstream& in)
            {
                Car* c = dynamic_cast<Car*>(t);
                int ownersTrans; double mileageTrans;
                in >> ownersTrans >> mileageTrans;
                c->set_owners(ownersTrans);
                c->set_mileage(mileageTrans);
            }},
        {"Boat", [](Transport* t, std::istringstream& in)
            {
                Boat* b = dynamic_cast<Boat*>(t);
                double lengthBoatTrans; double widthBoatTrans;
                in >> lengthBoatTrans >> widthBoatTrans;
                b->set_lengthBoat(lengthBoatTrans);
                b->set_widthBoat(widthBoatTrans);
            }},
        {"Helicopter", [](Transport* t, std::istringstream& in)
            {
                Helicopter* h = dynamic_cast<Helicopter*>(t);
                double capacityTrans; int enginePowerTrans;
                in >> capacityTrans >> enginePowerTrans;
                h->set_capacity(capacityTrans);
                h->set_enginePower(enginePowerTrans);
            }},
        {"Spaceship", [](Transport* t, std::istringstream& in)
            {
                Spaceship* s = dynamic_cast<Spaceship*>(t);
                double maxSpeedTrans; double hyperjumpRangeTrans;
                in >> maxSpeedTrans >> hyperjumpRangeTrans;
                s->set_maxSpeed(maxSpeedTrans);
                s->set_hyperjumpRange(hyperjumpRangeTrans);
            }}
    };

}


// методы

// отрисовка
void Table::printTable() const
{
    try
    {
        if (m_vehicles.empty())
            throw std::logic_error("Список пуст");
        std::cout << "\n";
        std::cout << std::left
                  << std::setw(2) << "ID" << "| "
                  << std::setw(13) << "Тип" << "| "
                  << std::setw(14) << "Марка" << "| "
                  << std::setw(14) << "Модель" << "| "
                  << std::setw(9) << "Год" << "| "
                  << std::setw(12) << "Вес (кг)" << '\n';

        // разделитель
        std::cout << std::string(2, '-') << "+"
                  << std::string(11, '-') << "+"
                  << std::string(10, '-') << "+"
                  << std::string(9, '-') << "+"
                  << std::string(7, '-') << "+"
                  << std::string(10, '-') << "\n";

        for (const auto &x : m_vehicles)
        {
            x->info();
        }
        std::cout << std::endl;
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
std::unique_ptr<Transport>  Table::create_tr(
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

            m_vehicles.push_back(std::move(res));
            return std::move(res);
        }
        return nullptr;
    }
    catch (...)
    {
        std::cerr << "Неизвестная ошибка" << std::endl;
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
        std::cout << "1: Да\n 2: Нет" << std::endl;
        bool answer;
        std::cin >> answer;
                
        if (answer)
            additMap[it->get_type()](it.get());        
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

        for (auto it = m_vehicles.begin(); it != m_vehicles.end(); it++)
        {
            if (id == (*it)->get_id())
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
void Table::edit_tr(int id)
{
    try
    {

        if (m_vehicles.empty())
            throw std::logic_error("Список пуст");

        bool flag = false;

        for (auto it = m_vehicles.begin(); it != m_vehicles.end(); ++it)
        {
            if (id == (*it)->get_id())
            {

                int for_edit = -1;

                while (for_edit != 0)
                {

                    std::cout << "Выберите: \n";
                    std::cout << "1: Марка\n";
                    std::cout << "2: Модель\n";
                    std::cout << "3: Год\n";
                    std::cout << "4: Вес\n";
                    std::cout << "5: Доп. поля\n";
                    std::cout << "0: Выход" << std::endl;

                    while (for_edit < 0 || for_edit > 5)
                        std::cin >> for_edit;

                    if (for_edit == 5) 
                    {
                        additMap[(*it)->get_type()]((*it).get());
                        continue;
                    }

                    if (for_edit != 0)
                    {
                    
                        std::cout << "Введите изменение: " << std::endl;
                        std::string editClassField;
                        std::cin >> editClassField;

                        editMap[for_edit - 1](editClassField, *it);

                        for_edit = -1;
                    }
                }

                flag = 1; // указываем, что нашли элемент
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
        if (for_sort > 0 && for_sort < 15)
        {
            sortMap[for_sort - 1]();
            printTable();
            sortMap[0]();
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

// поиск
void Table::find_tr(int for_find, const std::string& edit)
{
    try
    {
        if (m_vehicles.empty())
            throw std::logic_error("Список пуст");

        auto it = findMap[for_find - 1](edit);
        if (it != m_vehicles.end())
        {
            (*it)->info();
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
void Table::input_file(const std::string &name)
{
    try
    {
        WorkWithfile w(name);
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
            result += std::to_string(it->get_weight());
            result += " ";
            saveMap[it->get_type()](it.get(), result);
            w.in(result);
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
void Table::output_file(const std::string &name)
{
    try
    {
        std::string typeTrans, brandTrans, modelTrans;
        int yearTrans;
        double weightTrans;
        WorkWithfile w(name);
        std::vector<std::string> v;     //вектор строк из файла(1 строка - 1 объект)
        v = w.out();

        if (v.empty())
            throw std::runtime_error("Файл пустой");

        for (const std::string &line : v)
        {
            std::istringstream in(line);
            in >> typeTrans >> brandTrans >> modelTrans >> yearTrans >> weightTrans;
            auto it = create_tr(typeTrans, brandTrans, modelTrans, yearTrans, weightTrans);
            
            if (!it)
                loadMap[typeTrans](it.get(), in);
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