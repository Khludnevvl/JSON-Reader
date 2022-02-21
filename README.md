## JSON-Reader-Builder

---

Библеотека для чтение/создание json-файлов. Использует std::variant для хранения значений. Конструктор JSON использует цепочки вызовов методов. Большинство ошибок при построении цепочек находятся на этапе компиляции.

---

### Использование 

Пример использования указан в файле main.cpp.
Для конструктора используется класс json::Builder. Для хранение данных используется обертка над std::variant - json::Node.
Доступные значение Node: std::vector, std::map< std::string,Node >, std::string, bool, int, double.
Для считывания и записи финального JSON используется простая обертка над Node - json::Document

#### Функции конструктора JSON

* Value // Установить значение Node
* Key // Установить ключ словаря
* StartDict // Начать словарь
* StartArray // Начать массив
* EndDict // Закрыть словарь
* EndArray // Закрыть массив
* Build // Построение заданного JSON, возвращает финальный документ
* Print // Сохранить финальный документ в поток вывода

#### Функции считывания JSON 

* Is* //  Проверка на тип, хранящемся в Node. Например IsArray();
* As* //  Взять Node как определенный тип
* Load // Загрузить документ из входного потока

### Системные требования
---
С++17