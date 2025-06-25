#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>
#include <memory>

using namespace std;

class Transport {
	private:
		static int for_id;	//для уникальности
		int unique_id;		//уникальный id
		string type;		//тип транспортного средства
		string brand;		//марка
		string model;		//модель
		int year;			//год
		double weight;		//вес

	public:
		//конструктор
		Transport(string str_t, string str_b, string str_m, int i_y, double d_w) : unique_id{ for_id++ }, type{ str_t }, brand{ str_b }, model{ str_m }, year{ i_y }, weight{ d_w } {}
		//конструктор и оператор копирования
		Transport(const Transport& other) : unique_id{ for_id++ }, type{ other.type }, brand{ other.brand }, model{ other.model }, year{ other.year }, weight{ other.weight } {}
		Transport& operator=(const Transport& other) {
			if (&other == this) {
				return *this;
			}

			for_id++;
			unique_id = for_id;
			type = other.type;
			brand = other.brand;
			model = other.model;
			year = other.year;
			weight = other.weight;
		
			return *this;
		}
		//конструктор и оператор перемещения
		Transport(Transport&& other) noexcept: unique_id{ for_id++ }, type{ move(other.type) }, brand{ move(other.brand) }, model{ move(other.model) }, year{ move(other.year) }, weight{ move(other.weight) } {}
		Transport& operator=(Transport&& other) noexcept {
			if (&other == this) {
				return *this;
			}

			for_id++;
			unique_id = for_id;
			type = move(other.type);
			brand = move(other.brand);
			model = move(other.model);
			year = move(other.year);
			weight = move(other.weight);

			return *this;
		}
		//деструктор
		virtual ~Transport() noexcept {} 
		
		//get 
		virtual int get_id() const { return unique_id; }
		virtual string get_type() const { return type; }
		virtual string get_brand() const { return brand; }
		virtual string get_model() const { return model; }
		virtual int get_year() const { return year; }
		virtual double get_weight() const { return weight; }

		//set 
		virtual void set_type(const string& str) { type = str; }
		virtual void set_brand(const string& str) { brand = str; }
		virtual void set_model(const string& str) { model = str; }
		virtual void set_year(const int str) { year = str; }
		virtual void set_weight(const double str) { weight = str; }

		//информация
		virtual void info() const {
			cout << left
				<< setw(2) << get_id() << "| "
				<< setw(10) << get_type() << "| "
				<< setw(9) << get_brand() << "| "
				<< setw(8) << get_model() << "| "
				<< setw(6) << get_year() << "| "
				<< setw(9) << get_weight() << endl;
		}
};
int Transport::for_id = 1;

class Car : public Transport {
	private:


	public:
		//конструктор
		Car(string str_b, string str_m, int i_y, double d_w) : Transport("Car"s, str_b, str_m, i_y, d_w) {}
		//конструктор и оператор копирования
		Car(const Car& other) : Transport(other) {}
		Car& operator=(const Car& other) {
			if (&other == this) {
				return *this;
			}
			Transport::operator=(other);
			return *this;
		}
		//конструктор и оператор перемещения
		Car(Car&& other) noexcept : Transport(move(other)) {}
		Car& operator=(Car&& other) noexcept {
			if (&other == this) {
				return *this;
			}
			Transport::operator=(move(other));

			return *this;
		}
		//деструктор
		~Car() noexcept {}
		
		//get 
		int get_id() const override { return Transport::get_id(); }
		string get_type() const override { return Transport::get_type(); }
		string get_brand() const override { return Transport::get_brand(); }
		string get_model() const override { return Transport::get_model(); }
		int get_year() const override { return Transport::get_year(); }
		double get_weight() const override { return Transport::get_weight(); }

		//set 
		void set_type(const string& str) override { Transport::set_type(str); }
		void set_brand(const string& str) override { Transport::set_brand(str); }
		void set_model(const string& str) override { Transport::set_model(str); }
		void set_year(const int str) override { Transport::set_year(str); }
		void set_weight(const double str) override { Transport::set_weight(str); }

		//информация
		void info() const override {
			cout << left
				<< setw(2) << get_id() << "| "
				<< setw(10) << get_type() << "| "
				<< setw(9) << get_brand() << "| "
				<< setw(8) << get_model() << "| "
				<< setw(6) << get_year() << "| "
				<< setw(9) << get_weight() << endl;
		}

};
class Helicopter : public Transport {
	private:


	public:
		//конструктор
		Helicopter(string str_b, string str_m, int i_y, double d_w) : Transport("Helicopter"s, str_b, str_m, i_y, d_w) {}
		//конструктор и оператор копирования
		Helicopter(const Helicopter& other) : Transport(other) {}
		Helicopter& operator=(const Helicopter& other) {
			if (&other == this) {
				return *this;
			}
			Transport::operator=(other);
			return *this;
		}
		//конструктор и оператор перемещения
		Helicopter(Helicopter&& other) noexcept : Transport(move(other)) {}
		Helicopter& operator=(Helicopter&& other) noexcept {
			if (&other == this) {
				return *this;
			}
			Transport::operator=(move(other));

			return *this;
		}
		//деструктор
		~Helicopter() noexcept {}

		//get 
		int get_id() const override { return Transport::get_id(); }
		string get_type() const override { return Transport::get_type(); }
		string get_brand() const override { return Transport::get_brand(); }
		string get_model() const override { return Transport::get_model(); }
		int get_year() const override { return Transport::get_year(); }
		double get_weight() const override { return Transport::get_weight(); }

		//set 
		void set_type(const string& str) override { Transport::set_type(str); }
		void set_brand(const string& str) override { Transport::set_brand(str); }
		void set_model(const string& str) override { Transport::set_model(str); }
		void set_year(const int str) override { Transport::set_year(str); }
		void set_weight(const double str) override { Transport::set_weight(str); }

		//информация
		void info() const override {
			cout << left
				<< setw(2) << get_id() << "| "
				<< setw(10) << get_type() << "| "
				<< setw(9) << get_brand() << "| "
				<< setw(8) << get_model() << "| "
				<< setw(6) << get_year() << "| "
				<< setw(9) << get_weight() << endl;
		}

};
class Boat : public Transport {
	private:


	public:
		//конструктор
		Boat(string str_b, string str_m, int i_y, double d_w) : Transport("Boat"s, str_b, str_m, i_y, d_w) {}
		//конструктор и оператор копирования
		Boat(const Boat& other) : Transport(other) {}
		Boat& operator=(const Boat& other) {
			if (&other == this) {
				return *this;
			}
			Transport::operator=(other);
			return *this;
		}
		//конструктор и оператор перемещения
		Boat(Boat&& other) noexcept : Transport(move(other)) {}
		Boat& operator=(Boat&& other) noexcept {
			if (&other == this) {
				return *this;
			}
			Transport::operator=(move(other));

			return *this;
		}
		//деструктор
		~Boat() noexcept {}
		
		//get 
		int get_id() const override { return Transport::get_id(); }
		string get_type() const override { return Transport::get_type(); }
		string get_brand() const override { return Transport::get_brand(); }
		string get_model() const override { return Transport::get_model(); }
		int get_year() const override { return Transport::get_year(); }
		double get_weight() const override { return Transport::get_weight(); }

		//set 
		void set_type(const string& str) override { Transport::set_type(str); }
		void set_brand(const string& str) override { Transport::set_brand(str); }
		void set_model(const string& str) override { Transport::set_model(str); }
		void set_year(const int str) override { Transport::set_year(str); }
		void set_weight(const double str) override { Transport::set_weight(str); }

		//информация
		void info() const override {
			cout << left
				<< setw(2) << get_id() << "| "
				<< setw(10) << get_type() << "| "
				<< setw(9) << get_brand() << "| "
				<< setw(8) << get_model() << "| "
				<< setw(6) << get_year() << "| "
				<< setw(9) << get_weight() << endl;
		}

};
class Spaceship : public Transport {
	private:


	public:
		//конструктор
		Spaceship(string str_b, string str_m, int i_y, double d_w) : Transport("Spaceship"s, str_b, str_m, i_y, d_w) {}
		//конструктор и оператор копирования
		Spaceship(const Spaceship& other) : Transport(other) {}
		Spaceship& operator=(const Spaceship& other) {
			if (&other == this) {
				return *this;
			}
			Transport::operator=(other);
			return *this;
		}
		//конструктор и оператор перемещения
		Spaceship(Spaceship&& other) noexcept : Transport(move(other)) {}
		Spaceship& operator=(Spaceship&& other) noexcept {
			if (&other == this) {
				return *this;
			}
			Transport::operator=(move(other));

			return *this;
		}
		//деструктор
		~Spaceship() noexcept {}
	
		//get 
		int get_id() const override { return Transport::get_id(); }
		string get_type() const override { return Transport::get_type(); }
		string get_brand() const override { return Transport::get_brand(); }
		string get_model() const override { return Transport::get_model(); }
		int get_year() const override { return Transport::get_year(); }
		double get_weight() const override { return Transport::get_weight(); }

		//set 
		void set_type(const string& str) override { Transport::set_type(str); }
		void set_brand(const string& str) override { Transport::set_brand(str); }
		void set_model(const string& str) override { Transport::set_model(str); }
		void set_year(const int str) override { Transport::set_year(str); }
		void set_weight(const double str) override { Transport::set_weight(str); }

		//информация
		void info() const override {
			cout << left
				<< setw(2) << get_id() << "| "
				<< setw(10) << get_type() << "| "
				<< setw(9) << get_brand() << "| "
				<< setw(8) << get_model() << "| "
				<< setw(6) << get_year() << "| "
				<< setw(9) << get_weight() << endl;
		}

};

//фабричный метод
//базовый класс
class Creator {
public:
	virtual unique_ptr<Transport> create(string str_b, string str_m, int i_y, double d_w) const = 0;
};
//остальные
class CreateCar : public Creator {
	public:
		unique_ptr<Transport> create(string str_b, string str_m, int i_y, double d_w) const override {
			return make_unique<Car>(str_b, str_m, i_y, d_w);
		}
};
class CreateHelicopter : public Creator {
	public:
		unique_ptr<Transport> create(string str_b, string str_m, int i_y, double d_w) const override {
			return make_unique<Helicopter>(str_b, str_m, i_y, d_w);
		}
};
class CreateBoat : public Creator {
	public:
		unique_ptr<Transport> create(string str_b, string str_m, int i_y, double d_w) const override {
			return make_unique<Boat>(str_b, str_m, i_y, d_w);
		}
};
class CreateSpaceship : public Creator {
	public:
		unique_ptr<Transport> create(string str_b, string str_m, int i_y, double d_w) const override {
			return make_unique<Spaceship>(str_b, str_m, i_y, d_w);
		}
};

class WorkWithfile {
	private:
		string name;
		fstream file;
	public:
		//конструктор
		WorkWithfile(string str) : name{str} {
		try {
			file.open(str, ios_base::in | ios_base::out | ios_base::app);
			if (!file.is_open()) {
				throw runtime_error("Не удалось открыть файл");
			}
		} catch (const exception& e) {
			cerr << "Ошибка: " << e.what() << endl;
		}
		catch (...) {
			cerr << "Неизвестная ошибка" << endl;
		}
	}
		//деструктор
		~WorkWithfile() noexcept {
		if (file.is_open())
			file.close();
	}
		//запись
		void in(const string& str) {
			if (file.is_open())
				file << str << endl;
		}
		//чтение
		vector<string> out() {

			vector<string> v;
			string line;
			if (file.is_open()) {
				while (getline(file, line)) {
					v.push_back(line);
				}
			}
			return v;
		}
};

class Table {
	private:
		vector<unique_ptr<Transport>> vec;

	public:
		//конструктор
		Table() {}
		//деструктор
		~Table() noexcept {}

		//методы
		//отрисовка
		void printTable() const {
			try {
				if (vec.empty())
					throw logic_error("Список пуст");
				cout << "\n";
				std::cout << std::left
					<< std::setw(2) << "ID" << "| "
					<< std::setw(13) << "Тип" << "| "
					<< std::setw(14) << "Марка" << "| "
					<< std::setw(14) << "Модель" << "| "
					<< std::setw(9) << "Год" << "| "
					<< std::setw(7) << "Вес (кг)" << '\n';

				//разделитель
				std::cout << std::string(2, '-') << "+"
					<< std::string(11, '-') << "+"
					<< std::string(10, '-') << "+"
					<< std::string(9, '-') << "+"
					<< std::string(7, '-') << "+"
					<< std::string(10, '-') << "\n";

				for (const auto& x : vec) {
					x->info();
				}
				cout << endl;
			}
			catch (const exception& e) {
				cerr << "Ошибка: " << e.what() << endl;
			}
			catch (...) {
				cerr << "Неизвестная ошибка" << endl;
			}
		}

		//создание
		void create_tr(const string& _type, const string& _brand, const string& _model, int _year, double _weight) {
			try {
				unique_ptr<Creator> creator = nullptr;
				
				if (_type == "Car" || _type == "car") {
					creator = make_unique<CreateCar>();
				}
				else if (_type == "Helicopter" || _type == "helicopter") {
					creator = make_unique<CreateHelicopter>();
				}  
				else if (_type == "Boat" || _type == "boat") {
					creator = make_unique<CreateBoat>();
				}
				else if (_type == "Spaceship" || _type == "spaceship") {
					creator = make_unique<CreateSpaceship>();
				}
				if (creator) {
					unique_ptr<Transport> res = move(creator->create(_brand, _model, _year, _weight));
					vec.push_back(move(res));
				}
			} 
			catch (...) {
				cerr << "Неизвестная ошибка" << endl;
			}
		}

		//удаление
		void delete_tr(int id) {
			try {

				if (vec.empty())
					throw logic_error("Список пуст");

				bool flag = false;

				for (auto it = vec.begin(); it != vec.end(); it++) {
					if (id == (*it)->get_id()) {
						vec.erase(it);
						flag = 1; //указываем, что нашли элемент
						cout << "Элемент удален" << endl;
						break;
					}
				}
				
				if (!flag)
					throw logic_error("Элемент не найден");
			
			} 
			catch (const exception& e) {
				cerr << "Ошибка: " << e.what() << endl;
			} 
			catch (...) {
				cerr << "Неизвестная ошибка" << endl;
			}
		}

		//редактирование
		void edit_tr(int id) {
			try {

				if (vec.empty())
					throw logic_error("Список пуст");
				
				bool flag = false;
			
				for (auto it = vec.begin(); it != vec.end(); ++it) {
					if (id == (*it)->get_id()) {

						int for_edit = -1;
						
						while (for_edit != 0) {

							cout << "Выберите: \n";
							cout << "1: Марка\n";
							cout << "2: Модель\n";
							cout << "3: Год\n";
							cout << "4: Вес\n";
							cout << "0: Выход" << endl;

							while (for_edit < 0 || for_edit > 4)
								cin >> for_edit;

							switch (for_edit) {
								case 1: {
									cout << "Введите новую марку: \n";
									string set;
									cin >> set;

									(*it)->set_brand(set);

									for_edit = -1;
									break;
								}
								case 2: {
									cout << "Введите новую модель: \n";
									string set;
									cin >> set;

									(*it)->set_model(set);
									
									for_edit = -1;
									break;
								}
								case 3: {
									cout << "Введите новый год: \n";
								int set;
									cin >> set;

									(*it)->set_year(set);
									
									for_edit = -1;
									break;
								}
								case 4: {
									cout << "Введите новый вес(кг): \n";
									double set;
									cin >> set;

									(*it)->set_weight(set);
									
									for_edit = -1;
									break;
								}
								case 0: {
									break;
								}
							}
						}

						flag = 1; //указываем, что нашли элемент
						break;
					}
				}
				if (!flag)
					throw logic_error("Элемент не найден");
			}
			catch (const exception& e) {
				cerr << "Ошибка: " << e.what() << endl;
			}
			catch (...) {
				cerr << "Неизвестная ошибка" << endl;
			}
		}

		//сортировка
		void sort_tr(int for_sort) {
			try {
				switch (for_sort) {
					case 1: {
						sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) {return a->get_id() < b->get_id(); });
						break;
					} 
					case 2: {
						sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) {return a->get_type() < b->get_type(); });
						break;
					}
					case 3: {
						sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) {return a->get_brand() < b->get_brand(); });
						break;
					}
					case 4: {
						sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) {return a->get_model() < b->get_model(); });
						break;
					}
					case 5: {
						sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) {return a->get_year() < b->get_year(); });
						break;
					}
					case 6: {
						sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) {return a->get_weight() < b->get_weight(); });
						break;
					}
					case 0: {
						break;
					}
				}
				if (for_sort != 0) {
					printTable();
					sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) {return a->get_id() < b->get_id(); });
				}
			}
			catch (const exception& e) {
				cerr << "Ошибка: " << e.what() << endl;
			}
			catch (...) {
				cerr << "Неизвестная ошибка" << endl;
			}
			
		}

		//поиск
		void find_tr(int for_find)  const{
			try {
				
				if (vec.empty())
					throw logic_error("Список пуст");

				string str;
				auto it = vec.end();

				switch (for_find) {
					case 1: {
						cout << "Введите Id: " << endl;
						int number;
						cin >> number;
						it = find_if(vec.begin(), vec.end(), [&number](const auto& a) { return a->get_id() == number; });
						break;
					}
					case 2: {
						cout << "Введите тип: " << endl;
						cin >> str;
						it = find_if(vec.begin(), vec.end(), [&str](const auto& a) { return a->get_type() == str; });
						break;
					}
					case 3: {
						cout << "Введите марку: " << endl;
						cin >> str;
						it = find_if(vec.begin(), vec.end(), [&str](const auto& a) { return a->get_brand() == str; });
						break;
					}
					case 4: {
						cout << "Введите модель: " << endl;
						cin >> str;
						it = find_if(vec.begin(), vec.end(), [&str](const auto& a) { return a->get_model() == str; });
						break;
					}
					case 5: {
						cout << "Введите год: " << endl;
						int number;
						cin >> number;
						it = find_if(vec.begin(), vec.end(), [&number](const auto& a) { return a->get_year() == number; });
						break;
					}
					case 6: {
						cout << "Введите вес(кг): " << endl;
						double number;
						cin >> number;
						it = find_if(vec.begin(), vec.end(), [&number](const auto& a) { return a->get_weight() == number; });
						break;
					}
					case 0: {
						break;
					}
				}
				if (it != vec.end()) {
					(*it)->info();
				}


			} catch (const exception& e) {
				cerr << "Ошибка: " << e.what() << endl;
			}
			catch (...) {
				cerr << "Неизвестная ошибка" << endl;
			}
		}

		//сохранить в файл
		void input_file(const string& name) const {
			try {
				
				WorkWithfile w(name);
				
				string result;
				for (auto it = vec.begin(); it != vec.end(); ++it) {

					result = (*it)->get_type();
					result += " ";
					result += (*it)->get_brand();
					result += " ";
					result += (*it)->get_model();
					result += " ";
					result += to_string((*it)->get_year());
					result += " ";
					result += to_string((*it)->get_weight());

					w.in(result);
				}

			} 
			catch (const exception& e) {
				cerr << "Ошибка: " << e.what() << endl;
			} 
			catch (...) {
				cerr << "Неизвестная ошибка" << endl;
			}
		}

		//загрузить из файла
		void output_file(const string& name) {
			try {
				string _type, _brand, _model; 
				int _year, _weight;
				WorkWithfile w(name);
				vector<string> v;
				v = w.out();
				
				if (v.empty())
					throw runtime_error("Файл пустой");
				
				for (const string& line : v) {
					istringstream in(line);
					in >> _type >> _brand >> _model >> _year >> _weight;
					create_tr(_type, _brand, _model, _year, _weight);
				}
			} 
			catch (const exception& e) {
				cerr << "Ошибка: " << e.what() << endl;
			} 
			catch (...) {
				cerr << "Неизвестная ошибка" << endl;
			}
		}
};


int main() {
	setlocale(LC_ALL, "rus");
	int menu = -1;
	Table tb;
	while (menu) {
		
		//меню
		cout << "1: Создание\n";
		cout << "2: Редактирование\n";
		cout << "3: Удаление\n";
		cout << "4: Отображение с сортировкой по полю\n";
		cout << "5: Поиск по полю\n";
		cout << "6: Сохранение в файл\n";
		cout << "7: Запись из файла\n";
		cout << "8: Показать таблицу\n";
		cout << "0: Выход" << endl;

		while (menu < 0 || menu > 8)
			cin >> menu;
		
		switch (menu) {
			case 1: {
				//создание

				cout << "Выбери тип транспорта для создания \n";
				cout << "Car\n";
				cout << "Helicopter\n";
				cout << "Boat\n";
				cout << "Spaceship\n";
				cout << "Выйти - Null" << endl;
				
				string _type;
				cin >> _type;

				if (_type == "Null" || _type == "null") {
					menu = -1;
					break;
				}

				if (_type == "Car" || _type == "car" ||
					_type == "Helicopter" || _type == "helicopter" ||
					_type == "Boat" || _type == "boat" ||
					_type == "Spaceshit" || _type == "spaceship")
				{

					string _brand;
					string _model;
					int _year;
					double _weight;

					cout << "Введи марку: \n";
					cin >> _brand;
					cout << "Введи модель: \n";
					cin >> _model;
					cout << "Введи год: \n";
					cin >> _year;
					cout << "Введи вес(кг): \n";
					cin >> _weight;

					tb.create_tr(_type, _brand, _model, _year, _weight);
				}
				menu = -1;
				break;
			} 
			case 2: {
				//редактирование

				int id;
				cout << "Введите id объекта" << endl;
				cin >> id;

				tb.edit_tr(id);
				menu = -1;
				break;
			} 
			case 3: { 
				//удаление

				int id;
				cout << "Введите id объекта" << endl;
				cin >> id;

				tb.delete_tr(id);
				menu = -1;
				break;
			}
			case 4: {
				//сортировка

				cout << "Выберите поле для сортировки: \n";
				cout << "1: Id\n";
				cout << "2: Тип\n";
				cout << "3: Марка\n";
				cout << "4: Модель\n";
				cout << "5: Год\n";
				cout << "6: Вес\n";
				cout << "0: Выход" << endl;

				int for_sort = -1;
				while (for_sort < 0 || for_sort > 6)
					cin >> for_sort;

				tb.sort_tr(for_sort);
				menu = -1;
				break;
			} 
			case 5: {
				//поиск

				cout << "Выберите поле для поиска: \n";
				cout << "1: Id\n";
				cout << "2: Тип\n";
				cout << "3: Марка\n";
				cout << "4: Модель\n";
				cout << "5: Год\n";
				cout << "6: Вес\n";
				cout << "0: Выход" << endl;

				int for_find = -1;
				while (for_find < 0 || for_find > 6)
					cin >> for_find;

				tb.find_tr(for_find);
				menu = -1;
				break;
			} 
			case 6: {
				//сохранение в файл

				cout << "Введите имя файла для сохранения: " << endl;
				string name;
				cin >> name;


				tb.input_file(name);
				menu = -1;
				break;
			} 
			case 7: {
				//запись из файла

				cout << "Введите имя файла для чтения: " << endl;
				string name;
				cin >> name;

				tb.output_file(name);
				menu = -1;
				break;
			} 
			case 8: {
				//отрисовка

				tb.printTable();
				menu = -1;
				break;
			
			} 
			case 0: {
				menu = 0;
				break;
			}
		}
	}

	return 0;
}