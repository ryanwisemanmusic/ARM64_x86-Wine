CC = clang
AS = as
LD = ld
CFLAGS = -Wall -Wextra -O2 -I./src/headers
ASFLAGS = -arch arm64
LDFLAGS = -Wl,-e,_start

# Directories
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
ASM_DIR = $(SRC_DIR)/x86-DOS_C_Code
HEADER_DIR = $(SRC_DIR)/headers

# Source files
C_SOURCES = $(wildcard $(ASM_DIR)/*.c)
ASM_SOURCES = $(wildcard $(ASM_DIR)/*.asm)
HEADERS = $(wildcard $(HEADER_DIR)/*.h)

# Object files
C_OBJECTS = $(patsubst $(ASM_DIR)/%.c,$(OBJ_DIR)/%.o,$(C_SOURCES))
ASM_OBJECTS = $(patsubst $(ASM_DIR)/%.asm,$(OBJ_DIR)/%.o,$(ASM_SOURCES))
OBJECTS = $(C_OBJECTS) $(ASM_OBJECTS)

# Target executable
TARGET = $(BIN_DIR)/x86_emulator

# Default target
all: directories $(TARGET)

# Create necessary directories
directories:
	@mkdir -p $(OBJ_DIR) $(BIN_DIR)

# Link object files to create executable
$(TARGET): $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $^

# Compile C source files
$(OBJ_DIR)/%.o: $(ASM_DIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Assemble ASM source files
$(OBJ_DIR)/%.o: $(ASM_DIR)/%.asm
	$(AS) $(ASFLAGS) -o $@ $<

# Clean build files
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Rebuild everything
rebuild: clean all

# Run the emulator
run: all
	$(TARGET)
