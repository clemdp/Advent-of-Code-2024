#include "CppUTest/TestHarness.h"

extern "C" {
    #include "file_read.h"
}

TEST_GROUP(FileReadTest) {
    void setup() {
    }

    void teardown() {
    }
};

TEST(FileReadTest, ReadFile) {
    char *filename = "files/test-d1.txt";
    list_t *list_one = NULL;
    list_t *list_two = NULL;

    int result = read_file(filename, &list_one, &list_two);

    CHECK_EQUAL(EXIT_SUCCESS, result);
    CHECK(list_one != nullptr);
    CHECK(list_one != nullptr);
}