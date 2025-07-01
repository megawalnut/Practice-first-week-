#pragma once

#include "Creator.h"

#include "CreateCar.h"
#include "CreateBoat.h"
#include "CreateHelicopter.h"
#include "CreateSpaceship.h"

#include "WorkWithFile.h"

#include <map>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <functional>

class Table {
	private:
		
        using FindType = std::vector<std::unique_ptr<Transport>>::iterator;
		using CreateType = std::unique_ptr<Creator>;
        
		//map для поиска
		std::map<int,std::function<FindType(const std::string& edit)>> findMap;
		//map для создания
		std::map<std::string, std::function<CreateType()>> createMap;
		//map для добавления полей
		std::map<std::string, std::function<void(Transport* t)>> additMap;
		//map для редактирования
		std::map <int, std::function<void(std::string&, std::unique_ptr<Transport>&)>> editMap;
		//контейнер с объектами
		std::vector<std::unique_ptr<Transport>> m_vehicles;
		//map для загрузки из файла
		std::map<std::string, std::function<void(Transport*, std::istringstream&)>> loadMap;
		//map для сортиировки
		std::map<int, std::function<void()>> sortMap;
		//map для записи в файл
		std::map<std::string, std::function<std::string(Transport*, std::string&)>> saveMap;
		//map вывода найденого объекта
		std::map <std::string, std::function<void(Transport*)>> findTypeMap;
	public:
		//конструктор
		Table();
		//деструктор
		~Table() = default;

		//методы
		//для отрисовки
		void forPrintTable(const std::vector<std::unique_ptr<Transport>>& vehicles, 
				const std::string& label, 
				const int width, 
				const int data_width,
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
		void edit_tr(int id);

		//сортировка
		void sort_tr(int for_sort);

		//поиск
		void find_tr(int for_find, const std::string& edit);

		//сохранить в файл
		void input_file(const std::string& name);

		//загрузить из файла
		void output_file(const std::string& name);
};

