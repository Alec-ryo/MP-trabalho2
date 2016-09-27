#include <limits.h>
#include "romano.h"
#include "gtest/gtest.h"

/*Converteremos os respectivos valores romanos em valores arábicos*/
/*No primero teste espera-se que a conversão ocorra com sucesso*/
TEST(conversorTest, Existe){

  char nome[] = "MCCLVIII";
  EXPECT_EQ (1258, conversor(nome));
  char nome1[] = "MCCL";  
  EXPECT_EQ (1250, conversor(nome1));
  char nome2[] = "VIII";    
  EXPECT_EQ (8, conversor(nome2));
  char nome3[] = "MI";  
  EXPECT_EQ (1001, conversor(nome3));
}

/*Neste teste os valores nao existem, assim retorna -1*/

TEST(conversorTest, NaoExiste){
  char nome[] = "MIVVV";
  ASSERT_EQ (-1, conversor(nome));
  char nome1[] = "N";
  ASSERT_EQ (-1, conversor(nome1));
}

