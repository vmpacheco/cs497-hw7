#pragma once

#include <plx/object/Object.hpp>

namespace PLX {

    class List;
    class Triple;
    class Function;

    class Closure : public Object {
    public:

        // Overridden functions --------------------------------------------

        Object* apply(Evaluator* etor, List* arguments) override;
        void showOn(std::ostream& ostream) const override;
        TypeId typeId() const override;

    private:

    };

}
