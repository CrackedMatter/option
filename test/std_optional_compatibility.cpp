
// Copyright 2025.
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

TEST_CASE("construct from std::optional") {
    const std::optional<int> val = 1;

    const opt::option<int> a = std::optional<int>{1};
    CHECK_EQ(a, 1);

    struct explicit_type {
        explicit explicit_type(int x_) : x{x_} {}
        int x;
    };
    const opt::option<explicit_type> b{std::optional<int>{1}};
    CHECK_EQ(b->x, 1);

    const opt::option<int> c = val;
    CHECK_EQ(c, 1);

    const opt::option<explicit_type> d{val};
    CHECK_EQ(d->x, 1);
}

TEST_CASE("assign from std::optional") {
    opt::option<int> a;

    const std::optional<int> val = 1;
    a = val;
    CHECK_EQ(a, 1);

    a = std::optional<int>{2};
    CHECK_EQ(a, 2);
}

TEST_SUITE_END();

}
