#pragma once

#include "Creator.h"

#include "CreateCar.h"
#include "CreateBoat.h"
#include "CreateHelicopter.h"
#include "CreateSpaceship.h"

#include "WorkWithFile.h"

#include <iostream>
#include <algorithm>
#include <sstream>
#include <iomanip>

class Table {
	private:
		std::vector<std::unique_ptr<Transport>> m_vehicles;

	public:
		//конструктор
		Table() = default;
		//деструктор
		~Table() = default;

		//методы
		//отрисовка
		void printTable() const;

		//создание
		void create_tr(
            const std::string& typeTrans, 
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
		void find_tr(int for_find)  const;

		//сохранить в файл
		void input_file(const std::string& name) const;

		//загрузить из файла
		void output_file(const std::string& name);
};

