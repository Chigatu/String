CC=gcc

SRC_DIR:=.
BUILD_DIR:=./build
INC_DIR:=.

TST_DIR:=./tests
TST_BUILD:=$(TST_DIR)/build

GCOV_DIR:=report
GCOV_BUILD:=$(GCOV_DIR)/build


SRC:=$(wildcard $(SRC_DIR)/s21_*.c)
INC:=$(wildcard $(SRC_DIR)/s21_*.h)
OBJ:=$(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o, $(SRC))
TARGET:=s21_string.a

TST_SRC:=$(wildcard $(TST_DIR)/test_s21_*.c)
TST_INC:=$(wildcard $(TST_DIR)/test_s21_*.h)
TST_OBJ:=$(patsubst $(TST_DIR)/%.c,$(TST_BUILD)/%.o, $(TST_SRC))
TST_TARGET:=tests_s21
TST_TARGET_SRC:=$(TST_DIR)/$(TST_TARGET).c

GCOV_SRC:=$(wildcard $(SRC_DIR)/s21_*.c)
GCOV_INC:=$(wildcard $(SRC_DIR)/s21_*.h)
GCOV_OBJ:=$(patsubst $(SRC_DIR)/s21_%.c, $(GCOV_BUILD)/s21_%.o, $(GCOV_SRC) ) 
GCOV_LIB:=$(GCOV_BUILD)/$(TARGET)
GCOV_TST_TARGET:=$(GCOV_BUILD)/$(TST_TARGET)


PROG:=pkg-config
ifeq (,$(shell which $(PROG)))
$(error $(PROG) not found, sudo apt install pkg-config)
endif

AR:= ar rc
RANL:= ranlib
RM:= rm -rf
MKD:=mkdir -p 

# CFLAGS=-c -Wall -Wextra -Werror -std=c11
CFLAGS=-g -Wall -Wextra -std=c11
CHECK_FLAGS=$(shell pkg-config --cflags --libs check)
GCOV_FLAGS=-fprofile-arcs -ftest-coverage

all: s21_string.a test gcov_report

show:
	@echo $(TST_SRC)
	@echo $(TST_INC)
	@echo $(TST_OBJ)
	@echo $(CHECK_FLAGS)

$(TARGET): $(OBJ)
	$(AR)	$(TARGET) $(OBJ)
	$(RANL) $(TARGET)

$(OBJ):	$(BUILD_DIR)%.o: $(SRC_DIR)%.c $(INC)
	@$(MKD) $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ -c $<

#TESTS

test: $(TST_TARGET)
	./$(TST_TARGET)

$(TST_TARGET): $(TST_TARGET_SRC) $(TST_OBJ) $(TARGET) $(TST_INC)
	$(CC) $(CFLAGS) -o $(TST_TARGET) $< $(CHECK_FLAGS) $(TST_OBJ) $(TARGET) 


$(TST_OBJ):	$(TST_BUILD)%.o: $(TST_DIR)%.c $(TST_INC)
	@$(MKD) $(TST_BUILD)
	$(CC) $(CFLAGS) -o $@ -c $<
#END TESTS

#GCOV
# library with FLAGS
$(GCOV_OBJ): $(GCOV_BUILD)%.o: $(SRC_DIR)%.c $(GCOV_INC)
	@$(MKD) $(GCOV_BUILD)
	$(CC) $(CFLAGS) $(GCOV_FLAGS) -o $@ -c $<

$(GCOV_LIB): $(GCOV_OBJ)
	$(AR) $(GCOV_LIB) $(GCOV_OBJ)
	$(RANL) $(GCOV_LIB)

# tests with gcov lib
$(GCOV_TST_TARGET): $(TST_TARGET_SRC) $(GCOV_LIB) $(TST_OBJ)  $(TST_INC)
	$(CC) $(CFLAGS) $(GCOV_FLAGS) -o $(GCOV_TST_TARGET) $<  $(TST_OBJ) $(GCOV_LIB) $(CHECK_FLAGS)

# form report
gcov_report: $(GCOV_TST_TARGET)
	./$(GCOV_TST_TARGET)
	gcov $(GCOV_OBJ)
	lcov  -o $(GCOV_DIR)/report.info -c -d $(GCOV_DIR)
	genhtml -o $(GCOV_DIR) $(GCOV_DIR)/report.info
	@echo ---------------------------------------------
	@echo open  $(abspath .)/$(GCOV_DIR)/index.html to see report
	@echo ---------------------------------------------

#END GCOV

sanityze-flag:
	$(eval CFLAGS+=-fsanitize=address)

sanityze: sanityze-flag clean test

valgrind: clean $(TST_TARGET)
	valgrind --tool=memcheck --leak-check=yes  --show-leak-kinds=all -s $(SRC_DIR)/$(TST_TARGET)

clean:
	$(RM) $(BUILD_DIR)
	$(RM) $(TARGET)
	$(RM) $(TST_BUILD)
	$(RM) $(TST_TARGET)
	$(RM) $(GCOV_DIR)
	$(RM) *.gcov


clang:
	clang-format --style=Google -n $(SRC_DIR)/*.c $(INC_DIR)/*.h
 
clang-format:
	clang-format --style=Google -i $(SRC_DIR)/*.c $(INC_DIR)/*.h $(TST_DIR)/*.c  $(TST_DIR)/*.h

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem $(SRC_DIR)/*.c $(INC_DIR)/*.h
