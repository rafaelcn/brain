/* This is the source code of Brain Programming Language.
 * It is licensed under GNU GPL v. 3 or later.
 * You should have received a copy of the license in this archive (see LICENSE).
 *
 * Copyright Luiz Peres, 2016.
 */

#ifndef OUTPUT_EXPR_H
#define OUTPUT_EXPR_H

#include "Expr.h"

class OutputExpr : public Expr
{
  public:
    OutputExpr() { }
    void CodeGen();
};

#endif
