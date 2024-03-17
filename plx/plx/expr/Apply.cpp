#include <cassert>

#include <plx/data/List.hpp>
#include <plx/evaluator/Evaluator.hpp>
#include <plx/expr/Apply.hpp>
#include <plx/object/TypeIds.hpp>
#include <plx/object/TypeIds.hpp>

namespace PLX {

    void Apply::showOn(std::ostream& ostream) const {
#if 0
        switch (_abstractionObj->typeId()) {
            case TypeId::D_CLOSURE:
            case TypeId::E_FUNCTION:
            case TypeId::E_NAMEDFUNCTION:
                ostream << '(' << _abstractionObj << ')';
                break;
            default:
                ostream << _abstractionObj;
                break;
        }
        _arguments->showOnWith(ostream, "(", ", ", ")");
#else
    (void)ostream;
#endif
    }

    TypeId Apply::typeId() const {
        return TypeId::E_APPLY;
    }

}
