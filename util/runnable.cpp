//
// Created by austin on 10/4/19.
//

#include "runnable.hpp"

namespace Util {
    void Runnable::start() {
        while (shouldContinue()) {
            run();
        }
    }
}