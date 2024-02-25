#include <gtest/gtest.h>

#include "../include/board.h"

TEST(test_1, boar) {
    EXPECT_NO_THROW(
        Board test;
    );
}

TEST(test_2, board) {
    Board board;
    EXPECT_NO_THROW(
        board.add_npc(KNIGHT, 1,2);
    );
}

TEST(test_3, board) {
    Board board; 
    board.add_npc(KNIGHT, 1,2);
    board.add_npc(DRAGON, 1,2);
    board.add_npc(ELF, 1,2);
    EXPECT_NO_THROW(
        board.print();
    );
}

TEST(test_4, board) {
    Board board;
    board.add_npc(KNIGHT, 1,2);
    EXPECT_NO_THROW(
        board.file_save("save");
    );
}

TEST(test_5, board) {
    Board board;
    board.add_npc(KNIGHT, 1,2);
    board.file_save("save");
    std::ifstream in("save");
    int type, x, y;
    in >> type >> x >> y;
}

TEST(test_6, board) {
    Board board;
    EXPECT_NO_THROW(
        board.file_load("save");
    );
}


TEST(test_7, board) {
    Board board;
    board.file_load("save");
    board.file_save("test");
    std::ifstream in("test");
    int type, x, y;
    in >> type >> x >> y;
    ASSERT_TRUE(type == KNIGHT && x == 1 && y == 2);
}

TEST(test_8, board) {
    Board board;
    board.add_npc(KNIGHT, 100,29);
    board.add_npc(DRAGON, 4,93);
    board.add_npc(ELF, 11,43);
    board.add_npc(ELF, 149,2);
    board.add_npc(KNIGHT, 499,2);
    EXPECT_NO_THROW(board.fight());
}


int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}