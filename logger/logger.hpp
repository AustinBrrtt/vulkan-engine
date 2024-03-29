//
// Created by austin on 10/1/19.
//

#ifndef VULKAN_ENGINE_LOGGER_HPP
#define VULKAN_ENGINE_LOGGER_HPP

#include <stdexcept>
#include <iostream>
#include <optional>

namespace Logger {
    class error : public std::runtime_error {
        using std::runtime_error::runtime_error;
    };

    /*
     * assertTrue and assertFalse are implemented separately for now for performance
     * since implementation is simple. If implementation becomes complex, make one call
     * the other if appropriate.
     */
    void assertTrue(bool condition, std::string const& errorMessage);

    void assertFalse(bool condition, std::string const& errorMessage);

    template <typename T>
    void assertNotEmpty(T collection, std::string const& errorMessage) {
        if (collection.empty()) {
            throw error(errorMessage);
        }
    }

    template <typename T>
    T unwrap(std::optional<T> opt, std::string const& errorMessage) {
        if (!opt.has_value()) {
            throw error(errorMessage);
        }
        return *opt;
    }

    template<typename T>
    void log(T t) {
        std::cout << t << std::endl;
    }

    template<typename T, typename... Args>
    void log(T t, Args... args) {
        std::cout << t;
        log(args...);
    }
}

#endif //VULKAN_ENGINE_LOGGER_HPP
