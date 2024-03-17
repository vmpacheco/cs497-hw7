#include <plx/data/Array.hpp>
#include <plx/data/Closure.hpp>
#include <plx/data/List.hpp>
#include <plx/data/Triple.hpp>
#include <plx/evaluator/Evaluator.hpp>
#include <plx/expr/Function.hpp>
#include <plx/literal/Nil.hpp>
#include <plx/literal/String.hpp>
#include <plx/object/Globals.hpp>
#include <plx/object/ThrowException.hpp>
#include <plx/object/TypeIds.hpp>

namespace PLX {

    // Function::Function(what paremeters?)
    // {}

    Object* Function::eval(Evaluator* etor) {
        (void)etor;
        return GLOBALS->NilObject();
    }

    void Function::showOn(std::ostream& ostream) const {
        (void)ostream;
    }

    TypeId Function::typeId() const {
        return TypeId::E_FUNCTION;
    }

}