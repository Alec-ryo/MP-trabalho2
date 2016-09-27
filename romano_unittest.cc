#include <limits.h>
#include "romano.h"
#include "gtest/gtest.h"

/*Converteremos os respectivos valores romanos em valores arábicos*/
/*No primero teste espera-se que a conversão ocorra com sucesso*/
TEST(conversorTest, Existe){
  EXPECT_EQ (1258, conversor("MCCLVIII"));
  EXPECT_EQ (1250, conversor("MCCL"));
  EXPECT_EQ (8, conversor("VIII"));
  EXPECT_EQ (1001, conversor("MI"));
}

/*Neste teste os valores nao existem, assim retorna -1*/

TEST(conversorTest, NaoExiste){
  ASSERT_EQ (-1, conversor("MIVVV"));
  ASSERT_EQ (-1, conversor("N"));
}

