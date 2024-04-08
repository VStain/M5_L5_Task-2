//������ 2. ������������ �� ��������
/*
������ 2. ������������ �� ��������
��� ����� ������������ ������������ ������������ �� ��������.

��� ������, � ������� �������� ��������. ���� ������ � ���� ������������ ����������� ���������������� �� ���.

� ������ ��������� ������������ �������� ���� ���� � ����� ��������. ��������� ���������� ������������, ���� �� ����� �����. ������������ ������ �������� �� ���� ������, ��������� ���� �� ������:

up � ������� � ��������;
left � ������� � ������ �������;
right � ������� � ������� �������;
exit � ��������� ������ ���������.
����� ������ ������ ������� ��������� ������� ��������� �� ���������� �����:  � �������, �� ������� ������ ��������� ������������. ������� ��������� ���������� ����, ��� ���������� �������� � ������� �������.

����� ������� ����� ������� ��������� ������� ��������� � ����������. ���� ������� ���� ��������� �������, �������� �� ������� ��. ���� ��������� ������� �� �������, ��������, �� ����� ������� up, �������� � ����� ��������, �������� �� ������� ��������� �� ������ � ������� � �������������: ��������, ������! ����������� ��������.

��������� ���������� ������������ ������� ������� �� ��� ���, ���� ������������ �� ����� ������� exit. ���� ������������ ��� �������, ������� ��� � ������, �������� ��� �� ����.

������ ������ ���������
�������� ������: 1 3 6 5 9 8
��������:
0 root 1
1 left(1) 3
1 right(1) 6
2 left(3) 5
2 right(3) 9
2 left(6) 8
�� ���������� �����: 0 root 1
������� �������: right
��
�� ���������� �����: 1 right(1) 6
������� �������: right
������! ����������� ������ �������
�� ���������� �����: 1 right(1) 6
������� �������: left
��
�� ���������� �����: 2 left(6) 8
������� �������: right
������! ����������� ������ �������
�� ���������� �����: 2 left(6) 8
������� �������: left
������! ����������� ����� �������
�� ���������� �����: 2 left(6) 8
������� �������: up
��
�� ���������� �����: 1 right(1) 6
������� �������: up
��
�� ���������� �����: 0 root 1
������� �������: up
������! ����������� ��������
�� ���������� �����: 0 root 1
������� �������: exit
*/



// ��� �� ������ ������
/*#include <iostream>

// ������� ��� ���������� ������� �������� �� ������� �������
int pyramid_parent_index(int child_index) {
    // ���������� ������ ��������, ��������� ������� (child_index - 1) / 2
    return (child_index - 1) / 2;
}

// ������� ��� �����������, �������� �� ������� ����� ��������
bool pyramid_is_left(int index) {
    // ���������� true, ���� ������� �������� ����� �������� (index % 2 == 1),
    // � false, ���� ������ (index % 2 == 0)
    return (index % 2 == 1);
}

// ������� ��� ����������� ������ ��������
int pyramid_level(int index) {
    // ���������� ������� ��������, ��������� ������� log2(index + 1)
    return static_cast<int>(log2(index + 1));
}

// ������� ��� ������ ��������
void print_pyramid(int* arr, int size) {

    std::cout << "��������:" << std::endl;

    // ������� �������� �������
    // - ������� 0
    // - ������� "root"
    // - �������� ��������
    std::cout << 0 << " root(" << arr[0] << ") " << arr[0] << std::endl;

    // ���������� ��� �������� �������, ������� �� �������
    for (int i = 1; i < size; ++i) {
        // ��������� ������, ������� � ������� �������� ��������
        int parent_index = pyramid_parent_index(i);
        int level = pyramid_level(i);
        std::string position_str = pyramid_is_left(i) ? "left" : "right";

        // ������� ���������� � ������� ��������:
        // - �������
        // - ������� (�����/������)
        // - �������� ��������
        // - �������� ��������
        std::cout << level << " " << position_str << "(" << arr[parent_index] << ") " << arr[i] << std::endl;
    }
}

int main() {
    setlocale(LC_ALL, "ru");


    int* arr = new int[6] {1, 3, 6, 5, 9, 8};
    int arr_size = 6;

    // ������� �������� ������
    std::cout << "�������� ������: ";
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

// ������� ��� ���������� ������� �������� �� ������� �������
int pyramid_parent_index(int child_index) {
    // ���������� ������ ��������, ��������� ������� (child_index - 1) / 2
    return (child_index - 1) / 2;
}

// ������� ��� �����������, �������� �� ������� ����� ��������
bool pyramid_is_left(int index) {
    // ���������� true, ���� ������� �������� ����� �������� (index % 2 == 1),
    // � false, ���� ������ (index % 2 == 0)
    return (index % 2 == 1);
}

// ������� ��� ����������� ������ ��������
int pyramid_level(int index) {
    // ���������� ������� ��������, ��������� ������� log2(index + 1)
    return static_cast<int>(log2(index + 1));
}

// ������� ��� ������ ��������
void print_pyramid(int* arr, int size) {
    std::cout << "��������:" << std::endl;

    // ������� �������� �������
    // - ������� 0
    // - ������� "root"
    // - �������� ��������
    std::cout << 0 << " root(" << arr[0] << ") " << arr[0] << std::endl;

    // ���������� ��� �������� �������, ������� �� �������
    for (int i = 1; i < size; ++i) {
        // ��������� ������, ������� � ������� �������� ��������
        int parent_index = pyramid_parent_index(i);
        int level = pyramid_level(i);
        std::string position_str = pyramid_is_left(i) ? "left" : "right";

        // ������� ���������� � ������� ��������:
        // - �������
        // - ������� (�����/������)
        // - �������� ��������
        // - �������� ��������
        std::cout << level << " " << position_str << "(" << arr[parent_index] << ") " << arr[i] << std::endl;
    }
}

// ������� ��� ������ ���������� � ������� � ��� ��������
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

// ������� ��� ����������� ������������ �� ��������
void travel_pyramid(int* arr, int size) {
    int current_index = 0; // ������ �������� �������� (������ ��������)
    std::string command; // ���������� ��� �������� ��������� �������

    std::cout << "�� ���������� �����: " << 0 << " root " << arr[0] << std::endl;

    // ���� ��� ����� ������� � ����������� ������������ �� ��������
    while (true) {
        std::cout << "������� �������: ";
        std::cin >> command;

        if (command == "exit") {
            std::cout << "��������� ���������." << std::endl;
            break;
        }
        else if (command == "up") {
            if (current_index == 0) {
                std::cout << "������! ����������� ��������." << std::endl;
            }
            else {
                current_index = pyramid_parent_index(current_index);
                std::cout << "��" << std::endl;
                print_index(arr, size, current_index);
            }
        }
        else if (command == "left") {
            int left_child_index = 2 * current_index + 1;
            if (left_child_index >= size) {
                std::cout << "������! ����������� ����� �������." << std::endl;
            }
            else {
                current_index = left_child_index;
                std::cout << "��" << std::endl;
                print_index(arr, size, current_index);
            }
        }
        else if (command == "right") {
            int right_child_index = 2 * current_index + 2;
            if (right_child_index >= size) {
                std::cout << "������! ����������� ������ �������." << std::endl;
            }
            else {
                current_index = right_child_index;
                std::cout << "��" << std::endl;
                print_index(arr, size, current_index);
            }
        }
        else {
            std::cout << "������! �������� �������." << std::endl;
        }
    }
}

int main() {
    setlocale(LC_ALL, "ru");

    int* arr = new int[6] {1, 3, 6, 5, 9, 8};
    int arr_size = 6;

    std::cout << "�������� ������: ";
    for (int i = 0; i < arr_size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    print_pyramid(arr, arr_size);

    travel_pyramid(arr, arr_size);

    delete[] arr;

    return 0;
}

