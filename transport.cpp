//---------------------------------------------------
#include <iostream>
#include <fstream>
#include "transport.h"
using namespace std;

namespace simple_transport {
    // ���� ���������� �������� �� �����
    void In(airplane& r, ifstream& ifst) {
        ifst >> r.range >> r.carrying >> r.speed >> r.distance;
    }

    // ����� ���������� �������� � �����
    void Out(airplane& r, ofstream& ofst) {
        ofst << "It is Airplane: range = " << r.range
            << ", carrying = " << r.carrying
            << ", speed = " << r.speed
            << ", distance = " << r.distance
            << endl;
    }

    // ���� ���������� ������ �� ������
    void In(train& t, ifstream& ifst)
    {
        ifst >> t.number >> t.speed >> t.distance;
    }

    // ����� ���������� ������ � �����
    void Out(train& t, ofstream& ofst)
    {
        ofst << "It is Train: number = "
            << t.number << ", speed = " << t.speed
            << ", distance = " << t.distance << endl;
    }

    // ���� ���������� ����������� ���������� �� �����
    transport* In(ifstream& ifst)
    {
        transport* tr;
        int k;
        ifst >> k;
        switch (k) {
        case 1:
            tr = new transport;
            tr->k = transport::key::AIRPLANE;
                In(tr->a, ifst);
            return tr;
        case 2:
            tr = new transport;
            tr->k = transport::key::TRAIN;
            In(tr->t, ifst);
            return tr;
        default:
            return 0;
        }
    }

    // ����� ���������� �������� ���������� � �����
    void Out(transport& s, ofstream& ofst) {
        switch (s.k) {
        case transport::key::AIRPLANE:
            Out(s.a, ofst);
            break;
        case transport::key::TRAIN:
            Out(s.t, ofst);
            break;
        default:
            ofst << "Incorrect transport!" << endl;
        }
    }

    // ������������� ����������
    void Init(container& c) { c.len = 0; }

    // ������� ���������� �� ���������
    // (������������ ������)
    void Clear(container& c)
    {
        list* l= nullptr;
        list* l_next;
        for (int i = 0; i < c.len; i++)
        {
            if (i == 0)
                l = c.cont;
            l_next = l->next;
            delete l;
            l = l_next;
        }
        c.len = 0;
    }
           
    // ���� ����������� ���������� �� ���������� ������
    void In(container & c, ifstream & ifst) 
    {
        list* l;
        list* l_prev = nullptr;
        while (!ifst.eof())
        {
            transport* tr = In(ifst);
            if (tr != 0)
            {
                l = new list;
                l->tr = tr;
                if (c.len > 0)
                    l_prev->next = l;
                else
                    c.cont = l;
                l_prev = l;
                c.len++;
            }
        }
    }


    // ����� ����������� ���������� � ��������� �����
    void Out(container& c, ofstream& ofst)
    {
        list* l = nullptr;
        list* l_next;

        ofst << "Container contains " << c.len
            << " elements." << endl;
        for (int i = 0; i < c.len; i++)
        {
            ofst << i << ": ";
            if (i == 0)
                l = c.cont;
            Out(*(l->tr), ofst);
            l_next = l->next;
            l = l_next;
        }
    }
} // end simple_transport namespace
