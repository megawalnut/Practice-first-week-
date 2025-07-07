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
	std::unique_ptr<Strategy> strat = std::make_unique<Strategy>();
	Table tb(std::move(strat));

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

		//проверка на ввод
		while (menu < 0 || menu > 8)
			std::cin >> menu;

		switch (menu)
		{
		case 1:
		{
			// создание

			std::cout << "Выбери тип транспорта для создания: \n";
			std::cout << "Car\n";
			std::cout << "Helicopter\n";
			std::cout << "Boat\n";
			std::cout << "Spaceship\n";
			std::cout << "Выйти - Null" << std::endl;

			std::string typeTrans;	//тип

			//вводим тип
			std::cin >> typeTrans;

			//с заглавной буквы
			typeTrans[0] = std::toupper(typeTrans[0]);

			//проверка типа
			if (typeTrans == "Car" ||
				typeTrans == "Boat" ||
				typeTrans == "Helicopter" ||
				typeTrans == "Spaceshipr") 
			{
				std::string brandTrans;	//марка
				std::string modelTrans;	//модель
				int yearTrans;			//год
				double weightTrans;		//вес

				std::cout << "Введи марку: \n";
				//вводим марку
				std::cin >> brandTrans;

				//с заглавной буквы
				brandTrans[0] = std::toupper(brandTrans[0]);

				std::cout << "Введи модель: \n";
				//вводим модель
				std::cin >> modelTrans;

				//с заглавной буквы
				modelTrans[0] = std::toupper(modelTrans[0]);

				std::cout << "Введи год: \n";
				//вводим год
				std::cin >> yearTrans;

				std::cout << "Введи вес(кг): \n";
				//вводим вес
				std::cin >> weightTrans;

				//вызываем ф-цию создания
				tb.create_addit_field_tr(typeTrans, brandTrans, modelTrans, yearTrans, weightTrans);
			}
			menu = -1;
			break;
		}
		case 2:
		{
			// редактирование

			int id;	//id объекта
			std::cout << "Введите id объекта:" << std::endl;
			//вводим id
			std::cin >> id;

			std::cout << "Выберите: \n";
            std::cout << "1: Марка\n";
            std::cout << "2: Модель\n";
            std::cout << "3: Год\n";
            std::cout << "4: Вес\n";
            std::cout << "5: Доп. поля\n";
            std::cout << "0: Выход" << std::endl;

			int for_edit = -1;	//для выбора поля
			//проверка на вод
            while (for_edit < 0 || for_edit > 5)
                std::cin >> for_edit;

			//вызываем ф-цию редактирования
			tb.edit_tr(id, for_edit);
			menu = -1;
			break;
		}
		case 3:
		{
			// удаление

			int id;	//id объекта
			std::cout << "Введите id объекта" << std::endl;
			//вводим id
			std::cin >> id;

			//вызываем ф-цию удаления
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
			
			int for_sort = -1;	//для выбора поля
			//проверка на ввод
			while (for_sort < 0 || for_sort > 7)
				std::cin >> for_sort;

			//если не выбрали выход
			if (for_sort != 0)
			{
				//если выбрали доп. поля
				if (for_sort == 7) 
				{
					for_sort = -1;

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

					//проверка на ввод
					while (for_sort < 7 || for_sort > 14)
						std::cin >> for_sort;
				}

				//вызываем ф-цию сортировки
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

			int for_find = -1;	//для выбора поля
			//проверка на ввод
			while (for_find < 0 || for_find > 8)
				std::cin >> for_find;

			//если не выбрали выход
			if (for_find != 0)
			{		
				//если выбрали доп.поля
				if (for_find == 7)
				{
					for_find = -1;

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

					//проверка на ввод
					while (for_find < 7 || for_find > 14)
						std::cin >> for_find;
				}
				std::cout << "Введите элемент: " << std::endl;
				std::string edit;	//для поиска по этой строке
				//вводим
				std::cin >> edit;

				//с заглавной буквы 
				if(for_find == 2 || for_find == 3 || for_find == 4)
					edit[0] = std::toupper(edit[0]);

				//вызываем ф-цию поиска
				tb.find_tr(edit, for_find);
			}

			menu = -1;
			break;
		}
		case 6:
		{
			// сохранение в файл

			std::cout << "Введите имя файла для сохранения: " << std::endl;
			std::string name;	//имя файла для сохранения
			//вводим
			std::cin >> name;

			//вызываем ф-цию записи в файл
			tb.writingFile(name);
			menu = -1;
			break;
		}
		case 7:
		{
			// запись из файла

			std::cout << "Введите имя файла для чтения: " << std::endl;
			std::string name;	//имя файла для чтения
			//вводим
			std::cin >> name;

			//вызываем ф-цию чтения из файла
			tb.readingFile(name);
			menu = -1;
			break;
		}
		case 8:
		{
			// отрисовка

			//вызываем ф-цию отрисовки таблицы
			tb.printTable();
			menu = -1;
			break;
		}
		case 0:
		{
			//выход из меню

			menu = 0;
			break;
		}
		}
	}

	return 0;
}