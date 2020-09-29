/**
 * @file inpt_oupt.h
 * @brief Функции ввода и вывода
 * 
 */
#ifndef INPT_OUPT_H
#define INPT_OUPT_H

#include <stdio.h>
#include "number.h"

/**
 * @brief Функция ввода строки
 * 
 * @param str Указатель на строку
 * @return int Код возврата (Если успешно считалось - 0, иначе - 1)
 */
int input_str(char str[]);
/**
 * @brief Служебная функция проверки правильного считывания и анализа строки
 * 
 * @param num Введенное число
 */
void output_check(const number_t *num);
/**
 * @brief Вывод числа
 * 
 * @param num Число
 */
void output_num(const number_t *num);

#endif