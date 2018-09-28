//===----------------------------------------------------------------------===//
//
//                         Peloton
//
// tuple_value_translator.h
//
// Identification: src/include/execution/expression/tuple_value_translator.h
//
// Copyright (c) 2015-2017, Carnegie Mellon University Database Group
//
//===----------------------------------------------------------------------===//

#pragma once

#include "execution/expression/expression_translator.h"

namespace peloton {

namespace expression {
class TupleValueExpression;
}  // namespace expression

namespace codegen {

//===----------------------------------------------------------------------===//
// A translator for expressions that access a specific attribute in a tuple
//===----------------------------------------------------------------------===//
class TupleValueTranslator : public ExpressionTranslator {
 public:
  // Constructor
  TupleValueTranslator(const expression::TupleValueExpression &tve_expr,
                       CompilationContext &context);

  // Return the attribute from the row
  Value DeriveValue(CodeGen &codegen, RowBatch::Row &row) const override;
};

}  // namespace codegen
}  // namespace peloton