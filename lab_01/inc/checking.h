/**
 * @file checking.h
 * @brief Функции проверки ввода
 * 
 */
#ifndef CHECK_H
#define CHECK_H

#include <string.h>
#include "number.h"

#define CHECK_SUCCESS 0
#define CHECK_FAILURE 1
#define CHECK_WRONG_CHARACTERS 2
#define CHECK_MANT_ERROR 3
#define CHECK_EXP_ERROR 4
/**
 * @brief Проверка строки
 * 
 * @param str Проверяемая строка
 * @return int Код возврата (Если были введеы неверные символы - 2, если ошибка в мантиссе - 3, если ошибка в экспоненте - 4)
 */
int check_str(const char str[]);
/**
 * @brief Проверка символов в строке
 * 
 * @param p Указатель на строку
 * @return int Код возврата (Если не найдены ошибки - 0, иначе - 1)
 */
int check_char(const char *p);
/**
 * @brief Подсчет количества символов С в строке
 * 
 * @param c Символ, количество которого снужно посчтиать
 * @param start Указатель на начало строки
 * @param end Указатель на конец строки (это не обязательно \0)
 * @return size_t Количество символов С
 */
size_t count_char(const char c, const char *start, const char *end);
/**
 * @brief Подсчет количества цифр в строке
 * 
 * @param start Указатель на начало строки
 * @param end Указатель на конец строки (это не обязательно \0)
 * @return size_t Количество цифр
 */
size_t count_num(const char *start, const char *end);
/**
 * @brief Проверка арифметических знаков
 * 
 * @param start Указатель на начало строки
 * @param end Указатель на конец строки (это не обязательно \0)
 * @param dot_count Количество возможных точек
 * @return int Код возврата (Если цифр не больше нужного - 0, иначе - 1)
 */
int check_symb(const char *start, const char *end, const size_t dot_count);
/**
 * @brief Проверка мантиссы
 * 
 * @param str Указатель на начало строки
 * @param end Указатель на конец строки (это не обязательно \0)
 * @return int Код возврата  (Если не найдены ошибки - 0, иначе - 1)
 */
int check_mantissa(const char *str, const char *end);
/**
 * @brief Проверка экспоненты
 * 
 * @param e_ptr Указатель на Е
 * @return int Код возврата (Если не найдены ошибки - 0, иначе - 1)
 */
int check_exponent(const char *e_ptr);

#endif