#pragma once

#include "Creator.h"

#include "CreateCar.h"
#include "CreateBoat.h"
#include "CreateHelicopter.h"
#include "CreateSpaceship.h"
//_________________________________________

#include "Strategy.h"
#include "Context.h"

#include "StrategyId.h"
#include "StrategyType.h"
#include "StrategyBrand.h"
#include "StrategyModel.h"
#include "StrategyYear.h"
#include "StrategyWeight.h"
#include "StrategyOwners.h"
#include "StrategyMileage.h"
#include "StrategyLengthBoat.h"
#include "StrategyWidthBoat.h"
#include "StrategyCapacity.h"
#include "StrategyEnginePower.h"
#include "StrategyMaxSpeed.h"
#include "StrategyHyperjumpRange.h"
//_________________________________________

#include "WorkWithFile.h"

#include <map>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <functional>

class Table 
{
    private:
        
        using FindType = std::vector<std::unique_ptr<Transport>>::iterator;
        using CreateType = std::unique_ptr<Creator>;
        

        //вектор с ссылками на стратегии
        std::map<int, std::function<std::unique_ptr<Strategy>()>> m_mapForStrategy;

        //map для создания
        std::map<std::string, std::function<CreateType()>> createMap;

        //контейнер с объектами
        std::vector<std::unique_ptr<Transport>> m_vehicles;

        //для стратегий
        Context m_context;


    public:
        //конструктор
        Table(std::unique_ptr<Strategy>&& otherStrategy);
        //деструктор
        ~Table() = default;

        //методы
        //для отрисовки
        void forPrintTable(const std::vector<std::unique_ptr<Transport>>& vehicles, 
            const int width, 
            const int data_width,
            const std::string& label, 
            std::function<std::string(Transport*)> get_value) const;

        //отрисовка
        void printTable() const;

        //создание
        Transport* create_tr(
            const std::string& typeTrans, 
            const std::string& brandTrans, 
            const std::string& modelTrans, 
            int yearTrans, 
            double weightTrans);


        //создание с доп. полями
        void create_addit_field_tr(const std::string& typeTrans, 
            const std::string& brandTrans, 
            const std::string& modelTrans, 
            int yearTrans, 
            double weightTrans);
            
        //удаление
        void delete_tr(int id);

        //редактирование
        void edit_tr(int id, int for_edit);

        //сортировка
        void sort_tr(int for_sort);

        //поиск
        void find_tr(const std::string& edit, int for_find);

        //сохранить в файл
        void writingFile(const std::string& name);

        //загрузить из файла
        void readingFile(const std::string& name);
};