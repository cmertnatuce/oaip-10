    #include <iostream>
    #include <iomanip>
    #include <fstream>
    #include <string>
    #include <locale>
    #include <windows.h>

    using namespace std;

    const int MAX = 100; // Максимальное количество деталей

    // Структура для хранения информации о детали
    struct Detail {
        string name;
        float cost = 0;
        float size = 0;
        float weight = 0;
    };

    // Функция для ввода данных о детали
    void enter(Detail& detail) {
        cout << "Введите название детали: ";
        cin >> detail.name;
        cout << "Введите стоимость детали: ";
        cin >> detail.cost;
        cout << "Введите размер детали: ";
        cin >> detail.size;
        cout << "Введите вес детали: ";
        cin >> detail.weight;
    }

    // Функция для сортировки массива деталей по стоимости 
    void sort(Detail results[], int numResults) {
        for (int i = 0; i < numResults - 1; ++i) {
            for (int j = 0; j < numResults - i - 1; ++j) {
                if (results[j].cost > results[j + 1].cost) {
                    // Обмен местами
                    Detail temp = results[j];
                    results[j] = results[j + 1];
                    results[j + 1] = temp;
                }
            }
        }
    }

    // Функция для вывода массива деталей в виде таблицы
    void print(Detail results[], int numResults) {
        if (numResults > 0) {
            cout << "----------------------------------------------------------------------------------------------------------\n";
            cout << setw(20) << "Название детали" << setw(20) << "Стоимость" << setw(20) << "Размер" << setw(20) << "Вес" << endl;
            cout << "----------------------------------------------------------------------------------------------------------\n";
            for (int i = 0; i < numResults; ++i) {
                cout << setw(20) << results[i].name << setw(20) << results[i].cost << setw(20) << results[i].size << setw(20) << results[i].weight << endl;
            }
            cout << "----------------------------------------------------------------------------------------------------------\n";
        }
        else {
            cout << "\nНет информации о деталях для вывода.\n";
        }
    }

    // Функция для сохранения информации о деталях в файл
    void save(Detail results[], int numResults) {
        if (numResults > 0) {
            ofstream outFile("details.txt");
            if (outFile.is_open()) {
                for (int i = 0; i < numResults; ++i) {
                    outFile << "Название детали: " << results[i].name << "\nСтоимость детали: " << results[i].cost << "\nРазмер детали: " << results[i].size << "\nВес детали: " << results[i].weight << endl;
                }
                outFile.close();
                cout << "Информация о деталях сохранена в файле 'details.txt'.\n";
            }
            else {
                cout << "Невозможно открыть файл для записи.\n";
            }
        }
        else {
            cout << "Нет информации о деталях для сохранения.\n";
        }
    }

    int main() {
        SetConsoleOutputCP(1251);
        SetConsoleCP(1251);
        setlocale(LC_ALL, "Rus");
        Detail details[MAX]; // Массив структур Detail для хранения данных о деталях
        int numDetails = 0; // Количество реально заполненных деталей
        int choice;

        do {
            cout << "\nМеню выбора:\n";
            cout << "1. Ввести данные о детали\n";
            cout << "2. Отсортировать детали по стоимости\n";
            cout << "3. Вывести информацию о деталях\n";
            cout << "4. Сохранить информацию о деталях в файл\n";
            cout << "5. Выход\n";
            cout << "Выберите действие: ";
            cin >> choice;

            switch (choice) {
            case 1:
                if (numDetails < MAX) {
                    cout << "\nВведите данные о детали " << numDetails + 1 << ":\n";
                    enter(details[numDetails]);
                    numDetails++;
                }
                else {
                    cout << "Массив деталей заполнен.\n";
                }
                break;
            case 2: 
                print(details, numDetails);
                break;
           

            case 3:
                if (numDetails > 0) {
                    sort(details, numDetails);
                    cout << "\nДетали отсортированы по стоимости.\n";
                }
                else {
                    cout << "\nНет информации о деталях для сортировки.\n";
                }
                break;
           
            case 4:
                save(details, numDetails);
                break;
            case 5:
                cout << "Выход.\n";
                break;
            default:
                cout << "Неверный выбор.\n";
                break;
            }
        } while (choice != 5);

        return 0;
    }
