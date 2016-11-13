
//          Copyright Oliver Kowalke 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>
#include <iostream>
#include <tuple>

#include <boost/context/all.hpp>

namespace ctx = boost::context;

ctx::execution_context< void > f1( ctx::execution_context< void > && ctx) {
    std::cout << "f1: entered first time"  << std::endl;
    ctx();
    std::cout << "f1: entered second time" << std::endl;
    ctx();
    std::cout << "f1: entered third time" << std::endl;
    return std::move( ctx);
}

ctx::execution_context< void > f2( ctx::execution_context< void > && ctx) {
    std::cout << "f2: entered" << std::endl;
    return std::move( ctx);
}

int main() {
    ctx::execution_context< void > ctx( f1);
    ctx();
    std::cout << "f1: returned first time" << std::endl;
    ctx();
    std::cout << "f1: returned second time" << std::endl;
    ctx( ctx::exec_ontop_arg, f2);
    std::cout << "f1: returned third time" << std::endl;

    std::cout << "main: done" << std::endl;

    return EXIT_SUCCESS;
}
