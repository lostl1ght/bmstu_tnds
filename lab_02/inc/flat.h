#ifndef FLAT_H
#define FLAT_H

#define MAXN 32

typedef struct flat
{
    char adr[MAXN];
    int area;
    int price_per_m2;
    int price;
    int room_cnt;
    char is_new;
    union
    {
        char is_trim;
        struct
        {
            int year;
            int owner_cnt;
            int last_resident_cnt;
            char were_anmls;
        } old;
    } type;
} flat_t;

#endif