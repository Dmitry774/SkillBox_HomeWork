#include <iostream> // подключение библиотек
#include <string>

class Car // определение класса Car
{
  public:

  std::string mark; // Торговая марка
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
    if (_cilinder_count > 0 && _power > 0) {
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

  int getPower() { // геттер для Power
    return power;
  } 

  std::string getMark() { // геттер для Mark
    return mark;
  } 

  int get_Cilinder_Count() { // геттер для cilinder_count
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

class Lorry: public Car // // определение класса Lorry
{ 
  public:

    int max_load;

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

int main() {
  std::cout << "First Car" << std::endl;
  Car First_Car; // Создание объекта класса Car
  std::cout << First_Car.getMark() << std::endl;
  std::cout << First_Car.get_Cilinder_Count() << std::endl;
  std::cout << First_Car.getPower() << std::endl;
  std::cout << "Total number of created objects: " << count(First_Car) << std::endl;

  std::cout << "Second Car" << std::endl;
  Car Second_Car("BMW", 4, 120);
  std::cout << Second_Car.getMark() << std::endl;
  std::cout << Second_Car.get_Cilinder_Count() << std::endl;
  std::cout << Second_Car.getPower() << std::endl;
  std::cout << "Total number of created objects: " << count(Second_Car) << std::endl;

  std::cout << "Third Car" << std::endl;
  Car Third_Car;
  Third_Car.setPower(110);
  Third_Car.setMark("Nissan");
  Third_Car.set_Cilinder_Count(6);
  std::cout << Third_Car.getMark() << std::endl;
  std::cout << Third_Car.get_Cilinder_Count() << std::endl;
  std::cout << Third_Car.getPower() << std::endl;
  std::cout << "Total number of created objects: " << count(Third_Car) << std::endl;

  std::cout << "Fourth Car" << std::endl;
  Car Fourth_Car(Third_Car);
  std::cout << Fourth_Car.getMark() << std::endl;
  std::cout << Fourth_Car.get_Cilinder_Count() << std::endl;
  std::cout << Fourth_Car.getPower() << std::endl;
  std::cout << "Total number of created objects: " << count(Fourth_Car) << std::endl;

  std::cout << "First Lorry" << std::endl;
  Lorry First_Lorry; // Создание объекта класса Car
  std::cout << First_Lorry.getMark() << std::endl;
  std::cout << First_Lorry.get_Cilinder_Count() << std::endl;
  std::cout << First_Lorry.getPower() << std::endl;
  std::cout << "Total number of created objects: " << count(First_Lorry) << std::endl;

  std::cout << "Second Lorry" << std::endl;
  Lorry Second_Lorry("KIA", 4, 120, 100);
  std::cout << Second_Lorry.getMark() << std::endl;
  std::cout << Second_Lorry.get_Cilinder_Count() << std::endl;
  std::cout << Second_Lorry.getPower() << std::endl;
  std::cout << "Total number of created objects: " << count(Second_Lorry) << std::endl;

  std::cout << "Third Lorry" << std::endl;
  Lorry Third_Lorry;
  Third_Lorry.setPower(110);
  Third_Lorry.setMark("Mercedes");
  Third_Lorry.set_Cilinder_Count(6);
  Third_Lorry.setMaxLoad(105);
  std::cout << Third_Lorry.getMark() << std::endl;
  std::cout << Third_Lorry.get_Cilinder_Count() << std::endl;
  std::cout << Third_Lorry.getPower() << std::endl;
  std::cout << Third_Lorry.getMaxLoad() << std::endl;
  std::cout << "Total number of created objects: " << count(Third_Lorry) << std::endl;

  std::cout << "Fourth Lorry" << std::endl;
  Lorry Fourth_Lorry(Third_Lorry);
  std::cout << Fourth_Lorry.getMark() << std::endl;
  std::cout << Fourth_Lorry.get_Cilinder_Count() << std::endl;
  std::cout << Fourth_Lorry.getPower() << std::endl;
  std::cout << Fourth_Lorry.getMaxLoad() << std::endl;
  std::cout << "Total number of created objects: " << count(Fourth_Lorry) << std::endl;

  return 0;
}