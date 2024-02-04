#include <plx/data/Array.hpp>
#include <plx/data/Triple.hpp>
#include <plx/evaluator/Evaluator.hpp>
#include <plx/expr/Identifier.hpp>
#include <plx/literal/String.hpp>
#include <plx/object/ThrowException.hpp>
#include <plx/object/TypeIds.hpp>

namespace PLX {

    extern bool globalDebug;
    
    Evaluator::Evaluator() {
    }

    Triple* Evaluator::bind(Object* key, Object* value) {
        _environment = new Triple(key, value, _environment);
        return _environment;
    }

    Triple* Evaluator::environment() const {
        return _environment;
    }

    Object* Evaluator::evalExpr(Object* expr) {
        return expr->eval(this);
    }

    Object* Evaluator::evalExpr(Object* expr, Triple* environment) {
        Triple* savedEnv = _environment;
        _environment = environment;
        Object* value = evalExpr(expr);
        _environment = savedEnv;
        return value;
    }

    Object* Evaluator::lookup(Identifier* identifier) const {
        Object* value;
        if (!_environment->lookup(identifier, value)) {
            throwException("Evaluator", "Unbound identifier", identifier);
        }
        return value;
    }

    bool Evaluator::rebind(Identifier* key, Object* value) {
        Triple* binding = _environment->locate(key);
        if (binding->isEmpty()) {
            return false;
        }
        binding->setValue(value);
        return false;
    }


    void Evaluator::setEnvironment(Triple* env) {
        _environment = env;
    }

    TypeId Evaluator::typeId() const {
        return TypeId::T_EVALUATOR;
    }

}
