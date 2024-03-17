#include <cassert>

#include <plx/data/Array.hpp>
#include <plx/data/Closure.hpp>
#include <plx/data/List.hpp>
#include <plx/data/Triple.hpp>
#include <plx/evaluator/Evaluator.hpp>
#include <plx/expr/Function.hpp>
#include <plx/literal/Nil.hpp>
#include <plx/literal/String.hpp>
#include <plx/object/Globals.hpp>
#include <plx/object/TypeIds.hpp>

namespace PLX {

    Object* Closure::apply(Evaluator* etor, List* arguments) {
        (void)etor;
        (void)arguments;
        return GLOBALS->NilObject();
    }

    void Closure::showOn(std::ostream& ostream) const {
        (void)ostream;
    }

    TypeId Closure::typeId() const {
        return TypeId::D_CLOSURE;
    }

}