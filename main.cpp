#include "Transport.h"
#include "Car.h"
#include "Helicopter.h"
#include "Boat.h"
#include "Spaceship.h"

#include "Creator.h"
#include "CreateCar.h"
#include "CreateHelicopter.h"
#include "CreateBoat.h"
#include "CreateSpaceship.h"

#include "WorkWithFile.h"

#include "Table.h"

int main()
{
	setlocale(LC_ALL, "rus");

	int menu = -1;
	Table tb;
	while (menu)
	{

		// меню
		std::cout << "1: Создание\n";
		std::cout << "2: Редактирование\n";
		std::cout << "3: Удаление\n";
		std::cout << "4: Отображение с сортировкой по полю\n";
		std::cout << "5: Поиск по полю\n";
		std::cout << "6: Сохранение в файл\n";
		std::cout << "7: Запись из файла\n";
		std::cout << "8: Показать таблицу\n";
		std::cout << "0: Выход" << std::endl;

		while (menu < 0 || menu > 8)
			std::cin >> menu;

		switch (menu)
		{
		case 1:
		{
			// создание

			std::cout << "Выбери тип транспорта для создания \n";
			std::cout << "Car\n";
			std::cout << "Helicopter\n";
			std::cout << "Boat\n";
			std::cout << "Spaceship\n";
			std::cout << "Выйти - Null" << std::endl;

			std::string typeTrans;
			std::cin >> typeTrans;

			if (typeTrans == "Null" || typeTrans == "null")
			{
				menu = -1;
				break;
			}

			if (typeTrans == "Car" || typeTrans == "car" ||
				typeTrans == "Helicopter" || typeTrans == "helicopter" ||
				typeTrans == "Boat" || typeTrans == "boat" ||
				typeTrans == "Spaceshit" || typeTrans == "spaceship")
			{

				std::string brandTrans;
				std::string modeTrans;
				int yearTrans;
				double weightTrans;

				std::cout << "Введи марку: \n";
				std::cin >> brandTrans;
				std::cout << "Введи модель: \n";
				std::cin >> modeTrans;
				std::cout << "Введи год: \n";
				std::cin >> yearTrans;
				std::cout << "Введи вес(кг): \n";
				std::cin >> weightTrans;

				tb.create_tr(typeTrans, brandTrans, modeTrans, yearTrans, weightTrans);
			}
			menu = -1;
			break;
		}
		case 2:
		{
			// редактирование

			int id;
			std::cout << "Введите id объекта" << std::endl;
			std::cin >> id;

			tb.edit_tr(id);
			menu = -1;
			break;
		}
		case 3:
		{
			// удаление

			int id;
			std::cout << "Введите id объекта" << std::endl;
			std::cin >> id;

			tb.delete_tr(id);
			menu = -1;
			break;
		}
		case 4:
		{
			// сортировка

			std::cout << "Выберите поле для сортировки: \n";
			std::cout << "1: Id\n";
			std::cout << "2: Тип\n";
			std::cout << "3: Марка\n";
			std::cout << "4: Модель\n";
			std::cout << "5: Год\n";
			std::cout << "6: Вес\n";
			std::cout << "0: Выход" << std::endl;

			int for_sort = -1;
			while (for_sort < 0 || for_sort > 6)
				std::cin >> for_sort;

			tb.sort_tr(for_sort);
			menu = -1;
			break;
		}
		case 5:
		{
			// поиск

			std::cout << "Выберите поле для поиска: \n";
			std::cout << "1: Id\n";
			std::cout << "2: Тип\n";
			std::cout << "3: Марка\n";
			std::cout << "4: Модель\n";
			std::cout << "5: Год\n";
			std::cout << "6: Вес\n";
			std::cout << "0: Выход" << std::endl;

			int for_find = -1;
			while (for_find < 0 || for_find > 6)
				std::cin >> for_find;

			tb.find_tr(for_find);
			menu = -1;
			break;
		}
		case 6:
		{
			// сохранение в файл

			std::cout << "Введите имя файла для сохранения: " << std::endl;
			std::string name;
			std::cin >> name;

			tb.input_file(name);
			menu = -1;
			break;
		}
		case 7:
		{
			// запись из файла

			std::cout << "Введите имя файла для чтения: " << std::endl;
			std::string name;
			std::cin >> name;

			tb.output_file(name);
			menu = -1;
			break;
		}
		case 8:
		{
			// отрисовка

			tb.printTable();
			menu = -1;
			break;
		}
		case 0:
		{
			menu = 0;
			break;
		}
		}
	}

	return 0;
}