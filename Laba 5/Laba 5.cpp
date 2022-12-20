#include <stdio.h>
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <cstdlib>
#include <locale>
#include <algorithm>
#include <stdlib.h>
#include <string>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS
using namespace std; //  Это пространство имен содержит все имена из стандартной библиотеки языка C++, такие как поток вывода cin или класс string.

struct comanda
{
    int Igroki = 0;
    int KolIgr = 0;
    int points = 0;
    string name;
    string city;
    string fam;
};

typedef comanda* cm;

void Sortirovka_points(cm p[], int n)
{
    cm pusto;
    for (int i = 0; i < n - 1; i++)
    {
        for (int l = n - 2; l >= i; l--)
        {
            if (p[l + 1]->points < p[l]->points)
            {
                pusto = p[l];
                p[l] = p[l + 1];
                p[l + 1] = pusto;
            }
        }
    }
}

void Sortirovka_kolIgr(cm p[], int n)
{
    cm pustota;
    for (int i = 0; i < n - 1; i++)
    {
        for (int l = n - 2; l >= i; l--)
        {
            if (p[l + 1]->KolIgr < p[l]->KolIgr)
            {
                pustota = p[l];
                p[l] = p[l + 1];
                p[l + 1] = pustota;
            }
        }
    }
}

void Sortirovka_Igroki(cm p[], int n)
{
    cm pustoti;
    for (int i = 0; i < n - 1; i++)
    {
        for (int l = n - 2; l >= i; l--)
        {
            if (p[l + 1]->Igroki < p[l]-> Igroki)
            {
                pustoti = p[l];
                p[l] = p[l + 1];
                p[l + 1] = pustoti;
            }
        }
    }
}

void resize(int& n, comanda*& arr)
{
    int newSize = n + 1;
    comanda* newArr = new comanda[newSize];
    copy(arr, arr + n, newArr);
    n = newSize;
    arr = newArr;
}
void Search(cm p[], int n)
{
    cout << "Введите имя команды для поиска" << endl;
    string Name;
    cin >> Name;
    bool U = 0;
    for (int i = 0; i < n; i++)
    {
        if (p[i]->name == Name)
        {
            cout << "По вашему запросу найдена команда" << endl;
            cout << "Название команды\n" << p[i]->name << "\nКоличество игроков \n" << p[i]->Igroki << "\nФамилия тренера \n" <<
                p[i]->fam << "\nГород\n" << p[i]->city << "\nКоличество игр \n" << p[i]->KolIgr << "\nКоличество очков \n"
                << p[i]->points << "\n\n " << endl;
            U = 1;
        }
    }
    if (U == 0)
    {
        cout << "Команда не найдена" << endl;
    }
}
int main()
{
    int N = 1;
    int count = 0;
    string zapros;
    string quest;
    system("chcp 1251"); // Нормальный вывод русского языка
    cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
    ofstream fout("F1.txt");
    comanda* F = new comanda[N];
    cm* p = new cm[N];
    while (true)
    {
        cout << "Ввести новую команду в базу - 1" << endl;
        cout << "Найти команду по названию - 2" << endl;
        cout << "Отсортировать команды по выбранному параметру - 3" << endl;
        cout << "Вывести все команды в файл - 4" << endl;
        cout << "Вывести все команды на экран - 5" << endl;
        cout << "Закончить работу программы - 6" << endl;
        cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
        cin >> zapros;
        if (zapros == "1")
        {
            for (int i = count; i < count + 1; i++)
            {
                cout << "Введите имя команды: " << endl;
                cin >> F[i].name;
                cout << "Введите фамилию тренера: " << endl;
                cin >> F[i].fam;
                cout << "Город команды: " << endl;
                cin >> F[i].city;
                cout << "Количество игр: " << endl;
                cin >> F[i].KolIgr;
                cout << "Количество очков: " << endl;
                cin >> F[i].points;
                cout << "Количество игроков: " << endl;
                cin >> F[i].Igroki;
                cout << endl;
                resize(N, F);
                cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
            }
            count++;
        }
        if (zapros == "2")
        {
            p = new cm[N];
            for (int i = 0; i < N; i++)
            {
                p[i] = &F[i];
            }
            Search(p, N);
            cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
        }
        if (zapros == "3")
        {
            cout << "Выберите по какому параметру будет проведена сортировка: " << endl;
            cout << "По Очкам - 1" << endl;
            cout << "По Количеству сыгранных матчей - 2" << endl;
            cout << "По Количеству игроков - 3" << endl;
            cin >> quest;
            if (quest == "1") {
                p = new cm[N];
                for (int i = 0; i < N - 1; i++)
                {
                    p[i] = &F[i];
                }
                Sortirovka_points(p, N - 1);
                fout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
                for (int i = 0; i < N - 1; i++)
                {
                    fout << "Название команды:\n" << p[i]->name << "\nКоличество игроков: \n" << p[i]->Igroki << "\nФамилия тренера:\n" <<
                        p[i]->fam << "\nГород:\n" << p[i]->city << "\nКоличество игр: \n" << p[i]->KolIgr << "\nКоличество очков:\n"
                        << p[i]->points << "\n\n " << endl;
                }
                fout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
            }
            if (quest == "2"){
            p = new cm[N];
            for (int i = 0; i < N - 1; i++)
            {
                p[i] = &F[i];
            }
            Sortirovka_kolIgr(p, N - 1);
            fout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
            for (int i = 0; i < N - 1; i++)
            {
                fout << "Название команды:\n" << p[i]->name << "\nКоличество игроков: \n" << p[i]->Igroki << "\nФамилия тренера:\n" <<
                    p[i]->fam << "\nГород:\n" << p[i]->city << "\nКоличество игр: \n" << p[i]->KolIgr << "\nКоличество очков:\n"
                    << p[i]->points << "\n\n " << endl;
            }
            fout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
            }
            if (quest == "3") {
                p = new cm[N];
                for (int i = 0; i < N - 1; i++)
                {
                    p[i] = &F[i];
                }
                Sortirovka_Igroki(p, N - 1);
                fout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
                for (int i = 0; i < N - 1; i++)
                {
                    fout << "Название команды:\n" << p[i]->name << "\nКоличество игроков: \n" << p[i]->Igroki << "\nФамилия тренера:\n" <<
                        p[i]->fam << "\nГород:\n" << p[i]->city << "\nКоличество игр: \n" << p[i]->KolIgr << "\nКоличество очков:\n"
                        << p[i]->points << "\n\n " << endl;
                }
                fout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
            }


        }
        if (zapros == "4")
        {

            for (int i = 0; i < N - 1; i++)
            {
                fout << "Название команды:\n" << F[i].name << "\nКоличество игроков:\n " << F[i].Igroki << "\nФамилия тренера:\n" <<
                    F[i].fam << " \nГород:\n" << F[i].city << "\nКоличество игр:\n" << F[i].KolIgr << "\nКоличество очков:\n"
                    << F[i].points << "\n\n " << endl;
            }
        }
        if (zapros == "5")
        {
            for (int i = 0; i < N - 1; i++)
            {
                cout << "\nНазвание команды: \n" << F[i].name << "\nКоличество игроков: \n" << F[i].Igroki << "\nФамилия тренера: \n" <<
                    F[i].fam << "\nГород: \n" << F[i].city << "\nКоличество игр: \n" << F[i].KolIgr << "\nКоличество очков: \n"
                    << F[i].points << "\n\n " << endl;
                cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
            }
        }
        if (zapros == "6")
        {
            delete[]F;

            fout.close();
            exit(1);
        }
    }

}