/**
 * @file parse.h
 * @brief Функции анали строки
 * 
 */
#ifndef PARSE_H
#define PARSE_H

#include "number.h"
#include <string.h>
#include <ctype.h>
/**
 * @brief Анализ строки
 * 
 * @param str Строка
 * @param num Число
 * @return int Код возврата (Если успешно считалось - 0, иначе - 1)
 */
int parse_number(const char str[], number_t *num);
/**
 * @brief Удаление лишних нулей
 * 
 * @param num Число
 */
void remove_zeros(number_t *num);

#endif