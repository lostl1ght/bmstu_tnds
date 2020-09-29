/**
 * @file multiply.h
 * @brief Функции умножения
 * 
 */
#ifndef MULTIPLY_H
#define MULTIPLY_H

#include "number.h"

#define MTL_SUCCESS 0
#define MLT_FAILURE 1
/**
 * @brief Функция умножения
 * 
 * @param num1 Первое число
 * @param num2 Второе число
 * @param res Результат
 * @return int Код возврата (Если успешно считалось - 0, иначе - 1)
 */
int multiply(number_t *num1, number_t *num2, number_t *res);
/**
 * @brief Вычисление произвдения мантисс
 * 
 * @param num1 Первое число
 * @param num2 Второе число
 * @param res Результат
 * @return size_t Длина результата до округления
 */
size_t multiply_mant(number_t *num1, number_t *num2, number_t *res);
/**
 * @brief Перенос разрядов
 * 
 * @param len_m Длина мантиссы
 * @param i Сдвиг
 * @param arr0 Мантисса
 */
void num_carry(size_t len_m, size_t i, int arr0[]);
/**
 * @brief Округление
 * 
 * @param arr Мантисса
 * @param old_len Старая длина мантиссы
 * @return size_t Длина мантиссы
 */
size_t round_mant(int arr[], size_t *old_len);

#endif