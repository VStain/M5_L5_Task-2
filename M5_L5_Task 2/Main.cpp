//Задача 2. «Путешествие» по пирамиде
/*
Задача 2. «Путешествие» по пирамиде
Вам нужно организовать «путешествие» пользователя по пирамиде.

Дан массив, в котором хранится пирамида. Ваша задача — дать пользователю возможность «путешествовать» по ней.

В начале программы пользователь начинает свой путь в корне пирамиды. Программа спрашивает пользователя, куда он хочет пойти. Пользователь должен ответить на этот вопрос, используя одну из команд:

up — перейти к родителю;
left — перейти к левому потомку;
right — перейти к правому потомку;
exit — завершить работу программы.
Перед каждым вводом команды программа выводит сообщение Вы находитесь здесь:  и элемент, на котором сейчас находится пользователь. Элемент выводится аналогично тому, как выводились элементы в прошлом задании.

После каждого ввода команды программа выводит результат её выполнения. Если команда была выполнена успешно, выведите на консоль Ок. Если выполнить команду не удалось, например, вы ввели команду up, находясь в корне пирамиды, выведите на консоль сообщение об ошибке и причину её возникновения: например, Ошибка! Отсутствует родитель.

Программа предлагает пользователю вводить команды до тех пор, пока пользователь не введёт команду exit. Если пользователь ввёл команду, которой нет в списке, сообщите ему об этом.

Пример работы программы
Исходный массив: 1 3 6 5 9 8
Пирамида:
0 root 1
1 left(1) 3
1 right(1) 6
2 left(3) 5
2 right(3) 9
2 left(6) 8
Вы находитесь здесь: 0 root 1
Введите команду: right
Ок
Вы находитесь здесь: 1 right(1) 6
Введите команду: right
Ошибка! Отсутствует правый потомок
Вы находитесь здесь: 1 right(1) 6
Введите команду: left
Ок
Вы находитесь здесь: 2 left(6) 8
Введите команду: right
Ошибка! Отсутствует правый потомок
Вы находитесь здесь: 2 left(6) 8
Введите команду: left
Ошибка! Отсутствует левый потомок
Вы находитесь здесь: 2 left(6) 8
Введите команду: up
Ок
Вы находитесь здесь: 1 right(1) 6
Введите команду: up
Ок
Вы находитесь здесь: 0 root 1
Введите команду: up
Ошибка! Отсутствует родитель
Вы находитесь здесь: 0 root 1
Введите команду: exit
*/



// Код от первой задачи
/*#include <iostream>

// Функция для вычисления индекса родителя по индексу потомка
int pyramid_parent_index(int child_index) {
    // Возвращает индекс родителя, используя формулу (child_index - 1) / 2
    return (child_index - 1) / 2;
}

// Функция для определения, является ли элемент левым потомком
bool pyramid_is_left(int index) {
    // Возвращает true, если элемент является левым потомком (index % 2 == 1),
    // и false, если правым (index % 2 == 0)
    return (index % 2 == 1);
}

// Функция для определения уровня элемента
int pyramid_level(int index) {
    // Возвращает уровень элемента, используя формулу log2(index + 1)
    return static_cast<int>(log2(index + 1));
}

// Функция для вывода пирамиды
void print_pyramid(int* arr, int size) {

    std::cout << "Пирамида:" << std::endl;

    // Выводит корневой элемент
    // - Уровень 0
    // - Позиция "root"
    // - Значение элемента
    std::cout << 0 << " root(" << arr[0] << ") " << arr[0] << std::endl;

    // Перебираем все элементы массива, начиная со второго
    for (int i = 1; i < size; ++i) {
        // Вычисляем индекс, уровень и позицию текущего элемента
        int parent_index = pyramid_parent_index(i);
        int level = pyramid_level(i);
        std::string position_str = pyramid_is_left(i) ? "left" : "right";

        // Выводим информацию о текущем элементе:
        // - Уровень
        // - Позиция (левый/правый)
        // - Значение родителя
        // - Значение элемента
        std::cout << level << " " << position_str << "(" << arr[parent_index] << ") " << arr[i] << std::endl;
    }
}

int main() {
    setlocale(LC_ALL, "ru");


    int* arr = new int[6] {1, 3, 6, 5, 9, 8};
    int arr_size = 6;

    // Выводим исходный массив
    std::cout << "Исходный массив: ";
    for (int i = 0; i < arr_size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    print_pyramid(arr, arr_size);

    delete[] arr;

    return 0;
}*/



#include <iostream>
#include <string>

// Функция для вычисления индекса родителя по индексу потомка
int pyramid_parent_index(int child_index) {
    // Возвращает индекс родителя, используя формулу (child_index - 1) / 2
    return (child_index - 1) / 2;
}

// Функция для определения, является ли элемент левым потомком
bool pyramid_is_left(int index) {
    // Возвращает true, если элемент является левым потомком (index % 2 == 1),
    // и false, если правым (index % 2 == 0)
    return (index % 2 == 1);
}

// Функция для определения уровня элемента
int pyramid_level(int index) {
    // Возвращает уровень элемента, используя формулу log2(index + 1)
    return static_cast<int>(log2(index + 1));
}

// Функция для вывода пирамиды
void print_pyramid(int* arr, int size) {
    std::cout << "Пирамида:" << std::endl;

    // Выводит корневой элемент
    // - Уровень 0
    // - Позиция "root"
    // - Значение элемента
    std::cout << 0 << " root(" << arr[0] << ") " << arr[0] << std::endl;

    // Перебираем все элементы массива, начиная со второго
    for (int i = 1; i < size; ++i) {
        // Вычисляем индекс, уровень и позицию текущего элемента
        int parent_index = pyramid_parent_index(i);
        int level = pyramid_level(i);
        std::string position_str = pyramid_is_left(i) ? "left" : "right";

        // Выводим информацию о текущем элементе:
        // - Уровень
        // - Позиция (левый/правый)
        // - Значение родителя
        // - Значение элемента
        std::cout << level << " " << position_str << "(" << arr[parent_index] << ") " << arr[i] << std::endl;
    }
}

// Функция для вывода информации о потомке и его родителе
void print_index(int* arr, int arr_size, int index) {
    if (index == 0) {
        std::cout << 0 << " root " << arr[0] << std::endl;
        return;
    }
    int parent_index = pyramid_parent_index(index);
    std::cout << pyramid_level(index)
        << (pyramid_is_left(index) ? " left" : " right")
        << "(" << arr[parent_index] << ") "
        << arr[index] << std::endl;
}

// Функция для перемещения пользователя по пирамиде
void travel_pyramid(int* arr, int size) {
    int current_index = 0; // Индекс текущего элемента (корень пирамиды)
    std::string command; // Переменная для хранения введенной команды

    std::cout << "Вы находитесь здесь: " << 0 << " root " << arr[0] << std::endl;

    // Цикл для ввода команды и перемещения пользователя по пирамиде
    while (true) {
        std::cout << "Введите команду: ";
        std::cin >> command;

        if (command == "exit") {
            std::cout << "Программа завершена." << std::endl;
            break;
        }
        else if (command == "up") {
            if (current_index == 0) {
                std::cout << "Ошибка! Отсутствует родитель." << std::endl;
            }
            else {
                current_index = pyramid_parent_index(current_index);
                std::cout << "Ок" << std::endl;
                print_index(arr, size, current_index);
            }
        }
        else if (command == "left") {
            int left_child_index = 2 * current_index + 1;
            if (left_child_index >= size) {
                std::cout << "Ошибка! Отсутствует левый потомок." << std::endl;
            }
            else {
                current_index = left_child_index;
                std::cout << "Ок" << std::endl;
                print_index(arr, size, current_index);
            }
        }
        else if (command == "right") {
            int right_child_index = 2 * current_index + 2;
            if (right_child_index >= size) {
                std::cout << "Ошибка! Отсутствует правый потомок." << std::endl;
            }
            else {
                current_index = right_child_index;
                std::cout << "Ок" << std::endl;
                print_index(arr, size, current_index);
            }
        }
        else {
            std::cout << "Ошибка! Неверная команда." << std::endl;
        }
    }
}

int main() {
    setlocale(LC_ALL, "ru");

    int* arr = new int[6] {1, 3, 6, 5, 9, 8};
    int arr_size = 6;

    std::cout << "Исходный массив: ";
    for (int i = 0; i < arr_size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    print_pyramid(arr, arr_size);

    travel_pyramid(arr, arr_size);

    delete[] arr;

    return 0;
}

