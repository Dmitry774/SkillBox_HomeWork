#include <iostream> // подключение библиотек

#include <string>

class Car // определение класса Car
{
	public: std::string mark; // Торговая марка
	int cilinder_count; // Число цилиндров
	int power; // Мощность
	static int object_count; // объявление статической переменной для хранения количества созданных объектов
  
	Car() // Конструктор по умолчанию
	{
		mark = "Lada_Granta";
		cilinder_count = 4;
		power = 98;
		object_count++;
	}

	// Конструктор с параметрами.
	Car(std::string _mark, int _cilinder_count, int _power) {
		if(_cilinder_count > 0 && _power > 0) {
			cilinder_count = _cilinder_count;
			power = _power;
			mark = _mark;
			object_count++;
		}
	}

	// Конструктор копирования
	Car(const Car & car) {
		mark = car.mark;
		cilinder_count = car.cilinder_count;
		power = car.power;
		object_count++;
	}

	~Car() // Деструктор
	{
		std::cout << "Car " << mark << " deleted" << std::endl; // показываем, что деструктор сработал
		object_count--;
		std::cout << " Total objects " << object_count << std::endl; // выводим оставшееся число объектов
	}

	friend int count(Car & car); // объявляем дружественную функцию count

	int getPower() const { // геттер для Power
		return power;
	}

	std::string getMark() const { // геттер для Mark
		return mark;
	}

	int get_Cilinder_Count() const { // геттер для cilinder_count
		return cilinder_count;
	}

	void setPower(int _power) { // сеттер для power
		power = _power;
	}

	void setMark(std::string _mark) { // сеттер для mark
		mark = _mark;
	}

	void set_Cilinder_Count(int _cilinder_count) { // сеттер для cilinder_count
		cilinder_count = _cilinder_count;
	}
};

// Перегрузка оператора вывода для класса Car
std::ostream & operator << (std::ostream & os,
	const Car & car) {
	return os << "Car mark: " << car.getMark() << " , power: " << car.getPower() << " , cilinder count: " << car.get_Cilinder_Count();
}

// Перегрузка оператора ввода для класса Car
std::istream & operator >> (std::istream & in, Car & car) {
	std::string mark;
	int power;
	int cilinder_count;
	std::cout << "Enter mark: ";
	in >> mark;
	std::cout << "Enter power: ";
	in >> power;
	std::cout << "Enter cilinder_count: ";
	in >> cilinder_count;
	car.setPower(power);
	car.set_Cilinder_Count(cilinder_count);
	car.setMark(mark);
	return in;
}


class Lorry: public Car // // определение класса Lorry
{
	public: int max_load;
	Lorry(): Car() // Конструктор по умолчанию 
	{
		max_load = 1000;
		object_count++;
	}
	// Конструктор с параметрами.
	Lorry(std::string _mark, int _cilinder_count, int _power, int _max_load): Car(_mark, _cilinder_count, _power),
	max_load(_max_load) {
		object_count++;
	}
	// Конструктор копирования
	Lorry(const Lorry & lorry) {
		mark = lorry.mark;
		cilinder_count = lorry.cilinder_count;
		power = lorry.power;
		max_load = lorry.max_load;
		object_count++;
	}
	~Lorry() // Деструктор для класса Lorry
	{
		std::cout << "Lorry " << mark << " deleted" << std::endl;
		object_count--;
		std::cout << " Total objects " << object_count << std::endl;
	}
	int getMaxLoad() // геттер для max_load
	{
		return max_load;
	}
	void setMaxLoad(int _maxload) // сеттер для max_load
	{
		max_load = _maxload;
	}
};

int Car::object_count = 0; // Инициализация статического поля count нулем

int count(Car & car) {
	return car.object_count; // Возвращает значение статического поля count
}

// Перегрузка оператора ввода
std::istream & operator >> (std::istream & is, Lorry & lorry) {
	is >> static_cast < Car & > (lorry);
	std::cout << "Enter max load: ";
	is >> lorry.max_load;
	return is;
}

// Перегрузка оператора вывода
std::ostream & operator << (std::ostream & os, const Lorry & lorry) {
	os << static_cast <
		const Car & > (lorry);
	os << " Max Load: " << lorry.max_load;
	return os;
}

int main() {
	std::cout << "First Car" << std::endl;
	Car First_Car; // Создание объекта класса Car, использование конструктора по умолчанию
	std::cin >> First_Car; // вызов перегруженного оператора ввода
	std::cout << First_Car << std::endl; // вызов перегруженного оператора вывода
	std::cout << "Total number of created objects: " << count(First_Car) << std::endl;
	std::cout << "Second Car" << std::endl;

	Car Second_Car("BMW", 4, 120);
	std::cout << Second_Car << std::endl; // вызов перегруженного оператора вывода
	std::cin >> Second_Car; // вызов перегруженного оператора ввода
	std::cout << Second_Car << std::endl; // вызов перегруженного оператора вывода
	std::cout << "Total number of created objects: " << count(Second_Car) << std::endl;
	std::cout << "Third Car" << std::endl;

	Car Third_Car(Second_Car); // используем конструктор копирования
	std::cout << Third_Car << std::endl; // вызов перегруженного оператора вывода
	std::cout << "Total number of created objects: " << count(Third_Car) << std::endl;
	std::cout << "First Lorry" << std::endl;

	Lorry First_Lorry; // Создание объекта класса Lorry
	std::cout << First_Lorry << std::endl; // вызов перегруженного оператора ввода
	std::cout << "Total number of created objects: " << count(First_Lorry) << std::endl;
	std::cout << "Second Lorry" << std::endl;

	Lorry Second_Lorry("KIA", 4, 120, 100); // Создание объекта класса Lorry
	std::cout << Second_Lorry << std::endl; // вызов перегруженного оператора ввода
	std::cin >> Second_Lorry; // вызов перегруженного оператора ввода
	std::cout << Second_Lorry << std::endl; // вызов перегруженного оператора ввода
	std::cout << "Total number of created objects: " << count(Second_Lorry) << std::endl;
	return 0;
}