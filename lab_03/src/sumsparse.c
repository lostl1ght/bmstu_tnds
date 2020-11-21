#include "sumsparse.h"

void sumsparse(sparse_s *const s1, sparse_s *const s2, sparse_s *const res)
{
    stype_t non_zero, cur_res = 0, cur_s1 = 0, cur_s2 = 0;
    mtype_t swtch[res->r_count]; // = calloc(res->r_count, sizeof *swtch);
    const mtype_t *tmp;
    // if (!swtch)
    //     return SUMEMEM;
    res->col[cur_res] = cur_res;
    for (stype_t j = 0; j < res->c_count; j++)
    {
        memset(swtch, 0, res->c_count * sizeof *swtch);
        for (stype_t i = 0; i < s1->col[j + 1] - s1->col[j]; i++)
            swtch[s1->rows[i + s1->col[j]]] += 1;
        for (stype_t i = 0; i < s2->col[j + 1] - s2->col[j]; i++)
            swtch[s2->rows[i + s2->col[j]]] += 2;
        non_zero = count(swtch, res->r_count);
        tmp = swtch;
        for (stype_t i = 0; i < non_zero; i++)
        {
            while (tmp[i] == 0)
                tmp++;
            switch (tmp[i])
            {
                case 1:
                    res->non_zero[cur_res] = s1->non_zero[cur_s1];
                    res->rows[cur_res] = s1->rows[cur_s1];
                    cur_res++;
                    cur_s1++;
                    break;
                case 2:
                    res->non_zero[cur_res] = s2->non_zero[cur_s2];
                    res->rows[cur_res] = s2->rows[cur_s2];
                    cur_res++;
                    cur_s2++;
                    break;
                case 3:
                    res->non_zero[cur_res] = s1->non_zero[cur_s1] + s2->non_zero[cur_s2];
                    res->rows[cur_res] = s1->rows[cur_s1];
                    cur_res++;
                    cur_s1++;
                    cur_s2++;
                    break;
            }
        }
        res->col[j + 1] = cur_res;
    }
    res->n_count = cur_res;
    // free(swtch);
    // return SUMOK; 
}

stype_t count(mtype_t *swtch, stype_t size)
{
    stype_t count = 0;
    for (stype_t i = 0; i < size; i++)
        if (swtch[i] != 0)
            count++;
    return count;
}
