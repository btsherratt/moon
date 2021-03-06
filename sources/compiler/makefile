THIS_MAKEFILE_DIR:=$(shell DIRECTORY="$(dir $(realpath $(lastword $(MAKEFILE_LIST))))"; echo $${DIRECTORY%/})
include $(THIS_MAKEFILE_DIR)/../../makefile.settings

SOURCES:=$(shell find $(THIS_MAKEFILE_DIR) -type f -name "*.cpp")
OBJECTS:=$(PLATFORM_OBJ_DIR)/generated_lexer.o $(PLATFORM_OBJ_DIR)/generated_parser.o
OBJECTS+=$(patsubst $(THIS_MAKEFILE_DIR)/%,$(PLATFORM_OBJ_DIR)/%,$(SOURCES:.cpp=.o))
DEPS:=$(OBJECTS:.o=.deps)

.INTERMEDIATE: generated_lexer.cpp generated_parser.cpp

all: $(MOON)

# Dependencies
-include $(DEPS)

generated_parser.cpp: moon.y moon.l
	@echo $@: $<
	@mkdir -p $(PLATFORM_INC_DIR)/generated
	@$(BISON) $(BISON_FLAGS) --defines="$(PLATFORM_INC_DIR)/generated/parser.h" -o generated_parser.cpp $<

generated_lexer.cpp: moon.l moon.y
	@echo $@: $<
	@mkdir -p $(PLATFORM_INC_DIR)/generated
	@$(FLEX) $(FLEX_FLAGS) --header-file="$(PLATFORM_INC_DIR)/generated/lexer.h" -o generated_lexer.cpp $<

$(PLATFORM_OBJ_DIR)/generated_%.o: generated_%.cpp
	@echo $(<:.cpp=.o): $< [Auto-generated]
	@mkdir -p $(shell dirname $@)
	@$(CXX) -c $(CPP_FLAGS) $(CXX_FLAGS) -I"$(PLATFORM_INC_DIR)/generated" -MD -MF $(@:.o=.deps) -o $@ $<

$(PLATFORM_OBJ_DIR)/generated_lexer.o: generated_parser.cpp
$(PLATFORM_OBJ_DIR)/generated_parser.o: generated_lexer.cpp

# Rules
include $(MOON_ROOT_DIR)/makefile.rules

$(MOON): $(OBJECTS)
	@mkdir -p $(shell dirname $@)
	@$(LINKER) $(LINKER_FLAGS) -o $@ $^

clean:
	@rm -rf generated_*
	@rm -rf $(PLATFORM_INC_DIR)/generated
	@rm -rf $(DEPS)
	@rm -rf $(OBJECTS)
	@rm -rf $(PLATFORM_BIN_DIR)/$(COMPILER_FILENAME)
