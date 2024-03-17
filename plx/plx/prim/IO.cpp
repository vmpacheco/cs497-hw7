#include <cassert>

#include <plx/data/Array.hpp>
#include <plx/data/List.hpp>
#include <plx/data/Queue.hpp>
#include <plx/evaluator/Evaluator.hpp>
#include <plx/literal/Integer.hpp>
#include <plx/literal/Nil.hpp>
#include <plx/literal/String.hpp>
#include <plx/object/Globals.hpp>
#include <plx/object/Object.hpp>
#include <plx/object/ThrowException.hpp>
#include <plx/object/TypeIds.hpp>
#include <plx/prim/Primitive.hpp>

namespace PLX {
    namespace Prim_IO {

        Object* display(Evaluator* etor, List* args) {
            (void)etor;
            (void)args;
            return GLOBALS->NilObject();
        }

        Object* nl(Evaluator* etor, List* args) {
            (void)etor;
            (void)args;
            return GLOBALS->NilObject();
        }

        Object* readLine(Evaluator* etor, List* args) {
            (void)etor;
            (void)args;
            return GLOBALS->NilObject();
        }

        Object* show(Evaluator* etor, List* args) {
            (void)etor;
            (void)args;
            return GLOBALS->NilObject();
        }

    }
}
