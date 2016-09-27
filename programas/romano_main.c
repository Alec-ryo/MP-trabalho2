#include <romano.h>
#include <stdio.h>
#include "gtest/gtest.h"
#include <romano.h>

TEST(conversorTest, Existe){
  EXPECT_EQ (1258, conversor("MCCLVIII"));
  EXPECT_EQ (1250, conversor("MCCL"));
  EXPECT_EQ (8, conversor("VIII"));
  EXPECT_EQ (1001, conversor("MMI"));
}

TEST(conversorTest, NaoExiste){
  ASSERT_EQ (-1, conversor("MIVV"));
  ASSERT_EQ (-1, conversor(""));
}

int main(int argc, char **argv){

  char romano[30];
  int num;

  system("clear");

  printf("Digite o valor em algarismo romano: ");
  scanf("%29s", romano);

  num = conversor(romano);

  printf("\n%d\n", num);

  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();

}
