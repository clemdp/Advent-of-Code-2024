## Silence switch ##
# run 'make V=1' to make it verbose
ifeq ($(V),1)
	SILENCE=1
else
	SILENCE=0
endif

## CppUTest configuration ##
# Read header comment on file ${CPPUTEST_HOME}/build/MakefileWorker.mk to understand the variables

COMPONENT_NAME = test-template
CPPUTEST_HOME = cpputest
CPPUTEST_ENABLE_DEBUG = Y
CPPUTEST_USE_EXTENSIONS = Y
CPP_PLATFORM = Gcc
# CPPUTEST_USE_GCOV = Y
CPPUTEST_OBJS_DIR=objs/tests
CPPUTEST_LIB_DIR=lib/tests

SRC_DIRS = \
	src \

test_SRC_DIRS = \
	tests \

INCLUDE_DIRS = \
	$(CPPUTEST_HOME)/include \
	include \

## The real work ##
# including this file that will use configuration and have the make rules.
include $(CPPUTEST_HOME)/MakefileWorker.mk

# Coverage Report rules #
coverage: all
	$(SILENCE)lcov --capture --directory objs/tests/src --output-file coverage.info
	$(SILANCE)genhtml coverage.info --output-directory coverage
	@echo
	@echo "Written coverage report to coverage/index.html"
	@echo
	
coverage_clean:
	rm -rf coverage coverage.info