
// Copyright 2024.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at https://www.boost.org/LICENSE_1_0.txt)

#include <doctest/doctest.h>

#define OPTION_STD_OPTIONAL_COMPATIBILITY 1
#include <opt/option.hpp>

#include "utils.hpp"

namespace {

TEST_SUITE_BEGIN("std::optional compatibility");

TEST_CASE("comparison operators") {
    SUBCASE("operator==") {
        CHECK_UNARY(std::optional{1} == opt::option{1});
        CHECK_UNARY(opt::option{1} == std::optional{1});
    }
    SUBCASE("operator!=") {
        CHECK_UNARY(std::optional{1} != opt::option{2});
        CHECK_UNARY(opt::option{2} != std::optional{1});
    }
    SUBCASE("operator>") {
        CHECK_UNARY(std::optional{2} > opt::option{1});
        CHECK_UNARY(opt::option{2} > std::optional{1});
    }
    SUBCASE("operator>=") {
        CHECK_UNARY(std::optional{2} >= opt::option{1});
        CHECK_UNARY(opt::option{2} >= std::optional{1});
    }
    SUBCASE("operator<") {
        CHECK_UNARY(std::optional{1} < opt::option{2});
        CHECK_UNARY(opt::option{1} < std::optional{2});
    }
    SUBCASE("operator<=") {
        CHECK_UNARY(std::optional{1} <= opt::option{2});
        CHECK_UNARY(opt::option{1} <= std::optional{2});
    }
}

TEST_SUITE_END();

}
