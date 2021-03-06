#ifndef COMPILER_GENERATORS_C_OUTPUT_NEW_H
#define COMPILER_GENERATORS_C_OUTPUT_NEW_H

#include "common.h"

#include "compiler/operations.h"
#include "compiler/tree.h"
#include "printer.h"

namespace generator
{
	namespace c
	{
		class OutputNew : public operation::Operation
		{
		public:
			static void run(generator::c::Printer *printer, tree::Program *program);

			virtual void visit(tree::Scope *scope);
			virtual void visit(tree::Program *program);
			virtual void visit(tree::Aggregate *aggregate);
			virtual void visit(tree::Use *use);

		private:
			OutputNew() {}

			void outputScope(tree::Scope *scope);

			generator::c::Printer *mPrinter;
		};
	}
}

#endif
