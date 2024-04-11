#include <cassert>

#include <plx/data/Queue.hpp>
#include <plx/expr/Apply.hpp>
#include <plx/object/ThrowException.hpp>
#include <plx/parser/expr/P_Expr.hpp>
#include <plx/parser/P_Primitive.hpp>

namespace PLX {

    bool pArgumentList(List*& tokens, Object*& value) {
        return pProperListOf(pOpenParen, pAny, pComma, pCloseParen, ")", tokens, value);
    }

    bool pApply(List*& tokens, Object*& value) {
        // delete these three lines before fixing this function
        (void)tokens;
        (void)value;
        return false;
    }

}
