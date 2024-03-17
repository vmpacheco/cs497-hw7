#pragma once

#include <plx/object/Object.hpp>

namespace PLX {

    class Apply : public Object {
    public:
        Object* eval(Evaluator* etor) override;
        void showOn(std::ostream& ostream) const override;
        TypeId typeId() const override;
    private:
    };

}
