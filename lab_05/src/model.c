#include "model.h"

void arr_model(arrq_t *const q1, arrq_t *const q2,
               const time_range_t t1, const time_range_t t2,
               const time_range_t t3, const time_range_t t4)
{
    int type;// = 1;

    size_t in_tasks1 = 0;
    size_t out_tasks1 = 0;

    size_t in_tasks2 = 0;
    size_t out_tasks2 = 0;

    size_t out_show = 0;

    double total_time = 0.0;
    double t_oa = 0.0;

    task_t task = {.data = NULL};

    double t_in1 = 0.0;
    double t_in2 = 0.0;

    size_t overall_len1 = 0;
    size_t overall_len2 = 0;

    double total_t1 = 0.0;
    double total_t2 = 0.0;

    while (out_tasks1 != 1000)
    {
        //Время прихода
        if (t_in1 == 0.0)
            t_in1 = get_time(t1);
        if (t_in2 == 0.0)
            t_in2 = get_time(t2);

        // Получение заявки
        if (t_oa == 0.0)
        {
            if (is_arr_empty(q1) && !is_arr_empty(q2))
            {
                type = 2;
                t_oa = get_time(t4);
                get_arr_queue(q2, &task);
                total_t2 += t_oa;
            }
            else if (!is_arr_empty(q1))
            {
                type = 1;
                t_oa = get_time(t3);
                get_arr_queue(q1, &task);
                total_t1 += t_oa;
            }
        }
        /*Самое маленькое время, АКА что сейчас будет происходить.
        Если минимум - т_оа, то обработалась заявка,
        иначе - пришла заявка.
        */
        double t_min = 0.0;

        if (t_oa == 0.0)
            t_min = fmin(t_in1, t_in2);
        else
            t_min = fmin(t_in1, fmin(t_in2, t_oa));

        if (t_min == t_oa)
        {
            t_oa = 0.0;
            if (type == 1)
            {
                overall_len1 += q1->size;
                out_tasks1++;
            }
            if (type == 2)
            {
                overall_len2 += q2->size;
                out_tasks2++;
            }
        }
        if (out_tasks1 == 1000)
            break;

        if (t_min == t_in1)
        {
            if (!is_arr_full(q1))
            {
                put_arr_queue(q1, task);
            }
            in_tasks1++;
        }
        if (t_min == t_in2)
        {
            if (!is_arr_full(q2))
            {
                put_arr_queue(q2, task);
            }
            in_tasks2++;
        }
        //Здесь обновляется время для следующей итерации
        t_in1 -= t_min;
        t_in2 -= t_min;
        if (t_oa >= t_min)
            t_oa -= t_min;
        total_time += t_min;

        if (out_tasks1 % 100 == 0 && out_tasks1 > 0 && out_tasks1 != out_show)
        {
            out_show = out_tasks1;
            printf("\tOut tasks 1: %zu\n", out_tasks1);
            printf("Q1 size: %zu, avg: %lf\n", q1->size, (double)overall_len1 / out_tasks1);
            printf("Q2 size: %zu, avg: %lf\n", q2->size, (double)overall_len2 / out_tasks2);
        }
    }
    double expected_time;    
    if (t1.llim + t1.rlim > t3.llim + t3.rlim) 
        expected_time = (double)(t1.llim + t1.rlim) * 500;
    else
        expected_time = (double)(t3.llim + t3.rlim) * 500;
    double delta = fabs(total_time - expected_time) / expected_time * 100;
    printf("\nExpected time: %lf\n", expected_time);
    printf("Total time: %lf\n", total_time);
    printf("Delta: %lf%%\n", delta);
    printf("Service time: %lf\n", total_t1 + total_t2);
    printf("Hold time: %lf\n", fabs(total_time - total_t1 - total_t2));
    printf("In tasks 1: %zu\n", in_tasks1);
    printf("Out tasks 1: %zu\n", out_tasks1);
    printf("In tasks 2: %zu\n", in_tasks2);
    printf("Out tasks 2: %zu\n", out_tasks2);
}

void list_model(listq_t *const q1, listq_t *const q2,
               const time_range_t t1, const time_range_t t2,
               const time_range_t t3, const time_range_t t4)
{

    int type;// = 1;

    size_t in_tasks1 = 0;
    size_t out_tasks1 = 0;

    size_t in_tasks2 = 0;
    size_t out_tasks2 = 0;

    size_t out_show = 0;

    double total_time = 0.0;
    double t_oa = 0.0;

    task_t task = {.data = NULL};

    double t_in1 = 0.0;
    double t_in2 = 0.0;

    size_t overall_len1 = 0;
    size_t overall_len2 = 0;

    double total_t1 = 0.0;
    double total_t2 = 0.0;

    while (out_tasks1 != 1000)
    {
        //Время прихода
        if (t_in1 == 0.0)
            t_in1 = get_time(t1);
        if (t_in2 == 0.0)
            t_in2 = get_time(t2);

        // Получение заявки
        if (t_oa == 0.0)
        {
            if (is_list_empty(q1) && !is_list_empty(q2))
            {
                type = 2;
                t_oa = get_time(t4);
                get_list_queue(q2, &task);
                total_t1 += t_oa;
            }
            else if (!is_list_empty(q1))
            {
                type = 1;
                t_oa = get_time(t3);
                get_list_queue(q1, &task);
                total_t2 += t_oa;
            }
        }
        /*Самое маленькое время, АКА что сейчас будет происходить.
        Если минимум - т_оа, то обработалась заявка,
        иначе - пришла заявка.
        */
        double t_min = 0.0;

        if (t_oa == 0.0)
            t_min = fmin(t_in1, t_in2);
        else
            t_min = fmin(t_in1, fmin(t_in2, t_oa));

        if (t_min == t_oa)
        {
            t_oa = 0.0;
            if (type == 1)
            {
                overall_len1 += q1->size;
                out_tasks1++;
            }
            if (type == 2)
            {
                overall_len2 += q2->size;
                out_tasks2++;
            }
        }
        if (out_tasks1 == 1000)
            break;

        if (t_min == t_in1)
        {
            if (!is_list_full(q1))
            {
                put_list_queue(q1, task);
            }
            in_tasks1++;
        }
        if (t_min == t_in2)
        {
            if (!is_list_full(q2))
            {
                put_list_queue(q2, task);
            }
            in_tasks2++;
        }
        //Здесь обновляется время для следующей итерации
        t_in1 -= t_min;
        t_in2 -= t_min;
        if (t_oa >= t_min)
            t_oa -= t_min;
        total_time += t_min;

        if (out_tasks1 % 100 == 0 && out_tasks1 > 0 && out_tasks1 != out_show)
        {
            out_show = out_tasks1;
            printf("\tOut tasks 1: %zu\n", out_tasks1);
            printf("Q1 size: %zu, avg: %lf\n", q1->size, (double)overall_len1 / out_tasks1);
            printf("Q2 size: %zu, avg: %lf\n", q2->size, (double)overall_len2 / out_tasks2);
        }
    }
    double expected_time;
    if (t1.llim + t1.rlim > t3.llim + t3.rlim) 
        expected_time = (double)(t1.llim + t1.rlim) * 500;
    else
        expected_time = (double)(t3.llim + t3.rlim) * 500;
    double delta = fabs(total_time - expected_time) / expected_time * 100;
    printf("\nExpected time: %lf\n", expected_time);
    printf("Total time: %lf\n", total_time);
    printf("Service time: %lf\n", total_t1 + total_t2);
    printf("Delta: %lf%%\n", delta);
    printf("Hold time: %lf\n", fabs(total_time - total_t1 - total_t2));
    printf("In tasks 1: %zu\n", in_tasks1);
    printf("Out tasks 1: %zu\n", out_tasks1);
    printf("In tasks 2: %zu\n", in_tasks2);
    printf("Out tasks 2: %zu\n", out_tasks2);
}
