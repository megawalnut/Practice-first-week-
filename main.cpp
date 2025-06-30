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

			typeTrans[0] = std::toupper(typeTrans[0]);

			if (typeTrans == "Car" ||
				typeTrans == "Boat" ||
				typeTrans == "Helicopter" ||
				typeTrans == "CaSpaceshipr") 
			{
				std::string brandTrans;
				std::string modelTrans;
				int yearTrans;
				double weightTrans;

				std::cout << "Введи марку: \n";
				std::cin >> brandTrans;
				std::cout << "Введи модель: \n";
				std::cin >> modelTrans;
				std::cout << "Введи год: \n";
				std::cin >> yearTrans;
				std::cout << "Введи вес(кг): \n";
				std::cin >> weightTrans;

				tb.create_addit_field_tr(typeTrans, brandTrans, modelTrans, yearTrans, weightTrans);
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
			std::cout << "7: Доп. поля\n";
			std::cout << "0: Выход" << std::endl;
			
			int for_sort = -1;
			while (for_sort < 0 || for_sort > 7)
				std::cin >> for_sort;

			if (for_sort != 0)
			{
				if (for_sort == 7) 
				{
					std::cout << "Car ->\n";
					std::cout << "\t7: Число владельцев\n";
					std::cout << "\t8: Пробег\n";
					std::cout << "Boat ->\n";
					std::cout << "\t9: Длина судна\n";
					std::cout << "\t10: Ширина судна\\n";
					std::cout << "Helicopter ->\n";
					std::cout << "\t11: Грузоподьемность(т.)\n";
					std::cout << "\t12: Мощность двигателя(л.с.)\n";
					std::cout << "Spaceship ->\n";
					std::cout << "\t13: Максимальная скорость(км/с)\n";
					std::cout << "\t14: Дальность гиперпрыжка(а.е.)" << std::endl;

					while (for_sort < 7 || for_sort > 14)
						std::cin >> for_sort;
				}

				tb.sort_tr(for_sort);
			}
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
			std::cout << "7: Доп. поля\n";
			std::cout << "0: Выход" << std::endl;

			int for_find = -1;
			while (for_find < 0 || for_find > 8)
				std::cin >> for_find;

			if (for_find != 0)
			{		
				if (for_find == 7)
				{
					std::cout << "Car ->\n";
					std::cout << "\t7: Число владельцев\n";
					std::cout << "\t8: Пробег\n";
					std::cout << "Boat ->\n";
					std::cout << "\t9: Длина судна\n";
					std::cout << "\t10: Ширина судна\\n";
					std::cout << "Helicopter ->\n";
					std::cout << "\t11: Грузоподьемность(т.)\n";
					std::cout << "\t12: Мощность двигателя(л.с.)\n";
					std::cout << "Spaceship ->\n";
					std::cout << "\t13: Максимальная скорость(км/с)\n";
					std::cout << "\t14: Дальность гиперпрыжка(а.е.)" << std::endl;

					while (for_find < 7 || for_find > 14)
						std::cin >> for_find;
				}
				std::cout << "Введите элемент: " << std::endl;
				std::string edit;
				std::cin >> edit;

				tb.find_tr(for_find, edit);
			}

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