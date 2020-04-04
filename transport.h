#pragma once
//---------------------------------------------------
#ifndef __transport_atd__
#define __transport_atd__
namespace simple_transport {
    //самолет
    struct airplane {
        int range, carrying, speed, distance;
    };

    //поезд
    struct train {
        int number, speed, distance;
    };

    // структура, обобщающа€ все имеющиес€ фигуры
    struct transport {
        // значени€ ключей дл€ каждой из фигур
        enum key { AIRPLANE, TRAIN };
        key k; // ключ
        // используемые альтернативы
        union { // используем включение
            airplane a;
            train t;
        };
    };

    struct list {
        transport* tr;
        list* next;
    };

    // контейнер на базе однонаправленного списка
    struct container
    {
        enum { max_len = 100 }; // максимальна€ длина
        int len; // текуща€ длина
        list* cont;
    };
} // end simple_shapes namespace
#endif
