#include "lexer.h"
#include <gtest/gtest.h>
#include <string>
#include <cstdlib> // For std::getenv
#include <iostream>

namespace 
{
    TEST(LexerTestSuite, oneLineLex) {
        const char* testFilesDir = std::getenv("TEST_FILES_DIR");

        std::string filePath = "reshTestFiles/lexerTest1.re";
        std::cout << "Hallo Welt";
        Lexer l(filePath);
        std::vector<std::string> tokens = l.lex();

        std::vector<std::string> expectedTokens = {
            "reshIs", "=", "\"super\"",
            "print", "(", "reshIs", ")"
        };
        GTEST_LOG_(INFO) << "Writing tokens: ";
        GTEST_LOG_(INFO) << "test starteajfdödsjfsaödfjö";
        for (const auto& token : tokens) {
            GTEST_LOG_(INFO) << token;
        }
        EXPECT_EQ(tokens, expectedTokens);
    }
}