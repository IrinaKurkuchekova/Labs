#pragma once
//---------------------------------------------------
#ifndef __transport_atd__
#define __transport_atd__
namespace simple_transport {
    //�������
    struct airplane {
        int range, carrying, speed, distance;
    };

    //�����
    struct train {
        int number, speed, distance;
    };

    // ���������, ���������� ��� ��������� ������
    struct transport {
        // �������� ������ ��� ������ �� �����
        enum key { AIRPLANE, TRAIN };
        key k; // ����
        // ������������ ������������
        union { // ���������� ���������
            airplane a;
            train t;
        };
    };

    struct list {
        transport* tr;
        list* next;
    };

    // ��������� �� ���� ����������������� ������
    struct container
    {
        enum { max_len = 100 }; // ������������ �����
        int len; // ������� �����
        list* cont;
    };
} // end simple_shapes namespace
#endif
