#include "Table.h"

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
void Table::create_tr(
    const std::string &typeTrans,
    const std::string &brandTrans,
    const std::string &modelTrans,
    int yearTrans,
    double weightTrans)
{
    try
    {
        std::unique_ptr<Creator> creator = nullptr;

        if (typeTrans == "Car" || typeTrans == "car")
        {
            creator = std::make_unique<CreateCar>();
        }
        else if (typeTrans == "Helicopter" || typeTrans == "helicopter")
        {
            creator = std::make_unique<CreateHelicopter>();
        }
        else if (typeTrans == "Boat" || typeTrans == "boat")
        {
            creator = std::make_unique<CreateBoat>();
        }
        else if (typeTrans == "Spaceship" || typeTrans == "spaceship")
        {
            creator = std::make_unique<CreateSpaceship>();
        }
        if (creator)
        {
            std::unique_ptr<Transport> res = std::move(creator->create(brandTrans, modelTrans, yearTrans, weightTrans));
            m_vehicles.push_back(std::move(res));
        }
    }
    catch (...)
    {
        std::cerr << "Неизвестная ошибка" << std::endl;
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
                    std::cout << "0: Выход" << std::endl;

                    while (for_edit < 0 || for_edit > 4)
                        std::cin >> for_edit;

                    switch (for_edit)
                    {
                    case 1:
                    {
                        std::cout << "Введите новую марку: \n";
                        std::string set;
                        std::cin >> set;

                        (*it)->set_brand(set);

                        for_edit = -1;
                        break;
                    }
                    case 2:
                    {
                        std::cout << "Введите новую модель: \n";
                        std::string set;
                        std::cin >> set;

                        (*it)->set_model(set);

                        for_edit = -1;
                        break;
                    }
                    case 3:
                    {
                        std::cout << "Введите новый год: \n";
                        int set;
                        std::cin >> set;

                        (*it)->set_year(set);

                        for_edit = -1;
                        break;
                    }
                    case 4:
                    {
                        std::cout << "Введите новый вес(кг): \n";
                        double set;
                        std::cin >> set;

                        (*it)->set_weight(set);

                        for_edit = -1;
                        break;
                    }
                    case 0:
                    {
                        break;
                    }
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
        switch (for_sort)
        {
        case 1:
        {
            sort(m_vehicles.begin(), m_vehicles.end(), [](const auto &a, const auto &b)
                 { return a->get_id() < b->get_id(); });
            break;
        }
        case 2:
        {
            sort(m_vehicles.begin(), m_vehicles.end(), [](const auto &a, const auto &b)
                 { return a->get_type() < b->get_type(); });
            break;
        }
        case 3:
        {
            sort(m_vehicles.begin(), m_vehicles.end(), [](const auto &a, const auto &b)
                 { return a->get_brand() < b->get_brand(); });
            break;
        }
        case 4:
        {
            sort(m_vehicles.begin(), m_vehicles.end(), [](const auto &a, const auto &b)
                 { return a->get_model() < b->get_model(); });
            break;
        }
        case 5:
        {
            sort(m_vehicles.begin(), m_vehicles.end(), [](const auto &a, const auto &b)
                 { return a->get_year() < b->get_year(); });
            break;
        }
        case 6:
        {
            sort(m_vehicles.begin(), m_vehicles.end(), [](const auto &a, const auto &b)
                 { return a->get_weight() < b->get_weight(); });
            break;
        }
        case 0:
        {
            break;
        }
        }
        if (for_sort != 0)
        {
            printTable();
            sort(m_vehicles.begin(), m_vehicles.end(), [](const auto &a, const auto &b)
                 { return a->get_id() < b->get_id(); });
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
void Table::find_tr(int for_find) const
{
    try
    {

        if (m_vehicles.empty())
            throw std::logic_error("Список пуст");

        auto it = m_vehicles.end();

        switch (for_find)
        {
        case 1:
        {
            std::cout << "Введите Id: " << std::endl;
            int ifInputId;
            std::cin >> ifInputId;
            it = find_if(m_vehicles.begin(), m_vehicles.end(), [&ifInputId](const auto &a)
                         { return a->get_id() == ifInputId; });
            break;
        }
        case 2:
        {
            std::cout << "Введите тип: " << std::endl;
            std::string ifInputType;
            std::cin >> ifInputType;
            it = find_if(m_vehicles.begin(), m_vehicles.end(), [&ifInputType](const auto &a)
                         { return a->get_type() == ifInputType; });
            break;
        }
        case 3:
        {
            std::cout << "Введите марку: " << std::endl;
            std::string ifInputBrand;
            std::cin >> ifInputBrand;
            it = find_if(m_vehicles.begin(), m_vehicles.end(), [&ifInputBrand](const auto &a)
                         { return a->get_brand() == ifInputBrand; });
            break;
        }
        case 4:
        {
            std::cout << "Введите модель: " << std::endl;
            std::string ifInputModel;
            std::cin >> ifInputModel;
            it = find_if(m_vehicles.begin(), m_vehicles.end(), [&ifInputModel](const auto &a)
                         { return a->get_model() == ifInputModel; });
            break;
        }
        case 5:
        {
            std::cout << "Введите год: " << std::endl;
            int ifInputYear;
            std::cin >> ifInputYear;
            it = find_if(m_vehicles.begin(), m_vehicles.end(), [&ifInputYear](const auto &a)
                         { return a->get_year() == ifInputYear; });
            break;
        }
        case 6:
        {
            std::cout << "Введите вес(кг): " << std::endl;
            double ifInputWeight;
            std::cin >> ifInputWeight;
            it = find_if(m_vehicles.begin(), m_vehicles.end(), [&ifInputWeight](const auto &a)
                         { return a->get_weight() == ifInputWeight; });
            break;
        }
        case 0:
        {
            break;
        }
        }
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
void Table::input_file(const std::string &name) const
{
    try
    {

        WorkWithfile w(name);

        std::string result;
        for (auto it = m_vehicles.begin(); it != m_vehicles.end(); ++it)
        {

            result = (*it)->get_type();
            result += " ";
            result += (*it)->get_brand();
            result += " ";
            result += (*it)->get_model();
            result += " ";
            result += std::to_string((*it)->get_year());
            result += " ";
            result += std::to_string((*it)->get_weight());

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
        std::vector<std::string> v;
        v = w.out();

        if (v.empty())
            throw std::runtime_error("Файл пустой");

        for (const std::string &line : v)
        {
            std::istringstream in(line);
            in >> typeTrans >> brandTrans >> modelTrans >> yearTrans >> weightTrans;
            create_tr(typeTrans, brandTrans, modelTrans, yearTrans, weightTrans);
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