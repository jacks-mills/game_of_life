CC := gcc
CFLAGS := -std=c99 -Wall -pedantic
LDFLAGS := $(shell ncursesw5-config --cflags --libs)

SRC_DIR := ./src
BLD_DIR := ./bld
BIN_DIR := ./bin
INS_DIR := $(HOME)/.local/bin

OBJS := $(patsubst $(SRC_DIR)/%.c, $(BLD_DIR)/%.o, $(wildcard $(SRC_DIR)/*.c))
TARG := $(BIN_DIR)/game-of-life


.PHONY: all clean install uninstall


all: $(TARG)

clean:
	rm -rf $(BLD_DIR)
	rm -rf $(BIN_DIR)

install: $(INS_DIR)/$(notdir $(TARG))

uninstall:
	rm -f $(INS_DIR)/$(notdir $(TARG))



$(TARG): $(BIN_DIR)/%: $(OBJS) | $(BIN_DIR)
	$(CC) $(CFLAGS)   -o $@ $^ $(LDFLAGS)

$(OBJS): $(BLD_DIR)/%.o: $(SRC_DIR)/%.c | $(BLD_DIR)
	$(CC) $(CFLAGS)   -o $@ -c $^

$(INS_DIR)/% : $(BIN_DIR)/%
	cp $< $@

$(BLD_DIR) $(BIN_DIR):
	mkdir -p $@


