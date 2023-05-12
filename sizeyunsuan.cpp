#include <iostream>
#include <cstdio>
#include<fstream>
#include<string.h>
#include <cstdlib>
#include <time.h>
#include<iomanip>
using namespace std;
struct data
{
    int num[114514];
    float num1[114514];
}datascript[500];

void havebrackets(int NUM, int MaxNUM, int Num, int File, char Operator[], int decimal)       //带括号函数
{
    int sign1 = 0, sign2 = 0;
    int k1, k2, random, i, j, len;
    len = strlen(Operator);
    ofstream outfile;
    outfile.open("E:\\file.txt");
    for (i = 0; i < NUM; i++)
    {
        k1 = -1;                         //k为左括号右括号位置
        k2 = -1;
        while (1)
        {
            if (k1 > k2 || k2 - k1<2 || k2>Num)
            {
                k1 = int(rand() % (Num - 1));
                k2 = int(rand() % (Num - 1));
            }
            else
                break;
        }
        for (j = 0; j < Num; j++)
        {
            random = int(rand() % len);
            if (decimal == 1)
            {
                datascript[i].num[j] = rand() % MaxNUM + 1;        //随机输出不大于最大整数值的整数
                datascript[i].num[j + 1] = rand() % MaxNUM + 1;
            }
            if (decimal == 0)
            {
                datascript[i].num1[j] = rand() % MaxNUM / 1.0200000; //随机输出不大于最大整数值的小数
                datascript[i].num1[j + 1] = rand() % MaxNUM / 1.0200000;
            }
            if (j < Num - 1)
            {
                if (j == k1)                         //若数组下标等于k1，则输出左半括号
                {
                    if (decimal == 1)
                    {
                        cout << "(" << datascript[i].num[j] << " " << Operator[random] << " ";
                        sign1 = 1;
                        if (File == 1)
                            outfile << "(" << datascript[i].num[j] << " " << Operator[random] << " ";
                    }
                    else
                    {
                        cout << "(" << setprecision(1) << std::fixed << datascript[i].num1[j] << " " << Operator[random] << " ";
                        sign1 = 1;
                        if (File == 1)
                            outfile << "(" << setprecision(1) << std::fixed << datascript[i].num1[j] << " " << Operator[random] << " ";
                    }
                }
                else if (j == k2)                        //若数组下标等于k2，则输出右半括号
                {
                    if (decimal == 1)
                    {
                        cout << datascript[i].num[j] << ")" << " " << Operator[random] << " ";
                        sign2 = 1;
                        if (File == 1)
                            outfile << datascript[i].num[j] << ")" << " " << Operator[random] << " ";
                    }
                    else
                    {
                        cout << setprecision(1) << std::fixed << datascript[i].num1[j] << ")" << " " << Operator[random] << " ";
                        sign2 = 1;
                        if (File == 1)
                            outfile << setprecision(1) << std::fixed << datascript[i].num1[j] << ")" << " " << Operator[random] << " ";
                    }
                }
                else
                {
                    if (decimal == 1)
                    {
                        cout << datascript[i].num[j] << " " << Operator[random] << " ";
                        if (File == 1)
                            outfile << datascript[i].num[j] << " " << Operator[random] << " ";
                    }
                    else
                    {
                        cout << setprecision(1) << std::fixed << datascript[i].num1[j] << " " << Operator[random] << " ";
                        if (File == 1)
                            outfile << setprecision(1) << std::fixed << datascript[i].num1[j] << " " << Operator[random] << " ";
                    }
                }
            }
            else
            {
                if (sign1 == 1 && sign2 == 0)
                {
                    if (decimal == 1)
                    {
                        cout << datascript[i].num[j] << ")" << " ";
                        if (File == 1)
                            outfile << datascript[i].num[j] << ")" << " ";
                    }
                    else
                    {
                        cout << setprecision(1) << std::fixed << datascript[i].num1[j] << ')';
                        if (File == 1)
                            outfile << setprecision(1) << std::fixed << datascript[i].num1[j] << ')';
                    }
                }
                else
                {
                    if (decimal == 1)
                    {
                        cout << datascript[i].num[j] << " ";
                        if (File == 1)
                            outfile << datascript[i].num[j] << " ";
                    }
                    else
                    {
                        cout << setprecision(1) << std::fixed << datascript[i].num1[j];
                        if (File == 1)
                            outfile << setprecision(1) << std::fixed << datascript[i].num1[j];
                    }
                }
            }
        }
        cout << "= " << "\n";
        if (File == 1)
            outfile << "= " << "\n";
    }
    outfile.close();
}

void nobrackets(int NUM, int MaxNUM, int Num, int File, char Operator[], int decimal)      //无括号函数
{
    int i, j, len, random;
    len = strlen(Operator);

    ofstream outfile;
    outfile.open("E:\\file.txt");
    for (i = 0; i < NUM; i++)
    {
        for (j = 0; j < Num; j++)
        {
            random = int(rand() % len);
            if (decimal == 1)
            {
                datascript[i].num[j] = rand() % MaxNUM + 1;            //返回不大于最大值的随机整数
                datascript[i].num[j + 1] = rand() % MaxNUM + 1;
            }
            if (decimal == 0)
            {
                datascript[i].num1[j] = rand() % MaxNUM / 1.020000;    //返回不大于最大值的随机小数 ，有误差但是保留一位小数时候误差不计
                datascript[i].num1[j + 1] = rand() % MaxNUM / 1.020000;
            }
            if (j < Num - 1)
            {
                if (decimal == 1)
                {
                    cout << datascript[i].num[j] << " " << Operator[random] << " ";
                    if (File == 1)
                        outfile << datascript[i].num[j] << " " << Operator[random] << " ";
                }
                else
                {
                    cout << setprecision(1) << std::fixed << datascript[i].num1[j] << " " << Operator[random] << " ";
                    if (File == 1)
                        outfile << setprecision(1) << std::fixed << datascript[i].num1[j] << " " << Operator[random] << " ";
                }
            }
            if (j == Num - 1)
            {
                if (decimal == 1)
                {
                    cout << datascript[i].num[j] << " ";
                    if (File == 1)
                        outfile << datascript[i].num[j] << " ";
                }
                else
                {
                    cout << setprecision(1) << std::fixed << datascript[i].num1[j];
                    if (File == 1)
                        outfile << setprecision(1) << std::fixed << datascript[i].num1[j];
                }
            }
        }
        cout << "=  " << "\n";
        if (File == 1)
            outfile << "=  " << "\n";
    }
    outfile.close();
}
int main()
{
    int NUM, Num, MaxNUM;
    int brackets, File, decimal;
    char Operator[5];
    cout << "*****小学四则运算出题器*****\n";
    cout << "设置题组数为：";
    cin >> NUM;
    cout << "设置最大值为： ";
    cin >> MaxNUM;
    cout << "是否有括号   1.是 0.否: ";
    cin >> brackets;
    cout << "是否有小数   1.否 0.是：";
    cin >> decimal;
    cout << "输入运算符（+、-、*、/）（单个）：";
    cin >> Operator;
    cout << "是否存储文件 1.是 0.否: ";
    cin >> File;
    Num = -1;
    cout << "********************************************\n";
    while (1)
    {
        if (Num < 2 || Num>8)
            Num = int(rand() % 10);      //定义每个表达式有多少个参与运算的实数,返回0~9之间的一个随机整数
        else
            break;
    }
    if (brackets == 1)
    {
        havebrackets(NUM, MaxNUM, Num, File, Operator, decimal);
    }
    else if (brackets == 0)
    {
        nobrackets(NUM, MaxNUM, Num, File, Operator, decimal);
    }
    cout << "*****题目生成结束，如存储文件，可查看E:\\file.txt*****\n";
    system("pause");
    return 0;
}