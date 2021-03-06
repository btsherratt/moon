#ifndef COMPILER_GENERATORS_OBJ_C_OUTPUT_FUNCTION_PROTOTYPES_H
#define COMPILER_GENERATORS_OBJ_C_OUTPUT_FUNCTION_PROTOTYPES_H

#include "common.h"

#include <set>
#include "compiler/operations.h"
#include "compiler/tree.h"
#include "printer.h"

namespace generator
{
	namespace objC
	{
		class OutputFunctionPrototypes : public operation::Operation
		{
		public:
			static void run(generator::objC::Printer *printer, tree::Program *program);

			virtual void visit(tree::Scope *scope);
			virtual void visit(tree::Function *function);
			virtual void visit(tree::Import *import);

		private:
			OutputFunctionPrototypes() {}

			generator::objC::Printer *mPrinter;
			std::set<tree::FunctionPrototype *>mPrototypesOutput;
		};
	}
}

#endif
