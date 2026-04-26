#include <stdio.h>
#include <stdlib.h>

struct A
{
    int data;
};

struct B
{
    int data;
    struct A a;
};

struct C
{
    int data;
};

struct D
{
    int data;
    struct C *c;
};

int main()
{
    struct A *a;
    a = (struct A *)malloc(sizeof(struct A));
    a->data = 2;

    struct B b;
    b.data = 1;
    b.a = *a;

    printf("%d\n", b.data);
    printf("%d\n\n", b.a.data);

    // =============================

    struct A a2;
    a2.data = 2;

    struct B b2;
    b2.data = 1;
    b2.a = a2;

    printf("%d\n", b2.data);
    printf("%d\n\n", b2.a.data);

    // =============================
    // =============================
    // =============================
    // =============================

    struct C *c;
    c = (struct C *)malloc(sizeof(struct C));
    c->data = 2;

    struct D d;
    d.data = 1;
    d.c = c;

    printf("%d\n", d.data);
    printf("%d\n\n", d.c->data);

    // =============================

    struct C c2;
    c2.data = 2;

    struct D d2;
    d2.data = 1;
    d2.c = &c2;

    printf("%d\n", d2.data);
    printf("%d\n", d2.c->data);
}
