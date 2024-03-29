#pragma once

namespace Golem::Core
{
    class NonCopyable
    {
    protected:
        NonCopyable() {}
        ~NonCopyable() {}

    private:
        NonCopyable(const NonCopyable&) {}
        NonCopyable& operator=(const NonCopyable&) {}
    };
}
