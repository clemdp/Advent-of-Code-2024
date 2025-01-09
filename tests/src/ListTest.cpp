#include <CppUTest/TestHarness.h>

extern "C" {
    #include "list.h"
}

TEST_GROUP(ListTest) {
    void setup() {
    }

    void teardown() {
    }
};

TEST(ListTest, CreateList) {
    list_t *list = create_list(0);
    CHECK(list != nullptr);
    CHECK_EQUAL(0, list->value);
    CHECK_EQUAL(nullptr, list->next);
}

TEST(ListTest, Insert) {
    list_t *list = create_list(0);
    insert(&list, 1, 0);
    CHECK_EQUAL(1, list->next->value);
    insert(&list, 2, 0);
    CHECK_EQUAL(2, list->value);
    CHECK_EQUAL(1, list->next->value);
    insert(&list, 3, 0);
    CHECK_EQUAL(3, list->value);
    CHECK_EQUAL(2, list->next->value);
    CHECK_EQUAL(1, list->next->next->value);
}

TEST(ListTest, Pop) {
    list_t *list = create_list(0);
    insert(&list, 1, 0);
    insert(&list, 2, 0);
    list_t *value = pop(&list);
    CHECK_EQUAL(0, value->value);
    CHECK_EQUAL(1, list->value);
    value = pop(&list);
    CHECK_EQUAL(1, value->value);
    CHECK_EQUAL(2, list->value);
}

TEST(ListTest, PrintList) {
    list_t *list = create_list(0);
    insert(&list, 1, 0);
    insert(&list, 2, 0);
    insert(&list, 3, 0);
    print_list(list, false);
    printf("\n");
    print_list(list, true);
    printf("\n");
}

TEST(ListTest, FreeList) {
    list_t *list = create_list(0);
    insert(&list, 1, 0);
    insert(&list, 2, 0);
    insert(&list, 3, 0);
    free_list(&list);
    CHECK_EQUAL(nullptr, list);
}