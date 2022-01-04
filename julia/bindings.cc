#pragma GCC diagnostic ignored "-Wterminate"

#include <fmt/core.h>
#include <jlcxx/jlcxx.hpp>

#define BL_FATAL(...) throw \
fmt::format("[{}@{}] {}", __FILE__, __LINE__, __VA_ARGS__).c_str();

std::string greet() {
   return "hello, world";
}

JLCXX_MODULE define_julia_module(jlcxx::Module& mod) {
    mod.method("greet", &greet);
}
