#include "lexer.h"
#include <gtest/gtest.h>

//anonymous namepsace to limit the scope of the declarations better
namespace
{
    TEST(LexerTestSuite, functionHello)
    {
        Lexer l;
        EXPECT_EQ(l.hello("test"), "Hello from ");
    }
}