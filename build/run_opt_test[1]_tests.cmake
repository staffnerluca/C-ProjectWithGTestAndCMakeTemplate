add_test( LexerTestSuite.functionHello /home/staffnerluca/Dokumente/resh/build/run_opt_test [==[--gtest_filter=LexerTestSuite.functionHello]==] --gtest_also_run_disabled_tests)
set_tests_properties( LexerTestSuite.functionHello PROPERTIES WORKING_DIRECTORY /home/staffnerluca/Dokumente/resh/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set( run_opt_test_TESTS LexerTestSuite.functionHello)
